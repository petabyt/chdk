#include "stdio.h"
#include "../lib/font/font_8x16_uni.h"
#include "../lib/font/codepages.h"

//
// Tool to generate run-time font and codepage data
//
// Creates compressed font_data array and run-time codepage tables
// Avoids generating static tables at startup of CHDK.
//

//-------------------------------------------------------------------
#define DEFAULT_SYMBOL          0xFFFD

//-------------------------------------------------------------------
// Packed font data
unsigned char font_data[16384];
unsigned short char_codes[4096];    // List of used charcodes
unsigned short font_offsets[4096];  // Offsets into font_data for each charcode

//-------------------------------------------------------------------
static unsigned short font_find_offset(unsigned short charcode)
{
    int i=0;

    for (i=0; char_codes[i] != 0xFFFF; i++)
    {
        if (char_codes[i] == charcode)
            return font_offsets[i];
    }
    return 0xFFFF;
}

//-------------------------------------------------------------------
static void font_init_data(unsigned short *src, int st, int num)
{
    int i;
    unsigned short f;

    for (i=0; i<num; ++i)
    {
        f = font_find_offset(src[i]);
        if (f == 0xFFFF)
            f = font_find_offset(DEFAULT_SYMBOL);
        src[st+i] = f;
    }
}

//-------------------------------------------------------------------
static void check_used(unsigned short *cp)
{
    int i;
    for (i=0; i<128; i++)
    {
        unsigned short c = cp[i];
        int j;
        for (j=0; orig_font_data[j].charcode != -1; j++)
        {
            if (orig_font_data[j].charcode == c)
            {
                orig_font_data[j].isUsed++;
            }
        }
    }
}

//-------------------------------------------------------------------

int main(int argc, char **argv)
{
    int i, j, f = 0, cc = 0;

    int ncp = sizeof(codepages)/(sizeof(unsigned short*));
    
    // Check if chars in font are used in any codepages
    check_used(cp_common);
    for (j=0; j<ncp; j++)
    {
        check_used(codepages[j]);
    }

    printf("// This is a compressed version of font_8x16_uni.h produced by the tools/font_8x16_pack program\n\n");
    printf("// Format of each character is 'FontData' structure, followed by FontData.size bytes of character data.\n\n");
    printf("static unsigned char font_data[] = {\n");

    for (i=0; orig_font_data[i].charcode != -1; i++)
    {
        if (orig_font_data[i].isUsed > 0)
        {
            int top = 0;
            int bottom = 0;
            for (j=0; j<16 && orig_font_data[i].data[j] == 0; j++) { top++; }
            for (j=15; j>=top && orig_font_data[i].data[j] == 0; j--) { bottom++; }
            if (top == 16)  // Blank character
            {
                // Fix values to fit into 4 bits each (sorted out in draw_char function)
                top--;
                bottom++;
            }

            char_codes[cc] = orig_font_data[i].charcode;
            font_offsets[cc] = f;
            cc++;

            font_data[f++] = (top << 4) | bottom;

            printf("/*%04x*/ 0x%02x,", orig_font_data[i].charcode, (top << 4) | bottom);
            for (j=top; j<16-bottom; j++)
            {
                font_data[f++] = orig_font_data[i].data[j] & 0xFF;
                printf(" 0x%02x,",orig_font_data[i].data[j] & 0xFF);
            }
            printf("\n");
        }
    }

    char_codes[cc] = 0xFFFF;

    printf("};\n\n");

    // Set up codepage entries, and save to file
    font_init_data(cp_common, 0, 128);

    printf("// Offsets to font character data stored in the font_data array.\n\n");
    printf("static unsigned short cp_common[] =\n{\n");
    for (i=0; i<128; i++)
    {
        if ((i & 15) == 0) printf("    ");
        printf("0x%04x,", cp_common[i]);
        if ((i & 15) == 15) printf("\n");
    }
    printf("};\n");

    for (j=0; j<ncp; j++)
    {
        font_init_data(codepages[j], 0, 128);
        printf("static unsigned short cp_win_%s[] =\n{\n", cp_names[j]);
        for (i=0; i<128; i++)
        {
            if ((i & 15) == 0) printf("    ");
            printf("0x%04x,", codepages[j][i]);
            if ((i & 15) == 15) printf("\n");
        }
        printf("};\n");
    }

    printf("\n// Array of pointers to codepage tables.\n\n");
    printf("static unsigned short* codepages[] =\n{\n");
    for (j=0; j<ncp; j++)
    {
        printf("    cp_win_%s,\n", cp_names[j]);
    }
    printf("};\n");

    printf("\n// Codepage names for menu UI in gui.c (gui_font_enum).\n\n");
    printf("int num_codepages = %d;\n",ncp);
    printf("char* codepage_names[] =\n{\n");
    for (j=0; j<ncp; j++)
    {
        printf("    \"Win%s\",\n", cp_names[j]);
    }
    printf("};\n");

    return 0;
}
