FROM debian:stretch-slim
# NOTE stretch is used because it provides a compatible arm compiler (gcc 5)
# some later Debian releases provide versions not supported in the CHDK source
LABEL maintainer="reyalp at gmail dot com"
LABEL description="toolchain for building CHDK https://chdk.fandom.com/wiki/CHDK"
# building  the image
# docker build -t chdkbuild .
#
# running
# build a firmware on linux with separate dumps dir, as the current user
# docker run --rm --user=$(id -u):$(id -g) \
#  -v $HOME/chdk/trunk:/srv/src \
#  -v $HOME/chdk/dumps:/srv/dumps:ro chdkbuild \
# make PRIMARY_ROOT=/srv/dumps PLATFORM=ixus175_elph180 PLATFORMSUB=100c clean fir
#
# build on windows
# docker run --rm -v C:\chdk\trunk:/srv/src chdkbuild make PLATFORM=a540 PLATFORMSUB=100b clean fir
#
# get a bash shell
# docker run -ti --rm -v $HOME/chdk/trunk:/srv/src chdkbuild
#

# install packages: standard gcc, arm gcc, minimal C development files, zip for batch zip
# curl only needed at image build time, to fetch capstone.
# Base install includes other required stuff like sed and awk
RUN apt-get update && apt-get install --no-install-recommends -y \
 ca-certificates \
 curl \
 gcc \
 gcc-arm-none-eabi \
 libc6-dev \
 make \
 zip \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /srv
# download, build and install capstone lib for ARM only
RUN mkdir capstone \
 && cd capstone  \
 && curl -sSL https://github.com/aquynh/capstone/archive/4.0.2.tar.gz -o capstone-4.0.2.tar.gz \
 && echo 7c81d798022f81e7507f1a60d6817f63aa76e489aa4e7055255f21a22f5e526a capstone-4.0.2.tar.gz | sha256sum -c \
 && tar -xzf capstone-4.0.2.tar.gz \
 && cd capstone-4.0.2 \
 && CAPSTONE_ARCHS="arm" ./make.sh \
 && CAPSTONE_ARCHS="arm" ./make.sh install \
 && cd /srv \
 && rm -rf capstone \
 && apt-get purge -y curl ca-certificates \
 && apt-get autoremove -y

# export default environment variables to locate capstone, will be picked up by make
ENV OPT_CAPSTONE_TOOLS=1
ENV CAPSTONE_TOOLS_INC="-I/usr/include/capstone"
# linking static lib gives a reasonable chance tools will work on linux host
ENV CAPSTONE_TOOLS_LINK="-l:libcapstone.a"
WORKDIR /srv/src

CMD ["bash"]

