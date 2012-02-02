#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "math.h"
#include "stdlib.h"
#include "conf.h"

#ifndef PARAM_FILE_COUNTER
#	error Please define PARAM_FILE_COUNTER in platform/CAMERA/shooting.c!
#endif

#define AV96_MIN (aperture_sizes_table[0].prop_id)

const unsigned int SS_SIZE  = sizeof(shutter_speeds_table)/sizeof(shutter_speeds_table[0]);
const unsigned int AS_SIZE  = sizeof(aperture_sizes_table)/sizeof(aperture_sizes_table[0]);
const unsigned int ISO_SIZE = sizeof(iso_table)/sizeof(iso_table[0]);
const unsigned int MODESCNT = sizeof(modemap)/sizeof(modemap[0]);

const unsigned int param_file_counter = PARAM_FILE_COUNTER;

//-------------------------------------------------------------------

// Note: shooting functions moved to core/shooting.c
//       this compiles them as THUMB code to save space

//-------------------------------------------------------------------

//***********************
/*

static char debug_str[60];

void debug_char(char * deb_str)
{
 short debug_str_length=strlen(debug_str);
 if	(debug_str_length>50) strcpy(debug_str, "");
 sprintf(debug_str+debug_str_length, "%s", deb_str);
}

void debug_init()
{
 strcpy(debug_str, "");
}


void debug_int(int deb_str)
{
 short debug_str_length=strlen(debug_str);
 if	(debug_str_length>50) strcpy(debug_str, "");
 sprintf(debug_str+debug_str_length, "%d", deb_str);
}


void debug(char * deb_str, int deb_int)
{
 short debug_str_length=strlen(debug_str);
 if	(debug_str_length>50) strcpy(debug_str, "");
 sprintf(debug_str+debug_str_length, "%s", deb_str);
 sprintf(debug_str+strlen(debug_str), "%d", deb_int);
}

char * get_debug()
{
 return debug_str;
}
*/
//***********************

// Core override function
void __attribute__((naked,noinline)) shooting_expo_param_override(void)
{
    // Save registers
    asm volatile("STMFD   SP!, {R0-R12,LR}\n");

    // Call thumb code version in core/shooting.c
    extern void shooting_expo_param_override_thumb();
    shooting_expo_param_override_thumb();

    // Restore registers
    asm volatile("LDMFD   SP!, {R0-R12,PC}\n");
}

// Override ISO settings only
// need to do this before exposure calc for ISO, as well as after on some cameras
void __attribute__((naked,noinline)) shooting_expo_iso_override(void)
{
    // Save registers
    asm volatile("STMFD   SP!, {R0-R12,LR}\n");

    // Call thumb code version in core/shooting.c
    extern void shooting_expo_iso_override_thumb(void);
    shooting_expo_iso_override_thumb();

    // Restore registers
    asm volatile("LDMFD   SP!, {R0-R12,PC}\n");
}
