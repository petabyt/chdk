// CHDK palette colors for the sx510hs

// Define color values as needed in this file.
// Values not defined here will be set to default values in core/gui_draw.h
// See comments in core/gui_draw.h for more details on CHDK color definitions.

    // Cameras use custom colors (CAM_LOAD_CUSTOM_COLORS) - CHDK colors set in core/gui_draw.h

    #define CHDK_COLOR_BASE                 0xB0  // Start color index for CHDK colors loaded into camera palette.

    // CHDK colors loaded into these locations in the camera palette by load_chdk_palette()
    #define COLOR_RED           (CHDK_COLOR_BASE+0)
    #define COLOR_RED_DK        (CHDK_COLOR_BASE+1)
    #define COLOR_RED_LT        (CHDK_COLOR_BASE+2)
    #define COLOR_GREEN         (CHDK_COLOR_BASE+5)
    #define COLOR_GREEN_DK      (CHDK_COLOR_BASE+6)
    #define COLOR_GREEN_LT      (CHDK_COLOR_BASE+7)
    #define COLOR_BLUE          (CHDK_COLOR_BASE+8)
    #define COLOR_BLUE_DK       (CHDK_COLOR_BASE+9)
    #define COLOR_BLUE_LT       (CHDK_COLOR_BASE+10)
    #define COLOR_MAGENTA       (CHDK_COLOR_BASE+11)
    #define COLOR_YELLOW        (CHDK_COLOR_BASE+12)
    #define COLOR_YELLOW_DK     (CHDK_COLOR_BASE+13)
    #define COLOR_YELLOW_LT     (CHDK_COLOR_BASE+14)
