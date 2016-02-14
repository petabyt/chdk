// CHDK palette colors for the sx280hs
// Define color values as needed in this file.

#include "palette.h"

#undef  COLOR_TRANSPARENT
#define COLOR_TRANSPARENT           0x00
#undef  COLOR_BLACK
#define COLOR_BLACK                 0xff

// Playback mode colors
unsigned char ply_colors[] =
{
        COLOR_TRANSPARENT,         // Placeholder for script colors
        COLOR_BLACK,               // Placeholder for script colors
        0x3f,                       // White
        0x9a,                       // Red
        0x99,                       // Dark Red
        0x5a,                       // Light Red
        0x73,                       // Green
        0x9b,                       // Dark Green
        0x1e,                       // Light Green
        0x56,                       // Blue
        0x90,                       // Dark Blue
        0x13,                       // Light Blue / Cyan
        0x7f,                       // Grey
        0xbf,                       // Dark Grey
        0x17,                       // Light Grey
        0x1a,                       // Yellow
        0x98,                       // Dark Yellow
        0x1f,                       // Light Yellow
        0xc7,                       // Transparent Dark Grey (blue actually)
        0x52,                       // Magenta
};

// Record mode colors
unsigned char rec_colors[] =
{
        COLOR_TRANSPARENT,         // Placeholder for script colors
        COLOR_BLACK,               // Placeholder for script colors
        0x3f,                       // White
        0x9a,                       // Red
        0x99,                       // Dark Red
        0x5a,                       // Light Red
        0x73,                       // Green
        0x9b,                       // Dark Green
        0x1e,                       // Light Green
        0x56,                       // Blue
        0x90,                       // Dark Blue
        0x13,                       // Light Blue / Cyan
        0x7f,                       // Grey
        0xbf,                       // Dark Grey
        0x17,                       // Light Grey
        0x1a,                       // Yellow
        0x98,                       // Dark Yellow
        0x1f,                       // Light Yellow
        0xc7,                       // Transparent Dark Grey (blue actually)
        0x52,                       // Magenta
};

