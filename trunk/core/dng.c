#include "camera.h"

#if DNG_SUPPORT

#include "stdlib.h"
#include "string.h"
#include "platform.h"
#include "conf.h"
#include "console.h"
#include "dng.h"
#include "raw.h"
#include "action_stack.h"
#include "gui_mbox.h"
#include "gui_lang.h"

//thumbnail
#define DNG_TH_WIDTH 128
#define DNG_TH_HEIGHT 96
// higly recommended that DNG_TH_WIDTH*DNG_TH_HEIGHT would be divisible by 512

struct dir_entry{unsigned short tag; unsigned short type; unsigned int count; unsigned int offset;};

#define T_BYTE 1
#define T_ASCII 2
#define T_SHORT 3
#define T_LONG 4
#define T_RATIONAL 5
#define T_SBYTE 6
#define T_UNDEFINED 7
#define T_SSHORT 8
#define T_SLONG 9
#define T_SRATIONAL 10
#define T_FLOAT 11
#define T_DOUBLE 12

#define CAM_DEFAULT_CROP_ORIGIN_W ((CAM_ACTIVE_AREA_X2-CAM_ACTIVE_AREA_X1-CAM_JPEG_WIDTH )/2)
#define CAM_DEFAULT_CROP_ORIGIN_H ((CAM_ACTIVE_AREA_Y2-CAM_ACTIVE_AREA_Y1-CAM_JPEG_HEIGHT)/2)

unsigned short get_exp_program_for_exif(int exp_program);
unsigned short get_orientation_for_exif(short orientation);
unsigned short get_flash_mode_for_exif(short mode, short fired);
unsigned short get_metering_mode_for_exif(short metering_mode);

const int cam_DefaultCropSize[]={CAM_JPEG_WIDTH, CAM_JPEG_HEIGHT};    // jpeg size
const int cam_ActiveArea[]={CAM_ACTIVE_AREA_Y1, CAM_ACTIVE_AREA_X1, CAM_ACTIVE_AREA_Y2, CAM_ACTIVE_AREA_X2};
const int cam_DefaultCropOrigin[]={CAM_DEFAULT_CROP_ORIGIN_W,CAM_DEFAULT_CROP_ORIGIN_H};
#if defined(CAM_DNG_LENS_INFO)
const int cam_lensinfo[] = CAM_DNG_LENS_INFO;
#endif
#if defined(CAM_DNG_EXPOSURE_BIAS)
const int cam_BaselineExposure[]={CAM_DNG_EXPOSURE_BIAS};
#else
const int cam_BaselineExposure[]={-1,2};
#endif
const int cam_BaselineNoise[]={1,1};
const int cam_BaselineSharpness[]={4,3};
const int cam_LinearResponseLimit[]={1,1};
const int cam_AnalogBalance[]={1,1,1,1,1,1};
const int cam_ColorMatrix1[9*2]={CAM_COLORMATRIX1};
const char cam_name[32];
const short cam_PreviewBitsPerSample[]={8,8,8};
const char cam_chdk_ver[]=HDK_VERSION" ver. "BUILD_NUMBER;
const int cam_Resolution[]={180,1};
int cam_AsShotNeutral[]={1000,1000,1000,1000,1000,1000};

// warning: according to TIFF format specification, elements must be sorted by tag value in ascending order!

