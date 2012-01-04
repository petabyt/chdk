#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "lang.h"
#include "conf.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_batt.h"
#include "gui_mbox.h"

#include "module_load.h"

void gui_module_menu_kbd_process();
void gui_snake_kbd_process();
void gui_snake_draw();

gui_handler GUI_MODE_SNAKE = 
    /*GUI_MODE_SNAKE*/  { GUI_MODE_MODULE,   gui_snake_draw,     gui_snake_kbd_process,    gui_module_menu_kbd_process, GUI_MODE_FLAG_NODRAWRESTORE, GUI_MODE_MAGICNUM };


//-------------------------------------------------------------------
#define SNAKE_MAX_LENGTH 0xF0
#define SNAKE_ELEMENT_SIZE 8
#define RING_WIDTH 42
#define RING_HEIGHT 24
enum{
  DIR_LEFT = 0,
  DIR_RIGHT,
  DIR_UP,
  DIR_DOWN
};
unsigned char ring[RING_WIDTH][RING_HEIGHT];
unsigned short snake_head;
unsigned short snake_tail;
unsigned char snake[SNAKE_MAX_LENGTH][2];
unsigned int points;
unsigned char level;
unsigned char direction;
char str_buf[40];

const unsigned char labyrinth[4][RING_HEIGHT][RING_WIDTH] = {
    {
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     },
    {
     "##########################################",
     "#                                        #",
     "#                                        #",
     "#                                        #",
     "#     ############                       #",
     "#                #                       #",
     "#                #                       #",
     "#                #########################",
     "#                #                       #",
     "#                #                       #",
     "#                #                       #",
     "#                        ######          #",
     "#                        #    #          #",
     "#            #############    #          #",
     "#           #                 #          #",
     "#          #                  #          #",
     "#         #                   #          #",
     "#        #                    #          #",
     "#       #                     #          #",
     "#       #                     #          #",
     "#                             #          #",
     "#                             #          #",
     "#                             #          #",
     "##########################################",
     },

    {
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                  ##########              ",
     "                           #              ",
     "                           #              ",
     "                           #              ",
     "                    ########              ",
     "                    #                     ",
     "                    #                     ",
     "                    #                     ",
     "                    #                     ",
     "                                          ",
     "                    #                     ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     "                                          ",
     },

    {
     "                                          ",
     "                  #                       ",
     "                  #                       ",
     "                  #                       ",
     "     ##########################           ",
     "                           #              ",
     "                           #              ",
     "            ##########     #              ",
     "    #                      ####           ",
     "    #                                     ",
     "    #                                     ",
     "    #                                     ",
     "    #                                     ",
     "    #                                     ",
     "    #################            #        ",
     "                                 #        ",
     "            #                    #        ",
     "     ########                    #        ",
     "                                 #        ",
     "       ###########################        ",
     "                                 #        ",
     "                                 #        ",
     "                                 #        ",
     "                                          ",
     },
};

const char head[8][8] = {
  "     GG ",
  "    GBBG",
  "    G BG",
  " GGGGGGG",
  "RGGGGGGG",
  " GGGGGGG",
  "        ",
  "        ",
};

const char tail[8][8] = {
  "        ",
  "        ",
  "        ",
  "G GGG GG",
  "GGGGGGGG",
  "GGG GGG ",
  "        ",
  "        ",
};

const char tail2[8][8] = {
  "        ",
  "        ",
  "        ",
  " GG     ",
  "GGGG    ",
  "GGGGG   ",
  "  GGG   ",
  "  GG    ",
};

const char apple[8][8] = {
  "        ",
  " GGGB   ",
  "GGG B   ",
  " G RRR  ",
  "  RRRRR ",
  "  RRRRR ",
  "  RRRRR ",
  "   RRR  ",
};

const char wall[8][8] = {
  "OOOOO OO",
  "OOOOO OO",
  "        ",
  "OO OOOOO",
  "OO OOOOO",
  "        ",
  "OOOOO OO",
  "OOOOO OO",
};

static void draw_element(int x,int y,const char element[8][8],char angle){
  x = x * SNAKE_ELEMENT_SIZE;
  y = y * SNAKE_ELEMENT_SIZE;
  int xx,yy;
  for(xx=0;xx<SNAKE_ELEMENT_SIZE;xx++)
    for(yy=0;yy<SNAKE_ELEMENT_SIZE;yy++){
      char c = COLOR_RED;
      char col = 0;

      if(angle == 0) col = element[yy][xx];
      if(angle == 1) col = element[xx][7-yy];
      if(angle == 2) col = element[xx][yy];
      if(angle == 3) col = element[yy][7-xx];
      if(angle == 4) col = element[7-xx][yy];
      switch(col){
        case 'R': c = COLOR_RED; break;
        case 'G': c = COLOR_GREEN; break;
        case 'B': c = COLOR_BLACK; break;
        case 'b': c = COLOR_BLUE; break;
        case 'Y': c = COLOR_YELLOW; break;
        case 'O': c = 0x28; break;
        default: c = COLOR_WHITE; break;
      };
      draw_pixel( x+xx, y+yy, c );
    }
}



