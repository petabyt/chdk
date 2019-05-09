/*
 * palette.h
 *
 *  Created on: 1 Nov 2014
 *      Author: philmoz
 */

#ifndef INCLUDE_PALETTE_H_
#define INCLUDE_PALETTE_H_

//-------------------------------------------------------------------

// Common colors that are the same in all palettes
#define COLOR_TRANSPARENT               0x00
#define COLOR_BLACK                     0xFF

//-------------------------------------------------------------------

#define IDX_COLOR_TRANSPARENT       0
#define IDX_COLOR_BLACK             1
#define IDX_COLOR_WHITE             2
#define IDX_COLOR_RED               3
#define IDX_COLOR_RED_DK            4
#define IDX_COLOR_RED_LT            5
#define IDX_COLOR_GREEN             6
#define IDX_COLOR_GREEN_DK          7
#define IDX_COLOR_GREEN_LT          8
#define IDX_COLOR_BLUE              9
#define IDX_COLOR_BLUE_DK           10
#define IDX_COLOR_BLUE_LT           11
#define IDX_COLOR_GREY              12
#define IDX_COLOR_GREY_DK           13
#define IDX_COLOR_GREY_LT           14
#define IDX_COLOR_YELLOW            15
#define IDX_COLOR_YELLOW_DK         16
#define IDX_COLOR_YELLOW_LT         17
#define IDX_COLOR_GREY_DK_TRANS     18
#define IDX_COLOR_MAGENTA           19
#define IDX_COLOR_CYAN              IDX_COLOR_BLUE_LT

#define IDX_COLOR_MAX               19

#ifdef BITMAP_YUV2

#define COLOR_WHITE             IDX_COLOR_WHITE
#define COLOR_RED               IDX_COLOR_RED
#define COLOR_RED_DK            IDX_COLOR_RED_DK
#define COLOR_RED_LT            IDX_COLOR_RED_LT
#define COLOR_GREEN             IDX_COLOR_GREEN
#define COLOR_GREEN_DK          IDX_COLOR_GREEN_DK
#define COLOR_GREEN_LT          IDX_COLOR_GREEN_LT
#define COLOR_BLUE              IDX_COLOR_BLUE
#define COLOR_BLUE_DK           IDX_COLOR_BLUE_DK
#define COLOR_BLUE_LT           IDX_COLOR_BLUE_LT
#define COLOR_GREY              IDX_COLOR_GREY
#define COLOR_GREY_DK           IDX_COLOR_GREY_DK
#define COLOR_GREY_LT           IDX_COLOR_GREY_LT
#define COLOR_YELLOW            IDX_COLOR_YELLOW
#define COLOR_YELLOW_DK         IDX_COLOR_YELLOW_DK
#define COLOR_YELLOW_LT         IDX_COLOR_YELLOW_LT
#define COLOR_GREY_DK_TRANS     IDX_COLOR_GREY_DK_TRANS
#define COLOR_MAGENTA           IDX_COLOR_MAGENTA
#define COLOR_CYAN              IDX_COLOR_CYAN

#define CHDK_2_CANON_COLOR(c)   (c)

#else

extern  unsigned char   *chdk_colors;

#define COLOR_WHITE             (chdk_colors[IDX_COLOR_WHITE])
#define COLOR_RED               (chdk_colors[IDX_COLOR_RED])
#define COLOR_RED_DK            (chdk_colors[IDX_COLOR_RED_DK])
#define COLOR_RED_LT            (chdk_colors[IDX_COLOR_RED_LT])
#define COLOR_GREEN             (chdk_colors[IDX_COLOR_GREEN])
#define COLOR_GREEN_DK          (chdk_colors[IDX_COLOR_GREEN_DK])
#define COLOR_GREEN_LT          (chdk_colors[IDX_COLOR_GREEN_LT])
#define COLOR_BLUE              (chdk_colors[IDX_COLOR_BLUE])
#define COLOR_BLUE_DK           (chdk_colors[IDX_COLOR_BLUE_DK])
#define COLOR_BLUE_LT           (chdk_colors[IDX_COLOR_BLUE_LT])
#define COLOR_GREY              (chdk_colors[IDX_COLOR_GREY])
#define COLOR_GREY_DK           (chdk_colors[IDX_COLOR_GREY_DK])
#define COLOR_GREY_LT           (chdk_colors[IDX_COLOR_GREY_LT])
#define COLOR_YELLOW            (chdk_colors[IDX_COLOR_YELLOW])
#define COLOR_YELLOW_DK         (chdk_colors[IDX_COLOR_YELLOW_DK])
#define COLOR_YELLOW_LT         (chdk_colors[IDX_COLOR_YELLOW_LT])
#define COLOR_GREY_DK_TRANS     (chdk_colors[IDX_COLOR_GREY_DK_TRANS])
#define COLOR_MAGENTA           (chdk_colors[IDX_COLOR_MAGENTA])
#define COLOR_CYAN              (chdk_colors[IDX_COLOR_CYAN])

#define CHDK_2_CANON_COLOR(c)   chdk_colors[c]

#endif

//-------------------------------------------------------------------

#endif /* INCLUDE_PALETTE_H_ */
