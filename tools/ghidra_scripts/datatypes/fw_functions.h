/*
function prototypes for ghidra
initially based on lowelevel.h
manually adjusted / updated

Some adjustments
* CHDK lowlevel names  start _, stubs names do not
* long switched to int, identical on our platform
* removed extern
* add __stdcall functions, tells Ghidra to use normal ARM calling convention
* explicit void for void function args
* platform specific ifdefs removed except where prototypes vary by platform
* Use some known types e.g. __stat instead of void *
* some synchroniztaion object (eventflag, messagequeue) changed to int instead of void *

Note
Some functions already defined in Ghidra generic libc are also defined here

required defines
DryOS cams:
-DCAM_DRYOS_REL=<PLATFORMOSVER from makefile.inc
Some later DryOS and early vxworks
-DCAM_3ARG_DebugAssert=1
Ixus 30 / 40
-DVX_OLD_PTP=1

All (ghidra default)
-D__builtin_va_list=void *

ONLY functions that have different signatures in different versions should be
under ifdefs. Functions that only exist on some firmware can safely be present
without ifdefs.
*/
#ifndef FW_FUNCTIONS_H
#define FW_FUNCTIONS_H
#include "fw_types.h"
#include "ptp_handlers.h"
#ifdef CAM_DRYOS_REL
__stdcall int * GetSystemTime(int *t);
#else
__stdcall int GetSystemTime(void);
#endif
__stdcall int GetZoomLensCurrentPosition(void);
__stdcall int GetZoomLensCurrentPoint(void);
__stdcall int MoveZoomLensWithPoint(short *pos);
__stdcall int SetZoomActuatorSpeedPercent(short *perc);
__stdcall int GetFocusLensCurrentPosition(void);
__stdcall int GetFocusLensSubjectDistance(void);
__stdcall int GetFocusLensSubjectDistanceFromLens(void);
__stdcall void MoveFocusLensToDistance(short *dist);
__stdcall int MoveIrisWithAv(short*);
__stdcall void PutInNdFilter(void);
__stdcall void PutOutNdFilter(void);
__stdcall short get_nd_value(void);
__stdcall short get_current_nd_value(void);
__stdcall int GetCurrentShutterSpeed(void);
__stdcall int GetCurrentAvValue(void);
__stdcall short GetUsableMinAv(void);
__stdcall short GetUsableMaxAv(void);
__stdcall int GetCurrentTargetDistance(void);
__stdcall int GetPropertyCase(int opt_id, void *buf, int bufsize);
__stdcall int SetPropertyCase(int opt_id, void *buf, int bufsize);
__stdcall short PTM_GetCurrentItem(int id);
__stdcall int IsStrobeChargeCompleted(void);
__stdcall int VbattGet(void);
__stdcall int GetBatteryTemperature(void);
__stdcall int GetCCDTemperature(void);
__stdcall int GetOpticalTemperature(void);
#ifdef CAM_DRYOS_REL
__stdcall int GetAdChValue(int);
#else
__stdcall int GetAdChValue(int*);
#endif
__stdcall void PT_PlaySound(short , void*, int unk);
__stdcall void RefreshPhysicalScreen(int f);
__stdcall void Unmount_FileSystem(void);
__stdcall void Mount_FileSystem(void);
__stdcall void SleepTask(int msec);
__stdcall int CreateTask (const char *name, int prio, int stack_size, void *entry, int parm /*?*/);
__stdcall void ExitTask(void);
__stdcall int taskNameToId(char* taskName); // VxWorks only, task's name first letter must be 't', maximum 10 chars total
__stdcall const char * taskName(int taskID); // VxWorks only for now
__stdcall int taskIdListGet(int *idlist,int max); // VxWorks only for now
__stdcall void taskSuspend(int taskId);
__stdcall void taskResume(int taskId);
__stdcall int errnoOfTaskGet(int tid);

__stdcall int SetEventFlag(int flag, int what);
__stdcall int CheckAnyEventFlag(int flag, int mask, int *res);
__stdcall int GetEventFlagValue(int flag, int *res);

