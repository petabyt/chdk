// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
// DRYOS R47 (DRYOS version 2.3, release #0047)
// Firmware Ver GM1.01B
// Canon PowerShot SX220 HS

// Stubs below should be checked. Stub not matched 100%, or difference
// found to current 'stubs_entry_2.S' or original 'stubs_entry.S'
//    Name                                     Address           %   Comp to stubs_entry_2.S  Comp to stubs_entry.S.orig
//NSTUB(kbd_pwr_off                           ,0xff0565ac) //  2 60%    *** != 0xff000b24              Not Found
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff000b24              Not Found
//NSTUB(write                                 ,0xff0270d8) //101        *** != 0xff00adb8      *** != 0xff00adb8 @  80%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff0953cc -> ff091c94 -> ff1b2368 -> ff318d58 -> ff48a470
// Current modemap entry not found in firmware - MODE_SCN_MONOCHROME       8754
// Current modemap entry not found in firmware - MODE_SCN_TOY_CAMERA       8751
// Current modemap entry not found in firmware - MODE_SCN_SUPER_VIVID      8742
// Current modemap entry not found in firmware - MODE_SCN_MINIATURE        8748
// Current modemap entry not found in firmware - MODE_SCN_FISHEYE          8747
// Current modemap entry not found in firmware - MODE_SCN_POSTER_EFFECT    8743
// Current modemap entry not found in firmware - MODE_SCN_COLOR_SWAP       8734
// Current modemap entry not found in firmware - MODE_SCN_COLOR_ACCENT     8733

// Values below go in 'stubs_min.S':
//DEF(physw_status                            ,0x000357a8) // Found @0xff024960,          stubs_min = 0x000357a8 (0x357A8)
//DEF(physw_run                               ,0x00001c40) // Found @0xff0244f4,          stubs_min = 0x00001c40 (0x1C40)
//DEF(levent_table                            ,0xff41648c) // Found @0xff41648c,          stubs_min = 0xff41648c (0xFF41648C)
//DEF(FlashParamsTable                        ,0xff48a6bc) // Found @0xff48a6bc, ** != ** stubs_min = 0xff48a4b8 (0xFF48A4B8)
//DEF(movie_status                            ,0x00008594) // Found @0xff187064,          stubs_min = 0x00008594 (0x8550+0x44)
//DEF(full_screen_refresh                     ,0x0000b35c) // Found @0xff23d628,          stubs_min = 0x0000b35c (0xB35C)
//DEF(canon_menu_active                       ,0x00004274) // Found @0xff08b3f4,          stubs_min = 0x00004274 (0x4270+4)
//DEF(canon_shoot_menu_active                 ,0x000098e9) // Found @0xff1ce4f8,          stubs_min = 0x000098e9 (0x98E8+1)
//DEF(playrec_mode                            ,0x00003fa8) // Found @0xff07d76c,          stubs_min = 0x00003fa8 (0x3FA4+0x4)
//DEF(zoom_status                             ,0x0000f5c4) // Found @0xff31c410, ** != ** stubs_min = 0x0000f5a4 (0xF5A4)
//DEF(some_flag_for_af_scan                   ,0x00008998) // Found @0xff18b738,          stubs_min = 0x00008998 (0x8998)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()     { return (void*)0x40471000; } // Found @0xff050f20
//void *vid_get_viewport_fb()   { return (void*)0x405d7980; } // Found @0xff371eb0
//char *camera_jpeg_count_str() { return (char*)0x000ca790; } // Found @0xff2327fc
//long hook_raw_size()          { return 0x0123eaf0; }        // Found @0xff3753c4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xff3b18bc, levent 0x90a
//#define SD_READONLY_IDX     2         
//#define USB_FLAG            0x04000000 // Found @0xff3b18ec, levent 0x902
//#define USB_IDX             2         

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_DISPLAY     ,0x00000800 }, // Found @0xff3b182c, levent 0x0a
//    { 0, KEY_UP          ,0x00001000 }, // Found @0xff3b1834, levent 0x04
//    { 0, KEY_RIGHT       ,0x00004000 }, // Found @0xff3b1844, levent 0x07
//    { 0, KEY_SET         ,0x00010000 }, // Found @0xff3b1854, levent 0x08
//    { 0, KEY_DOWN        ,0x00020000 }, // Found @0xff3b185c, levent 0x05
//    { 0, KEY_MENU        ,0x00040000 }, // Found @0xff3b1864, levent 0x09
//    { 2, KEY_LEFT        ,0x00000100 }, // Found @0xff3b1894, levent 0x06
//    { 2, KEY_SHOOT_HALF  ,0x00002000 }, // Found @0xff3b18a4, levent 0x00
//    { 2, KEY_SHOOT_FULL  ,0x00002002 }, // Found @0xff3b1884, levent 0x01
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1
//#define CAM_RAW_ROWPIX    4168 // Found @0xff152aa4
//#define CAM_RAW_ROWS      3060 // Found @0xff152aa8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02b88c

