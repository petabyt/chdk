#include "platform.h"
char *hook_raw_image_addr() {
    return (char*) (*(int*)(0x2CCC + 0xC)? 0x46000000 : 0x4132C0A0);    // looks like every RAW is valid
}

char *camera_jpeg_count_str() {
    return (char*)0xA15B8;
}
