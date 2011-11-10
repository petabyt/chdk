#include "platform.h"

//ROM:FF3E3934                 MOV     R1, #0x44000000
//ROM:FF3E3938                 ADR     R0, aCrawBuffP  ; "CRAW BUFF       %p"

char *hook_raw_image_addr()   
{
	if (*((int*)0x3148+0xC) != 0) //@FF07ECB4 + 0xC FF07ECF0
	{
		return (char*) 0x4ADB54A0; //FF060680
	}
	else
	{
		return (char*)	0x40D439F0; //SX40 0x1247A60 @FF3E3A20

	}
}

char *hook_alt_raw_image_addr() 
{
	if (*((int*)0x3148+0xC) != 0) //@FF07ECB4 + 0xC FF07ECF0
	{
		return (char*) 0x4ADB54A0; //FF060680
	}
	else
	{
		return (char*)	0x40D439F0; //SX40 0x1247A60 @FF3E3A20

	}
}

long hook_raw_size()
{
	//SX40 @FF3E3A20
	return 0x1247A60;
}

void *vid_get_viewport_live_fb()
{
	if ((mode_get()&MODE_MASK) == MODE_REC)
		return (void*)((void*)(*(int*)(0x225C))-vid_get_viewport_xoffset()*3);
	
	return (void*)(void*)(*(int*)(0x225C));
}

void *vid_get_bitmap_fb()        { return (void*)0x40685000; } // Found @0xff0515dc SX40

void *vid_get_viewport_fb()
{	
	//return (void*)0x407dab80;  // Found @0xff3e0b3c
#if 1 // TODO
	if ((mode_get()&MODE_MASK) == MODE_REC)
		return (void*)(0x407DAB80-vid_get_viewport_xoffset()*3); // SX40

	return (void*)0x407DAB80;   //SX40
#endif
}

void *vid_get_viewport_fb_d()
{	//SX40
	//FF06B264 DCD 0x2CA0
	//FF06BFE4 STR     R12, [R5,#0x58]
	return (void*)(*(int*)(0x2CA0+0x58));
}

char *camera_jpeg_count_str()
{	//SX40
	//FF28543C                 LDR     R0, =0xDF0E8
	//FF285440                 ADR     R1, a9999       ; "9999"
	 return (void*)0xDF0E8;
}





