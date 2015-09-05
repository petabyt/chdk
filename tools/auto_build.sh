#!/bin/sh

# Read the 'camera_list.csv' file ($3) and run the
# CHDK build action ($2) using the designated
# make program ($1)
# ($4) = -noskip: ignore the SKIP_AUTOBUILD column; -not2: skip thumb-2 ports
# - also see main Makefile

# -noskip operations will only execute on 'real' ports
# the firzipsub and firzipsubcomplete actions will be transformed into firzipsubcopy and firzipsubcompletecopy
# when the srcfw column is not empty

while IFS=, read cam fw pid state srccam srcfw skip
do
  if [ ${cam} != "CAMERA" ] && ( [ "$4" = "-noskip" ] || [ "${skip}" = "" ] ); then \
    if [ "${state}" != "" ]; then state=_${state}; fi; \
    if [ "${srccam}" = "" ]; then srccam=${cam}; fi; \
    if [ "${srcfw}" = "" ]; then srcfw=${fw}; fi; \
    if [ "$4" = "-noskip" ] && ( [ ${srccam} != ${cam} ] || [ ${srcfw} != ${fw} ] ); then jmp=1; else jmp=0; fi; \
    if ( [ "$2" = "firzipsub" ] || [ "$2" = "firzipsubcomplete" ] ) && [ ${srcfw} != ${fw} ] ; then cpy=1; else cpy=0; fi; \
    ist2=`grep -s "THUMB_FW" platform/${srccam}/makefile.inc` ; \
    if ( [ "${ist2}" = "" ] || [ "$4" != "-not2" ] ) && [ ${jmp} -eq 0 ] ; then \
      if [ ${cpy} -ne 1 ] ; then \
        $1 -s --no-print-directory TARGET_CAM=${cam} TARGET_FW=${fw} TARGET_PID=${pid} PLATFORM=${srccam} PLATFORMSUB=${srcfw} STATE=${state} SKIP_AUTOBUILD=${skip} $2 || exit 1; \
      else \
        $1 -s --no-print-directory TARGET_CAM=${cam} TARGET_FW=${fw} TARGET_PID=${pid} PLATFORM=${srccam} PLATFORMSUB=${srcfw} STATE=${state} SKIP_AUTOBUILD=${skip} ${2}copy || exit 1; \
      fi; \
    fi; \
  fi;
done < $3