__stdcall int ReceiveMessageQueue(int msgq, int *dst, int unk1 /* probably timeout */);

/* Canon stuff with nonoriginal naming */
__stdcall int GetParameterData(int id, void *buf, int size);
__stdcall int SetParameterData(int id, void *buf, int size);
__stdcall void MakeSDCardBootable(int driveno);
__stdcall void UpdateMBROnFlash(int driveno, int offset, char *str);

/* standard C library */
__stdcall int creat (const char *name, int flags);
__stdcall int open (const char *name, int flags, int mode );
__stdcall int close (int fd);
__stdcall int write (int fd, const void *buffer, int nbytes);
__stdcall int read (int fd, void *buffer, int nbytes);
__stdcall int lseek (int fd, int offset, int whence);
__stdcall int mkdir(const char *dirname);

__stdcall int Open (const char *name, int flags, int mode );
__stdcall int Close (int fd);
__stdcall int Write (int fd, const void *buffer, int nbytes);
__stdcall int Read (int fd, void *buffer, int nbytes);
// alias to lseek
//int Lseek (int fd, int offset, int whence);
__stdcall int Remove(const char *name);

__stdcall FILE * Fopen_Fut(const char *filename, const char *mode);
__stdcall int Fclose_Fut(FILE *f);
__stdcall int Fread_Fut(void *buf, int elsize, int count, FILE *f);
__stdcall int Fwrite_Fut(const void *buf, int elsize, int count, FILE *f);
__stdcall int Fseek_Fut(FILE *f, int offset, int whence);
__stdcall int Fflush_Fut(FILE *f);
__stdcall int Feof_Fut(FILE *f);
__stdcall int Fflush_Fut(FILE *f);
__stdcall char * Fgets_Fut(char *buf, int n, FILE *f);
__stdcall int RenameFile_Fut(const char *oldname, const char *newname);
__stdcall int DeleteFile_Fut(const char *name);
__stdcall int MakeDirectory_Fut(const char *name,int unk);
__stdcall int DeleteDirectory_Fut(const char *name);

__stdcall int isdigit(int c);
__stdcall int isspace(int c);
__stdcall int isalpha(int c);
__stdcall int isupper(int c);
__stdcall int islower(int c);
__stdcall int ispunct(int c);
__stdcall int isxdigit(int c);

__stdcall int strlen(const char *s);
__stdcall int strcmp(const char *s1, const char *s2);
__stdcall int strncmp(const char *s1, const char *s2, int n);
__stdcall char * strchr(const char *s, int c);
__stdcall char * strcpy(char *dest, const char *src);
__stdcall char * strncpy(char *dest, const char *src, int n);
__stdcall char * strcat(char *dest, const char *app);
__stdcall char * strrchr(const char *s, int c);
__stdcall char * strpbrk(const char *s, const char *accept);

__stdcall int strtol(const char *nptr, char **endptr, int base);
__stdcall unsigned strtoul(const char *nptr, char **endptr, int base);
// DRYOS: this function is called by strtol (mode=1) and strtoul (mode=0)
// easier to match with sig finder
__stdcall int strtolx(const char *nptr, char **endptr, int base, int mode);

__stdcall int tolower(int c);
__stdcall int toupper(int c);

__stdcall int vsprintf(char *buf, const char *fmt, __builtin_va_list va_list);

/**
 * No STUBS!
 * You can't use these two directly from THUMB code (core), only from platform.
 */
//int fprintf(FILE *fd, char*buf, ...);
//int printf(char *buf, ...);

__stdcall void * malloc(int size);
__stdcall void free(void *p);
__stdcall void * AllocateUncacheableMemory(int size);
__stdcall void FreeUncacheableMemory(void *p);

__stdcall void * memchr(const void *s, int c, int n);
__stdcall void * memcpy(void *dest, const void *src, int n);
__stdcall void * memset(void *s, int c, int n);
__stdcall int memcmp(const void *s1, const void *s2, int n);

