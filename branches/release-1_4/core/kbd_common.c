/*
common low level keyboard handling functions

WARNING:
If you change code here, be sure to grep platform_kbd.h files for
KBD_CUSTOM_ and make sure that the cameras special platform specific
requirements are updated if required.

platform_kbd.h defines
** controls for kbd.c implementation
* this camera has a totally custom keyboard code, don't build common code
KBD_CUSTOM_ALL

* non-standard key state update
KBD_CUSTOM_UPDATE_KEY_STATE

* non-standard manipulation of other physw bits (SD readonly, USB etc)
KBD_CUSTOM_UPDATE_PHYSW_BITS


* use logical event to simulate "video" button from script
* for touchscreen cameras without a physical video button
KBD_SIMULATE_VIDEO_KEY

* For cams without an SD card lock (micro-SD)
KBD_SKIP_READONLY_BIT

* Cameras that have an MF key and enable ZOOM_FOR_MF detect mf presses and use MF key
KBD_ZOOM_FOR_MF_USE_MF_KEY

** defines for hardware bits etc

* key masks - for keys used by CHDK in alt mode
* bitwise OR of all keymap canon key values
KEYS_MASK0
KEYS_MASK1
KEYS_MASK2

** SD card read only bit
SD_READONLY_FLAG
** physw_status index for readonly bit
SD_READONLY_IDX

** USB +5v bit
USB_MASK
** physw_status index for USB bit
USB_IDX

** get_usb_bit should use the following MMIO directly
USB_MMIO

** battery cover override - requires additional supporting code
BATTCOVER_IDX
BATTCOVER_FLAG 

* override SD card door for cameras micro-sd cams that use it for autoboot
SD_DOOR_OVERRIDE 1
* bit for SD door
SD_DOOR_FLAG
* physw_status index for SD door
SD_DOOR_IDX

*/
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "kbd_common.h"
#include "conf.h"

// for KBD_SIMULATE_VIDEO_KEY
#include "levent.h"

// if KBD_CUSTOM_ALL, platform kbd.c provides everything, this file is noop
// when adding funtionality, grep KBD_CUSTOM_ALL and update accordingly
#ifndef KBD_CUSTOM_ALL
extern long physw_status[3];
extern int forced_usb_port;

#ifndef KBD_CUSTOM_UPDATE_KEY_STATE

#ifdef CAM_HAS_GPS
int gps_key_trap=0 ;
#endif

/*
 saves & updates key state, runs main CHDK kbd task code in kbd_process,
 returns kbd_process value
*/
long kbd_update_key_state(void)
{
    kbd_prev_state[0] = kbd_new_state[0];
    kbd_prev_state[1] = kbd_new_state[1];
    kbd_prev_state[2] = kbd_new_state[2];

#ifdef CAM_TOUCHSCREEN_UI
    kbd_prev_state[3] = kbd_new_state[3];
#endif

    // note assumed kbd_pwr_on has been called if needed
    kbd_fetch_data(kbd_new_state);

#ifdef CAM_HAS_GPS
    if (gps_key_trap > 0)        // check if gps code is waiting for a specific key press to cancel shutdown
    {
        if (kbd_get_pressed_key() == gps_key_trap)
        {
            kbd_key_release(gps_key_trap);
            kbd_key_press(0);
            gps_key_trap = -1;  // signal the gps task that the specified button was pressed
            msleep(1000);       // pause to allow button release so Canon f/w does not see the press
        }
    }
#endif

    long status = kbd_process();
    if (status == 0){
        // leave it alone...
        physw_status[0] = kbd_new_state[0];
        physw_status[1] = kbd_new_state[1];
        physw_status[2] = kbd_new_state[2];

#ifdef CAM_HAS_JOGDIAL
        jogdial_control(0);
#endif
    } else {
        // override keys
        // TODO doesn't handle inverted logic yet
        physw_status[0] = (kbd_new_state[0] & (~KEYS_MASK0)) | (kbd_mod_state[0] & KEYS_MASK0);

        physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1)) | (kbd_mod_state[1] & KEYS_MASK1);

        physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2)) | (kbd_mod_state[2] & KEYS_MASK2);

