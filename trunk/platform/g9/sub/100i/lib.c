#include "platform.h"
#include "lolevel.h"


char *hook_raw_image_addr()
{
 return (char*) (*(int*)(0x5854+0x18) ? 0x11F8F740 : 0x108297C0);
}

void *vid_get_viewport_fb_d()
{
    return (void*)(*(int*)0x55A0); //OK // 0x5558 + 0x48
}

void JogDial_CW(void){
  (*(short*)(0x263C+2))--;
//  *(int*)(0x263C+0x18)=0x0;
  *(int*)(0x263C+0x14)=0x32;
  _GiveSemaphore(*(int*)(0x263C+0x0C));
}

void JogDial_CCW(void){
  (*(short*)(0x263C+2))++;
//  *(int*)(0x263C+0x18)=0x0;
  *(int*)(0x263C+0x14)=0x32;
  _GiveSemaphore(*(int*)(0x263C+0x0C));
}


int review_fullscreen_mode(){
 char r;
 get_parameter_data(53, &r, 1);
 return  r==0;
}
//from g7