__stdcall void qsort (void * _base, int _nelem, int _size, int (* _cmp)(const void * _e1, const void * _e2));

/* VxWorks */
__stdcall int taskLock(void);
__stdcall int taskUnlock(void);
__stdcall int taskCreateHookAdd (void *createHook);
__stdcall int taskDeleteHookAdd (void *deleteHook);
__stdcall int iosDevAdd(void*,void*,int);
__stdcall int iosDevDelete(void*);
__stdcall int iosDrvInstall(void*,void*,void*,void*,void*,void*,void*);

/* synchronization objects */
__stdcall int TakeSemaphore(int sem, int timeout);
__stdcall void GiveSemaphore(int sem);

/* misc */
__stdcall int kbd_p1_f(void);
__stdcall void kbd_p2_f(void);
__stdcall void kbd_pwr_on(void);
__stdcall void kbd_pwr_off(void);
__stdcall void kbd_read_keys_r2(int *p);

__stdcall void kbd_fetch_data(int *dst);

__stdcall void UniqueLedOn(void *addr, int brightness);
__stdcall void UniqueLedOff(void *addr);
//struct led_control {int led_num; int action; int brightness; int blink_count;};
__stdcall int PostLEDMessage(struct led_control *);
__stdcall int LEDDrive(int led, int action);


__stdcall int LockMainPower(void);
__stdcall int UnlockMainPower(void);
__stdcall void SetAutoShutdownTime(int t);

/*
The following two functions post an event such as button press, switch change, cable connection change.
event:
  A number identifying the event. This number may vary between camera models.
  See levent.c and levent.h for methods to identify events by name.
unk:
  Unknown value, usually 0 in canon code. For jogdial messages, this is number of clicks.
return value:
  Unknown, possibly void.
*/
__stdcall int  PostLogicalEventForNotPowerType(int event, int unk);
__stdcall int  PostLogicalEventToUI(int event, int unk);
/*
Used in the canon code to modify the generation or delivery of events. For example, Canon
mode override code sets 1 on the desired dial position, and zero on all others.
event: as described above for PostLogicalEvent*
state: if 1, the event will be generated/delivered as normal. If 0, the event is disabled/blocked.
*/
__stdcall void SetLogicalEventActive(unsigned event, unsigned state);
/* Somehow related to the above. Normally 0, set to 1 for script mode */
__stdcall void SetScriptMode(unsigned mode);


/* math */
__stdcall int rand(void);
__stdcall void srand(unsigned int seed);

__stdcall double _log(double x);
__stdcall double _log10(double x);
__stdcall double _pow(double x, double y);
__stdcall double _sqrt(double x);

/* time */
__stdcall int utime(const char *file, void *newTimes);
__stdcall unsigned int time(/*time_t*/ unsigned int *timer);
__stdcall void * localtime(const /*time_t*/ unsigned int * tod);
__stdcall void * LocalTime(const /*time_t*/ unsigned int * tod, void * t_m); // DRYOS
__stdcall int strftime(char *s, unsigned int maxsize, const char *format, const /*struct tm*/ void *timp);
__stdcall /*time_t*/ int mktime(/*struct tm*/ void *timp); // VXWORKS
__stdcall /*time_t*/ int mktime_ext(void *tim_extp); // DRYOS, doesn't take a struct tm *
__stdcall int SetDate(void *setdate_p); // expects ptr to year, month, day, hour, min, sec, not compatible with tm
                                      // appears to return non-DST adjusted time

#if CAM_DRYOS_REL >= 39
__stdcall int SetFileTimeStamp(const char *file_path, int time1, int time2);
__stdcall int SetFileAttributes(const char *fn, int attr);
#else
__stdcall int SetFileTimeStamp(int fd, int time1, int time2);
__stdcall void SetFileAttributes(int fd, int attr);
#endif

