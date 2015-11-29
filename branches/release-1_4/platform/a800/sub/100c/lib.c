#include "platform.h"
#include "lolevel.h"

char *hook_raw_image_addr()
{
	return (char*) 0x10e59860; // (a800=ffe72f80 x ixus=ffb61594) 0x10E52420; // at ffe73088 
}

// OSD buffer
void *vid_get_bitmap_fb()
{
	return (void*)0x10361000; // "BmpDDev.c", 0xFFCD1DD4 <-> sub_entry.S { return (void*)0x10361000; } // Found @0xffc3fafc
}

void *vid_get_viewport_fb_d()
{
	return (void*)(*(int*)(0x2588+0x54)); // ffc54ff8 comparando com FFc53554 de A495; // sub_FFC528C0 / sub_FFC53554?
}

long vid_get_viewport_height() { return 240; }

char *camera_jpeg_count_str()
{
	{ return (char*)0x00088994; } // from stub_entry.S Found @0xffd810bcreturn (char*)0x7486C;  // "9999"
}

/*
Note copied from SX110 IS
GetBatteryTemperature usually will get back temperature of battery compartment/batteries. GetBatteryTemperature is implemented in Canon's firmware for SX120IS.
Firmware entry point is identified (0xFFC394D8) but function is not usable. Camera will crash if Canon's GetBatteryTemperature is called by CHDK.
To avoid a crash Canon's GetBatteryTemperature must not called. As long CHDK general code do not distinguish between cameras that support or don't support GetBatteryTemperature, 
this function will be implemented as specific CHDK-code. It returns always with -99 (which means -99° Celsius or -146° Fahrenheit).
Original entry point in Canon's firmware is disabled (in stubs_entry.S).
*/

int _GetBatteryTemperature()
{
      return -99;
}
