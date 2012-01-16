/*===================================================================================================================================================

	USB Remote : Shooting Control Modules

		- shooting control modules monitor the state of the "virtual switch" variable and take
		  appropriate action according to the logic defined for that mode
		- all interface to the physical camera is performed by these modules
		- the active control module is selected from a menu entry in the USB Remote menu
		- to add a control module, create a new function here, add string to gui_USB_control_modes[]
		  in gui.c and add ptr below to stucture (*usb_control_module[10])(int)
 ===================================================================================================================================================*/

#include "kbd.h"
#include "stdlib.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "conf.h"
#include "action_stack.h"
#include "camera.h"
#include "usb_remote.h"

/*===================================================================================================
    Variables
  ===================================================================================================*/
extern int sync_counter;
extern int usb_sync_wait ;
extern int usb_remote_active ;
extern int virtual_remote_pulse_count ;
extern int virtual_remote_pulse_width ;
extern int stime_stamp ;
extern int sync_counter;
extern int usb_sync_wait ;

extern enum SWITCH_TYPE	 switch_type ;
extern enum CONTROL_MODULE  control_module  ;
extern enum VIRTUAL_REMOTE_STATE  virtual_remote_state;
extern enum DRIVER_STATE  driver_state;
extern enum LOGIC_MODULE_STATE logic_module_state ;
extern enum USB_STATE  usb_state ;
extern enum CAMERA_MODE  camera_mode ;

/*===================================================================================================
	Debug and error handling
  ===================================================================================================*/

#ifdef USB_REMOTE_DEBUGGING

extern int debug_errors[] ;
extern void debug_error(int ) ;

#else

extern void debug_error(int ) ;

#endif


/*---------------------------------------------------------------------------------------------------
	Control Module :  Normal
		- module to activate camera's half press key on virtual half press and full press key on virtual full press
		- implements sync as follows :
			1) one press switch - starts a full shoot on half press so that sync happens on "full press"
			2) two press switch - does half press action, starts shoot on full press, sync will happen when full press released
			3) CA-1 - does half press action, starts shoot on full press - sync happens at end of CA-1 150 mSec pulse
  ---------------------------------------------------------------------------------------------------*/