struct dir_entry IFD0[]={
 {0xFE,   T_LONG,      1,  1},       // NewSubFileType: Preview Image
 {0x100,  T_LONG,      1,  DNG_TH_WIDTH},   // ImageWidth
 {0x101,  T_LONG,      1,  DNG_TH_HEIGHT},   // ImageLength
 {0x102,  T_SHORT,     3,  (int)cam_PreviewBitsPerSample},   // BitsPerSample: 8,8,8
 {0x103,  T_SHORT,     1,  1},   // Compression: Uncompressed
 {0x106,  T_SHORT,     1,  2}, //PhotometricInterpretation: RGB
 {0x10E,  T_ASCII,     1,  0}, // ImageDescription
 {0x10F,  T_ASCII,     sizeof(CAM_MAKE),  (int)CAM_MAKE}, // Make
 {0x110,  T_ASCII,     32, (int)cam_name}, //Model: Filled at header generation.
 {0x111,  T_LONG,      1,  0}, //StripOffsets: Offset
 {0x112,  T_SHORT,     1,  1}, //Orientation: 1 - 0th row is top, 0th column is left
 {0x115,  T_SHORT,     1,  3}, // SamplesPerPixel: 3
 {0x116,  T_SHORT,     1,  DNG_TH_HEIGHT}, //RowsPerStrip
 {0x117,  T_LONG,      1,  DNG_TH_WIDTH*DNG_TH_HEIGHT*3}, // StripByteCounts = preview size
 {0x11C,  T_SHORT,     1,  1}, // PlanarConfiguration: 1
 {0x131,  T_ASCII,     sizeof(cam_chdk_ver),  (int)cam_chdk_ver}, //Software
 {0x132,  T_ASCII,     20, 0}, // DateTime
 {0x14A,  T_LONG,      1,  0}, //SubIFDs offset
 {0x8298, T_ASCII,     1,  0}, // Copyright
 {0x8769, T_LONG,      1,  0}, //EXIF_IFD offset
#if defined(OPT_GPS)
 {0x8825, T_LONG,      1,  0}, //GPS_IFD offset
#endif
 {0x9216, T_BYTE,      4,  0x00000001},  // TIFF/EPStandardID: 1.0.0.0
 {0xC612, T_BYTE,      4,  0x00000101}, //DNGVersion: 1.1.0.0
 {0xC614, T_ASCII,     32, (int)cam_name}, //UniqueCameraModel. Filled at header generation.
 {0xC621, T_SRATIONAL, 9,  (int)cam_ColorMatrix1},
 {0xC627, T_RATIONAL,  3,  (int)cam_AnalogBalance},
 {0xC628, T_RATIONAL,  3,  (int)cam_AsShotNeutral},
 {0xC62A, T_SRATIONAL, 1,  (int)cam_BaselineExposure},
 {0xC62B, T_RATIONAL,  1,  (int)cam_BaselineNoise},
 {0xC62C, T_RATIONAL,  1,  (int)cam_BaselineSharpness},
 {0xC62E, T_RATIONAL,  1,  (int)cam_LinearResponseLimit},
#if defined(CAM_DNG_LENS_INFO)
 {0xC630, T_RATIONAL,  4,  (int)cam_lensinfo},
#endif
 {0xC65A, T_SHORT,     1,  cam_CalibrationIlluminant1}, 
 {0}
};

                                                                                      
struct dir_entry IFD1[]={
 {0xFE,   T_LONG,      1,  0},       // NewSubFileType: Main Image
 {0x100,  T_LONG,      1,  CAM_RAW_ROWPIX},   // ImageWidth
 {0x101,  T_LONG,      1,  CAM_RAW_ROWS},   // ImageLength
 {0x102,  T_SHORT,     1,  CAM_SENSOR_BITS_PER_PIXEL},   // BitsPerSample
 {0x103,  T_SHORT,     1,  1},   // Compression: Uncompressed
 {0x106,  T_SHORT,     1,  0x8023}, //PhotometricInterpretation: CFA
 {0x111,  T_LONG,      1,  0}, //StripOffsets: Offset
 {0x115,  T_SHORT,     1,  1}, // SamplesPerPixel: 1
 {0x116,  T_SHORT,     1,  CAM_RAW_ROWS}, //RowsPerStrip
 {0x117,  T_LONG,      1,  CAM_RAW_ROWS*RAW_ROWLEN}, // StripByteCounts = CHDK RAW size
 {0x11A,  T_RATIONAL,  1,  (int)cam_Resolution}, // XResolution
 {0x11B,  T_RATIONAL,  1,  (int)cam_Resolution}, // YResolution
 {0x11C,  T_SHORT,     1,  1}, // PlanarConfiguration: 1
 {0x128,  T_SHORT,     1,  2}, // ResolutionUnit: inch
 {0x828D, T_SHORT,     2,  0x00020002}, // CFARepeatPatternDim: Rows = 2, Cols = 2
 {0x828E, T_BYTE,      4,  cam_CFAPattern},
 {0xC61A, T_LONG,      1,  CAM_BLACK_LEVEL}, // BlackLevel
 {0xC61D, T_LONG,      1,  CAM_WHITE_LEVEL}, // WhiteLevel
 {0xC61F, T_LONG,      2,  (int)cam_DefaultCropOrigin},
 {0xC620, T_LONG,      2,  (int)cam_DefaultCropSize},
 {0xC68D, T_LONG,      4,  (int)cam_ActiveArea},
 {0}
};


static int cam_shutter[2]       = { 0, 1000000 };       // Shutter speed
static int cam_aperture[2]      = { 0, 10 };            // Aperture
static char cam_datetime[20]    = "";                   // DateTimeOriginal
static int cam_apex_shutter[2]  = { 0, 96 };            // Shutter speed in APEX units
static int cam_apex_aperture[2] = { 0, 96 };            // Aperture in APEX units
static int cam_exp_bias[2]      = { 0, 96 };
static int cam_max_av[2]        = { 0, 96 };
static int cam_focal_length[2]  = { 0, 1000 };