#ifdef CAM_HAS_JOGDIAL
        if ((jogdial_stopped==0) && !camera_info.state.state_kbd_script_run) {
            jogdial_control(1);
            get_jogdial_direction();
        }
        else if (jogdial_stopped && camera_info.state.state_kbd_script_run) {
            jogdial_control(0);
        }
#endif
    }
    return status;
}
#endif // KBD_CUSTOM_UPDATE_KEY_STATE

#ifndef KBD_CUSTOM_UPDATE_PHYSW_BITS
void kbd_update_physw_bits(void)
{
    // TODO could save the real USB bit to avoid low level calls in get_usb_bit when immediate update not needed
    if (forced_usb_port) {
        physw_status[USB_IDX] = physw_status[USB_IDX] | USB_MASK;
    } else if (conf.remote_enable) {
        // TODO some cameras (e.g. a530, a540) didn't mask USB with remote,
        // because +5v has no effect on canon firmware in rec mode
        physw_status[USB_IDX] = physw_status[USB_IDX] & ~(USB_MASK);
    }
// microsd cams don't have a read only bit
#ifndef KBD_SKIP_READONLY_BIT
    physw_status[SD_READONLY_IDX] = physw_status[SD_READONLY_IDX] & ~SD_READONLY_FLAG;
#endif

// n and possibly other micro SD cams uses door bit for autoboot, force back to closed (?)
#ifdef SD_DOOR_OVERRIDE
    physw_status[SD_DOOR_IDX] |= SD_DOOR_FLAG;                // override SD card door switch
#endif

#ifdef OPT_RUN_WITH_BATT_COVER_OPEN
    physw_status[BATTCOVER_IDX] = physw_status[BATTCOVER_IDX] | BATTCOVER_FLAG;
#endif

#ifdef CAM_HOTSHOE_OVERRIDE
    if (conf.hotshoe_override == 1) {
        physw_status[HOTSHOE_IDX] = physw_status[HOTSHOE_IDX] & ~HOTSHOE_FLAG;
    } else if (conf.hotshoe_override == 2) {
        physw_status[HOTSHOE_IDX] = physw_status[HOTSHOE_IDX] | HOTSHOE_FLAG;
    }
#endif
}
#endif // KBD_CUSTOM_UPDATE_PHYSW_BITS

// if the port reads an MMIO directly to get USB +5v status, use generic get_usb_bit
// others must define in platform kbd.c
#ifdef USB_MMIO
int get_usb_bit() 
{
    volatile int *mmio = (void*)USB_MMIO;
    return(( *mmio & USB_MASK)==USB_MASK); 
}
#endif

#ifdef KBD_SIMULATE_VIDEO_KEY
static int is_video_key_pressed = 0;
#endif

void kbd_key_press(long key)
{
#ifdef KBD_SIMULATE_VIDEO_KEY
    if (key == KEY_VIDEO && !is_video_key_pressed)
    {
        // TODO define for ID would be more efficient
        PostLogicalEventToUI(levent_id_for_name("PressMovieButton"),0);
        is_video_key_pressed = 1;
        // TODO not clear if this should return, or set state too
        return;
    }    
#endif
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            kbd_mod_state[keymap[i].grp] &= ~keymap[i].canonkey;
            return;
        }
    }
}

void kbd_key_release(long key)
{
#ifdef KBD_SIMULATE_VIDEO_KEY
    if (key == KEY_VIDEO && is_video_key_pressed)
    {
        PostLogicalEventToUI(levent_id_for_name("UnpressMovieButton"),0);
        is_video_key_pressed = 0;
        return;
    }
#endif
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            kbd_mod_state[keymap[i].grp] |= keymap[i].canonkey;
            return;
        }
    }
}