void usb_control_module_normal(int cam_mode)
{
	static long usb_remote_stack_name = -1;

	if ( conf.synch_enable == 0  )			// handle key presses differently if in sync mode
	{
		switch( logic_module_state )
		{
			case LM_RESET :
				kbd_key_release(KEY_SHOOT_FULL);
				kbd_key_release(KEY_SHOOT_HALF);
				logic_module_state = LM_RELEASE ;
				break ;

			case LM_RELEASE :
				switch ( virtual_remote_state )
				{
					case REMOTE_RELEASE :
						break ;

					case REMOTE_HALF_PRESS :
						kbd_key_press(KEY_SHOOT_HALF);
						logic_module_state = LM_HALF_PRESS ;
						break ;

					case REMOTE_FULL_PRESS:
						kbd_key_press(KEY_SHOOT_HALF);
						kbd_key_press(KEY_SHOOT_FULL);
						logic_module_state = LM_FULL_PRESS ;
						break ;

					default :
						debug_error(INVALID_STATE) ;
						break ;
				}
				break ;

			case LM_HALF_PRESS :
				switch ( virtual_remote_state )
				{
					case REMOTE_RELEASE :
						kbd_key_release(KEY_SHOOT_HALF);
						logic_module_state = LM_RELEASE ;
						break ;

					case REMOTE_HALF_PRESS :
						break ;

					case REMOTE_FULL_PRESS:
						kbd_key_press(KEY_SHOOT_FULL);
						logic_module_state = LM_FULL_PRESS ;
						break ;

					default :
						debug_error(INVALID_STATE) ;
						break ;
				}
				break ;


			case LM_FULL_PRESS :
				switch ( virtual_remote_state )
				{
					case REMOTE_RELEASE :
						kbd_key_release(KEY_SHOOT_FULL);
						kbd_key_release(KEY_SHOOT_HALF);
						logic_module_state = LM_RELEASE ;
						break ;

					case REMOTE_HALF_PRESS:
						kbd_key_release(KEY_SHOOT_FULL);
						logic_module_state = LM_HALF_PRESS ;
						break ;

					case REMOTE_FULL_PRESS:
						break ;

					default :
						debug_error(INVALID_STATE) ;
						break ;
				}
				break ;

			default :
				debug_error(INVALID_STATE) ;
				break ;

		}
	}
	else					// syncable remote mode
	{
		switch( logic_module_state )
		{
			case LM_RESET :
				logic_module_state = LM_RELEASE ;
				break ;

			case LM_RELEASE :
				switch ( virtual_remote_state )
				{
					case REMOTE_HALF_PRESS :
						switch ( switch_type)
						{
							case SW_ONE_PRESS :
								usb_remote_stack_name = action_stack_create(&action_stack_standard,AS_SHOOT);
								usb_sync_wait = 1;
								logic_module_state = LM_HALF_PRESS ;
								break ;

							case SW_TWO_PRESS :
							case SW_RICOH_CA1 :
								kbd_key_press(KEY_SHOOT_HALF);
								logic_module_state = LM_HALF_PRESS ;
								break ;

							default :
								break ;
						}
						break ;

					case REMOTE_RELEASE :
					case REMOTE_FULL_PRESS:
						break ;
					default :
						debug_error(INVALID_STATE) ;
						break ;
				}
				break ;

			case LM_HALF_PRESS :
				switch ( virtual_remote_state )
				{
					case REMOTE_FULL_PRESS:
						switch ( switch_type)
						{
							case SW_ONE_PRESS :
								logic_module_state = LM_FULL_PRESS ;
								break ;

							case SW_TWO_PRESS :
							case SW_RICOH_CA1 :
								usb_sync_wait = 1;
								kbd_key_press(KEY_SHOOT_FULL);
								logic_module_state = LM_FULL_PRESS ;
								break ;

							default :
								break ;
						}
						break ;
					case REMOTE_RELEASE :
						switch ( switch_type)
						{
							case SW_ONE_PRESS :
								if( action_stack_is_finished(usb_remote_stack_name) )
								{
									logic_module_state = LM_RELEASE ;
								}
								break ;

							case SW_TWO_PRESS :
							case SW_RICOH_CA1 :
								kbd_key_release(KEY_SHOOT_HALF);
								logic_module_state = LM_RELEASE ;
								break ;

							default :
								break ;
						}
						break ;

					case REMOTE_HALF_PRESS :
						break ;
					default :
						debug_error(INVALID_STATE) ;
						break ;
				}
				break ;

			case LM_FULL_PRESS :
				switch ( virtual_remote_state )
				{
					case REMOTE_RELEASE :
						switch ( switch_type)
						{
							case SW_ONE_PRESS :
								if( action_stack_is_finished(usb_remote_stack_name) )
								{
									logic_module_state = LM_RELEASE ;
								}
								break ;

							case SW_TWO_PRESS :
							case SW_RICOH_CA1 :
								logic_module_state = LM_RELEASE ;
								kbd_key_release(KEY_SHOOT_FULL);
								kbd_key_release(KEY_SHOOT_HALF);
								break ;

							default :
								break ;
						}
						break ;

					case REMOTE_HALF_PRESS :
					case REMOTE_FULL_PRESS:
						break ;

					default :
						debug_error(INVALID_STATE) ;
						break ;
				}
				break ;

			default :
				debug_error(INVALID_STATE) ;
				break ;
		}
	}

};

/*---------------------------------------------------------------------------------------------------
	Control Module :  Quick
		- module to launch "shoot()" on leading edge of either virtual HALF_PRESS or FULL_PRESS
		- does not support sync
  ---------------------------------------------------------------------------------------------------*/

 void usb_control_module_quick(int cam_mode)
{
	static long usb_remote_stack_name = -1;

	switch( logic_module_state )
	{
		case LM_RESET :
			logic_module_state = LM_RELEASE ;
			break ;

		case LM_RELEASE :
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					break ;

				case REMOTE_HALF_PRESS :
				case REMOTE_FULL_PRESS:
					usb_remote_stack_name = action_stack_create(&action_stack_standard,AS_SHOOT);
					logic_module_state = LM_FULL_PRESS ;
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break ;

		case LM_FULL_PRESS :
			if (( virtual_remote_state == REMOTE_RELEASE ) && action_stack_is_finished(usb_remote_stack_name) )
			{
				logic_module_state = LM_RELEASE ;
			}
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;

	}

}

/*---------------------------------------------------------------------------------------------------
	Control Module :  Burst
		- module to launch "shoot()" continuously while virtual HALF_PRESSED is true
		- refocus & exposure set on each shot - another mode could be added to lock those on first shot
		- virtual FULL_PRESS is ignored
  ---------------------------------------------------------------------------------------------------*/

