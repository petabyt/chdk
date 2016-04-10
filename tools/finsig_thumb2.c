#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#include <inttypes.h>

#include <capstone.h>


#include "stubs_load.h"
#include "firmware_load_ng.h"

// arbitrary standardized constant for search "near" a string ref etc
// could base on ADR etc reach
#define SEARCH_NEAR_REF_RANGE 1024

/* copied from finsig_dryos.c */
char    out_buf[32*1024] = "";
int     out_len = 0;
char    hdr_buf[32*1024] = "";
int     hdr_len = 0;
int     out_hdr = 1;

FILE *out_fp;

void bprintf(char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);

    if (out_hdr)
        hdr_len += vsprintf(hdr_buf+hdr_len,fmt,argp);
    else
        out_len += vsprintf(out_buf+out_len,fmt,argp);

    va_end(argp);
}

void add_blankline()
{
    if (strcmp(hdr_buf+hdr_len-2,"\n\n") != 0)
    {
        hdr_buf[hdr_len++] = '\n';
        hdr_buf[hdr_len] = 0;
    }
}

void write_output()
{
    add_blankline();
    if (out_fp)
    {
        fprintf(out_fp,"%s",hdr_buf);
        fprintf(out_fp,"%s",out_buf);
    }
}

// Master list of functions / addresses to find

#define DONT_EXPORT    0x01
#define OPTIONAL       0x02
#define UNUSED         0x04
#define BAD_MATCH      0x08
#define EV_MATCH       0x10
#define LIST_ALWAYS    0x20
// force an arm veneer (NHSTUB2)
#define ARM_STUB       0x80

typedef struct {
    char        *name;
    int         flags;
    uint32_t    val;
} sig_entry_t;

int next_sig_entry = 0;

#define MAX_SIG_ENTRY  5000

