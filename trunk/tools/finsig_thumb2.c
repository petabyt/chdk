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
// TODO doesn't really belong in funcs
#define STUBSMIN_DEF   0x40

typedef struct {
    char        *name;
    int         flags;
    uint32_t    val;
} func_entry;

int next_func_entry = 0;

#define MAX_FUNC_ENTRY  5000

func_entry  func_names[MAX_FUNC_ENTRY] =
{
    // Do these first as they are needed to find others
    { "ctypes", STUBSMIN_DEF },
    { "ExportToEventProcedure_FW", UNUSED|DONT_EXPORT },
    { "RegisterEventProcedure", UNUSED|DONT_EXPORT },
    { "RegisterEventProcedure_alt1", UNUSED|DONT_EXPORT },
    { "RegisterEventProcedure_alt2", UNUSED|DONT_EXPORT },
    { "RegisterEventProcTable", UNUSED|DONT_EXPORT },
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
    { "ExecuteEventProcedure" },
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
    { "mkdir" },
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

    { "EngDrvIn", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "EngDrvOut", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "EngDrvRead" },
    { "EngDrvBits", OPTIONAL|UNUSED|LIST_ALWAYS },

    { "PTM_GetCurrentItem" },
    { "PTM_SetCurrentItem", UNUSED|LIST_ALWAYS },
    { "PTM_NextItem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PTM_PrevItem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PTM_SetPropertyEnable", OPTIONAL|UNUSED|LIST_ALWAYS },

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

    { "MFOn", OPTIONAL },
    { "MFOff", OPTIONAL },
    { "PT_MFOn", OPTIONAL },
    { "PT_MFOff", OPTIONAL },
    { "SS_MFOn", OPTIONAL },
    { "SS_MFOff", OPTIONAL },

    { "GetAdChValue", OPTIONAL },

    { "physw_run", STUBSMIN_DEF },
    { "physw_sleep_delay", STUBSMIN_DEF },
    { "physw_status", STUBSMIN_DEF },
    { "fileio_semaphore", STUBSMIN_DEF },

    {0,0,0},
};