void usb_control_module_burst(int cam_mode)
{
	static long usb_remote_stack_name = -1;

	switch( logic_module_state )
	{
		case LM_RESET :
			logic_module_state = LM_RELEASE ;
			break ;

		case LM_RELEASE :
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					break ;

				case REMOTE_HALF_PRESS :
				case REMOTE_FULL_PRESS:
					usb_remote_stack_name = action_stack_create(&action_stack_standard,AS_SHOOT);
					logic_module_state = LM_HALF_PRESS ;
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break ;

		case LM_HALF_PRESS :
			if( action_stack_is_finished(usb_remote_stack_name) )
			{
				logic_module_state = LM_RELEASE ;
			}
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;

	}

}

/*---------------------------------------------------------------------------------------------------
	Control Module :  Zoom
		- module to allow zoom action to be synced between two camera
		- works with Pulse Count input device
			- 1 pulse  = zoom in
			- 2 pulses = zoom out
			- 3 pulses = shoot
			- 4 pulses = zoom full in
			- 5 pulses = zoom full out
  ---------------------------------------------------------------------------------------------------*/

void usb_control_zoom(int cam_mode)
{
	static long usb_remote_stack_name = -1;

	switch( logic_module_state )
	{
		case LM_RESET :
			logic_module_state = LM_RELEASE ;
			break ;

		case LM_RELEASE :
			switch( virtual_remote_pulse_count )
			{
				case ZOOM_STEP_OUT :
					shooting_set_zoom_rel(1) ;
					break ;

				case ZOOM_STEP_IN :
					shooting_set_zoom_rel(-1) ;
					break ;

				case ZOOM_SHOOT :
					logic_module_state = LM_FULL_PRESS ;
					usb_remote_stack_name = action_stack_create(&action_stack_standard,AS_SHOOT);
					break ;

				case ZOOM_FULL_OUT :
					shooting_set_zoom(zoom_points) ;
					break ;

				case ZOOM_FULL_IN :
					shooting_set_zoom(0) ;
					break ;

				default :
					break ;
			}
			break ;

		case LM_FULL_PRESS :
			if( action_stack_is_finished(usb_remote_stack_name) )
			{
				logic_module_state = LM_RELEASE ;
			}
			break ;

		default :
			break ;
	}

	virtual_remote_pulse_count =  0;

};

/*---------------------------------------------------------------------------------------------------
	Control Module :  Bracketing
		- module to allow bracketing shots without using camera's timer or continuous modes
		- focus & exposure on each half press - shoots on full press
		- times out in 5 seconds after the last full press
  ---------------------------------------------------------------------------------------------------*/
extern void bracketing_step() ;
extern void bracketing_reset() ;

void usb_control_bracketing(int cam_mode)
{
	int current_time ;

	current_time = get_tick_count() ;

	static long usb_remote_stack_name = -1;

	switch( logic_module_state )
	{
		case LM_RESET :
			logic_module_state = LM_RELEASE ;
			break ;

		case LM_RELEASE :
			if (( stime_stamp ) && ( current_time - stime_stamp > 5000 ) )
			{
				 bracketing_reset() ;
				 stime_stamp = 0 ;
			}
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					break ;

				case REMOTE_HALF_PRESS :
					kbd_key_press(KEY_SHOOT_HALF);
					logic_module_state = LM_HALF_PRESS ;
					break ;

				case REMOTE_FULL_PRESS:
					kbd_key_press(KEY_SHOOT_FULL);
					logic_module_state = LM_FULL_PRESS ;
					stime_stamp	= current_time ;
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break ;

		case LM_HALF_PRESS :
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					kbd_key_release(KEY_SHOOT_HALF);
					logic_module_state = LM_RELEASE ;
					break ;

				case REMOTE_HALF_PRESS :
					break ;

				case REMOTE_FULL_PRESS:
					kbd_key_press(KEY_SHOOT_FULL);
					logic_module_state = LM_FULL_PRESS ;
					stime_stamp	= current_time ;
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break ;


		case LM_FULL_PRESS :
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					kbd_key_release(KEY_SHOOT_FULL_ONLY);
					kbd_key_release(KEY_SHOOT_HALF);
					logic_module_state = LM_RELEASE ;
					bracketing_step(SET_LATER) ;
					break ;

				case REMOTE_HALF_PRESS :
					kbd_key_release(KEY_SHOOT_FULL_ONLY);
					logic_module_state = LM_HALF_PRESS ;
					bracketing_step(SET_LATER) ;
					break ;

				case REMOTE_FULL_PRESS:
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break ;

		default :
			debug_error(INVALID_STATE) ;
			break ;

	}

}

 /*---------------------------------------------------------------------------------------------------
	Control Module :  Video
		- starts video (with sync if selected) on press,  stops on next press
  ---------------------------------------------------------------------------------------------------*/
