// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.01B
//   Canon PowerShot A4000 IS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12867 (0x3243) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff1d28
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff1d38

// Note, ROM copied to RAM :- from 0xffc06164, to 0x003f1000, len 15733 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(DeleteFile_Fut                         ,0xff830e30) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff831940
//NHSTUB(kbd_pwr_off                          ,0xff856988) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff888adc -> ff8856fc -> ff988ba0 -> ffa83000 -> ffba2d18
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00031290) // Found @0xff82ed9c
DEF(physw_run                               ,0x00001c18) // Found @0xff82e94c
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff82e94c
DEF(levent_table                            ,0xffb5e9c8) // Found @0xffb5e9c8
DEF(FlashParamsTable                        ,0xffba2f70) // Found @0xffba2f70
DEF(movie_status                            ,0x00006424) // Found @0xff95e290
DEF(full_screen_refresh                     ,0x0000872c) // Found @0xff9d764c
DEF(canon_menu_active                       ,0x00002ec8) // Found @0xff8815e8
DEF(canon_shoot_menu_active                 ,0x00007881) // Found @0xff99fa90
DEF(playrec_mode                            ,0x00002c1c) // Found @0xff8755f4
DEF(zoom_status                             ,0x0000b770) // Found @0xffa86798
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xfffeabc8) // Found @0xfffeabc8
DEF(zoom_busy                               ,0x000062bc) // Found @0xff9588bc
DEF(focus_busy                              ,0x00006150) // Found @0xff954048
DEF(recreview_hold                          ,0x00003474) // Found @0xff88eeac
DEF(palette_control                         ,0x0000872c) // Found @0xff9d75c8
DEF(active_palette_buffer                   ,0x00008734) // Found @0xff9d75cc
DEF(palette_buffer                          ,0x000b2228) // Found @0xff9d7970
DEF(viewport_buffers                        ,0xffb10490) // Found @0xff849bd8
DEF(active_viewport_buffer                  ,0x000020b4) // Found @0xff849940

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff852d80
//void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffae038c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2960+0x54)); } // Found @0xff867a04 & 0xff867a3c
//char *camera_jpeg_count_str()    { return (char*)0x000b1abc; }             // Found @0xff9cd8c4
//long hook_raw_size()             { return 0x01794300; }                    // Found @0xffae31c0
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff989bec

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb10954, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb1095c, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb108dc, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb108e4, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb108f4, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb108f4, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb108ec, levent 0x00
//    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb108fc, levent 0x04
//    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb10904, levent 0x05
//    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb1090c, levent 0x07
//    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb10914, levent 0x06
//    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb1091c, levent 0x09
//    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb10924, levent 0x08
//    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb1092c, levent 0x1a
//    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb10934, levent 0x14
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb1093c, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb10944, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff92ee38
//#define CAM_RAW_ROWS      3504 // Found @0xff92ee44
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff8342c4

// Misc stuff
DEF(ctypes, 0xffb0fce0)

