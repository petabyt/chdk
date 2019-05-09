
// Digic6 colour handling

#include "palette.h"

#ifndef BITMAP_YUV2

// CHDK palette colors for cameras with yuv overlay

// Colors for all camera modes
unsigned char ply_colors[] =
{
        COLOR_TRANSPARENT,         // Placeholder for script colors
        COLOR_BLACK,               // Placeholder for script colors
        0x0f,                       // White
        0xbe,                       // Red
        0xd5,                       // Dark Red
        0x7a,                       // Light Red
        0x61,                       // Green
        0xc5,                       // Dark Green
        0x05,                       // Light Green
        0xa9,                       // Blue
        0xee,                       // Dark Blue
        0x45,                       // Light Blue / Cyan
        0x74,                       // Grey
        0xb4,                       // Dark Grey
        0x34,                       // Light Grey
        0x11,                       // Yellow
        0x5a,                       // Dark Yellow
        0x0e,                       // Light Yellow
        0xb0,                       // Transparent Dark Grey
        0xfe,                       // Magenta
};

#endif