void usb_video(int cam_mode)
{

	switch( logic_module_state )
	{
		case LM_RESET :
			logic_module_state = LM_RELEASE ;
			break ;

		case LM_RELEASE :
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					break ;

				case REMOTE_HALF_PRESS :
				case REMOTE_FULL_PRESS:
					kbd_key_press(KEY_SHOOT_FULL);
					logic_module_state = LM_START_RECORD ;
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break ;

		case LM_START_RECORD:
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					logic_module_state = LM_RECORDING ;
					kbd_key_release(KEY_SHOOT_FULL);
					break ;

				case REMOTE_HALF_PRESS :
				case REMOTE_FULL_PRESS:
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break;

		case LM_RECORDING :
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					break ;

				case REMOTE_HALF_PRESS :
				case REMOTE_FULL_PRESS:
					kbd_key_press(KEY_SHOOT_FULL);
					logic_module_state = LM_STOP_RECORDING ;
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break;

		case LM_STOP_RECORDING :
			switch ( virtual_remote_state )
			{
				case REMOTE_RELEASE :
					logic_module_state = LM_RELEASE ;
					kbd_key_release(KEY_SHOOT_FULL);
					break ;

				case REMOTE_HALF_PRESS :
				case REMOTE_FULL_PRESS:
					break ;

				default :
					debug_error(INVALID_STATE) ;
					break ;
			}
			break;


		default :
			debug_error(INVALID_STATE) ;
			break ;

	}

};

/*---------------------------------------------------------------------------------------------------
	Control Module :  gentWIRE-USB2   ++ FUTURE ++
		- interfaces with PWM input device module and a USB port connected to a gentWIRE-USB2 device
		- the gentWIRE-USB2 lets you connect two servo channels to the USB port of a CHDK-enabled Canon camera.
		- inputs from the gentWIRE-USB2 are as follows :
			30 mS signal when joystick 1 is moved up
			60mS signal when joystick 1 is centered
			90mS signal when joystick 1 is moved down
			120 mS signal when joystick 2 is moved up
			150mS signal when joystick 2 is centered
			180mS signal when joystick 2 is moved down
		For example, an "up" movement of joystick 2 will return a value of 12 (or possibly 13 since it's not possible for the system to be exactly precise).

		Important Note  : when assigning an action to the joystick middle position, bear in mind that it's not possible
					to move a joystick from the up position to the down position without going through the middle position.

  ---------------------------------------------------------------------------------------------------*/
void usb_gentWIRE(int cam_mode)
{

};

/*---------------------------------------------------------------------------------------------------
	Control Module :  Script  ++ FUTURE ++
		- currently CHDK scripts are disabled while a USB remote process is running
		- this mode converts virtual remote state so that script can access via wait_click and is_key
		- does not press keys itself
  ---------------------------------------------------------------------------------------------------*/
void usb_control_scripting(int cam_mode)
{

};

 /*===================================================================================================

    Control Module Jump Tables

  ===================================================================================================*/

void usb_null_module(int i) {  } ;						// module that does nothing - useful for unused entries in jump table


// play mode jump table for control logic modules - must match gui_USB_control_modes[] in gui.c

void (*usb_module_play[NUM_USB_MODULES])(int) =
	{
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module,
				usb_null_module
	};


// shooting mode jump table for control logic modules - must match gui_USB_control_modes[] in gui.c

void (*usb_module_shoot[NUM_USB_MODULES])(int) =
	{
				usb_null_module ,
				usb_control_module_normal ,
				usb_control_module_quick ,
				usb_control_module_burst ,
				usb_control_bracketing ,
				usb_control_zoom ,
				usb_null_module ,						// video mode only
				usb_gentWIRE ,
				usb_control_scripting,
				usb_null_module
	};


// video mode jump table for control logic modules - must match gui_USB_control_modes[] in gui.c

void (*usb_module_video[NUM_USB_MODULES])(int) =
	{
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_null_module ,
				usb_video ,
				usb_null_module ,
				usb_null_module,
				usb_null_module
		};