struct dir_entry EXIF_IFD[]={
 {0x829A, T_RATIONAL,  1,  (int)cam_shutter},           // Shutter speed
 {0x829D, T_RATIONAL,  1,  (int)cam_aperture},          // Aperture
 {0x8822, T_SHORT,     1,  0},                          // ExposureProgram
 {0x8827, T_SHORT,     1,  0},                          // ISOSpeedRatings
 {0x9000, T_UNDEFINED, 4,  0x31323230},                 // ExifVersion: 2.21
 {0x9003, T_ASCII,     20, (int)cam_datetime},          // DateTimeOriginal
 {0x9201, T_SRATIONAL, 1,  (int)cam_apex_shutter},      // ShutterSpeedValue (APEX units)
 {0x9202, T_RATIONAL,  1,  (int)cam_apex_aperture},     // ApertureValue (APEX units)
 {0x9204, T_SRATIONAL, 1,  (int)cam_exp_bias},          // ExposureBias
 {0x9205, T_RATIONAL,  1,  (int)cam_max_av},            // MaxApertureValue
 {0x9207, T_SHORT,     1,  0},                          // Metering mode
 {0x9209, T_SHORT,     1,  0},                          // Flash mode
 {0x920A, T_RATIONAL,  1,  (int)cam_focal_length},      // FocalLength
 {0xA405, T_SHORT,     1,  0},                          // FocalLengthIn35mmFilm
 {0}
};


#if defined(OPT_GPS)
struct dir_entry GPS_IFD[]={
// {0x0000, T_BYTE,      4,  0x00000302}, //GPSVersionID: 2 3 0 0
 {0x0001, T_ASCII,     2,  0}, //North or South Latitude "N\0" or "S\0"
 {0x0002, T_RATIONAL,  3,  0}, //Latitude
 {0x0003, T_ASCII,     2,  0}, //East or West Latitude "E\0" or "W\0"
 {0x0004, T_RATIONAL,  3,  0}, //Longitude
 {0x0005, T_ASCII,     2,  0}, //AltitudeRef
 {0x0006, T_RATIONAL,  3,  0}, //Altitude
 {0x0007, T_RATIONAL,  3,  0}, //TimeStamp
 {0x0009, T_ASCII,     2,  0}, //Status
// {0x000A, T_ASCII,     1,  0}, //MeasureMode
 {0x0012, T_ASCII,     8,  0}, //MapDatum 7 + 1 pad byte
 {0x001D, T_ASCII,    12,  0}, //DateStamp 11 + 1 pad byte
 {0}
};
#endif


int get_type_size(int type){
 switch(type){
  case T_BYTE:      return 1;
  case T_ASCII:     return 1; 
  case T_SHORT:     return 2;
  case T_LONG:      return 4;
  case T_RATIONAL:  return 8;
  case T_SBYTE:     return 1;
  case T_UNDEFINED: return 1;
  case T_SSHORT:    return 2;
  case T_SLONG:     return 4;
  case T_SRATIONAL: return 8;
  case T_FLOAT:     return 4;
  case T_DOUBLE:    return 8;
  default: return 0;
 }
}

#if defined(OPT_GPS)
struct {struct dir_entry* entry; int count;} IFD_LIST[]={{IFD0,0}, {IFD1,0}, {EXIF_IFD,0}, {GPS_IFD, 0}};
#else
struct {struct dir_entry* entry; int count;} IFD_LIST[]={{IFD0,0}, {IFD1,0}, {EXIF_IFD,0}};
#endif

#define IFDs (sizeof(IFD_LIST)/sizeof(IFD_LIST[0]))

#define TIFF_HDR_SIZE (8)

char* dng_header_buf;
int dng_header_buf_size;
int dng_header_buf_offset;
char *thumbnail_buf;

void add_to_buf(void* var, int size)
{
 memcpy(dng_header_buf+dng_header_buf_offset,var,size);
 dng_header_buf_offset+=size;
}

struct t_data_for_exif{
 short iso;
 int exp_program;
 int effective_focal_length;
 short orientation;
 short flash_mode;
 short flash_fired;
 short metering_mode;
};

static struct t_data_for_exif exif_data;

