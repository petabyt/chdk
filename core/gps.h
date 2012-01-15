#ifndef __CHDK_GPS_H
#define __CHDK_GPS_H

typedef struct {
    char    latitudeRef[4];
    int     latitude[6];
    char    longitudeRef[4];
    int     longitude[6];
    char    heightRef[4];
    int     height[2];
    int     timeStamp[6];
    char    status[4];
    char    mapDatum[7];
    char    dateStamp[11];
    char    unknown2[260];
} tGPS;

void gps_getData(tGPS* gps);

#endif