sig_entry_t  sig_names[MAX_SIG_ENTRY] =
{
    // Order here currently has no effect on search order, but mostly copied from finsig_dryos which did
    { "ExportToEventProcedure_FW", UNUSED|DONT_EXPORT },
    { "RegisterEventProcedure", UNUSED|DONT_EXPORT },
    { "RegisterEventProcedure_alt1", UNUSED|DONT_EXPORT },
    { "RegisterEventProcedure_alt2", UNUSED|DONT_EXPORT },
    { "RegisterEventProcTable", UNUSED|DONT_EXPORT },
    { "UnRegisterEventProcTable", UNUSED|DONT_EXPORT },
    { "UnRegisterEventProcedure", UNUSED|DONT_EXPORT },
    { "PrepareDirectory_1", UNUSED|DONT_EXPORT },
    { "PrepareDirectory_x", UNUSED|DONT_EXPORT },
    { "PrepareDirectory_0", UNUSED|DONT_EXPORT },
    { "CreateTaskStrictly", UNUSED|DONT_EXPORT },
    { "CreateJumptable", UNUSED },
    { "_uartr_req", UNUSED },
    { "StartRecModeMenu", UNUSED },
    { "LogCameraEvent", UNUSED|DONT_EXPORT },
    { "getImageDirName", UNUSED|DONT_EXPORT },

    { "AllocateMemory", UNUSED|LIST_ALWAYS },
    { "AllocateUncacheableMemory" },
    { "Close" },
    { "CreateBinarySemaphore", UNUSED|LIST_ALWAYS },
    { "CreateCountingSemaphore", UNUSED|LIST_ALWAYS },
    { "CreateTask" },
    { "DebugAssert", OPTIONAL|LIST_ALWAYS },
    { "DeleteDirectory_Fut" },
    { "DeleteFile_Fut" },
    { "DeleteSemaphore", UNUSED|LIST_ALWAYS },
    { "DoAELock" },
    { "DoAFLock" },
    { "EnterToCompensationEVF" },
    { "ExecuteEventProcedure", ARM_STUB },
    { "ExitFromCompensationEVF" },
    { "ExitTask" },
    { "ExpCtrlTool_StartContiAE" },
    { "ExpCtrlTool_StopContiAE" },
    { "Fclose_Fut" },
    { "Feof_Fut" },
    { "Fflush_Fut" },
    { "Fgets_Fut" },
    { "Fopen_Fut" },
    { "Fread_Fut" },
    { "FreeMemory", UNUSED|LIST_ALWAYS },
    { "FreeUncacheableMemory" },
    { "Fseek_Fut" },
    { "Fwrite_Fut" },
    { "GetBatteryTemperature" },
    { "GetCCDTemperature" },
    { "GetCurrentAvValue" },
    { "GetDrive_ClusterSize" },
    { "GetDrive_FreeClusters" },
    { "GetDrive_TotalClusters" },
    { "GetFocusLensSubjectDistance" },
    { "GetFocusLensSubjectDistanceFromLens" },
    { "GetImageFolder", OPTIONAL },
    { "GetKbdState" },
    { "GetMemInfo" },
    { "GetOpticalTemperature" },
    { "GetParameterData" },
    { "GetPropertyCase" },
    { "GetSystemTime" },
    { "GetVRAMHPixelsSize" },
    { "GetVRAMVPixelsSize" },
    { "GetZoomLensCurrentPoint" },
    { "GetZoomLensCurrentPosition" },
    { "GiveSemaphore", OPTIONAL|LIST_ALWAYS },
    { "IsStrobeChargeCompleted" },
    { "LEDDrive", OPTIONAL },
    { "LocalTime" },
    { "LockMainPower" },
    { "Lseek", UNUSED|LIST_ALWAYS },
    { "MakeDirectory_Fut" },
    { "MakeSDCardBootable", OPTIONAL },
    { "MoveFocusLensToDistance" },
    { "MoveIrisWithAv", OPTIONAL },
    { "MoveZoomLensWithPoint" },
    { "NewTaskShell", UNUSED },
    { "Open" },
    { "PB2Rec" },
    { "PT_MoveDigitalZoomToWide", OPTIONAL },
    { "PT_MoveOpticalZoomAt", OPTIONAL },
    { "PT_PlaySound" },
    { "PostLogicalEventForNotPowerType" },
    { "PostLogicalEventToUI" },
    { "PutInNdFilter", OPTIONAL },
    { "PutOutNdFilter", OPTIONAL },
    { "Read" },
    { "ReadFastDir" },
    { "Rec2PB" },
    { "RefreshPhysicalScreen" },
    { "Remove", OPTIONAL|UNUSED },
    { "RenameFile_Fut" },
    { "Restart" },
    { "ScreenLock" },
    { "ScreenUnlock" },
    { "SetAE_ShutterSpeed" },
    { "SetAutoShutdownTime" },
    { "SetCurrentCaptureModeType" },
    { "SetFileAttributes" },
    { "SetFileTimeStamp" },
    { "SetLogicalEventActive" },
    { "SetParameterData" },
    { "SetPropertyCase" },
    { "SetScriptMode" },
    { "SleepTask" },
    { "TakeSemaphore" },
    { "TurnOffBackLight" },
    { "TurnOnBackLight" },
    { "TurnOnDisplay" },
    { "TurnOffDisplay" },
    { "UIFS_WriteFirmInfoToFile" },
    { "UnlockAE" },
    { "UnlockAF" },
    { "UnlockMainPower" },
    { "UnsetZoomForMovie", OPTIONAL },
//    { "UpdateMBROnFlash" },
    { "VbattGet" },
    { "Write" },
    { "WriteSDCard" },

    { "_log" },
    { "_log10" },
    { "_pow" },
    { "_sqrt" },
    { "add_ptp_handler" },
    { "apex2us" },
    { "close" },
    { "displaybusyonscreen", OPTIONAL },
    { "err_init_task", OPTIONAL },
    { "exmem_alloc" },
    { "exmem_free", OPTIONAL|LIST_ALWAYS },
    { "free" },

    { "kbd_p1_f" },
    { "kbd_p1_f_cont" },
    { "kbd_p2_f" },
    { "kbd_read_keys" },
    { "kbd_read_keys_r2" },

    { "kbd_pwr_off", OPTIONAL },
    { "kbd_pwr_on", OPTIONAL },
    { "lseek" },
    { "malloc" },
    { "memcmp" },
    { "memcpy" },
    { "memset" },
// identical to MakeDirectory_Fut for recent cams
//    { "mkdir" },
    { "mktime_ext" },
    { "open" },
    { "OpenFastDir" },
    { "closedir" },
    { "get_fstype", OPTIONAL|LIST_ALWAYS },
    { "qsort" },
    { "rand" },
    { "read", UNUSED|OPTIONAL },
    { "realloc", OPTIONAL|LIST_ALWAYS },
    { "reboot_fw_update" },
    { "set_control_event" },
    { "srand" },
    { "stat" },
    { "strcat" },
    { "strchr" },
    { "strcmp" },
    { "strcpy" },
    { "strftime" },
    { "strlen" },
    { "strncmp" },
    { "strncpy" },
    { "strrchr" },
    { "strtol" },
    { "strtolx" },

    { "task_CaptSeq" },
    { "task_DvlpSeqTask", OPTIONAL },
    { "task_ExpDrv" },
    { "task_FileWrite", OPTIONAL },
    { "task_InitFileModules" },
    { "task_MovieRecord" },
    { "task_PhySw", OPTIONAL },
    { "task_RotaryEncoder", OPTIONAL },
    { "task_TouchPanel", OPTIONAL },

    { "hook_CreateTask" },

    { "time" },
    { "vsprintf" },
    { "write", UNUSED|OPTIONAL },
    { "undisplaybusyonscreen", OPTIONAL },

    { "EngDrvIn", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "EngDrvOut", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "EngDrvRead" },
    { "EngDrvBits", OPTIONAL|UNUSED|LIST_ALWAYS },

    { "PTM_GetCurrentItem" },
    { "PTM_SetCurrentItem", UNUSED|LIST_ALWAYS },
    { "PTM_NextItem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PTM_PrevItem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PTM_SetPropertyEnable", OPTIONAL|UNUSED|LIST_ALWAYS },

    { "DisableISDriveError", OPTIONAL },

    // OS functions, mostly to aid firmware analysis. Order is important!
    { "_GetSystemTime", OPTIONAL|UNUSED|LIST_ALWAYS }, // only for locating timer functions
    { "SetTimerAfter", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "SetTimerWhen", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CancelTimer", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CancelHPTimer" },
    { "SetHPTimerAfterTimeout", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "SetHPTimerAfterNow" },
    { "CreateTaskStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetSemaphoreValue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TryTakeSemaphore", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateMessageQueueStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateEventFlagStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateBinarySemaphoreStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateCountingSemaphoreStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateRecursiveLockStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TakeSemaphoreStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "ReceiveMessageQueueStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "PostMessageQueueStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },    // r23+
    { "WaitForAnyEventFlagStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "WaitForAllEventFlagStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "AcquireRecursiveLockStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "DeleteMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PostMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "ReceiveMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TryReceiveMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TryPostMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetNumberOfPostedMessages", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "DeleteRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "AcquireRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "ReleaseRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "WaitForAnyEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "WaitForAllEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "ClearEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "SetEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetEventFlagValue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "DeleteEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CheckAnyEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CheckAllEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "RegisterInterruptHandler", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "UnregisterInterruptHandler", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetSRAndDisableInterrupt", OPTIONAL|UNUSED|LIST_ALWAYS }, // disables IRQ, returns a value
    { "SetSR", OPTIONAL|UNUSED|LIST_ALWAYS }, // enables IRQ, puts back value returned by GetSR
    { "EnableInterrupt", OPTIONAL|UNUSED|LIST_ALWAYS }, // enables IRQ
    { "_divmod_signed_int", OPTIONAL|UNUSED|LIST_ALWAYS}, // division for signed integers, remainder is returned in r1
    { "_divmod_unsigned_int", OPTIONAL|UNUSED|LIST_ALWAYS}, // division for unsigned integers, remainder is returned in r1
    { "_dflt", OPTIONAL|UNUSED|LIST_ALWAYS}, // int -> double
    { "_dfltu", OPTIONAL|UNUSED|LIST_ALWAYS}, // uint -> double
    { "_dfix", OPTIONAL|UNUSED|LIST_ALWAYS}, // double -> int
    { "_dfixu", OPTIONAL|UNUSED|LIST_ALWAYS}, // double -> uint
    { "_dmul", OPTIONAL|UNUSED|LIST_ALWAYS}, // double precision float multiplication
    { "_ddiv", OPTIONAL|UNUSED|LIST_ALWAYS}, // double precision float division
    { "_dadd", OPTIONAL|UNUSED|LIST_ALWAYS}, // addition for doubles
    { "_dsub", OPTIONAL|UNUSED|LIST_ALWAYS}, // subtraction for doubles
    { "_drsb", OPTIONAL|UNUSED|LIST_ALWAYS}, // reverse subtraction for doubles (?)
    { "_dcmp", OPTIONAL|UNUSED|LIST_ALWAYS}, // comparison of 2 doubles, only updates condition flags
    { "_dcmp_reverse", OPTIONAL|UNUSED|LIST_ALWAYS}, // like _dcmp, but operands in reverse order, only updates condition flags
    { "_safe_sqrt", OPTIONAL|UNUSED|LIST_ALWAYS}, // only calls _sqrt for numbers >= 0
    { "_scalbn", OPTIONAL|UNUSED|LIST_ALWAYS}, // double scalbn (double x, long exp), returns x * FLT_RADIX ** exp
    { "_fflt", OPTIONAL|UNUSED|LIST_ALWAYS}, // int -> float
    { "_ffltu", OPTIONAL|UNUSED|LIST_ALWAYS}, // uint -> float
    { "_ffix", OPTIONAL|UNUSED|LIST_ALWAYS}, // float -> int
    { "_ffixu", OPTIONAL|UNUSED|LIST_ALWAYS}, // float -> uint
    { "_fmul", OPTIONAL|UNUSED|LIST_ALWAYS}, // single precision float multiplication
    { "_fdiv", OPTIONAL|UNUSED|LIST_ALWAYS}, // single precision float division
    { "_f2d", OPTIONAL|UNUSED|LIST_ALWAYS}, // float -> double
    { "DisplayBusyOnScreen", OPTIONAL|UNUSED|LIST_ALWAYS}, // displays full screen "busy" message
    { "UndisplayBusyOnScreen", OPTIONAL|UNUSED|LIST_ALWAYS},
    { "CreateDialogBox", OPTIONAL|UNUSED|LIST_ALWAYS},
    { "DisplayDialogBox", OPTIONAL|UNUSED|LIST_ALWAYS},
    { "add_ui_to_dialog", OPTIONAL|UNUSED|LIST_ALWAYS}, // name made up, assigns resources to a dialog
    { "get_string_by_id", OPTIONAL|UNUSED|LIST_ALWAYS}, // name made up, retrieves a localised or unlocalised string by its ID
    { "malloc_strictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // name made up
    { "GetCurrentMachineTime", OPTIONAL|UNUSED|LIST_ALWAYS }, // reads usec counter, name from ixus30
    { "HwOcReadICAPCounter", OPTIONAL|UNUSED|LIST_ALWAYS }, // reads usec counter, name from ixus30

    // Other stuff needed for finding misc variables - don't export to stubs_entry.S
    { "GetSDProtect", UNUSED },
    { "DispCon_ShowBitmapColorBar", UNUSED },
    { "ResetZoomLens", OPTIONAL|UNUSED },
    { "ResetFocusLens", OPTIONAL|UNUSED },
    { "NR_GetDarkSubType", OPTIONAL|UNUSED },
    { "NR_SetDarkSubType", OPTIONAL|UNUSED },
    { "SavePaletteData", OPTIONAL|UNUSED },
    { "GUISrv_StartGUISystem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "get_resource_pointer", OPTIONAL|UNUSED|LIST_ALWAYS }, // name made up, gets a pointer to a certain resource (font, dialog, icon)
    { "CalcLog10", OPTIONAL|UNUSED|LIST_ALWAYS }, // helper
    { "CalcSqrt", OPTIONAL|UNUSED }, // helper
    { "bzero", OPTIONAL|UNUSED }, // helper
    { "dry_memcpy", OPTIONAL|UNUSED }, // helper, memcpy-like function in dryos kernel code
    { "get_playrec_mode", OPTIONAL|UNUSED }, // helper, made up name
    { "DebugAssert2", OPTIONAL|UNUSED }, // helper, made up name, two arg form of DebugAssert
    { "get_canon_mode_list", OPTIONAL|UNUSED }, // helper, made up name
    { "taskcreate_LowConsole", OPTIONAL|UNUSED }, // helper, made up name

    { "MFOn", OPTIONAL },
    { "MFOff", OPTIONAL },
    { "PT_MFOn", OPTIONAL },
    { "PT_MFOff", OPTIONAL },
    { "SS_MFOn", OPTIONAL },
    { "SS_MFOff", OPTIONAL },

    { "GetAdChValue", OPTIONAL },

    {0,0,0},
};

// for values that don't get a DEF etc
#define MISC_VAL_NO_STUB    1
// DEF_CONST instead of DEF
#define MISC_VAL_DEF_CONST  2
// variables and constants
typedef struct {
    char        *name;
    int         flags; // not used yet, will want for DEF_CONST, maybe non-stubs values
    uint32_t    val;
    // informational values
    uint32_t    base; // if stub is found as ptr + offset, record
    uint32_t    offset;
    uint32_t    ref_adr; // code address near where value found (TODO may want list)
} misc_val_t;

misc_val_t misc_vals[]={
    // stubs_min variables / constants
    { "ctypes",             },
    { "physw_run",          },
    { "physw_sleep_delay",  },
    { "physw_status",       },
    { "fileio_semaphore",   },
    { "levent_table",       },
    { "FlashParamsTable",   },
    { "playrec_mode",       },
    { "jpeg_count_str",     },
    { "zoom_busy",          },
    { "focus_busy",         },
    { "CAM_UNCACHED_BIT",   MISC_VAL_NO_STUB},
    { "physw_event_table",  MISC_VAL_NO_STUB},
    { "uiprop_count",       MISC_VAL_DEF_CONST},
    { "canon_mode_list",    MISC_VAL_NO_STUB},
    { "ARAM_HEAP_START",    MISC_VAL_NO_STUB},
    { "ARAM_HEAP_SIZE",     MISC_VAL_NO_STUB},
    {0,0,0},
};

misc_val_t *get_misc_val(const char *name)
{
    misc_val_t *p=misc_vals;
    while(p->name) {
        if(strcmp(name,p->name) == 0) {
            return p;
        }
        p++;
    }
    return NULL;
}

// get value of misc val, if set. Name :<
uint32_t get_misc_val_value(const char *name)
{
    misc_val_t *p=get_misc_val(name);
    if(!p) {
        printf("get_misc_val_value: invalid name %s\n",name);
        return 0;
    }
    return p->val;
}
void save_misc_val(const char *name, uint32_t base, uint32_t offset, uint32_t ref_adr)
{
    misc_val_t *p=get_misc_val(name);
    if(!p) {
        printf("save_misc_val: invalid name %s\n",name);
        return;
    }
    p->val = base + offset;
    p->base = base;
    p->offset = offset;
    p->ref_adr = ref_adr;
}

// Return the array index of a named function in the array above
#if 0
int find_saved_sig_index(const char *name)
{
    int i;
    for (i=0; sig_names[i].name != 0; i++)
    {
        if (strcmp(name,sig_names[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}
#endif

sig_entry_t * find_saved_sig(const char *name)
{
    int i;
    for (i=0; sig_names[i].name != 0; i++)
    {
        if (strcmp(name,sig_names[i].name) == 0)
        {
            return &sig_names[i];
        }
    }
    return NULL;
}

// return value of saved sig, or 0 if not found / doesn't exist
uint32_t get_saved_sig_val(const char *name)
{
    sig_entry_t *sig=find_saved_sig(name);
    if(!sig) {
        // printf("get_saved_sig_val: missing %s\n",name);
        return 0;
    }
    return sig->val;
}

// unused for now
// Return the array index of of function with given address
#if 0
int find_saved_sig_index_by_adr(uint32_t adr)
{
    if(!adr) {
        return  -1;
    }
    int i;
    for (i=0; sig_names[i].name != 0; i++)
    {
        if (sig_names[i].val == adr)
        {
            return i;
        }
    }
    return -1;
}
#endif
#if 0
sig_entry_t* find_saved_sig_by_val(uint32_t val)
{
    if(!val) {
        return NULL;
    }
    int i;
    for (i=0; sig_names[i].name != 0; i++)
    {
        if (sig_names[i].val == val)
        {
            return &sig_names[i];
        }
    }
    return NULL;
}
#endif

// Save the address value found for a function in the above array
void save_sig(const char *name, uint32_t val)
{
    sig_entry_t *sig = find_saved_sig(name);
    if (!sig)
    {
        printf("save_sig: refusing to save unknown name %s\n",name);
        return;
    }
    if(sig->val && sig->val != val) {
        printf("save_sig: duplicate name %s existing 0x%08x != new 0x%08x\n",name,sig->val,val);
    }
    sig->val = val;
}

void add_func_name(char *n, uint32_t eadr, char *suffix)
{
    int k;

    char *s = n;
    if (suffix != 0)
    {
        s = malloc(strlen(n) + strlen(suffix) + 1);
        sprintf(s, "%s%s", n, suffix);
    }

    for (k=0; sig_names[k].name != 0; k++)
    {
        if (strcmp(sig_names[k].name, s) == 0)
        {
            if (sig_names[k].val == 0)             // same name, no address
            {
                sig_names[k].val = eadr;
                sig_names[k].flags |= EV_MATCH;
                return;
            }
            else if (sig_names[k].val == eadr)     // same name, same address
            {
                return;
            }
            else // same name, different address
            {
                printf("add_func_name: duplicate name %s existing 0x%08x != new 0x%08x\n",s, sig_names[k].val, eadr);
            }
        }
    }

    sig_names[next_sig_entry].name = s;
    sig_names[next_sig_entry].flags = OPTIONAL|UNUSED;
    sig_names[next_sig_entry].val = eadr;
    next_sig_entry++;
    sig_names[next_sig_entry].name = 0;
}

// save sig, with up to one level veneer added as j_...
int save_sig_with_j(firmware *fw, char *name, uint32_t adr)
{
    if(!adr) {
        printf("save_sig_with_j: %s null adr\n",name);
        return 0;
    }
    // attempt to disassemble target
    if(!fw_disasm_iter_single(fw,adr)) {
        printf("save_sig_with_j: %s disassembly failed at 0x%08x\n",name,adr);
        return 0;
    }
    // handle functions that immediately jump
    // only one level of jump for now, doesn't check for conditionals, but first insn shouldn't be conditional
    //uint32_t b_adr=B_target(fw,fw->is->insn);
    uint32_t b_adr=get_direct_jump_target(fw,fw->is);
    if(b_adr) {
        char *buf=malloc(strlen(name)+6);
        sprintf(buf,"j_%s",name);
        add_func_name(buf,adr,NULL); // this is the orignal named address
//        adr=b_adr | fw->is->thumb; // thumb bit from iter state
        adr=b_adr; // thumb bit already handled by get_direct...
    }
    save_sig(name,adr);
    return 1;
}

// find next call to func named "name" or j_name, up to max_offset form the current is address
// TODO should have a way of dealing with more than one veneer
// TODO max_offset is in bytes, unlike insn search functions that use insn counts
int find_next_sig_call(firmware *fw, iter_state_t *is, uint32_t max_offset, const char *name)
{
    uint32_t adr=get_saved_sig_val(name);

    if(!adr) {
        printf("find_next_sig_call: missing %s\n",name);
        return 0;
    }

    search_calls_multi_data_t match_fns[3];

    match_fns[0].adr=adr;
    match_fns[0].fn=search_calls_multi_end;
    char veneer[128];
    sprintf(veneer,"j_%s",name);
    adr=get_saved_sig_val(veneer);
    if(!adr) {
        match_fns[1].adr=0;
    } else {
        match_fns[1].adr=adr;
        match_fns[1].fn=search_calls_multi_end;
        match_fns[2].adr=0;
    }
    return fw_search_insn(fw,is,search_disasm_calls_multi,0,match_fns,is->adr + max_offset);
}
// is the insn pointed to by is a call to "name" or one of it's veneers?
// not inefficient, should not be used for large searches
int is_sig_call(firmware *fw, iter_state_t *is, const char *name)
{
    uint32_t adr=get_branch_call_insn_target(fw,is);
    // not a call at all
    // TODO could check if unknown veneer
    if(!adr) {
        return 0;
    }
    uint32_t sig_adr=get_saved_sig_val(name);
    if(!sig_adr) {
        printf("is_sig_call: missing %s\n",name);
        return 0;
    }
    if(adr == sig_adr) {
        return 1;
    }
    char veneer[128];
    sprintf(veneer,"j_%s",name);
    sig_adr=get_saved_sig_val(veneer);
    if(!sig_adr) {
        return 0;
    }
    return (adr == sig_adr);
}

typedef struct sig_rule_s sig_rule_t;
typedef int (*sig_match_fn)(firmware *fw, iter_state_t *is, sig_rule_t *rule);
// signature matching structure
struct sig_rule_s {
    sig_match_fn    match_fn;       // function to locate function
    char        *name;              // function name used in CHDK
    char        *ref_name;          // event / other name to match in the firmware
    int         param;              // function specific param/offset
    int         dryos_min;          // minimum dryos rel (0 = any)
    int         dryos_max;          // max dryos rel to apply this sig to (0 = any)
    // DryOS version specific params / offsets - not used yet
    /*
    int         dryos52_param; // ***** UPDATE for new DryOS version *****
    int         dryos54_param;
    int         dryos55_param;
    int         dryos57_param;
    int         dryos58_param;
    */
};

// Get DryOS version specific param
/*
int dryos_param(firmware *fw, sig_rule_t *sig)
{
    switch (fw->dryos_ver)
    {
    case 52:    return sig->dryos52_param;
    case 54:    return sig->dryos54_param;
    case 55:    return sig->dryos55_param;
    case 57:    return sig->dryos57_param;
    case 58:    return sig->dryos58_param;
    }
    return 0;
}
*/

// initialize iter stat using address from ref_name, print error and return 0 if not found
int init_disasm_sig_ref(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!rule->ref_name) {
        printf("init_disasm_sig_ref: %s missing ref_name\n",rule->name);
        return 0;
    }
    uint32_t adr=get_saved_sig_val(rule->ref_name);
    if(!adr) {
        printf("init_disasm_sig_ref: %s missing %s\n",rule->name,rule->ref_name);
        return 0;
    }
    if(!disasm_iter_init(fw,is,adr)) {
        printf("init_disasm_sig_ref: %s bad address 0x%08x for %s\n",rule->name,adr,rule->ref_name);
        return 0;
    }
    return 1;
}

int sig_match_near_str(firmware *fw, iter_state_t *is, sig_rule_t *rule);

// match 
// r0=ref value
//...
// bl=<our func>
int sig_match_str_r0_call(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_str_r0_call: %s failed to find ref %s\n",rule->name,rule->ref_name);
        return  0;
    }

//    printf("sig_match_str_r0_call: %s ref str %s 0x%08x\n",rule->name,rule->ref_name,str_adr);

    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
            // printf("sig_match_str_r0_call: %s ref str %s ref 0x%"PRIx64"\n",rule->name,rule->ref_name,is->insn->address);
            // TODO should check if intervening insn nuke r0
            if(insn_match_find_next(fw,is,4,match_b_bl_blximm)) {
                uint32_t adr=get_branch_call_insn_target(fw,is);
                // printf("sig_match_str_r0_call: thumb %s call 0x%08x\n",rule->name,adr);
                return save_sig_with_j(fw,rule->name,adr);
            }
        }
    }
    return 0;
}

// find RegisterEventProcedure
int sig_match_reg_evp(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    const insn_match_t reg_evp_match[]={
        {MATCH_INS(MOV,   2),  {MATCH_OP_REG(R2),  MATCH_OP_REG(R1)}},
        {MATCH_INS(LDR,   2),  {MATCH_OP_REG(R1),  MATCH_OP_MEM_ANY}},
        {MATCH_INS(B,     MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };

    uint32_t e_to_evp=get_saved_sig_val("ExportToEventProcedure_FW");
    if(!e_to_evp) {
        printf("sig_match_reg_evp: failed to find ExportToEventProcedure, giving up\n");
        return 0;
    }

    //look for the underlying RegisterEventProcedure function (not currently used)
    uint32_t reg_evp=0;
    // start at identified Export..
    disasm_iter_init(fw,is,e_to_evp);
    if(insn_match_seq(fw,is,reg_evp_match)) {
        reg_evp=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
        //printf("RegisterEventProcedure found 0x%08x at %"PRIx64"\n",reg_evp,is->insn->address);
        save_sig("RegisterEventProcedure",reg_evp);
    }
    return (reg_evp != 0);
}

// find event proc table registration, and some other stuff
// TODO this should be broken up to some generic parts
int sig_match_reg_evp_table(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    // ref to find RegisterEventProcTable
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name); // note this string may appear more than once, assuming want first
    if(!str_adr) {
        printf("sig_match_reg_evp_table: failed to find %s\n",rule->ref_name);
        return 0;
    }
    //printf("sig_match_reg_evp_table: DispDev_EnableEventProc 0x%08x\n",str_adr);
    uint32_t reg_evp_alt1=0;
    uint32_t reg_evp_tbl=0;
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    uint32_t dd_enable_p=0;
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(is->insn->detail->arm.operands[0].reg != ARM_REG_R0) {
            continue;
        }
        if(!insn_match_find_next(fw,is,2,match_b_bl)) {
            continue;
        }
        reg_evp_alt1=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
        //printf("RegisterEventProcedure_alt1 found 0x%08x at %"PRIx64"\n",reg_evp_alt1,is->insn->address);
        save_sig("RegisterEventProcedure_alt1",reg_evp_alt1);

        uint32_t regs[4];

        // get r0 and r1, backtracking up to 4 instructions
        if((get_call_const_args(fw,is,4,regs)&3)==3) {
            // sanity check, arg0 was the original thing we were looking for
            if(regs[0]==str_adr) {
                dd_enable_p=regs[1]; // constant value should already have correct ARM/THUMB bit
                //printf("DispDev_EnableEventProc found 0x%08x at %"PRIx64"\n",dd_enable_p,is->insn->address);
                add_func_name("DispDev_EnableEventProc",dd_enable_p,NULL);
                break;
            }
        }
    } 
    // found candidate function
    if(dd_enable_p) {
        disasm_iter_init(fw,is,dd_enable_p); // start at found func
        if(insn_match_find_next(fw,is,4,match_b_bl)) { // find the first bl
            // sanity check, make sure we get a const in r0
            uint32_t regs[4];
            if(get_call_const_args(fw,is,4,regs)&1) {
                reg_evp_tbl=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
                // printf("RegisterEventProcTable found 0x%08x at %"PRIx64"\n",reg_evp_tbl,is->insn->address);
                save_sig("RegisterEventProcTable",reg_evp_tbl);
            }
        }
    }
    return (reg_evp_tbl != 0);
}

// find an alternate eventproc registration call
int sig_match_reg_evp_alt2(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t reg_evp_alt2=0;
    // TODO could make this a param for different fw variants
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_reg_evp_alt2: failed to find %s\n",rule->ref_name);
        return 0;
    }
    //printf("sig_match_reg_evp_alt2: EngApp.Delete 0x%08x\n",str_adr);
    uint32_t reg_evp_alt1=get_saved_sig_val("RegisterEventProcedure_alt1");

    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(is->insn->detail->arm.operands[0].reg != ARM_REG_R0) {
            continue;
        }
        if(!insn_match_find_next(fw,is,3,match_b_bl)) {
            continue;
        }
        uint32_t regs[4];
        // sanity check, constants in r0, r1 and r0 was the original thing we were looking for
        if((get_call_const_args(fw,is,4,regs)&3)==3) {
            if(regs[0]==str_adr) {
                reg_evp_alt2=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
                // TODO could keep looking
                if(reg_evp_alt2 == reg_evp_alt1) {
                    printf("RegisterEventProcedure_alt2 == _alt1 at %"PRIx64"\n",is->insn->address);
                    reg_evp_alt2=0;
                } else {
                    save_sig("RegisterEventProcedure_alt2",reg_evp_alt2);
                   // printf("RegisterEventProcedure_alt2 found 0x%08x at %"PRIx64"\n",reg_evp_alt2,is->insn->address);
                    // TODO could follow alt2 and make sure it matches expected mov r2,0, bl register..
                }
                break;
            }
        }
    }
    return (reg_evp_alt2 != 0);
}

// find UnRegisterEventProc (made up name) for reference, finding tables missed by reg_event_proc_table
int sig_match_unreg_evp_table(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_unreg_evp_table: failed to find %s\n",rule->ref_name);
        return 0;
    }
    // for checks
    uint32_t reg_evp_alt1=get_saved_sig_val("RegisterEventProcedure_alt1");
    uint32_t reg_evp_alt2=get_saved_sig_val("RegisterEventProcedure_alt2");

    uint32_t mecha_unreg=0;
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        //printf("sig_match_unreg_evp_table: found ref 0x%"PRIx64"\n",is->insn->address);
        if(is->insn->detail->arm.operands[0].reg != ARM_REG_R0) {
            continue;
        }
        if(!insn_match_find_next(fw,is,3,match_b_bl)) {
            continue;
        }
        uint32_t reg_call=get_branch_call_insn_target(fw,is);
        // wasn't a registration call (could be unreg)
        // TODO could check veneers
        if(!reg_call || (reg_call != reg_evp_alt1 && reg_call != reg_evp_alt2)) {
            continue;
        }
        uint32_t regs[4];
        if((get_call_const_args(fw,is,4,regs)&3)==3) {
            // sanity check we got the right string
            if(regs[0]==str_adr) {
                mecha_unreg=ADR_SET_THUMB(regs[1]);
                break;
            }
        }
    }
    if(!mecha_unreg) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,mecha_unreg);
    // find first func call
    if(!insn_match_find_next(fw,is,7,match_b_bl)) {
        return 0;
    }
    // now find next ldr pc. Could follow above func, but this way picks up veneer on many fw
    const insn_match_t match_ldr_r0[]={
        {MATCH_INS(LDR, 2),   {MATCH_OP_REG(R0),  MATCH_OP_MEM_BASE(PC)}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next(fw,is,18,match_ldr_r0)) {
        return 0;
    }
    uint32_t tbl=LDR_PC2val(fw,is->insn);
    if(!tbl) {
        return 0;
    }
    if(!disasm_iter(fw,is)) {
        printf("sig_match_unreg_evp_table: disasm failed\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}
int sig_match_screenlock(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // match specific instruction sequence instead of first call because g3x, g5x have different code
    // not by dryos rev, sx710 has same code as earlier cams
    const insn_match_t match_cmp_bne_bl[]={
        {MATCH_INS(CMP, 2), {MATCH_OP_REG(R0),  MATCH_OP_IMM(0)}},
        {MATCH_INS_CC(B,NE,MATCH_OPCOUNT_IGNORE)},
        {MATCH_INS(BL,MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,6,match_cmp_bne_bl)) {
        // printf("sig_match_screenlock: match failed\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

int sig_match_screenunlock(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // look for ScreenLock call to verify right version of UIFS_DisplayFirmUpdateView
    if(!find_next_sig_call(fw,is,14,"ScreenLock")) {
        // printf("sig_match_screenunlock: no ScreenLock\n");
        return 0;
    }
    
    // expect tail call to ScreenUnlock
    const insn_match_t match_end[]={
        {MATCH_INS(POP, MATCH_OPCOUNT_IGNORE)},
        {MATCH_INS_CC(B,AL,MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,38,match_end)) {
        // printf("sig_match_screenunlock: match failed\n");
        return 0;
    }
    // TODO would be nice to have some validation
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

// look for f(0x60,"_Simage") at start of task_StartupImage
int sig_match_log_camera_event(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!insn_match_find_next(fw,is,6,match_bl_blximm)) {
        // printf("sig_match_log_camera_event: bl match failed\n");
        return 0;
    }
    uint32_t regs[4];
    if((get_call_const_args(fw,is,4,regs)&3)!=3) {
        // printf("sig_match_log_camera_event: get args failed\n");
        return 0;
    }
    if(regs[0] != 0x60) {
        // printf("sig_match_log_camera_event: bad r0 0x%x\n",regs[0]);
        return 0;
    }
    const char *str=(char *)adr2ptr(fw,regs[1]);
    if(!str || strcmp(str,"_SImage") != 0) {
        // printf("sig_match_log_camera_event: bad r1 0x%x\n",regs[1]);
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

// TODO this finds multiple values in PhySwTask main function
int sig_match_physw_misc(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    int i;
    uint32_t physw_run=0;
    for(i=0; i<3; i++) {
        if(!disasm_iter(fw,is)) {
            printf("sig_match_physw_misc: disasm failed\n");
            return 0;
        }
        physw_run=LDR_PC2val(fw,is->insn);
        if(physw_run) {
            if(adr_is_var(fw,physw_run)) {
                save_misc_val("physw_run",physw_run,0,(uint32_t)is->insn->address);
                break;
            } else {
                printf("sig_match_physw_misc: adr not data? 0x%08x\n",physw_run);
                return 0;
            }
        }
    }
    if(!physw_run) {
        return 0;
    }

    // look for physw_sleep_delay, offset from physw_run, loaded before SleepTask
    if(!insn_match_find_next(fw,is,7,match_bl_blximm)) {
        return 0;
    }
    uint32_t sleeptask=get_saved_sig_val("SleepTask");
    if(!sleeptask) {
        printf("sig_match_physw_misc: missing SleepTask\n");
        return 0;
    }
    uint32_t f=get_branch_call_insn_target(fw,is);

    // call wasn't direct, check for veneer
    if(f != sleeptask) {
        fw_disasm_iter_single(fw,f);
        uint32_t f2=get_direct_jump_target(fw,fw->is);
        if(f2 != sleeptask) {
            return 0;
        }
        // sleeptask veneer is useful for xref
        // re-adding existing won't hurt
        save_sig_with_j(fw,"SleepTask",f);
    }
    // rewind 1 for r0
    disasm_iter_init(fw,is,adr_hist_get(&is->ah,1));
    if(!disasm_iter(fw,is)) {
        printf("sig_match_physw_misc: disasm failed\n");
        return 0;
    }
    // TODO could check base is same reg physw_run was loaded into
    if(is->insn->id != ARM_INS_LDR
        || is->insn->detail->arm.operands[0].reg != ARM_REG_R0) {
        return 0;
    }
    save_misc_val("physw_sleep_delay",physw_run,is->insn->detail->arm.operands[1].mem.disp,(uint32_t)is->insn->address);
    // skip over sleeptask to next insn
    if(!disasm_iter(fw,is)) {
        printf("sig_match_physw_misc: disasm failed\n");
        return 0;
    }
    
    // look for kbd_p1_f
    if(!insn_match_find_next(fw,is,2,match_bl_blximm)) {
        return 0;
    }
    save_sig("kbd_p1_f",get_branch_call_insn_target(fw,is));

    // look for kbd_p2_f
    if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
        return 0;
    }
    save_sig("kbd_p2_f",get_branch_call_insn_target(fw,is));
    return 1;
}
// TODO also finds p1_f_cont, physw_status
int sig_match_kbd_read_keys(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // look for kbd_read_keys
    if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
        return 0;
    }
    save_sig("kbd_read_keys",get_branch_call_insn_target(fw,is));
    if(!disasm_iter(fw,is)) {
        printf("sig_match_kbd_read_keys: disasm failed\n");
        return 0;
    }
    uint32_t physw_status=LDR_PC2val(fw,is->insn);
    if(physw_status) {
        save_misc_val("physw_status",physw_status,0,(uint32_t)is->insn->address);
        save_sig("kbd_p1_f_cont",(uint32_t)(is->insn->address) | is->thumb);
        return 1;
    }
    return 0;
}

// TODO also finds kbd_read_keys_r2
int sig_match_get_kbd_state(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // instructions that zero out physw_status
    insn_match_t match[]={
        {MATCH_INS(LDR, 2), {MATCH_OP_REG(R0),  MATCH_OP_MEM_BASE(PC)}},
        {MATCH_INS(BL,  MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };

    if(!insn_match_find_next_seq(fw,is,11,match)) {
        return 0;
    }
    save_sig_with_j(fw,"GetKbdState",get_branch_call_insn_target(fw,is));
    // look for kbd_read_keys_r2
    if(!insn_match_find_next(fw,is,5,match_b_bl_blximm)) {
        return 0;
    }
    save_sig_with_j(fw,"kbd_read_keys_r2",get_branch_call_insn_target(fw,is));
    return 1;
}

int sig_match_create_jumptable(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // find second function call
    if(!insn_match_find_nth(fw,is,20,2,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    if(!insn_match_find_next(fw,is,15,match_bl_blximm)) {
        return 0;
    }
    // TODO could verify it looks right (version string)
    save_sig("CreateJumptable",get_branch_call_insn_target(fw,is));
    return 1;
}

// TODO this actually finds a bunch of different stuff
int sig_match_take_semaphore_strict(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // find first function call
    if(!insn_match_find_next(fw,is,6,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // find second call
    if(!insn_match_find_nth(fw,is,10,2,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // skip two calls, next should be DebugAssert
    if(!insn_match_find_nth(fw,is,20,3,match_bl_blximm)) {
        return 0;
    }
    save_sig_with_j(fw,"DebugAssert",get_branch_call_insn_target(fw,is));

    // next should be TakeSemaphoreStrictly
    if(!insn_match_find_next(fw,is,7,match_bl_blximm)) {
        return 0;
    }
    save_sig_with_j(fw,"TakeSemaphoreStrictly",get_branch_call_insn_target(fw,is));
    arm_reg ptr_reg = ARM_REG_INVALID;
    uint32_t sem_adr=0;
    int i;
    // iterate backwards looking for the value put in r0
    for(i=1; i<7; i++) {
        fw_disasm_iter_single(fw,adr_hist_get(&is->ah,i));
        cs_insn *insn=fw->is->insn;
        if(insn->id != ARM_INS_LDR) {
            continue;
        }
        if(ptr_reg == ARM_REG_INVALID
            && insn->detail->arm.operands[0].reg == ARM_REG_R0
            && insn->detail->arm.operands[1].mem.base != ARM_REG_PC) {
            ptr_reg = insn->detail->arm.operands[1].mem.base;
            continue;
        }
        if(ptr_reg == ARM_REG_INVALID || !isLDR_PC(insn) || insn->detail->arm.operands[0].reg != ptr_reg) {
            continue;
        }
        sem_adr=LDR_PC2val(fw,insn);
        if(sem_adr) {
            break;
        }
    }
    if(!sem_adr) {
        return 0;
    }
    save_misc_val("fileio_semaphore",sem_adr,0,(uint32_t)is->insn->address);
    // look for next call: GetDrive_FreeClusters
    if(!insn_match_find_next(fw,is,10,match_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,"GetDrive_FreeClusters",get_branch_call_insn_target(fw,is));
}

int sig_match_get_semaphore_value(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_get_semaphore_value: failed to find ref %s\n",rule->ref_name);
        return 0;
    }

    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    // assume first / only ref
    if(!fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // printf("sig_get_semaphore_value: failed to find code ref to %s\n",rule->ref_name);
        return 0;
    }
    // search backwards for func call
    uint32_t fadr=0;
    int i;
    for(i=1; i<=5; i++) {
        if(!fw_disasm_iter_single(fw,adr_hist_get(&is->ah,i))) {
            // printf("sig_get_semaphore_value: disasm failed\n");
            return 0;
        }
        if(insn_match_any(fw->is->insn,match_bl_blximm)){
            fadr=get_branch_call_insn_target(fw,fw->is);
            break;
        }
    }
    if(!fadr) {
        // printf("sig_get_semaphore_value: failed to find bl 1\n");
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,fadr);
    // look for first call
    if(!insn_match_find_next(fw,is,9,match_bl_blximm)) {
        // printf("sig_get_semaphore_value: failed to find bl 2\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}
// similar to sig_match_str_r0_call, but string also appears with Fopen_Fut
int sig_match_stat(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_stat: %s failed to find ref %s\n",rule->name,rule->ref_name);
        return  0;
    }

    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
            if(insn_match_find_next(fw,is,2,match_bl_blximm)) {
                uint32_t adr=get_branch_call_insn_target(fw,is);
                // same string ref'd by Fopen
                if(is_sig_call(fw,is,"Fopen_Fut_FW")) {
                    continue;
                }
                // TODO could check r1 not a const
                return save_sig_with_j(fw,rule->name,adr);
            }
        }
    }
    return 0;
}
static const insn_match_t match_open_mov_call[]={
    // 3 reg / reg movs, followed by a call
    {MATCH_INS(MOV, 2), {MATCH_OP_REG_ANY,  MATCH_OP_REG_ANY}},
    {MATCH_INS(MOV, 2), {MATCH_OP_REG_ANY,  MATCH_OP_REG_ANY}},
    {MATCH_INS(MOV, 2), {MATCH_OP_REG_ANY,  MATCH_OP_REG_ANY}},
    {MATCH_INS(BL,  MATCH_OPCOUNT_IGNORE)},
    {ARM_INS_ENDING}
};


// find low level open
int sig_match_open(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!insn_match_find_next_seq(fw,is,48,match_open_mov_call)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}
// find low level open for dryos >= 58
// TODO not verified it works as expected
int sig_match_open_gt_57(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,38,"TakeSemaphoreStrictly")) {
        return 0;
    }
    // looking for next call
    // this should be equivalent to previous versions Open, without the extra semaphore wrapper
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // match same pattern as normal
    if(!insn_match_find_next_seq(fw,is,48,match_open_mov_call)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

// find low level close for dryos >= 58
// TODO not verified it works as expected
int sig_match_close_gt_57(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,34,"TakeSemaphoreStrictly")) {
        return 0;
    }
    // looking for next call
    // this should be equivalent to previous versions Close, without the extra semaphore wrapper
    if(!insn_match_find_next(fw,is,3,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // first call
    if(!insn_match_find_next(fw,is,3,match_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}


// AllocateUncacheableMemory
int sig_match_umalloc(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // looking for 3rd call
    if(!insn_match_find_nth(fw,is,15,3,match_bl_blximm)) {
        return 0;
    }
    //follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // looking for 3rd call again
    if(!insn_match_find_nth(fw,is,14,3,match_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

// FreeUncacheableMemory
int sig_match_ufree(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // find the first call to strcpy
    if(!find_next_sig_call(fw,is,60,"strcpy_FW")) {
        return 0;
    }
    // find 3rd call
    if(!insn_match_find_nth(fw,is,12,3,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // Look for Close call
    if(!find_next_sig_call(fw,is,40,"Close_FW")) {
        return 0;
    }
    // next call should be FreeUncacheableMemory
    if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

int sig_match_deletefile_fut(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_deletefile_fut: %s failed to find ref %s\n",rule->name,rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // next call should be DeleteFile_Fut
        if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
            continue;
        }
        // follow
        uint32_t adr=get_branch_call_insn_target(fw,is);
        if(!fw_disasm_iter_single(fw,adr)) {
            printf("sig_match_deletefile_fut: disasm failed\n");
            return 0;
        }
        const insn_match_t match_mov_r1[]={
            {MATCH_INS(MOV,     2), {MATCH_OP_REG(R1),  MATCH_OP_IMM_ANY}},
            {MATCH_INS(MOVS,    2), {MATCH_OP_REG(R1),  MATCH_OP_IMM_ANY}},
            {ARM_INS_ENDING}
        };

        if(!insn_match_any(fw->is->insn,match_mov_r1)){
            continue;
        }
        return save_sig_with_j(fw,rule->name,adr);
    }
    return 0;
}

int sig_match_closedir(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_closedir: %s failed to find ref %s\n",rule->name,rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(!find_next_sig_call(fw,is,60,"sprintf_FW")) {
            continue;
        }
        if(insn_match_find_nth(fw,is,7,2,match_bl_blximm)) {
            return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
        }
    }
    return 0;
}


int sig_match_time(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_time: %s failed to find ref %s\n",rule->name,rule->ref_name);
        return  0;
    }
    uint32_t fadr=0;
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // find second func after str ref
        if(insn_match_find_nth(fw,is,6,2,match_bl_blximm)) {
            fadr=get_branch_call_insn_target(fw,is);
            break;
        }
    }
    if(!fadr) {
        return 0;
    }
    // follow found func
    disasm_iter_init(fw,is,fadr);
    // find second call
    if(insn_match_find_nth(fw,is,11,2,match_bl_blximm)) {
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}

int sig_match_strncpy(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,60,"strcpy_FW")) {
        return 0;
    }
    if(!insn_match_find_next(fw,is,6,match_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

int sig_match_strncmp(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_strncmp: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(!insn_match_find_next(fw,is,3,match_bl_blximm)) {
            continue;
        }
        uint32_t regs[4];
        if((get_call_const_args(fw,is,4,regs)&6)==6) {
            // sanity check we got the right string
            if(regs[1]==str_adr &&  regs[2] == strlen(rule->ref_name)) {
                return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
            }
        }
    }
    return 0;
}

int sig_match_strtolx(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,120,"strncpy")) {
        return 0;
    }
    // find first call after strncpy
    if(!insn_match_find_next(fw,is,6,match_bl_blximm)) {
        return 0;
    }
    uint32_t adr=get_branch_call_insn_target(fw,is);
    if(!adr) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,adr);
    if(!disasm_iter(fw,is)) {
        printf("sig_match_strtolx: disasm failed\n");
        return 0;
    }
    // expect
    // mov r3, #0
    // b ...
    const insn_match_t match_mov_r3_imm[]={
        {MATCH_INS(MOV, 2), {MATCH_OP_REG(R3),  MATCH_OP_IMM_ANY}},
        {ARM_INS_ENDING}
    };
    if(!insn_match(is->insn,match_mov_r3_imm)){
        return 0;
    }
    if(!disasm_iter(fw,is)) {
        printf("sig_match_strtolx: disasm failed\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

// find the version of ExecuteEventProcedure that doesn't assert evp isn't reg'd
int sig_match_exec_evp(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_exec_evp: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // search backwards for push {r0,...}
        int i;
        for(i=1; i<=18; i++) {
            if(!fw_disasm_iter_single(fw,adr_hist_get(&is->ah,i))) {
                break;
            }
            if(fw->is->insn->id == ARM_INS_PUSH && fw->is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
                // push should be start of func
                uint32_t adr=(uint32_t)(fw->is->insn->address) | is->thumb;
                // search forward in original iter_state for DebugAssert. If found, in the wrong ExecuteEventProcedure
                if(find_next_sig_call(fw,is,28,"DebugAssert")) {
                    break;
                }
                return save_sig_with_j(fw,rule->name,adr);
            }
        }
    }
    return 0;
}

int sig_match_fgets_fut(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,16,"Fopen_Fut_FW")) {
        return 0;
    }
    if(!insn_match_find_nth(fw,is,20,2,match_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

int sig_match_log(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    const insn_match_t match_pop6[]={
        {MATCH_INS(POP, 6), {MATCH_OP_REST_ANY}},
        {ARM_INS_ENDING}
    };
    // skip forward through 3x pop     {r4, r5, r6, r7, r8, lr}
    if(!insn_match_find_nth(fw,is,38,3,match_pop6)) {
        return 0;
    }
    // third call
    if(!insn_match_find_nth(fw,is,24,3,match_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

// this only works on DryOS r52 cams
int sig_match_pow_dry_52(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if (fw->dryos_ver != 52) {
        return 0;
    }
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    const insn_match_t match_ldrd_r0_r1[]={
        {MATCH_INS(LDRD,    3), {MATCH_OP_REG(R0), MATCH_OP_REG(R1),    MATCH_OP_ANY}},
        {ARM_INS_ENDING}
    };
    // skip forward to first ldrd    r0, r1, [r...]
    if(!insn_match_find_next(fw,is,50,match_ldrd_r0_r1)) {
        return 0;
    }
    // prevent false positive
    if(is->insn->detail->arm.operands[2].mem.base == ARM_REG_SP) {
        return 0;
    }
    if(!disasm_iter(fw,is)) {
        printf("sig_match_pow: disasm failed\n");
        return 0;
    }
    uint32_t adr=get_branch_call_insn_target(fw,is);
    if(!adr) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,adr);
}

// match for dryos > r52 cams
int sig_match_pow_dry_gt_52(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if (fw->dryos_ver <= 52) {
        return 0;
    }
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    const insn_match_t match1[]={
        {MATCH_INS(LDRSH,   2), {MATCH_OP_REG(R0),  MATCH_OP_MEM(SP,INVALID,0x12)}},
        {MATCH_INS(LDRD,    3), {MATCH_OP_REG(R2),  MATCH_OP_REG(R3), MATCH_OP_MEM(SP,INVALID,0x20)}},
        {MATCH_INS(STR,     2), {MATCH_OP_REG_ANY,  MATCH_OP_MEM(SP,INVALID,0)}},
        {MATCH_INS(BL,      MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };
    // match above sequence
    if(!insn_match_find_next_seq(fw,is,50,match1)) {
        return 0;
    }
    uint32_t adr=get_branch_call_insn_target(fw,is);
    if(!adr) {
        return 0;
    }
    // follow bl
    disasm_iter_init(fw,is,adr);
    const insn_match_t match2[]={
        {MATCH_INS(LDRD,3), {MATCH_OP_REG(R0),  MATCH_OP_REG(R1),   MATCH_OP_MEM_ANY}},
        {MATCH_INS(BLX, 1), {MATCH_OP_IMM_ANY}},
        {ARM_INS_ENDING}
    };
    // match above sequence
    if(!insn_match_find_next_seq(fw,is,15,match2)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

int sig_match_sqrt(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // third call
    if(!insn_match_find_nth(fw,is,12,3,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    if(!disasm_iter(fw,is)) {
        printf("sig_match_sqrt: disasm failed\n");
        return 0;
    }
    uint32_t j_tgt=get_direct_jump_target(fw,is);
    // veneer?
    if(j_tgt) {
        // follow
        disasm_iter_init(fw,is,j_tgt);
        if(!disasm_iter(fw,is)) {
            printf("sig_match_sqrt: disasm failed\n");
            return 0;
        }
    }
    // second call/branch (seems to be bhs)
    if(!insn_match_find_nth(fw,is,12,2,match_b_bl_blximm)) {
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}
int sig_match_get_drive_cluster_size(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // only handle first mach, don't expect multiple refs to string
    if(fw_search_insn(fw,is,search_disasm_str_ref,0,"A/OpLogErr.txt",(uint32_t)is->adr+60)) {
        // find first call after string ref
        if(!insn_match_find_next(fw,is,3,match_bl_blximm)) {
            // printf("sig_match_get_drive_cluster_size: bl not found\n");
            return 0;
        }
        // follow
        disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
        // find second call
        if(!insn_match_find_nth(fw,is,13,2,match_bl_blximm)) {
            // printf("sig_match_get_drive_cluster_size: call 1 not found\n");
            return 0;
        }
        // follow
        disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
        // find next call
        if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
            // printf("sig_match_get_drive_cluster_size: call 2 not found\n");
            return 0;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}

int sig_match_mktime_ext(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_mktime_ext: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // expect sscanf after str
        if(!find_next_sig_call(fw,is,12,"sscanf_FW")) {
            // printf("sig_match_mktime_ext: no sscanf\n");
            return 0;
        }
        // find next call
        if(!insn_match_find_next(fw,is,22,match_bl_blximm)) {
            // printf("sig_match_mktime_ext: no call\n");
            return 0;
        }
        // follow
        disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
        if(!disasm_iter(fw,is)) {
            printf("sig_match_mktime_ext: disasm failed\n");
            return 0;
        }
        uint32_t j_tgt=get_direct_jump_target(fw,is);
        // veneer?
        if(j_tgt) {
            // follow
            disasm_iter_init(fw,is,j_tgt);
            if(!disasm_iter(fw,is)) {
                printf("sig_match_mktime_ext: disasm failed\n");
                return 0;
            }
        }
        const insn_match_t match_pop4[]={
            {MATCH_INS(POP, 4), {MATCH_OP_REST_ANY}},
            {ARM_INS_ENDING}
        };

        // find pop
        if(!insn_match_find_next(fw,is,54,match_pop4)) {
            // printf("sig_match_mktime_ext: no pop\n");
            return 0;
        }
        if(!insn_match_find_next(fw,is,1,match_b)) {
            // printf("sig_match_mktime_ext: no b\n");
            return 0;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}

// match call after ref to "_EnrySRec" because "AC:Rec2PB" ref before push in function, hard to be sure of start
int sig_match_rec2pb(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_mktime_ext: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        const insn_match_t match_ldr_cbnz_r0[]={
            {MATCH_INS(LDR, 2), {MATCH_OP_REG(R0), MATCH_OP_MEM_ANY}},
            {MATCH_INS(CBNZ, 2), {MATCH_OP_REG(R0), MATCH_OP_IMM_ANY}},
            {ARM_INS_ENDING}
        };
        if(!insn_match_find_next_seq(fw,is,10,match_ldr_cbnz_r0)) {
            // printf("sig_match_rec2pb: no cbnz\n");
            continue;
        }
        // follow
        disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
        if(!insn_match_find_next(fw,is,3,match_b_bl_blximm)) {
            // printf("sig_match_rec2pb: no call\n");
            // followed branch, doesn't make sense to keep searching
            return 0;
        }
        uint32_t adr=(uint32_t)is->insn->address | is->thumb;
        // follow for sanity check
        disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
        if(!find_next_sig_call(fw,is,16,"LogCameraEvent")) {
            // printf("sig_match_rec2pb: no LogCameraEvent call\n");
            return 0;
        }
        uint32_t regs[4];
        if((get_call_const_args(fw,is,4,regs)&3)!=3) {
            // printf("sig_match_rec2pb: failed to get args\n");
            return 0;
        }
        // sanity check starts with LogCameraEvent with expected number and string
        if(regs[0]==0x60 && adr2ptr(fw,regs[1]) && (strcmp((const char *)adr2ptr(fw,regs[1]),"AC:Rec2PB")==0)) {
            return save_sig_with_j(fw,rule->name,adr);
        } else {
            // printf("sig_match_rec2pb: bad args\n");
            return 0;
        }
    }
    return 0;
}

// could just do sig_match_named, 3rd b, but want more validation
int sig_match_get_parameter_data(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    const insn_match_t match_cmp_bhs[]={
        {MATCH_INS(CMP, 2), {MATCH_OP_REG_ANY, MATCH_OP_IMM_ANY}},
        {MATCH_INS_CC(B,HS,MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,4,match_cmp_bhs)) {
        // printf("sig_match_get_parameter_data: no match cmp, bhs\n");
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    if(!insn_match_find_next(fw,is,1,match_b)) {
        // printf("sig_match_get_parameter_data: no match b\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

// PrepareDirectory (via string ref) points at something like
// mov r1, 1
// b PrepareDirectory_x
int sig_match_prepdir_x(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    const insn_match_t match_mov_r1_1[]={
        {MATCH_INS(MOV,     2), {MATCH_OP_REG(R1),  MATCH_OP_IMM(1)}},
        {MATCH_INS(MOVS,    2), {MATCH_OP_REG(R1),  MATCH_OP_IMM(1)}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next(fw,is,1,match_mov_r1_1)) {
        //printf("sig_match_prepdir_x: no match mov\n");
        return 0;
    }
    if(!insn_match_find_next(fw,is,1,match_b)) {
        //printf("sig_match_prepdir_x: no match b\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}
// assume this function is directly after the 2 instructions of ref
int sig_match_prepdir_0(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    uint32_t ref_pdx=get_saved_sig_val("PrepareDirectory_x");
    if(!ref_pdx) {
        printf("sig_match_prepdir_0: missing PrepareDirectory_x\n");
        return 0;
    }
    // skip over, assume validated previously
    disasm_iter(fw,is);
    disasm_iter(fw,is);
    // this should be the start address of our function
    uint32_t adr=(uint32_t)is->adr|is->thumb;
    const insn_match_t match_mov_r1_1[]={
        {MATCH_INS(MOV,     2), {MATCH_OP_REG(R1),  MATCH_OP_IMM(0)}},
        {MATCH_INS(MOVS,    2), {MATCH_OP_REG(R1),  MATCH_OP_IMM(0)}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next(fw,is,1,match_mov_r1_1)) {
        //printf("sig_match_prepdir_0: no match mov\n");
        return 0;
    }
    if(!insn_match_find_next(fw,is,1,match_b)) {
        //printf("sig_match_prepdir_0: no match b\n");
        return 0;
    }
    uint32_t pdx=get_branch_call_insn_target(fw,is);
    if(pdx != ref_pdx) {
        //printf("sig_match_prepdir_0: target 0x%08x != 0x%08x\n",pdx,ref_pdx);
        return 0;
    }
    return save_sig_with_j(fw,rule->name,adr);
}
int sig_match_mkdir(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    const insn_match_t match[]={
        {MATCH_INS(STRB,2), {MATCH_OP_REG_ANY,  MATCH_OP_MEM_ANY}},
        {MATCH_INS(MOV, 2), {MATCH_OP_REG(R0),  MATCH_OP_REG(SP)}},
        {MATCH_INS(LDR, 2), {MATCH_OP_REG(R1),  MATCH_OP_MEM_BASE(SP)}},
        {MATCH_INS(BL,  MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,148,match)) {
        //printf("sig_match_mkdir: no match\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

int sig_match_add_ptp_handler(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_add_ptp_handler: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // expect CreateTaskStrictly
        if(!find_next_sig_call(fw,is,8,"CreateTaskStrictly")) {
            // printf("sig_match_add_ptp_handler: no CreateTaskStrictly\n");
            continue;
        }
        // expect add_ptp_handler is 3rd call after CreateTask
        if(!insn_match_find_nth(fw,is,13,3,match_bl_blximm)) {
            // printf("sig_match_add_ptp_handler: no match bl\n");
            return 0;
        }
        // sanity check, expect opcode, func, 0
        uint32_t regs[4];
        if((get_call_const_args(fw,is,5,regs)&7)!=7) {
            // printf("sig_match_add_ptp_handler: failed to get args\n");
            return 0;
        }
        if(regs[0] < 0x9000 || regs[0] > 0x10000 || !adr2ptr(fw,regs[1]) || regs[2] != 0) {
            // printf("sig_match_add_ptp_handler: bad args 0x%08x 0x%08x 0x%08x\n",regs[0],regs[1],regs[2]);
            return 0;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}
int sig_match_qsort(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,90,"DebugAssert")) {
        // printf("sig_match_qsort: no DebugAssert\n");
        return 0;
    }
    if(!insn_match_find_nth(fw,is,38,3,match_bl_blximm)) {
        // printf("sig_match_qsort: no match bl\n");
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // if call in first 4 insn, follow again (newer cams have an extra sub)
    if(insn_match_find_next(fw,is,4,match_bl_blximm)) {
        disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    }
    if(!insn_match_find_next(fw,is,14,match_bl_blximm)) {
        // printf("sig_match_qsort: no match bl (qsort)\n");
        return 0;
    }
    // sanity check, expect r1-r3 to be const
    uint32_t regs[4];
    if((get_call_const_args(fw,is,5,regs)&0xe)!=0xe) {
        // printf("sig_match_qsort: failed to get args\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}
// looks for sequence of calls near ref string RedEyeController.c
// DeleteFile_Fut
// ...
// strcpy
// ...
// strchr
// ...
// DeleteDirectory_Fut
int sig_match_deletedirectory_fut(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_deletedirectory_fut: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    // TODO using larger than default "near" range, needed for sx710
    // not looking for ref to string, just code near where the actual string is
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - 2048) | fw->thumb_default); // reset to a bit before where the string was found
    uint32_t end_adr = ADR_ALIGN4(str_adr) + 2048;
    while(find_next_sig_call(fw,is,end_adr - (uint32_t)is->adr,"DeleteFile_Fut")) {
        if(!insn_match_find_next(fw,is,6,match_bl_blximm)) {
            // printf("sig_match_deletedirectory_fut: no match bl strcpy\n");
            continue;
        }
        if(!is_sig_call(fw,is,"strcpy")) {
            // printf("sig_match_deletedirectory_fut: bl not strcpy at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
            // printf("sig_match_deletedirectory_fut: no match bl strrchr at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(!is_sig_call(fw,is,"strrchr")) {
            // printf("sig_match_deletedirectory_fut: bl not strrchr at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        // verify that arg1 to strrch is /
        uint32_t regs[4];
        if((get_call_const_args(fw,is,2,regs)&0x2)!=0x2) {
            // printf("sig_match_deletedirectory_fut: failed to get strrchr r1 at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(regs[1] != '/') {
            // printf("sig_match_deletedirectory_fut: strrchr r1 not '/' at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
            // printf("sig_match_deletedirectory_fut: no match bl at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}

/*
match
   ref "LogicalEvent:0x%04x:adr:%p,Para:%ld" (or "LogicalEvent:0x%08x:adr:%p,Para:%ld")
   bl      LogCameraEvent
   mov     r0, rN
   bl      <some func>
   bl      set_control_event (or veneer)
same string is used elsewhere, so match specific sequence
*/
int sig_match_set_control_event(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        // not logged, two different ref strings so failing one is normal
        // printf("sig_match_set_control_event: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
            // printf("sig_match_set_control_event: no match bl at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(!is_sig_call(fw,is,"LogCameraEvent")) {
            // printf("sig_match_set_control_event: not LogCameraEvent at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        const insn_match_t match_seq[]={
            {MATCH_INS(MOV, 2), {MATCH_OP_REG(R0),  MATCH_OP_REG_ANY,}},
            {MATCH_INS(BL, MATCH_OPCOUNT_IGNORE)},
            {MATCH_INS(BL, MATCH_OPCOUNT_IGNORE)},
            {ARM_INS_ENDING}
        };
        if(!insn_match_find_next_seq(fw,is,1,match_seq)) {
            // printf("sig_match_set_control_event: no match seq\n");
            continue;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}
// find displaybusyonscreen for r52 cams, later uses different code
int sig_match_displaybusyonscreen_52(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if (fw->dryos_ver != 52) {
        return 0;
    }
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_displaybusyonscreen: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(!insn_match_find_next(fw,is,3,match_bl_blximm)) {
            // printf("sig_match_displaybusyonscreen: no match bl at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(!is_sig_call(fw,is,"LogCameraEvent")) {
            // printf("sig_match_displaybusyonscreen: not LogCameraEvent at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(!find_next_sig_call(fw,is,4,"GUISrv_StartGUISystem_FW")) {
            // printf("sig_match_displaybusyonscreen: no match GUISrv_StartGUISystem_FW\n");
            continue;
        }
        if(!insn_match_find_nth(fw,is,5,2,match_bl_blximm)) {
            // printf("sig_match_displaybusyonscreen: no match bl 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}
// find undisplaybusyonscreen for r52 cams, later uses different code
int sig_match_undisplaybusyonscreen_52(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if (fw->dryos_ver != 52) {
        return 0;
    }
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_undisplaybusyonscreen: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // assume same function display* was found in, skip to that
        if(!find_next_sig_call(fw,is,24,"displaybusyonscreen")) {
            // printf("sig_match_undisplaybusyonscreen: no match displaybusyonscreen\n");
            continue;
        }
        if(!find_next_sig_call(fw,is,12,"GUISrv_StartGUISystem_FW")) {
            // printf("sig_match_undisplaybusyonscreen: no match GUISrv_StartGUISystem_FW\n");
            continue;
        }
        if(!insn_match_find_nth(fw,is,6,3,match_bl_blximm)) {
            // printf("sig_match_undisplaybusyonscreen: no match bl 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}
int sig_match_pt_playsound(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    // function looks different on dry >= 57, may be OK but will need wrapper changes
    if (fw->dryos_ver >= 57) {
        return 0;
    }
    return sig_match_near_str(fw,is,rule);
}

int sig_match_wait_all_eventflag_strict(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    uint32_t str_adr = find_str_bytes(fw,"EFTool.c");
    if(!str_adr) {
        printf("sig_match_wait_all_eventflag_strict: failed to find ref EFTool.c\n");
        return 0;
    }
    if(!find_next_sig_call(fw,is,60,"SleepTask")) {
        printf("sig_match_wait_all_eventflag_strict: failed to find SleepTask\n");
        return 0;
    }

    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,is->adr + 60)) {
        if(!insn_match_find_next(fw,is,6,match_bl_blximm)) {
            printf("sig_match_wait_all_eventflag_strict: no match bl 0x%"PRIx64"\n",is->insn->address);
            return 0;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}

int sig_match_get_num_posted_messages(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,50,"TakeSemaphore")) {
        printf("sig_match_get_num_posted_messages: failed to find TakeSemaphore\n");
        return 0;
    }
    // find next call
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        printf("sig_match_get_num_posted_messages:  no match bl 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
}

int sig_match_set_hp_timer_after_now(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_set_hp_timer_after_now: failed to find ref %s\n",rule->ref_name);
        return 0;
    }
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(!find_next_sig_call(fw,is,20,"ClearEventFlag")) {
            // printf("sig_match_set_hp_timer_after_now: failed to find ClearEventFlag\n");
            continue;
        }
        // find 3rd call
        if(!insn_match_find_nth(fw,is,13,3,match_bl_blximm)) {
            // printf("sig_match_set_hp_timer_after_now: no match bl 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        // check call args, expect r0 = 70000
        uint32_t regs[4];
        if((get_call_const_args(fw,is,6,regs)&0x1)!=0x1) {
            // printf("sig_match_set_hp_timer_after_now: failed to get args 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        // r1, r2 should be func pointers but may involve reg-reg moves that get_call_const_args doesn't track
        if(regs[0] != 70000) {
            // printf("sig_match_set_hp_timer_after_now: args mismatch 0x%08x 0x%08x 0x%"PRIx64"\n",regs[0],regs[1],is->insn->address);
            continue;
        }
        return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
    }
    return 0;
}
int sig_match_levent_table(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
        // printf("sig_match_levent_table: no match bl 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));

    // find first call of next function
    if(!insn_match_find_next(fw,is,4,match_bl_blximm)) {
        // printf("sig_match_levent_table: no match bl 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));

    // first instruction should load address
    disasm_iter(fw,is);
    uint32_t adr=LDR_PC2val(fw,is->insn);
    if(!adr) {
        // printf("sig_match_levent_table: no match LDR PC 0x%"PRIx64"\n",is->insn->address);
        return  0;
    }
    uint32_t *p=(uint32_t *)adr2ptr(fw,adr);
    if(!p) {
        printf("sig_match_levent_table: 0x%08x not a ROM adr 0x%"PRIx64"\n",adr,is->insn->address);
        return  0;
    }
    if(*(p+1) != 0x800) {
        printf("sig_match_levent_table: expected 0x800 not 0x%x at 0x%08x ref 0x%"PRIx64"\n",*(p+1),adr,is->insn->address);
        return  0;
    }
    // TODO saving the function might be useful for analysis
    save_misc_val(rule->name,adr,0,(uint32_t)is->insn->address);
    return 1;
}
int sig_match_flash_param_table(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // expect 3 asserts
    if(!insn_match_find_next(fw,is,14,match_bl_blximm)) {
        // printf("sig_match_flash_param_table: no match bl 1\n");
        return 0;
    }
    if(!is_sig_call(fw,is,"DebugAssert")) {
        // printf("sig_match_flash_param_table: bl 1 not DebugAssert at 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    if(!insn_match_find_next(fw,is,7,match_bl_blximm)) {
        // printf("sig_match_flash_param_table: no match bl 2\n");
        return 0;
    }
    if(!is_sig_call(fw,is,"DebugAssert")) {
        // printf("sig_match_flash_param_table: bl 2 not DebugAssert at 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    if(!insn_match_find_next(fw,is,8,match_bl_blximm)) {
        // printf("sig_match_flash_param_table: no match bl 3\n");
        return 0;
    }
    if(!is_sig_call(fw,is,"DebugAssert")) {
        // printf("sig_match_flash_param_table: bl 3 not DebugAssert at 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    // expect AcquireRecursiveLockStrictly, func
    if(!insn_match_find_nth(fw,is,14,2,match_bl_blximm)) {
        // printf("sig_match_flash_param_table: no match sub 1\n");
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));

    // first call
    if(!insn_match_find_next(fw,is,8,match_bl_blximm)) {
        // printf("sig_match_flash_param_table: no match sub 1 bl\n");
        return 0;
    }
    
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // first instruction should load address
    disasm_iter(fw,is);
    uint32_t adr=LDR_PC2val(fw,is->insn);
    if(!adr) {
        // printf("sig_match_flash_param_table: no match LDR PC 0x%"PRIx64"\n",is->insn->address);
        return  0;
    }
    save_misc_val(rule->name,adr,0,(uint32_t)is->insn->address);
    return 1;
}
int sig_match_jpeg_count_str(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_jpeg_count_str: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // printf("sig_match_jpeg_count_str: str match 0x%"PRIx64"\n",is->insn->address);
        if(!insn_match_find_next(fw,is,3,match_bl_blximm)) {
            // printf("sig_match_jpeg_count_str: no match bl\n");
            continue;
        }
        if(!is_sig_call(fw,is,"sprintf_FW")) {
            // printf("sig_match_jpeg_count_str: not sprintf_FW at 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        // expect ptr in r0, str in r1
        uint32_t regs[4];
        if((get_call_const_args(fw,is,5,regs)&0x3)!=0x3) {
            // printf("sig_match_jpeg_count_str: failed to get sprintf args 0x%"PRIx64"\n",is->insn->address);
            continue;
        }
        if(regs[1] != str_adr) {
            // printf("sig_match_jpeg_count_str: expected r1 == 0x%08x not 0x%08x at 0x%"PRIx64"\n",str_adr, regs[1],is->insn->address);
            return 0;
        }
        if(!adr_is_var(fw,regs[0])) {
            // printf("sig_match_jpeg_count_str: r0 == 0x%08x not var ptr at 0x%"PRIx64"\n",regs[0],is->insn->address);
            return 0;
        }
        save_misc_val(rule->name,regs[0],0,(uint32_t)is->insn->address);
        return 1;
    }
    return 0;
}

int sig_match_cam_uncached_bit(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    const insn_match_t match_bic_r0[]={
        {MATCH_INS(BIC, 3), {MATCH_OP_REG(R0),  MATCH_OP_REG(R0),   MATCH_OP_IMM_ANY}},
        {ARM_INS_ENDING}
    };
    if(insn_match_find_next(fw,is,4,match_bic_r0)) {
        save_misc_val(rule->name,is->insn->detail->arm.operands[2].imm,0,(uint32_t)is->insn->address);
        return 1;
    }
    return 0;
}

int sig_match_physw_event_table(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // expect first LDR pc
    if(!insn_match_find_next(fw,is,5,match_ldr_pc)) {
        printf("sig_match_physw_event_table: match LDR PC failed\n");
        return 0;
    }
    uint32_t adr=LDR_PC2val(fw,is->insn);
    if(!adr) {
        printf("sig_match_physw_event_table: no match LDR PC 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    if(!adr2ptr(fw,adr)) {
        printf("sig_match_physw_event_table: adr not ROM 0x%08x at 0x%"PRIx64"\n",adr,is->insn->address);
        return 0;
    }
    save_misc_val(rule->name,adr,0,(uint32_t)is->insn->address);
    return 1;
}
int sig_match_uiprop_count(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    if(!find_next_sig_call(fw,is,38,"DebugAssert")) {
        // printf("sig_match_uiprop_count: no DebugAssert 1\n");
        return 0;
    }
    if(!find_next_sig_call(fw,is,14,"DebugAssert")) {
        // printf("sig_match_uiprop_count: no DebugAssert 2\n");
        return 0;
    }
    const insn_match_t match_bic_cmp[]={
        {MATCH_INS(BIC, 3), {MATCH_OP_REG_ANY,  MATCH_OP_REG_ANY,   MATCH_OP_IMM(0x8000)}},
        {MATCH_INS(CMP, 2), {MATCH_OP_REG_ANY,  MATCH_OP_ANY}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,3,match_bic_cmp)) {
        // printf("sig_match_uiprop_count: no bic,cmp\n");
        return 0;
    }
    save_misc_val(rule->name,is->insn->detail->arm.operands[1].imm,0,(uint32_t)is->insn->address);
    return 1;
}

int sig_match_get_canon_mode_list(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_get_canon_mode_list: failed to find ref %s\n",rule->ref_name);
        return  0;
    }
    uint32_t adr=0;
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        // printf("sig_match_get_canon_mode_list: str match 0x%"PRIx64"\n",is->insn->address);
        if(!find_next_sig_call(fw,is,4,"LogCameraEvent")) {
            // printf("sig_match_get_canon_mode_list: no LogCameraEvent\n");
            continue;
        }
        // some cameras have a mov and an extra call
        if(!disasm_iter(fw,is)) {
            // printf("sig_match_var_struct_get: disasm failed\n");
            return 0;
        }
        const insn_match_t match_mov_r0_1[]={
            {MATCH_INS(MOVS, 2), {MATCH_OP_REG(R0),  MATCH_OP_IMM(1)}},
            {MATCH_INS(MOV, 2), {MATCH_OP_REG(R0),  MATCH_OP_IMM(1)}},
            {ARM_INS_ENDING}
        };
        if(insn_match_any(is->insn,match_mov_r0_1)) {
            if(!insn_match_find_nth(fw,is,2,2,match_bl_blximm)) {
                // printf("sig_match_get_canon_mode_list: no match bl 1x\n");
                continue;
            }
        } else {
            if(!insn_match_any(is->insn,match_bl_blximm)) {
                // printf("sig_match_get_canon_mode_list: no match bl 1\n");
                continue;
            }
        }
        // found something to follow, break
        adr=get_branch_call_insn_target(fw,is);
        break;
    }
    if(!adr) {
        return 0;
    }
    // printf("sig_match_get_canon_mode_list: sub 1 0x%08x\n",adr);
    disasm_iter_init(fw,is,adr);
    if(!find_next_sig_call(fw,is,40,"TakeSemaphoreStrictly")) {
        // printf("sig_match_get_canon_mode_list: no TakeSemaphoreStrictly\n");
        return 0;
    }
    // match second call
    if(!insn_match_find_nth(fw,is,12,2,match_bl_blximm)) {
        // printf("sig_match_get_canon_mode_list: no match bl 2\n");
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    const insn_match_t match_loop[]={
        {MATCH_INS(ADD, 3), {MATCH_OP_REG_ANY,  MATCH_OP_REG_ANY,   MATCH_OP_IMM(1)}},
        {MATCH_INS(UXTH, 2), {MATCH_OP_REG_ANY,  MATCH_OP_REG_ANY}},
        {MATCH_INS(CMP, 2), {MATCH_OP_REG_ANY,  MATCH_OP_IMM_ANY}},
        {MATCH_INS_CC(B,LO,MATCH_OPCOUNT_IGNORE)},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,40,match_loop)) {
        // printf("sig_match_get_canon_mode_list: match 1 failed\n");
        return 0;
    }
    if(!insn_match_find_next(fw,is,2,match_bl_blximm)) {
        // printf("sig_match_get_canon_mode_list: no match bl 3\n");
        return 0;
    }
    // should be func
    adr=get_branch_call_insn_target(fw,is);
    // sanity check
    disasm_iter_init(fw,is,adr);
    const insn_match_t match_ldr_r0_ret[]={
        {MATCH_INS(LDR, 2),   {MATCH_OP_REG(R0),  MATCH_OP_MEM_BASE(PC)}},
        {MATCH_INS(BX, 1),   {MATCH_OP_REG(LR)}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,1,match_ldr_r0_ret)) {
        // printf("sig_match_get_canon_mode_list: match 2 failed\n");
        return 0;
    }
    return save_sig_with_j(fw,rule->name,adr);
} 

int sig_match_zoom_busy(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // first call
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        // printf("sig_match_zoom_busy: no match bl\n");
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // get base address from first LDR PC
    if(!insn_match_find_next(fw,is,5,match_ldr_pc)) {
        // printf("sig_match_zoom_busy: match LDR PC failed\n");
        return 0;
    }
    uint32_t base=LDR_PC2val(fw,is->insn);
    arm_reg rb=is->insn->detail->arm.operands[0].reg;
    
    // look for first TakeSemaphoreStrictly
    if(!find_next_sig_call(fw,is,40,"TakeSemaphoreStrictly")) {
        // printf("sig_match_zoom_busy: no match TakeSemaphoreStrictly\n");
        return 0;
    }
    if(!disasm_iter(fw,is)) {
        // printf("sig_match_zoom_busy: disasm failed\n");
        return 0;
    }
    // assume next instruction is ldr
    if(is->insn->id != ARM_INS_LDR 
        || is->insn->detail->arm.operands[0].reg != ARM_REG_R0
        || is->insn->detail->arm.operands[1].mem.base != rb) {
        // printf("sig_match_zoom_busy: no match LDR\n");
        return 0;
    }
    save_misc_val(rule->name,base,is->insn->detail->arm.operands[1].mem.disp,(uint32_t)is->insn->address);
    return 1;
}

int sig_match_focus_busy(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    // look for first TakeSemaphore
    if(!find_next_sig_call(fw,is,40,"TakeSemaphore")) {
        // printf("sig_match_focus_busy: no match TakeSemaphore\n");
        return 0;
    }
    // next call
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        // printf("sig_match_focus_busy: no match bl\n");
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // get base address from first LDR PC
    if(!insn_match_find_next(fw,is,5,match_ldr_pc)) {
        // printf("sig_match_focus_busy: match LDR PC failed\n");
        return 0;
    }
    uint32_t base=LDR_PC2val(fw,is->insn);
    arm_reg rb=is->insn->detail->arm.operands[0].reg;
    
    // look for first TakeSemaphoreStrictly
    if(!find_next_sig_call(fw,is,50,"TakeSemaphoreStrictly")) {
        // printf("sig_match_focus_busy: no match TakeSemaphoreStrictly\n");
        return 0;
    }
    const insn_match_t match_ldr[]={
        {MATCH_INS(LDR, 2), {MATCH_OP_REG(R0), MATCH_OP_MEM_ANY}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next(fw,is,7,match_ldr)) {
        // printf("sig_match_focus_busy: no match LDR\n");
        return 0;
    }

    // check LDR 
    if(is->insn->detail->arm.operands[1].mem.base != rb) {
        // printf("sig_match_focus_busy: no match LDR base\n");
        return 0;
    }
    save_misc_val(rule->name,base,is->insn->detail->arm.operands[1].mem.disp,(uint32_t)is->insn->address);
    return 1;
}
int sig_match_aram_size(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        printf("sig_match_aram_size: missing ref\n");
        return 0;
    }
    const insn_match_t match_ldr_r0_sp_cmp[]={
        {MATCH_INS(LDR, 2), {MATCH_OP_REG(R0),MATCH_OP_MEM(SP,INVALID,0xc)}},
        {MATCH_INS(CMP, 2), {MATCH_OP_REG(R0),MATCH_OP_IMM_ANY}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,15,match_ldr_r0_sp_cmp)) {
        printf("sig_match_aram_size: no match LDR\n");
        return 0;
    }
    uint32_t val=is->insn->detail->arm.operands[1].imm;
    if(val != 0x22000 && val != 0x32000) {
        printf("sig_match_aram_size: unexpected ARAM size 0x%08x\n",val);
    }
    save_misc_val(rule->name,val,0,(uint32_t)is->insn->address);
    return 1;
}

int sig_match_aram_start(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        printf("sig_match_aram_start: missing ref\n");
        return 0;
    }
    if(!find_next_sig_call(fw,is,46,"DebugAssert")) {
        printf("sig_aram_start: no match DebugAssert\n");
        return 0;
    }
    const insn_match_t match_cmp_bne_ldr[]={
        {MATCH_INS(CMP, 2), {MATCH_OP_REG(R1),MATCH_OP_IMM(0)}},
        {MATCH_INS_CC(B,NE,MATCH_OPCOUNT_IGNORE)},
        {MATCH_INS(LDR, 2), {MATCH_OP_REG_ANY,MATCH_OP_MEM_BASE(PC)}},
        {ARM_INS_ENDING}
    };
    if(!insn_match_find_next_seq(fw,is,15,match_cmp_bne_ldr)) {
        printf("sig_match_aram_start: no match CMP\n");
        return 0;
    }
    uint32_t adr=LDR_PC2val(fw,is->insn);
    if(!adr) {
        printf("sig_match_aram_start: no match LDR PC 0x%"PRIx64"\n",is->insn->address);
        return 0;
    }
    // could sanity check that it looks like a RAM address
    save_misc_val(rule->name,adr,0,(uint32_t)is->insn->address);
    return 1;
}

// get the address used by a function that does something like
// ldr rx =base
// ldr r0 [rx, offset] (optional)
// bx lr
int sig_match_var_struct_get(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    uint32_t fadr=is->adr;
    if(!disasm_iter(fw,is)) {
        printf("sig_match_var_struct_get: disasm failed\n");
        return 0;
    }
    uint32_t adr=LDR_PC2val(fw,is->insn);
    if(!adr) {
        // printf("sig_match_var_struct_get: no match LDR PC 0x%"PRIx64"\n",is->insn->address);
        return  0;
    }
    arm_reg reg_base = is->insn->detail->arm.operands[0].reg; // reg value was loaded into
    if(!disasm_iter(fw,is)) {
        printf("sig_match_var_struct_get: disasm failed\n");
        return 0;
    }
    uint32_t disp=0;
    if(is->insn->id == ARM_INS_LDR) {
        if(is->insn->detail->arm.operands[0].reg != ARM_REG_R0
            || is->insn->detail->arm.operands[1].mem.base != reg_base) {
            // printf("sig_match_var_struct_get: no ldr match\n");
            return 0;
        }
        disp = is->insn->detail->arm.operands[1].mem.disp;
        if(!disasm_iter(fw,is)) {
            printf("sig_match_var_struct_get: disasm failed\n");
            return 0;
        }
    } else if(reg_base != ARM_REG_R0) {
        // if no second LDR, first must be into R0
        // printf("sig_match_var_struct_get: not r0\n");
        return 0;
    }
    // TODO could check for other RET type instructions
    if(!insn_match(is->insn,match_bxlr)) {
        // printf("sig_match_var_struct_get: no match BX LR\n");
        return 0;
    }
    save_misc_val(rule->name,adr,disp,fadr);
    return 1;
}

int sig_match_rom_ptr_get(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    if(!init_disasm_sig_ref(fw,is,rule)) {
        return 0;
    }
    uint32_t fadr=is->adr;
    if(!disasm_iter(fw,is)) {
        printf("sig_match_rom_ptr_get: disasm failed\n");
        return 0;
    }
    uint32_t adr=LDR_PC2val(fw,is->insn);
    if(!adr) {
        printf("sig_match_rom_ptr_get: no match LDR PC 0x%"PRIx64"\n",is->insn->address);
        return  0;
    }
    if(is->insn->detail->arm.operands[0].reg != ARM_REG_R0) {
        printf("sig_match_rom_ptr_get: not R0\n");
        return 0;
    }
    if(!disasm_iter(fw,is)) {
        printf("sig_match_rom_ptr_get: disasm failed\n");
        return 0;
    }
    // TODO could check for other RET type instructions
    if(!insn_match(is->insn,match_bxlr)) {
        printf("sig_match_rom_ptr_get: no match BX LR\n");
        return 0;
    }
    save_misc_val(rule->name,adr,0,fadr);
    return 1;
}

#define SIG_NEAR_OFFSET_MASK    0x00FF
#define SIG_NEAR_COUNT_MASK     0xFF00
#define SIG_NEAR_COUNT_SHIFT    8
#define SIG_NEAR_REV            0x10000
#define SIG_NEAR_INDIRECT       0x20000
#define SIG_NEAR_JMP_SUB        0x40000
#define SIG_NEAR_AFTER(max_insns,n) (((max_insns)&SIG_NEAR_OFFSET_MASK) \
                                | (((n)<<SIG_NEAR_COUNT_SHIFT)&SIG_NEAR_COUNT_MASK))
#define SIG_NEAR_BEFORE(max_insns,n) (SIG_NEAR_AFTER(max_insns,n)|SIG_NEAR_REV)
                                
// find Nth function call within max_insns ins of string ref
int sig_match_near_str(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t str_adr = find_str_bytes(fw,rule->ref_name);
    if(!str_adr) {
        printf("sig_match_near_str: %s failed to find ref %s\n",rule->name,rule->ref_name);
        return 0;
    }
    uint32_t search_adr = str_adr;
    // looking for ref to ptr to string, not ref to string
    // TODO only looks for first ptr
    if(rule->param & SIG_NEAR_INDIRECT) {
        // printf("sig_match_near_str: %s str 0x%08x\n",rule->name,str_adr);
        search_adr=find_u32_adr(fw,str_adr,fw->base);
        if(!search_adr) {
            printf("sig_match_near_str: %s failed to find indirect ref %s\n",rule->name,rule->ref_name);
            return 0;
        }
        // printf("sig_match_near_str: %s indirect 0x%08x\n",rule->name,search_adr);
    }
    const insn_match_t *insn_match;
    if(rule->param & SIG_NEAR_JMP_SUB) {
        insn_match = match_b_bl_blximm;
    } else {
        insn_match = match_bl_blximm;
    }

    int max_insns=rule->param&SIG_NEAR_OFFSET_MASK;
    int n=(rule->param&SIG_NEAR_COUNT_MASK)>>SIG_NEAR_COUNT_SHIFT;
    //printf("sig_match_near_str: %s max_insns %d n %d %s\n",rule->name,max_insns,n,(rule->param & SIG_NEAR_REV)?"rev":"fwd");
    // TODO should handle multiple instances of string
    disasm_iter_init(fw,is,(ADR_ALIGN4(search_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,search_adr+SEARCH_NEAR_REF_RANGE)) {
        // bactrack looking for preceding call
        if(rule->param & SIG_NEAR_REV) {
            int i;
            int n_calls=0;
            for(i=1; i<=max_insns; i++) {
                fw_disasm_iter_single(fw,adr_hist_get(&is->ah,i));
                if(insn_match_any(fw->is->insn,insn_match)) {
                    n_calls++;
                }
                if(n_calls == n) {
                    return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,fw->is));
                }
            }
        } else {
            if(insn_match_find_nth(fw,is,max_insns,n,insn_match)) {
                return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
            }
        }
    }
    printf("sig_match_near_str: no match %s\n",rule->name);
    return 0;
}

// check if func is a nullsub or mov r0, x ; ret
// to prevent sig_named* matches from going off the end of dummy funcs
int is_immediate_ret_sub(firmware *fw,iter_state_t *is_init)
{
    fw_disasm_iter_single(fw,is_init->adr | is_init->thumb);
    const insn_match_t match_mov_r0_imm[]={
        {MATCH_INS(MOV,   2),  {MATCH_OP_REG(R0),  MATCH_OP_IMM_ANY}},
        {MATCH_INS(MOVS,  2),  {MATCH_OP_REG(R0),  MATCH_OP_IMM_ANY}},
        {ARM_INS_ENDING}
    };
    // if it's a MOV, check if next is ret
    if(insn_match_any(fw->is->insn,match_mov_r0_imm)) {
        fw_disasm_iter(fw);
    }
    if(isRETx(fw->is->insn)) {
        return 1;
    }
    return 0;
}

// match last function called by already matched sig, 
// either the last bl/blximmg before pop {... pc}
// or b after pop {... lr}
// param defines min and max number of insns
// doesn't work on functions that don't push/pop since can't tell if unconditional branch is last
// TODO should probably be split into a general "find last call of current func"
#define SIG_NAMED_LAST_MAX_MASK     0x00000FFF
#define SIG_NAMED_LAST_MIN_MASK     0x00FFF000
#define SIG_NAMED_LAST_MIN_SHIFT    12
#define SIG_NAMED_LAST_RANGE(min,max)   ((SIG_NAMED_LAST_MIN_MASK&((min)<<SIG_NAMED_LAST_MIN_SHIFT)) \
                                         | (SIG_NAMED_LAST_MAX_MASK&(max)))

int sig_match_named_last(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t ref_adr = get_saved_sig_val(rule->ref_name);
    int min = (rule->param&SIG_NAMED_LAST_MIN_MASK)>>SIG_NAMED_LAST_MIN_SHIFT;
    int max = (rule->param&SIG_NAMED_LAST_MAX_MASK);
    if(!ref_adr) {
        printf("sig_match_named_last: %s missing %s\n",rule->name,rule->ref_name);
        return 0;
    }
    disasm_iter_init(fw,is,ref_adr);
    if(is_immediate_ret_sub(fw,is)) {
        printf("sig_match_named_last: immediate return %s\n",rule->name);
        return 0;
    }
    int push_found=0;
    uint32_t last_adr=0;
    int count;
    for(count=0; count < max; count++) {
        if(!disasm_iter(fw,is)) {
            printf("sig_match_named_last: disasm failed %s 0x%"PRIx64"\n",rule->name,is->adr);
            return 0;
        }
        if(isPUSH_LR(is->insn)) {
            // already found a PUSH LR, probably in new function
            if(push_found) {
                return 0;
            }
            push_found=1;
            continue;
        }
        // ignore everything before push (could be some mov/ldr, shoudln't be any calls)
        if(!push_found) {
            continue;
        }
        // found a potential call, store
        if(insn_match_any(is->insn,match_bl_blximm) && count >= min) {
            last_adr=get_branch_call_insn_target(fw,is);
            continue;
        }
        // found pop PC, can only be stored call if present
        if(isPOP_PC(is->insn)) {
            if(last_adr) {
                return save_sig_with_j(fw,rule->name,last_adr);
            }
            // no call found, or not found within min
            return 0;
        }
        // found pop LR, check if next is unconditional B
        if(isPOP_LR(is->insn)) {
            // hit func end with less than min, no match
            if(count < min) {
                return 0;
            }
            if(!disasm_iter(fw,is)) {
                printf("sig_match_named_last: disasm failed %s 0x%"PRIx64"\n",rule->name,is->adr);
                return 0;
            }
            if(is->insn->id == ARM_INS_B && is->insn->detail->arm.cc == ARM_CC_AL) {
                return save_sig_with_j(fw,rule->name,get_branch_call_insn_target(fw,is));
            }
            // doen't go more than one insn after pop (could be more, but uncommon)
            return 0;
        }
        // found another kind of ret, give up
        if(isRETx(is->insn)) {
            return 0;
        }
    }
    return 0;
}

// default - use the named firmware function
#define SIG_NAMED_ASIS          0x00000000
// use the target of the first B, BX, BL, BLX etc
#define SIG_NAMED_JMP_SUB       0x00000001
// use the target of the first BL, BLX
#define SIG_NAMED_SUB           0x00000002
#define SIG_NAMED_TYPE_MASK     0x0000000F

#define SIG_NAMED_CLEARTHUMB    0x00000010
#define SIG_NAMED_FLAG_MASK     0x000000F0

#define SIG_NAMED_NTH_MASK      0x00000F00
#define SIG_NAMED_NTH_SHIFT     8

//#define SIG_NAMED_NTH(n,type)   ((SIG_NAMED_NTH_MASK&((n)<<SIG_NAMED_NTH_SHIFT)) | ((SIG_NAMED_##type)&SIG_NAME_TYPE_MASK))
#define SIG_NAMED_NTH(n,type)   ((SIG_NAMED_NTH_MASK&((n)<<SIG_NAMED_NTH_SHIFT)) | (SIG_NAMED_##type))

void sig_match_named_save_sig(const char *name, uint32_t adr, uint32_t flags)
{
    if(flags & SIG_NAMED_CLEARTHUMB) {
        adr = ADR_CLEAR_THUMB(adr);
    }
    save_sig(name,adr);
}
// match already identified function found by name
// if offset is 1, match the first called function with 20 insn instead (e.g. to avoid eventproc arg handling)
// initial direct jumps (j_foo) assumed to have been handled
int sig_match_named(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t ref_adr = get_saved_sig_val(rule->ref_name);
    if(!ref_adr) {
        printf("sig_match_named: missing %s\n",rule->ref_name);
        return 0;
    }
    uint32_t sig_type = rule->param & SIG_NAMED_TYPE_MASK;
    uint32_t sig_flags = rule->param & SIG_NAMED_FLAG_MASK;
    uint32_t sig_nth = (rule->param & SIG_NAMED_NTH_MASK)>>SIG_NAMED_NTH_SHIFT;
    if(!sig_nth) {
        sig_nth=1;
    }
    // no offset, just save match as is
    // TODO might want to validate anyway
    if(sig_type == SIG_NAMED_ASIS) {
        sig_match_named_save_sig(rule->name,ref_adr,sig_flags); 
        return 1;
    }
    const insn_match_t *insn_match;
    if(sig_type == SIG_NAMED_JMP_SUB) {
        insn_match = match_b_bl_blximm;
    } else if(sig_type == SIG_NAMED_SUB) {
        insn_match = match_bl_blximm;
    } else {
        printf("sig_match_named: %s invalid type %d\n",rule->ref_name,sig_type);
        return 0;
    }
    // untested, warn
    if(!ADR_IS_THUMB(ref_adr)) {
        printf("sig_match_named: %s is ARM 0x%08x\n",rule->ref_name, ref_adr);
//        return 0;
    }
    disasm_iter_init(fw,is,ref_adr);
    // TODO for eventprocs, may just want to use the original
    if(is_immediate_ret_sub(fw,is)) {
        printf("sig_match_named: immediate return %s\n",rule->name);
        return 0;
    }
    // TODO max search is hardcoded
    if(insn_match_find_nth(fw,is,15 + 5*sig_nth,sig_nth,insn_match)) {
        uint32_t adr = B_BL_BLXimm_target(fw,is->insn);
        if(adr) {
            // BLX, set thumb bit 
            if(is->insn->id == ARM_INS_BLX) {
                // curently not thumb, set in target
                if(!is->thumb) {
                    adr=ADR_SET_THUMB(adr);
                }
            } else {
                // preserve current state
                adr |= is->thumb;
            }
            disasm_iter_set(fw,is,adr);
            if(disasm_iter(fw,is)) {
                // TODO only checks one level
                uint32_t j_adr=get_direct_jump_target(fw,is);
                if(j_adr) {
                    char *buf=malloc(strlen(rule->name)+3);
                    // add j_ for cross referencing
                    sprintf(buf,"j_%s",rule->name);
                    add_func_name(buf,adr,NULL); // add the previous address as j_...
                    adr=j_adr;
                }
            } else {
                printf("sig_match_named: disasm failed in j_ check at %s 0x%08x\n",rule->name,adr);
            }
            sig_match_named_save_sig(rule->name,adr,sig_flags); 
            return 1;
        } else {
            printf("sig_match_named: %s invalid branch target 0x%08x\n",rule->ref_name,adr);
        }
    } else {
        printf("sig_match_named: %s branch not found 0x%08x\n",rule->ref_name,ref_adr);
    }
    return 0;
}

#define SIG_DRY_MIN(min_rel) (min_rel),0
#define SIG_DRY_MAX(max_rel) 0,(max_rel)
#define SIG_DRY_RANGE(min_rel,max_rel) (min_rel),(max_rel)
// bootstrap sigs
// order is important
sig_rule_t sig_rules_initial[]={
// function         CHDK name                   ref name/string         func param          dry rel
// NOTE _FW is in the CHDK column, because that's how it is in sig_names
{sig_match_str_r0_call, "ExportToEventProcedure_FW","ExportToEventProcedure"},
{sig_match_reg_evp,     "RegisterEventProcedure",},
{sig_match_reg_evp_table, "RegisterEventProcTable","DispDev_EnableEventProc"},
{sig_match_reg_evp_alt2, "RegisterEventProcedure_alt2","EngApp.Delete"},
{sig_match_unreg_evp_table,"UnRegisterEventProcTable","MechaUnRegisterEventProcedure"},
{sig_match_str_r0_call,"CreateTaskStrictly",    "FileWriteTask",},
{sig_match_str_r0_call,"CreateTask",            "EvShel",},
{NULL},
};

sig_rule_t sig_rules_main[]={
// function         CHDK name                   ref name/string         func param          dry rel
{sig_match_named,   "ExitTask",                 "ExitTask_FW",},
{sig_match_named,   "EngDrvRead",               "EngDrvRead_FW",        SIG_NAMED_JMP_SUB},
{sig_match_named,   "CalcLog10",                "CalcLog10_FW",         SIG_NAMED_JMP_SUB},
{sig_match_named,   "CalcSqrt",                 "CalcSqrt_FW",          SIG_NAMED_JMP_SUB},
{sig_match_named,   "Close",                    "Close_FW",},
{sig_match_named,   "close",                    "Close",                SIG_NAMED_SUB,      SIG_DRY_MAX(57)},
{sig_match_named,   "DoAELock",                 "SS.DoAELock_FW",       SIG_NAMED_JMP_SUB},
{sig_match_named,   "DoAFLock",                 "SS.DoAFLock_FW",       SIG_NAMED_JMP_SUB},
{sig_match_named,   "Fclose_Fut",               "Fclose_Fut_FW",},
{sig_match_named,   "Fopen_Fut",                "Fopen_Fut_FW",},
{sig_match_named,   "Fread_Fut",                "Fread_Fut_FW",},
{sig_match_named,   "Fseek_Fut",                "Fseek_Fut_FW",},
{sig_match_named,   "Fwrite_Fut",               "Fwrite_Fut_FW",},
{sig_match_named,   "GetAdChValue",             "GetAdChValue_FW",},
{sig_match_named,   "GetCurrentAvValue",        "GetCurrentAvValue_FW",},
{sig_match_named,   "GetBatteryTemperature",    "GetBatteryTemperature_FW",},
{sig_match_named,   "GetCCDTemperature",        "GetCCDTemperature_FW",},
{sig_match_named,   "GetFocusLensSubjectDistance","GetFocusLensSubjectDistance_FW",SIG_NAMED_JMP_SUB},
{sig_match_named,   "GetOpticalTemperature",    "GetOpticalTemperature_FW",},
{sig_match_named,   "GetPropertyCase",          "GetPropertyCase_FW",   SIG_NAMED_SUB},
{sig_match_named,   "GetSystemTime",            "GetSystemTime_FW",},
{sig_match_named,   "GetVRAMHPixelsSize",       "GetVRAMHPixelsSize_FW",},
{sig_match_named,   "GetVRAMVPixelsSize",       "GetVRAMVPixelsSize_FW",},
{sig_match_named,   "GetZoomLensCurrentPoint",  "GetZoomLensCurrentPoint_FW",},
{sig_match_named,   "GetZoomLensCurrentPosition","GetZoomLensCurrentPosition_FW",},
{sig_match_named,   "GiveSemaphore",            "GiveSemaphore_FW",},
{sig_match_named,   "IsStrobeChargeCompleted",  "EF.IsChargeFull_FW",},
{sig_match_named,   "Read",                     "Read_FW",},
{sig_match_named,   "LEDDrive",                 "LEDDrive_FW",},
{sig_match_named,   "LockMainPower",            "LockMainPower_FW",},
{sig_match_named,   "MoveFocusLensToDistance",  "MoveFocusLensToDistance_FW",},
{sig_match_named,   "MoveIrisWithAv",           "MoveIrisWithAv_FW",},
{sig_match_named,   "MoveZoomLensWithPoint",    "MoveZoomLensWithPoint_FW",},
{sig_match_named,   "Open",                     "Open_FW",},
{sig_match_named,   "PostLogicalEventForNotPowerType",  "PostLogicalEventForNotPowerType_FW",},
{sig_match_named,   "PostLogicalEventToUI",     "PostLogicalEventToUI_FW",},
{sig_match_named,   "PT_MFOn",                  "SS.MFOn_FW",           SIG_NAMED_JMP_SUB},
{sig_match_named,   "PT_MFOff",                 "SS.MFOff_FW",          SIG_NAMED_JMP_SUB},
{sig_match_named,   "PT_MoveDigitalZoomToWide", "SS.MoveDigitalZoomToWide_FW", SIG_NAMED_JMP_SUB},
{sig_match_named,   "PT_MoveOpticalZoomAt",     "SS.MoveOpticalZoomAt_FW",},
{sig_match_named,   "PutInNdFilter",            "PutInNdFilter_FW",},
{sig_match_named,   "PutOutNdFilter",           "PutOutNdFilter_FW",},
{sig_match_named,   "SetAE_ShutterSpeed",       "SetAE_ShutterSpeed_FW",},
{sig_match_named,   "SetAutoShutdownTime",      "SetAutoShutdownTime_FW",},
{sig_match_named,   "SetCurrentCaptureModeType","SetCurrentCaptureModeType_FW",},
{sig_match_named,   "SetLogicalEventActive",    "UiEvnt_SetLogicalEventActive_FW",},
{sig_match_named,   "SetScriptMode",            "SetScriptMode_FW",},
{sig_match_named,   "SleepTask",                "SleepTask_FW",},
{sig_match_named,   "SetPropertyCase",          "SetPropertyCase_FW",   SIG_NAMED_SUB},
{sig_match_named,   "TakeSemaphore",            "TakeSemaphore_FW",},
{sig_match_named,   "TurnOnDisplay",            "DispCon_TurnOnDisplay_FW",SIG_NAMED_SUB},
{sig_match_named,   "TurnOffDisplay",           "DispCon_TurnOffDisplay_FW",SIG_NAMED_SUB},
{sig_match_named,   "TurnOnBackLight",          "DispCon_TurnOnBackLight_FW",SIG_NAMED_SUB},
{sig_match_named,   "TurnOffBackLight",         "DispCon_TurnOffBackLight_FW",SIG_NAMED_SUB},
{sig_match_named,   "UIFS_WriteFirmInfoToFile", "UIFS_WriteFirmInfoToFile_FW",},
{sig_match_named,   "UnlockAE",                 "SS.UnlockAE_FW",       SIG_NAMED_JMP_SUB},
{sig_match_named,   "UnlockAF",                 "SS.UnlockAF_FW",       SIG_NAMED_JMP_SUB},
{sig_match_named,   "UnlockMainPower",          "UnlockMainPower_FW",},
{sig_match_named,   "UnRegisterEventProcedure", "UnRegisterEventProcTable", SIG_NAMED_SUB},
//{sig_match_named,   "UnsetZoomForMovie",        "UnsetZoomForMovie_FW",},
{sig_match_named,   "VbattGet",                 "VbattGet_FW",},
{sig_match_named,   "Write",                    "Write_FW",},
{sig_match_named,   "bzero",                    "exec_FW",              SIG_NAMED_SUB},
{sig_match_named,   "dry_memcpy",               "task__tgTask",         SIG_NAMED_SUB},
{sig_match_named,   "exmem_free",               "ExMem.FreeCacheable_FW",SIG_NAMED_JMP_SUB},
{sig_match_named,   "exmem_alloc",              "ExMem.AllocCacheable_FW",SIG_NAMED_JMP_SUB},
{sig_match_named,   "free",                     "FreeMemory_FW",        SIG_NAMED_JMP_SUB},
{sig_match_named,   "lseek",                    "Lseek_FW",},
{sig_match_named,   "_log10",                   "CalcLog10",            SIG_NAMED_NTH(2,SUB)},
{sig_match_named,   "malloc",                   "AllocateMemory_FW",    SIG_NAMED_JMP_SUB},
{sig_match_named,   "memcmp",                   "memcmp_FW",},
{sig_match_named,   "memcpy",                   "memcpy_FW",},
{sig_match_named,   "memset",                   "memset_FW",},
{sig_match_named,   "strcmp",                   "strcmp_FW",},
{sig_match_named,   "strcpy",                   "strcpy_FW",},
{sig_match_named,   "strlen",                   "strlen_FW",},
{sig_match_named,   "task_CaptSeq",             "task_CaptSeqTask",},
{sig_match_named,   "task_ExpDrv",              "task_ExpDrvTask",},
{sig_match_named,   "task_FileWrite",           "task_FileWriteTask",},
//{sig_match_named,   "task_MovieRecord",         "task_MovieRecord",},
//{sig_match_named,   "task_PhySw",               "task_PhySw",},
{sig_match_named,   "vsprintf",                 "sprintf_FW",           SIG_NAMED_SUB},
{sig_match_named,   "PTM_GetCurrentItem",       "PTM_GetCurrentItem_FW",},
{sig_match_named,   "DisableISDriveError",      "DisableISDriveError_FW",},
// TODO assumes CreateTask is in RAM, doesn't currently check
{sig_match_named,   "hook_CreateTask",          "CreateTask",           SIG_NAMED_CLEARTHUMB},
{sig_match_named,   "malloc_strictly",          "task_EvShel",          SIG_NAMED_NTH(2,SUB)},
{sig_match_named,   "DebugAssert2",             "malloc_strictly",      SIG_NAMED_NTH(3,SUB)},
{sig_match_named,   "AcquireRecursiveLockStrictly","StartWDT_FW",       SIG_NAMED_NTH(1,SUB)},
{sig_match_named,   "CheckAllEventFlag",        "ChargeStrobeForFA_FW", SIG_NAMED_SUB},
{sig_match_named,   "ClearEventFlag",           "GetAEIntegralValueWithFix_FW",SIG_NAMED_SUB},
{sig_match_named,   "CheckAnyEventFlag",        "task_SynchTask",       SIG_NAMED_NTH(2,SUB)},
{sig_match_named,   "taskcreate_LowConsole",    "task_EvShel",          SIG_NAMED_SUB},
{sig_match_named,   "CreateMessageQueueStrictly","taskcreate_LowConsole",SIG_NAMED_SUB},
{sig_match_named,   "CreateBinarySemaphoreStrictly","taskcreate_LowConsole",SIG_NAMED_NTH(2,SUB)},
{sig_match_named,   "PostMessageQueue",         "GetCh_FW",             SIG_NAMED_NTH(2,SUB)},
{sig_match_named,   "CreateEventFlagStrictly",  "task_CreateHeaderTask",SIG_NAMED_SUB},
{sig_match_named,   "WaitForAnyEventFlag",      "task_CreateHeaderTask",SIG_NAMED_NTH(2,SUB)},
{sig_match_named,   "GetEventFlagValue",        "task_CreateHeaderTask",SIG_NAMED_NTH(3,SUB)},
{sig_match_named,   "CreateBinarySemaphore",    "task_UartLog",         SIG_NAMED_SUB},
{sig_match_named,   "PostMessageQueueStrictly", "EF.IsChargeFull_FW",   SIG_NAMED_SUB},
{sig_match_named,   "SetEventFlag",             "StopStrobeChargeForFA_FW",SIG_NAMED_SUB},
{sig_match_named,   "TryReceiveMessageQueue",   "task_DvlpSeqTask",     SIG_NAMED_NTH(3,SUB)},
// Semaphore funcs found by eventproc match, but want veneers. Will warn if mismatched
{sig_match_named,   "TakeSemaphore",            "task_Bye",             SIG_NAMED_SUB},
{sig_match_named_last,"GiveSemaphore",          "TurnOnVideoOutMode_FW",SIG_NAMED_LAST_RANGE(10,24)},
// can't use last because func has early return POP
{sig_match_named,   "ReleaseRecursiveLock",     "StartWDT_FW",          SIG_NAMED_NTH(2,SUB)},
//{sig_match_named,   "ScreenLock",               "UIFS_DisplayFirmUpdateView_FW",SIG_NAMED_SUB},
{sig_match_screenlock,"ScreenLock",             "UIFS_DisplayFirmUpdateView_FW"},
{sig_match_screenunlock,"ScreenUnlock",         "UIFS_DisplayFirmUpdateView_FW"},
{sig_match_log_camera_event,"LogCameraEvent",   "task_StartupImage",},
{sig_match_physw_misc, "physw_misc",            "task_PhySw"},
{sig_match_kbd_read_keys, "kbd_read_keys",      "kbd_p1_f"},
{sig_match_get_kbd_state, "GetKbdState",        "kbd_read_keys"},
{sig_match_create_jumptable, "CreateJumptable", "InitializeAdjustmentSystem_FW"},
{sig_match_take_semaphore_strict, "TakeSemaphoreStrictly","Fopen_Fut"},
{sig_match_get_semaphore_value,"GetSemaphoreValue","\tRaw[%i]"},
{sig_match_stat,    "stat",                     "A/uartr.req"},
{sig_match_open,    "open",                     "Open_FW",              0,              SIG_DRY_MAX(57)},
{sig_match_open_gt_57,"open",                   "Open_FW",              0,              SIG_DRY_MIN(58)},
// match close for dryos 58 and later
{sig_match_close_gt_57,"close",                 "Close_FW",             0,              SIG_DRY_MIN(58)},
{sig_match_umalloc, "AllocateUncacheableMemory","Fopen_Fut_FW"},
{sig_match_ufree,   "FreeUncacheableMemory",    "Fclose_Fut_FW"},
{sig_match_cam_uncached_bit,"CAM_UNCACHED_BIT", "FreeUncacheableMemory"},
{sig_match_deletefile_fut,"DeleteFile_Fut",     "Get Err TempPath"},
// not using Strictly, to pick up veneers
{sig_match_near_str,"AcquireRecursiveLock",     "not executed\n",SIG_NEAR_BEFORE(20,3)},
{sig_match_near_str,"CreateCountingSemaphoreStrictly","DvlpSeqTask",    SIG_NEAR_BEFORE(18,3)},
{sig_match_near_str,"CreateMessageQueue",       "CreateMessageQueue:%ld",SIG_NEAR_BEFORE(7,1)},
{sig_match_near_str,"CreateEventFlag",          "CreateEventFlag:%ld",  SIG_NEAR_BEFORE(7,1)},
{sig_match_near_str,"CreateRecursiveLock",      "WdtInt",               SIG_NEAR_BEFORE(9,1)},
{sig_match_near_str,"CreateRecursiveLockStrictly","LoadedScript",       SIG_NEAR_AFTER(6,2)},
{sig_match_near_str,"DeleteMessageQueue",       "DeleteMessageQueue(%d) is FAILURE",SIG_NEAR_BEFORE(10,1)},
{sig_match_near_str,"DeleteEventFlag",          "DeleteEventFlag(%d) is FAILURE",SIG_NEAR_BEFORE(10,1)},
{sig_match_near_str,"ReceiveMessageQueue",      "ReceiveMessageQue:%d", SIG_NEAR_BEFORE(9,1)},
{sig_match_near_str,"RegisterInterruptHandler", "WdtInt",               SIG_NEAR_AFTER(3,1)},
{sig_match_near_str,"TryPostMessageQueue",      "TryPostMessageQueue(%d)\n",SIG_NEAR_BEFORE(9,1)},
// different string on cams newer than sx280
{sig_match_near_str,"TryPostMessageQueue",      "[CWS]TryPostMessageQueue(%d) Failed\n",SIG_NEAR_BEFORE(9,1)},
{sig_match_near_str,"TryTakeSemaphore",         "FileScheduleTask",     SIG_NEAR_AFTER(10,2)},
{sig_match_near_str,"WaitForAllEventFlag",      "Error WaitEvent PREPARE_TESTREC_EXECUTED.", SIG_NEAR_BEFORE(5,1)},
{sig_match_near_str,"WaitForAnyEventFlagStrictly","_imageSensorTask",   SIG_NEAR_AFTER(10,2)},
{sig_match_wait_all_eventflag_strict,"WaitForAllEventFlagStrictly","EF.StartInternalMainFlash_FW"},
{sig_match_near_str,"DeleteSemaphore",          "DeleteSemaphore passed",SIG_NEAR_BEFORE(3,1)},
{sig_match_get_num_posted_messages,"GetNumberOfPostedMessages","task_CtgTotalTask"},
{sig_match_near_str,"LocalTime",                "%Y-%m-%dT%H:%M:%S",    SIG_NEAR_BEFORE(5,1)},
{sig_match_near_str,"strftime",                 "%Y/%m/%d %H:%M:%S",    SIG_NEAR_AFTER(3,1)},
{sig_match_near_str,"OpenFastDir",              "OpenFastDir_ERROR\n",  SIG_NEAR_BEFORE(5,1)},
{sig_match_near_str,"ReadFastDir",              "ReadFast_ERROR\n",     SIG_NEAR_BEFORE(5,1)},
// this matches using sig_match_near_str, but function for dryos >=57 takes additional param so disabling for those versions
{sig_match_pt_playsound,"PT_PlaySound",         "BufAccBeep",           SIG_NEAR_AFTER(7,2)|SIG_NEAR_JMP_SUB, SIG_DRY_MAX(56)},
{sig_match_closedir,"closedir",                 "ReadFast_ERROR\n",},
{sig_match_near_str,"strrchr",                  "ReadFast_ERROR\n",     SIG_NEAR_AFTER(9,2)},
{sig_match_time,    "time",                     "<UseAreaSize> DataWidth : %d , DataHeight : %d\r\n",},
{sig_match_near_str,"strcat",                   "String can't be displayed; no more space in buffer",SIG_NEAR_AFTER(5,2)},
{sig_match_near_str,"strchr",                   "-._~",SIG_NEAR_AFTER(4,1)},
{sig_match_strncpy, "strncpy",                  "UnRegisterEventProcedure",},
{sig_match_strncmp, "strncmp",                  "EXFAT   ",},
{sig_match_strtolx, "strtolx",                  "CheckSumAll_FW",},
{sig_match_near_str,"strtol",                   "prio <task ID> <priority>\n",SIG_NEAR_AFTER(7,1)},
{sig_match_exec_evp,"ExecuteEventProcedure",    "Can not Execute "},
{sig_match_fgets_fut,"Fgets_Fut",               "CheckSumAll_FW",},
{sig_match_log,     "_log",                     "_log10",},
{sig_match_pow_dry_52,"_pow",                   "GetDefectTvAdj_FW",    0,                  SIG_DRY_MAX(52)},
{sig_match_pow_dry_gt_52,"_pow",                "GetDefectTvAdj_FW",    0,                  SIG_DRY_MIN(53)},
{sig_match_sqrt,    "_sqrt",                    "CalcSqrt",},
{sig_match_named,   "get_fstype",               "OpenFastDir",          SIG_NAMED_NTH(2,SUB)},
{sig_match_near_str,"GetMemInfo",               " -- refusing to print malloc information.\n",SIG_NEAR_AFTER(7,2)},
{sig_match_get_drive_cluster_size,"GetDrive_ClusterSize","OpLog.WriteToSD_FW",},
{sig_match_mktime_ext,"mktime_ext",             "%04d%02d%02dT%02d%02d%02d.%01d",},
{sig_match_near_str,"PB2Rec",                   "AC:ActionP2R Fail",     SIG_NEAR_BEFORE(6,1)},
{sig_match_rec2pb,  "Rec2PB",                   "_EnrySRec",},
//{sig_match_named,   "GetParameterData",         "PTM_RestoreUIProperty_FW",          SIG_NAMED_NTH(3,JMP_SUB)},
{sig_match_get_parameter_data,"GetParameterData","PTM_RestoreUIProperty_FW",},
{sig_match_near_str,"PrepareDirectory_1",       "<OpenFileWithDir> PrepareDirectory NG\r\n",SIG_NEAR_BEFORE(7,2)},
{sig_match_prepdir_x,"PrepareDirectory_x",      "PrepareDirectory_1",},
{sig_match_prepdir_0,"PrepareDirectory_0",      "PrepareDirectory_1",},
{sig_match_mkdir,   "MakeDirectory_Fut",        "PrepareDirectory_x",},
{sig_match_add_ptp_handler,"add_ptp_handler",   "PTPtoFAPI_EventProcTask_Try",},
{sig_match_qsort,   "qsort",                    "task_MetaCtg",},
{sig_match_deletedirectory_fut,"DeleteDirectory_Fut","RedEyeController.c",},
{sig_match_set_control_event,"set_control_event","LogicalEvent:0x%04x:adr:%p,Para:%ld",},
// newer cams use %08x
{sig_match_set_control_event,"set_control_event","LogicalEvent:0x%08x:adr:%p,Para:%ld",},
{sig_match_displaybusyonscreen_52,"displaybusyonscreen","_PBBusyScrn",  0,                  SIG_DRY_MAX(52)},
{sig_match_undisplaybusyonscreen_52,"undisplaybusyonscreen","_PBBusyScrn",0,                SIG_DRY_MAX(52)},
{sig_match_near_str,"srand",                    "Canon Degital Camera"/*sic*/,SIG_NEAR_AFTER(14,4)|SIG_NEAR_INDIRECT},
{sig_match_near_str,"rand",                     "Canon Degital Camera"/*sic*/,SIG_NEAR_AFTER(15,5)|SIG_NEAR_INDIRECT},
{sig_match_set_hp_timer_after_now,"SetHPTimerAfterNow","MechaNC.c",},
{sig_match_levent_table,"levent_table",         "ShowLogicalEventName_FW",},
{sig_match_flash_param_table,"FlashParamsTable","GetParameterData",},
{sig_match_named,   "get_playrec_mode",         "task_SsStartupTask",   SIG_NAMED_SUB},
{sig_match_var_struct_get,"playrec_mode",       "get_playrec_mode",},
{sig_match_jpeg_count_str,"jpeg_count_str",     "9999",},
{sig_match_physw_event_table,"physw_event_table","kbd_read_keys_r2",},
{sig_match_uiprop_count,"uiprop_count",         "PTM_SetCurrentItem_FW",},
{sig_match_get_canon_mode_list,"get_canon_mode_list","AC:PTM_Init",},
{sig_match_rom_ptr_get,"canon_mode_list",       "get_canon_mode_list",},
{sig_match_zoom_busy,"zoom_busy",               "ResetZoomLens_FW",},
{sig_match_focus_busy,"focus_busy",             "MoveFocusLensToTerminate_FW",},
{sig_match_aram_size,"ARAM_HEAP_SIZE",          "AdditionAgentRAM_FW",},
{sig_match_aram_start,"ARAM_HEAP_START",        "AdditionAgentRAM_FW",},
{NULL},
};

void run_sig_rules(firmware *fw, sig_rule_t *sig_rules)
{
    sig_rule_t *rule=sig_rules;
    // for convenience, pass an iter_state to match fns so they don't have to manage
    iter_state_t *is=disasm_iter_new(fw,0);
    while(rule->match_fn) {
        if((rule->dryos_min && fw->dryos_ver < rule->dryos_min)
            || (rule->dryos_max && fw->dryos_ver > rule->dryos_max)) {
            rule++;
            continue;
        }
//        printf("rule: %s ",rule->name);
        //int r=rule->match_fn(fw,is,rule);
        rule->match_fn(fw,is,rule);
//        printf("%d\n",r);
        rule++;
    }
    disasm_iter_free(is);
}

void add_event_proc(firmware *fw, char *name, uint32_t adr)
{
    // TODO - no ARM eventprocs seen so far, warn
    if(!ADR_IS_THUMB(adr)) {
        printf("add_event_proc: %s is ARM 0x%08x\n",name,adr);
    }
    // attempt to disassemble target
    if(!fw_disasm_iter_single(fw,adr)) {
        printf("add_event_proc: %s disassembly failed at 0x%08x\n",name,adr);
        return;
    }
    // handle functions that immediately jump
    // only one level of jump for now, doesn't check for conditionals, but first insn shouldn't be conditional
    //uint32_t b_adr=B_target(fw,fw->is->insn);
    uint32_t b_adr=get_direct_jump_target(fw,fw->is);
    if(b_adr) {
        char *buf=malloc(strlen(name)+6);
        sprintf(buf,"j_%s_FW",name);
        add_func_name(buf,adr,NULL); // this is the orignal named address
//        adr=b_adr | fw->is->thumb; // thumb bit from iter state
        adr=b_adr; // thumb bit already handled by get_direct...
    }
    add_func_name(name,adr,"_FW");
}

// process a call to an 2 arg event proc registration function
int process_reg_eventproc_call(firmware *fw, iter_state_t *is,uint32_t unused) {
    uint32_t regs[4];
    // get r0, r1, backtracking up to 4 instructions
    if((get_call_const_args(fw,is,4,regs)&3)==3) {
        // TODO follow ptr to verify code, pick up underlying functions
        if(isASCIIstring(fw,regs[0])) {
            char *nm=(char *)adr2ptr(fw,regs[0]);
            add_event_proc(fw,nm,regs[1]);
            //add_func_name(nm,regs[1],NULL);
            //printf("eventproc found %s 0x%08x at 0x%"PRIx64"\n",nm,regs[1],is->insn->address);
        } else {
            printf("eventproc name not string at 0x%"PRIx64"\n",is->insn->address);
        }
    } else {
        printf("failed to get export/register eventproc args at 0x%"PRIx64"\n",is->insn->address);
    }
    return 0; // always keep looking
}

// process a call to event proc table registration
int process_eventproc_table_call(firmware *fw, iter_state_t *is,uint32_t unused) {
    uint32_t regs[4];
    // get r0, backtracking up to 4 instructions
    if(get_call_const_args(fw,is,4,regs)&1) {
        // include tables in RAM data
        uint32_t *p=(uint32_t*)adr2ptr_with_data(fw,regs[0]);
        //printf("found eventproc table 0x%08x\n",regs[0]);
        // if it was a valid address
        if(p) {
            while(*p) {
                uint32_t nm_adr=*p;
                if(!isASCIIstring(fw,nm_adr)) {
                    printf("eventproc name not string tbl 0x%08x 0x%08x\n",regs[0],nm_adr);
                    break;
                }
                char *nm=(char *)adr2ptr(fw,nm_adr);
                p++;
                uint32_t fn=*p;
                p++;
                //printf("found %s 0x%08x\n",nm,fn);
                add_event_proc(fw,nm,fn);
                //add_func_name(nm,fn,NULL);
            }
        } else {
            printf("failed to get *EventProcTable arg 0x%08x at 0x%"PRIx64"\n",regs[0],is->insn->address);
        }
    } else {
        printf("failed to get *EventProcTable r0 at 0x%"PRIx64"\n",is->insn->address);
    }
    return 0;
}

int process_createtask_call(firmware *fw, iter_state_t *is,uint32_t unused) {
    //printf("CreateTask call at %"PRIx64"\n",is->insn->address);
    uint32_t regs[4];
    // get r0 (name) and r3 (entry), backtracking up to 10 instructions
    if((get_call_const_args(fw,is,10,regs)&9)==9) {
        if(isASCIIstring(fw,regs[0])) {
            // TODO
            char *buf=malloc(64);
            char *nm=(char *)adr2ptr(fw,regs[0]);
            sprintf(buf,"task_%s",nm);
            //printf("found %s 0x%08x at 0x%"PRIx64"\n",buf,regs[3],is->insn->address);
            add_func_name(buf,regs[3],NULL);
        } else {
            printf("task name name not string at 0x%"PRIx64"\n",is->insn->address);
        }
    } else {
        printf("failed to get CreateTask args at 0x%"PRIx64"\n",is->insn->address);
    }
    return 0;
}

int add_generic_func_match(search_calls_multi_data_t *match_fns,
                            int *match_fn_count,
                            int max_funcs,
                            search_calls_multi_fn fn,
                            uint32_t adr)
{
    if(*match_fn_count >= max_funcs-1) {
        printf("add_generic_func_match: ERROR max_funcs %d reached\n",max_funcs);
        match_fns[max_funcs-1].adr=0;
        match_fns[max_funcs-1].fn=NULL;
        return 0;
    }
    match_fns[*match_fn_count].adr=adr;
    match_fns[*match_fn_count].fn=fn;
    (*match_fn_count)++;
    match_fns[*match_fn_count].adr=0;
    match_fns[*match_fn_count].fn=NULL;
    return 1;
}
#define MAX_GENERIC_FUNCS 16
void add_generic_sig_match(search_calls_multi_data_t *match_fns,
                                int *match_fn_count,
                                search_calls_multi_fn fn,
                                const char *name)
{
    uint32_t adr=get_saved_sig_val(name);
    if(!adr) {
        printf("add_generic_sig_match: missing %s\n",name);
    }
    add_generic_func_match(match_fns,match_fn_count,MAX_GENERIC_FUNCS,fn,adr);
    char veneer[128];
    sprintf(veneer,"j_%s",name);
    adr=get_saved_sig_val(veneer);
    if(adr) {
        add_generic_func_match(match_fns,match_fn_count,MAX_GENERIC_FUNCS,fn,adr);
    }
}
/*
collect as many calls as possible of functions identified by name, whether or not listed in funcs to find
*/
void find_generic_funcs(firmware *fw) {
    search_calls_multi_data_t match_fns[MAX_GENERIC_FUNCS];

    int match_fn_count=0;

    add_generic_sig_match(match_fns,&match_fn_count,process_reg_eventproc_call,"ExportToEventProcedure_FW");
    add_generic_sig_match(match_fns,&match_fn_count,process_reg_eventproc_call,"RegisterEventProcedure_alt1");
    add_generic_sig_match(match_fns,&match_fn_count,process_reg_eventproc_call,"RegisterEventProcedure_alt2");
    add_generic_sig_match(match_fns,&match_fn_count,process_eventproc_table_call,"RegisterEventProcTable");
    add_generic_sig_match(match_fns,&match_fn_count,process_eventproc_table_call,"UnRegisterEventProcTable");
    add_generic_sig_match(match_fns,&match_fn_count,process_createtask_call,"CreateTaskStrictly");
    add_generic_sig_match(match_fns,&match_fn_count,process_createtask_call,"CreateTask");

    iter_state_t *is=disasm_iter_new(fw,0);
    disasm_iter_init(fw,is,fw->rom_code_search_min_adr | fw->thumb_default); // reset to start of fw
    fw_search_insn(fw,is,search_disasm_calls_multi,0,match_fns,0);

    // currently only finds SD1stInit task on a couple cams
    int i;
    for(i=0;i<fw->adr_range_count;i++) {
        if(fw->adr_ranges[i].type != ADR_RANGE_RAM_CODE) {
            continue;
        }
        disasm_iter_init(fw,is,fw->adr_ranges[i].start | fw->thumb_default); // reset to start of range
        fw_search_insn(fw,is,search_disasm_calls_multi,0,match_fns,0);
    }

    disasm_iter_free(is);
}

int find_ctypes(firmware *fw, int k)
{
    static unsigned char ctypes[] =
    {
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x60, 0x60, 0x60, 0x60, 0x60, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x48, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
        0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
        0x10, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0x10, 0x10, 0x10, 0x10, 0x10,
        0x10, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0x10, 0x10, 0x10, 0x10, 0x20
    };

    if (k < (fw->size8 - sizeof(ctypes)))
    {
        if (memcmp(((char*)fw->buf8)+k,ctypes,sizeof(ctypes)) == 0)
        {
            //printf("found ctypes 0x%08x\n",fw->base + k);
            save_misc_val("ctypes",fw->base + k,0,0); 
            // use ctypes as max search address for non-copied / relocated code. 
            // seems to be true on current firmwares
            fw->rom_code_search_max_adr = fw->base + k;
            return 1;
        }
    }
    return 0;
}

void print_misc_val_makefile(const char *name)
{
    misc_val_t *mv=get_misc_val(name);
    if(!mv) {
        return;
    }
    // TODO legitimate 0 values might be possible, if so can add found bit
    if(!mv->val) {
        bprintf("// %s not found\n",name);
        return;
    }
    bprintf("//   %s = 0x%08x # ",name,mv->val);
    if(mv->offset) {
        bprintf(" (0x%x+0x%x)",mv->base,mv->offset);
    }
    if(mv->ref_adr) {
        bprintf(" Found @0x%08x",mv->ref_adr);
    }
    bprintf("\n");
}


void output_firmware_vals(firmware *fw)
{
    bprintf("// Camera info:\n");
    bprintf("//   Main firmware start: 0x%08x\n",fw->base+fw->main_offs);
    if (fw->dryos_ver == 0)
    {
        bprintf("//   Can't find DRYOS version !!!\n\n");
    } else {
        bprintf("//   DRYOS R%d (%s)\n",fw->dryos_ver,fw->dryos_ver_str);
    }
    if (fw->firmware_ver_str == 0)
    {
        bprintf("//   Can't find firmware version !!!\n\n");
    }
    else
    {
        char *c = strrchr(fw->firmware_ver_str,' ') + 1; // points after the last space char
        uint32_t j = ptr2adr(fw,(uint8_t *)fw->firmware_ver_str);
        uint32_t k = j + c - fw->firmware_ver_str;
        if ( (k>=j) && (k<j+32) )
        {
            bprintf("//   %s   // Found @ 0x%08x, \"%s\" @ 0x%08x\n",fw->firmware_ver_str,j,c,k);
        }
        else
        {
            // no space found in string (shouldn't happen)
            bprintf("//   %s   // Found @ 0x%08x, \"%s\" @ 0x%08x\n",fw->firmware_ver_str,j,fw->firmware_ver_str,j);
        }
    }
    bprintf("\n// Values for makefile.inc\n");
    bprintf("//   PLATFORMOSVER = %d\n",fw->dryos_ver);

    if (fw->memisostart) {
        bprintf("//   MEMISOSTART = 0x%x\n",fw->memisostart);
    } else {
        bprintf("//   MEMISOSTART not found !!!\n");
    }
    if (fw->data_init_start)
    {
        bprintf("//   MEMBASEADDR = 0x%x\n",fw->data_start);
    }
    print_misc_val_makefile("ARAM_HEAP_START");
    print_misc_val_makefile("ARAM_HEAP_SIZE");

    bprintf("\n// Detected address ranges:\n");
    int i;
    for(i=0; i<fw->adr_range_count; i++) {
        if(fw->adr_ranges[i].type == ADR_RANGE_ROM) {
            bprintf("// %-8s 0x%08x - 0x%08x (%7d bytes)\n",
                    adr_range_type_str(fw->adr_ranges[i].type),
                    fw->adr_ranges[i].start,
                    fw->adr_ranges[i].start+fw->adr_ranges[i].bytes,
                    fw->adr_ranges[i].bytes);
        } else {
            bprintf("// %-8s 0x%08x - 0x%08x copied from 0x%08x (%7d bytes)\n",
                    adr_range_type_str(fw->adr_ranges[i].type),
                    fw->adr_ranges[i].start,
                    fw->adr_ranges[i].start+fw->adr_ranges[i].bytes,
                    fw->adr_ranges[i].src_start,
                    fw->adr_ranges[i].bytes);
        }
    }
    add_blankline();
}

// print platform.h define, if not default value
void print_platform_misc_val_undef(const char *name, uint32_t def)
{
    misc_val_t *mv=get_misc_val(name);
    if(mv->val && mv->val != def) {
        bprintf("//#undef  %s\n",name);
        bprintf("//#define %s  0x%08x // Found @0x%08x\n",name,mv->val,mv->ref_adr);
    }
}

void output_platform_vals(firmware *fw) {
    bprintf("// Values below go in 'platform_camera.h':\n");
    bprintf("//#define CAM_DRYOS         1\n");
    if (fw->dryos_ver >= 39)
        bprintf("//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher\n");
    if (fw->dryos_ver >= 47)
        bprintf("//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher\n");

    print_platform_misc_val_undef("CAM_UNCACHED_BIT",0x10000000);

    add_blankline();
}

void print_misc_val_comment(const char *name)
{
    misc_val_t *mv=get_misc_val(name);
    if(!mv) {
        return;
    }
    // TODO legitimate 0 values might be possible, if so can add found bit
    if(!mv->val) {
        bprintf("// %s not found\n",name);
        return;
    }
    bprintf("// %s 0x%08x",name,mv->val);
    if(mv->offset) {
        bprintf(" (0x%x+0x%x)",mv->base,mv->offset);
    }
    if(mv->ref_adr) {
        bprintf(" Found @0x%08x",mv->ref_adr);
    }
    bprintf("\n");
}

typedef struct {
    int reg;
    uint32_t bit;
    uint32_t ev;
    uint32_t raw_info;
    int no_invert;
} physw_table_entry_t;

void get_physw_table_entry(firmware *fw, uint32_t adr, physw_table_entry_t *vals)
{
    uint32_t info=fw_u32(fw,adr);
    vals->raw_info=info;
    vals->ev=fw_u32(fw,adr+4);
    // taken from finsig_dryos print_physw_raw_vals
    vals->reg=(info >>5) & 7;
    vals->bit=(1 << (info & 0x1f));
    // vals->no_invert=(info >> 16) & 1;
    vals->no_invert=((info&0xff0000)==0x10000)?1:0;
}
uint32_t find_physw_table_entry(firmware *fw, uint32_t tadr, int tcount, uint32_t ev)
{
    int i;
    for(i=0; i<tcount; i++,tadr += 8) {
        if(fw_u32(fw,tadr+4) == ev) {
            return tadr;
        }
    }
    return 0;
}
// look for the first invalid looking entry
uint32_t find_physw_table_max(firmware *fw, uint32_t tadr, int max_count)
{
    int i;
    for(i=0; i<max_count; i++,tadr += 8) {
        physw_table_entry_t v;
        get_physw_table_entry(fw,tadr,&v);
        if(v.raw_info == 0 || v.raw_info == 0xFFFFFFFF || v.reg > 2) {
            return i;
        }
        // TODO could check that no event numbers (except -1) are repeated
    }
    return max_count;
}
void write_physw_event_table_dump(firmware *fw, uint32_t tadr, int tcount)
{
    FILE *f=fopen("physw_bits.txt","w");
    if(!f) {
        return;
    }
    fprintf(f,"physw_event_table dump (%d entries printed, may not all be valid)\n",tcount);
    fprintf(f,"address    info       event      index bit        non-inverted\n");
    int i;
    physw_table_entry_t v;

    for(i=0; i<tcount; i++,tadr += 8) {
        get_physw_table_entry(fw,tadr,&v);
        fprintf(f,"0x%08x 0x%08x 0x%08x %-5d 0x%08x %d\n",tadr,v.raw_info,v.ev,v.reg,v.bit,v.no_invert);
    }
    fclose(f);
}
void print_kval(firmware *fw, uint32_t tadr, int tcount, uint32_t ev, const char *name, const char *sfx)
{
    uint32_t adr=find_physw_table_entry(fw,tadr,tcount,ev);
    if(!adr) {
        return;
    }
    physw_table_entry_t v;
    get_physw_table_entry(fw,adr,&v);
    
    char fn[100], rn[100];
    strcpy(fn,name); strcat(fn,sfx);
    strcpy(rn,name); strcat(rn,"_IDX");

    bprintf("//#define %-20s0x%08x // Found @0x%08x, levent 0x%x%s\n",fn,v.bit,adr,v.ev,v.no_invert?" (non-inverted logic)":"");
    bprintf("//#define %-20s%d\n",rn,v.reg);

}

// key stuff copied from finsig_dryos.c
typedef struct {
    int         reg;
    uint32_t    bits;
    char        nm[32];
    uint32_t    fadr;
    uint32_t    ev;
    int         inv;
} kinfo;

int     kmask[3];
kinfo   key_info[100];
int     kcount = 0;
uint32_t kshutter_min_bits = 0xFFFFFFFF;

void add_kinfo(int r, uint32_t b, const char *nm, uint32_t adr, uint32_t ev, int inv)
{
    key_info[kcount].reg = r;
    key_info[kcount].bits = b;
    strcpy(key_info[kcount].nm, nm);
    key_info[kcount].fadr = adr;
    key_info[kcount].ev = ev;
    key_info[kcount].inv = inv;
    kcount++;
    kmask[r] |= b;
    if ((ev <= 1) && (b < kshutter_min_bits)) kshutter_min_bits = b;
}

uint32_t add_kmval(firmware *fw, uint32_t tadr, int tsiz, int tlen, uint32_t ev, const char *name, uint32_t xtra)
{
    uint32_t adr=find_physw_table_entry(fw,tadr,tlen,ev);
    if(!adr) {
        return 0;
    }
    physw_table_entry_t v;
    get_physw_table_entry(fw,adr,&v);

    add_kinfo(v.reg,v.bit|xtra,name,adr,v.ev,(v.no_invert)?0:1);
    return v.bit;
}

int kinfo_compare(const kinfo *p1, const kinfo *p2)
{
    if (p1->reg > p2->reg)
    {
        return 1;
    }
    else if (p1->reg < p2->reg)
    {
        return -1;
    }
    if ((p1->ev <= 1) && (p2->ev <= 1))    // output shutter entries in reverse order
    {
        if (p1->bits > p2->bits)
        {
            return -1;
        }
        else if (p1->bits < p2->bits)
        {
            return 1;
        }
    }
    // if one entry is shutter then compare to min shutter bits
    if (p1->ev <= 1)
    {
        if (kshutter_min_bits > p2->bits)
        {
            return 1;
        }
        else if (kshutter_min_bits < p2->bits)
        {
            return -1;
        }
    }
    if (p2->ev <= 1)
    {
        if (p1->bits > kshutter_min_bits)
        {
            return 1;
        }
        else if (p1->bits < kshutter_min_bits)
        {
            return -1;
        }
    }
    if (p1->bits > p2->bits)
    {
        return 1;
    }
    else if (p1->bits < p2->bits)
    {
        return -1;
    }

    return 0;
}

void print_kmvals()
{
    qsort(key_info, kcount, sizeof(kinfo), (void*)kinfo_compare);

    bprintf("//KeyMap keymap[] = {\n");

    int k;
    for (k=0; k<kcount; k++)
    {
        bprintf("//    { %d, %-20s,0x%08x }, // Found @0x%08x, levent 0x%02x%s\n",key_info[k].reg,key_info[k].nm,key_info[k].bits,key_info[k].fadr,key_info[k].ev,(key_info[k].inv==0)?"":" (uses inverted logic in physw_status)");
    }

    bprintf("//    { 0, 0, 0 }\n//};\n");
}

void do_km_vals(firmware *fw, uint32_t tadr,int tsiz,int tlen)
{
    uint32_t key_half = add_kmval(fw,tadr,tsiz,tlen,0,"KEY_SHOOT_HALF",0);
    add_kmval(fw,tadr,tsiz,tlen,1,"KEY_SHOOT_FULL",key_half);
    add_kmval(fw,tadr,tsiz,tlen,1,"KEY_SHOOT_FULL_ONLY",0);
    
    add_kmval(fw,tadr,tsiz,tlen,0x101,"KEY_PLAYBACK",0);
    add_kmval(fw,tadr,tsiz,tlen,0x100,"KEY_POWER",0); // unverified

    // TODO mostly copied from finsig_dryos, with < r52 stuff removed
    // unverified for others
    if (fw->dryos_ver == 52)  // unclear if this applies any other ver
    {
        add_kmval(fw,tadr,tsiz,tlen,3,"KEY_ZOOM_IN",0);
        add_kmval(fw,tadr,tsiz,tlen,4,"KEY_ZOOM_OUT",0);
        add_kmval(fw,tadr,tsiz,tlen,6,"KEY_UP",0);
        add_kmval(fw,tadr,tsiz,tlen,7,"KEY_DOWN",0);
        add_kmval(fw,tadr,tsiz,tlen,8,"KEY_LEFT",0);
        add_kmval(fw,tadr,tsiz,tlen,9,"KEY_RIGHT",0);
        add_kmval(fw,tadr,tsiz,tlen,0xA,"KEY_SET",0);
        add_kmval(fw,tadr,tsiz,tlen,0xB,"KEY_MENU",0);
        add_kmval(fw,tadr,tsiz,tlen,0xC,"KEY_DISPLAY",0);
        add_kmval(fw,tadr,tsiz,tlen,0x12,"KEY_HELP",0);
        add_kmval(fw,tadr,tsiz,tlen,0x19,"KEY_ERASE",0);
        add_kmval(fw,tadr,tsiz,tlen,2,"KEY_VIDEO",0);
    }
    else if (fw->dryos_ver < 54)
    {
        add_kmval(fw,tadr,tsiz,tlen,2,"KEY_ZOOM_IN",0);
        add_kmval(fw,tadr,tsiz,tlen,3,"KEY_ZOOM_OUT",0);
        add_kmval(fw,tadr,tsiz,tlen,4,"KEY_UP",0);
        add_kmval(fw,tadr,tsiz,tlen,5,"KEY_DOWN",0);
        add_kmval(fw,tadr,tsiz,tlen,6,"KEY_LEFT",0);
        add_kmval(fw,tadr,tsiz,tlen,7,"KEY_RIGHT",0);
        add_kmval(fw,tadr,tsiz,tlen,8,"KEY_SET",0);
        add_kmval(fw,tadr,tsiz,tlen,9,"KEY_MENU",0);
        add_kmval(fw,tadr,tsiz,tlen,0xA,"KEY_DISPLAY",0);
    }
    else if (fw->dryos_ver < 55)
    {
        add_kmval(fw,tadr,tsiz,tlen,3,"KEY_ZOOM_IN",0);
        add_kmval(fw,tadr,tsiz,tlen,4,"KEY_ZOOM_OUT",0);
        add_kmval(fw,tadr,tsiz,tlen,6,"KEY_UP",0);
        add_kmval(fw,tadr,tsiz,tlen,7,"KEY_DOWN",0);
        add_kmval(fw,tadr,tsiz,tlen,8,"KEY_LEFT",0);
        add_kmval(fw,tadr,tsiz,tlen,9,"KEY_RIGHT",0);
        add_kmval(fw,tadr,tsiz,tlen,0xA,"KEY_SET",0);
        add_kmval(fw,tadr,tsiz,tlen,0xE,"KEY_MENU",0);
        add_kmval(fw,tadr,tsiz,tlen,2,"KEY_VIDEO",0);
        add_kmval(fw,tadr,tsiz,tlen,0xD,"KEY_HELP",0);
        //add_kmval(fw,tadr,tsiz,tlen,?,"KEY_DISPLAY",0);
    }
    else
    {
        add_kmval(fw,tadr,tsiz,tlen,3,"KEY_ZOOM_IN",0);
        add_kmval(fw,tadr,tsiz,tlen,4,"KEY_ZOOM_OUT",0);
        add_kmval(fw,tadr,tsiz,tlen,6,"KEY_UP",0);
        add_kmval(fw,tadr,tsiz,tlen,7,"KEY_DOWN",0);
        add_kmval(fw,tadr,tsiz,tlen,8,"KEY_LEFT",0);
        add_kmval(fw,tadr,tsiz,tlen,9,"KEY_RIGHT",0);
        add_kmval(fw,tadr,tsiz,tlen,0xA,"KEY_SET",0);
        add_kmval(fw,tadr,tsiz,tlen,0x14,"KEY_MENU",0);
        add_kmval(fw,tadr,tsiz,tlen,2,"KEY_VIDEO",0);
        add_kmval(fw,tadr,tsiz,tlen,0xD,"KEY_HELP",0);
        //add_kmval(fw,tadr,tsiz,tlen,?,"KEY_DISPLAY",0);
    }

    bprintf("\n// Keymap values for kbd.c. Additional keys may be present, only common values included here.\n");
    bprintf("// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!\n");
    print_kmvals();
}
void output_physw_vals(firmware *fw) {
    print_misc_val_comment("physw_event_table");
    uint32_t physw_tbl=get_misc_val_value("physw_event_table");
    if(!physw_tbl) {
        return;
    }
    int physw_tbl_len=find_physw_table_max(fw,physw_tbl,50);
    write_physw_event_table_dump(fw,physw_tbl,physw_tbl_len);

    bprintf("// Values below go in 'platform_kbd.h':\n");
    print_kval(fw,physw_tbl,physw_tbl_len,0x20A,"SD_READONLY","_FLAG");
    print_kval(fw,physw_tbl,physw_tbl_len,0x202,"USB","_MASK");
    print_kval(fw,physw_tbl,physw_tbl_len,0x205,"BATTCOVER","_FLAG");
    print_kval(fw,physw_tbl,physw_tbl_len,0x204,"HOTSHOE","_FLAG");
    do_km_vals(fw,physw_tbl,2,physw_tbl_len);

    add_blankline();
}

/*
typedef struct
{
    uint16_t mode;
    char *nm;
} ModeMapName;


// TODO numbers changed after g1xmk2
// M=32770
ModeMapName mmnames[] = {
    { 32768,"MODE_AUTO" },
    { 32769,"MODE_M" },
    { 32770,"MODE_AV" },
    { 32771,"MODE_TV" },
    { 32772,"MODE_P" },

    { 65535,"" }
};

char* mode_name(uint16_t v)
{
    int i;
    for (i=0; mmnames[i].mode != 65535; i++)
    {
        if (mmnames[i].mode == v)
            return mmnames[i].nm;
    }

    return "";
}
*/


void output_modemap(firmware *fw) {
    print_misc_val_comment("canon_mode_list");
    bprintf("// Check modemap values from 'platform/CAMERA/shooting.c':\n");
    misc_val_t *mv=get_misc_val("canon_mode_list");
    if(!mv) {
        add_blankline();
        return;
    }
    int i;
    uint32_t adr=mv->val;
    int bad=0;
    for(i=0; i<50; i++,adr+=2) {
        uint16_t *pv=(uint16_t*)adr2ptr(fw,adr);
        if(!pv) {
            break;
        }
        if(*pv==0xFFFF) {
            break;
        }
        osig *m = find_sig_val(fw->sv->modemap, *pv);
        if (!m) {
            bprintf("// %5hu  0x%04hx In firmware but not in current modemap",*pv,*pv);
            /*
            char *s = mode_name(*pv);
            if (strcmp(s,"") != 0) {
                bprintf(" (%s)",s);
            }
            */
            bprintf("\n");
            bad++;
        } else {
//            bprintf("// %5hu  0x%04hx %s\n", *pv,*pv,m->nm);
            m->pct = 100;
        }
    }
    osig *m = fw->sv->modemap;
    while (m)
    {
        if (m->pct != 100)    // not matched above?
        {
            bprintf("// Current modemap entry not found in firmware - %-24s %5d\n",m->nm,m->val);
            bad++;
        }
        m = m->nxt;
    }
    if (bad == 0)
    {
        bprintf("// No problems found with modemap table.\n");
    }

    add_blankline();
}

// copied from finsig_dryos
int compare_sig_names(const sig_entry_t **p1, const sig_entry_t **p2)
{
    int rv = strcasecmp((*p1)->name, (*p2)->name);     // Case insensitive
    if (rv != 0)
        return rv;
    rv = strcmp((*p1)->name, (*p2)->name);          // Case sensitive (if equal with insensitive test)
    if (rv != 0)
        return rv;
    if ((*p1)->val < (*p2)->val)
        return -1;
    else if ((*p1)->val > (*p2)->val)
        return 1;
    return 0;
}

int compare_func_addresses(const sig_entry_t **p1, const sig_entry_t **p2)
{
    if ((*p1)->val < (*p2)->val)
        return -1;
    else if ((*p1)->val > (*p2)->val)
        return 1;
    return compare_sig_names(p1,p2);
}

void write_funcs(firmware *fw, char *filename, sig_entry_t *fns[], int (*compare)(const sig_entry_t **p1, const sig_entry_t **p2))
{
    int k;

    qsort(fns, next_sig_entry, sizeof(sig_entry_t*), (void*)compare);

    FILE *out_fp = fopen(filename, "w");
    for (k=0; k<next_sig_entry; k++)
    {
        if (strncmp(fns[k]->name,"hook_",5) == 0) {
            continue;
        }
        if (fns[k]->val != 0)
        {
            if (fns[k]->flags & BAD_MATCH)
            {
                osig* ostub2 = find_sig(fw->sv->stubs,fns[k]->name);
                if (ostub2 && ostub2->val)
                    fprintf(out_fp, "0x%08x,%s,(stubs_entry_2.s)\n", ostub2->val, fns[k]->name);
            }
            else
                fprintf(out_fp, "0x%08x,%s\n", fns[k]->val, fns[k]->name);
        }
#ifdef LIST_IMPORTANT_FUNCTIONS
        else if (fns[k]->flags & LIST_ALWAYS)
        {
            // helps development by listing important functions even when not found
            fprintf(out_fp, "0,%s,(NOT FOUND)\n", fns[k]->name);
        }
#endif
    }
    fclose(out_fp);
}
// end copy finsig_dryos
void write_func_lists(firmware *fw) {
    sig_entry_t *fns[MAX_SIG_ENTRY];
    int k;
    for (k=0; k<next_sig_entry; k++)
        fns[k] = &sig_names[k];

    write_funcs(fw, "funcs_by_name.csv", fns, compare_sig_names);
    write_funcs(fw, "funcs_by_address.csv", fns, compare_func_addresses);
}

void print_stubs_min_def(firmware *fw, misc_val_t *sig)
{
    if(sig->flags & MISC_VAL_NO_STUB) {
        return;
    }
    // find best match and report results
    osig* ostub2=find_sig(fw->sv->stubs_min,sig->name);

    const char *macro = "DEF";
    if(sig->flags & MISC_VAL_DEF_CONST) {
        macro="DEF_CONST";
    }

    if (ostub2)
    {
        bprintf("//%s(%-34s,0x%08x)",macro,sig->name,sig->val);
        if (sig->val != ostub2->val)
        {
            bprintf(", ** != ** stubs_min = 0x%08x (%s)",ostub2->val,ostub2->sval);
        }
        else
        {
            bprintf(",          stubs_min = 0x%08x (%s)",ostub2->val,ostub2->sval);
        }
    }
    else if(sig->base || sig->offset)
    {
        bprintf("%s(%-34s,0x%08x)",macro,sig->name,sig->val);
        if(sig->offset || sig->ref_adr) {
            bprintf(" //");
            if(sig->offset) {
                bprintf(" (0x%x+0x%x)",sig->base,sig->offset);
            }
            if(sig->ref_adr) {
                bprintf(" Found @0x%08x",sig->ref_adr);
            }
        }
    }
    else 
    {
        bprintf("// %s not found",sig->name);
    }
    bprintf("\n");
}

// Output match results for function
// matches stuff butchered out for now, just using value in sig_names table
void print_results(firmware *fw, sig_entry_t *sig)
{
    int i;
    int err = 0;
    char line[500] = "";

    if (sig->flags & DONT_EXPORT) {
        return;
    }

    // find best match and report results
    osig* ostub2 = find_sig(fw->sv->stubs,sig->name);

    if (ostub2 && (sig->val != ostub2->val))
    {
        if (ostub2->type != TYPE_IGNORE)
            err = 1;
       sig->flags |= BAD_MATCH;
    }
    else
    {
        if (sig->flags & UNUSED) return;
    }

    // write to header (if error) or body buffer (no error)
    out_hdr = err;

    char *macro = "NHSTUB";
    if (sig->flags & ARM_STUB) {
        macro = "NHSTUB2";
    }
    if (strncmp(sig->name,"task_",5) == 0 ||
        strncmp(sig->name,"hook_",5) == 0) macro = "   DEF";

    if (!sig->val && !ostub2)
    {
        if (sig->flags & OPTIONAL) return;
        char fmt[50] = "";
        sprintf(fmt, "// ERROR: %%s is not found. %%%ds//--- --- ", (int)(34-strlen(sig->name)));
        sprintf(line+strlen(line), fmt, sig->name, "");
    }
    else
    {
        if (ostub2 || (sig->flags & UNUSED))
            sprintf(line+strlen(line),"//%s(%-37s,0x%08x) //%3d ", macro, sig->name, sig->val, 0);
        else
            sprintf(line+strlen(line),"%s(%-39s,0x%08x) //%3d ", macro, sig->name, sig->val, 0);

        /*
        if (matches->fail > 0)
            sprintf(line+strlen(line),"%2d%% ", matches->success*100/(matches->success+matches->fail));
        else
            */
            sprintf(line+strlen(line),"    ");
    }

    if (ostub2)
    {
        if (ostub2->type == TYPE_IGNORE)
            sprintf(line+strlen(line),"       Overridden");
        else if (sig->val == ostub2->val)
            sprintf(line+strlen(line),"       == 0x%08x    ",ostub2->val);
        else {
            // if both have some value check if differs only by veneer
            if(sig->val && ostub2->val) {
                fw_disasm_iter_single(fw,ostub2->val);
                if(get_direct_jump_target(fw,fw->is) == sig->val) {
                    sprintf(line+strlen(line)," <-veneer 0x%08x    ",ostub2->val);
                } else {
                    fw_disasm_iter_single(fw,sig->val);
                    if(get_direct_jump_target(fw,fw->is) == ostub2->val) {
                        sprintf(line+strlen(line)," veneer-> 0x%08x    ",ostub2->val);
                    } else {
                        sprintf(line+strlen(line),"   *** != 0x%08x    ",ostub2->val);
                    }
                }
            } else {
                sprintf(line+strlen(line),"   *** != 0x%08x    ",ostub2->val);
            }
        }
    }
    else
        sprintf(line+strlen(line),"                        ");

    for (i=strlen(line)-1; i>=0 && line[i]==' '; i--) line[i] = 0;
    bprintf("%s\n",line);

    /*
    for (i=1;i<count && matches[i].fail==matches[0].fail;i++)
    {
        if (matches[i].ptr != matches->ptr)
        {
            bprintf("// ALT: %s(%s, 0x%x) // %d %d/%d\n", macro, curr_name, matches[i].ptr, matches[i].sig, matches[i].success, matches[i].fail);
        }
    }
    */
}

void write_stubs(firmware *fw,int max_find_func) {
    int k;
    bprintf("// Values below can be overridden in 'stubs_min.S':\n");
    misc_val_t *stub_min=misc_vals;
    while(stub_min->name) {
        print_stubs_min_def(fw,stub_min);
        stub_min++;
    }

    add_blankline();

    for (k = 0; k < max_find_func; k++)
    {
        print_results(fw,&sig_names[k]);
    }
}

int main(int argc, char **argv)
{
    clock_t t1 = clock();

    firmware fw;
    memset(&fw,0,sizeof(firmware));
    if (argc < 4) {
        fprintf(stderr,"finsig_thumb2 <primary> <base> <outputfilename>\n");
        exit(1);
    }

    for (next_sig_entry = 0; sig_names[next_sig_entry].name != 0; next_sig_entry++);
    int max_find_sig = next_sig_entry;

    fw.sv = new_stub_values();
    load_stubs(fw.sv, "stubs_entry_2.S", 1);
    load_stubs_min(fw.sv);
    load_modemap(fw.sv);

    bprintf("// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!\n");
    bprintf("#include \"stubs_asm.h\"\n\n");

    firmware_load(&fw,argv[1],strtoul(argv[2], NULL, 0),FW_ARCH_ARMv7);
    if(!firmware_init_capstone(&fw)) {
        exit(1);
    }
    firmware_init_data_ranges(&fw);

    out_fp = fopen(argv[3],"w");
    if (out_fp == NULL) {
        fprintf(stderr,"Error opening output file %s\n",argv[3]);
        exit(1);
    }
    

    // find ctypes - used for code search limit
    fw_search_bytes(&fw, find_ctypes);

    run_sig_rules(&fw,sig_rules_initial);
    find_generic_funcs(&fw);
    run_sig_rules(&fw,sig_rules_main);

    output_firmware_vals(&fw);

    output_platform_vals(&fw);
    output_physw_vals(&fw);
    output_modemap(&fw);

    write_stubs(&fw,max_find_sig);

    write_output();
    fclose(out_fp);

    write_func_lists(&fw);

    firmware_unload(&fw);

    clock_t t2 = clock();

    printf("Time to generate stubs %.2f seconds\n",(double)(t2-t1)/(double)CLOCKS_PER_SEC);

    return 0;
}
