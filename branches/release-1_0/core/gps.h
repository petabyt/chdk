#ifndef __CHDK_GPS_H
#define __CHDK_GPS_H

typedef struct {
    int latitudeRef;
    int latitude[6];
    int longitudeRef;
    int longitude[6];
    int heightRef;
    int height[2];
    int timeStamp[6];
    short status;
    char mapDatum[7];
    char dateStamp[11];
    char unknown2[260];
} tGPS;

void gps_getData(tGPS* gps);

#endif