/* file */
__stdcall int   stat(const char *name, __stat *pStat);
__stdcall unsigned int GetDrive_ClusterSize(int drive);
__stdcall unsigned int GetDrive_TotalClusters(int drive);
__stdcall unsigned int GetDrive_FreeClusters(int drive);
__stdcall int WriteSDCard(unsigned int drive, unsigned int start_sect, unsigned int num_sect, void *buf);

__stdcall void UnsetZoomForMovie(void);
__stdcall void TurnOffMic(void);
__stdcall void TurnOnMic(void);

__stdcall void MakeAFScan(int*, int);
__stdcall void ExpCtrlTool_StartContiAE(int, int);
__stdcall void ExpCtrlTool_StopContiAE(int, int);

__stdcall int some_flag_for_af_scan;
__stdcall int parameter_for_af_scan;
__stdcall short SetAE_ShutterSpeed(short* tv);

__stdcall void EnterToCompensationEVF(void);
__stdcall void ExitFromCompensationEVF(void);

__stdcall void TurnOnBackLight(void);
__stdcall void TurnOffBackLight(void);
__stdcall void TurnOnDisplay(void);
__stdcall void TurnOffDisplay(void);

__stdcall void DoAELock(void);
__stdcall void UnlockAE(void);
__stdcall void DoAFLock(void);
__stdcall void UnlockAF(void);
__stdcall void MFOn(void);
__stdcall void MFOff(void);
__stdcall void PT_MFOn(void);
__stdcall void PT_MFOff(void);
__stdcall void SS_MFOn(void);
__stdcall void SS_MFOff(void);

__stdcall int EngDrvRead(int gpio_reg);

__stdcall int apex2us(int);

__stdcall void ScreenLock(void);
__stdcall void SetCurrentCaptureModeType(void);
__stdcall unsigned ExecuteEventProcedure(const char *name, ...);
// known in CHDK as RefreshPhysicalScreen
//void ScreenUnLock(void);

// 7 calls functions and sets some MMIOs, but doesn't disable caches and actually restart
// 3 skips one function call on some cameras, but does restart
__stdcall void Restart(unsigned option);

// boot an fir/fi2 file
__stdcall void reboot_fw_update(const char* bootfile);

// PTP
__stdcall int add_ptp_handler(int opcode, ptp_handler handler, int unk);
__stdcall void set_control_event(int);
__stdcall void PB2Rec(void);
__stdcall void Rec2PB(void);
__stdcall int get_ptp_buf_size(int slot);
__stdcall char * get_ptp_file_buf(void);

// dryos + some vxworks only takes 3 params in reality
// on some vxworks the function that is easy to match with sig finder takes an additional param,
// set to zero in the real AllocateExMem
// versions that don't expect a 4th param will just ignore it
__stdcall void * exmem_alloc(unsigned int pool_id,unsigned int size,int unk,int unk2);

// exmem
__stdcall void * exmem_ualloc(unsigned int type, unsigned int size, void *allocinf);
__stdcall void exmem_ufree(unsigned int type);

// vxworks only
// used on a few cameras that don't have memPartInfoGet, see CAM_NO_MEMPARTINFO
__stdcall int memPartFindMax(int mempart_id);
__stdcall int memPartInfoGet(int mempart_id,int *info);

__stdcall void GPS_UpdateData(void);

// gathered from places other than lowlevel
// generic/wrappers.c
__stdcall void PT_MoveDigitalZoomToWide(void);
__stdcall void MoveOpticalZoomAt(long pt,int speed);
__stdcall int closedir(void *d);
__stdcall int get_fstype(int);
__stdcall void *OpenFastDir(const char* name);
__stdcall int ReadFastDir(void *d, void* dd);
__stdcall void *opendir(const char* name);
__stdcall void *readdir(void *d);
__stdcall void GetMemInfo(int*);
__stdcall int SetHPTimerAfterNow(int delay, int(*good_cb)(int, int), int(*bad_cb)(int, int), int );
__stdcall int CancelHPTimer(int);
__stdcall void EnableHDMIPower(void);
__stdcall void DisableISDriveError(void);
#if CAM_3ARG_DebugAssert
__stdcall void DebugAssert(int x, char *file, int line);
// some cams with 3 arg form also have 2 arg
__stdcall void DebugAssert2(char *file, int line);
#else
__stdcall void DebugAssert(char *file, int line);
#endif
__stdcall int CreateBinarySemaphore(char *name, int v);
__stdcall void SetVideoOutType(int vt);
__stdcall int GetVideoOutType(void);
__stdcall void LogCameraEvent(int level, const char *fmt, ...);