// Return the array index of a named function in the array above
int find_saved_sig(const char *name)
{
    int i;
    for (i=0; func_names[i].name != 0; i++)
    {
        if (strcmp(name,func_names[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Save the address value found for a function in the above array
void save_sig(const char *name, uint32_t val)
{
    int i = find_saved_sig(name);
    if (i >= 0)
    {
        func_names[i].val = val;
    }
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

    for (k=0; func_names[k].name != 0; k++)
    {
        if (strcmp(func_names[k].name, s) == 0)
        {
            if (func_names[k].val == 0)             // same name, no address
            {
                func_names[k].val = eadr;
                func_names[k].flags |= EV_MATCH;
                return;
            }
            else if (func_names[k].val == eadr)     // same name, same address
            {
                return;
            }
        }
    }

    func_names[next_func_entry].name = s;
    func_names[next_func_entry].flags = OPTIONAL|UNUSED;
    func_names[next_func_entry].val = eadr;
    next_func_entry++;
    func_names[next_func_entry].name = 0;
}

// save sig, with up to one level veneer added as j_...
void save_sig_with_j(firmware *fw, char *name, uint32_t adr)
{
    // attempt to disassemble target
    if(!fw_disasm_iter_single(fw,adr)) {
        printf("save_sig_with_j: %s disassembly failed at 0x%08x\n",name,adr);
        return;
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
}


typedef struct sig_rule_s sig_rule_t;
typedef int (*sig_match_fn)(firmware *fw, iter_state_t *is, sig_rule_t *rule);
// signature matching structure
typedef struct sig_rule_s {
    sig_match_fn    match_fn;       // function to locate function
    char        *name;              // function name used in CHDK
    char        *ref_name;          // event / other name to match in the firmware
    int         param;              // function specific param/offset
    // DryOS version specific params / offsets
    int         dryos52_param; // ***** UPDATE for new DryOS version *****
    int         dryos54_param;
    int         dryos55_param;
    int         dryos57_param;
    int         dryos58_param;
} sig_rule_t;

// Get DryOS version specific param
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

// match 
// r0=ref value
//...
// bl=<our func>
int sig_match_str_r0_call(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    uint32_t adr=0;
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
                adr=is->insn->detail->arm.operands[0].imm;
                if(is->insn->id != ARM_INS_BLX) {
                    // if not a BLX, thumb address (TODO assumes search was on thumb code, currently valid)
                    adr=ADR_SET_THUMB(adr);
                }
                // printf("sig_match_str_r0_call: thumb %s call 0x%08x\n",rule->name,adr);
                save_sig_with_j(fw,rule->name,adr);
            }
        }
    }
    return (adr != 0);
}

// find RegisterEventProcedure
int sig_match_reg_evp(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    static insn_match_t reg_evp_match[]={
        {ARM_INS_MOV,2,{{ARM_OP_REG,ARM_REG_R2},{ARM_OP_REG,ARM_REG_R1}}},
        {ARM_INS_LDR,2,{{ARM_OP_REG,ARM_REG_R1},{ARM_OP_MEM,ARM_REG_INVALID}}},
        {ARM_INS_B,1,{{ARM_OP_IMM,ARM_REG_INVALID}}},
        {ARM_INS_ENDING}
    };

    int i=find_saved_sig("ExportToEventProcedure_FW");

    if(i==-1) {
        printf("sig_match_reg_evp: failed to find ExportToEventProcedure, giving up\n");
        return 0;
    }
    uint32_t e_to_evp=func_names[i].val;  

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
    uint32_t str_adr = find_str_bytes(fw,"DispDev_EnableEventProc"); // note this string may appear more than once, assuming want first
    if(!str_adr) {
        printf("sig_match_reg_evp_table: failed to find DispDev_EnableEventProc\n");
        return 0;
    }
    //printf("sig_match_reg_evp_table: DispDev_EnableEventProc 0x%08x\n",str_adr);
    uint32_t reg_evp_alt1=0;
    uint32_t reg_evp_tbl=0;
    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    uint32_t dd_enable_p=0;
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
            if(insn_match_find_next(fw,is,2,match_b_bl)) {
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
    uint32_t str_adr = find_str_bytes(fw,"EngApp.Delete");
    if(!str_adr) {
        printf("sig_match_reg_evp_alt2: failed to find EngApp.Delete\n");
        return 0;
    }
    //printf("sig_match_reg_evp_alt2: EngApp.Delete 0x%08x\n",str_adr);
    uint32_t reg_evp_alt1=0;
    int i=find_saved_sig("RegisterEventProcedure_alt1");
    if(i != -1) {
        reg_evp_alt1=func_names[i].val;
    }

    disasm_iter_init(fw,is,(ADR_ALIGN4(str_adr) - SEARCH_NEAR_REF_RANGE) | fw->thumb_default); // reset to a bit before where the string was found
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+SEARCH_NEAR_REF_RANGE)) {
        if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
            if(insn_match_find_next(fw,is,3,match_b_bl)) {
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
        }
    }
    return (reg_evp_alt2 != 0);
}

// TODO this finds multiple values in PhySwTask main function
int sig_match_physw_misc(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    int i=find_saved_sig("task_PhySw");
    if(i == -1) {
        printf("sig_match_physw_misc: missing task_PhySw\n");
        return 0;
    }
    // look for physw_run (first value in physw_task struct)
    disasm_iter_init(fw,is,func_names[i].val);
    uint32_t physw_run=0;
    for(i=0; i<3; i++) {
        if(!disasm_iter(fw,is)) {
            printf("sig_match_physw_misc: disasm failed\n");
            return 0;
        }
        physw_run=LDR_PC2val(fw,is->insn);
        if(physw_run) {
            if(adr_is_var(fw,physw_run)) {
                save_sig("physw_run",physw_run);
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
    i=find_saved_sig("SleepTask");
    if(i==-1) {
        printf("sig_match_physw_misc: missing SleepTask\n");
        return 0;
    }
    uint32_t sleeptask=func_names[i].val;
    uint32_t f=get_branch_call_insn_target(fw,is);

    // call wasn't direct, check for veneer
    if(f != sleeptask) {
        fw_disasm_iter_single(fw,f);
        f=get_direct_jump_target(fw,fw->is);
        if(f != sleeptask) {
            return 0;
        }
        // TODO sleeptask veneer is useful for xref
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
    save_sig("physw_sleep_delay",physw_run + is->insn->detail->arm.operands[1].mem.disp);
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
    int i=find_saved_sig("kbd_p1_f");
    if(i == -1) {
        printf("sig_match_kbd_read_keys: missing kbd_p1_f\n");
        return 0;
    }
    disasm_iter_init(fw,is,func_names[i].val);
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
        save_sig("physw_status",physw_status);
        save_sig("kbd_p1_f_cont",(uint32_t)(is->insn->address) | is->thumb);
        return 1;
    }
    return 0;
}

// TODO also finds kbd_read_keys_r2
int sig_match_get_kbd_state(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    int i=find_saved_sig("kbd_read_keys");
    if(i == -1) {
        printf("sig_match_get_kbd_state: missing kbd_read_keys\n");
        return 0;
    }
    disasm_iter_init(fw,is,func_names[i].val);
    // look for GetKbdState
    if(!insn_match_find_next(fw,is,11,match_bl_blximm)) {
        return 0;
    }
    save_sig("GetKbdState",get_branch_call_insn_target(fw,is));
    // look for kbd_read_keys_r2
    if(!insn_match_find_next(fw,is,5,match_b_bl_blximm)) {
        return 0;
    }
    save_sig("kbd_read_keys_r2",get_branch_call_insn_target(fw,is));
    return 1;
}

int sig_match_create_jumptable(firmware *fw, iter_state_t *is, sig_rule_t *rule)
{
    int i=find_saved_sig("InitializeAdjustmentSystem_FW");
    if(i == -1) {
        printf("sig_match_create_jumptable: missing InitializeAdjustmentSystem_FW\n");
        return 0;
    }
    disasm_iter_init(fw,is,func_names[i].val);
    // find second function call
    if(!insn_match_find_next(fw,is,10,match_bl_blximm)) {
        return 0;
    }
    if(!insn_match_find_next(fw,is,10,match_bl_blximm)) {
        return 0;
    }
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
    int i=find_saved_sig("Fopen_Fut");
    if(i == -1) {
        printf("sig_match_take_semaphore_strict: missing Fopen_Fut\n");
        return 0;
    }
    disasm_iter_init(fw,is,func_names[i].val);
    // find first function call
    if(!insn_match_find_next(fw,is,6,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // find second call
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        return 0;
    }
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        return 0;
    }
    // follow
    disasm_iter_init(fw,is,get_branch_call_insn_target(fw,is));
    // skip two calls
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        return 0;
    }
    if(!insn_match_find_next(fw,is,5,match_bl_blximm)) {
        return 0;
    }
    // next one should be DebugAssert
    if(!insn_match_find_next(fw,is,10,match_bl_blximm)) {
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
    save_sig("fileio_semaphore",sem_adr);
    // look for next call: GetDrive_FreeClusters
    if(!insn_match_find_next(fw,is,10,match_bl_blximm)) {
        return 0;
    }
    save_sig_with_j(fw,"GetDrive_FreeClusters",get_branch_call_insn_target(fw,is));
    return 1;
}

// default - use the named firmware function
#define SIG_NAMED_ASIS        0
// use the target of the first B, BX, BL, BLX etc
#define SIG_NAMED_JMP_SUB     1
// use the target of the first BL, BLX
#define SIG_NAMED_SUB         2
#define SIG_NAMED_TYPE_MASK  0xFF

#define SIG_NAMED_CLEARTHUMB 0x100
#define SIG_NAMED_FLAG_MASK  0xFF00

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
    int i=find_saved_sig(rule->ref_name);
    uint32_t sig_type = rule->param & SIG_NAMED_TYPE_MASK;
    uint32_t sig_flags = rule->param & SIG_NAMED_FLAG_MASK;
    if(i==-1) {
        printf("sig_match_named: %s function not found\n",rule->ref_name);
        return 0;
    }
    uint32_t ref_adr = func_names[i].val;
    if(!ref_adr) {
        printf("sig_match_named: %s address not found\n",rule->ref_name);
        return 0;
    }
    // no offset, just save match as is
    // TODO might want to validate anyway
    if(sig_type == SIG_NAMED_ASIS) {
        sig_match_named_save_sig(rule->name,func_names[i].val,sig_flags); 
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
    if(insn_match_find_next(fw,is,20,insn_match)) {
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

// bootstrap sigs
// order is important
sig_rule_t sig_rules_initial[]={
// function         CHDK name                   ref name/string         func param  dry52   dry54   dry55   dry57   dry58
// NOTE _FW is in the CHDK column, because that's how it is in func_names
{sig_match_str_r0_call, "ExportToEventProcedure_FW",   "ExportToEventProcedure"},
{sig_match_reg_evp,     "RegisterEventProcedure",},
{sig_match_reg_evp_table, "RegisterEventProcTable",},
{sig_match_reg_evp_alt2, "RegisterEventProcedure_alt2",},
{sig_match_str_r0_call,"CreateTaskStrictly",    "FileWriteTask",},
{sig_match_str_r0_call,"CreateTask",            "EvShel",},
{NULL},
};

sig_rule_t sig_rules_main[]={
// function         CHDK name                   ref name/string         func param  dry52   dry54   dry55   dry57   dry58
{sig_match_named,   "ExitTask",                 "ExitTask_FW",},
{sig_match_named,   "EngDrvRead",               "EngDrvRead_FW",        SIG_NAMED_JMP_SUB},
{sig_match_named,   "Close",                    "Close_FW",},
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
{sig_match_named,   "SetScriptMode",            "SetScriptMode_FW",},
{sig_match_named,   "SleepTask",                "SleepTask_FW",},
{sig_match_named,   "SetPropertyCase",          "SetPropertyCase_FW",   SIG_NAMED_SUB},
{sig_match_named,   "TakeSemaphore",            "TakeSemaphore_FW",},
{sig_match_named,   "TurnOnDisplay",            "DispCon_TurnOnDisplay_FW",},
{sig_match_named,   "TurnOffDisplay",           "DispCon_TurnOffDisplay_FW",},
{sig_match_named,   "UIFS_WriteFirmInfoToFile", "UIFS_WriteFirmInfoToFile_FW",},
{sig_match_named,   "UnlockAE",                 "SS.UnlockAE_FW",       SIG_NAMED_JMP_SUB},
{sig_match_named,   "UnlockAF",                 "SS.UnlockAF_FW",       SIG_NAMED_JMP_SUB},
{sig_match_named,   "UnlockMainPower",          "UnlockMainPower_FW",},
//{sig_match_named,   "UnsetZoomForMovie",        "UnsetZoomForMovie_FW",},
{sig_match_named,   "VbattGet",                 "VbattGet_FW",},
{sig_match_named,   "Write",                    "Write_FW",},
{sig_match_named,   "exmem_free",               "ExMem.FreeCacheable_FW",SIG_NAMED_JMP_SUB},
{sig_match_named,   "exmem_alloc",              "ExMem.AllocCacheable_FW",SIG_NAMED_JMP_SUB},
{sig_match_named,   "free",                     "FreeMemory_FW",        SIG_NAMED_JMP_SUB},
{sig_match_named,   "lseek",                    "Lseek_FW",},
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
{sig_match_named,   "vsprintf",                   "sprintf_FW",         SIG_NAMED_SUB},
{sig_match_named, "PTM_GetCurrentItem",         "PTM_GetCurrentItem_FW",},
// TODO assumes CreateTask is in RAM, doesn't currently check
{sig_match_named, "hook_CreateTask",            "CreateTask",           SIG_NAMED_CLEARTHUMB},
{sig_match_physw_misc, "physw_misc",},
{sig_match_kbd_read_keys, "kbd_read_keys",},
{sig_match_get_kbd_state, "GetKbdState",},
{sig_match_create_jumptable, "CreateJumptable",},
{sig_match_take_semaphore_strict, "TakeSemaphoreStrictly",},
{NULL},
};

void run_sig_rules(firmware *fw, sig_rule_t *sig_rules)
{
    sig_rule_t *rule=sig_rules;
    // for convenience, pass an iter_state to match fns so they don't have to manage
    iter_state_t *is=disasm_iter_new(fw,0);
    while(rule->match_fn) {
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
int process_reg_eventproc_table_call(firmware *fw, iter_state_t *is,uint32_t unused) {
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
            printf("failed to get RegisterEventProcTable arg 0x%08x at 0x%"PRIx64"\n",regs[0],is->insn->address);
        }
    } else {
        printf("failed to get RegisterEventProcTable r0 at 0x%"PRIx64"\n",is->insn->address);
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

/*
collect as many calls as possible of functions identified by name, whether or not listed in funcs to find
*/
void find_generic_funcs(firmware *fw) {
    search_calls_multi_data_t match_fns[10];

    int match_fn_count=0;

    int i=find_saved_sig("ExportToEventProcedure_FW");

    if(i==-1) {
        printf("failed to find ExportToEventProcedure\n");
    } else {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_reg_eventproc_call;
        match_fn_count++;
    }
    i=find_saved_sig("RegisterEventProcedure_alt1");

    if(i==-1) {
        printf("failed to find RegisterEventProcedure_alt1\n");
    } else {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_reg_eventproc_call;
        match_fn_count++;
    }

    i=find_saved_sig("RegisterEventProcTable");

    if(i==-1) {
        printf("failed to find RegisterEventProcTable\n");
    } else {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_reg_eventproc_table_call;
        match_fn_count++;
    }

    i=find_saved_sig("RegisterEventProcedure_alt2");
    if(i==-1) {
        printf("failed to find RegisterEventProcedure_alt2\n");
    } else {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_reg_eventproc_call;
        match_fn_count++;
    }

    i=find_saved_sig("CreateTaskStrictly");
    if(i==-1) {
        printf("failed to find CreateTaskStrictly\n");
    } else {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_createtask_call;
        match_fn_count++;
    }
    // if veneer exists, use that too
    i=find_saved_sig("j_CreateTaskStrictly");
    if(i!=-1) {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_createtask_call;
        match_fn_count++;
    }
    i=find_saved_sig("CreateTask");
    if(i==-1) {
        printf("failed to find CreateTask\n");
    } else {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_createtask_call;
        match_fn_count++;
    }
    // if veneer exists, use that too
    i=find_saved_sig("j_CreateTask");
    if(i!=-1) {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(func_names[i].val);
        match_fns[match_fn_count].fn=process_createtask_call;
        match_fn_count++;
    }

    iter_state_t *is=disasm_iter_new(fw,0);

    match_fns[match_fn_count].adr=0;
    match_fns[match_fn_count].fn=NULL;

    disasm_iter_init(fw,is,fw->rom_code_search_min_adr | fw->thumb_default); // reset to start of fw
    fw_search_insn(fw,is,search_disasm_calls_multi,0,match_fns,0);

    /*
    // currently nothing useful
    for(i=0;i<fw->adr_range_count;i++) {
        if(fw->adr_ranges[i].type != ADR_RANGE_RAM_CODE) {
            continue;
        }
        disasm_iter_init(fw,is,fw->adr_ranges[i].start | fw->thumb_default); // reset to start of fw
        fw_search_insn(fw,is,search_disasm_calls_multi,0,match_fns,0);
    }
    */

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
            save_sig("ctypes",fw->base + k); 
            // use ctypes as max search address for non-copied / relocated code. 
            // seems to be true on current firmwares
            fw->rom_code_search_max_adr = fw->base + k;
            return 1;
        }
    }
    return 0;
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
// copied from finsig_dryos
int compare_func_names(const func_entry **p1, const func_entry **p2)
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

int compare_func_addresses(const func_entry **p1, const func_entry **p2)
{
    if ((*p1)->val < (*p2)->val)
        return -1;
    else if ((*p1)->val > (*p2)->val)
        return 1;
    return compare_func_names(p1,p2);
}

void write_funcs(firmware *fw, char *filename, func_entry *fns[], int (*compare)(const func_entry **p1, const func_entry **p2))
{
    int k;

    qsort(fns, next_func_entry, sizeof(func_entry*), (void*)compare);

    FILE *out_fp = fopen(filename, "w");
    for (k=0; k<next_func_entry; k++)
    {
        if(fns[k]->flags & STUBSMIN_DEF) {
            continue;
        }
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
    func_entry *fns[MAX_FUNC_ENTRY];
    int k;
    for (k=0; k<next_func_entry; k++)
        fns[k] = &func_names[k];

    write_funcs(fw, "funcs_by_name.csv", fns, compare_func_names);
    write_funcs(fw, "funcs_by_address.csv", fns, compare_func_addresses);
}

void print_stubs_min_def(firmware *fw, int k)
{
    if (!(func_names[k].flags & STUBSMIN_DEF)) {
        return;
    }
    // find best match and report results
    const char *curr_name = func_names[k].name;
    osig* ostub2=find_sig(fw->sv->stubs_min,curr_name);
    // TODO should be DEF_CONST for some
    const char *macro = "DEF";
    // TODO should save a ref address to print with stubs
    if (ostub2)
    {
        bprintf("//%s(%-34s,0x%08x)",macro,curr_name,func_names[k].val);
        if (func_names[k].val != ostub2->val)
        {
            bprintf(", ** != ** stubs_min = 0x%08x (%s)",ostub2->val,ostub2->sval);
        }
        else
        {
            bprintf(",          stubs_min = 0x%08x (%s)",ostub2->val,ostub2->sval);
        }
    }
    else
    {
        bprintf("%s(%-34s,0x%08x)",macro,curr_name,func_names[k].val);
    }
    bprintf("\n");
}

// Output match results for function
// matches stuff butchered out for now, just using value in func_names table
void print_results(firmware *fw, const char *curr_name, int k)
{
    int i;
    int err = 0;
    char line[500] = "";

    if (func_names[k].flags & DONT_EXPORT) {
        return;
    }

    // listed separately 
    if (func_names[k].flags & STUBSMIN_DEF) {
        return;
    }

    // find best match and report results
    osig* ostub2 = find_sig(fw->sv->stubs,curr_name);

    if (ostub2 && (func_names[k].val != ostub2->val))
    {
        if (ostub2->type != TYPE_IGNORE)
            err = 1;
        func_names[k].flags |= BAD_MATCH;
    }
    else
    {
        if (func_names[k].flags & UNUSED) return;
    }

    // write to header (if error) or body buffer (no error)
    out_hdr = err;

    char *macro = "NHSTUB";
    if (strncmp(curr_name,"task_",5) == 0 ||
        strncmp(curr_name,"hook_",5) == 0) macro = "   DEF";

    if (!func_names[k].val && !ostub2)
    {
        if (func_names[k].flags & OPTIONAL) return;
        char fmt[50] = "";
        sprintf(fmt, "// ERROR: %%s is not found. %%%ds//--- --- ", (int)(34-strlen(curr_name)));
        sprintf(line+strlen(line), fmt, curr_name, "");
    }
    else
    {
        if (ostub2 || (func_names[k].flags & UNUSED))
            sprintf(line+strlen(line),"//%s(%-37s,0x%08x) //%3d ", macro, curr_name, func_names[k].val, 0);
        else
            sprintf(line+strlen(line),"%s(%-39s,0x%08x) //%3d ", macro, curr_name, func_names[k].val, 0);

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
        else if (func_names[k].val == ostub2->val)
            sprintf(line+strlen(line),"       == 0x%08x    ",ostub2->val);
        else
            sprintf(line+strlen(line),"   *** != 0x%08x    ",ostub2->val);
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
    for (k = 0; k < max_find_func; k++)
    {
        if(func_names[k].flags & STUBSMIN_DEF) {
            print_stubs_min_def(fw,k);
        }
    }

    add_blankline();

    for (k = 0; k < max_find_func; k++)
    {
        const char *curr_name = func_names[k].name;
        print_results(fw,curr_name,k);
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

    for (next_func_entry = 0; func_names[next_func_entry].name != 0; next_func_entry++);
    int max_find_func = next_func_entry;

    fw.sv = new_stub_values();
    load_stubs(fw.sv, "stubs_entry_2.S", 1);
    load_stubs_min(fw.sv);

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
    
    output_firmware_vals(&fw);

    // find ctypes - used for code search limit
    fw_search_bytes(&fw, find_ctypes);

    run_sig_rules(&fw,sig_rules_initial);
    find_generic_funcs(&fw);
    run_sig_rules(&fw,sig_rules_main);
    write_stubs(&fw,max_find_func);

    write_output();
    fclose(out_fp);

    write_func_lists(&fw);

    firmware_unload(&fw);

    clock_t t2 = clock();

    printf("Time to generate stubs %.2f seconds\n",(double)(t2-t1)/(double)CLOCKS_PER_SEC);

    return 0;
}
