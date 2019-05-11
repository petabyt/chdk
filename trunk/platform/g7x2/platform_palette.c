// CHDK palette colors for the G7X2
// Define color values as needed in this file.

#include "palette.h"

int bpp32_colors[] =
{
        0x00000000,                 // Transparent
        0xFF000000,                 // Black
        0xFFFFFFFF,                 // White
        0xFFFF0000,                 // Red
        0xFFA00000,                 // Dark Red
        0xFFFF8080,                 // Light Red
        0xFF00FF00,                 // Green
        0xFF00A000,                 // Dark Green
        0xFF80FF80,                 // Light Green
        0xFF0000FF,                 // Blue
        0xFF0000A0,                 // Dark Blue
        0xFF00FFFF,                 // Light Blue / Cyan
        0xFF808080,                 // Grey
        0xFF404040,                 // Dark Grey
        0xFFC0C0C0,                 // Light Grey
        0xFFFFFF00,                 // Yellow
        0xFFA0A000,                 // Dark Yellow
        0xFFFFFF80,                 // Light Yellow
        0x80404040,                 // Transparent Dark Grey (blue actually)
        0xFFFF00FF,                 // Magenta
};

unsigned char ply_colors[] =
{
        COLOR_TRANSPARENT,
        COLOR_BLACK,
        2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19
};