// Stubs below matched 100%.
//    Name                                     Address           %   Comp to stubs_entry_2.S  Comp to stubs_entry.S.orig
//NSTUB(AllocateMemory                        ,0xff3075f4) //101            == 0xff3075f4          != 0xff3075d0 @  82%
//NSTUB(AllocateUncacheableMemory             ,0xff02b844) //112            == 0xff02b844          == 0xff02b844 @  82%
//NSTUB(Close                                 ,0xff027084) //101            == 0xff027084              Not Found
//NSTUB(CreateTask                            ,0xff00e9b0) //101            == 0xff00e9b0          == 0xff00e9b0 @  51%
//NSTUB(DebugAssert                           ,0xff00ec88) //111            == 0xff00ec88    
//NSTUB(DeleteFile_Fut                        ,0xff02699c) //112            == 0xff02699c          == 0xff02699c @  85%
//NSTUB(DoAFLock                              ,0xff028bd8) //102            == 0xff028bd8    
//NSTUB(EnterToCompensationEVF                ,0xff028e74) //104            == 0xff028e74              Not Found
//NSTUB(ExecuteEventProcedure                 ,0xff086bdc) //  1            == 0xff086bdc    
//NSTUB(ExitFromCompensationEVF               ,0xff028eb8) //104            == 0xff028eb8              Not Found
//NSTUB(ExitTask                              ,0xff00ec40) //101            == 0xff00ec40          == 0xff00ec40 @  57%
//NSTUB(ExpCtrlTool_StartContiAE              ,0xff037fe4) //104            == 0xff037fe4    
//NSTUB(ExpCtrlTool_StopContiAE               ,0xff0380bc) //104            == 0xff0380bc    
//NSTUB(Fclose_Fut                            ,0xff026b18) //101            == 0xff026b18          == 0xff026b18 @  96%
//NSTUB(Feof_Fut                              ,0xff026d04) //  1            == 0xff026d04    
//NSTUB(Fflush_Fut                            ,0xff026d40) //  1            == 0xff026d40    
//NSTUB(Fgets_Fut                             ,0xff026c6c) //  6            == 0xff026c6c              Not Found
//NSTUB(Fopen_Fut                             ,0xff026ad8) //101            == 0xff026ad8          == 0xff026ad8 @  89%
//NSTUB(Fread_Fut                             ,0xff026bc4) //101            == 0xff026bc4              Not Found
//NSTUB(FreeMemory                            ,0xff3075ec) //101            == 0xff3075ec          != 0xff3075c8 @  88%
//NSTUB(FreeUncacheableMemory                 ,0xff02b884) //112            == 0xff02b884          == 0xff02b884 @  83%
//NSTUB(Fseek_Fut                             ,0xff026cb8) //101            == 0xff026cb8          == 0xff026cb8 @  72%
//NSTUB(Fwrite_Fut                            ,0xff026c18) //101            == 0xff026c18              Not Found
//NSTUB(GetBatteryTemperature                 ,0xff05d010) //102            == 0xff05d010          == 0xff05d010 @  52%
//NSTUB(GetCCDTemperature                     ,0xff05cf9c) //102            == 0xff05cf9c          == 0xff05cf9c @  52%
//NSTUB(GetCurrentAvValue                     ,0xff17f15c) //102            == 0xff17f15c              Not Found
//NSTUB(GetDrive_ClusterSize                  ,0xff06adbc) //  6            == 0xff06adbc              Not Found
//NSTUB(GetDrive_FreeClusters                 ,0xff06ae14) //  6            == 0xff06ae14              Not Found
//NSTUB(GetDrive_TotalClusters                ,0xff06adec) //  6            == 0xff06adec              Not Found
//NSTUB(GetFocusLensSubjectDistance           ,0xff17d3ec) //102            == 0xff17d3ec          == 0xff17d3ec @  64%
//NSTUB(GetFocusLensSubjectDistanceFromLens   ,0xff17d84c) //  3            == 0xff17d84c          == 0xff17d84c @  77%
//NSTUB(GetImageFolder                        ,0xff1598b8) //  6            == 0xff1598b8    
//NSTUB(GetKbdState                           ,0xff056474) //109            == 0xff056474    
//NSTUB(GetMemInfo                            ,0xff00a29c) //  3            == 0xff00a29c          == 0xff00a29c @  96%
//NSTUB(GetOpticalTemperature                 ,0xff05d084) //102            == 0xff05d084          == 0xff05d084 @  65%
//NSTUB(GetParameterData                      ,0xff1b3360) //101            == 0xff1b3360              Not Found
//NSTUB(GetPropertyCase                       ,0xff08a944) //102            == 0xff08a944          == 0xff08a944 @  65%
//NSTUB(GetSystemTime                         ,0xff30764c) //101            == 0xff30764c          != 0xff307628 @  59%
//NSTUB(GetZoomLensCurrentPoint               ,0xff182660) //102            == 0xff182660              Not Found
//NSTUB(GetZoomLensCurrentPosition            ,0xff2f14cc) //102            == 0xff2f14cc              Not Found
//NSTUB(GiveSemaphore                         ,0xff02b23c) //112            == 0xff02b23c    
//NSTUB(IsStrobeChargeCompleted               ,0xff0e0cd0) //102            == 0xff0e0cd0          == 0xff0e0cd0 @  54%
//NSTUB(LEDDrive                              ,0xff0557c0) //101            == 0xff0557c0    
//NSTUB(LocalTime                             ,0xff08446c) //  6            == 0xff08446c              Not Found
//NSTUB(LockMainPower                         ,0xff091884) //103            == 0xff091884          == 0xff091884 @  82%
//NSTUB(Lseek                                 ,0xff0272a0) //101            == 0xff0272a0              Not Found
//NSTUB(MakeDirectory_Fut                     ,0xff026a10) //  6            == 0xff026a10              Not Found
//NSTUB(MakeSDCardBootable                    ,0xff06b04c) //  6            == 0xff06b04c    
//NSTUB(MoveFocusLensToDistance               ,0xff36e1ac) //102            == 0xff36e1ac          != 0xff36e188 @  61%
//NSTUB(MoveIrisWithAv                        ,0xff30365c) //102            == 0xff30365c    
//NSTUB(MoveZoomLensWithPoint                 ,0xff303e20) //102            == 0xff303e20              Not Found
//NSTUB(NewTaskShell                          ,0xff08a38c) //101            == 0xff08a38c          == 0xff08a38c @  51%
//NSTUB(Open                                  ,0xff026fbc) //101            == 0xff026fbc              Not Found
//NSTUB(PB2Rec                                ,0xff094a5c) //104            == 0xff094a5c              Not Found
//NSTUB(PT_MoveDigitalZoomToWide              ,0xff0746e8) //102            == 0xff0746e8    
//NSTUB(PT_MoveOpticalZoomAt                  ,0xff0746c0) //102            == 0xff0746c0    
//NSTUB(PT_PlaySound                          ,0xff07f848) //  6            == 0xff07f848              Not Found
//NSTUB(PostLogicalEventForNotPowerType       ,0xff08f3a8) //103            == 0xff08f3a8              Not Found
//NSTUB(PostLogicalEventToUI                  ,0xff08f3f4) //103            == 0xff08f3f4              Not Found
//NSTUB(PutInNdFilter                         ,0xff36bdf8) //102            == 0xff36bdf8    
//NSTUB(PutOutNdFilter                        ,0xff36be30) //102            == 0xff36be30    
//NSTUB(Read                                  ,0xff00ad58) //101            == 0xff00ad58          == 0xff00ad58 @  80%
//NSTUB(ReadFastDir                           ,0xff2dd404) //  6            == 0xff2dd404              Not Found
//NSTUB(Rec2PB                                ,0xff0931fc) //104            == 0xff0931fc              Not Found
//NSTUB(RefreshPhysicalScreen                 ,0xff0aa058) //104            == 0xff0aa058              Not Found
//NSTUB(Remove                                ,0xff0271f8) //  6            == 0xff0271f8              Not Found
//NSTUB(RenameFile_Fut                        ,0xff026908) //  6            == 0xff026908          != 0xff026ad4 @  60%
//NSTUB(Restart                               ,0xff02d058) //106            == 0xff02d058          != 0xff307134 @  69%
//NSTUB(ScreenLock                            ,0xff0ab250) //  4            == 0xff0ab250    
//NSTUB(ScreenUnlock                          ,0xff0ab2b4) //  3            == 0xff0ab2b4    
//NSTUB(SetAutoShutdownTime                   ,0xff0918f8) //103            == 0xff0918f8          == 0xff0918f8 @  80%
//NSTUB(SetCurrentCaptureModeType             ,0xff09ae08) //101            == 0xff09ae08              Not Found
//NSTUB(SetFileTimeStamp                      ,0xff027410) //  6            == 0xff027410          != 0xff16b670 @  61%
//NSTUB(SetLogicalEventActive                 ,0xff0915c0) //101            == 0xff0915c0          == 0xff0915c0 @  64%
//NSTUB(SetParameterData                      ,0xff1b32d0) //101            == 0xff1b32d0          == 0xff1b32d0 @  62%
//NSTUB(SetPropertyCase                       ,0xff08a828) //102            == 0xff08a828          == 0xff08a828 @  58%
//NSTUB(SetScriptMode                         ,0xff091610) //101            == 0xff091610    
//NSTUB(SleepTask                             ,0xff02b4e8) //101            == 0xff02b4e8              Not Found
//NSTUB(TakeSemaphore                         ,0xff02b16c) //101            == 0xff02b16c          == 0xff02b16c @  60%
//NSTUB(TurnOffBackLight                      ,0xff0a21b8) //104            == 0xff0a21b8              Not Found
//NSTUB(TurnOnBackLight                       ,0xff0a21a0) //104            == 0xff0a21a0              Not Found
//NSTUB(UIFS_WriteFirmInfoToFile              ,0xff1a4414) //101            == 0xff1a4414              Not Found
//NSTUB(UnlockAF                              ,0xff028c10) //102            == 0xff028c10    
//NSTUB(UnlockMainPower                       ,0xff0917d8) //103            == 0xff0917d8          == 0xff0917d8 @  73%
//NSTUB(VbattGet                              ,0xff023040) //101            == 0xff023040          == 0xff023040 @  85%
//NSTUB(Write                                 ,0xff0270d8) //101            == 0xff0270d8              Not Found
//NSTUB(WriteSDCard                           ,0xff16c828) //108            == 0xff16c828    
//NSTUB(_log                                  ,0xff3ac798) //111            == 0xff3ac798              Not Found
//NSTUB(_log10                                ,0xff3accd8) //112            == 0xff3accd8              Not Found
//NSTUB(_pow                                  ,0xff3ace50) //114            == 0xff3ace50              Not Found
//NSTUB(_sqrt                                 ,0xff3aed34) //  6            == 0xff3aed34          != 0xff3aed14 @  66%
//NSTUB(add_ptp_handler                       ,0xff28aa1c) //  6            == 0xff28aa1c          == 0xff28aa1c @  71%
//NSTUB(apex2us                               ,0xff246bec) //  4            == 0xff246bec    
//NSTUB(close                                 ,0xff00abb4) //  6            == 0xff00abb4          == 0xff00abb4 @  84%
//NSTUB(closedir                              ,0xff2dd260) //  4            == 0xff2dd260              Not Found
//NSTUB(err_init_task                         ,0xff005fd4) //  4            == 0xff005fd4    
//NSTUB(exmem_alloc                           ,0xff085434) //101            == 0xff085434    
//NSTUB(free                                  ,0xff004244) //112            == 0xff004244              Not Found
//NSTUB(kbd_p1_f                              ,0xff0249dc) //109            == 0xff0249dc              Not Found
//NSTUB(kbd_p1_f_cont                         ,0xff0249e8) //109            == 0xff0249e8              Not Found
//NSTUB(kbd_p2_f                              ,0xff0241c4) //109            == 0xff0241c4              Not Found
//NSTUB(kbd_read_keys                         ,0xff024960) //109            == 0xff024960              Not Found
//NSTUB(kbd_read_keys_r2                      ,0xff055c78) //109            == 0xff055c78              Not Found
//NSTUB(lseek                                 ,0xff0272a0) //101            == 0xff0272a0          != 0xff0272ac @  60%
//NSTUB(malloc                                ,0xff0041ec) //112            == 0xff0041ec          != 0xff0041e8 @  85%
//NSTUB(memcmp                                ,0xff0108f4) //101            == 0xff0108f4    
//NSTUB(memcpy                                ,0xff030fec) //101            == 0xff030fec              Not Found
//NSTUB(memset                                ,0xff245bec) //101            == 0xff245bec              Not Found
//NSTUB(mkdir                                 ,0xff027520) //  6            == 0xff027520              Not Found
//NSTUB(mktime_ext                            ,0xff0ac0c8) //  1            == 0xff0ac0c8    
//NSTUB(open                                  ,0xff00ab04) //  6            == 0xff00ab04          == 0xff00ab04 @  80%
//NSTUB(opendir                               ,0xff2dd2b0) //  6            == 0xff2dd2b0          == 0xff2dd2b0 @  59%
//NSTUB(openfastdir                           ,0xff2dd2b0) //  6            == 0xff2dd2b0              Not Found
//NSTUB(qsort                                 ,0xff35949c) //  6            == 0xff35949c              Not Found
//NSTUB(rand                                  ,0xff245d2c) //  6            == 0xff245d2c              Not Found
//NSTUB(read                                  ,0xff00ad58) //101            == 0xff00ad58          == 0xff00ad58 @  80%
//NSTUB(readfastdir                           ,0xff2dd404) //  6            == 0xff2dd404              Not Found
//NSTUB(reboot_fw_update                      ,0xff2e28a0) //  6            == 0xff2e28a0          == 0xff2e28a0 @  58%
//NSTUB(rename                                ,0xff026908) //  6            == 0xff026908              Not Found
//NSTUB(set_control_event                     ,0xff0911b8) //111            == 0xff0911b8              Not Found
//NSTUB(srand                                 ,0xff245d20) //  6            == 0xff245d20              Not Found
//NSTUB(stat                                  ,0xff0272e8) //  3            == 0xff0272e8          == 0xff0272e8 @  76%
//NSTUB(strcat                                ,0xff0ab880) //  1            == 0xff0ab880          != 0xff004030 @  61%
//NSTUB(strchr                                ,0xff0040b8) //  1            == 0xff0040b8          == 0xff0040b8 @  56%
//NSTUB(strcmp                                ,0xff0108b0) //101            == 0xff0108b0    
//NSTUB(strcpy                                ,0xff010898) //101            == 0xff010898    
//NSTUB(strftime                              ,0xff0abac8) //113            == 0xff0abac8          == 0xff0abac8 @  72%
//NSTUB(strlen                                ,0xff004104) //101            == 0xff004104          != 0xff0108d0 @  79%
//NSTUB(strncmp                               ,0xff00406c) //  1            == 0xff00406c    
//NSTUB(strncpy                               ,0xff004030) //  1            == 0xff004030          == 0xff004030 @  73%
//NSTUB(strrchr                               ,0xff0040dc) //  1            == 0xff0040dc              Not Found
//NSTUB(strtol                                ,0xff0312ec) //101            == 0xff0312ec              Not Found
//NSTUB(strtolx                               ,0xff0310f0) //109            == 0xff0310f0              Not Found
//  DEF(task_CaptSeq                          ,0xff077628) //110            == 0xff077628    
//  DEF(task_ExpDrv                           ,0xff0c3e54) //110            == 0xff0c3e54    
//  DEF(task_InitFileModules                  ,0xff095240) //110            == 0xff095240    
//  DEF(task_MovieRecord                      ,0xff1882f0) //110            == 0xff1882f0    
//  DEF(task_PhySw                            ,0xff0244f0) //110            == 0xff0244f0    
//  DEF(task_RotaryEncoder                    ,0xff05671c) //110            == 0xff05671c    
//NSTUB(time                                  ,0xff084a48) //  6            == 0xff084a48          == 0xff084a48 @  80%
//NSTUB(vsprintf                              ,0xff010858) //  6            == 0xff010858              Not Found