static void load_laby(int num){
  int x,y;
  for(x=0;x<RING_WIDTH;x++)
    for(y=0;y<RING_HEIGHT;y++){
      ring[x][y] = labyrinth[num][y][x];
      if(ring[x][y] != ' '){
        draw_element(x,y,wall,0);
      }else{
        draw_filled_rect(x * SNAKE_ELEMENT_SIZE,
                         y * SNAKE_ELEMENT_SIZE,
                         x * SNAKE_ELEMENT_SIZE+SNAKE_ELEMENT_SIZE-1,
                         y * SNAKE_ELEMENT_SIZE+SNAKE_ELEMENT_SIZE-1, MAKE_COLOR(COLOR_WHITE,COLOR_WHITE));
      }
    }
}

static void snake_generate_apple()
{
  int x,y,i;
  while(1)
  {
    randomagain:
    x = rand() % RING_WIDTH;
    y = rand() % RING_HEIGHT;
    if(ring[x][y] != ' ') continue;
    i = snake_tail;
    while(1){
      if(snake[i][0] == x && snake[i][1] == y) goto randomagain;
      if(i == snake_head) break;
      i = (i+1)%SNAKE_MAX_LENGTH;
    }
    draw_element(x,y,apple,0);
    ring[x][y] = 1;
    break;
  }
}

static void game_over();

static void snake_start(){
  int i;
  load_laby(rand()%4);
  snake_head = 3;
  snake_tail = 0;
  level = 5;
  points = 0;
  for(i=snake_tail;i<snake_head;i++){
    snake[i][0] = 2+i;
    snake[i][1] = 2;
    draw_filled_rect(snake[i][0] * SNAKE_ELEMENT_SIZE,
                     snake[i][1] * SNAKE_ELEMENT_SIZE,
                     snake[i][0] * SNAKE_ELEMENT_SIZE+SNAKE_ELEMENT_SIZE-1,
                     snake[i][1] * SNAKE_ELEMENT_SIZE+SNAKE_ELEMENT_SIZE-1, MAKE_COLOR(COLOR_WHITE,COLOR_RED));
  }
  direction = DIR_RIGHT;
  for(i=0;i<10;i++)
    snake_generate_apple();
}


static void game_over(){
    draw_filled_rect(0,0,camera_screen.width,camera_screen.height, COLOR_WHITE);
    sprintf(str_buf,"Points: %d",points);
    draw_string(0,0,str_buf, MAKE_COLOR(COLOR_WHITE, COLOR_BLUE));
    msleep(3000);
    snake_start();
}

void gui_snake_kbd_process() {
    switch (kbd_get_autoclicked_key()) {
        case KEY_UP:
            if(direction != DIR_DOWN) direction = DIR_UP;
            break;
        case KEY_DOWN:
            if(direction != DIR_UP) direction = DIR_DOWN;
            break;
        case KEY_LEFT:
                if(direction != DIR_RIGHT) direction = DIR_LEFT;
            break;
        case KEY_RIGHT:
                if(direction != DIR_LEFT) direction = DIR_RIGHT;
            break;
        case KEY_SET:
             
             
            break;
        case KEY_ERASE:
        case KEY_DISPLAY:
            break;
    }
}