// For capt_seq.c
DEF(_nrflag,0x8868) // Found @ ff9e41ac (0x8868) & ff9e41e8 (+0x00)
//static long *nrflag = (long*)(0x8868+0x00);  // Found @ ff9e41ac & ff9e41e8
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffae338c) //  1
// ALT: NHSTUB(CreateJumptable, 0xffae56fc) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff81a7cc) //111
//NHSTUB(AllocateMemory                       ,0xffa75370) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83427c) //112
NHSTUB(Close                                  ,0xff8314a4) //101
NHSTUB(CreateTask                             ,0x003f6824) //101
NHSTUB(DebugAssert                            ,0x003f6afc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff830ea4) //116
NHSTUB(DoAFLock                               ,0xff832d24) //102
NHSTUB(EnterToCompensationEVF                 ,0xff832f88) //104
NHSTUB(ExecuteEventProcedure                  ,0xff87cb10) //104
NHSTUB(ExitFromCompensationEVF                ,0xff832fcc) //104
NHSTUB(ExitTask                               ,0x003f6ab4) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff83d708) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83d864) //104
NHSTUB(Fclose_Fut                             ,0xff830f3c) //101
NHSTUB(Feof_Fut                               ,0xff831128) //  1
NHSTUB(Fflush_Fut                             ,0xff831164) //  1
NHSTUB(Fgets_Fut                              ,0xff831090) //  6
NHSTUB(Fopen_Fut                              ,0xff830efc) //101
NHSTUB(Fread_Fut                              ,0xff830fe8) //101
//NHSTUB(FreeMemory                           ,0xffa75368) //101
NHSTUB(FreeUncacheableMemory                  ,0xff8342bc) //112
NHSTUB(Fseek_Fut                              ,0xff8310dc) //101
NHSTUB(Fwrite_Fut                             ,0xff83103c) //101
NHSTUB(GetBatteryTemperature                  ,0xff85896c) //102
NHSTUB(GetCCDTemperature                      ,0xff8588f8) //102
NHSTUB(GetCurrentAvValue                      ,0xff955bf8) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff866458) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff8664b0) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff866488) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff954e0c) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff95525c) //  3
NHSTUB(GetImageFolder                         ,0xff9383a4) //  6
NHSTUB(GetKbdState                            ,0xff856978) //109
NHSTUB(GetMemInfo                             ,0xff81508c) //115
NHSTUB(GetOpticalTemperature                  ,0xff8589e0) //102
NHSTUB(GetParameterData                       ,0xff989bac) //101
NHSTUB(GetPropertyCase                        ,0xff880b88) //102
NHSTUB(GetSystemTime                          ,0xffa753c8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff84bcb8) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff84bcc4) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff958d30) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa66524) //102
NHSTUB(GiveSemaphore                          ,0x003f7704) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8cabb4) //102
NHSTUB(LEDDrive                               ,0xff95fb4c) //101
NHSTUB(LocalTime                              ,0x003fb1b8) //115
NHSTUB(LockMainPower                          ,0xff885438) //103
//NHSTUB(Lseek                                ,0xff8316c0) //101
NHSTUB(MakeSDCardBootable                     ,0xff8666e8) //105
NHSTUB(MoveFocusLensToDistance                ,0xffadc448) //102
NHSTUB(MoveIrisWithAv                         ,0xffa70800) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa70f34) //102
//NHSTUB(NewTaskShell                         ,0xff880508) //101
NHSTUB(Open                                   ,0xff8313dc) //101
NHSTUB(PB2Rec                                 ,0xff888168) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86e588) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86e560) //102
NHSTUB(PT_PlaySound                           ,0xff87734c) // 11
NHSTUB(PostLogicalEventForNotPowerType        ,0xff884b2c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff884b78) //103
NHSTUB(PutInNdFilter                          ,0xffa70d0c) //102
NHSTUB(PutOutNdFilter                         ,0xffa70d30) //102
NHSTUB(Read                                   ,0xff815b48) //101
NHSTUB(ReadFastDir                            ,0xffa56ac0) //115
NHSTUB(Rec2PB                                 ,0xff8881a8) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff896d88) //104
//NHSTUB(Remove                               ,0xff831618) //  6
NHSTUB(RenameFile_Fut                         ,0xff830d9c) //116
NHSTUB(Restart                                ,0xff835a90) //106
NHSTUB(ScreenLock                             ,0xff897da8) //  4
NHSTUB(ScreenUnlock                           ,0xff897e0c) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffadf564) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8854ac) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff88c324) //101
NHSTUB(SetFileAttributes                      ,0xff8318a8) //  6
NHSTUB(SetFileTimeStamp                       ,0xff831830) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8851b4) //101
NHSTUB(SetParameterData                       ,0xff989b1c) //101
NHSTUB(SetPropertyCase                        ,0xff880a00) //102
NHSTUB(SetScriptMode                          ,0xff885204) //101
NHSTUB(SleepTask                              ,0x003f79b0) //101
NHSTUB(TakeSemaphore                          ,0x003f7634) //101
NHSTUB(TurnOffBackLight                       ,0xff891ea8) //104
NHSTUB(TurnOnBackLight                        ,0xff891e90) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff97b764) //101
NHSTUB(UnlockAF                               ,0xff832d5c) //102
NHSTUB(UnlockMainPower                        ,0xff88538c) //103
NHSTUB(UnsetZoomForMovie                      ,0xff99034c) //104
NHSTUB(VbattGet                               ,0xff82c3bc) //101
NHSTUB(Write                                  ,0xff8314f8) //101
NHSTUB(WriteSDCard                            ,0xff9480cc) //108
NHSTUB(_log                                   ,0x003fcce0) //111
NHSTUB(_log10                                 ,0x003fd220) //112
NHSTUB(_pow                                   ,0x003fd398) //114
NHSTUB(_sqrt                                  ,0x003fefbc) //  6
NHSTUB(add_ptp_handler                        ,0xffa1a0e8) //  6
NHSTUB(apex2us                                ,0xff9dd9c4) //  4
NHSTUB(close                                  ,0xff8159a4) //  6
NHSTUB(closedir                               ,0xffa5691c) //  4
NHSTUB(err_init_task                          ,0xff81436c) //111
NHSTUB(exmem_alloc                            ,0xff87b4e4) //101
NHSTUB(exmem_free                             ,0xff87b55c) //101
NHSTUB(free                                   ,0xff812f68) //112
NHSTUB(kbd_p1_f                               ,0xff82edec) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82edf8) //109
NHSTUB(kbd_p2_f                               ,0xff82e5e4) //109
NHSTUB(kbd_read_keys                          ,0xff82ed9c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff856494) //109
NHSTUB(lseek                                  ,0xff8316c0) //101
NHSTUB(malloc                                 ,0xff812f10) //112
NHSTUB(memcmp                                 ,0xff81ae20) //101
NHSTUB(memcpy                                 ,0xff8371fc) //101
NHSTUB(memset                                 ,0xff9dbc58) //101
NHSTUB(mkdir                                  ,0xff831940) //  6
NHSTUB(mktime_ext                             ,0xff8982d8) //  1
NHSTUB(open                                   ,0xff8158f4) //  6
NHSTUB(OpenFastDir                            ,0xffa5696c) //115
NHSTUB(qsort                                  ,0xff9dbbf8) //  6
//NHSTUB(read                                 ,0xff815b48) //101
NHSTUB(realloc                                ,0xff9dbcd4) //115
NHSTUB(reboot_fw_update                       ,0xffa5be9c) //106
NHSTUB(set_control_event                      ,0xff884e74) //111
NHSTUB(stat                                   ,0xff831708) //109
NHSTUB(strcat                                 ,0xff898958) //  1
NHSTUB(strchr                                 ,0xff812ddc) //  1
NHSTUB(strcmp                                 ,0xff81af1c) //101
NHSTUB(strcpy                                 ,0xff81ae08) //101
NHSTUB(strftime                               ,0xff898324) //113
NHSTUB(strlen                                 ,0xff812e28) //101
NHSTUB(strncmp                                ,0xff812d90) //  1
NHSTUB(strncpy                                ,0xff812d54) //  1
NHSTUB(strrchr                                ,0xff812e00) //  1
NHSTUB(strtol                                 ,0xff8371e8) //101
NHSTUB(strtolx                                ,0xff836fec) //109
   DEF(task_CaptSeq                           ,0xff870db0) //110
   DEF(task_ExpDrv                            ,0xff8afb60) //110
   DEF(task_FileWrite                         ,0xffa55324) //110
   DEF(task_InitFileModules                   ,0xff88895c) //110
   DEF(task_MovieRecord                       ,0xff95edf4) //110
   DEF(task_PhySw                             ,0xff82e948) //110
NHSTUB(time                                   ,0x003fb794) //  6
NHSTUB(vsprintf                               ,0xff81acb8) //115
//NHSTUB(write                                ,0xff8314f8) //101
//NHSTUB(EngDrvIn                             ,0xff82fc24) //102
//NHSTUB(EngDrvOut                            ,0xff82fc0c) //102
//NHSTUB(EngDrvRead                           ,0xff82fc2c) //102
//NHSTUB(EngDrvBits                           ,0xff82fc40) //102
//NHSTUB(GetSDProtect                         ,0xff82ed58) //101
//NHSTUB(StartRecModeMenu                     ,0xff8815e4) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff852d50) //102
//NHSTUB(ResetZoomLens                        ,0xffa70e88) //102
//NHSTUB(ResetFocusLens                       ,0xffa6fa04) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff9e426c) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff9e41a4) //102
//NHSTUB(SavePaletteData                      ,0xff96254c) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff89663c) //101
