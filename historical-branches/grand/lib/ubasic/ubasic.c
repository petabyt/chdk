/*
 * Copyright (c) 2006, Adam Dunkels
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#if DEBUG
#define DEBUG_PRINTF(...)  printf(__VA_ARGS__)
#else
#define DEBUG_PRINTF(...)
#endif

#ifdef TEST
#include "../../include/ubasic.h"
#include "../../include/platform.h"
#include "../../include/script.h"
#include <string.h>
#include <fcntl.h>
#include <io.h>
#else
#include "ubasic.h"
#include "platform.h"
#include "script.h"
#endif
#include "tokenizer.h"

#include "camera_functions.h"

#include "stdlib.h" /* exit() */

#ifdef DEBUG
#include <stdio.h>
#endif

static char const *program_ptr;
#define MAX_STRINGLEN 40
static char string[MAX_STRINGLEN];

#define MAX_GOSUB_STACK_DEPTH 10
static short gosub_stack[MAX_GOSUB_STACK_DEPTH];
static int gosub_stack_ptr;

struct for_state {
  short line_after_for;
  short for_variable;
  int to;
};
#define MAX_FOR_STACK_DEPTH 4
static struct for_state for_stack[MAX_FOR_STACK_DEPTH];
static int for_stack_ptr;

#define MAX_VARNUM 26
static int variables[MAX_VARNUM];

static int  print_screen_p;             // print_screen predicate: 0-off 1-on.
static int  print_screen_d = -1;        // print_screen file descriptor.
static const char print_screen_file[] ="A/CHDK/SCRIPTS/PR_SCREEN.TXT";

static int ended;

static int expr(void);
static void line_statement(void);
static void statement(void);
static int relation(void);

int ubasic_error;
const char *ubasic_errstrings[UBASIC_E_ENDMARK] = 
{
    "No err",
    "Parse err",
    "Unk stmt",
    "Unk key",
    "Unk label",
    "Stack ful",
    "bad return",
    "Unk err" 
};

/*---------------------------------------------------------------------------*/
int
ubasic_linenumber()
{
  return tokenizer_line_number();
}

