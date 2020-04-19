// G16 1.01c
#include "stubs_asm.h"

DEF(file_counter_var              ,0x000124f8)           // @0xfc1c3244 - found by searching for "FileBackupProperty.c"

DEF(active_raw_buffer             ,0x0000bd9c)           // 0x0000bd90 + 0x0c (@fc1552ae & @fc155312)
DEF(raw_buffers                   ,0xfc598218)           // Found @fc186428 or @fc1865de , "DevelopAddress.c"
DEF(raw_buffers_jpeg              ,0xfc5b5368)           // near DevelopPipeline.c at 0xfc192a32:

DEF(bitmap_buffer                 ,0xC984)               // struct @ 0x0000c94c + 0x38  from [ 0xfc15a834: in G16] match to [fc1439f2: in sx280] and [fc361eae: in G7x]
DEF(active_bitmap_buffer          ,0xC97C)               // subtract 8 because that's what g7x, sx280, g16 use
DEF(current_fb_d                  ,0x0000fbe4+0x24)      // found @fc1b424e similiar to sx280 102b @0xfc186624 and g7x 100d 0xfc1ba452
DEF(current_viewport_buffer       ,0x8858+0x38)          // GetMovieJpegVRAMVPixelsSize_FW 0xfc144a09
DEF(viewport_buffers              ,0xfc571014)           // multiple refs like @ 0xfc14426a - add 0x010 like sx280 & g7x

DEF(simple_movie_status           ,0x0000bae8+0x80+0x0c) // found @fc14efb6 sub_fc14ef9c via task_MovieRecord. 1 when recording or busy after, 0 otherwise
DEF(full_screen_refresh           ,0x00012a94)           // Found @0xfc30a954
DEF(canon_menu_active             ,0x0000c9ac+0x8)       // found @fc2caab4:, via call to sub_fc2caab2 , near ref to "MviCon_ClrEvt" @fc1456c4
DEF(zoom_status                   ,0x0000f88c)           // after "TerminateDeliverToZoomController" 0xfc1af414 = 0xf8ac - 0x20
DEF(dial_positions                ,0x0000fdd4)           // 0xfc06befe: matches g7x 
DEF(focus_len_table               ,0xfdf2bd38)           // G16 search upper meory for [000017D4 00000064] and [00007724 00000064]  (6.1-30.5 mm)

//******* values below need to be checked *************
DEF(recreview_hold                ,0x00008f18)           // G16  - found @0fc2fdcc4 ( *"StartRecReviewTimer" )
                                                         //      - NOTE : this is just review mode - recreview_hold is true when (0x8f18 == 1) && (0x8f1C == 0) 

//******* values below not found yet *************
FAKEDEF(canon_shoot_menu_active   ,1)                    // not found for any DIGIC6 camera


