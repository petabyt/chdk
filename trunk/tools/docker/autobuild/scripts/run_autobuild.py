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
driver script to run autobuild actions as standalone processes
each invocation is passed the original command line options,
which are merged with config settings
Other state is maintained in files in the state tree defined by the config

running individual steps as standalone processes isolates state, errors
and ensures they can be run individually for development + testing

see autobuild.py for options
"""

import subprocess
import sys
import os

# absolute path to scripts, based on path of this script
script_dir = os.path.dirname(os.path.abspath(__file__))
script_path = os.path.join(script_dir,'autobuild.py')
# script options, passed to each sub script
run_args = sys.argv[1:]

cmd_base = [script_path, '--step']
def run_cmd(cmd):
    """
    run a sub script, returning exit status
    exceptions may be generated in other cases like file not found or permission errors
    """
    return subprocess.run([*cmd_base, cmd, *run_args]).returncode

def check_cmd(cmd):
    """
    run sub script and throw CalledProcessError on non-zero exit status
    """
    subprocess.check_call([*cmd_base, cmd, *run_args])

def cleanup():
    try:
        # attempt to cleanup source files etc
        run_cmd('cleanup_build')
    finally:
        # attempt to remove lock file
        run_cmd('remove_lock')

def run():
    have_lock = False
    # run build steps, attempting to clean up if any failed
    try:
        # print the version to make it easy to identify what container is running
        subprocess.check_call([script_path,'-V'])
        # check for lock file indicating build is running, throw if present
        # will also throw if config is invalid
        check_cmd('init_lock')
        have_lock = True
        # ensure expected directories are present or created
        check_cmd('init_tree')

        # attempt to get current revision for branch, check against last attempted build
        # returns 2 if no build needed. In this case, we want cleanup with success status
        # note the finally will be executed, because sys.exit is exception under the hood
        r = run_cmd('check_need_build')
        if r == 2:
            sys.exit(0)
        elif r != 0:
            sys.exit(r)
        # else
        # export source and create build configuration
        # updates last attempted build state, so failures beyond this point will not be
        # retried unless ctl.checkrev is turned off
        check_cmd('fetch_src')
        # add auto-build specific configuration
        check_cmd('config_src')
        # perform build. returns 0 on success, 2 on make failure, others on other failure
        r = run_cmd('build')
        if r == 0:
            # generate file and build information for upload
            check_cmd('create_meta')
            # upload files, meta data, clean old files
            check_cmd('publish')
            # record successful completion
            check_cmd('finish')
        elif r == 2:
            # generate file indicating failure
            check_cmd('create_fail_meta')
            # upload fail status
            check_cmd('publish_fail')
        # else just continue to cleanup

    except subprocess.CalledProcessError as CPE:
        # subprocess error means a called script returns non-zero
        # assume it already printed any diagnostics
        sys.exit(CPE.returncode)
    finally:
        # if exception occurred before lock (or due to lock) don't want to clean
        if have_lock:
            cleanup()

run()