void create_dng_header(){
 int var;
 int i,j;
 int extra_offset;
 int raw_offset;

 // filling EXIF fields
  
#if defined(OPT_GPS)
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
tGPS gps;

get_property_case(PROPCASE_GPS, &gps, sizeof(tGPS));
#endif

 for (j=0;j<IFDs;j++) {
  for(i=0; IFD_LIST[j].entry[i].tag; i++) {
    switch (IFD_LIST[j].entry[i].tag) {
	 // For camera name string make sure the 'count' in the IFD header is correct for the string
     case 0x110 :                                                                                       // CameraName
     case 0xC614: IFD_LIST[j].entry[i].count = strlen((char*)IFD_LIST[j].entry[i].offset) + 1; break;   // UniqueCameraModel
     case 0x132 :
     case 0x8827: IFD_LIST[j].entry[i].offset=exif_data.iso; break;//ISOSpeedRatings
     case 0x8822: IFD_LIST[j].entry[i].offset=get_exp_program_for_exif(exif_data.exp_program); break;//ExposureProgram
     case 0xA405: IFD_LIST[j].entry[i].offset=exif_data.effective_focal_length/1000; break; ////FocalLengthIn35mmFilm
     case 0x0112: IFD_LIST[j].entry[i].offset=get_orientation_for_exif(exif_data.orientation); break; //Orientation
     case 0x9209: IFD_LIST[j].entry[i].offset=get_flash_mode_for_exif(exif_data.flash_mode, exif_data.flash_fired); break; //Flash mode
     case 0x9207: IFD_LIST[j].entry[i].offset=get_metering_mode_for_exif(exif_data.metering_mode); break; // Metering mode
#if defined(OPT_GPS)
     case 0x0001: IFD_LIST[j].entry[i].offset=gps.latitudeRef; break;
     case 0x0002: IFD_LIST[j].entry[i].offset=(int)&(gps.latitude); break;
     case 0x0003: IFD_LIST[j].entry[i].offset=gps.longitudeRef; break;
     case 0x0004: IFD_LIST[j].entry[i].offset=(int)&(gps.longitude); break;
     case 0x0005: IFD_LIST[j].entry[i].offset=gps.heightRef; break;
     case 0x0006: IFD_LIST[j].entry[i].offset=(int)&(gps.height); break;
     case 0x0007: IFD_LIST[j].entry[i].offset=(int)&(gps.timeStamp); break;
     case 0x0009: IFD_LIST[j].entry[i].offset=(int)gps.status; break;
     case 0x0012: IFD_LIST[j].entry[i].offset=(int)&(gps.mapDatum); break;
     case 0x001D: IFD_LIST[j].entry[i].offset=(int)&(gps.dateStamp); break;
#endif
    }
  }
 }
  
 // calculating offset of RAW data and count of directories for each IFD

 raw_offset=TIFF_HDR_SIZE;

 for (j=0;j<IFDs;j++) {
  IFD_LIST[j].count=0;
  raw_offset+=6; // IFD header+footer
  for(i=0; IFD_LIST[j].entry[i].tag; i++) {
   int size_ext;
   IFD_LIST[j].count++;
   raw_offset+=12; // IFD directory size
   size_ext=get_type_size(IFD_LIST[j].entry[i].type)*IFD_LIST[j].entry[i].count;
   if (size_ext>4) raw_offset+=size_ext+(size_ext&1);
  }
 }

 // creating buffer for writing data
 raw_offset=(raw_offset/512+1)*512; // exlusively for CHDK fast file writing
 dng_header_buf_size=raw_offset;
 dng_header_buf=umalloc(raw_offset);
 dng_header_buf_offset=0;
 if (!dng_header_buf) return;

 // create buffer for thumbnail
 thumbnail_buf = malloc(DNG_TH_WIDTH*DNG_TH_HEIGHT*3);
 if (!thumbnail_buf)
 {
     ufree(dng_header_buf);
     dng_header_buf = 0;
     return;
 }

 //  writing  offsets for EXIF IFD and RAW data and calculating offset for extra data

 extra_offset=TIFF_HDR_SIZE;

 for (j=0;j<IFDs;j++) {
  extra_offset+=6+IFD_LIST[j].count*12; // IFD header+footer
  for(i=0; IFD_LIST[j].entry[i].tag; i++) {
   if (IFD_LIST[j].entry[i].tag==0x8769) IFD_LIST[j].entry[i].offset=TIFF_HDR_SIZE+(IFD_LIST[0].count+IFD_LIST[1].count)*12+6+6;  // EXIF IFD offset
#if defined(OPT_GPS)
   if (IFD_LIST[j].entry[i].tag==0x8825) IFD_LIST[j].entry[i].offset=TIFF_HDR_SIZE+(IFD_LIST[0].count+IFD_LIST[1].count+IFD_LIST[2].count)*12+6+6+6;  // GPS IFD offset
#endif
   if (IFD_LIST[j].entry[i].tag==0x14A)  IFD_LIST[j].entry[i].offset=TIFF_HDR_SIZE+IFD_LIST[0].count*12+6; // SubIFDs offset
   if (IFD_LIST[j].entry[i].tag==0x111)  {
    if (j==1) IFD_LIST[j].entry[i].offset=raw_offset+DNG_TH_WIDTH*DNG_TH_HEIGHT*3;  //StripOffsets for main image
    if (j==0) IFD_LIST[j].entry[i].offset=raw_offset;  //StripOffsets for thumbnail
   }
  }
 }

 // TIFF file header

 var=0x4949; // little endian
 add_to_buf(&var, sizeof(short));
 var=42; //An arbitrary but carefully chosen number that further identifies the file as a TIFF file.
 add_to_buf(&var, sizeof(short));
 var=0x8; // offset of first IFD
 add_to_buf(&var, sizeof(int));


 // writing IFDs

 for (j=0;j<IFDs;j++) {
  int size_ext;
  var=IFD_LIST[j].count;
  add_to_buf(&var, sizeof(short));
  for(i=0; IFD_LIST[j].entry[i].tag; i++) {
   add_to_buf(&IFD_LIST[j].entry[i].tag, sizeof(short));
   add_to_buf(&IFD_LIST[j].entry[i].type, sizeof(short));
   add_to_buf(&IFD_LIST[j].entry[i].count, sizeof(int));
   size_ext=get_type_size(IFD_LIST[j].entry[i].type)*IFD_LIST[j].entry[i].count;
   if (size_ext<=4) add_to_buf(&IFD_LIST[j].entry[i].offset, sizeof(int));
   else {
    add_to_buf(&extra_offset, sizeof(int));
    extra_offset+=size_ext+(size_ext&1);    
   }
  }
 var=0; 
 add_to_buf(&var, sizeof(int));
 }


 // writing extra data

 for (j=0;j<IFDs;j++) {
  int size_ext;
  char zero=0;
  for(i=0; IFD_LIST[j].entry[i].tag; i++) {
   size_ext=get_type_size(IFD_LIST[j].entry[i].type)*IFD_LIST[j].entry[i].count;
   if (size_ext>4){
    add_to_buf((void*)IFD_LIST[j].entry[i].offset, size_ext);
    if (size_ext&1) add_to_buf(&zero, 1);
   }
  }
 }

 // writing zeros to tail of dng header (just for fun)
 for (i=dng_header_buf_offset; i<dng_header_buf_size; i++) dng_header_buf[i]=0;
}

