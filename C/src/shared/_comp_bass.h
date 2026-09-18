#pragma once

#include "bass.h"

#ifdef LIB_BASS_DYNAMIC_LOAD
typedef BOOL    (*setconfig_func)           (DWORD, DWORD);
typedef DWORD   (*getconfig_func)           (DWORD);
typedef BOOL    (*setconfigptr_func)        (DWORD, const void*);
typedef VOID    (*getconfigptr_func)        (DWORD);
typedef DWORD   (*getversion_func)          (VOID);
typedef INT     (*errorgetcode_func)        (VOID);
typedef BOOL    (*getdeviceinfo_func)       (DWORD, BASS_DEVICEINFO*);
#if defined(_WIN32) && !defined(_WIN32_WCE) && !(WINAPI_FAMILY && WINAPI_FAMILY!=WINAPI_FAMILY_DESKTOP_APP)
typedef BOOL    (*init_func)                (INT, DWORD, DWORD, HWND, const GUID*);
#else
typedef BOOL    (*init_func)                (INT, DWORD, DWORD, VOID*, VOID*);
#endif
typedef BOOL    (*setdevice_func)           (DWORD);
typedef DWORD   (*getdevice_func)           (VOID);
typedef BOOL    (*free_func)                (VOID);
#if defined(_WIN32) && !defined(_WIN32_WCE) && !(WINAPI_FAMILY && WINAPI_FAMILY!=WINAPI_FAMILY_DESKTOP_APP)
typedef VOID*   (*getdsoundobject_func)     (DWORD);
#endif
typedef BOOL    (*getinfo_func)             (BASS_INFO*);
typedef BOOL    (*update_func)              (DWORD);
typedef FLOAT   (*getcpu_func)              (VOID);
typedef BOOL    (*start_func)               (VOID);
typedef BOOL    (*stop_func)                (VOID);
typedef BOOL    (*pause_func)               (VOID);
typedef BOOL    (*isstarted_func)           (VOID);
typedef BOOL    (*setvolume_func)           (FLOAT);
typedef FLOAT   (*getvolume_func)           (VOID);
typedef HPLUGIN (*pluginload_func)          (const CHAR*, DWORD);
typedef BOOL    (*pluginfree_func)          (HPLUGIN);
typedef const BASS_PLUGININFO*
                (*plugingetinfo_func)       (HPLUGIN);
typedef BOOL    (*set3dfactors_func)        (FLOAT, FLOAT, FLOAT);
typedef BOOL    (*get3dfactors_func)        (FLOAT*, FLOAT*, FLOAT*);
typedef BOOL    (*set3dposition_func)       (const BASS_3DVECTOR*, const BASS_3DVECTOR*, const BASS_3DVECTOR*, const BASS_3DVECTOR*);
typedef BOOL    (*get3dposition_func)       (BASS_3DVECTOR*, BASS_3DVECTOR*, BASS_3DVECTOR*, BASS_3DVECTOR*);
typedef VOID    (*apply3d_func)             (VOID);
#if defined(_WIN32) && !defined(_WIN32_WCE) && !(WINAPI_FAMILY && WINAPI_FAMILY!=WINAPI_FAMILY_DESKTOP_APP)
typedef BOOL    (*seteaxparameters_func)    (INT, FLOAT, FLOAT, FLOAT);
typedef BOOL    (*geteaxparameters_func)    (DWORD*, FLOAT*, FLOAT*, FLOAT*);
#endif
typedef HMUSIC  (*musicload_func)           (BOOL, const void*, QWORD, DWORD, DWORD, DWORD);
typedef BOOL    (*musicfree_func)           (HMUSIC);
typedef HSAMPLE (*sampleload_func)          (BOOL, const void*, QWORD, DWORD, DWORD, DWORD);
typedef HSAMPLE (*samplecreate_func)        (DWORD, DWORD, DWORD, DWORD, DWORD);
typedef BOOL    (*samplefree_func)          (HSAMPLE);
typedef BOOL    (*samplesetdata_func)       (HSAMPLE, const void*);
typedef BOOL    (*samplegetdata_func)       (HSAMPLE, void*);
typedef BOOL    (*samplegetinfo_func)       (HSAMPLE, BASS_SAMPLE*);
typedef BOOL    (*samplesetinfo_func)       (HSAMPLE, const BASS_SAMPLE*);
typedef HCHANNEL
                (*samplegetchannel_func)    (HSAMPLE, BOOL);
typedef DWORD   (*samplegetchannels_func)   (HSAMPLE, HCHANNEL);
typedef BOOL    (*samplestop_func)          (HSAMPLE);
typedef HSTREAM (*streamcreate_func)        (DWORD, DWORD, DWORD, STREAMPROC*, VOID*);
typedef HSTREAM (*streamcreatefile_func)    (BOOL, const VOID*, QWORD, QWORD, DWORD);
typedef HSTREAM (*streamcreateurl_func)     (const CHAR*, DWORD, DWORD, DOWNLOADPROC*, VOID*);
typedef HSTREAM (*streamcreatefileuser_func)(DWORD, DWORD, const BASS_FILEPROCS*, VOID*);
typedef BOOL    (*streamfree_func)          (HSTREAM);
typedef QWORD   (*streamgetfileposition_func)
                                            (HSTREAM, DWORD);
