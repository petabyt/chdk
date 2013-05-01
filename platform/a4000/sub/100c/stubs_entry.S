// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00C
//   Canon PowerShot A4000 IS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12867 (0x3243) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff1d28
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff1d38

// Note, ROM copied to RAM :- from 0xffc04d4c, to 0x003f1000, len 15733 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(DeleteFile_Fut                          ,0xff830e30) //  1 90%
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff831940
//NSTUB(kbd_pwr_off                           ,0xff856988) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff888adc -> ff8856fc -> ff988b14 -> ffa8270c -> ffba19b0
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00031270) // Found @0xff82ed9c
DEF(physw_run                               ,0x00001c18) // Found @0xff82e94c
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff82e94c
DEF(levent_table                            ,0xffb5d65c) // Found @0xffb5d65c
DEF(FlashParamsTable                        ,0xffba1c08) // Found @0xffba1c08
DEF(movie_status                            ,0x00006424) // Found @0xff95e204
DEF(full_screen_refresh                     ,0x0000872c) // Found @0xff9d75c0
DEF(canon_menu_active                       ,0x00002ec8) // Found @0xff8815e8
DEF(canon_shoot_menu_active                 ,0x00007881) // Found @0xff99fa04
DEF(playrec_mode                            ,0x00002c1c) // Found @0xff8755f4
DEF(zoom_status                             ,0x0000b750) // Found @0xffa85ea4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 127 entries in the table - set NUM_FL to 127
DEF(focus_len_table                         ,0xfffeabc8) // Found @0xfffeabc8
DEF(zoom_busy                               ,0x000062bc) // Found @0xff958830
DEF(focus_busy                              ,0x00006150) // Found @0xff953fbc
DEF(recreview_hold                          ,0x00003474) // Found @0xff88eeac
DEF(palette_control                         ,0x0000872c) // Found @0xff9d753c
DEF(active_palette_buffer                   ,0x00008734) // Found @0xff9d7540
DEF(palette_buffer                          ,0x000b2228) // Found @0xff9d78e4
DEF(viewport_buffers                        ,0xffb0f13c) // Found @0xff849bd8
DEF(active_viewport_buffer                  ,0x000020b4) // Found @0xff849940

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff852d80
//void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffadf038
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2960+0x54)); } // Found @0xff867a04 & 0xff867a3c
//char *camera_jpeg_count_str()    { return (char*)0x000b1abc; }             // Found @0xff9cd838
//long hook_raw_size()             { return 0x01794300; }                    // Found @0xffae1e6c
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff989b60

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0f600, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0f608, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb0f588, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb0f590, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb0f5a0, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb0f5a0, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb0f598, levent 0x00
//    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb0f5a8, levent 0x04
//    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb0f5b0, levent 0x05
//    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb0f5b8, levent 0x07
//    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb0f5c0, levent 0x06
//    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb0f5c8, levent 0x09
//    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb0f5d0, levent 0x08
//    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb0f5d8, levent 0x1a
//    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb0f5e0, levent 0x14
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb0f5e8, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb0f5f0, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff92edac
//#define CAM_RAW_ROWS      3504 // Found @0xff92edb8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff8342c4

// Misc stuff
DEF(ctypes, 0xffb0e98c)