void gui_snake_draw() {
  unsigned short new_head;
  unsigned short new_tail;
  unsigned short new_cord;
  char game_over_flag = 0,draw_head,clear_tail,draw_points=1;
  unsigned char prevdir = direction;
  unsigned int i;
    new_head = (snake_head+1)%SNAKE_MAX_LENGTH;
    new_tail = (snake_tail+1)%SNAKE_MAX_LENGTH;
    draw_head = 1;
    clear_tail = 1;
    if(direction == DIR_RIGHT){
      new_cord = (snake[snake_head][0]+1)%RING_WIDTH;
      snake[new_head][0] = new_cord;
      snake[new_head][1] = snake[snake_head][1];
    }
    if(direction == DIR_LEFT){
      new_cord = snake[snake_head][0]-1;
      if(new_cord == 0xFFFF) new_cord = RING_WIDTH-1;
      snake[new_head][0] = new_cord;
      snake[new_head][1] = snake[snake_head][1];
    }
    if(direction == DIR_UP){
      new_cord = snake[snake_head][1]-1;
      if(new_cord == 0xFFFF) new_cord = RING_HEIGHT-1;
      snake[new_head][0] = snake[snake_head][0];
      snake[new_head][1] = new_cord;
    }
    if(direction == DIR_DOWN){
      new_cord = (snake[snake_head][1]+1)%RING_HEIGHT;
      snake[new_head][0] = snake[snake_head][0];
      snake[new_head][1] = new_cord;
    }

    i = snake_tail;
    while(1){
      if(snake[i][0] == snake[new_head][0] && snake[i][1] == snake[new_head][1]){
        game_over_flag = 1;
        break;
      }
      if(i == snake_head) break;
      i = (i+1)%SNAKE_MAX_LENGTH;
    }

    if(ring[snake[new_head][0]][snake[new_head][1]] == 1){
      ring[snake[new_head][0]][snake[new_head][1]] = ' ';
      snake_generate_apple();
      points+=level;
      draw_points = 1;
      if((new_head+1)%SNAKE_MAX_LENGTH != snake_tail){
        new_tail = snake_tail;
        clear_tail = 0;
      }
    }else if(ring[snake[new_head][0]][snake[new_head][1]] != ' '){
      game_over_flag = 1;
    }
    if(draw_head){
      if(direction == DIR_UP) draw_element(snake[new_head][0],snake[new_head][1],head,2);   //up
      if(direction == DIR_LEFT) draw_element(snake[new_head][0],snake[new_head][1],head,0);  //left
      if(direction == DIR_DOWN) draw_element(snake[new_head][0],snake[new_head][1],head,1);  //down
      if(direction == DIR_RIGHT) draw_element(snake[new_head][0],snake[new_head][1],head,3);  //right

      new_cord = snake_head-1;
      if(new_cord == 0xFFFF) new_cord = SNAKE_MAX_LENGTH-1;
      if(snake[new_cord][0] > snake[new_head][0] && snake[new_cord][1] > snake[new_head][1] && direction == DIR_UP) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,2);
      else if(snake[new_cord][0] > snake[new_head][0] && snake[new_cord][1] > snake[new_head][1] && direction == DIR_LEFT) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,0);
      else if(snake[new_cord][0] < snake[new_head][0] && snake[new_cord][1] > snake[new_head][1] && direction == DIR_UP) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,4);
      else if(snake[new_cord][0] < snake[new_head][0] && snake[new_cord][1] > snake[new_head][1] && direction == DIR_RIGHT) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,3);
      else if(snake[new_cord][0] < snake[new_head][0] && snake[new_cord][1] < snake[new_head][1] && direction == DIR_RIGHT) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,2);
      else if(snake[new_cord][0] < snake[new_head][0] && snake[new_cord][1] < snake[new_head][1] && direction == DIR_DOWN) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,0);
      else if(snake[new_cord][0] > snake[new_head][0] && snake[new_cord][1] < snake[new_head][1] && direction == DIR_LEFT) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,4);
      else if(snake[new_cord][0] > snake[new_head][0] && snake[new_cord][1] < snake[new_head][1] && direction == DIR_DOWN) draw_element(snake[snake_head][0],snake[snake_head][1],tail2,3);
      else if(prevdir == direction && (direction == DIR_RIGHT || direction == DIR_LEFT)) draw_element(snake[snake_head][0],snake[snake_head][1],tail,0);
      else if(prevdir == direction && (direction == DIR_UP || direction == DIR_DOWN)) draw_element(snake[snake_head][0],snake[snake_head][1],tail,1);
    }
    prevdir = direction;
    if(clear_tail){
        draw_filled_rect(snake[snake_tail][0] * SNAKE_ELEMENT_SIZE,
                         snake[snake_tail][1] * SNAKE_ELEMENT_SIZE,
                         snake[snake_tail][0] * SNAKE_ELEMENT_SIZE+SNAKE_ELEMENT_SIZE-1,
                         snake[snake_tail][1] * SNAKE_ELEMENT_SIZE+SNAKE_ELEMENT_SIZE-1, COLOR_WHITE);
    }
    snake_head = new_head;
    snake_tail = new_tail;
    msleep(100);
    if(game_over_flag){
      game_over();
      game_over_flag = 0;
    }
    if(draw_points){
      draw_points = 0;
      sprintf(str_buf,"Points: %d",points);
      draw_string(10,220,str_buf, MAKE_COLOR(COLOR_WHITE, COLOR_BLUE));
    }
}

int gui_snake_init() {
    draw_filled_rect(0,0,camera_screen.width,camera_screen.height, COLOR_WHITE);
    snake_start();
	gui_set_mode(&GUI_MODE_SNAKE);
    return 1;
}

extern int module_idx;
void gui_module_menu_kbd_process() {
	gui_default_kbd_process_menu_btn();
  	module_async_unload(module_idx);
}


// =========  MODULE INIT =================
#include "module_load.h"
int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)0
		};


//---------------------------------------------------------
// PURPOSE:   Bind module symbols with chdk. 
//		Required function
// PARAMETERS: pointer to chdk list of export
// RETURN VALUE: 1 error, 0 ok
//---------------------------------------------------------
int _module_loader( void** chdk_export_list )
{
  if ( (unsigned int)chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;
  if ( !API_VERSION_MATCH_REQUIREMENT( gui_version.common_api, 1, 0 ) )
	  return 1;

  return 0;
}



//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
  return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  int rv = gui_snake_init();
  if ( ! rv )
	module_async_unload(moduleidx);		// fail to init - "unload me"

  return 0;
}

/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									0,							// flag
									(int32_t)"Snake",			// Module name
									1, 0,						// Module version
									(int32_t)"Game"
								 };


/*************** END OF AUXILARY PART *******************/
