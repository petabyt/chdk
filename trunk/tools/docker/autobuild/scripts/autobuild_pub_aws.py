#!/usr/bin/env python3
#
# Copyright (C) 2023 <reyalp (at) gmail dot com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# with chdk. If not, see <http://www.gnu.org/licenses/>.

"""
upload build and meta files, remove obsolete - AWS s3 + cloudfront implementation

AWS credentials are assumed to be available in one of the normal places used by
boto3. For containers running in ECS, this should be temporary task role
credentials obtained via AWS_CONTAINER_CREDENTIALS_RELATIVE_URI
For other scenarios they could be provided by the standard AWS environment variables

In all cases, the supplied key should provide the following permissions and no more

For the bucket specified by pub_aws.bucket
ListBucket

PutObject
DeleteObject

The object operations should be restricted to the prefix specified
by pub.dir and branch id

For the cloudfront distribution specified in pub_aws.cf_dist
CreateInvalidation
"""

import re
import os
import time
import posixpath
import boto3
import botocore.config

class AutobuildPubAWS:
    """publish interface for AWS"""
    # simple map for content types
    mime_map = {
        'zip':'application/zip',
        'json':'application/json',
        'txt':'text/plain',
        'log':'text/plain',
    }
    def __init__(self, pub_data, cfg, infomsg = None):
        """initialize with publication root, pub_* cfg section, and infomsg function"""

        self.data = pub_data
        self.cfg = cfg
        self.infomsg = infomsg or self.infomsg_default

        self.prefix = self.data['path']
        # s3 methods do not expect a leading /
        if self.prefix[0] == '/':
            self.prefix = self.prefix[1:]

        # also normalize to a trailing /
        if self.prefix[-1] != '/':
            self.prefix += '/'


    def infomsg_default(self,level,msg):
        print(msg)

    def init_aws(self):
        self.aws_config = botocore.config.Config(
            region_name = self.cfg['region'],
            retries = {
                # defaults
                'max_attempts':self.cfg.getint('max_retry',3),
                'mode':'standard',
            }
        )

        self.s3 = boto3.client('s3',config=self.aws_config)
        self.cf = boto3.client('cloudfront',config=self.aws_config)
        self.delete_batch_max = self.cfg.getint('delete_batch',1000) # batch size, can be lowered for testing

    def get_cache_control_for_ext(self, ext):
        max_age = ''
        if ext in ['json','txt','log']:
            if self.cfg['max_age_meta']:
                max_age = self.cfg['max_age_meta']
        elif ext == 'zip':
            if self.cfg['max_age_meta']:
                max_age = self.cfg['max_age_zip']

        if max_age:
            return f'max-age={max_age}'


    def deliver_single(self, src, dst):
        """upload a single file to dst in bucket"""
        # note sequential upload is inefficient, but our files are tiny
        extra_args = None
        # set content type for types we use
        m = re.search('\.([^./]*)$',dst)
        if m:
            ext = m[1].lower()
            mime_type = self.mime_map.get(ext)
            cache_control = self.get_cache_control_for_ext(ext)
            if mime_type or cache_control:
                extra_args = {}
                if mime_type:
                    extra_args['ContentType']=mime_type
                if cache_control:
                    extra_args['CacheControl']=cache_control

        self.infomsg(1,f"upload {src} {self.cfg['bucket']}:{dst} extra {extra_args}")
        if self.cfg.getboolean('pretend'):
            return

        # note errors are fatal. boto3 should retry internally for network errors
        self.s3.upload_file(src, self.cfg['bucket'], dst, ExtraArgs=extra_args)

    def get_pub_path(self,*args):
        """return a directory path under prefix by joining args"""
        return posixpath.join(self.prefix,*args)

    def get_delete_list(self):
        """get a list of build zip files from the bucket, excluding those we uploaded"""
        pg = self.s3.get_paginator('list_objects_v2')
        delete_excludes = []

        # build list of full paths uploaded to save from delete
        for fn in self.data['zips']['files']:
            delete_excludes.append(self.get_pub_path(self.data['zips']['subdir'],fn))

        r = []
        bin_pfx = posixpath.join(self.prefix,self.data['zips']['subdir']) + '/'
        for page in pg.paginate(Bucket = self.cfg['bucket'], Prefix = bin_pfx):
            if page['KeyCount'] > 0:
                for objinfo in page['Contents']:
                    # shouldn't happen but lets be paranoid with deletes
                    if not objinfo['Key'].startswith(bin_pfx):
                        raise ValueError(f"unexpected key {objinfo['Key']}")

                    # filter paths that look like a build zip
                    # TODO we could filter N recent builds here
                    key = objinfo['Key']

                    sub = key[len(bin_pfx):]
                    if re.match(r'[^./]+-\d+\.\d+\.\d+-\d+[^./]*.zip$', sub):
                        # we could exclude the current build number, but we have the upload list so use that
                        if key not in delete_excludes:
                            self.infomsg(1, f"delete match {key}")
                            r.append(key)

        return r

    def clean_obsolete(self):
        """remove build zips not from the current build"""
        if not self.cfg.getboolean('delete_old'):
            self.infomsg(1,'delete_old disabled, skipping delete_obsolete')
            return

        if not self.data['build_status']:
            self.infomsg(0,'build failed, skipping delete_obsolete')
            return

        delete_list = self.get_delete_list()

        # delete_objects accepts batches of max 1000
        while len(delete_list) > 0:
            delete_batch = delete_list[:self.delete_batch_max]
            delete_list = delete_list[self.delete_batch_max:]

            self.infomsg(1,"delete batch:")
            for fname in delete_batch:
                self.infomsg(1,fname)

            if self.cfg.getboolean('pretend'):
                continue

            r = self.s3.delete_objects(
                Bucket = self.cfg['bucket'],
                Delete = {
                    'Objects':[{'Key':name} for name in delete_batch],
                    'Quiet':True,
                }
            )
            self.infomsg(2,f'delete_objects status: {r}')
            # don't abort on errors but report them
            if 'Errors' in r and len(r['Errors']):
                self.infomsg(0,'delete_objects errors:')
                for err in r['Errors']:
                    self.infomsg(0,f'{err}')

    def cdn_invalidate_files(self, sub_paths):
        """invalidate paths specified in sub_paths under our prefix"""

        # note cf names *do* require a leading /
        paths = []
        # on cloudfront, a wildcard is single invalidation
        # invalidate everything under the prefix
        for sub in sub_paths:
            p = posixpath.join('/',self.prefix,sub)
            self.infomsg(1,f"invalidate {p}")
            paths.append(p)

        ref = str(time.time())
        self.infomsg(1,f"invalidate ref {ref}")
        if self.cfg.getboolean('pretend'):
            return

        r = self.cf.create_invalidation(
            DistributionId=self.cfg['cf_dist'],
            InvalidationBatch={
                'Paths': {
                    'Quantity': len(paths),
                    'Items': paths,
                },
                'CallerReference': ref
            }
        )
        self.infomsg(2,f'create_invalidation status: {r}')

    def run(self):
        # set up aws clients
        self.init_aws()

        if self.data['build_status']:
            # if build was successful, upload zips from bin to <prefix>/*.zip
            for fn in self.data['zips']['files']:
                self.deliver_single(os.path.join(self.data['zips']['src'],fn), self.get_pub_path(self.data['zips']['subdir'],fn))

        # meta files
        for fn in self.data['meta']['files']:
            self.deliver_single(os.path.join(self.data['meta']['src'],fn), self.get_pub_path(self.data['meta']['subdir'],fn))

        invalidate_list = [posixpath.join(self.data['meta']['subdir'],fn) for fn in self.data['meta']['files']]

        # log file, if enabled
        if 'log' in self.data:
            self.deliver_single(self.data['log']['src'], self.get_pub_path(self.data['log']['subdir'],self.data['log']['dst']))
            invalidate_list.append(posixpath.join(self.data['log']['subdir'],self.data['log']['dst']))

        # cloudfront treats wildcard a single invaldiation so we should probably just do all
        if self.cfg['invalidate'] == 'all':
            self.cdn_invalidate_files(['*'])
        elif self.cfg['invalidate'] == 'allmeta':
            self.cdn_invalidate_files([posixpath.join(self.data['meta']['subdir'],'*')])
        elif self.cfg['invalidate'] == 'files':
            self.cdn_invalidate_files(invalidate_list)

        # if build was successful and all above completed without failures, remove previous zips
        if self.data['build_status']:
            self.clean_obsolete()

def do_publish(pub_data, cfg, log_fn = None):
    """
    publish files to AWS and delete obsolte files.
    Errors will be raised on failure of any step.
    """
    AutobuildPubAWS(pub_data, cfg, log_fn).run()

