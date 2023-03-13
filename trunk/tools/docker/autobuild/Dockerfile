FROM debian:bullseye-slim
LABEL maintainer="reyalp at gmail dot com"
LABEL description="Automatic batch build CHDK"

# building the image
# docker build -t chdkautobuild .

# install packages: standard gcc, arm gcc, minimal C development files, zip for batch zip
# ca certs for svn and upload
# Base install includes other required stuff like sed and awk
# python for main script, boto3 for AWS interaction
# boto3 could be omitted for non-AWS environments
# unlike generic build image autobuild shouldn't build stubs, doesn't need capstone
# delete apt stuff and arm toolchain files we don't need in same command to avoid image bloat
RUN apt-get update && apt-get install --no-install-recommends -y \
 ca-certificates \
 gcc \
 gcc-arm-none-eabi \
 libc6-dev \
 make \
 subversion \
 zip \
 python3 \
 python3-boto3 \
 && rm -rf /var/lib/apt/lists/* \
 && rm -rf /var/cache/debconf/*-old \
 && rm -rf /usr/share/doc/* \
 && rm -rf /usr/lib/gcc/arm-none-eabi/8.3.1/arm/v5te/hard \
 && rm -rf /usr/lib/gcc/arm-none-eabi/8.3.1/thumb/v6-m \
 && rm -rf /usr/lib/gcc/arm-none-eabi/8.3.1/thumb/v7+fp \
 && rm -rf /usr/lib/gcc/arm-none-eabi/8.3.1/thumb/v7-m \
 && rm -rf /usr/lib/gcc/arm-none-eabi/8.3.1/thumb/v7e-* \
 && rm -rf /usr/lib/gcc/arm-none-eabi/8.3.1/thumb/v7+fp/hard \
 && rm -rf /usr/lib/gcc/arm-none-eabi/8.3.1/thumb/v8-m.*

# unprivileged user to run build
# if bind or network mounts are used, it may be convenient to map this to a particular user
ARG BUILD_UID=1000

RUN adduser chdkbuild --uid ${BUILD_UID}

WORKDIR /srv
COPY scripts scripts/
COPY cfg cfg/
COPY data data/

RUN mkdir /srv/build /srv/state /srv/log \
 && chmod 555 /srv/scripts /srv/cfg /srv/data \
 && chmod 755 /srv/build /srv/state /srv/log \
 && find /srv/scripts -type f \( -name *.py -o -name *.sh \) -exec chmod 555 {} \; \
 && find /srv/cfg -type f -exec chmod 444 {} \; \
 && find /srv/data -type f -exec chmod 444 {} \; \
 && rm -rf /srv/scripts/__pycache__

# mount point for persistent state files
VOLUME /srv/state

# mount point for logs
VOLUME /srv/log

# ephemeral working area
VOLUME /srv/build

ENTRYPOINT ["/usr/bin/python3","/srv/scripts/run_autobuild.py"]