typedef DWORD   (*streamputdata_func)       (HSTREAM, const VOID*, DWORD);
typedef DWORD   (*streamputfiledata_func)   (HSTREAM, const VOID*, DWORD);
typedef BOOL    (*recordgetdeviceinfo_func) (DWORD, BASS_DEVICEINFO*);
typedef BOOL    (*recordinit_func)          (INT);
typedef BOOL    (*recordsetdevice_func)     (DWORD);
typedef DWORD   (*recordgetdevice_func)     (VOID);
typedef BOOL    (*recordfree_func)          (VOID);
typedef BOOL    (*recordgetinfo_func)       (BASS_RECORDINFO*);
typedef const CHAR*
                (*recordgetinputname_func)  (INT);
typedef BOOL    (*recordsetinput_func)      (INT, DWORD, FLOAT);
typedef DWORD   (*recordgetinput_func)      (INT, FLOAT*);
typedef HRECORD (*recordstart_func)         (DWORD, DWORD, DWORD, RECORDPROC*, VOID*);
typedef DOUBLE  (*channelbytes2seconds_func)(DWORD, QWORD);
typedef QWORD   (*channelseconds2bytes_func)(DWORD, DOUBLE);
typedef DWORD   (*channelgetdevice_func)    (DWORD);
typedef BOOL    (*channelsetdevice_func)    (DWORD, DWORD);
typedef DWORD   (*channelisactive_func)     (DWORD);
typedef BOOL    (*channelgetinfo_func)      (DWORD, BASS_CHANNELINFO*);
typedef const CHAR*
                (*channelgettags_func)      (DWORD, DWORD);
typedef DWORD   (*channelflags_func)        (DWORD, DWORD, DWORD);
typedef BOOL    (*channelupdate_func)       (DWORD, DWORD);
typedef BOOL    (*channellock_func)         (DWORD, BOOL);
typedef BOOL    (*channelplay_func)         (DWORD, BOOL);
typedef BOOL    (*channelstop_func)         (DWORD);
typedef BOOL    (*channelpause_func)        (DWORD);
typedef BOOL    (*channelsetattribute_func) (DWORD, DWORD, FLOAT);
typedef BOOL    (*channelgetattribute_func) (DWORD, DWORD, FLOAT*);
typedef BOOL    (*channelslideattribute_func)
                                            (DWORD, DWORD, FLOAT, DWORD);
typedef BOOL    (*channelissliding_func)    (DWORD, DWORD);
typedef BOOL    (*channelsetattributeex_func)
                                            (DWORD, DWORD, VOID*, DWORD);
typedef DWORD   (*channelgetattributeex_func)
                                            (DWORD, DWORD, VOID*, DWORD);
typedef BOOL    (*channelset3dattributes_func)
                                            (DWORD, INT, FLOAT, FLOAT, INT, INT, FLOAT);
typedef BOOL    (*channelget3dattributes_func)
                                            (DWORD, DWORD*, FLOAT*, FLOAT*, DWORD*, DWORD*, FLOAT*);
typedef BOOL    (*channelset3dposition_func)(DWORD, const BASS_3DVECTOR*, const BASS_3DVECTOR*, const BASS_3DVECTOR*);
typedef BOOL    (*channelget3dposition_func)(DWORD, BASS_3DVECTOR*, BASS_3DVECTOR*, BASS_3DVECTOR*);
typedef QWORD   (*channelgetlength_func)    (DWORD, DWORD);
typedef BOOL    (*channelsetposition_func)  (DWORD, QWORD, DWORD);
typedef QWORD   (*channelgetposition_func)  (DWORD, DWORD);
typedef DWORD   (*channelgetlevel_func)     (DWORD);
typedef BOOL    (*channelgetlevelex_func)   (DWORD, FLOAT*, FLOAT, DWORD);
typedef DWORD   (*channelgetdata_func)      (DWORD, VOID*, DWORD);
typedef HSYNC   (*channelsetsync_func)      (DWORD, DWORD, QWORD, SYNCPROC*, VOID*);
typedef BOOL    (*channelremovesync_func)   (DWORD, HSYNC);
typedef HDSP    (*channelsetdsp_func)       (DWORD, DSPPROC*, VOID*, INT);
typedef BOOL    (*channelremovedsp_func)    (DWORD, HDSP);
typedef BOOL    (*channelsetlink_func)      (DWORD, DWORD);
typedef BOOL    (*channelremovelink_func)   (DWORD, DWORD);
typedef HFX     (*channelsetfx_func)        (DWORD, DWORD, INT);
typedef BOOL    (*channelremovefx_func)     (DWORD, HFX);
typedef BOOL    (*fxsetparameters_func)     (HFX, const VOID*);
typedef BOOL    (*fxgetparameters_func)     (HFX, VOID*);
typedef BOOL    (*fxreset_func)             (HFX);
typedef BOOL    (*fxsetpriority_func)       (HFX, INT);
#endif