= Introduction =
This image is intended support CHDK autobuilds, which automatically perform a
batch build of all supported models + Canon firmware variants when changes are
made on a specific SVN branch, and upload the resulting files to a public web
site.

The image designed primarily to support running the image and hosting the built
files in Amazon AWS, but should be straightforward to adapt to other
environments.

= Docker Image =
The image is based on the Debian 11 bullseye-slim image, using the gcc 8.3.1
gcc-arm-none-eabi toolchain from the distro package repository.

== Directory structure ==
In the default configuration, directories related to the build are under /srv

Most directory locations can be overridden in the configuration file.

The directories are as follows:

=== /srv/cfg ===
Contains the configuration file autobuild.cfg, and other customizable files
such as fi2.inc

May be built into the container image, or mounted.

If configuration files are to be built into the image, populate cfg in the
source directory before building.

May be read only.

=== /srv/state ===
Stores state that needs to persist between container invocations, in particular
the last built revision, and the lock file used to indicate a build is running
Assumed to be mounted from persistent filesystem shared by all instances of the
autobuild container. In AWS, this can be provided using EFS.

Must be writable.

=== /srv/build ===
Ephemeral files used in a given invocation of the container, including source
built output and metadata files generated from the build. This can simply
be a directory in the container, or a docker volume or bind mount if you want
the source to persist after builds.

Must be writable.

=== /srv/log ===
SVN export and build logs. May be ephemeral or persistent.

Must be writable.

=== /srv/data ===
Additional data files. Currently only platform_model_info.json, which provides
a mapping of CHDK platform names to EXIF model ID and other information.

May be read only.

== Building the image ==
Use

 docker build -t chdkautobuild <src_dir>

where <src_dir> is the directory containing the Dockerfile.  Files in the cfg,
scripts and data directories of src_dir are copied to corresponding directories
under /srv in the container.

The image is intended to be customized with the correct configuration at build
time, so is not intended to be distributed in public repositories. If using AWS
the image can be pushed to a private ECR repository.

= Configuration =
The configuration files is an .ini style (python configparser) text file,
located in /srv/cfg in the container. The configuration location may be
overridden from the command line by setting dir.cfg.

Configuration sections and options are documented in autobuild.py

Configuration options may be overridden from the command line, using the syntax

 section.name=value

In autobuild script and the documentation below, configuration values are
referred to in this section.name format.

In general, the defaults should not need to be changed for most configuration
options, except those that identify specific AWS resources, or select the
branch to be built.

Options in the ctl section can used to override which steps are run,
and are generally intended to be used from the command line for debugging or
one-off manual runs. See Running below for more details.

== Minimum configuration ==
To use the AWS publish method, you must configure the pub_aws options
bucket, cf_dist and region.

To build a branch other than trunk, you must set build.branch. Setting it to
'release' is sufficient to build the current (1.6) release branch. You can
create additional branch_* sections for other branches.

To build firmware update files, you must place a fi2.inc file containing key
and iv values for all supported firmware in the cfg directory. See fi2.inc.txt
in the platform directory of the CHDK source for details.

= Running =
The container entrypoint is run_autobuild.py, which invokes autobuild.py for
each of a series of steps, passing through all command line options.  Steps are
implemented in the STEP_* methods in autobuild.py

If any step fails, run_autobuild.py proceeds to the appropriate failure and
cleanup steps.

The publish step is only executed if the preceding steps are successful, to
ensure that most recent successful build remains publicly available in failure
modes that do not involve the upload itself.

Individual steps can be enabled or disabled using the ctl config options, which
may be passed from the command line.

== Steps ==
=== init_lock ===
Create /srv/state/build_running, failing if it exists. Used to prevent a build
being attempted while a previous build is running. Use ctl.checklock=0 to run
regardless of lock state.

=== init_tree ===
Check / create some essential directories. ctl.createdirs controls whether
missing directories are created, or treated as an error.

=== check_need_build ===
Check if a build is needed by comparing the most recent revision of the
configured branch against build.rev in /srv/state/state.cfg

After the check, build.rev is updated to the revision obtained from svn,
meaning that if subsequent steps fail, they will not be re-tried until the
revision changes, or a build is forced. This is intentional, to avoid
repeated builds in the case of compile errors, but also means that transient
errors may need to be cleared manually.

