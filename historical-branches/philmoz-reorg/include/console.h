#ifndef _CONSOLE_H
#define _CONSOLE_H

// CHDK console OSD interface

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

#define MAX_CONSOLE_LINES        14
#define MAX_CONSOLE_LINE_LENGTH  45
#define CONSOLE_HIDE_TIMEOUT     3000

extern void console_close();
extern void console_init(int num_lines, int line_length, int x_pos, int y_pos);
extern void console_clear();
extern void console_add_line(const char *str);
extern void console_draw();
extern void console_set_layout(int x1, int y1, int x2, int y2);
extern void console_redraw();
extern void console_set_autoredraw(int val);

extern int console_displayed;

#endif // _CONSOLE_H

