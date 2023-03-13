#!/bin/sh
# tiny wrapper to run the make command without output redirected from autobuild.py or setpriv
LOGNAME="$1"
shift
make "$@" >"$LOGNAME" 2>&1
