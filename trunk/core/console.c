#include "camera_info.h"
#include "stdlib.h"
#include "console.h"
#include "clock.h"
#include "gui.h"
#include "gui_draw.h"

#define MAX_CONSOLE_LINES        14
#define MAX_CONSOLE_LINE_LENGTH  45
#define CONSOLE_HIDE_TIMEOUT     3000

// Static buffer for console output
static char console_data[MAX_CONSOLE_LINES*(MAX_CONSOLE_LINE_LENGTH+1)];
// Pointers for each line in the console - points into console_data array
static char* console_buf[MAX_CONSOLE_LINES];
// Flag for initialisation of console_buf
static int console_buffer_inited;

static int console_max_lines;           // total number of lines in console
static int console_num_lines;           // number of valid lines
static int console_line_length = 0;     // current console width
static int console_x;                   // screen X position
static int console_y;                   // screen Y position
static int console_autoredraw = 1;
static long console_last_drawn;
int console_displayed = 0;

static void console_init(int num_lines, int line_length, int x_pos, int y_pos)
{
    console_max_lines = num_lines;
    console_line_length = line_length;
    console_y = y_pos;
    console_x = x_pos;

    console_num_lines = 0;
    console_last_drawn = 0;
}

static int console_is_inited()
{
    return (console_line_length > 0);
}

static void console_ensure_inited()
{
    if (!console_buffer_inited)
    {
        int i;
        for (i=0; i<MAX_CONSOLE_LINES; i++)
            console_buf[i] = &console_data[i*(MAX_CONSOLE_LINE_LENGTH+1)];
        console_buffer_inited = 1;
    }

    if (!console_is_inited())
        console_init(5, 25, 0, MAX_CONSOLE_LINES - 5);
}

static void console_start_line()
{
    if (console_max_lines == console_num_lines)
    {
        // Scroll lines up
        int i;
        char *tmp = console_buf[0];
        for (i=1; i<console_max_lines; i++)
            console_buf[i-1] = console_buf[i];
        console_buf[i-1] = tmp;
    }
    else
        ++console_num_lines;
    
    console_buf[console_num_lines - 1][0] = 0;
}

void console_close()
{
    console_line_length = 0;
}

void console_clear()
{
    console_num_lines = 0;
    
    if (console_autoredraw)
        console_redraw();
}

void console_draw()
{
    console_ensure_inited();

    console_displayed = 0;

    long t = get_tick_count();
    if (t <= console_last_drawn + CONSOLE_HIDE_TIMEOUT)
    {
        int y = (console_y + console_max_lines - console_num_lines) * FONT_HEIGHT;
        int x = console_x * FONT_WIDTH + camera_screen.ts_button_border;

        int c;
        for (c = 0; c < console_num_lines; ++c)
        {
            draw_string(x, y + c * FONT_HEIGHT, console_buf[c], MAKE_COLOR(COLOR_BG, COLOR_FG));

            int l = strlen(console_buf[c]);
            
            if (l < console_line_length)
                draw_filled_rect(x + l * FONT_WIDTH, y + c * FONT_HEIGHT,
                                 x + console_line_length * FONT_WIDTH, y + c * FONT_HEIGHT + FONT_HEIGHT,
                                 MAKE_COLOR(COLOR_BG, COLOR_BG));

            console_displayed = 1;
        }
    }
}

void console_add_line(const char *str)
{
	// Set console_autoredraw to -1 to stop script print statements from being displayed on screen
	// Can be used to send script output to a file (using print_screen function); but not have it displayed
	// on the LCD.
    if (console_autoredraw == -1)
	    return;

    console_ensure_inited();
    console_start_line();
    
    do
    {
        char *cur = console_buf[console_num_lines - 1];
        int curlen = strlen(cur);
        int left = console_line_length - curlen;
        if (strlen(str) > left)
        {
            strncpy(cur + curlen, str, left);
            cur[console_line_length] = 0;
            console_start_line();
            str += left;
        }
        else
        {
            strcat(cur, str);
            break;
        }
    } while(1);
    
    console_last_drawn = get_tick_count();

	if (console_autoredraw)
		console_draw();
}

void console_set_layout(int x1, int y1, int x2, int y2) //untere linke Ecke(x1,y1), obere reche Ecke(x2,y2) - lower left corner (x1,y1), upper right corner(x2,y2)
{
    int i, len, newLinesCount, newLineLength, newNumLines, lineDelta, idx;
    
    // Swap co-ords so x1 < x2 & y1 < y2
    if (x1 > x2) { i = x1; x1 = x2; x2 = i; }
    if (y1 > y2) { i = y1; y1 = y2; y2 = i; }

    if ((x1 >= 0) && (y1 >= 0) && (x2 <= MAX_CONSOLE_LINE_LENGTH) && (y2 <= MAX_CONSOLE_LINES))
    {
        //Adjust for new size if needed
        newLineLength = x2 - x1;
        newLinesCount = y2 - y1;
        newNumLines = console_num_lines;

        // If number of lines in console has reduced and old console has too many lines
        if (newNumLines > newLinesCount)
        {
            // Move bottom most lines to fit into new console
            for (i=newNumLines-newLinesCount; i<newNumLines; i++)
                console_buf[i-(newNumLines-newLinesCount)] = console_buf[i];
            newNumLines = newLinesCount;
        }

        // If new console is narrower truncate existing lines
        if (newLineLength < console_line_length)
        {
            for (i=0; i<newNumLines; i++)
                console_buf[i][newLineLength] = 0;
        }

        //neue Werte setzten - set new values
        console_num_lines = newNumLines;
        console_max_lines = newLinesCount;
        console_line_length = newLineLength;
        
        console_x = x1;
        console_y = MAX_CONSOLE_LINES - y2;

		if (console_autoredraw)
			console_redraw();
    }
}

void console_set_autoredraw(int val)
{
	console_autoredraw = val;
}

void console_redraw()
{
	draw_restore();
	console_last_drawn = get_tick_count();
	console_draw();
}

