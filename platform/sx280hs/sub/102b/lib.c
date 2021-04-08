#include "platform.h"
#include "gps.h"

char *camera_jpeg_current_filename() {
     return (void*)0xE6A18;
}

char *camera_jpeg_count_str()    { return (char*)0x000e4308; }

#ifdef CAM_HAS_GPS
char *camera_jpeg_current_gps()
{
    static gps_img_data gid;
    // a compatible fw struct has not been found yet, returning empty struct
    return (void*)&gid;
}
#endif
