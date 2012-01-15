#include "camera.h"
#ifdef CAM_HAS_GPS
#include "platform.h"
#include "gps.h"

void gps_getData(tGPS* gps){
    get_property_case(PROPCASE_GPS, gps, sizeof(tGPS));
}

#endif
