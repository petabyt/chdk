#include "camera_info.h"
#include "stdlib.h"
#include "conf.h"
#include "script.h"
#include "meminfo.h"

// to keep format simple, we always write meminfo for each
// but can skip actual getmeminfo since call might crash on mem corruption
#define DBG_DUMP_FL_NOMEMINFO   0x1
#define DBG_DUMP_FL_NOEXMEMINFO 0x2

/*
dump debug info to a file
format
 header
 meminfo (camera heap, may be mostly -1 if meminfo not supported,0s if desabled)
 meminfo (exmem, 0s if exmem disabled)
 stack dump (length in words given stack_count)
 user data (variable length given in user_data_len)
*/
typedef struct {
    int ver;
    int time;
    int platform_id;
    int romstart;
    int text_start; // == _start
    int data_start; // == text_end
    int bss_start;  // == data_end
    int bss_end;    // == _end
    int sp;
    int stack_count; // number of words of stack dumped (not related to number of words in stack!)
    int user_val; // user_data address if not null, otherwise treat user_data_size as an arbitrary int and put it here
    int user_data_len;
    int flags;
} dumpheader;

// this does not describe the structure, just a convenient way to access uncached
typedef union {
    dumpheader h;
    cam_meminfo m;
} dumpinfo;

// number of words to dump -- could get initial SP from task
#define STACK_DUMP_COUNT 512


void dbg_dump_write(const char *dumpname,unsigned flags, int user_data_len, char *user_data) {
    static dumpinfo buf;
    // convenient access to uncached version
    dumpinfo *pb = (dumpinfo *)((int)&buf | camera_info.cam_uncached_bit);
    
    // use open + uncached mem because we may not have enough memory for fopen
    int fd=open(dumpname, O_WRONLY|O_CREAT|O_TRUNC, 0777);
    if(fd >= 0) {
        int *sp;
        asm volatile( "MOV %0,SP\n" :"=r"(sp));
        pb->h.ver = 1; // version
        pb->h.time = time(NULL);
        pb->h.platform_id = conf.platformid;
        pb->h.romstart = camera_info.rombaseaddr;
        pb->h.text_start = camera_info.text_start;
        pb->h.data_start = camera_info.data_start;
        pb->h.bss_start = camera_info.bss_start;
        pb->h.bss_end = camera_info.bss_end;
        pb->h.sp = (int)sp;
        pb->h.stack_count = STACK_DUMP_COUNT;
        if(user_data) {
            pb->h.user_data_len = user_data_len;
            pb->h.user_val = (int)user_data;
        } else {
            pb->h.user_data_len = 0;
            pb->h.user_val = user_data_len;
        }

        pb->h.flags = flags;
        write(fd,&pb->h,sizeof(dumpheader));

        if(!(flags & DBG_DUMP_FL_NOMEMINFO)) {
            GetMemInfo(&pb->m);
        } else {
            memset(&pb->m,0,sizeof(cam_meminfo));
        }
        write(fd,&pb->m,sizeof(cam_meminfo));

// if no exmem don't check
        memset(&pb->m,0,sizeof(cam_meminfo));
        if(!(flags & DBG_DUMP_FL_NOEXMEMINFO)) {
            GetExMemInfo(&pb->m);
        }
        write(fd,&pb->m,sizeof(cam_meminfo));

        // poor mans cache clean
        // read and write 4k of presumably unrelated memory - chdk code
        static volatile int dummy;
        int *p;
        for(p=(int *)camera_info.text_start;p < (int *)(camera_info.text_start+4096);p++) {
            dummy = *p;
            *p = dummy;
        }
        write(fd,(char *)((int)sp|camera_info.cam_uncached_bit),STACK_DUMP_COUNT*4);
        if(user_data_len && user_data) {
            // we assume user_data has been flushed out by preceding
            write(fd,(char *)((int)user_data|camera_info.cam_uncached_bit),user_data_len);
        }
        close(fd);
    } else {
        script_console_add_line( (long)"failed to open dump file" );
    }
}

void dbg_dump_assert(const char *dumpfile,const char *expr,const char *file,int line) {
    static char buf[128]; // could overflow if expr is long
    sprintf(buf,"ASSERT %s:%d %s",file,line,expr);
    script_console_add_line( (long)buf );
    dbg_dump_write(dumpfile,0,sizeof(buf),buf);
}
