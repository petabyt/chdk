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
chdk autobuild runner

see init_args and init_conf for command line and configuration options
"""
import sys
import os
import argparse
import configparser
import subprocess
import shutil
import glob
import json
import re
import importlib
import posixpath
import hashlib
from datetime import datetime, timezone
import xml.etree.ElementTree as xmlElementTree


class AutoBuilder:
    """
    class providing functions for a CHDK autobuild, handling source download, build and upload
    """
    # program version
    VERSION = "1.0.1"
    # versions for meta files. Minor version updates will be backward compatible
    # 1.1
    #  added zip file size to file info
    #  added family level aka value to label ixus/sd/elph/ixy
    json_info_ver = '1.1'
    json_status_ver = '1.0'

    # default meta files
    meta_files = ['sha256sums.txt','files_small.txt','files_full.txt','build_info.json', 'build_status.json']

    def __init__(self,init_args=None):
        """init_args is an array of command line options. Defaults to sys.argv, excluding argv[0]"""
        self.init_args(init_args)
        self.init_conf()

    def init_args(self,init_args=None):
        """initialize command line options"""

        if init_args is None:
            init_args = sys.argv[1:]

        parser = argparse.ArgumentParser(description="CHDK autobuild runner")
        parser.add_argument(
            "-V",
            "--version",
            action="version",
            version="%(prog)s {}".format(self.VERSION)
        )
        parser.add_argument(
            "-s",
            "--step",
            help="run autobuild step",
        )
        parser.add_argument(
            "--dump-cfg",
            metavar='file',
            help="dump merged config to file, - for stdout",
        )

        parser.add_argument(
            "cfg",
            help="config options in the form foo.bar=baz",
            nargs="*"
        )

        self.argparse = parser
        self.args = parser.parse_args(init_args)

    def init_conf(self):
        """set initial configuration, override with options provided command line and config file"""
        self.cfg = configparser.ConfigParser(interpolation=configparser.ExtendedInterpolation())
        # default configuration values
        self.cfg.read_dict({
            # controls for test or manual build
            'ctl':{
                'checklock':'1',  # abort if lock file present
                'createdirs':'0', # create expected directory structure if missing, otherwise error
                'checkrev':'1',   # check revision, abort if current rev already recorded as built in state
                'fetch':'1',      # download source
                'fetchclean':'1', # remove src dir if found present in fetch (otherwise, error)
                'configsrc':'1',  # create localbuilconf.inc and install fi2.inc
                'build':'1',      # make
                'checkzips':'1',  # check zips from build exist (disable for no-op testing)
                'updaterev':'1',  # update state to reflect built revision
                'meta':'1',       # create meta files
                'metaextra':'1',  # include extra mid/pid info in meta
                'jsonpretty':'0', # pretty print json
                'publish':'1',    # web file upload / update
                'clean':'1',      # build file cleanup
                'cleanlock':'1',  # delete lock file on completion
                'verbose':'1',    # verbosity: -1 = quiet, 0 = off nominal only, 1 = chatty, 2 = detailed
            },
            'svn':{
                'use_guest':'1', # use username / password 'guest', as assembla requires for anon access
                'repo_url':'https://subversion.assembla.com/svn/chdk',
                'browse_url':'https://app.assembla.com/spaces/chdk/subversion', # root for user friendly browse links
                'log_revs':'5',  # number of log revisions to include in meta, 0 to disable
            },
            'dir':{
                'root':'/srv',          # root of autobuild tree
                'cfg':'${root}/cfg',    # configuration files, should be read only (override by command line only)
                'data':'${root}/data',  # data files - currently exif model id info
                'state':'${root}/state',# state files, tracks current build number. Should be persistent
                'log':'${root}/log',    # build log directory, can be persistent or ephemeral
                'build':'${root}/build',# root of build tree. Everything in build tree can be ephemeral
                'src':'${build}/src',   # source build directory
                'meta':'${build}/meta', # build meta file output
            },
            'pub':{
                'type':'aws',     # publish method, used to select pub_* section below and the
                                  # autobuild_pub_<type>.py module implementing the publish method
                'dir':'/builds',  # path prefix for published files root
                'bin_dir':'bin',  # subdirectory for zip files
                'meta_dir':'meta',# subdirectory for meta files (includes log for now)
                'buildlog':'failed',# publish build, one of 'always', 'failed', 'never'
                'buildlog_path':'build.log' # path + name of uploaded build log under upload tree
            },
            # non-sensitive settings for publishing to AWS
            'pub_aws':{
                'bucket':'',    # s3 origin bucket name
                'cf_dist':'',   # cloudfront distribution ID
                'region':'',    # despite bucket names being globally unique, API wants a region
                'max_retry':'3',# 3 is boto3 default
                'pretend':'0',  # print AWS upload/delete/invalidate commands without doing them
                'delete_old':'1', # delete zips not from the current build
                'delete_batch':'1000', # AWS multi-delete limit, can be lowered for testing
                'max_age_meta':str(60*5),  # cache control max age for meta files.
                                       # Should be short so clients don't cache stale date, but cloudfront
                                       # TTL can be long since explicitly invalidated on build
                'max_age_zip':str(60*60*24), # max age for zip files. Can be long since build number is included in name
                'invalidate':'all', # files to invalidate from cloudfront.
                                    # 'all' = everything in build subdirectory
                                    # 'allmeta' = everything meta directory
                                    # 'files' = individual files
                                    # 'none' = do not invalidate
                                    # cloudfront counts wildcards a single invalidation so all or allmeta is recommended
            },
            'build':{
                'camera_list':'', # optional camera_list.csv override
                'fi2':'1',        # build FI2, if fi2.inc is available in cfg dir
                'branch':'trunk', # branch ID for branch config sections below
                'setuser':'1',    # run make as a different user. Ignored if not root
                'user':'chdkbuild',  # user name or UID to run make
                'group':'chdkbuild', # group name or GID
            },
            # branch definitions selected by the build branch section
            'branch_trunk':{
                'svn_path':'trunk', # path relative to repo_url
                'rel_sfx':'',       # version suffix like 1_6 for release branch, or empty for trunk / other other
                'id':'trunk',       # simple id string for branch
                'desc':'Development / Unstable', # Human description
            },
            'branch_release':{
                'svn_path':'branches/release',
                'rel_sfx':'1_6',
                'id':'release',
                'desc':'Release / Stable',
            },
        })
        # merge command line to config values, so the config location can be overridden
        self.args_to_cfg()

        self.cfg.read(os.path.join(self.cfg['dir']['cfg'],'autobuild.cfg'))

        # re-merge command line options, so they override file
        self.args_to_cfg()

        # validate configuration and initialize convenience properties
        # validate and create shorthand for current branch config
        branch_sec = 'branch_'+self.cfg['build']['branch']
        if branch_sec in self.cfg:
            self.branch_cfg = self.cfg[branch_sec]
        else:
            raise ValueError(f'missing branch cfg section {branch_sec}')

        # validate and create shorthand for current publish config
        pub_sec = 'pub_'+self.cfg['pub']['type']
        if pub_sec in self.cfg:
            self.pub_cfg= self.cfg[pub_sec]
        else:
            raise ValueError(f'missing pub cfg section {pub_sec}')

        if self.cfg['pub']['buildlog'] not in ['failed','always','never']:
            raise ValueError(f"expected pub.buildlog one of 'failed','always','never' not '{self.cfg['pub']['buildlog']}'")

        # properties for svn
        self.branch_url = posixpath.join(self.cfg['svn']['repo_url'],self.branch_cfg['svn_path'])
        for name in ['svn_path','id','desc']:
            if not name in self.branch_cfg:
                raise ValueError(f'missing {name} in {branch_sec}')

        self.branch_id = self.branch_cfg['id']

        if self.branch_cfg.get('rel_sfx'):
            self.branch_sfx_full = '-' + self.branch_cfg['rel_sfx']
        else:
            self.branch_sfx_full = ''

        self.branch_url += self.branch_sfx_full

        if self.cfg['pub_aws']['invalidate'] not in ['all','allmeta','files','none']:
            raise ValueError(f"unexpected pub_aws.invalidate in {self.cfg['pub_aws']['invalidate']}")

        # check control options are valid. Currently all bool except verbose
        for name in self.cfg['ctl']:
            if name == 'verbose':
                self.cfg['ctl'].getint(name)
            else:
                self.cfg['ctl'].getboolean(name) # will error if not, could log overrides

        # misc file paths TODO could be interpolated config items
        self.state_file = os.path.join(self.cfg['dir']['state'],'state.cfg')
        self.lock_file = os.path.join(self.cfg['dir']['state'],'build_running')
        self.export_log = os.path.join(self.cfg['dir']['log'],'export.log')
        self.build_log = os.path.join(self.cfg['dir']['log'],'build.log')

        self.bin_dir = os.path.join(self.cfg['dir']['src'],'bin')

        self.svn_cmd_base = [ 'svn', '--non-interactive' ]
        # don't use general username / password options
        # because they probably be stored differently if sensitive
        if self.cfg['svn'].getboolean('use_guest'):
            self.svn_cmd_base = [ *self.svn_cmd_base,
                '--username', 'guest',
                '--password', 'guest',
            ]

        if self.cfg['ctl'].getboolean('jsonpretty'):
            self.json_opts = {'indent':1,'separators':(', ',':')}
        else:
            self.json_opts = {'indent':None,'separators':(',',':')}

        if self.cfg['build'].getboolean('setuser'):
            if os.geteuid() != 0:
                self.infomsg(1,f'euid {os.geteuid()} not root, ignoring build.setuser')
                self.cfg['build']['setuser']='0'

    def main(self):
        """
        run as command line script for when file invoked directly
        returns a sys.exit value, with None or 0 indicating success
        """
        got_cmd = False
        if self.args.dump_cfg:
            if self.args.dump_cfg == '-':
                self.cfg.write(sys.stdout)
            else:
                self.infomsg(1,f"write {self.args.dump_cfg}")
                with open(self.args.dump_cfg,"w") as f:
                    self.cfg.write(f)
            got_cmd = True

        if self.args.step:
            return self.run_step(self.args.step)
        elif not got_cmd:
            self.argparse.parse_args(['-h'])

    def args_to_cfg(self):
        """merge supplied command line options into config"""
        for s in self.args.cfg:
            m = re.match('([^.]+)\.([^=]+)=(.+)',s)
            if not m:
                raise ValueError(f'expected section.name=value in {s}')
            section = m.group(1)
            name = m.group(2)
            val = m.group(3)
            if not section in self.cfg:
                raise ValueError(f'unknown cfg section {section} in {s}')
            if not name in self.cfg[section]:
                raise ValueError(f'unknown cfg name {name} in {s}')

            # no validation here, cfg values should be sanity checked regardless of source
            self.cfg[section][name]=val

    def infomsg(self,level,msg):
        if not hasattr(self,'cfg') or self.cfg['ctl'].getint('verbose') >= level:
            print(msg)

    def init_state(self, step):
        """initialize / load state file"""
        self.state = configparser.ConfigParser()
        # default configuration values
        self.state.read_dict({
            'rev':{
                'build':'0', # revision to be potentially built in current invocation, updated by check_need_build
                'last_ok':'0', # most recent completed, updated by finish
            },
        })
        # don't attempt to load state file if don't have lock
        if step != 'init_lock':
            # configparser doesn't care about missing files / dirs, but want to warn
            if os.path.isfile(self.state_file):
                self.infomsg(1,f'loading state {self.state_file}')
                self.state.read(self.state_file)
            else:
                self.infomsg(0,f'missing state file {self.state_file}, using defaults')

    def write_state(self):
        """write current state to file"""
        self.check_req_dir(self.cfg['dir']['state'])
        with open(self.state_file,'w') as f:
            self.infomsg(1,f'write state {self.state_file}')
            self.state.write(f)

    def svn_cmd(self,svnargs):
        """return list of arguments to run svn with subprocess.run and friends"""
        cmd = [*self.svn_cmd_base,*svnargs]
        self.infomsg(1,' '.join(cmd))

        return cmd

    def check_req_dir(self,path):
        """check expected directly exists in tree, make if ctl.createdirs set, otherwise raise ValueError"""
        if not os.path.isdir(path):
            if self.cfg['ctl'].getboolean('createdirs'):
                self.infomsg(1,f'creating {path}')
                os.makedirs(path)
            else:
                raise ValueError(f'missing required directory {path}')

    def get_svn_branch_rev(self):
        """get latest revision of branch from svn"""
        # error output will go to our stderr
        svn_rev_str = subprocess.check_output(self.svn_cmd(['info','--show-item','last-changed-revision',self.branch_url]))
        return int(svn_rev_str)

    def get_source_ver_str(self):
        """get the version string from version.inc"""
        with open(os.path.join(self.cfg['dir']['src'],'version.inc'),'r') as f:
            content = f.read()

        m = re.match(r'BUILD_NUMBER\s*:=\s*(\d+\.\d+\.\d+)\s*$',content)
        if not m:
            self.infomsg(0,'faild to parse version.inc {content}')
            return "0.0.0"

        return m[1]

    def get_svn_log_xml(self):
        """get recent svn log entries for meta"""
        if not self.cfg['svn'].getint('log_revs'):
            return

        return subprocess.check_output(self.svn_cmd([
                    'log', '-l', self.cfg['svn']['log_revs'],'--xml',
                    f"{self.branch_url}@{self.state['rev']['build']}"
                ]),
            )

    def get_json_svn_log(self):
        """return recent svn log entries as an array of dicts for json"""
        if not self.cfg['svn'].getint('log_revs'):
            return []

# logentry elements should look like
# <logentry revision="6221">
# <author>reyalp</author>
# <date>2023-01-28T21:44:33.328072Z</date>
# <msg>ixus175_elph180 - update notes with crash on turning MF off without halfpress, remove alpha warning</msg>
# msg may be empty, or contain new lines

        e = xmlElementTree.fromstring(self.get_svn_log_xml())
        r = []
        for le in e:
            if le.tag == 'logentry':
                rev = le.attrib['revision']
                msg = le.find('msg').text
                if msg is not None:
                    msg = msg.split('\n')
                else:
                    msg = []

                r.append({
                    'svn': self.get_commit_browse_url(rev),
                    'revision': rev,
                    'author': le.find('author').text,
                    'utc': le.find('date').text,
                    'msg': msg,
                })
            else:
                raise ValueError(f"unexpected tag {le.tag}")

        return r

    def get_source(self):
        if not self.cfg['ctl'].getboolean('fetch'):
            self.infomsg(0,"skip svn fetch")
            return

        if os.path.isdir(self.cfg['dir']['src']):
            if self.cfg['ctl'].getboolean('fetchclean'):
                self.infomsg(0,f"remove src {self.cfg['dir']['src']}")
                shutil.rmtree(self.cfg['dir']['src'])
            else:
                raise ValueError(f"src {self.cfg['dir']['src']} exists")

        os.makedirs(os.path.dirname(self.export_log),exist_ok=True)
        if self.cfg['build'].getboolean('setuser'):
            os.makedirs(self.cfg['dir']['src'],exist_ok=True)
            os.chmod(self.cfg['dir']['src'],0o2775)
            shutil.chown(self.cfg['dir']['src'],group=self.cfg['build']['group'])
            os.umask(0o002) # want exported dirs to be group write
        with open(self.export_log,'w') as log:
            subprocess.check_call(self.svn_cmd([
                    'export','-r',
                    str(self.state['rev']['build']),
                    '--force', # force because we want the directory created with perms above
                    self.branch_url,self.cfg['dir']['src']
                ]),
                stdout=log, stderr=subprocess.STDOUT)

        if self.cfg['build'].getboolean('setuser'):
            os.umask(0o022)

    def configure_source(self):
        if not self.cfg['ctl'].getboolean('configsrc'):
            self.infomsg(0,"skip config source")
            return

        buildconf = f'''\
# auto generated {datetime.now(tz=timezone.utc).isoformat(timespec='seconds')}
OPT_GEN_SIGS=
OPT_GEN_STUBS=
DEF_SVN_REF={self.state['rev']['build']}
'''
        if self.cfg['build']['camera_list']:
            self.infomsg(1,f"override camera_list {self.cfg['build']['camera_list']}")
            buildconf += f'''\
CAMERA_LIST={self.cfg['build']['camera_list']}
'''
        if self.cfg['build'].getboolean('fi2'):
            fi2src = os.path.join(self.cfg['dir']['cfg'],'fi2.inc')
            if os.path.isfile(fi2src):
                fi2dest = os.path.join(self.cfg['dir']['src'],'platform/fi2.inc')
                self.infomsg(1,f'copy {fi2src} {fi2dest}')
                # if root, use copy that preserves owner / permissions
                if os.geteuid() == 0:
                    shutil.copy(fi2src,fi2dest)
                else:
                    shutil.copyfile(fi2src,fi2dest)
                buildconf += f'''\
OPT_FI2=1
'''
            else:
                self.infomsg(0,'missing fi2.inc, FI2 build disabled')
        buildconf_file = os.path.join(self.cfg['dir']['src'],'localbuildconf.inc')
        self.infomsg(1,f'write {buildconf_file}')
        with open(buildconf_file,'w') as f:
            f.write(buildconf)

    def str_removeprefix(self, s, pfx):
        """python 3.9 function, boo"""
        if s.startswith(pfx):
            return s[len(pfx):]
        return s

    def init_zip_lists(self):
        """load lists of zips of files in the build bin directory"""
        bin_dir = os.path.join(self.cfg['dir']['src'],'bin')
        # filenames are  model-firmware-version-build[-full][_STATUS].zip like
        # sx620hs-100b-1.6.1-6222-full.zip
        # sx620hs-100b-1.6.1-6222.zip
        # sx620hs-100c-1.6.1-6222-full_ALPHA.zip
        # sx620hs-100c-1.6.1-6222_ALPHA.zip
        rev = self.state['rev']['build']
        self.all_zips = [self.str_removeprefix(x,bin_dir+'/') for x in glob.glob(os.path.join(bin_dir,f'*-{rev}*.zip'))]
        self.all_zips.sort()
        self.full_zips = [x for x in self.all_zips if f'-{rev}-full' in x]
        self.small_zips = [x for x in self.all_zips if not f'-{rev}-full' in x]

        if self.cfg['ctl'].getboolean('checkzips'):
            if len(self.all_zips) == 0:
                raise ValueError('no zips found')

            if len(self.full_zips) != len(self.small_zips):
                raise ValueError('full vs small zip numbers do not match')

    def init_zip_hashes(self):
        """make dict mapping names in all_zips to sha256 hashes"""
        self.zip_hashes={}
        bin_dir = os.path.join(self.cfg['dir']['src'],'bin')
        for fn in self.all_zips:
            h = hashlib.new('sha256')
            with open(os.path.join(bin_dir,fn),'rb') as f:
                data=f.read()
            h.update(data)
            self.zip_hashes[fn] = h.hexdigest()

    def init_zip_sizes(self):
        """make dict mapping names in all_zips to file sizes"""
        self.zip_sizes={}
        bin_dir = os.path.join(self.cfg['dir']['src'],'bin')
        for fn in self.all_zips:
            self.zip_sizes[fn] = os.path.getsize(os.path.join(bin_dir,fn))

    def init_platform_model_info_map(self):
        with open(os.path.join(self.cfg['dir']['data'],'platform_model_info.json')) as f:
            self.platform_model_info_map = json.load(f)

    def get_platform_model_info(self, plat):
        if not hasattr(self,'platform_model_info_map'):
            self.init_platform_model_info_map()

        if plat in self.platform_model_info_map:
            return self.platform_model_info_map[plat]
        else:
            self.infomsg(0,f'missing model info for {plat}')

    def get_zip_sha256(self,zipname):
        return self.zip_hashes[zipname]

    def get_zip_size(self,zipname):
        return self.zip_sizes[zipname]

    def get_zip_name_info(self,fn):
        m = re.match(r'([^-]+)-(\d{3}[^-])-(\d+)\.(\d+)\.(\d+)-(\d+)(-full)?(?:_([^.]+))?.zip$', fn)
        if not m:
            raise ValueError(f"unexpected zip name {fn}")

        platform = m[1]
        c = platform[:1]
        if c in ['a','d','g','m','n']:
            family = c.upper()
        elif c == 's':
            if platform[:2] == 'sx':
                family = 'SX'
            else:
                family = 'S'
        elif c == 't':
            family = 'TX'
        elif platform[:4] == 'ixus':
            family = 'IXUS'
        else:
            self.infomsg(0,f"unexpected platform {platform}")
            family = ''

        if family == 'M':
            line = 'EOS'
        elif family == 'IXUS':
            line = 'Digital'
        else:
            line = 'PowerShot'

        return {
            'file':fn,
            'line':line,
            'family':family,
            'platform':platform,
            'sub':m[2],
            'version':[int(m[3]),int(m[4]),int(m[5])],
            'build':int(m[6]),
            'full':m[7] is not None,
            'status':m[8] or '',
        }

    def get_zip_list_name_info(self, zip_list):
        r = []
        for fn in zip_list:
            r.append(self.get_zip_name_info(fn))

        return r

    def zip_full_to_small_name(self,fn):
        # full follows the build number, like
        # sx620hs-100b-1.6.1-6222-full.zip
        return re.sub(r'(-\d+)-full',r'\1',fn)

    def get_zip_model_dict(self):
        """
        create a dict structured like
        {
            'A':{
                'line':'PowerShot',
                'models':{
                    'a1100':{
                        mid:40042496,
                        pid:12739,
                        desc:'A1100 IS',
                        subs:{
                            '100b':{
                                'full':{
                                    'status':'',
                                    'name':'a1100-100b-1.6.1-6222-full.zip',
                                    'sha256':'<shasum>',
                                },
                                'small':{
                                    'name':'a1100-100b-1.6.1-6222.zip',
                                    'sha256':'<shasum>',
                                },
                            },
                            '100c':{
                                ...
                            },
                        },
                    }
                    'a1200':{
                        #...
                    },
                },
            },
            'D':{
                ...
            },
        }
        mid and pid are only set if ctl.metaextra is set, and data is available in platform_model_info.json
        mid is the exif model ID, pid is the USB platform ID
        """
        families = {}
        zip_list_info = self.get_zip_list_name_info(self.full_zips)
        for fi in zip_list_info:
            if fi['family'] not in families:
                families[fi['family']] = {
                    #'name':fi['family'],
                    'line':fi['line'],
                    'platforms':{},
                }

                if fi['family'] == 'IXUS':
                    families[fi['family']]['aka'] = 'SD, ELPH, IXY'

            fam = families[fi['family']]
            if fi['platform'] not in fam['platforms']:
                fam['platforms'][fi['platform']] = {
                    #'name':fi['platform'],
                    'subs':{},
                }

            plat = fam['platforms'][fi['platform']]
            if fi['sub'] not in plat['subs']:
                plat['subs'][fi['sub']] = {
                    #'name':fi['sub'],
                    'status':fi['status'],
                    'full':{
                        'file':fi['file'],
                        'sha256':self.get_zip_sha256(fi['file']),
                        'size':self.get_zip_size(fi['file']),
                    },
                    'small':{
                        'file':self.zip_full_to_small_name(fi['file']),
                        'sha256':self.get_zip_sha256(self.zip_full_to_small_name(fi['file'])),
                        'size':self.get_zip_size(self.zip_full_to_small_name(fi['file'])),
                    },
                }

            if self.cfg['ctl'].getboolean('metaextra'):
                mi = self.get_platform_model_info(fi['platform'])
                # allow missing since models may be added before list is updated
                if mi:
                    plat['mid'] = mi['mid']
                    plat['pid'] = mi['pid']
                    plat['desc'] = mi['desc']
                    if 'aka' in mi:
                        plat['aka'] = mi['aka']

        return families

    def get_json_firmware_list(self):
        """transform model info dict to arrays to preserve order in json"""
        # similar but not identical to 'chdk' in https://chdkde.akalab.de/release_full.json
        d = self.get_zip_model_dict()
        r = []
        for fam_id, fam_info in d.items():
            fam = {
                'id':fam_id,
                'line':fam_info['line'],
            }
            if 'aka' in fam_info:
                fam['aka'] = fam_info['aka']

            fam['models']=[]

            for plat_id, plat_info in fam_info['platforms'].items():
                plat = {
                    'id':plat_id,
                }
                if 'mid' in plat_info:
                    plat['mid'] = plat_info['mid']
                    plat['pid'] = plat_info['pid']
                    plat['desc'] = plat_info['desc']
                    if 'aka' in plat_info:
                        plat['aka'] = plat_info['aka']

                plat['fw'] = []

                for sub_id, sub_info in plat_info['subs'].items():
                    sub = {
                        'id':sub_id,
                        'full':sub_info['full'],
                        'small':sub_info['small'],
                    }
                    # only include no-default (ALPHA, BETA etc) status
                    if sub_info['status']:
                        sub['status'] = sub_info['status']

                    plat['fw'].append(sub)

                fam['models'].append(plat)

            r.append(fam)

        return r

    def get_json_firmware_counts(self):
        """return dict with counts of platform, firmwares and alpha / beta states"""
        # similar to 'counts' in https://chdkde.akalab.de/release_full.json but values are numbers
        d = self.get_zip_model_dict()
        r = {
            'models':0,
            'cameras':0,
            'states':[],
        }
        status_map = {}
        for fam_id, fam_info in d.items():
            for plat_id, plat_info in fam_info['platforms'].items():
                r['models'] += 1
                for sub_id, sub_info in plat_info['subs'].items():
                    r['cameras'] += 1
                    status = sub_info['status']
                    if status:
                        if status not in status_map:
                            status_map[status] = 1
                        else:
                            status_map[status] += 1

        for status, count in status_map.items():
            r['states'].append({
                'desc': status,
                'count': count,
            })
        r['states'].sort(key = lambda x: x['desc'])
        return r


    def write_meta_file(self, fname, content):
        """write content to fname in meta directory"""
        fpath = os.path.join(self.cfg['dir']['meta'], fname)
        self.infomsg(1,f'write {fpath}')
        with open(fpath,'w') as f:
            f.write(content)

    def get_rev_browse_url(self,rev):
        """return assembla browsable url for rev on current branch"""
        # assembla urls look like
        # https://app.assembla.com/spaces/chdk/subversion/source/6222/branches/release-1_6
        r = posixpath.join(self.cfg['svn']['browse_url'],
                                'source',
                                str(rev),
                                self.branch_cfg['svn_path'])
        if self.branch_sfx_full:
            r += self.branch_sfx_full

        return r

    def get_commit_browse_url(self,rev):
        """return assembla browsable url for commit"""
        # assembla urls look like
        # https://app.assembla.com/spaces/chdk/subversion/commits/6230
        r = posixpath.join(self.cfg['svn']['browse_url'],
                                'commits',
                                str(rev))
        if self.branch_sfx_full:
            r += self.branch_sfx_full

        return r

    def get_meta_buildinfo(self):
        """return dict describing branch, revision, build time etc of build"""
        return {
            'desc': "CHDK",
            'type': self.branch_cfg['id'],
            'type_desc': self.branch_cfg['desc'],
            'utc':datetime.now(tz=timezone.utc).isoformat(timespec='seconds'),
            'version': self.get_source_ver_str(),
            'revision': self.state['rev']['build'],
            'svn':self.get_rev_browse_url(self.state['rev']['build']),
            'svn_checkout':self.branch_url,
        }

    def init_lock(self):
        """attempt to create lock file, return False if existing and ctl.checklock enabled"""
        # if creating dirs is enabled, ensure lock dir exists before creating file
        # otherwise, error if it doesn't exist
        self.check_req_dir(os.path.dirname(self.lock_file))
        try:
            with open(self.lock_file,'x') as f:
                pass
        except FileExistsError:
            # could fail if lock is deleted between here and above, but this should be failure case anyway
            locktime = datetime.fromtimestamp(os.path.getmtime(self.lock_file),tz=timezone.utc).isoformat()
            if self.cfg['ctl'].getboolean('checklock'):
                self.infomsg(0,f'Abort due to lockfile present {self.lock_file} mtime {locktime}')
                return False
            else:
                self.infomsg(0,f'Ignore existing lockfile {self.lock_file} mtime {locktime}')
        return True

    def check_need_build(self):
        """fetch branch revision, update state, return if true greater than rev in state or ctl.checkrev is off"""
        # we use the revision of the most recently attempted build, not last
        # success since we don't want to repeatedly retry failing builds
        prev_rev = self.state['rev'].getint('build')
        svn_rev = self.get_svn_branch_rev()
        self.state['rev']['build']=str(svn_rev)
        # record rev to be attempted
        self.write_state()

        if self.cfg['ctl'].getboolean('checkrev'):
            if prev_rev < svn_rev:
                self.infomsg(1,f'Build needed {prev_rev} < {svn_rev}')
                return True
            else:
                # greater should maybe be an error?
                self.infomsg(0,f'Build not needed {prev_rev} >= {svn_rev}')
                return False
        else:
            self.infomsg(0,f'Build forced last={prev_rev} new={svn_rev}')
            return True

    def run_publish_module(self,pub_data):
        """run module that implements configured publish method"""
        # handle running directly or import autobuild vs import foo.autobuild
        if '.' in __name__:
            pub_mod = importlib.import_module('..autobuild_pub_'+self.cfg['pub']['type'],__name__)
        else:
            pub_mod = importlib.import_module('..autobuild_pub_'+self.cfg['pub']['type'],'.')

        pub_mod.do_publish(pub_data, self.pub_cfg, log_fn = self.infomsg)


    def run_step(self,step_name):
        """run a step function by name"""
        self.infomsg(1,f'start step {step_name}')
        fn_name = 'STEP_'+step_name
        if not hasattr(self,fn_name):
            raise ValueError(f'unknown step {step_name}')

        t0 = datetime.now()
        self.init_state(step_name)
        r = getattr(self,fn_name)()
        self.infomsg(1,f'completed step {step_name} result {r} time {datetime.now() - t0}')
        return r

    def execute_step(self,step_name = None):
        """run a step function and exit with its status"""
        step_name = step_name or self.args.step
        sys.exit(self.run_step(step_name))

# functions below define autobuild steps
# each function should return a sys.exit value, or None for success
    def STEP_init_lock(self):
        if self.init_lock():
            return 0
        else:
            return 1

    def STEP_init_tree(self):
        """ensure required top level directories exist, create or raise error based on ctl.createdirs"""
        self.check_req_dir(self.cfg['dir']['state'])
        self.check_req_dir(self.cfg['dir']['build']) # build root expected to exist
        # build subdirs handled at point of use

    def STEP_check_need_build(self):
        if self.check_need_build():
            return 0
        else:
            return 2

    def STEP_fetch_src(self):
        """
        fetch source from svn

        if ctl.fetch is on, state build rev is exported
        if source tree exists and ctl.fetchclean is on, it is removed.
        Otherwise ValueError is raised

        raises various exceptions on error
        """
        self.get_source()

    def STEP_config_src(self):
        """
        configure source tree

        localbuildconf.inc is generated and fi2.inc copied in from config directory
        """
        self.configure_source()

    def STEP_build(self):
        """run the CHDK batch build processs"""
        if not self.cfg['ctl'].getboolean('build'):
            self.infomsg(0,'skipping build')
            return

        # ensure log dir exists
        os.makedirs(os.path.dirname(self.build_log), exist_ok=True)

        # TODO this should probably be in cfg, but more convenient to find relative to current file
        script_dir = os.path.dirname(os.path.abspath(__file__))

        cmd = [ os.path.join(script_dir,'run_make.sh'), self.build_log, 'batch-zip-complete' ]
        if self.cfg['build'].getboolean('setuser'):
            cmd = [ 'setpriv',
                     f"--reuid={self.cfg['build']['user']}",
                     f"--regid={self.cfg['build']['group']}",
                     '--clear-groups', # don't inherit groups from root
                     '--inh-caps=-all', # don't inherit capabilities
                     '--no-new-privs', # don't allow gaining privs by setuid, build really shouldn't need
                     '--reset-env', # reset environment, ensuring AWS related values are not exposed
                     *cmd ]

            # create log and ensure build user can write
            with open(self.build_log,'w') as log:
                pass

            os.chmod(self.build_log,0o664)
            shutil.chown(self.build_log,group=self.cfg['build']['group'])

        self.infomsg(1,' '.join(cmd))

        r = subprocess.run(cmd, cwd=self.cfg['dir']['src'])
        if r.returncode == 2:
            self.infomsg(0,'chdk build failed')
        elif r.returncode != 0:
            self.infomsg(0,f'error running build {r.returncode}')
        else:
            self.infomsg(2,'build ok')

        return r.returncode

    def STEP_create_meta(self):
        """create file lists and json"""
        if not self.cfg['ctl'].getboolean('meta'):
            self.infomsg(0,'skipping meta')
            return

        os.makedirs(self.cfg['dir']['meta'],exist_ok=True)
        self.init_zip_lists()
        self.init_zip_hashes()
        self.init_zip_sizes()

        self.write_meta_file('files_small.txt','\n'.join(self.small_zips) + '\n')
        self.write_meta_file('files_full.txt','\n'.join(self.full_zips) + '\n')
        hashlist = []
        for fname, h in self.zip_hashes.items():
            hashlist.append(f"{h}  {fname}\n")

        self.write_meta_file('sha256sums.txt',''.join(hashlist))
        build_info = self.get_meta_buildinfo()

        file_info_json = {
            'info_version':self.json_info_ver,
            'build': build_info,
            'files_path':posixpath.join(self.cfg['pub']['dir'],self.branch_cfg['id'],self.cfg['pub']['bin_dir']),
            'files': self.get_json_firmware_list(),
            'counts': self.get_json_firmware_counts(),
            'svnlog': self.get_json_svn_log(),
        }
        self.write_meta_file('build_info.json', json.dumps(file_info_json, **self.json_opts))

        status_json = {
            'status_version':self.json_status_ver,
            'build': build_info,
            'status': True,
        }
        self.write_meta_file('build_status.json', json.dumps(status_json, **self.json_opts))

    def STEP_create_fail_meta(self):
        """create status file indicating failure"""
        if not self.cfg['ctl'].getboolean('meta'):
            self.infomsg(0,'skipping meta (fail)')
            return

        status_json = {
            'status_version':self.json_status_ver,
            'build': self.get_meta_buildinfo(),
            'status': False,
        }

        os.makedirs(self.cfg['dir']['meta'],exist_ok=True)
        self.write_meta_file('build_status.json', json.dumps(status_json, **self.json_opts))

    def STEP_publish(self):
        """deliver files and delete previous from public location"""
        if not self.cfg['ctl'].getboolean('publish'):
            self.infomsg(0,'skipping publish')
            return

        self.init_zip_lists()

        pub_data = {
            'build_status':True,
            'path':posixpath.join(self.cfg['pub']['dir'], self.branch_cfg['id']),
            'zips':{
                'src':self.bin_dir,
                'files':self.all_zips,
                'subdir':self.cfg['pub']['bin_dir'],
            },
            'meta':{
                'src':self.cfg['dir']['meta'],
                'files':self.meta_files,
                'subdir':self.cfg['pub']['meta_dir'],
            }
        }
        if self.cfg['pub']['buildlog'] == 'always':
            pub_data['log']={
                'src':self.build_log,
                'dst':self.cfg['pub']['buildlog_path'],
                'subdir':self.cfg['pub']['meta_dir'],
            }

        self.run_publish_module(pub_data)

    def STEP_publish_fail(self):
        """upload file indicating build failure"""
        if not self.cfg['ctl'].getboolean('publish'):
            self.infomsg(0,'skipping publish (fail)')
            return

        pub_data = {
            'build_status':False,
            'path':posixpath.join(self.cfg['pub']['dir'], self.branch_cfg['id']),
            'meta':{
                'src':self.cfg['dir']['meta'],
                'files':['build_status.json'],
                'subdir':self.cfg['pub']['meta_dir'],
            }
        }
        if self.cfg['pub']['buildlog'] == 'failed' or self.cfg['pub']['buildlog'] == 'always':
            pub_data['log']={
                'src':self.build_log,
                'dst':self.cfg['pub']['buildlog_path'],
                'subdir':self.cfg['pub']['meta_dir'],
            }

        self.run_publish_module(pub_data)

    def STEP_finish(self):
        """record success"""
        self.state['rev']['last_ok'] = self.state['rev']['build']
        self.write_state()

    def STEP_cleanup_build(self):
        """remove source tree"""
        self.infomsg(1,f"remove {self.cfg['dir']['src']}")
        if self.cfg['ctl'].getboolean('clean'):
            try:
                shutil.rmtree(self.cfg['dir']['src'])
            except FileNotFoundError:
                self.infomsg(0,f"src {self.cfg['dir']['src']} not found")
        else:
            self.infomsg(0,'skipping clean')

    def STEP_remove_lock(self):
        """remove lock file"""
        if self.cfg['ctl'].getboolean('cleanlock'):
            self.infomsg(1,f'remove {self.lock_file}')
            os.remove(self.lock_file)
        elif os.path.isfile(self.lock_file):
            self.infomsg(0,f'not removing lock file {self.lock_file}')

if __name__ == '__main__':
    sys.exit(AutoBuilder().main())