// For capt_seq.c
//static long *nrflag = (long*)(0x8868+0x00);  // Found @ ff9e4120 & ff9e415c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa74a7c) //101
NSTUB(AllocateUncacheableMemory               ,0xff83427c) //112
NSTUB(Close                                   ,0xff8314a4) //101
NSTUB(CreateTask                              ,0x003f6824) //101
NSTUB(DebugAssert                             ,0x003f6afc) //111
NSTUB(DeleteDirectory_Fut                     ,0xff830ea4) //116
NSTUB(DoAFLock                                ,0xff832d24) //102
NSTUB(EnterToCompensationEVF                  ,0xff832f88) //104
NSTUB(ExecuteEventProcedure                   ,0xff87cb10) //104
NSTUB(ExitFromCompensationEVF                 ,0xff832fcc) //104
NSTUB(ExitTask                                ,0x003f6ab4) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff83d708) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff83d864) //104
NSTUB(Fclose_Fut                              ,0xff830f3c) //101
NSTUB(Feof_Fut                                ,0xff831128) //  1
NSTUB(Fflush_Fut                              ,0xff831164) //  1
NSTUB(Fgets_Fut                               ,0xff831090) //  6
NSTUB(Fopen_Fut                               ,0xff830efc) //101
NSTUB(Fread_Fut                               ,0xff830fe8) //101
NSTUB(FreeMemory                              ,0xffa74a74) //101
NSTUB(FreeUncacheableMemory                   ,0xff8342bc) //112
NSTUB(Fseek_Fut                               ,0xff8310dc) //101
NSTUB(Fwrite_Fut                              ,0xff83103c) //101
NSTUB(GetBatteryTemperature                   ,0xff85896c) //102
NSTUB(GetCCDTemperature                       ,0xff8588f8) //102
NSTUB(GetCurrentAvValue                       ,0xff955b6c) //102
NSTUB(GetDrive_ClusterSize                    ,0xff866458) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff8664b0) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff866488) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff954d80) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff9551d0) //  3
NSTUB(GetImageFolder                          ,0xff938318) //  6
NSTUB(GetKbdState                             ,0xff856978) //109
NSTUB(GetMemInfo                              ,0xff81508c) //115
NSTUB(GetOpticalTemperature                   ,0xff8589e0) //102
NSTUB(GetParameterData                        ,0xff989b20) //101
NSTUB(GetPropertyCase                         ,0xff880b88) //102
NSTUB(GetSystemTime                           ,0xffa74ad4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff84bcb8) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff84bcc4) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff958ca4) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa65c30) //102
NSTUB(GiveSemaphore                           ,0x003f7704) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8cab30) //102
NSTUB(LEDDrive                                ,0xff95fac0) //101
NSTUB(LocalTime                               ,0x003fb1b8) //115
NSTUB(LockMainPower                           ,0xff885438) //103
NSTUB(Lseek                                   ,0xff8316c0) //101
NSTUB(MakeSDCardBootable                      ,0xff8666e8) //105
NSTUB(MoveFocusLensToDistance                 ,0xffadb0f4) //102
NSTUB(MoveIrisWithAv                          ,0xffa6ff0c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa70640) //102
NSTUB(NewTaskShell                            ,0xff880508) //101
NSTUB(Open                                    ,0xff8313dc) //101
NSTUB(PB2Rec                                  ,0xff888168) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff86e588) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff86e560) //102
NSTUB(PT_PlaySound                            ,0xff87734c) // 11
NSTUB(PostLogicalEventForNotPowerType         ,0xff884b2c) //103
NSTUB(PostLogicalEventToUI                    ,0xff884b78) //103
NSTUB(PutInNdFilter                           ,0xffa70418) //102
NSTUB(PutOutNdFilter                          ,0xffa7043c) //102
NSTUB(Read                                    ,0xff815b48) //101
NSTUB(ReadFastDir                             ,0xffa561cc) //115
NSTUB(Rec2PB                                  ,0xff8881a8) //104
NSTUB(RefreshPhysicalScreen                   ,0xff896d88) //104
NSTUB(Remove                                  ,0xff831618) //  6
NSTUB(RenameFile_Fut                          ,0xff830d9c) //116
NSTUB(Restart                                 ,0xff835a90) //106
NSTUB(ScreenLock                              ,0xff897da8) //  4
NSTUB(ScreenUnlock                            ,0xff897e0c) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffade210) //102
NSTUB(SetAutoShutdownTime                     ,0xff8854ac) //103
NSTUB(SetCurrentCaptureModeType               ,0xff88c324) //101
NSTUB(SetFileAttributes                       ,0xff8318a8) //  6
NSTUB(SetFileTimeStamp                        ,0xff831830) //  6
NSTUB(SetLogicalEventActive                   ,0xff8851b4) //101
NSTUB(SetParameterData                        ,0xff989a90) //101
NSTUB(SetPropertyCase                         ,0xff880a00) //102
NSTUB(SetScriptMode                           ,0xff885204) //101
NSTUB(SleepTask                               ,0x003f79b0) //101
NSTUB(TakeSemaphore                           ,0x003f7634) //101
NSTUB(TurnOffBackLight                        ,0xff891ea8) //104
NSTUB(TurnOnBackLight                         ,0xff891e90) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff97b6d8) //101
NSTUB(UnlockAF                                ,0xff832d5c) //102
NSTUB(UnlockMainPower                         ,0xff88538c) //103
NSTUB(UnsetZoomForMovie                       ,0xff9902c0) //104
NSTUB(VbattGet                                ,0xff82c3bc) //101
NSTUB(Write                                   ,0xff8314f8) //101
NSTUB(WriteSDCard                             ,0xff948040) //108
NSTUB(_log                                    ,0x003fcce0) //111
NSTUB(_log10                                  ,0x003fd220) //112
NSTUB(_pow                                    ,0x003fd398) //114
NSTUB(_sqrt                                   ,0x003fefbc) //  6
NSTUB(add_ptp_handler                         ,0xffa19e48) //  6
NSTUB(apex2us                                 ,0xff9dd938) //  4
NSTUB(close                                   ,0xff8159a4) //  6
NSTUB(closedir                                ,0xffa56028) //  4
NSTUB(err_init_task                           ,0xff81436c) //111
NSTUB(exmem_alloc                             ,0xff87b4e4) //101
NSTUB(free                                    ,0xff812f68) //112
NSTUB(kbd_p1_f                                ,0xff82edec) //109
NSTUB(kbd_p1_f_cont                           ,0xff82edf8) //109
NSTUB(kbd_p2_f                                ,0xff82e5e4) //109
NSTUB(kbd_read_keys                           ,0xff82ed9c) //109
NSTUB(kbd_read_keys_r2                        ,0xff856494) //109
NSTUB(lseek                                   ,0xff8316c0) //101
NSTUB(malloc                                  ,0xff812f10) //112
NSTUB(memcmp                                  ,0xff81ae20) //101
NSTUB(memcpy                                  ,0xff8371fc) //101
NSTUB(memset                                  ,0xff9dbbcc) //101
NSTUB(mkdir                                   ,0xff831940) //  6
NSTUB(mktime_ext                              ,0xff8982d8) //  1
NSTUB(open                                    ,0xff8158f4) //  6
NSTUB(OpenFastDir                             ,0xffa56078) //115
NSTUB(qsort                                   ,0xff9dbb6c) //  6
NSTUB(read                                    ,0xff815b48) //101
NSTUB(reboot_fw_update                        ,0xffa5b5a8) //106
NSTUB(set_control_event                       ,0xff884e74) //111
NSTUB(stat                                    ,0xff831708) //109
NSTUB(strcat                                  ,0xff898958) //  1
NSTUB(strchr                                  ,0xff812ddc) //  1
NSTUB(strcmp                                  ,0xff81af1c) //101
NSTUB(strcpy                                  ,0xff81ae08) //101
NSTUB(strftime                                ,0xff898324) //113
NSTUB(strlen                                  ,0xff812e28) //101
NSTUB(strncmp                                 ,0xff812d90) //  1
NSTUB(strncpy                                 ,0xff812d54) //  1
NSTUB(strrchr                                 ,0xff812e00) //  1
NSTUB(strtol                                  ,0xff8371e8) //101
NSTUB(strtolx                                 ,0xff836fec) //109
  DEF(task_CaptSeq                            ,0xff870db0) //110
  DEF(task_ExpDrv                             ,0xff8afadc) //110
  DEF(task_InitFileModules                    ,0xff88895c) //110
  DEF(task_MovieRecord                        ,0xff95ed68) //110
  DEF(task_PhySw                              ,0xff82e948) //110
NSTUB(time                                    ,0x003fb794) //  6
NSTUB(vsprintf                                ,0xff81acb8) //115
NSTUB(write                                   ,0xff8314f8) //101
