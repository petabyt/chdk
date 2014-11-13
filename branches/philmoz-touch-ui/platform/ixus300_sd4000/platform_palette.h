// CHDK palette colors for the ixus300_sd4000

// Define color values as needed in this file.
// Values not defined here will be set to default values in core/gui_draw.h
// See comments in core/gui_draw.h for more details on CHDK color definitions.

    // pallete changes almost completely depenting on mode and if canon menu is active or not
    // playback, playback with menu, photo record mode, photo record mode with menu, ...
    #define COLOR_WHITE                 0x01    // always the same
    #define COLOR_RED                   0x1E    // always the same, bright orange (red is only available in record more without menu)
    #define COLOR_GREY                  0x16    // always the same
    #define COLOR_GREEN                 0x9F    // playback only, without menu
    #define COLOR_BLUE_LT               0x0C    // playback: light brown
    #define COLOR_BLUE                  0x12    // playback: dark brown (almost like sh.t)
    #define COLOR_YELLOW                0x90    // playback only, without menu
    #define COLOR_GREY_DK               0x1D    // greyisch
    #define COLOR_RED_DK                COLOR_RED
    #define COLOR_RED_LT                COLOR_BLUE
    #define COLOR_GREY_LT               0x16    // darker grey
    // Override histogram colors if needed
    #define COLOR_REC_RED               0x66    // record only, without menu
    #define COLOR_REC_BLUE              0x3C
    #define COLOR_PLY_BLUE              0x50    // playback without menu dont have blue at all, bright Orange
    #define COLOR_REC_GREEN             0x6B
    #define COLOR_REC_MAGENTA           COLOR_RED
    #define COLOR_PLY_MAGENTA           COLOR_REC_MAGENTA