/*---------------------------------------------------------------------------*/
void
ubasic_init(const char *program)
{
  program_ptr = program;
  for_stack_ptr = gosub_stack_ptr = 0;
  tokenizer_init(program);
  ended = 0;
  print_screen_p = 0;
  if (print_screen_d >= 0) {
    close(print_screen_d);
    print_screen_d = -1;
  }
  ubasic_error = UBASIC_E_NONE;
}
/*---------------------------------------------------------------------------*/
static void
accept(int token)
{
  if(token != tokenizer_token()) {
    DEBUG_PRINTF("Token not what was expected (expected %d, got %d)\n",
		 token, tokenizer_token());
    tokenizer_error_print();
     tokenizer_next();
     ended = 1;
     ubasic_error = UBASIC_E_PARSE;
     return;
  }
  DEBUG_PRINTF("Expected %d, got it\n", token);
  tokenizer_next();
}
/*---------------------------------------------------------------------------*/
static void
accept_cr()
{

    while(tokenizer_token() != TOKENIZER_CR)
      tokenizer_next();
    accept(TOKENIZER_CR);
}
/*---------------------------------------------------------------------------*/
static int
varfactor(void)
{
  int r;
  DEBUG_PRINTF("varfactor: obtaining %d from variable %d\n", variables[tokenizer_variable_num()], tokenizer_variable_num());
  r = ubasic_get_variable(tokenizer_variable_num());
  accept(TOKENIZER_VARIABLE);
  return r;
}
/*---------------------------------------------------------------------------*/
static int
factor(void)
{
  int r;

  DEBUG_PRINTF("factor: token %d\n", tokenizer_token());
  switch(tokenizer_token()) {
  case TOKENIZER_NUMBER:
    r = tokenizer_num();
    DEBUG_PRINTF("factor: number %d\n", r);
    accept(TOKENIZER_NUMBER);
    break;
  case TOKENIZER_LEFTPAREN:
    accept(TOKENIZER_LEFTPAREN);
    r = relation();
    accept(TOKENIZER_RIGHTPAREN);
    break;
  case TOKENIZER_PLUS:
    accept(TOKENIZER_PLUS);
    r = factor();
    break;
  case TOKENIZER_MINUS:
    accept(TOKENIZER_MINUS);
    r = - factor();
    break;
  case TOKENIZER_LNOT:
    accept(TOKENIZER_LNOT);
    r = ! relation();
    break;
  default:
    r = varfactor();
    break;
  }
  return r;
}
/*---------------------------------------------------------------------------*/
static int
term(void)
{
  int f1, f2;
  int op;

  f1 = factor();
  op = tokenizer_token();
  DEBUG_PRINTF("term: token %d\n", op);
  while(op == TOKENIZER_ASTR ||
	op == TOKENIZER_SLASH ||
	op == TOKENIZER_LT ||
	op == TOKENIZER_GT ||
	op == TOKENIZER_GE ||
	op == TOKENIZER_LE ||
	op == TOKENIZER_NE ||
	op == TOKENIZER_EQ ||
	op == TOKENIZER_XOR || 
        op == TOKENIZER_OR ||
	op == TOKENIZER_MOD) {
    tokenizer_next();
    f2 = factor();
    DEBUG_PRINTF("term: %d %d %d\n", f1, op, f2);
    switch(op) {
    case TOKENIZER_ASTR:
      f1 = f1 * f2;
      break;
    case TOKENIZER_SLASH:
      f1 = f1 / f2;
      break;
    case TOKENIZER_MOD:
      f1 = f1 % f2;
      break;
    case TOKENIZER_LT:
      f1 = f1 < f2;
      break;
    case TOKENIZER_GT:
      f1 = f1 > f2;
      break;
    case TOKENIZER_EQ:
      f1 = f1 == f2;
      break;
    case TOKENIZER_NE:
      f1 = f1 != f2;
      break;
    case TOKENIZER_LE:
      f1 = f1 <= f2;
      break;
    case TOKENIZER_GE:
      f1 = f1 >= f2;
      break;
    case TOKENIZER_OR:
      f1 = f1 | f2;
      break;
    case TOKENIZER_XOR:
      f1 = f1 ^ f2;
      break;
    }
    op = tokenizer_token();
  }
  DEBUG_PRINTF("term: %d\n", f1);
  return f1;
}
/*---------------------------------------------------------------------------*/
static int
expr(void)
{
  int t1, t2;
  int op;
  
  t1 = term();
  op = tokenizer_token();
  DEBUG_PRINTF("expr: token %d\n", op);
  while(op == TOKENIZER_PLUS ||
	op == TOKENIZER_MINUS ||
	op == TOKENIZER_AND ||
        op == TOKENIZER_LOR ||
	op == TOKENIZER_XOR) {
    tokenizer_next();
    t2 = term();
    DEBUG_PRINTF("expr: %d %d %d\n", t1, op, t2);
    switch(op) {
    case TOKENIZER_PLUS:
      t1 = t1 + t2;
      break;
    case TOKENIZER_MINUS:
      t1 = t1 - t2;
      break;
    case TOKENIZER_AND:
      t1 = t1 & t2;
      break;
    case TOKENIZER_LOR:
      t1 = t1 || t2;
      break;
    }
    op = tokenizer_token();
  }
  DEBUG_PRINTF("expr: %d\n", t1);
  return t1;
}
/*---------------------------------------------------------------------------*/
static int
relation(void)
{
  int r1, r2;
  int op;
  
  r1 = expr();
  op = tokenizer_token();
  DEBUG_PRINTF("relation: token %d\n", op);
  while(op == TOKENIZER_LAND) {
    tokenizer_next();
    r2 = expr();
    DEBUG_PRINTF("relation: %d %d %d\n", r1, op, r2);
    switch(op) {
    case TOKENIZER_LAND:
      r1 = r1 && r2;
      break;
    }
    op = tokenizer_token();
  }
  return r1;
}

#if 0
/*---------------------------------------------------------------------------*/
static void
jump_linenum(int linenum)
{
  tokenizer_init(program_ptr);
  while(tokenizer_num() != linenum) {
    do {
      do {
	tokenizer_next();
      } while(tokenizer_token() != TOKENIZER_CR &&
	      tokenizer_token() != TOKENIZER_ENDOFINPUT);
      if(tokenizer_token() == TOKENIZER_CR) {
	tokenizer_next();
      }
    } while(tokenizer_token() != TOKENIZER_NUMBER);
    DEBUG_PRINTF("jump_linenum: Found line %d\n", tokenizer_num());
  }
}
#endif