void free_dng_header(void)
{
    if (dng_header_buf)
    {
        ufree(dng_header_buf);
        dng_header_buf=NULL;
    }
    if (thumbnail_buf)
    {
        free(thumbnail_buf);
        thumbnail_buf = 0;
    }
}

unsigned short get_exp_program_for_exif(int exp_program){
 switch(exp_program){
  case MODE_M: return 1;
  case MODE_P: return 2;
  case MODE_AV: return 3;
  case MODE_TV: return 4;
  default: return 0;
 }
}

unsigned short get_orientation_for_exif(short orientation){
 switch(orientation){
  case  90: return 6;  // Right  - Top
  case 180: return 3;  // Bottom - Right
  case 270: return 8;  // Left   - Bottom
  case   0:            // Top    - Left
  default : return 1;
 }
}

unsigned short get_flash_mode_for_exif(short mode, short fired){
 fired&=1;
 switch(mode){
  case 0: return (3<<3)|fired; // auto
  case 1: return (1<<3)|fired; // on
  case 2: return (2<<3)|fired; // off
  default: return fired;
 };
}

unsigned short get_metering_mode_for_exif(short metering_mode){
 switch (metering_mode){
  case 0: return 5; // Evaluative
  case 1: return 3; // Spot
  case 2: return 2; // CenterWeightedAverage
  default: return 255; // other
 }
}

void capture_data_for_exif(void)
{
 short short_prop_val;
 unsigned long datetime;
 struct tm *ttm;
 extern volatile long shutter_open_time; // defined in platform/generic/capt_seq.c
 int wb[3];

 exif_data.iso=shooting_get_iso_market();

 // Shutter speed tags
 get_property_case(PROPCASE_TV, &short_prop_val, sizeof(short_prop_val));
 cam_shutter[0]      = pow_calc( 1000000, 2, 1, -short_prop_val, 96);
 cam_apex_shutter[0] = short_prop_val;

 // Date & time tag (note - uses shutter speed from 'short_prop_val' code above)
 if (shutter_open_time) { datetime = shutter_open_time + pow_calc(1, 2, 1, -short_prop_val, 96); shutter_open_time=0;} // shutter closing time
 else  datetime = time(NULL);
 ttm = localtime(&datetime);
 sprintf(cam_datetime, "%04d:%02d:%02d %02d:%02d:%02d", ttm->tm_year+1900, ttm->tm_mon+1, ttm->tm_mday, ttm->tm_hour, ttm->tm_min, ttm->tm_sec);

 get_property_case(PROPCASE_AV, &short_prop_val, sizeof(short_prop_val));
 cam_aperture[0]      = pow_calc( 10, 2, 1, short_prop_val, 192);
 cam_apex_aperture[0] = short_prop_val;

 get_property_case(PROPCASE_MIN_AV, &short_prop_val, sizeof(short_prop_val));
 cam_max_av[0] = short_prop_val;

 get_property_case(PROPCASE_EV_CORRECTION_2, &short_prop_val, sizeof(short_prop_val));
 cam_exp_bias[0] = short_prop_val;

 exif_data.exp_program=mode_get() & MODE_SHOOTING_MASK;

 cam_focal_length[0] = get_focal_length(shooting_get_zoom());
 exif_data.effective_focal_length = get_effective_focal_length(shooting_get_zoom());

 get_property_case(PROPCASE_ORIENTATION_SENSOR, &exif_data.orientation, sizeof(exif_data.orientation));
 get_parameter_data(PARAM_CAMERA_NAME, &cam_name, sizeof(cam_name));
 get_property_case(PROPCASE_FLASH_MODE, &exif_data.flash_mode, sizeof(exif_data.flash_mode));
 get_property_case(PROPCASE_FLASH_FIRE, &exif_data.flash_fired, sizeof(exif_data.flash_fired));
 get_property_case(PROPCASE_METERING_MODE, &exif_data.metering_mode, sizeof(exif_data.metering_mode));

 get_property_case(PROPCASE_WB_ADJ, &wb, sizeof(wb));  
 cam_AsShotNeutral[1]=wb[1];
 cam_AsShotNeutral[3]=wb[0];
 cam_AsShotNeutral[5]=wb[2];
}

