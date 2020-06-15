#include "camera_info.h"
#include "gui.h"
#include "gui_draw.h"
#include "meminfo.h"
#include "module_load.h"
#include "simple_module.h"
#include "clock.h"
#include "console.h"
#include "conf.h"

// =========  MODULE INIT =================

static int running = 0;
static char osdbuf[128];

extern int basic_module_init();

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

int _run()
{
    basic_module_init();

    return 0;
}

int _module_can_unload()
{
    return (running==0);
}

int _module_exit_alt()
{
    running = 0;
    return 0;
}

/******************** Module Information structure ******************/

libsimple_sym _librun =
{
    {
         0, 0, _module_can_unload, _module_exit_alt, _run
    }
};

ModuleInfo _module_info =
{
    MODULEINFO_V1_MAGICNUM,
    sizeof(ModuleInfo),
    {1,0},      // Module version

    ANY_CHDK_BRANCH, 0, OPT_ARCHITECTURE,           // Requirements of CHDK version
    ANY_PLATFORM_ALLOWED,       // Specify platform dependency

    (int32_t)"Checksum Canon firmware",
    MTYPE_TOOL,

    &_librun.base,

    CONF_VERSION,               // CONF version
    CAM_SCREEN_VERSION,         // CAM SCREEN version
    ANY_VERSION,                // CAM SENSOR version
    ANY_VERSION,                // CAM INFO version
};

/*************** END OF AUXILARY PART *******************/
//-------------------------------------------------------------------
// From public domain crc32 code
//-------------------------------------------------------------------

unsigned long crc32_for_byte(unsigned long r) {
    unsigned long j;
    for (j = 0; j < 8; j++) {
        r = (r & 1? 0: (unsigned long)0xEDB88320) ^ r >> 1;
    }
    return r ^ (unsigned long)0xFF000000;
}

void crc32(const void *data, unsigned long n_bytes, unsigned long* crc) {
    static unsigned long ct[0x100] = {0};
    unsigned long i;
    if (!ct[0]) {
        for (i = 0; i < 0x100; i++) {
            ct[i] = crc32_for_byte(i);
        }
    }
    for (i = 0; i < n_bytes; i++) {
        *crc = ct[(unsigned char)*crc ^ ((unsigned char*)data)[i]] ^ *crc >> 8;
    }
}

#define MAX_CRC_BLOCKS 10

typedef struct {
    char *start;
    unsigned size;
    unsigned crc;
} block_desc_t;

block_desc_t blocks[MAX_CRC_BLOCKS+1];

int load_checksum_file(const char *fn)
{
    struct stat st;
    if(stat(fn, &st) != 0) {
        return 0;
    }
    unsigned size = st.st_size;

    char *buf = malloc(size);
    if(!buf) {
        return 0;
    }

    FILE *fd = fopen(fn, "rb");
    if (!fd) {
        free(buf);
        return 0;
    }

    int ret = fread(buf, 1, size, fd);
    fclose(fd);
    if (ret != size) {
        free(buf);
        return 0;
    }
    int b = 0;
    char *p = buf;
    for(b = 0; b < MAX_CRC_BLOCKS && *p; b++) {
        blocks[b].start = (char *)strtoul(p,&p,16);
        blocks[b].size = strtoul(p,&p,16);
        blocks[b].crc = strtoul(p,&p,16);
        if(!blocks[b].start || !blocks[b].size || !blocks[b].crc || blocks[b].start < (void*)camera_info.rombaseaddr ) {
            blocks[b].start = 0;
            break;
        }
    }
    free(buf);
    return (b > 0); // no blocks loaded = bad file
}


/*************** GUI MODULE *******************/

#include "gui_lang.h"
#include "gui_mbox.h"
#include "gui_fselect.h"
#include "stdlib.h"


//xxxxxxxx xxxxxxxx PASS\n  x 10
static char out[250];

static void gui_firmware_crc_done(unsigned unused)
{
    running = 0;
}
static void gui_firmware_crc_file_selected(const char *fn)
{
    if (fn) {
        if(load_checksum_file(fn)) {
            char *s = out;
            int failed = 0;
            int b = 0;
            for(b = 0; b < MAX_CRC_BLOCKS && blocks[b].start; b++) {
                s += sprintf(s,"%8x %8x ",blocks[b].start,blocks[b].size);
                unsigned long fw_crc = 0;
                crc32(blocks[b].start,blocks[b].size,&fw_crc);
                if(fw_crc == blocks[b].crc) {
                    s += sprintf(s,"PASS\n");
                } else {
                    s += sprintf(s,"FAIL\n");
                    failed++;
                }
            }
            if(failed > 0) {
                gui_mbox_init(LANG_ERROR, (int)out, MBOX_BTN_OK|MBOX_TEXT_CENTER|MBOX_FUNC_RESTORE, gui_firmware_crc_done );
            } else {
                gui_mbox_init(LANG_INFORMATION, (int)out, MBOX_BTN_OK|MBOX_TEXT_CENTER|MBOX_FUNC_RESTORE, gui_firmware_crc_done );
            }
        } else {
            gui_mbox_init(LANG_ERROR, (int)"Failed to load file", MBOX_BTN_OK|MBOX_TEXT_CENTER|MBOX_FUNC_RESTORE, gui_firmware_crc_done );
        }
    } else {
        running = 0;
    }
}

//-------------------------------------------------------------------

int basic_module_init()
{
    running = 1;
    libfselect->file_select((int)"Checksum file", "A/CHDK", "A/CHDK", gui_firmware_crc_file_selected);
    return 1;
}


