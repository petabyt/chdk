#include "platform.h"

char *hook_raw_image_addr()
{
	// Found 0x11B96B80 at ROM:FFC377A0
	// Found 0x107D58E0 at ROM:FFC756CC
	// 0x51C0 + 0x18 found at ROM:FFC4C504	
	return (char*) (*(int*)(0x51C0+0x18) ? 0x11B96B80 : 0x107D58E0);
}

void *vid_get_viewport_live_fb()
{
    void **fb=(void **)0x6A68;  // at: ROM:FFC9FF3C
    unsigned char buff = *((unsigned char*)0x68DC);	// at: ROM:FFC9FF34
    if (buff == 0) {
        buff = 2;
    }
    else {
        buff--;
    }
    return fb[buff];
}