//-------------------------------------------------------------------

void convert_dng_to_chdk_raw(char* fn){
 #define BUF_SIZE (32768)
 FILE *dng, *raw;
 int *buf;
 int i;
 struct STD_stat st;
 struct utimbuf t;

 if (safe_stat(fn, &st) != 0 || st.st_size<=hook_raw_size())  return;
 buf=malloc(BUF_SIZE);
 if (buf){
  started();
  dng=fopen(fn,"rb");
  if (dng){
   fread(buf, 1, 8, dng);
   if (buf[0]==0x2A4949 && buf[1]==8) {  // chdk dng header
    i=strlen(fn)-3;
    if (strncmp(fn+i,"CR",2)==0) strcpy(fn+i,"WAV"); else strcpy(fn+i,"CRW");
    raw=fopen(fn,"w+b");
    if (raw){
     fseek(dng, st.st_size-hook_raw_size(), SEEK_SET); // SEEK_END is not working?
     for (i=0; i<hook_raw_size()/BUF_SIZE; i++) {
      fread(buf, 1, BUF_SIZE, dng);
      reverse_bytes_order((char*)buf, BUF_SIZE);
      fwrite(buf, 1, BUF_SIZE, raw);
     }
     fread(buf, 1, hook_raw_size()%BUF_SIZE, dng);
     reverse_bytes_order((char*)buf, hook_raw_size()%BUF_SIZE);
     fwrite(buf, 1, hook_raw_size()%BUF_SIZE, raw);
     fclose(raw);
     t.actime = t.modtime = time(NULL);
     utime(fn, &t);
    } // if (raw)
   } // if chdk dng header
  fclose(dng);
  } //if (dng)
 free(buf);
 finished();
 }  //if (buf)
}

//-------------------------------------------------------------------
// Functions for creating DNG thumbnail image

static unsigned char gamma[256];

void fill_gamma_buf(void) {
    int i;
    if (gamma[255]) return;
#if defined(CAMERA_sx30) || defined(CAMERA_sx40hs) || defined(CAMERA_g12) || defined(CAMERA_ixus310_elph500hs)
    for (i=0; i<12; i++) gamma[i]=pow_calc_2(255, i, 255, 0.5, 1);
    for (i=12; i<64; i++) gamma[i]=pow_calc_2(255, i, 255, 0.4, 1);
    for (i=64; i<=255; i++) gamma[i]=pow_calc_2(255, i, 255, 0.25, 1);
#else
    for (i=0; i<=255; i++) gamma[i]=pow_calc_2(255, i, 255, 0.5, 1);
#endif
}

void create_thumbnail() {
    register int i, j, x, y;
    register char *buf = thumbnail_buf;

    for (i=0; i<DNG_TH_HEIGHT; i++)
        for (j=0; j<DNG_TH_WIDTH; j++)
        {
            x = (CAM_ACTIVE_AREA_X1+((CAM_ACTIVE_AREA_X2-CAM_ACTIVE_AREA_X1)*j)/DNG_TH_WIDTH) & 0xFFFFFFFE;
            y = (CAM_ACTIVE_AREA_Y1+((CAM_ACTIVE_AREA_Y2-CAM_ACTIVE_AREA_Y1)*i)/DNG_TH_HEIGHT) & 0xFFFFFFFE;

#if cam_CFAPattern==0x02010100    // Red  Green  Green  Blue
            *buf++ = gamma[get_raw_pixel(x,y)>>(CAM_SENSOR_BITS_PER_PIXEL-8)];           // red pixel
            *buf++ = gamma[6*(get_raw_pixel(x+1,y)>>(CAM_SENSOR_BITS_PER_PIXEL-8))/10];  // green pixel
            *buf++ = gamma[get_raw_pixel(x+1,y+1)>>(CAM_SENSOR_BITS_PER_PIXEL-8)];       // blue pixel
#elif cam_CFAPattern==0x01000201 // Green  Blue  Red  Green
            *buf++ = gamma[get_raw_pixel(x,y+1)>>(CAM_SENSOR_BITS_PER_PIXEL-8)];         // red pixel
            *buf++ = gamma[6*(get_raw_pixel(x,y)>>(CAM_SENSOR_BITS_PER_PIXEL-8))/10];    // green pixel
            *buf++ = gamma[get_raw_pixel(x+1,y)>>(CAM_SENSOR_BITS_PER_PIXEL-8)];         // blue pixel
#else 
    #error please define new pattern here
#endif
        }
}