// common in platform lib.c
__stdcall void transfer_src_overlay(int which);
__stdcall int GetVRAMHPixelsSize(void);
__stdcall int GetVRAMVPixelsSize(void);

// kbd.c
__stdcall void GetKbdState(int *phsw);
__stdcall int get_dial_hw_position(int dial);

// platform / shooting.c
__stdcall void GetImageFolder(char * out,int filecount,int flags,int time);

// other (sigs etc) - many not tested, may not be 100% correct
__stdcall void * wrapped_malloc(int size);
__stdcall void * malloc_strictly(int size);
__stdcall int TakeSemaphoreStrictly(int sem, int timeout, const char *file, int line);
__stdcall int DeleteSemaphore(int sem);
__stdcall int CreateTaskStrictly (const char *name, int prio, int stack_size,int (*entry)(), int parm /*?*/);
__stdcall int CreateEventFlag(const char *name/*?*/, int v);
__stdcall int CreateEventFlagStrictly(const char *name/*?*/, int v);
__stdcall int CreateBinarySemaphoreStrictly(const char *name, int v);
__stdcall int CreateCountingSemaphore(const char *name, int v);
__stdcall int CreateCountingSemaphoreStrictly(const char *name, int v);
__stdcall int createsemaphore_low(int v,int type, const char *name);
__stdcall int DeleteMessageQueue(int msgq);
__stdcall void dry_memcpy(void *dst, void *src, int n);
__stdcall void bzero(void *p, int n);
__stdcall void memset32(void *p, int n, int v);
__stdcall char *sprintf_FW(char *p, const char *fmt,...);
__stdcall int takesemaphore_low(int sem, int *t);
__stdcall int givesemaphore_low(int sem);
__stdcall void DisableDispatch(void);
__stdcall void EnableDispatch(void);
__stdcall int GetSemaphoreValue(int sem, int *p);
__stdcall int ClearEventFlag(int flag, int what);
__stdcall int TryTakeSemaphore(int sem);
__stdcall int WaitForAnyEventFlag(int flag, int what, int timeout);
__stdcall int ExportToEventProcedure_FW(const char *name, int (*func)());
#ifdef CAM_DRYOS_REL
// vx cams may identify 2 arg version as RegisterEventProcedure
__stdcall int RegisterEventProcedure(const char *name, int (*func)(), int (*func2)());
#endif
__stdcall int RegisterEventProcedure_FW(const char *name, int (*func)());
__stdcall int RegisterEventProcedure_alt1(const char *name, int (*func)());
__stdcall int RegisterEventProcedure_alt2(const char *name, int (*func)());
__stdcall int RegisterEventProcTable(const eventproc_table_entry *defs);
__stdcall int RegisterEventProcTable_alt(const eventproc_table_entry *defs);
__stdcall unsigned ExecuteEventProcedure_FW(const char *name,...);
__stdcall int UnRegisterEventProcedure(const char *name);
__stdcall int CreateTask_low(int (*entry)(),int parm, int unk1, int stack_size, int prio, int unk2, const char *name);
__stdcall int DeleteEventFlag(int flag);
__stdcall int CheckAllEventFlag(int flag, int mask, int *res);
__stdcall int WaitForAllEventFlag(int flag, int what, int timeout);
__stdcall int RegisterInterruptHandler(const char *name, int int_num, int (*int_handler)(),int unk);
__stdcall int CreateMessageQueue(const char *name/*?*/, int unk/*size? Flags?*/);
__stdcall int CreateMessageQueueStrictly(const char *name/*?*/, int unk/*size? Flags?*/);
__stdcall int TryReceiveMessageQueue(int msgq, int *dst);
__stdcall int PostMessageQueue(int msgq,int val,int timeout);
__stdcall int TryPostMessageQueue(int msgq,int val);
__stdcall int GetNumberOfPostedMessages(int msgq,int *res);