/*---------------------------------------------------------------------------*/
static void
jump_line(int linenum)
{
  tokenizer_init(program_ptr);
  while(tokenizer_line_number() != linenum) {
    tokenizer_next();
  }
  /* swallow the CR that would be read next */
  accept(TOKENIZER_CR);

}
/*---------------------------------------------------------------------------*/
// TODO: error handling?
static int
jump_label(char * label)
{
  char currLabel[MAX_STRINGLEN];
  tokenizer_init(program_ptr);
  currLabel[0] = 0;
  while(tokenizer_token() != TOKENIZER_ENDOFINPUT) {
    tokenizer_next();
    if (tokenizer_token() == TOKENIZER_LABEL) {
      tokenizer_label(currLabel, sizeof(currLabel));
      tokenizer_next();
      if(strcmp(label, currLabel) == 0) {
        accept(TOKENIZER_CR);
        DEBUG_PRINTF("jump_linenum: Found line %d\n", tokenizer_line_number());
        break;
      }
    }
  }
  if (tokenizer_token() == TOKENIZER_ENDOFINPUT) {
      DEBUG_PRINTF("Label %s not found", label);
      ubasic_error = UBASIC_E_UNK_LABEL;
      return 0;
  } else {
      return 1;
  }
}
/*---------------------------------------------------------------------------*/
static void
goto_statement(void)
{
  accept(TOKENIZER_GOTO);
  if(tokenizer_token() == TOKENIZER_STRING) {
    tokenizer_string(string, sizeof(string));
    tokenizer_next();
    jump_label(string);
  } else {
    DEBUG_PRINTF("ubasic.c: goto_statement(): no label specified\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNK_LABEL;
  }
}
/*---------------------------------------------------------------------------*/
static void
print_screen_statement(void)
{
  int val;
  accept(TOKENIZER_PRINT_SCREEN);
  val = expr();
  accept(TOKENIZER_CR);
  if (val && print_screen_d<0) {
      print_screen_d = open(print_screen_file, O_WRONLY|O_CREAT|O_TRUNC, 0777);
  }
  print_screen_p = val;
}
/*---------------------------------------------------------------------------*/
static void
print_statement(void)
{
  static char buf[128];

  buf[0]=0;
  accept(TOKENIZER_PRINT);
  do {
    DEBUG_PRINTF("Print loop\n");
    if(tokenizer_token() == TOKENIZER_STRING) {
      tokenizer_string(string, sizeof(string));
      sprintf(buf+strlen(buf), "%s", string);
      tokenizer_next();
    } else if(tokenizer_token() == TOKENIZER_COMMA) {
      strcat(buf, " ");
      tokenizer_next();
    } else if(tokenizer_token() == TOKENIZER_SEMICOLON) {
      tokenizer_next();
    } else {
      sprintf(buf+strlen(buf), "%d", expr());
    }
  } while(tokenizer_token() != TOKENIZER_CR && tokenizer_token() != TOKENIZER_ENDOFINPUT && tokenizer_token() != TOKENIZER_ELSE);
  script_console_add_line(buf);
  if (print_screen_p && print_screen_d>=0) {
    int bl = strlen(buf);
    buf[bl]='\n';
    write(print_screen_d, buf, bl+1);
  }
  DEBUG_PRINTF("End of print\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
if_statement(void)
{
  int r;
  
  accept(TOKENIZER_IF);

  r = relation();
  DEBUG_PRINTF("if_statement: relation %d\n", r);
  accept(TOKENIZER_THEN);
  if(r) {
    statement();
  } else {
    do {
      tokenizer_next();
    } while(tokenizer_token() != TOKENIZER_ELSE &&
	    tokenizer_token() != TOKENIZER_CR &&
	    tokenizer_token() != TOKENIZER_ENDOFINPUT);
    if(tokenizer_token() == TOKENIZER_ELSE) {
      tokenizer_next();
      statement();
    } else if(tokenizer_token() == TOKENIZER_CR) {
      tokenizer_next();
    }
  }
}
/*---------------------------------------------------------------------------*/
static void
let_statement(void)
{
 
  int var;

  var = tokenizer_variable_num();

  accept(TOKENIZER_VARIABLE);
  accept(TOKENIZER_EQ);
  ubasic_set_variable(var, expr());
  DEBUG_PRINTF("let_statement: assign %d to %d\n", variables[var], var);
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
rem_statement(void)
{
  accept(TOKENIZER_REM);
  DEBUG_PRINTF("rem_statement\n");
  accept(TOKENIZER_CR);
}
/*---------------------------------------------------------------------------*/
static void
cls_statement(void)
{
  accept(TOKENIZER_CLS);
  script_console_clear();
  DEBUG_PRINTF("cls_statement\n");
  accept(TOKENIZER_CR);
}
/*---------------------------------------------------------------------------*/
static void
gosub_statement(void)
{
  accept(TOKENIZER_GOSUB);
  if(tokenizer_token() == TOKENIZER_STRING) {
    tokenizer_string(string, sizeof(string));
    do {
    tokenizer_next();
    } while(tokenizer_token() != TOKENIZER_CR);
    accept(TOKENIZER_CR);
    if(gosub_stack_ptr < MAX_GOSUB_STACK_DEPTH) {
/*    tokenizer_line_number_inc();*/
      gosub_stack[gosub_stack_ptr] = tokenizer_line_number();
      gosub_stack_ptr++;
      jump_label(string);
    } else {
      DEBUG_PRINTF("gosub_statement: gosub stack exhausted\n");
      ended = 1;
      ubasic_error = UBASIC_E_GOSUB_STACK_EXHAUSTED;
    }
  } else {
    DEBUG_PRINTF("ubasic.c: goto_statement(): no label specified\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNK_LABEL;
  }
}
/*---------------------------------------------------------------------------*/
static void
return_statement(void)
{
  accept(TOKENIZER_RETURN);
  if(gosub_stack_ptr > 0) {
    gosub_stack_ptr--;
    jump_line(gosub_stack[gosub_stack_ptr]);
  } else {
    DEBUG_PRINTF("return_statement: non-matching return\n");
    ended = 1;
    ubasic_error = UBASIC_E_UNMATCHED_RETURN;
  }
}
/*---------------------------------------------------------------------------*/
static void
next_statement(void)
{
  int var, value;
  
  accept(TOKENIZER_NEXT);
  var = tokenizer_variable_num();
  accept(TOKENIZER_VARIABLE);
  if(for_stack_ptr > 0 &&
     var == for_stack[for_stack_ptr - 1].for_variable) {
    value = ubasic_get_variable(var) + 1;
    ubasic_set_variable(var, value);
    if(value <= for_stack[for_stack_ptr - 1].to) {
      jump_line(for_stack[for_stack_ptr - 1].line_after_for);
    } else {
      for_stack_ptr--;
      accept(TOKENIZER_CR);
    }
  } else {
    DEBUG_PRINTF("next_statement: non-matching next (expected %d, found %d)\n", for_stack[for_stack_ptr - 1].for_variable, var);
    accept(TOKENIZER_CR);
  }

}
/*---------------------------------------------------------------------------*/
static void
for_statement(void)
{
  int for_variable, to;
  
  accept(TOKENIZER_FOR);
  for_variable = tokenizer_variable_num();
  accept(TOKENIZER_VARIABLE);
  accept(TOKENIZER_EQ);
  ubasic_set_variable(for_variable, expr());
  accept(TOKENIZER_TO);
  to = expr();
  accept(TOKENIZER_CR);

  if(for_stack_ptr < MAX_FOR_STACK_DEPTH) {
    for_stack[for_stack_ptr].line_after_for = tokenizer_line_number();
    for_stack[for_stack_ptr].for_variable = for_variable;
    for_stack[for_stack_ptr].to = to;
    DEBUG_PRINTF("for_statement: new for, var %d to %d\n",
		 for_stack[for_stack_ptr].for_variable,
		 for_stack[for_stack_ptr].to);
		 
    for_stack_ptr++;
  } else {
    DEBUG_PRINTF("for_statement: for stack depth exceeded\n");
  }
}
/*---------------------------------------------------------------------------*/
static void
end_statement(void)
{
  accept(TOKENIZER_END);
  ended = 1;
}
/*---------------------------------------------------------------------------*/
static void
click_statement(void)
{
  accept(TOKENIZER_CLICK);
  tokenizer_string(string, sizeof(string));
  ubasic_camera_click(string);
  tokenizer_next();
  DEBUG_PRINTF("End of click\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
press_statement(void)
{
  accept(TOKENIZER_PRESS);
  tokenizer_string(string, sizeof(string));
  ubasic_camera_press(string);
  tokenizer_next();
  DEBUG_PRINTF("End of press\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
release_statement(void)
{
  accept(TOKENIZER_RELEASE);
  tokenizer_string(string, sizeof(string));
  ubasic_camera_release(string);
  tokenizer_next();
  DEBUG_PRINTF("End of release\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
sleep_statement(void)
{
  int val;
  accept(TOKENIZER_SLEEP);
  val = expr();
  ubasic_camera_sleep(val);
  DEBUG_PRINTF("End of sleep\n");
  accept_cr();
}
/*---------------------------------------------------------------------------*/
static void
shoot_statement(void)
{
  accept(TOKENIZER_SHOOT);
  ubasic_camera_shoot();
  DEBUG_PRINTF("End of shoot\n");
  accept_cr();
}

/*---------------------------------------------------------------------------*/

static void get_tv_statement()
{
    int var;
    accept(TOKENIZER_GET_TV);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, shooting_get_tv());
    accept_cr();
}

static void set_tv_statement()
{
    int to;
    accept(TOKENIZER_SET_TV);
    to = expr();
    shooting_set_tv(to);
    accept_cr();
}

static void set_tv_rel_statement()
{
    int to;
    accept(TOKENIZER_SET_TV_REL);
    to = expr();
    shooting_set_tv_rel(to);
    accept_cr();
}

/*---------------------------------------------------------------------------*/

static void get_av_statement()
{
    int var;
    accept(TOKENIZER_GET_AV);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, shooting_get_av());
    accept_cr();
}

static void set_av_statement()
{
    int to;
    accept(TOKENIZER_SET_AV);
    to = expr();
    shooting_set_av(to);
    accept_cr();
}

static void set_av_rel_statement()
{
    int to;
    accept(TOKENIZER_SET_AV_REL);
    to = expr();
    shooting_set_av_rel(to);
    accept_cr();
}

/*---------------------------------------------------------------------------*/

static void get_zoom_statement()
{
    int var;
    accept(TOKENIZER_GET_ZOOM);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, shooting_get_zoom());
    accept_cr();
}

static void set_zoom_statement()
{
    int to;
    accept(TOKENIZER_SET_ZOOM);
    to = expr();
    shooting_set_zoom(to);
    accept_cr();
}

static void set_zoom_rel_statement()
{
    int to;
    accept(TOKENIZER_SET_ZOOM_REL);
    to = expr();
    shooting_set_zoom_rel(to);
    accept_cr();
}

static void set_zoom_speed_statement()
{
    int to;
    accept(TOKENIZER_SET_ZOOM_SPEED);
    to = expr();
    shooting_set_zoom_speed(to);
    accept_cr();
}

/*---------------------------------------------------------------------------*/

static void get_focus_statement()
{
    int var;
    accept(TOKENIZER_GET_FOCUS);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, shooting_get_focus());
    accept_cr();
}

static void set_focus_statement()
{
    int to;
    accept(TOKENIZER_SET_FOCUS);
    to = expr();
    shooting_set_focus(to);
    accept_cr();
}

/*---------------------------------------------------------------------------*/

static void get_iso_statement()
{
    int var;
    accept(TOKENIZER_GET_ISO);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    ubasic_set_variable(var, shooting_get_iso());
    accept_cr();
}

static void set_iso_statement()
{
    int to;
    accept(TOKENIZER_SET_ISO);
    to = expr();
    shooting_set_iso(to);
    accept_cr();
}

static void set_iso_direct_statement()
{
    int to;
    accept(TOKENIZER_SET_ISO_DIRECT);
    to = expr();
    shooting_set_iso_direct(to);
    accept_cr();
}

/*---------------------------------------------------------------------------*/

static void wait_click_statement()
{
    int timeout=0;
    accept(TOKENIZER_WAIT_CLICK);
    if (tokenizer_token() != TOKENIZER_CR &&
        tokenizer_token() != TOKENIZER_ELSE ) {
        timeout = expr();
    }
    ubasic_camera_wait_click(timeout);
    accept_cr();
}

static void is_key_statement(void)
{
    int var;
    accept(TOKENIZER_IS_KEY);
    var = tokenizer_variable_num();
    accept(TOKENIZER_VARIABLE);
    tokenizer_string(string, sizeof(string));
    tokenizer_next();
    ubasic_set_variable(var, ubasic_camera_is_clicked(string));
    DEBUG_PRINTF("End of is_key\n");
    accept_cr();
}

/*---------------------------------------------------------------------------*/
static void
statement(void)
{
  ubasic_token token;

  token = tokenizer_token();

  switch(token) {

  case TOKENIZER_PRINT_SCREEN:
    print_screen_statement();
    break;
  case TOKENIZER_PRINT:
    print_statement();
    break;

  case TOKENIZER_SLEEP:
    sleep_statement();
    break;
  case TOKENIZER_CLICK:
    click_statement();
    break;
  case TOKENIZER_PRESS:
    press_statement();
    break;
  case TOKENIZER_RELEASE:
    release_statement();
    break;
  case TOKENIZER_SHOOT:
    shoot_statement();
    break;

  case TOKENIZER_GET_TV:
    get_tv_statement();
    break;
  case TOKENIZER_SET_TV:
    set_tv_statement();
    break;
  case TOKENIZER_SET_TV_REL:
    set_tv_rel_statement();
    break;

  case TOKENIZER_GET_AV:
    get_av_statement();
    break;
  case TOKENIZER_SET_AV:
    set_av_statement();
    break;
  case TOKENIZER_SET_AV_REL:
    set_av_rel_statement();
    break;

  case TOKENIZER_GET_ZOOM:
    get_zoom_statement();
    break;
  case TOKENIZER_SET_ZOOM:
    set_zoom_statement();
    break;
  case TOKENIZER_SET_ZOOM_REL:
    set_zoom_rel_statement();
    break;
  case TOKENIZER_SET_ZOOM_SPEED:
    set_zoom_speed_statement();
    break;

  case TOKENIZER_GET_FOCUS:
    get_focus_statement();
    break;
  case TOKENIZER_SET_FOCUS:
    set_focus_statement();
    break;

  case TOKENIZER_GET_ISO:
    get_iso_statement();
    break;
  case TOKENIZER_SET_ISO:
    set_iso_statement();
    break;
  case TOKENIZER_SET_ISO_DIRECT:
    set_iso_direct_statement();
    break;

  case TOKENIZER_WAIT_CLICK:
    wait_click_statement();
    break;
  case TOKENIZER_IS_KEY:
    is_key_statement();
    break;

  case TOKENIZER_IF:
    if_statement();
    break;
  case TOKENIZER_GOTO:
    goto_statement();
    break;
  case TOKENIZER_GOSUB:
    gosub_statement();
    break;
  case TOKENIZER_RETURN:
    return_statement();
    break;
  case TOKENIZER_FOR:
    for_statement();
    break;
  case TOKENIZER_NEXT:
    next_statement();
    break;
  case TOKENIZER_END:
    end_statement();
    break;
  case TOKENIZER_LET:
    accept(TOKENIZER_LET);
    /* Fall through. */
  case TOKENIZER_VARIABLE:
    let_statement();
    break;
  case TOKENIZER_REM:
    rem_statement();
    break;
  case TOKENIZER_CLS:
    cls_statement();
    break;
  default:
    DEBUG_PRINTF("ubasic.c: statement(): not implemented %d\n", token);
    ended = 1;
    ubasic_error = UBASIC_E_UNK_STATEMENT;
  }
}
/*---------------------------------------------------------------------------*/
static void
line_statement(void)
{
  /* line numbers have been removed */
  DEBUG_PRINTF("----------- Line number %d ---------\n", tokenizer_line_number());
  /*    current_linenum = tokenizer_num();*/
  if (tokenizer_token() == TOKENIZER_LABEL) {
#ifdef DEBUG
      tokenizer_label(string, sizeof(string));
      DEBUG_PRINTF("line_statement: label: %s\n", string );
#endif
      accept(TOKENIZER_LABEL);
      accept(TOKENIZER_CR);
      return;
  }
  statement();
  return;
}
/*---------------------------------------------------------------------------*/
void
ubasic_run(void)
{
  if(tokenizer_finished()) {
    DEBUG_PRINTF("uBASIC program finished\n");
    return;
  }

  line_statement();
}
/*---------------------------------------------------------------------------*/
int
ubasic_finished(void)
{
  return ended || tokenizer_finished();
}
/*---------------------------------------------------------------------------*/
void
ubasic_set_variable(int varnum, int value)
{
  if(varnum >= 0 && varnum < MAX_VARNUM) {
    variables[varnum] = value;
  }
}
/*---------------------------------------------------------------------------*/
int
ubasic_get_variable(int varnum)
{
  if(varnum >= 0 && varnum < MAX_VARNUM) {
    return variables[varnum];
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
void
ubasic_end() {
  if (print_screen_d >= 0) {
    close(print_screen_d);
    print_screen_d = -1;
    print_screen_p = 0;
  }
}
/*---------------------------------------------------------------------------*/