//-------------------------------------------------------------------
// Functions for handling DNG bad pixel file creation and bad pixel
// removal from images.

#define INIT_BADPIXEL_COUNT -1
#define INIT_BADPIXEL_FILE -2

#define PATH_BADPIXEL_BIN "A/CHDK/badpixel.bin"
#define PATH_BAD_TMP_BIN "A/CHDK/bad_tmp.bin"

int init_badpixel_bin_flag; // contants above to count/create file, > 0 num bad pixel

int raw_init_badpixel_bin() {
    int count;
    unsigned short c[2];
    FILE*f;
    if(init_badpixel_bin_flag == INIT_BADPIXEL_FILE) {
        f=fopen(PATH_BAD_TMP_BIN,"w+b");
    } else if (init_badpixel_bin_flag == INIT_BADPIXEL_COUNT) {
        f=NULL;
    } else {
        return 0;
    }
    count = 0;
#ifdef DNG_VERT_RLE_BADPIXELS
    for (c[0]=CAM_ACTIVE_AREA_X1; c[0]<CAM_ACTIVE_AREA_X2; c[0]++)
    {
        for (c[1]=CAM_ACTIVE_AREA_Y1; c[1]<CAM_ACTIVE_AREA_Y2; c[1]++)
        {
            if (get_raw_pixel(c[0],c[1])==0)
            {
                unsigned short l;
                for (l=0; l<7; l++) if (get_raw_pixel(c[0],c[1]+l+1)!=0) break;
                c[1] = c[1] | (l << 13);
                if (f) fwrite(c, 1, 4, f);
                c[1] = (c[1] & 0x1FFF) + l;
                count = count + l + 1;
            }
        }
    }
#else
    for (c[1]=CAM_ACTIVE_AREA_Y1; c[1]<CAM_ACTIVE_AREA_Y2; c[1]++) 
    {
        for (c[0]=CAM_ACTIVE_AREA_X1; c[0]<CAM_ACTIVE_AREA_X2; c[0]++) 
        {
            if (get_raw_pixel(c[0],c[1])==0) 
            {
                if (f) fwrite(c, 1, 4, f);
                count++;
            }
        }
    }
#endif
    if (f) fclose(f);
    init_badpixel_bin_flag = count;
    state_shooting_progress = SHOOTING_PROGRESS_PROCESSING;
    return 1;
}

short* binary_list=NULL;
int binary_count=-1;

void load_bad_pixels_list_b(char* filename) {
    struct STD_stat st;
    long filesize;
    void* ptr;
    FILE *fd;

	if ( filename==0 )
	 { unload_bad_pixels_list_b(); return; }

    binary_count=-1;
    if (safe_stat(filename,&st)!=0) return;
    filesize=st.st_size;
    if (filesize%(2*sizeof(short)) != 0) return;
	if (filesize == 0) { binary_count = 0; return; }	// Allow empty badpixel.bin file
    ptr=malloc(filesize);
    if (!ptr) return;
    fd=fopen(filename, "rb");
    if (fd) {
        fread(ptr,1, filesize,fd);
        fclose(fd);
        binary_list=ptr;
        binary_count=filesize/(2*sizeof(short));
    }
    else free(ptr);
}

void unload_bad_pixels_list_b(void) {
    if (binary_list) free(binary_list);
    binary_list=NULL;
    binary_count=-1;
}

void patch_bad_pixels_b(void) {
    int i;
    short* ptr=binary_list;
#ifdef DNG_VERT_RLE_BADPIXELS
    short y, cnt;
    for (i=0; i<binary_count; i++, ptr+=2)
    {
        y = ptr[1] & 0x1FFF;
        cnt = (ptr[1] >> 13) & 7;
        for (; cnt>=0; cnt--, y++)
            if (get_raw_pixel(ptr[0], y)==0)
                patch_bad_pixel(ptr[0], y);
    }
#else
    for (i=0; i<binary_count; i++, ptr+=2)
        if (get_raw_pixel(ptr[0], ptr[1])==0)
            patch_bad_pixel(ptr[0], ptr[1]);
#endif
}

