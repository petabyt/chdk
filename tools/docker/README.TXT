=Introduction=
The chdkbuild directory contains a Dockerfile for a CHDK build environment in a
Docker (https://www.docker.com/) container. This can be used on Windows, Linux
and Mac.

If you don't already use docker, installing and configuring it just to build
CHDK may not be the best choice. Other options are described on
https://chdk.fandom.com/wiki/For_Developers

Refer to the Docker documentation for information on how to install and
use Docker on your platform.

=Overview=
The container is based on Debian stretch, with arm-none-eabi-gcc 5.4.1 and host
gcc 6.3 (both from distro packages) and capstone 4.0.2.

The intended use is for the CHDK source tree to be mounted from the host using
a bind mount, so the container essentially replaces the 'make' command and you
still edit, grep, upload binaries to the camera etc from your regular desktop.

=Building the image=
Use

 docker build -t chdkbuild <directory containing Dockerfile>

This will create an image tagged chdkbuild:latest. The tag is arbitrary, but
assumed in the examples below.

=Building CHDK=
To build CHDK, you need to mount the source you want to use on /srv/src inside
the container, and pass whatever make command you'd normally use.

On Linux, you probably want the container to run as your normal user. Put
together, you end up with a command like

 docker run --rm --user=$(id -u):$(id -g) -v $HOME/chdk/trunk:/srv/src chdkbuild make PLATFORM=ixus175_elph180 PLATFORMSUB=100c

If your firmware dumps are in a separate tree, you can mount that as well, like

 docker run --rm --user=$(id -u):$(id -g) -v $HOME/chdk/trunk:/srv/src -v $HOME/chdk/dumps:/srv/dumps:ro chdkbuild make PRIMARY_ROOT=/srv/dumps PLATFORM=ixus175_elph180 PLATFORMSUB=100c

The dumps mount location is arbitrary, it just needs to be the same in the mount
and PRIMARY_ROOT specification

You can get a shell in the container by adding -ti and omitting the make
command, like

 docker run -ti --rm --user=$(id -u):$(id -g) -v $HOME/chdk/trunk:/srv/src chdkbuild

From the shell, you can run make commands just as would building in a normal
Linux environment.

On Windows, you don't need to specify the user, so a typical command would be

 docker run --rm -v C:\chdk\trunk:/srv/src chdkbuild make PLATFORM=a540 PLATFORMSUB=100b clean fir

Docker may warn about poor performance if you source tree is on a Windows
filesystem, but in practice IO speed is not likely to be a big deal.

=Notes=
If you used this extensively, you probably want to wrap it in a shell script
containing all the boilerplate options, like

 #!/bin/sh
 docker run --rm --user=$(id -u):$(id -g) -v $HOME/chdk/trunk:/srv/src -v $HOME/chdk/dumps:/srv/dumps:ro chdkbuild "$@"

The PRIMARY_ROOT (and any other paths) on the command line must match the path
inside the container, not the path on the host system.

The --rm in the examples above isn't strictly required, but you probably don't
want docker leaving a stopped container around every time you run.
Alternatively you could give the container a name in the first run, and then
reuse it with docker start to execute the exact same command again, like:

 docker run --user=$(id -u):$(id -g) -v $HOME/chdk/trunk:/srv/src --name makeg7x chdkbuild make  PLATFORM=g7x PLATFORMSUB=100d clean fir
 ... edit code ...
 docker start -a makeg7x

=Caveats=
The image is quite large (330MB) of which ~50 is the base Debian system and the
rest is related to the toolchains.

Tool binaries (capdis etc) will be compiled for container. They may not run on
the host although they're statically linked, so there is some chance they'll
run on Linux hosts or WSL.

If you specify a user on the command line, it will not exist in the container
/etc/passwd file, which will show "I have no name!" in the bash prompt.  This
doesn't interfere with building CHDK, but may break other commands.

The make starts in /srv/src. If you want to build in a subdirectory, you can
use -C dir in the make command line, or use -w in docker command line to set
the workdir.

The container doesn't include svn, so it doesn't add revision numbers to builds
and will complain (harmlessly) about "svnversion not found"
svn could easily be included (just add it to the package list), but would
potentially be problematic if the host system has a different version of svn.

If you alternate compiling through the container and the native toolchain on
windows, you can end up with confusing errors: The container leaves (Linux)
executables without a .exe suffix. 'make clean' on windows only cleans the .exe
files, but bash in the windows toolchain can still try to execute the files
without .exe. To avoid issues like this, clean from the container.

