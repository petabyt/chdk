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
// Format of header block for each character in the packed 'font_data' array
// This is immediately followed by 'size' bytes of character data.
typedef struct {
    unsigned char charcode[2];      // Don't change this to a short as the data is not aligned in memory
    unsigned char offset;
    unsigned char size;
} FontData;

//-------------------------------------------------------------------
#define DEFAULT_SYMBOL          0xFFFD

//-------------------------------------------------------------------
// Packed font data
unsigned char font_data[16384];

//-------------------------------------------------------------------
static FontData* font_find_data (unsigned short charcode)
{
    int i=0;
    unsigned short c;

    while (1)
    {
        FontData *f = (FontData*)(font_data+i);
        c = (f->charcode[1] << 8) | f->charcode[0];
        if (c == 0xFFFF) return 0;
        if (c == charcode) return f;
        i = i + f->size + sizeof(FontData);
    }
    return 0;
}

//-------------------------------------------------------------------
static void font_init_data(unsigned short *src, int st, int num)
{
    int i;
    FontData *f;

    for (i=0; i<num; ++i)
    {
        f = font_find_data(src[i]);
        if (f == 0)
            f = font_find_data(DEFAULT_SYMBOL);
        src[st+i] = (short)((unsigned char*)f - font_data);
    }
}

//-------------------------------------------------------------------

int main(int argc, char **argv)
{
    int i, j, offset, size, f = 0;
    
    printf("// This is a compressed version of font_8x16_uni.h produced by the tools/font_8x16_pack program\n\n");
    printf("// Format of each character is 'FontData' structure, followed by FontData.size bytes of character data.\n\n");
    printf("static unsigned char font_data[] = {\n");

    for (i=0; orig_font_data[i].charcode != -1; i++)
    {
        offset = 0;
        size = 16;
        for (j=0; j<16 && orig_font_data[i].data[j] == 0; j++) { offset++; size--; }
        for (j=15; j>offset && orig_font_data[i].data[j] == 0; j--) { size--; }

        font_data[f++] = orig_font_data[i].charcode & 0xFF;
        font_data[f++] = (orig_font_data[i].charcode >> 8) & 0xFF;
        font_data[f++] = offset;
        font_data[f++] = size;

        printf("0x%02x, 0x%02x, 0x%02x, 0x%02x,", orig_font_data[i].charcode & 0xff, (orig_font_data[i].charcode >> 8) & 0xFF, offset, size);
        for (j=0; j<size; j++)
        {
            font_data[f++] = orig_font_data[i].data[offset+j] & 0xFF;
            printf(" 0x%02x,",orig_font_data[i].data[offset+j] & 0xFF);
        }
        printf("\n");
    }

    font_data[f++] = 0xFF;
    font_data[f++] = 0xFF;
    printf("0xff, 0xff\n};\n\n");

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

    int ncp = sizeof(codepages)/(sizeof(unsigned short*));

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
