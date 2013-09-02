void *vid_get_bitmap_fb()        { return (void*)0x406b1000; }             // Found @0xff08b550
void *vid_get_viewport_fb()      { return (void*)0x40806b80; }             // Found @0xff412680
void *vid_get_viewport_live_fb() { return (void *)0;}
void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}

char *hook_raw_image_addr()
{
    return (char*)0x42365c30; //(Found @0xff413f98)
}

// TODO C&P, likely wrong
int vid_get_viewport_width()
{
	return 360;
}

long vid_get_viewport_height()
{
    return 240;
}


long hook_raw_size()             { return 0x01794300; }                    // Found @0xff413ff0
int get_flash_params_count(void) { return 0x91; }                          // Found @0xff2075ac

// TODO AF led for now
#define LED_PR 0xc0223030 // red LED, no DP

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

// TODO not really complete, last call from task_Bye
void shutdown()
{
    extern void _finish_shutdown(void);
    _finish_shutdown();
    while(1);
}

// TODO
void camera_set_led(int led, int state, int bright) {
 /*
 static char led_table[]={0,1,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
 */
}

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