If a build is not needed, run_autobuild proceeds to the cleanup_build step.

Use ctl.checkrev=0 to force a build even if not required by the revision.

=== fetch_src ===
Export the selected revision from svn to /srv/build/src

Use ctl.fetch=0 to skip.

ctl.fetchclean controls the behavior if /srv/build/src exists when
fetch is enabled. If enabled, the directory is removed prior to export,
otherwise, an error is generated.

=== config_src ===
Prepares localbuildconf.inc and fi2.inc in the source tree

Use ctl.configsrc=0 to disable

=== build ===
Run the make command, logging to /srv/log/build.log

If the build fails, run_autobuild proceeds to the create_fail_meta step.

Use ctl.build=0 to disable.

The build.camera_list option may be used to specify an alternate
camera_list.csv, to customize which models and firmwares are built.


=== create_meta ===
Create file lists and related json files

Use ctl.meta=0 to disable
Use ctl.jsonpretty=1 to output pretty-printed json instead of minified
Use ctl.metaextra=1 to include EXIF model ID, USB product ID, and marketing
names in the build_info.json

=== publish ===
Upload files and perform CDN invalidations.

The AWS publish process first uploads the built files and meta files, then
deletes any zip files not from the current build.

Use ctl.publish=0 to disable

For the AWS publish method, use pub_aws.pretend=1 to execute the AWS publish
process without uploading, deleting or issuing cloudfront invalidations.

Use the pub.buildlog option to control whether the make output is published.
Use 'failed' to upload only on build failure, or 'always' or 'never'

=== finish ===
Records completion in state.cfg rev.last_ok. This information is currently
not used.

=== create_fail_meta ===
Executed only on make failure. Creates build_status.json file indicating build
failure.

Controlled by ctl.meta

=== publish_fail ===
Executed only on make failure. Publish build_status.json and build.log (if
enabled) only, without removing zips.

Controlled by ctl.publish

=== cleanup_build ===
Remove source tree.

Use ctl.clean=0 to disable.

=== remove_lock ===
Remove lock file.

Use ctl.cleanlock=0 to disable.


== Logs ==
Status and diagnostic information from autobuild.py is written to stdout.
In ECS, stdout is recorded in timestamped in cloudwatch logs. For non-AWS
environments, docker has various options for capturing output.

The output of svn export and the make command are captured to export.log and
build.log respectively in the log directory. The amount of output makes
it desirable to separate them from diagnostic logs, and build.log may be
needed in a file to upload.

== Running the container manually ==
When running the container locally in docker, you generally want to specify
some mounts and configuration options.

A typical example for development:

 docker run -ti --rm \
  -v $HOME/test/build:/srv/build \
  -v $HOME/test/state:/srv/state \
  -v $HOME/test/log:/srv/log \
  -v $HOME/test/aws:/srv/aws \
  -e AWS_CONFIG_FILE=/srv/aws/config \
  -e AWS_SHARED_CREDENTIALS_FILE=/srv/aws/credentials \
  chdkautobuild \
  build.camera_list=/srv/cfg/camera_test.csv \
  ctl.checkrev=0 ctl.fetch=1 ctl.configsrc=1 ctl.build=1 ctl.meta=1 \
  ctl.publish=1 pub_aws.pretend=1 ctl.clean=0 ctl.verbose=2

The options -ti and --rm set it to use the terminal, and remove the container
after execution completes.

The -v options use bind mounts to make various directories in $HOME/test
available for the autobuild directories.

The -e options specify where to find AWS files in a directory mounted in with -v

The arguments following chdkautobuild
* Use a custom camera_list.csv, from the container cfg directory
* Force a build regardless of revision
* Perform the fetch, configsrc, build and meta steps as normal. These are
  default values, but including them makes it easy to turn things on and of
  by editing command history.
* Perform the publish step, but skip actual AWS updates.
* Don't delete src on completion.
* Full verbosity.

To get a shell in the container, use --entrypoint bash, and omit the options
after chdkautobuild. If you intend to run the autobuild scripts from the shell
the various mounts should also be set.

