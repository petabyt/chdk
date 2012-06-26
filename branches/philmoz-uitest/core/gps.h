/*-----------------------------------------------------------------------------------
**	$Id: gps.h, v 1.1 2011/11/20 genie01 Exp $
**---------------------------------------------------------------------------------*/
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

extern int _CreateTask (const char *name, int prio, int stack_size /*?*/, void *entry, long parm /*?*/);
void gps_getData(tGPS* gps);
extern void GPS_UpdateData();
void gps_startup();
void anzeige_gps();
void write_timezone();
void write_home();
extern void gps_navigate_home();
void test_timezone();
void gpx_bild_ohne_signal();
void wegpunkt();
void init_gpx_record_task();
void gpx_record();
void init_gps_kompass_task();
void anzeige_kompass();
void init_gps_trackback_task();
void trackback();
char *load_bitmap(char *datei);
void anzeige_kompassnadel (int winkel, double s_w, double c_w, char *bitmap, int laenge, int m_x, int m_y, int offset_x, int offset_y, int f_v_1, int f_h_1, int f_v_2, int f_h_2);
void anzeige_kompassbild (char *bitmap1, int o_x, int o_y, int f_v_0, int f_h_0, int f_v_1, int f_h_1, int f_v_2, int f_h_2, int f_v_4, int f_h_4);
#endif

/*-----------------------------------------------------------------------------------
**	$Id: gps.h, v 1.1 2011/11/20 genie01 Exp $
**---------------------------------------------------------------------------------*/
