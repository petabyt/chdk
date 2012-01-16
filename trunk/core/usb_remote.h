/*===================================================================================================
    Static Variables & #defines
  ===================================================================================================*/

#undef USB_REMOTE_DEBUGGING
// #define USB_REMOTE_DEBUGGING 1

#define NUM_USB_INPUT_DRV 10
#define NUM_USB_MODULES 10

enum {
		INVALID_STATE ,
		INVALID_DEVICE ,
		INVALID_MODULE
	} ;


enum  SWITCH_TYPE {							// USB remote switch types
	SW_NONE = 0 ,
	SW_ONE_PRESS ,
	SW_TWO_PRESS ,
	SW_RICOH_CA1 ,
	SW_PWN
}  ;

enum CONTROL_MODULE {						// USB remote control modes
	RMT_NONE  = 0 ,
	RMT_HALF_PRESS_FULL_PRESS ,
	RMT_AUTO_1 ,
	RMT_AUTO_2 ,
	RMT_CONTINUOUS ,
	RMT_ZOOM ,
	RMT_BRACKETING,
	RMT_SCRIPT
} ;

enum VIRTUAL_REMOTE_STATE {					// state of Virtual USB remote switch
	REMOTE_RESET = 0 ,
    REMOTE_RELEASE,
    REMOTE_HALF_PRESS,
    REMOTE_FULL_PRESS
} ;

enum DRIVER_STATE {								// state variable for drivers
	SW_RESET = 0 ,
    SW_IDLE,
    SW_POWER_CONNECT,
    SW_POWER_ON,
	SW_POWER_DISCONNECT,
	SW_FULL_PRESS_ACTIVE ,
	SW_SHORT_PRESS ,
	SW_CANCEL_PULSE ,
	SW_HALF_PRESS,
	SW_FULL_PRESS ,
	SW_FULL_PRESS_RESET,
	SW_PRESS ,
	SW_RELEASE ,
	SW_CANCEL
} ;

enum  LOGIC_MODULE_STATE {								// remote control mode states
	LM_RESET = 0 ,
    LM_RELEASE,
	LM_HALF_PRESS,
	LM_FULL_PRESS,
	LM_START_RECORD ,
	LM_RECORDING ,
	LM_STOP_RECORDING
} ;

enum USB_STATE {								// values returned from get_usb_power(1)
	USB_POWER_OFF,
	USB_POWER_ON
} ;

enum CAMERA_MODE {								// camera mode  = 0 in picture record mode, 1 in playback mode, 2 when modedial is set to videomode AND camera is in record mode
	CAMERA_MODE_SHOOTING ,
	CAMERA_MODE_PLAYBACK ,
	CAMERA_MODE_VIDEO
} ;

enum  ZOOM_MODE {
	ZOOM_STEP_OUT  = 1,
	ZOOM_STEP_IN ,
	ZOOM_SHOOT ,
	ZOOM_FULL_OUT ,
	ZOOM_FULL_IN
} ;

// USB remote processing status

#define RMT_DISABLED 0
#define RMT_ENABLED 1

// timing parameters

#define DEBOUNCE_TIME 10
#define MAX_PULSE_TIME 10000
#define FULL_PRESS_PULSE_TIME 1000
#define MAX_FULL_PRESS_DELAY 1000
#define CA1_MIN_HALFPRESS_TIME 10
#define CA1_MAX_HALFPRESS_TIME 50
#define CA1_CANCEL_PULSE_TIME 100
#define CA1_MIN_FULLPRESS_TIME 100
#define CA1_MAX_FULLPRESS_TIME 300
#define CA1_FULL_WAIT_PRESS_TIMEOUT 30000

#define DELAY_TIMEOUT 10000

