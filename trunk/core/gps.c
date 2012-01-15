#include "camera.h"
#include "stdlib.h"
#include "platform.h"
#include "gps.h"

void gps_getData(tGPS* gps){
    if (camera_info.props.gps)
        get_property_case(camera_info.props.gps, gps, sizeof(tGPS));
    else
        memset(gps, 0, sizeof(tGPS));
}