int badpixel_list_loaded_b(void) {
	return (binary_count >= 0) ? 1 : 0;
}

// -----------------------------------------------

enum BadpixelFSM {
    BADPIX_START,
    BADPIX_S1,
    BADPIX_S2
};

int badpixel_task_stack(long p) {
    static unsigned int badpix_cnt1;

    switch(p) {
        case BADPIX_START:
            action_pop();

            console_clear();
            console_add_line("Wait please... ");
            console_add_line("This takes a few seconds,");
            console_add_line("don't panic!");

            init_badpixel_bin_flag = INIT_BADPIXEL_COUNT;

            shooting_set_tv96_direct(96, SET_LATER);
            action_push(BADPIX_S1);
            action_push(AS_SHOOT);
            action_push_delay(3000);
            break;
        case BADPIX_S1:
            action_pop();

            badpix_cnt1 = init_badpixel_bin_flag;
            init_badpixel_bin_flag = INIT_BADPIXEL_FILE;
            shooting_set_tv96_direct(96, SET_LATER);

            action_push(BADPIX_S2);
            action_push(AS_SHOOT);
            break;
        case BADPIX_S2:
            action_pop();

            console_clear();
            if (badpix_cnt1 == init_badpixel_bin_flag) {
                // TODO script asked confirmation first
                // should sanity check bad pixel count at least,
                // wrong buffer address could make badpixel bigger than available mem
                char msg[32];
                console_add_line("badpixel.bin created.");
                sprintf(msg, "Bad pixel count: %d", badpix_cnt1);
                console_add_line(msg);
                remove(PATH_BADPIXEL_BIN);
                rename(PATH_BAD_TMP_BIN,PATH_BADPIXEL_BIN);
            } else {
                console_add_line("badpixel.bin failed.");
                console_add_line("Please try again.");
            }
            init_badpixel_bin_flag = 0;
            remove(PATH_BAD_TMP_BIN);

            action_push_delay(3000);
            break;
        default:
            action_stack_standard(p);
            break;
    }

    return 1;
}


void create_badpixel_bin() {
    if (!(mode_get() & MODE_REC)) {
        gui_mbox_init(LANG_ERROR, LANG_MSG_RECMODE_REQUIRED, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
        return;
    }

    gui_set_mode(GUI_MODE_ALT);
    action_stack_create(&badpixel_task_stack, BADPIX_START);
}

//-------------------------------------------------------------------
// Write DNG header and thumbnail to file

void write_dng_header(int fd)
{
    if (dng_header_buf)
    {
        fill_gamma_buf();
        patch_bad_pixels_b();
        create_thumbnail();
        write(fd, dng_header_buf, dng_header_buf_size);
        write(fd, thumbnail_buf, DNG_TH_WIDTH*DNG_TH_HEIGHT*3);
    }
}

//-------------------------------------------------------------------
void write_dng(int fd, char* rawadr, char* altrawadr, unsigned long uncachedbit) 
{
	create_dng_header();
    write_dng_header(fd);

    reverse_bytes_order2(rawadr, altrawadr, hook_raw_size());

    // Write alternate (inactive) buffer that we reversed the bytes into above (if only one buffer then it will be the active buffer instead)
    write(fd, (char*)(((unsigned long)altrawadr)|uncachedbit), hook_raw_size());

    if (rawadr == altrawadr)    // If only one RAW buffer then we have to swap the bytes back
    	reverse_bytes_order2(rawadr, altrawadr, hook_raw_size());

    free_dng_header();
}

/*********** BEGIN OF AUXILARY PART **********************/

#include "module_load.h"

void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)9,

			create_badpixel_bin,
			raw_init_badpixel_bin,
			capture_data_for_exif,
			load_bad_pixels_list_b,
			badpixel_list_loaded_b,

			convert_dng_to_chdk_raw,
			write_dng,
		};

int _module_loader( void** chdk_export_list )
{
  if ( (unsigned int)chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;

  return 0;
}


//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{

	unload_bad_pixels_list_b();
    free_dng_header();
    return 0;
}


#else

/*********** NO DNG SUPPORTED BY CAMERA - EMPTY MODULE **********/

#include "module_load.h"

int _module_loader( void** chdk_export_list )
{
	// error bind - DNG is not supported and module is empty
	return 1;
}


//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
  return 0;
}


#endif //DNG_SUPPORT


/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									PLATFORMID,					// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"DNG (dll)",	// Module name
									1, 0,						// Module version
									(int32_t)"Processing of DNG"
								 };


/*************** END OF AUXILARY PART *******************/