void kbd_key_release_all()
{
    kbd_mod_state[0] |= KEYS_MASK0;
    kbd_mod_state[1] |= KEYS_MASK1;
    kbd_mod_state[2] |= KEYS_MASK2;
// touch screen virtual keys
#ifdef CAM_TOUCHSCREEN_UI
    kbd_mod_state[3] |= 0xFFFFFFFF;
#endif
}

long kbd_is_key_pressed(long key)
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            return ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0) ? 1:0;
        }
    }
    return 0;
}

long kbd_is_key_clicked(long key)
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if (keymap[i].hackkey == key){
            return ((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
                    ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0);
        }
    }
    return 0;
}

long kbd_get_pressed_key()
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0){
            return keymap[i].hackkey;
        }
    }
    return 0;
}

long kbd_get_clicked_key()
{
    int i;
    for (i=0;keymap[i].hackkey;i++){
        if (((kbd_prev_state[keymap[i].grp] & keymap[i].canonkey) != 0) &&
            ((kbd_new_state[keymap[i].grp] & keymap[i].canonkey) == 0)){
            return keymap[i].hackkey;
        }
    }
    return 0;
}

#ifdef CAM_USE_ZOOM_FOR_MF
// cameras with an MF use it (s2, s3, s5 etc)
#ifdef KBD_ZOOM_FOR_MF_USE_MF_KEY
long kbd_use_zoom_as_mf() {
    static long zoom_key_pressed = 0;

    if (kbd_is_key_pressed(KEY_ZOOM_IN) && kbd_is_key_pressed(KEY_MF) && camera_info.state.mode_rec) {
        if (shooting_get_focus_mode()) {
            kbd_key_release_all();
            kbd_key_press(KEY_MF);
            kbd_key_press(KEY_UP);
            zoom_key_pressed = KEY_ZOOM_IN;
            return 1;
        }
    } else {
        if (zoom_key_pressed==KEY_ZOOM_IN) {
            kbd_key_release(KEY_UP);
            zoom_key_pressed = 0;
            return 1;
        }
    }
    if (kbd_is_key_pressed(KEY_ZOOM_OUT) && kbd_is_key_pressed(KEY_MF) && camera_info.state.mode_rec) {
        if (shooting_get_focus_mode()) {
            kbd_key_release_all();
            kbd_key_press(KEY_MF);
            kbd_key_press(KEY_DOWN);
            zoom_key_pressed = KEY_ZOOM_OUT;
            return 1;
        }
    } else {
        if (zoom_key_pressed==KEY_ZOOM_OUT) {
            kbd_key_release(KEY_DOWN);
            zoom_key_pressed = 0;
            return 1;
        }
    }
    return 0;
}
#else
long kbd_use_zoom_as_mf() {
    static long zoom_key_pressed = 0;

    if (kbd_is_key_pressed(KEY_ZOOM_IN) && camera_info.state.mode_rec) {
        if (shooting_get_focus_mode()) {
            kbd_key_release_all();
            kbd_key_press(KEY_RIGHT);
            zoom_key_pressed = KEY_ZOOM_IN;
            return 1;
        }
    } else {
        if (zoom_key_pressed==KEY_ZOOM_IN) {
            kbd_key_release(KEY_RIGHT);
            zoom_key_pressed = 0;
            return 1;
        }
    }
    if (kbd_is_key_pressed(KEY_ZOOM_OUT) && camera_info.state.mode_rec) {
        if (shooting_get_focus_mode()) {
            kbd_key_release_all();
            kbd_key_press(KEY_LEFT);
            zoom_key_pressed = KEY_ZOOM_OUT;
            return 1;
        }
    } else {
        if (zoom_key_pressed==KEY_ZOOM_OUT) {
            kbd_key_release(KEY_LEFT);
            zoom_key_pressed = 0;
            return 1;
        }
    }
    return 0;
}
#endif //KBD_ZOOM_FOR_MF_USE_MF_KEY
#endif // CAM_USE_ZOOM_FOR_MF
#endif // KBD_CUSTOM_ALL
