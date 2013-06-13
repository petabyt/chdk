// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R39 (DRYOS version 2.3, release #0039)
//   Firmware Ver GM1.00F
//   Canon PowerShot G11

// Values for makefile.inc
//   PLATFORMOSVER = 39
//   PLATFORMID = 12767 (0x31df) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff35a8
//   NEED_ENCODED_DISKBOOT = 3   // Found @ 0xffff35b8

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(SetScriptMode                        ,0xff895014) //101        *** != 0xff810f4c
NHSTUB(kbd_pwr_off                            ,0xff8603ec) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff899018 -> ff895658 -> ff995248 -> ffab4778 -> ffbe6f0c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032578) // Found @0xff833554
DEF(physw_run                               ,0x00001c44) // Found @0xff8331c4
DEF(physw_sleep_delay                       ,0x00001c42) // Found @0xff8331c4
DEF(levent_table                            ,0xffb95d20) // Found @0xffb95d20
DEF(FlashParamsTable                        ,0xffbe7100) // Found @0xffbe7100
DEF(movie_status                            ,0x00006d90) // Found @0xff9627d8
DEF(video_compression_rate                  ,0x00006dbc) // Found @0xff962994
DEF(full_screen_refresh                     ,0x00009840) // Found @0xffa0ec68
DEF(canon_menu_active                       ,0x0000303c) // Found @0xff88e1ac
DEF(canon_shoot_menu_active                 ,0x00008259) // Found @0xff9af8c4
DEF(playrec_mode                            ,0x00002d64) // Found @0xff880488
DEF(zoom_status                             ,0x0000c868) // Found @0xffab7664
DEF(some_flag_for_af_scan                   ,0x000072b4) // Found @0xff965e50
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 14 entries in the table - set NUM_FL to 14
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00006cc0) // Found @0xff95e9b4
DEF(focus_busy                              ,0x00006bb4) // Found @0xff9599a8
//DEF(recreview_hold                          ,0x00003be4) // Found @0xff89fa18, ** != ** stubs_min = 0x00007dd8 (0x7D00+0xD8)
// Palette colour tables  found @ 0xffbb0a00
DEF(active_palette_buffer                   ,0x00009848) // Found @0xffa0eba4
DEF(palette_buffer_ptr                      ,0x00009854) // Found @0xffa0e878
// Offset from start of palette_buffer to color data = 8 (Found @0xffaedb14)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85a490
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb066ac
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2a50+0x58)); } // Found @0xff8712a8 & 0xff8712e0
//char *camera_jpeg_count_str()    { return (char*)0x00097234; }             // Found @0xffa0107c
//long hook_raw_size()             { return 0x00ee9200; }                    // Found @0xffb09964
//int get_flash_params_count(void) { return 0x84; }                          // Found @0xff996848

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb474ec, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00100000 // Found @0xffb47510, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb47378, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb47384, levent 0x02
//    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xffb473cc, levent 0x06
//    { 0, KEY_SET             ,0x00000800 }, // Found @0xffb473d8, levent 0x08
//    { 0, KEY_RIGHT           ,0x00001000 }, // Found @0xffb473e4, levent 0x07
//    { 0, KEY_DOWN            ,0x00002000 }, // Found @0xffb473f0, levent 0x05
//    { 0, KEY_UP              ,0x00004000 }, // Found @0xffb473fc, levent 0x04
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb47420, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xffb4742c, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb474b0, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb474b0, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb474a4, levent 0x00
//    { 2, KEY_POWER           ,0x00000004 }, // Found @0xffb474bc, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xffb474c8, levent 0x601 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3744 // Found @0xff9356e4
//#define CAM_RAW_ROWS      2784 // Found @0xff9356ec
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff839430

// Misc stuff
DEF(ctypes, 0xffb402c6)