== Running the scripts outside the container ==
For development or debugging, it can be useful to execute either
run_autobuild.py or autobuild.py directly, without building the container.
These scripts require at least python 3.8, and assume a linux environment. If
publish is enabled, the publish module requires the boto3 library. Otherwise,
dependencies are common, standard python libraries.

Typical run_autobuild.py example:

 ( SRC=$HOME/chdk/trunk/tools/docker/autobuild ; \
 $SRC/scripts/run_autobuild.py \
 dir.root=$HOME/test \
 dir.cfg=$SRC/cfg \
 dir.data=$SRC/data \
 ctl.fetch=0 ctl.checkrev=0 ctl.configsrc=0 ctl.build=0 build.setuser=0 ctl.meta=1 \
 ctl.metaextra=1 ctl.jsonpretty=1 ctl.publish=1 pub_aws.pretend=1 ctl.clean=0 ctl.verbose=2 )

The options are similar to the container example, except dir options are used
to specify directory locations, rather than docker mounts. Additionally,
build.setuser=0 is used since the command isn't run as root.

Example of invoking autobuild.py directly:

 ( SRC=$HOME/chdk/trunk/tools/docker/autobuild ; \
 $SRC/scripts/autobuild.py --step publish \
 dir.root=$HOME/test dir.cfg=$SRC/autobuild/cfg )


= Output =
* zips - full and small zips for each model + Canon firmware combination
* build_status.json - Build information, filenames and sha256sums organized by
  family, model and firmware
* build_info.json - Build information and the status of the most recent build
  attempt
* files_full.txt, files_small.txt - simple text lists of the full and small
  files respectively
* sha256sums.txt - sha256sums of all zips, in the format used by sha256sum -c
* build.log - Log of the make command output, optionally published based on the
  pub.buildlog setting.

=AWS configuration=
Step by step AWS configuration is beyond the scope of this document, but the
following provides a general outline.

Push the image to an ECR repository

Configure a cluster in ECS

Configure task definitions for each branch to be built

A 1 VCPU / 2 GB container completes a full build in about 18 minutes. The build
requires less than 1 GB of RAM. Using Fargate avoids the need to manage EC2
instances to host the container.

Create an EFS filesystem for persistent directories. At a minimum, each task
needs a state directory to mount on /srv/state. You can use EFS access points to
restrict each task to subdirectories of a single filesystem.

Use Eventbridge to create a schedule rule (or scheduled task) to periodically
run the container. Note that running a full container to check if a build is
needed is inefficient, but the execution time is negligible when a build is not
needed.

To run builds for multiple branches, you can use a single container image and
either specify the branch in the container command like

 build.branch=release

or create separate cfg directories in EFS and mount them.

Hosting the files in AWS requires an S3 bucket and optionally (but recommended)
a cloudfront distribution using the bucket as an origin.

The container must be provided with credentials which allow the following
and SHOULD NOT allow more:

* s3:ListBucket on the bucket specified by pub_aws.bucket
* s3:PutObject, s3:DeleteObject under prefix given by pub_aws.dir
* cloudfront:CreateInvalidation on the distribution given by pub_aws.cf_dist

If using ECS, the above should be provided using a task role, to ensures the
credentials are temporary and only usable within the task. The boto3 library
automatically discovers the role credentials in ECS, so no additional
configuration is need required.

If the container is not running in ECS, AWS credentials can be provided by
passing AWS_CONFIG_FILE, AWS_SHARED_CREDENTIALS_FILE etc environment variables
and mounting a directory containing the corresponding files in the container.

= Security considerations =
The CHDK build compiles and runs native host code as part of the build process.
Thus, anyone with commit access to the CHDK project (legitimate or obtained
through compromise) can execute arbitrary code in the container, albeit with
a high likelihood the code would be recorded in SVN.

By default, the autobuild script runs as root, and runs the make process as an
unprivileged user. The build users environment is reset, so AWS variables will
not be trivially accessible. However, this is not a rigorous sandboxing, so it's
advisable to ensure the container has the minimum required privileges and is
isolated from other resources.

Any AWS credentials should be limited to the minimum required permissions, and
not exposed to the user that runs make.