// lower level file IO functions for the *_Fut system
__stdcall FILE * fopen_low(const char *filename, const char *mode);
__stdcall int fclose_low(FILE *f);
__stdcall int fread_low(void *buf, int elsize, int count, FILE *f);
__stdcall int fwrite_low(const void *buf, int elsize, int count, FILE *f);
__stdcall int fseek_low(FILE *f, int offset, int whence);
__stdcall int fflush_low(FILE *f);
__stdcall int feof_low(FILE *f);
__stdcall int fflush_low(FILE *f);
__stdcall char * fgets_low(char *buf, int n, FILE *f);
// called at the start of most fut functions, checks path and takes fileio_semaphore
__stdcall int fut_prepare(const char *name, int unk);
// called at the end of most fut functions, gives fileio_semaphore
__stdcall int fut_finish(int unk);
// even lower level flush, called by _Fut functions, does actual Write
__stdcall int fut_flush(FILE *f);

__stdcall void set_assert_handler(void (*assert_handler)());
__stdcall void set_exception_handler(void (*exception_handler)());
__stdcall void set_panic_handler(void (*panic_handler)());

__stdcall int *get_self_task_errno_pointer(void);
__stdcall int get_self_task_id(void);
__stdcall int get_task_properties(int task_id, void *task_props);
__stdcall void dry_error_printf(const char *fmt,...);
__stdcall int CreateTask_alt(const char *name, int prio, int stack_size, void *entry, int parm /*?*/,int core /*?*/);
__stdcall int CreateTaskStrictly_alt(const char *name, int prio, int stack_size,int (*entry)(), int parm /*?*/,int core /*?*/);

__stdcall int is_movie_recording(void);

// dryos underlying function, return value is status not time
__stdcall int _GetSystemTime(int *t);
__stdcall unsigned GetSRAndDisableInterrupt(void); //note this actually only returns interrupt mask bit
__stdcall void SetSR(unsigned sr_int_bit); // and this only sets it

__stdcall int cache_flush_range(int is_data, void *addr, unsigned size); // dry <=52 on pre-digic 6
__stdcall void dcache_flush_range(void *addr, unsigned size); // dry >52, or d6/d7
__stdcall void dcache_clean_range(void *addr, unsigned size); // dry >52, or d6/d7
__stdcall void icache_flush_range(void *addr, unsigned size); // dry >52, or d6/d7
__stdcall void dcache_clean_flush_and_disable(void);
__stdcall void dcache_flush_and_enable(void);
__stdcall void data_synchronization_barrier(void);

__stdcall void *heap_alloc(void *heap, unsigned size); // used by malloc and other heaps
__stdcall void heap_free(void *heap, void *p);

__stdcall mzrm_msg * mzrm_createmsg(mzrm_context *ctx, int unk, int msg_type, int payload_size);
__stdcall int mzrm_sendmsg(mzrm_context *ctx, mzrm_msg *msg);
__stdcall void GraphicSystemCoreFinish(void);
__stdcall int GraphicSystemCoreFinish_helper(void);
__stdcall void zicokick_copy(void *dst, void *src, unsigned size);
__stdcall void zicokick_start(void);

__stdcall void *umalloc_strictly(unsigned size);
__stdcall void dry_memset(void *dst, unsigned n, int c);
__stdcall void dry_memzero(void *dst, unsigned n);
// like dry_memcpy but additional logic for small n and unaligned
__stdcall void dry_memcpy_bytes(void *dst, void *src, unsigned n);
// handles overlap(?)
__stdcall void dry_memmove_bytes(void *dst, void *src, unsigned n);

__stdcall int GetRomID(void *adr, int unk);

#endif

