This directory contains manually maintained header files to make firmware function prototypes
and structure definitions available in Ghidra.

Usage:
You program should have initial analysis done.

Go to File -> Parse C Source

* Use the small disk icon with ... under it to copy an existing parse configuration, e.g clib.prf
* Name your copy something obviously related to CHDK and camera configuration, e.g. chdk-dryos31
* Select all the header file entries, and use the red X button to delete them
* Use the green + button to add chdk source/tools/ghidra_scripts/fw_functions.h
* Adjust the parse options section to match your platform:
  Remove all entries except
   -D__builtin_va_list=void *
  If your camera uses dryos, add the PLATFORMOSVER value from makefile.inc, like
   -DCAM_DRYOS_REL=31
  If your camera uses 3 argument DebugAssert (see platform_camera.h) add
   -DCAM_3ARG_DebugAssert=1
  This applies to some early vxworks, all digic 6, and some other DryOS 52 and later.
 * Save your parse configuration with the big floppy icon. Note: Parse configurations are global
   within Ghidra, not specific to a particular project or program.
 * Click "Parse to Program", and continue when prompted
 * If a prompt about "Use Open Archives" appears, click continue. It may be covered by a dialog
   titled "Parsing C Files". If so, move the "Parsing C files" dialog out of the way.
 * If parsing is unsuccessful, the pre-processed output will appear in your system home directory
   in a file named CParserPlugin.out
 * If parsing succeeds, dismiss the Parse C Source dialog.

In the types manager window, right click on your program, and choose "Apply Function Data Types"

If you update the header files, re-run File -> Parse C Source, select the parse configuration
created earlier, and re-run "Apply Function Data Types".
