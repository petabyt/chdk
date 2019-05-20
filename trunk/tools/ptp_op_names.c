#include <stdint.h>
#include "ptp_op_names.h"

typedef struct {
    const char *name;
    uint32_t op;
} ptp_op_name_t;

// names from libgphoto2
// https://github.com/gphoto/libgphoto2/blob/master/camlibs/ptp2/ptp.h as of May 18 2019
// commented out items with just a number, since we auto-name those already
ptp_op_name_t ptp_op_names[]={
/* PTP v1.0 operation codes */
{"PTP_OC_Undefined",                0x1000},
{"PTP_OC_GetDeviceInfo",            0x1001},
{"PTP_OC_OpenSession",              0x1002},
{"PTP_OC_CloseSession",             0x1003},
{"PTP_OC_GetStorageIDs",            0x1004},
{"PTP_OC_GetStorageInfo",           0x1005},
{"PTP_OC_GetNumObjects",            0x1006},
{"PTP_OC_GetObjectHandles",         0x1007},
{"PTP_OC_GetObjectInfo",            0x1008},
{"PTP_OC_GetObject",                0x1009},
{"PTP_OC_GetThumb",                 0x100A},
{"PTP_OC_DeleteObject",             0x100B},
{"PTP_OC_SendObjectInfo",           0x100C},
{"PTP_OC_SendObject",               0x100D},
{"PTP_OC_InitiateCapture",          0x100E},
{"PTP_OC_FormatStore",              0x100F},
{"PTP_OC_ResetDevice",              0x1010},
{"PTP_OC_SelfTest",                 0x1011},
{"PTP_OC_SetObjectProtection",      0x1012},
{"PTP_OC_PowerDown",                0x1013},
{"PTP_OC_GetDevicePropDesc",        0x1014},
{"PTP_OC_GetDevicePropValue",       0x1015},
{"PTP_OC_SetDevicePropValue",       0x1016},
{"PTP_OC_ResetDevicePropValue",     0x1017},
{"PTP_OC_TerminateOpenCapture",     0x1018},
{"PTP_OC_MoveObject",               0x1019},
{"PTP_OC_CopyObject",               0x101A},
{"PTP_OC_GetPartialObject",         0x101B},
{"PTP_OC_InitiateOpenCapture",      0x101C},
/* PTP v1.1 operation codes */
{"PTP_OC_StartEnumHandles",         0x101D},
{"PTP_OC_EnumHandles",              0x101E},
{"PTP_OC_StopEnumHandles",          0x101F},
{"PTP_OC_GetVendorExtensionMaps",   0x1020},
{"PTP_OC_GetVendorDeviceInfo",      0x1021},
{"PTP_OC_GetResizedImageObject",    0x1022},
{"PTP_OC_GetFilesystemManifest",    0x1023},
{"PTP_OC_GetStreamInfo",            0x1024},
{"PTP_OC_GetStream",                0x1025},

/* Canon extension Operation Codes */
{"PTP_OC_CANON_GetPartialObjectInfo",0x9001},
{"PTP_OC_CANON_SetObjectArchive",   0x9002},
{"PTP_OC_CANON_KeepDeviceOn",       0x9003},
{"PTP_OC_CANON_LockDeviceUI",       0x9004},
{"PTP_OC_CANON_UnlockDeviceUI",     0x9005},
{"PTP_OC_CANON_GetObjectHandleByName",0x9006},
{"PTP_OC_CANON_InitiateReleaseControl",0x9008},
{"PTP_OC_CANON_TerminateReleaseControl",0x9009},
{"PTP_OC_CANON_TerminatePlaybackMode",0x900A},
{"PTP_OC_CANON_ViewfinderOn",       0x900B},
{"PTP_OC_CANON_ViewfinderOff",      0x900C},
{"PTP_OC_CANON_DoAeAfAwb",          0x900D},
{"PTP_OC_CANON_GetCustomizeSpec",   0x900E},
{"PTP_OC_CANON_GetCustomizeItemInfo",0x900F},
{"PTP_OC_CANON_GetCustomizeData",   0x9010},
{"PTP_OC_CANON_SetCustomizeData",   0x9011},
{"PTP_OC_CANON_GetCaptureStatus",   0x9012},
{"PTP_OC_CANON_CheckEvent",         0x9013},
{"PTP_OC_CANON_FocusLock",          0x9014},
{"PTP_OC_CANON_FocusUnlock",        0x9015},
{"PTP_OC_CANON_GetLocalReleaseParam",0x9016},
{"PTP_OC_CANON_SetLocalReleaseParam",0x9017},
{"PTP_OC_CANON_AskAboutPcEvf",      0x9018},
{"PTP_OC_CANON_SendPartialObject",  0x9019},
{"PTP_OC_CANON_InitiateCaptureInMemory",0x901A},
{"PTP_OC_CANON_GetPartialObjectEx", 0x901B},
{"PTP_OC_CANON_SetObjectTime",      0x901C},
{"PTP_OC_CANON_GetViewfinderImage", 0x901D},
{"PTP_OC_CANON_GetObjectAttributes",0x901E},
{"PTP_OC_CANON_ChangeUSBProtocol",  0x901F},
{"PTP_OC_CANON_GetChanges",         0x9020},
{"PTP_OC_CANON_GetObjectInfoEx",    0x9021},
{"PTP_OC_CANON_InitiateDirectTransfer",0x9022},
{"PTP_OC_CANON_TerminateDirectTransfer",0x9023},
{"PTP_OC_CANON_SendObjectInfoByPath",0x9024},
{"PTP_OC_CANON_SendObjectByPath",   0x9025},
{"PTP_OC_CANON_InitiateDirectTansferEx",0x9026},
{"PTP_OC_CANON_GetAncillaryObjectHandles",0x9027},
{"PTP_OC_CANON_GetTreeInfo",        0x9028},
{"PTP_OC_CANON_GetTreeSize",        0x9029},
{"PTP_OC_CANON_NotifyProgress",     0x902A},
{"PTP_OC_CANON_NotifyCancelAccepted",0x902B},
//{"PTP_OC_CANON_902C",               0x902C},
{"PTP_OC_CANON_GetDirectory",       0x902D},
//{"PTP_OC_CANON_902E",               0x902E},
//{"PTP_OC_CANON_902F",               0x902F},    /* used during camera init */
{"PTP_OC_CANON_SetPairingInfo",     0x9030},
{"PTP_OC_CANON_GetPairingInfo",     0x9031},
{"PTP_OC_CANON_DeletePairingInfo",  0x9032},
{"PTP_OC_CANON_GetMACAddress",      0x9033}, /* no args */
{"PTP_OC_CANON_SetDisplayMonitor",  0x9034},
{"PTP_OC_CANON_PairingComplete",    0x9035},
{"PTP_OC_CANON_GetWirelessMAXChannel",0x9036},
{"PTP_OC_CANON_GetWebServiceSpec",  0x9068}, /* no args */
{"PTP_OC_CANON_GetWebServiceData",  0x9069}, /* no args */
{"PTP_OC_CANON_SetWebServiceData",  0x906A},
{"PTP_OC_CANON_DeleteWebServiceData",0x906B},
{"PTP_OC_CANON_GetRootCertificateSpec",0x906C}, /* no args */
{"PTP_OC_CANON_GetRootCertificateData",0x906D}, /* no args */
{"PTP_OC_CANON_SetRootCertificateData",0x906F},
{"PTP_OC_CANON_GetGpsMobilelinkObjectInfo",0x9075}, /* 2 args: utcstart, utcend */
{"PTP_OC_CANON_SendGpsTagInfo",     0x9076}, /* 1 arg: oid */
{"PTP_OC_CANON_GetTranscodeApproxSize",0x9077}, /* 1 arg: oid? */
{"PTP_OC_CANON_RequestTranscodeStart",0x9078}, /* 1 arg: oid? */
{"PTP_OC_CANON_RequestTranscodeCancel",0x9079}, /* 1 arg: oid? */
{"PTP_OC_CANON_SetRemoteShootingMode",0x9086},
{"PTP_OC_CANON_EOS_GetStorageIDs",  0x9101},
{"PTP_OC_CANON_EOS_GetStorageInfo", 0x9102},
{"PTP_OC_CANON_EOS_GetObjectInfo",  0x9103},
{"PTP_OC_CANON_EOS_GetObject",      0x9104},
{"PTP_OC_CANON_EOS_DeleteObject",   0x9105},
{"PTP_OC_CANON_EOS_FormatStore",    0x9106},
{"PTP_OC_CANON_EOS_GetPartialObject",0x9107},
{"PTP_OC_CANON_EOS_GetDeviceInfoEx",0x9108},
{"PTP_OC_CANON_EOS_GetObjectInfoEx",0x9109},
{"PTP_OC_CANON_EOS_GetThumbEx",     0x910A},
{"PTP_OC_CANON_EOS_SendPartialObject",0x910B},
{"PTP_OC_CANON_EOS_SetObjectAttributes",0x910C},
{"PTP_OC_CANON_EOS_GetObjectTime",  0x910D},
{"PTP_OC_CANON_EOS_SetObjectTime",  0x910E},
{"PTP_OC_CANON_EOS_RemoteRelease",  0x910F},
{"PTP_OC_CANON_EOS_SetDevicePropValueEx",0x9110},
{"PTP_OC_CANON_EOS_GetRemoteMode",  0x9113},
{"PTP_OC_CANON_EOS_SetRemoteMode",  0x9114},
{"PTP_OC_CANON_EOS_SetEventMode",   0x9115},
{"PTP_OC_CANON_EOS_GetEvent",       0x9116},
{"PTP_OC_CANON_EOS_TransferComplete",0x9117},
{"PTP_OC_CANON_EOS_CancelTransfer", 0x9118},
{"PTP_OC_CANON_EOS_ResetTransfer",  0x9119},
{"PTP_OC_CANON_EOS_PCHDDCapacity",  0x911A},
{"PTP_OC_CANON_EOS_SetUILock",      0x911B},
{"PTP_OC_CANON_EOS_ResetUILock",    0x911C},
{"PTP_OC_CANON_EOS_KeepDeviceOn",   0x911D}, /* no arg */
{"PTP_OC_CANON_EOS_SetNullPacketMode",0x911E}, /* 1 param */
{"PTP_OC_CANON_EOS_UpdateFirmware", 0x911F},
{"PTP_OC_CANON_EOS_TransferCompleteDT",0x9120},
{"PTP_OC_CANON_EOS_CancelTransferDT",0x9121},
{"PTP_OC_CANON_EOS_SetWftProfile",  0x9122},
{"PTP_OC_CANON_EOS_GetWftProfile",  0x9123}, /* 2 args: setnum, configid */
{"PTP_OC_CANON_EOS_SetProfileToWft",0x9124},
{"PTP_OC_CANON_EOS_BulbStart",      0x9125},
{"PTP_OC_CANON_EOS_BulbEnd",        0x9126},
{"PTP_OC_CANON_EOS_RequestDevicePropValue",    0x9127},
{"PTP_OC_CANON_EOS_RemoteReleaseOn",    0x9128},
{"PTP_OC_CANON_EOS_RemoteReleaseOff",    0x9129},
{"PTP_OC_CANON_EOS_RegistBackgroundImage",    0x912A},
{"PTP_OC_CANON_EOS_ChangePhotoStudioMode",    0x912B},
{"PTP_OC_CANON_EOS_GetPartialObjectEx",    0x912C},
{"PTP_OC_CANON_EOS_ResetMirrorLockupState",    0x9130}, /* no args */
{"PTP_OC_CANON_EOS_PopupBuiltinFlash",    0x9131},
{"PTP_OC_CANON_EOS_EndGetPartialObjectEx",    0x9132},
{"PTP_OC_CANON_EOS_MovieSelectSWOn",    0x9133}, /* no args */
{"PTP_OC_CANON_EOS_MovieSelectSWOff",    0x9134}, /* no args */
{"PTP_OC_CANON_EOS_GetCTGInfo",        0x9135},
{"PTP_OC_CANON_EOS_GetLensAdjust",        0x9136},
{"PTP_OC_CANON_EOS_SetLensAdjust",        0x9137},
{"PTP_OC_CANON_EOS_ReadyToSendMusic",    0x9138},
{"PTP_OC_CANON_EOS_CreateHandle",        0x9139},
{"PTP_OC_CANON_EOS_SendPartialObjectEx",    0x913A},
{"PTP_OC_CANON_EOS_EndSendPartialObjectEx",    0x913B},
{"PTP_OC_CANON_EOS_SetCTGInfo",        0x913C},
{"PTP_OC_CANON_EOS_SetRequestOLCInfoGroup",    0x913D},
{"PTP_OC_CANON_EOS_SetRequestRollingPitchingLevel",    0x913E}, /* 1 arg: onoff? */
{"PTP_OC_CANON_EOS_GetCameraSupport",    0x913F},
{"PTP_OC_CANON_EOS_SetRating",        0x9140}, /* 2 args, objectid, rating? */
{"PTP_OC_CANON_EOS_RequestInnerDevelopStart",    0x9141}, /* 2 args: 1 type, 1 object? */
{"PTP_OC_CANON_EOS_RequestInnerDevelopParamChange",    0x9142},
{"PTP_OC_CANON_EOS_RequestInnerDevelopEnd",        0x9143},
{"PTP_OC_CANON_EOS_GpsLoggingDataMode",        0x9144}, /* 1 arg */
{"PTP_OC_CANON_EOS_GetGpsLogCurrentHandle",        0x9145},
{"PTP_OC_CANON_EOS_SetImageRecoveryData",        0x9146}, /* sends data? */
{"PTP_OC_CANON_EOS_GetImageRecoveryList",        0x9147},
{"PTP_OC_CANON_EOS_FormatImageRecoveryData",    0x9148},
{"PTP_OC_CANON_EOS_GetPresetLensAdjustParam",    0x9149}, /* no arg */
{"PTP_OC_CANON_EOS_GetRawDispImage",        0x914A}, /* ? 2 args ? */
{"PTP_OC_CANON_EOS_SaveImageRecoveryData",        0x914B},
{"PTP_OC_CANON_EOS_RequestBLE",            0x914C}, /* 2? args? */
{"PTP_OC_CANON_EOS_DrivePowerZoom",            0x914D}, /* 1 arg */
{"PTP_OC_CANON_EOS_GetIptcData",        0x914F},
{"PTP_OC_CANON_EOS_SetIptcData",        0x9150}, /* sends data? */
{"PTP_OC_CANON_EOS_InitiateViewfinder",    0x9151},    /* no arg */
{"PTP_OC_CANON_EOS_TerminateViewfinder",    0x9152},
{"PTP_OC_CANON_EOS_GetViewFinderData",    0x9153},
{"PTP_OC_CANON_EOS_DoAf",            0x9154},
{"PTP_OC_CANON_EOS_DriveLens",        0x9155},
{"PTP_OC_CANON_EOS_DepthOfFieldPreview",    0x9156}, /* 1 arg */
{"PTP_OC_CANON_EOS_ClickWB",        0x9157}, /* 2 args: x,y */
{"PTP_OC_CANON_EOS_Zoom",            0x9158}, /* 1 arg: zoom */
{"PTP_OC_CANON_EOS_ZoomPosition",        0x9159}, /* 2 args: x,y */
{"PTP_OC_CANON_EOS_SetLiveAfFrame",        0x915A}, /* sends data? */
{"PTP_OC_CANON_EOS_TouchAfPosition",    0x915B}, /* 3 args: type,x,y */
{"PTP_OC_CANON_EOS_SetLvPcFlavoreditMode",    0x915C}, /* 1 arg */
{"PTP_OC_CANON_EOS_SetLvPcFlavoreditParam",    0x915D}, /* 1 arg */
{"PTP_OC_CANON_EOS_AfCancel",        0x9160},
{"PTP_OC_CANON_EOS_SetImageRecoveryDataEx",    0x916B},
{"PTP_OC_CANON_EOS_GetImageRecoveryListEx",    0x916C},
{"PTP_OC_CANON_EOS_NotifyAutoTransferStatus",    0x916E},
{"PTP_OC_CANON_EOS_GetReducedObject",    0x916F},
{"PTP_OC_CANON_EOS_GetObjectInfo64",    0x9170},    /* 1 arg: oid */
{"PTP_OC_CANON_EOS_GetObject64",        0x9171},    /* 1 arg: oid */
{"PTP_OC_CANON_EOS_GetPartialObject64",    0x9172},    /* args: oid, offset, maxbyte */
{"PTP_OC_CANON_EOS_GetObjectInfoEx64",    0x9173},    /* 2 args: storageid, oid  ? */
{"PTP_OC_CANON_EOS_GetPartialObjectEX64",    0x9174},    /* args: oid, offset 64bit, maxbyte */
{"PTP_OC_CANON_EOS_CreateHandle64",        0x9175},
{"PTP_OC_CANON_EOS_NotifySaveComplete",    0x9177},
{"PTP_OC_CANON_EOS_NotifyEstimateNumberofImport",        0x9182}, /* 1 arg: importnumber */
{"PTP_OC_CANON_EOS_NotifyNumberofImported",    0x9183}, /* 1 arg: importnumber */
{"PTP_OC_CANON_EOS_NotifySizeOfPartialDataTransfer",    0x9184}, /* 4 args: filesizelow, filesizehigh, downloadsizelow, downloadsizehigh */
{"PTP_OC_CANON_EOS_NotifyFinish",        0x9185}, /* 1 arg: reason */
{"PTP_OC_CANON_EOS_GetObjectURL",        0x91AB},
{"PTP_OC_CANON_EOS_SetFELock",        0x91B9},
{"PTP_OC_CANON_EOS_SetDefaultCameraSetting",        0x91BE},
{"PTP_OC_CANON_EOS_GetAEData",        0x91BF},
{"PTP_OC_CANON_EOS_NotifyNetworkError",    0x91E8}, /* 1 arg: errorcode */
{"PTP_OC_CANON_EOS_AdapterTransferProgress",        0x91E9},
{"PTP_OC_CANON_EOS_TransferCompleteFTP",    0x91F0},
{"PTP_OC_CANON_EOS_CancelTransferFTP",    0x91F1},
{"PTP_OC_CANON_EOS_FAPIMessageTX",        0x91FE},
{"PTP_OC_CANON_EOS_FAPIMessageRX",    0x91FF},
};

const char *get_ptp_op_name(uint32_t op) {
    int i;
    for(i=0;i<(sizeof(ptp_op_names)/sizeof(ptp_op_name_t)); i++) {
        if(op==ptp_op_names[i].op) {
            return ptp_op_names[i].name;
        }
    }
    return NULL;
}