// For capt_seq.c
DEF(_nrflag,0x7290) // Found @ ff968738 (0x7298) & ff968758 (-0x08)
//static long *nrflag = (long*)(0x7298-0x08);  // Found @ ff968738 & ff968754

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb0a3ec) //  1
//NHSTUB(_uartr_req                           ,0xff81f968) //111
//NHSTUB(AllocateMemory                       ,0xffaa3438) //101
NHSTUB(AllocateUncacheableMemory              ,0xff8393ec) //112
NHSTUB(Close                                  ,0xff835980) //101
NHSTUB(CreateTask                             ,0xff81e5b4) //101
NHSTUB(DebugAssert                            ,0xff81e88c) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff8353f0) //116
NHSTUB(DeleteFile_Fut                         ,0xff83530c) //112
NHSTUB(DoAFLock                               ,0xff837128) //102
NHSTUB(EnterToCompensationEVF                 ,0xff8373a8) //104
NHSTUB(ExecuteEventProcedure                  ,0xff889834) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8373ec) //104
NHSTUB(ExitTask                               ,0xff81e844) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff844cb0) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff844d88) //104
NHSTUB(Fclose_Fut                             ,0xff835488) //101
NHSTUB(Feof_Fut                               ,0xff835674) //  1
NHSTUB(Fflush_Fut                             ,0xff8356b0) //  1
NHSTUB(Fgets_Fut                              ,0xff8355dc) //  1
NHSTUB(Fopen_Fut                              ,0xff835448) //101
NHSTUB(Fread_Fut                              ,0xff835534) //101
//NHSTUB(FreeMemory                           ,0xffaa3430) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83942c) //112
NHSTUB(Fseek_Fut                              ,0xff835628) //101
NHSTUB(Fwrite_Fut                             ,0xff835588) //101
NHSTUB(GetBatteryTemperature                  ,0xff863588) //102
NHSTUB(GetCCDTemperature                      ,0xff863514) //102
NHSTUB(GetCurrentAvValue                      ,0xff95c14c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86fc30) //  3
NHSTUB(GetDrive_FreeClusters                  ,0xff86fc90) //  3
NHSTUB(GetDrive_TotalClusters                 ,0xff86fc64) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff95a720) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff95ab68) //  3
NHSTUB(GetImageFolder                         ,0xff93d570) //106
NHSTUB(GetKbdState                            ,0xff8603d4) //109
NHSTUB(GetMemInfo                             ,0xff81a070) //115
NHSTUB(GetOpticalTemperature                  ,0xff8635fc) //102
NHSTUB(GetParameterData                       ,0xff996808) //101
NHSTUB(GetPropertyCase                        ,0xff88d5e0) //102
NHSTUB(GetSystemTime                          ,0xffaa3490) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff850ad8) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff850ae4) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff95ed28) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa9669c) //102
NHSTUB(GiveSemaphore                          ,0xff838e08) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8db30c) //102
NHSTUB(LEDDrive                               ,0xff85f624) //103
NHSTUB(LocalTime                              ,0xff8871a8) //115
NHSTUB(LockMainPower                          ,0xff895274) //103
//NHSTUB(Lseek                                ,0xff835a9c) //101
NHSTUB(MakeDirectory_Fut                      ,0xff835380) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb030c8) //102
NHSTUB(MoveIrisWithAv                         ,0xffaa0344) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffaa0a5c) //102
//NHSTUB(NewTaskShell                         ,0xff88d08c) //103
NHSTUB(Open                                   ,0xff835928) //101
NHSTUB(PB2Rec                                 ,0xff89837c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff8780a8) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff878080) //102
NHSTUB(PT_PlaySound                           ,0xff882344) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8930a0) //103
NHSTUB(PostLogicalEventToUI                   ,0xff8930ec) //103
NHSTUB(PutInNdFilter                          ,0xffaa08c0) //102
NHSTUB(PutOutNdFilter                         ,0xffaa08e4) //102
NHSTUB(Read                                   ,0xff81ab78) //101
NHSTUB(ReadFastDir                            ,0xffa8416c) //  3
NHSTUB(Rec2PB                                 ,0xff8983bc) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffa0fe64) //104
//NHSTUB(Remove                               ,0xff8359b4) //  4
NHSTUB(RenameFile_Fut                         ,0xff835278) //116
NHSTUB(Restart                                ,0xff83ab40) //106
NHSTUB(ScreenLock                             ,0xffa11094) //  3
NHSTUB(ScreenUnlock                           ,0xffa110bc) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb0586c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8952e8) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff89ca38) //101
NHSTUB(SetFileAttributes                      ,0xff835c50) //  3
NHSTUB(SetFileTimeStamp                       ,0xff835c0c) //  3
NHSTUB(SetLogicalEventActive                  ,0xff894fc4) //101
NHSTUB(SetParameterData                       ,0xff9966e4) //101
NHSTUB(SetPropertyCase                        ,0xff88d4dc) //102
NHSTUB(SleepTask                              ,0xff839070) //101
NHSTUB(TakeSemaphore                          ,0xff838d38) //101
NHSTUB(TurnOffBackLight                       ,0xff8a33a8) //104
NHSTUB(TurnOnBackLight                        ,0xff8a3390) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff98047c) //105
NHSTUB(UnlockAF                               ,0xff837160) //102
NHSTUB(UnlockMainPower                        ,0xff8951c8) //103
NHSTUB(UnsetZoomForMovie                      ,0xff99cdb4) //104
NHSTUB(UpdateMBROnFlash                       ,0xff86fab0) //105
NHSTUB(VbattGet                               ,0xff831e08) //103
NHSTUB(Write                                  ,0xff835a10) //101
NHSTUB(WriteSDCard                            ,0xff94b66c) //108
NHSTUB(_log                                   ,0xffb3dd88) //111
NHSTUB(_log10                                 ,0xffb3cccc) //112
NHSTUB(_pow                                   ,0xffb3ce3c) //114
NHSTUB(_sqrt                                  ,0xffb3f0f0) //  1
NHSTUB(add_ptp_handler                        ,0xffa4dd8c) //  3
NHSTUB(apex2us                                ,0xffa1484c) //  4
NHSTUB(close                                  ,0xff81a990) //  1
NHSTUB(closedir                               ,0xffa83ff4) //  3
NHSTUB(err_init_task                          ,0xff815f28) //111
NHSTUB(exmem_alloc                            ,0xff888068) //103
NHSTUB(exmem_free                             ,0xff8880e0) //103
NHSTUB(free                                   ,0xff814138) //112
NHSTUB(kbd_p1_f                               ,0xff8335d0) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8335dc) //109
NHSTUB(kbd_p2_f                               ,0xff832e90) //109
NHSTUB(kbd_read_keys                          ,0xff833554) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85fb44) //109
NHSTUB(lseek                                  ,0xff835a9c) //101
NHSTUB(malloc                                 ,0xff8140dc) //112
NHSTUB(memcmp                                 ,0xff8203ec) //101
NHSTUB(memcpy                                 ,0xff83e9ec) //101
NHSTUB(memset                                 ,0xffa1389c) //101
NHSTUB(mkdir                                  ,0xff835df4) //109
NHSTUB(mktime_ext                             ,0xff8aaf6c) //  1
NHSTUB(open                                   ,0xff81a8e0) //  1
NHSTUB(OpenFastDir                            ,0xffa84038) //  3
NHSTUB(qsort                                  ,0xffaf37d8) //  1
NHSTUB(rand                                   ,0xff8204f4) //  1
//NHSTUB(read                                 ,0xff81ab78) //101
NHSTUB(realloc                                ,0xffa13918) //115
NHSTUB(reboot_fw_update                       ,0xffa8967c) //106
NHSTUB(set_control_event                      ,0xff894c18) //111
NHSTUB(srand                                  ,0xff8204e8) //  1
NHSTUB(stat                                   ,0xff835ad8) //109
NHSTUB(strcat                                 ,0xff8aa728) //  1
NHSTUB(strchr                                 ,0xff813fc0) //  1
NHSTUB(strcmp                                 ,0xff8203a8) //101
NHSTUB(strcpy                                 ,0xff820390) //101
NHSTUB(strftime                               ,0xff8aa974) //  1
NHSTUB(strlen                                 ,0xff81400c) //101
NHSTUB(strncmp                                ,0xff813f74) //  1
NHSTUB(strncpy                                ,0xff813f38) //  1
NHSTUB(strrchr                                ,0xff813fe4) //  1
NHSTUB(strtol                                 ,0xff83eccc) //101
NHSTUB(strtolx                                ,0xff83ead0) //109
   DEF(task_CaptSeq                           ,0xff87b06c) //110
   DEF(task_ExpDrv                            ,0xff8bfac4) //110
   DEF(task_InitFileModules                   ,0xff898ea4) //110
   DEF(task_MovieRecord                       ,0xff962a10) //110
   DEF(task_PhySw                             ,0xff8331c0) //110
   DEF(task_RotaryEncoder                     ,0xff860504) //110
NHSTUB(time                                   ,0xff887720) //109
NHSTUB(vsprintf                               ,0xff820354) //115
//NHSTUB(write                                ,0xff835a10) //101
//NHSTUB(EngDrvIn                             ,0xff834410) //102
//NHSTUB(EngDrvOut                            ,0xff8343f8) //102
//NHSTUB(EngDrvRead                           ,0xff834418) //102
//NHSTUB(EngDrvBits                           ,0xff83442c) //102
//NHSTUB(GetSDProtect                         ,0xff83352c) //103
//NHSTUB(StartRecModeMenu                     ,0xff88e1a8) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85a448) //102
//NHSTUB(ResetZoomLens                        ,0xffaa09b0) //102
//NHSTUB(ResetFocusLens                       ,0xffa9f5e8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff96b3d4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff96b32c) //102
//NHSTUB(SavePaletteData                      ,0xffb07b8c) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8aa4a8) //101
