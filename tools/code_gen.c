/*
 * CHDK code_gen
 *      automate generation of boot.c, capt_seq.c and movie_rec.c source files for CHDK
 *      based on chdk-dasm.c from CHDK-PT, created by waterwingz, with extensions from finsig_dryos.c
*
*   usage :- code_gen ROMBASE instructions_file firmware_dump_file
*
*   where:
*       ROMBASE = start address of the firmware in the camera
*       instructions_file   = filename of the instructions file used to generate the code files
*       firmware_dump_file  = filename of the camera firmware dump
*
*   If present the progam will also read stubs_entry.S and stubs_entry_2.S to get function names and addresses
*/

/*
    Notes.
    ======

    The purpose of this program is to generate the source code files used to boot CHDK and override / patch
    the default firmware behaviour. This is done by mimicing the normal camera startup code but with key
    elements replaced or changed to insert the CHDK code.

    A key component of this is to disassemble the firmware code, copy it to the CHDK source file, and then
    patch the necessary instructions for CHDK. This can be tedious and it is easy to make mistakes.

    CHDK-PT provides a GUI interface to examine and dump the firmware instructions in the correct format
    thus achieving the first two goals.

    This program aims to automate the third step of applying the patches and generating final source files.

    Note: this program is not magic - it will still require some digging into the camera firmware disassembly
    and finding functions and function lengths. It may help with the overall porting process, especially for
    a new firmware version for an existing camera port.
*/

/*
    Format of the instructions file used to generate the output code files.
    =======================================================================

    The input file is a series of instructions, one per line, that control the processing of this program.
    The instructions perform the following operations:
        - Open a new file for output
        - Close the output file
        - Copy lines from the instruction file directly to the output file unchanged
                e.g. to add header sections to .c files
        - Copy the contents of another file to the output file
                e.g. to store common code blocks in other source files
        - Begin disassembly of a new function
        - End function disassembly
        - Add the 'asm...' directive to the file to begin disassebled code
        - End the 'asm...' code block
        - Disassemble a block of code from the firmware into the output file
        - Skip over a block of firmware (e.g. DCD code)
        - Disassemble an instruction; but comment it out in the output file (including a comment for explanation)
        - Disassemble and patch an instruction that references another function
                e.g. convert BL sub_XXXXXXX to BL sub_XXXXXXXX_my
        - Disassemble and patch the immediate value in an instruction
                e.g. convert LDR R2, #0x800 to LDR R2, #0x2000
        - Generate a B instruction that jumps back to the firmware at the current address (continue execution in the firmware)

    Each line of the input file looks like:
        operation arguments
    Arguments are of the form:
        name
        value
        name value
        name=value
    The first form is used when no value is required, the second when a single argument is needed, and the third and fourth are equivalent.

    Note there is not much error checking so lines not formatted correctly may cause invalid results.
    
    Lines with unrecognised operations or blank lines are ignores - so you can document the instruction file.
    It is recommended to use C style single line comments (//) to document the file, multi line comments are not implemented.

    Notes:
        Operation and argument names are case sensitive.
        Optional arguments below are shown in square brackets.
        Alternate versions of an argument are shown with '|' seperating them.
        Arguments with spaces (e.g. comments) must be enclosed in double quotes.
        Numeric arguments can be entered as decimal or hex, hex arguments must begin with 0x.
        If no FILE instruction is active output is written to stdout

    The available operations and arguments are:
        FILE filename                               - opens a new file for output
        ENDFILE                                     - closes the current file
        >>>                                         - copies all lines from the input file to the current output file until
                                                      a line beginning with '<<<' is found.
        >>> prelabel                                - as above, except the lines are copied before the 'loc_XXXXXXXX' label on the current instruction
                                                      if the current instruction address has a 'loc_XXXXXXXX' label (for branches, etc), the label is
                                                      normally written to the output file first.
                                                      the 'prelabel' argument causes the lines to be copied before the label.
        <<<                                         - ends the direct copy started above
        >>> file=filename                           - copies the contents of the named file to the output file (note no '<<<' is needed to end the copy)
        FUNC name=FuncName start=X [end=Y length=N] - starts a new function called 'FuncName' writing the prologue to the output file
                                                      
                                                      Note: one of 'end' or 'length' are required; but may be calculated (see below)
                                                      start = function start address in the firmware
                                                      end = address of the last instruciton in the function
                                                      length = number of instructions
                                                      If end is not supplied it is calculated from length & start
                                                      If length is not supplied it is calculated from end & start
                                                      Validation -> length == (end - start / 4) + 1;

                                                      If 'end' or 'length' are not initially supplied then the code will try and calculate them
                                                      - If the FUNC instructions are all fixed length (FW n, PATCHSUB, PATCHVAL, REM & SKIP) then the
                                                        length of each is totalled to calculate 'length'
                                                      - Otherwise (instructions includes 'FW $') the program searches for the next 'STMFD SP!,{...,LR}'
                                                        instruction. If found within 500 instructions it then searches back for the last instruction
                                                        that is either 'LDMFD SP!,{...,PC}', 'B', 'BX LR', or 'LDR PC,[SP,...]' (within the prev 50 instruction).
                                                        If found this instruction is considered the 'end' address.

        FUNC ref=N [end=Y length=N]                 - starts a new function; with the name and start address from a PATCHSUB (see below)
                                                      end and length rules as above
        FUNC sig=SigName [name=FuncName] [end=Y length=N]
                                                    - starts a new function. The address and name are looked up in the values
                                                      loaded from the stubs files. If supplied 'name' will override the function name from stubs.
                                                      end and length rules as above
        ENDFUNC                                     - ends the current function and writes the epiligue code
        ASM                                         - writes the 'asm...' stuff to begin assembly code in the .c source
        ENDASM                                      - ends the 'asm...' code block
        ENDASM prelabel                             - ends the 'asm...' code block
                                                      if there is a label for the next instruction output the label first
        FW                                          - disassemble a single instruction from the firmware to the output file at the current address
                                                      the initial start address is set by FUNC
                                                      the address is updated after each FW instruction by the number of instructions output
        FW n                                        - disassemble the next 'n' instructions to the output file. 
        FW $                                        - disassemble from the current address to the end of the function
        FW $-n                                      - disassemble from the current address to the end of the function - 'n' instructions
        FW [n|$|$-n] ^X                             - as above but reset the current disassembly address to X before disassembling anything
                                                      can be user to jump forward in the function.
                                                      X must be inside the function start - end range
        FW [n|$|$-n] -X                             - as above but reset the current function end address to X before disassembling anything
                                                      no idea if this is of any actual use.
                                                      X must be inside the function start - end range
        REM ["comment"]                             - Disassemble a single instruction; but comment it out in the output file
                                                      the optional comment is added to the output file (to explain if necessary)
        SKIP                                        - Updates the disassembly address by one instruction (skips over the instruction)
        SKIP n                                      - Updates the disassembly address by 'n' instructions (skips over the instructions)
        ->FW                                        - generates a 'B sub_XXXXXXXX' instruction to the current firmware address
                                                      used to jump back to the firmware to continue execution
        PATCHVAL value=N [comment="S"]              - disassembles a single instruction, replacing any immediate value in the instruction with N
                                                      comments are written that show the original value
                                                      e.g. can be used to convert
                                                            LDR R2, #0x800
                                                      to    LDR R2, #0x2000
                                                      if supplied the 'S' comment value is also written to the output
        PATCHSUB [comment="S"]                      - disassembles the next instruction, patching a function reference.
                                                      this changes sub_XXXXXXXX to sub_XXXXXXXX_my
                                                      e.g. convert
                                                            BL sub_FF811234
                                                      to    BL sub_FF811234_my
                                                      or convert
                                                            LDR R1, =sub_FF811234
                                                      to    LDR R1, =sub_FF811234_my
                                                      if supplied the 'S' comment value is also written to the output
        PATCHSUB name=FuncName [comment="S"]        - disassembles the next instruction, patching a function reference.
                                                      this changes sub_XXXXXXXX to FuncName
                                                      e.g. convert
                                                            BL sub_FF811234
                                                      to    BL FuncName
                                                      or convert
                                                            LDR R1, =sub_FF811234
                                                      to    LDR R1, =FuncName
                                                      if supplied the 'S' comment value is also written to the output
        PATCHSUB ref=N [name=FN] [comment="s"]      - as above, this disassembles and patches a function reference instruction
                                                      in addition this saves the function address and patched name to reference array at index 'N'
                                                      this can then be used in the 'FUNC ref=N' operation to retrieve the saved name and address
                                                      to begin a new function. This saves the effort of entering the name and address on the FUNC
                                                      line and makes the instructions more portable across firmware versions.
                                                      Up to 20 patch references can be saved.

    Some examples from the G12 port:

        FILE boot.c                                 - opens the boot.c file for output

        >>> file=../boot_hdr.c                      - copies the content of the common boot_hdr.c file to boot.c

        FUNC start=0xFF81000C length=86 name=boot   - begins disassebly of the boot loader at address FF81000C with a length of 86 instructions
        ASM                                         - adds the 'asm..' code
        FW $-1                                      - disassemble the firmware boot code up to, but not including, the last instruction
        PATCHSUB ref=0                              - disassemble the last instruction, with the function name patched
        ENDASM                                      - ends the 'asm...' code
        ENDFUNC                                     - ends the function (writes the epilogue)

        FUNC ref=0 length=27                        - starts the next function using the name and address saved in the PATCHSUB ref=0 above.
                                                    - this allows the instructions to be used on another port without entering new values
        >>>                                         - copy the lines below to the function (before the assembler code)

        	//http://chdk.setepontos.com/index.php/topic,4194.0.html
        	*(int*)0x1938=(int)taskHook;
        	*(int*)0x193C=(int)taskHook;
    
        	// replacement of sub_FF864BE0 for correct power-on.
        	*(int*)(0x25E0) = (*(int*)0xC0220108)&1 ? 0x100000 : 0x200000; 

        <<<                                         - stop copying
        ASM                                         - adds the 'asm..' code
        FW $-1                                      - disassemble the firmware boot code up to, but not including, the last instruction
        PATCHSUB ref=0                              - disassemble the last instruction, with the function name patched
                                                    - we reuse the same 'ref=0' since we are done with the previous values
        ENDASM                                      - ends the 'asm...' code
        ENDFUNC                                     - ends the function (writes the epilogue)

        ....

        FUNC ref=0 length=9
        ASM
        FW 7
        PATCHSUB name=mykbd_task                    - Patch a call so it now uses the CHDK kbd task
        PATCHVAL value=0x2000 comment="stack size for new task_PhySw"
                                                    - Patch the instruction that sets the kbd task stack size (with a comment)
        ->FW                                        - contine execution in the firmware
        ENDASM
        ENDFUNC

        ENDFILE                                     - close boot.c

        FILE movie_rec.c                            - open the movie_rec.c file

        ....

        FUNC sig=task_MovieRecord length=85 name=movie_record_task
                                                    - start the movie_record_task hook function, get the start address from stubs found
                                                      by finsig_dryos
        ASM
        FW 58
        >>>

        "    BL      unlock_optical_zoom\n"     // added to unlock the zoom

        <<<
        FW 3
        >>>

        "    LDR     R0, =0x7318-4\n" // <----   -4 //+ set in sub_FF9867F8 above
        "    BL      set_quality\n"                 //+ reset here to user value

        <<<
        FW $
        ENDASM
        ENDFUNC

        ....

        ENDFILE                                     - close movie_rec.c

    Another example of using multiple patch references (from the IXUS 310)

        ....

        FUNC ref=0 length=21                        - patched function using previously saved ref
        ASM
        FW 5
        PATCHSUB ref=0                              - we need to patch two functions inside this one, save the reference to the first
        FW
        PATCHSUB ref=1                              - and patch and save the reference to the second function
        FW $
        ENDASM
        ENDFUNC

        FUNC ref=0 length=67                        - now generate the code for the first patched function above
        ASM
        FW 37
        PATCHSUB ref=2                              - which calls a third one
        FW 12
        PATCHSUB                                    - this is the same function as the previous PATCHSUB so need to save the reference
        FW $
        ENDASM
        ENDFUNC

        FUNC ref=1 length=53                        - now generate the code for the second patch function above
        ASM
        FW $-3
        PATCHSUB
        FW $
        ENDASM
        ENDFUNC

        FUNC ref=2 length=1                         - and finally the code for the third function
                                                      note: we are not disassembling any of the firmware code for this function
                                                      instead we add some CHDK code, then jump directly to the original
                                                      firmware address.
                                                      In this case length=1 is required as length=0 is considered an error.
        ASM
        >>>
        "    STMFD   SP!, {R4,R5,LR} \n"
        "    BL      chdk_process_touch \n"
        "    LDMFD   SP!, {R4,R5,LR} \n"
        "    CMP     R0, #0 \n"
        "    BXNE    LR \n"
        <<<
        ->FW
        ENDASM
        ENDFUNC

        ....
 */

/*=====================================================================================================
	chdk_dasm.c
	
	This sofware is provided "as is" with no warantee or representation of any "fitness for use"/
	
	This software contains code included under the license included below. The code was changed to
			- provide formatting compatible with gcc as used for CHDK development
			- provide a multi-pass approach was added to allow the generation and handling of labels.  
			- expanded command line options
			- correction to dissassembly bugs and added support for the STRD instruction.
			
	None of these modifications are the work of the original author.

	And if you are wondering,  the original dissassembler code appears to have been optimized to 
	run on an ARM process, which explains all the goofy use of left and right shifts.  Those compile
	nicely to a single instrucion on the ARM processor.
	
=====================================================================================================*/

/* disarm -- a simple disassembler for ARM instructions
 * (c) 2000 Gareth McCaughan
 *
 * This file may be distributed and used freely provided:
 * 1. You do not distribute any version that lacks this
 *    copyright notice (exactly as it appears here, extending
 *    from the start to the end of the C-language comment
 *    containing these words)); and,
 * 2. If you distribute any modified version, its source
 *    contains a clear description of the ways in which
 *    it differs from the original version, and a clear
 *    indication that the changes are not mine.
 * There is no restriction on your permission to use and
 * distribute object code or executable code derived from
 * this.
 *
 * The original version of this file (or perhaps a later
 * version by the original author) may or may not be
 * available at http://web.ukonline.co.uk/g.mccaughan/g/software.html .
 *
 * Share and enjoy!    -- g
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#include "stubs_load.h"
#include "firmware_load.h"

//------------------------------------------------------------------------------------------------------------

firmware    *fw;

//------------------------------------------------------------------------------------------------------------

void usage(char *err)
{
    fprintf(stderr,"code_gen <base> <primary> [alt base] - Error = %s\n",err);
    exit(1);
}

void error(char *fmt, int n)
{
    exit(1);
}

//------------------------------------------------------------------------------------------------------------

typedef unsigned int t_address;
typedef unsigned int t_value;

#define declstruct(name) typedef struct name s##name, * p##name
#define defstruct(name) struct name
#define defequiv(new,old) typedef struct old s##new, * p##new

declstruct(DisOptions);
declstruct(Instruction);

typedef enum {
    target_None,		/* instruction doesn't refer to an address */
    target_Data,		/* instruction refers to address of data */
    target_FloatS,	/* instruction refers to address of single-float */
    target_FloatD,	/* instruction refers to address of double-float */
    target_FloatE,	/* blah blah extended-float */
    target_FloatP,	/* blah blah packed decimal float */
    target_Code,		/* instruction refers to address of code */
    target_Unknown	/* instruction refers to address of *something* */
} eTargetType;

defstruct(Instruction) {
    char text[128];			/* the disassembled instruction */
    int undefined;			/* non-0 iff it's an undefined instr */
    int badbits;				/* non-0 iff something reserved has the wrong value */
    int oddbits;				/* non-0 iff something unspecified isn't 0 */
    int is_SWI;				/* non-0 iff it's a SWI */
    t_value swinum;		/* only set for SWIs */
    t_address target;			/* address instr refers to */
    eTargetType target_type;	/* and what we expect to be there */
    int offset;				/* offset from register in LDR or STR or similar */
    char * addrstart;			/* start of address part of instruction, or 0 */
    t_value instr ;				/* the raw instruction data */
};

#define disopt_SWInames		            0x001	/* use names, not &nnnn */
#define disopt_CommaSpace	            0x002	/* put spaces after commas */
#define disopt_FIXS			            0x004	/* bogus FIX syntax for ObjAsm */
#define disopt_print_address_mode	    0x008   /* output in plain mode - no address comments */
#define disopt_indent_mneumonics_mode   0x010	/* indent mneumonics additionally */
#define disopt_patch_comment            0x020   // add comment to patched instruction
#define disopt_exclude_dcd              0x040   // Don't write 'DCD' disassembly
#define disopt_nullsub_call             0x080   // Call to nullsub detected
#define disopt_patch_branch             0x100   // patch address in next instruction
#define disopt_patch_value              0x200   // patch value in next instruction
#define disopt_remember_branches        0x400   // enable/disable storing branch addresses
#define disopt_comment_lines            0x800   // enable/disable commenting out of instructions

char *patch_func_name;
t_address patch_new_val;
t_address patch_old_val;
int patch_ref_address[20];
char patch_ref_name[20][256];
int save_patch_ref;
char *patch_comment;

defstruct(DisOptions) {
    t_value flags;
    char * * regnames;					/* pointer to 16 |char *|s: register names */
    t_address ROM_start;
    t_address ROM_end;
    t_address start_address;
    t_address end_address;
};

static char * reg_names[16] = {
    "R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7",  "R8", "R9", "R10", "R11", "R12", "SP", "LR", "PC"
};

static sDisOptions options = {
    disopt_CommaSpace|disopt_exclude_dcd,
    reg_names
};

/* Some important single-bit fields. */

#define Sbit	(1<<20)		/* set condition codes (data processing) */
#define Lbit	(1<<20)		/* load, not store (data transfer) */
#define Wbit	(1<<21)		/* writeback (data transfer) */
#define Bbit	(1<<22)		/* single byte (data transfer, SWP) */
#define Ubit	(1<<23)		/* up, not down (data transfer) */
#define Pbit	(1<<24)		/* pre-, not post-, indexed (data transfer) */
#define Ibit	(1<<25)		/* non-immediate (data transfer) */
/* immediate (data processing) */
#define SPSRbit	(1<<22)		/* SPSR, not CPSR (MRS, MSR) */

/* Some important 4-bit fields. */

#define RD(x)	((x)<<12)	/* destination register */
#define RN(x)	((x)<<16)	/* operand/base register */
#define CP(x)	((x)<<8)	/* coprocessor number */
#define RDbits	RD(15)
#define RNbits	RN(15)
#define CPbits	CP(15)
#define RD_is(x)	((instr&RDbits)==RD(x))
#define RN_is(x)	((instr&RNbits)==RN(x))
#define CP_is(x)	((instr&CPbits)==CP(x))

/* A slightly efficient way of telling whether two bits are the same
 * or not. It's assumed that a<b.
 */
#define BitsDiffer(a,b) ((instr^(instr>>(b-a)))&(1<<a))

//------------------------------------------------------------------------------------------------------------

/* -----------------------------------------------------------------
 * Linked List Routines
 * ----------------------------------------------------------------- */
 
struct lnode {					// linked list node - Storage memory address / memory data pairs
    struct lnode *next;
    t_address address;
    t_value data ;
}; 

struct llist {					// Head of linked list
    struct lnode *head;
    int size;
};

/* -----------------------------------------------------------------
 * struct llist * new_list(void)
 * ----------------------------------------------------------------- */
struct llist * new_list()
{ 
    struct llist *lst;

    lst = (struct llist *) malloc(sizeof(struct llist));
    if (lst == NULL) {
        printf("\n **new_list() : malloc error");
        return NULL;
    }
    lst->head = 0;
    lst->size = 0;

    return lst;
}

void free_list(struct llist *lst)
{
    if (lst)
    {
        struct lnode *p, *n;
        p = lst->head;
        while (p)
        {
            n = p->next;
            free(p);
            p = n;
        }
        free(lst);
    }
}

/* -----------------------------------------------------------------
 * struct new_node * new_node(void * item, t_value data)
 * ----------------------------------------------------------------- */
struct lnode * new_node(t_address address, t_value data) {
    struct lnode *node;

    node = (struct lnode *) malloc (sizeof (struct lnode));
    if (node == NULL) {
        printf("\n **new_node() : malloc error");
        return NULL;
    }
    node->address = address;
    node->data = data;
    node->next = 0;

    return node;
}  

/* -----------------------------------------------------------------
 * int l_search(struct llist *ls, void *address) {
 * ----------------------------------------------------------------- */
struct lnode * l_search(struct llist *ls, t_address address) {
    struct lnode *node;

    node = ls->head;
    while ( node != NULL && node->address != address ) {
        node = node->next ;
    }
    if (node == NULL) {
        return 0; /* 'item' not found */
    }

    return node;
}

/* -----------------------------------------------------------------
 * int l_insert(struct llist *ls, void *item)
 * ----------------------------------------------------------------- */
int l_insert(struct llist *ls, t_address address, t_value data)
{
    struct lnode *node;

    if( l_search(ls, address)) return -1 ;
    node = new_node(address, data);
    if (node == NULL) return 0;
    node->next = ls->head;
    ls->head = node;  
    (ls->size)++;

    return 1;
}

void l_remove(struct llist *ls, t_address addr)
{
    if (ls)
    {
        struct lnode *p, *l;
        l = 0;
        p = ls->head;
        while (p)
        {
            if (p->address == addr)
            {
                if (l)
                    l->next = p->next;
                else
                    ls->head = p->next;
                (ls->size)--;
                return;
            }
            l = p;
            p = p->next;
        }
    }
}
 
/* -----------------------------------------------------------------
 *  Create Linked Lists
 * ----------------------------------------------------------------- */
 
struct llist *dcd_list;				// create list of DCD addresses
struct llist *branch_list;			// create list of branch instruction target addresses

/* -----------------------------------------------------------------
 *  Dissassembler Code
 * ----------------------------------------------------------------- */
 
extern void swiname(t_value, char *, size_t);

/* op = append(op,ip) === op += sprintf(op,"%s",ip),
 * except that it's faster.
 */
static char * append(char * op, const char *ip) {
    char c;
    while ((c=*ip++)!=0) *op++=c;
    return op;
}

/* op = xhex8(op,w) === op += sprintf(op,"&%08lX",w)
 */
static char * xhex8(char * op, t_value w)
{
    char *s = op;

    if (options.flags & disopt_patch_value)
    {
        patch_old_val = w;
        w = patch_new_val;
    }

    if (options.flags & disopt_patch_branch)
    {
        patch_old_val = w;
        if (patch_func_name)
            op += sprintf(op,"=%s",patch_func_name) ;
        else
        {
            if (options.flags & disopt_comment_lines)
                op += sprintf(op,"=_sub_%08X_my",w);     // prepend '_' to prevent sub from appearing in stubs_auto.S
            else
                op += sprintf(op,"=sub_%08X_my",w);
        }
        if (save_patch_ref >= 0)
        {
            *op = 0;
            patch_ref_address[save_patch_ref] = w;
            strcpy(patch_ref_name[save_patch_ref],s+1);
        }
    }
    else
        op += sprintf(op,"=0x%X",w) ;

    return op;
}

/* op = ahex8(op,w) === op += sprintf(op,"&%08lX",w)
  --> xhex hacked to insert addresses into linked list for use on pass 3
 */
static char * ahex8(char * op, t_value w)
{
    struct lnode * lptr ;
    lptr = l_search( dcd_list, w) ;  		// does this DCD address exist already ?

    if ( lptr ) w = lptr->data ;  					// dereference indirect address (typically pass 3)
    else	l_insert(dcd_list, w, 0) ;  	// add node if not found - typically on pass 1

    return xhex8(op, w);
}

/* op = yhex8(op,w) === op += sprintf(op,"&%08lX",w)
 */
static char * yhex8(char * op, t_value w)
{
    if (options.flags & disopt_patch_value)
    {
        patch_old_val = w;
        w = patch_new_val;
    }
    op += sprintf(op,"0x%X",w) ;
    return op;
}

/* op = sub_hex8(op,w) === op += sprintf(op,"&%08lX",w), but faster.
 */
static char * sub_hex8(char * op, t_value w)
{
    if (options.flags & disopt_remember_branches)
        l_insert(branch_list, w, 0) ;

    char *s = op;

    if ((options.flags & disopt_patch_branch) && patch_func_name)
    {
        patch_old_val = w;
        op += sprintf(op,"%s",patch_func_name);
    }
    else
    {
        w = followBranch(fw,w,1);           // If call to Branch then follow branch
        osig *o = find_sig_val_by_type(stubs, w, TYPE_NHSTUB);
        if (o)
        {
            op += sprintf(op,"_%s",o->nm);
        }
        else
        {
            if (( w >= options.start_address )&&( w <= options.end_address ))
            {
                op += sprintf(op,"loc_%08X",w);
            }
            else
            {
                if (options.flags & disopt_comment_lines)
                    op += sprintf(op,"_sub_%08X",w);     // prevent sub from appearing in stubs_auto.S
                else
                {
                    // Get 1st instruction in sub_XXXXXXXX
                    t_value v = fwval(fw,adr2idx(fw,w));
                    if (v == 0xE12FFF1E)    // BX LR?
                    {
                        // Comment out 'nullsub' calls
                        op += sprintf(op,"_sub_%08X",w);
                        options.flags |= disopt_nullsub_call;
                    }
                    else
                        op += sprintf(op,"sub_%08X",w);
                }
            }
            if (options.flags & disopt_patch_branch)
            {
                patch_old_val = w;
                op += sprintf(op,"_my");
            }
        }
    }

    if ((save_patch_ref >= 0) && (options.flags & disopt_patch_branch))
    {
        *op = 0;
        patch_ref_address[save_patch_ref] = w;
        strcpy(patch_ref_name[save_patch_ref],s);
    }

    return op;
}

/* op = reg(op,'x',n) === op += sprintf(op,"x%lu",n&15).
 */
static char * reg(char * op, char c, t_value n) {
    *op++=c;
    n&=15;
    if (n>=10) { *op++='1'; n+='0'-10; } else n+='0';
    *op++=(char)n;

    return op;
}

/* op = num(op,n) appends n in decimal or &n in hex
 * depending on whether n<decmax. It's assumed that n>=0.
 */
static char * num(char * op, t_value w, int decmax)
{
    char tmpbuf[16] ;
    char * tptr ;
    tptr = tmpbuf ;

    if (options.flags & disopt_patch_value)
    {
        patch_old_val = w;
        w = patch_new_val;
    }

    if ( w<decmax ) sprintf( tptr, "%d", w) ;
    else
    {
        if (w < 16)
            sprintf( tptr, "0x%X", w);
        else
            sprintf( tptr, "0x%X", w);
    }
    tptr = tmpbuf ;
    while(*tptr) *op++ = *tptr++ ;
    return op;
}

/* instr_disassemble
 * Disassemble a single instruction.
 *
 * args:   instr   a single ARM instruction
 *         addr    the address it's presumed to have come from
 *         opts    cosmetic preferences for our output
 *
 * reqs:   opts must be filled in right. In particular, it must contain
 *         a list of register names.
 *
 * return: a pointer to a structure containing the disassembled instruction
 *         and some other information about it.
 *
 *
 * This function proceeds in two phases. The first is very simple:
 * it works out what sort of instruction it's looking at and sets up
 * three strings:
 *   - |mnemonic|  (the basic mnemonic: LDR or whatever)
 *   - |flagchars| (things to go after the cond code: B or whatever)
 *   - |format|    (a string describing how to display the instruction)
 
 * The second phase consists of interpreting |format|, character by
 * character. Some characters (e.g., letters) just mean `append this
 * character to the output string'; some mean more complicated things
 * like `append the name of the register whose number is in bits 12..15'
 * or, worse, `append a description of the <op2> field'.
 *
 * I'm afraid the magic characters in |format| are rather arbitrary.
 * One criterion in choosing them was that they should form a contiguous
 * subrange of the character set! Sorry.
 *
 * Format characters:
 *
 *   \01..\05 copro register number from nybble (\001 == nybble 0, sorry)
 *   $        SWI number
 *   %        register set for LDM/STM (takes note of bit 22 for ^)
 *   &        address for B/BL
 *   '        ! if bit 21 set, else nothing (mnemonic: half a !)
 *   (        #regs for SFM (bits 22,15 = fpn, assumed already tweaked)
 *   )        copro opcode in bits 20..23 (for CDP)
 *   *        op2 (takes note of bottom 12 bits, and bit 25)
 *   +        FP register or immediate value: bits 0..3
 *   ,        comma or comma-space
 *   -        copro extra info in bits 5..7 preceded by , omitted if 0
 *   .        address in ADR instruction
 *   /        address for LDR/STR (takes note of bit 23 & reg in bits 16..19)
 *   0..4     register number from nybble
 *   5..9     FP register number from nybble
 *   :        copro opcode in bits 21..23 (for MRC/MCR)
 *   ;        copro number in bits 8..11
 *   =        32 constant (address or data)
 *
 * NB that / takes note of bit 22, too, and does its own ! when appropriate.
 *
 */


extern pInstruction instr_disassemble(t_value instr, t_address addr, pDisOptions opts) {
    static char         flagchars[4];
    static sInstruction result;
    const char * mnemonic  = 0;
    char * flagp     = flagchars;
    const char * format    = 0;
    t_value         fpn;
    eTargetType  poss_tt = target_None;
    int is_v4 = 0;

    options.flags &= ~disopt_nullsub_call;

    /* PHASE 0. Set up default values for |result|. */

    fpn = ((instr>>15)&1) + ((instr>>21)&2);

    result.undefined =
        result.badbits =
        result.oddbits =
        result.instr =
        result.is_SWI = 0;
    result.target_type = target_None;
    result.offset = 0x80000000;
    result.addrstart = 0;

    /* PHASE 1. Decode and classify instruction. */

    switch ((instr>>24)&15) {

    case 0:						/* multiply or data processing, or LDRH etc */
        if ((instr&(15<<4))!=(9<<4)) goto lMaybeLDRHetc;   // F0  90

        if (instr&(1<<23)) {			/* long multiply */
            mnemonic = "UMULL\0UMLAL\0SMULL\0SMLAL" + 6*((instr>>21)&3);
            format = "3,4,0,2";
        }
        else {						
            if (instr&(1<<22)) goto laUndefined;	/* "class C" */

            if (instr&(1<<21)) { 		/* short multiply */
                mnemonic = "MLA";
                format   = "4,0,2,3";
            }
            else {
                mnemonic = "MUL";
                format   = "4,0,2";
            }
        }
        if (instr&Sbit) *flagp++='S';
        break;

    case 1:					/* SWP or MRS/MSR or BX or data processing */
    case 3:

        if ((instr&0x0FF000F0)==0x01200010) {	  		/* BX */
            mnemonic = "BX";
            format = "0";
            break;
        }
        if ((instr&0x0FF000F0)==0x01200030) {	 	   /* BLX */
            mnemonic = "BLX";
            format = "0";
            break;
        }
        if ((instr&0x02B00FF0)==0x00000090) {        /* SWP */
            mnemonic = "SWP";
            format   = "3,0,[4]";
            if (instr&Bbit) *flagp++='B';
            break;
        }
        if ((instr&0x02BF0FFF)==0x000F0000) {        /* MRS */
            mnemonic = "MRS";
            format   = (instr&SPSRbit) ? "3,SPSR" : "3,CPSR";
            break;
        }

        if ((instr&0x0FB00010)==0x03200000) {      /* MSR psr<P=0/1...>,Rm */
            mnemonic = "MSR";
            format   = (instr&SPSRbit) ? "SPSR,0" : "CPSR,0";
            break;
        }

        if ((instr&0x0FB00010)==0x01200000) {     /* MSR {C,S}PSR_flag,op2 */
            mnemonic = "MSR";
            format   = (instr&SPSRbit) ? "SPSR_cxsf,*" : "CPSR_cxsf,*";
            if (!(instr&Ibit) && (instr&(15<<4)))
                goto lMaybeLDRHetc;
            break;
        }


lMaybeLDRHetc:			 										/* fall through here */
        if ( (instr&(14<<24))==0 && ((instr&(9<<4))==(9<<4)) ) 
        {  														/* Might well be LDRH or similar. */
            if ((instr&(Wbit+Pbit))==Wbit) goto lbUndefined;		/* "class E", case 1 */
            if ((instr&(Lbit+(1<<6)))==(1<<6)) 						/* is it LDRD/STRD or LDRSH/STRSH */
            {
                if ((instr&(1<<6))!=(1<<6)) 	goto lcUndefined ;
                mnemonic = "LDR\0STR" + (( instr & 0x0000020) >> 3) ;		/*  */
                if (instr&(1<<6)) *flagp++='D';
                format = "3,/";
                if (!(instr&(1<<22))) instr |= Ibit;
                is_v4=1;
            }
            else
            {
                mnemonic = "STR\0LDR" + ((instr&Lbit) >> 18);
                if (instr&(1<<6)) *flagp++='S';
                *flagp++ = (instr&(1<<5)) ? 'H' : 'B';   				/* fixed 2011/03/27 - B & H reversed */
                format = "3,/";									        /* aargh: */
                if (!(instr&(1<<22))) instr |= Ibit;
                is_v4=1;
            }
            break;
        }

    case 2:												      /* data processing */
        { t_value op21 = instr&(15<<21);
        if ((op21==(2<<21) || (op21==(4<<21)))				/* ADD or SUB */
            && ((instr&(RNbits+Ibit+Sbit))==RN(15)+Ibit)	/* imm, no S */
            /*&& ((instr&(30<<7))==0 || (instr&3))*/) {		/* normal rot */
                /* ADD ...,pc,#... or SUB ...,pc,#...: turn into ADR */
                mnemonic = "LDR";									//** 2011/03/27 changed from "ADR" to "LDR" for gcc assembler compatability 
                format   = "3,.";
                if ((instr&(30<<7))!=0 && !(instr&3)) result.oddbits=1;
                break;
        }
        if ((op21==(4<<21))				                    /* ADD */
            && ((instr&(Ibit))==Ibit)                    	/* imm */
            && ((instr&0xFFF)==0)                           /* 0 offset */
            ) {
                /* ADD Rn, Rd, #0 --> MOV */
                mnemonic = "MOV";
                format   = "3,4";
                if (instr&Sbit && (op21<(8<<21) || op21>=(12<<21))) *flagp++='S';
                break;
        }
        mnemonic = "AND\0EOR\0SUB\0RSB\0ADD\0ADC\0SBC\0RSC\0"
            "TST\0TEQ\0CMP\0CMN\0ORR\0MOV\0BIC\0MVN" /* \0 */
            + (op21 >> 19);
        /* Rd needed for all but TST,TEQ,CMP,CMN (8..11) */
        /* Rn needed for all but MOV,MVN (13,15) */
        if (op21 < ( 8<<21)) format = "3,4,*";
        else if (op21 < (12<<21)) {
            format = "4,*";
            if (instr&RDbits) {
                if ((instr&Sbit) && RD_is(15))
                    *flagp++='P';
                else result.oddbits=1;
            }
            if (!(instr&Sbit)) goto ldUndefined;	/* CMP etc, no S bit */
        }
        else if (op21 & (1<<21)) {
            format = "3,*";
            if (instr&RNbits) result.oddbits=1;
        }
        else format = "3,4,*";
        if (instr&Sbit && (op21<(8<<21) || op21>=(12<<21))) *flagp++='S';
        }
        break;

    case 4:								     /* undefined or STR/LDR */
    case 5:
    case 6:
    case 7:
        if ((instr&Ibit) && (instr&(1<<4))) goto leUndefined;	/* "class A" */
        mnemonic = "STR\0LDR"  + ((instr&Lbit) >> 18);
        format   = "3,/";
        if (instr&Bbit) *flagp++='B';
        if ((instr&(Wbit+Pbit))==Wbit) *flagp++='T';
        poss_tt = target_Data;
        break;

    case 8:												 /* STM/LDM */
    case 9:
        mnemonic = "STM\0LDM" + ((instr&Lbit) >> 18);
        if (RN_is(13)) {							        /* r13, so treat as stack */
            t_value x = (instr&(3<<23)) >> 22;
            if (instr&Lbit) x^=6;
            { const char * foo = "EDEAFDFA"+x;
            *flagp++ = *foo++;
            *flagp++ = *foo;
            }
        }
        else {									        /* not r13, so don't treat as stack */
            *flagp++ = (instr&Ubit) ? 'I' : 'D';
            *flagp++ = (instr&Pbit) ? 'B' : 'A';
        }
        format = "4',%";
        break;

    case 10:  											 /* B or BL */
    case 11:
        mnemonic = "B\0BL"+((instr&(1<<24))>>23);
        format   = "&";
        break;

    case 12:											/* STC or LDC */
    case 13:   
        if (CP_is(1)) {							        /* copro 1: FPU. This is STF or LDF. */
            mnemonic = "STF\0LDF" + ((instr&Lbit) >> 18);
            format   = "8,/";
            *flagp++ = "SDEP"[fpn];
            poss_tt = (eTargetType)(target_FloatS+fpn);
        }
        else if (CP_is(2)) {						        /* copro 2: this is LFM or SFM. */
            mnemonic = "SFM\0LFM" + ((instr&Lbit) >> 18);
            if (!fpn) fpn=4;
            if (RN_is(13) && BitsDiffer(23,24)) {
                if ((instr&255)!=fpn) goto lNonStackLFM;		/* r13 and U!=P, so treat as stack */
                if (BitsDiffer(20,24)) {		            	/* L != P, so FD */
                    *flagp++ = 'F'; *flagp++ = 'D';
                }
                else {							            /* L == P, so EA */
                    *flagp++ = 'E'; *flagp++ = 'A';
                }
                format = "8,(,[4]'";
            }
            else {
lNonStackLFM:											/* not r13 or U=P or wrong offset, so don't treat as stack */
                format = "8,(,/";
                poss_tt = target_FloatE;
            }
        }
        else {									        /* some other copro number: STC or LDC. */
            mnemonic = "STC\0LDC" + ((instr&Lbit) >> 18);
            format   = ";,\004,/";
            if (instr&(1<<22)) *flagp++ = 'L';
            poss_tt = target_Unknown;
        }
        break;

    case 14:									   		/* CDP or MRC/MCR */
        if (instr&(1<<4)) {					 	   		/* MRC/MCR. */
            if (CP_is(1)) {						     		/* copro 1: FPU. */
                if ((instr&Lbit) && RD_is(15)) {         		/* MCR in FPU with Rd=r15: comparison (ugh) */
                    if (!(instr&(1<<23))) goto lfUndefined;		/* unused operation */
                    mnemonic = "CMF\0\0CNF\0\0CMFE\0CNFE" + (5*(instr&(3<<21)) >> 21);
                    format   = "9,+";
                    if (instr&((1<<19)+(7<<5)))
                        result.badbits=1;							/* size,rmode reseved */
                }
                else {							            /* normal FPU MCR/MRC */
                    t_value op20 = instr&(15<<20);
                    if (op20>=6<<20) goto lgUndefined;
                    mnemonic = "FLT\0FIX\0WFS\0RFS\0WFC\0RFC" + (op20>>18);
                    if (op20==0) {					             /* FLT instruction */
                        format = "9,3";
                        { char c = "SDE*"[((instr>>7)&1) + ((instr>>18)&2)];
                        if (c=='*') goto lhUndefined; else *flagp++=c;
                        }
                        if (instr&15) result.oddbits=1;			/* Fm and const flag unused */
                    }
                    else {						              	/* not FLT instruction */
                        if (instr&((1<<7)+(1<<19)))
                            result.badbits=1;						/* size bits reserved */
                        if (op20==1<<20) {		                /* FIX instruction */
                            format = "3,+";
                            if (opts->flags&disopt_FIXS)
                                *flagp++ = "SDEP"[((instr>>7)&1) + ((instr>>18)&2)];
                            *flagp++ = "\0PMZ"[(instr&(3<<5))>>5];
                            if (instr&(7<<15)) result.oddbits=1;	/* Fn unused */
                            if (instr&(1<<3)) result.badbits=1;		/* no immediate consts */
                        }
                        else {					                /* neither FLT nor FIX */
                            format = "3";
                            if (instr&(3<<5)) result.badbits=1;		/* rmode reserved */
                            if (instr&(15+(7<<15))) result.oddbits=1; /* iFm, Fn unused */
                        }
                    }
                }
            }
            else {								          /* some other copro number. Not FPU. */
                mnemonic = "MCR\0MRC";
                mnemonic += (instr&Lbit) >> 18;
                format = ";,:,3,\005,\001-";
            }
        }
        else {								   			/* CDP. */
            if (CP_is(1)) {						    		/* copro 1: FPU. */
                mnemonic = 									/* dyadics: */
                    "ADF\0MUF\0SUF\0RSF\0"
                    "DVF\0RDF\0POW\0RPW\0"
                    "RMF\0FML\0FDV\0FRD\0"
                    "POL\0***\0***\0***\0"
                    /* monadics: */
                    "MVF\0MNF\0ABS\0RND\0"
                    "SQT\0LOG\0LGN\0EXP\0"
                    "SIN\0COS\0TAN\0ASN\0"
                    "ACS\0ATN\0URD\0NRM\0"
                    + ((instr&(15<<20)) >> 18)			/* opcode   -> bits 5432 */
                    + ((instr&(1<<15)) >> 9);			/* monadicP -> bit 6 */
                format = (instr&(1<<15)) ? "8,+" : "8,9,+";
                *flagp++ = "SDE*"[((instr>>7)&1) + ((instr>>18)&2)];
                *flagp++ = "\0PMZ"[(instr&(3<<5))>>5];        /* foregoing relies on this being the last flag! */
                if (*mnemonic=='*' || *flagchars=='*') goto liUndefined;
            }
            else {									          /* some other copro number. Not FPU. */
                mnemonic = "CDP";
                format   = ";,),\004,\005,\001-";
            }
        }
        break;
    case 15:										      /* SWI */
       // not used in Canon firmware, treat as data
       /*
       mnemonic = "SWI";
       format   = "$";
       break;
       */
       goto lUndefined;
      

/* Nasty hack: this is code that won't be reached in the normal
 * course of events, and after the last case of the switch is a
 * convenient place for it.
 */
laUndefined:
        strcpy(result.text, "Undefined instruction a");  	  goto lUndefined ;
lbUndefined:
        strcpy(result.text, "Undefined instruction b"); 	  goto lUndefined ;
lcUndefined:
        strcpy(result.text, "Undefined instruction c"); 	  goto lUndefined ;
ldUndefined:
        strcpy(result.text, "Undefined instruction d"); 	  goto lUndefined ;
leUndefined:
        strcpy(result.text, "Undefined instruction e");	 	  goto lUndefined ;
lfUndefined:
        strcpy(result.text, "Undefined instruction f"); 	  goto lUndefined ;
lgUndefined:
        strcpy(result.text, "Undefined instruction g"); 	  goto lUndefined ;
lhUndefined:
        strcpy(result.text, "Undefined instruction h"); 	  goto lUndefined ;
liUndefined:
        strcpy(result.text, "Undefined instruction i"); 	  goto lUndefined ;
ljUndefined:
        strcpy(result.text, "Undefined instruction j"); 	  goto lUndefined ;
lkUndefined:
        strcpy(result.text, "Undefined instruction k"); 	  goto lUndefined ;
llUndefined:
        strcpy(result.text, "Undefined instruction l"); 	  goto lUndefined ;
lUndefined:	  
        // treat every undefined instruction as data
        /*
        result.undefined = 1;
 	    result.instr = instr ;
        return &result;
        */
        result.instr = instr ;
        mnemonic = ".long";
        format = "=";
        instr = 14 << 28; // no condition code please, see below
    }
    *flagp=0;

    /* PHASE 2. Produce string. */

    { char * op = result.text;

    /* 2a. Mnemonic. */

    op = append(op,mnemonic);

    /* 2b. Condition code. */

    { t_value cond = instr>>28;
    if (cond!=14) {
        const char * ip = "EQNECSCCMIPLVSVCHILSGELTGTLEALNV"+2*cond;
        *op++ = *ip++;
        *op++ = *ip;
    }
    }

    /* 2c. Flags. */

    { const char * ip = flagchars;
    while (*ip) *op++ = *ip++;
    }

    /* 2d. A tab character. */

    do {
        *op++ = ' ';
        *op = 0 ;
    } while ( strlen( result.text ) < 8 ) ;

    /* 2e. Other stuff, determined by format string. */

    { const char * ip = format;
    char c;

    char * * regnames = opts->regnames;
    t_value     oflags   = opts->flags;

    while ((c=*ip++) != 0) {
        switch(c) {
          case '=':
            if (((unsigned long)result.instr > (unsigned long)addr) && ((unsigned long)result.instr < (unsigned long)addr+0x1000)) { // looks like a jumptable
                result.addrstart = op;
                op = sub_hex8(op, result.instr);
            }
            else {
                op = yhex8(op, result.instr);
            }
            break;
    case '$':
        result.is_SWI = 1;
        result.swinum = instr&0x00FFFFFF;
        result.addrstart = op;
        if (oflags&disopt_SWInames) {
            swiname(result.swinum, op, 128-(op-result.text));
            op += strlen(op);
        }
        else
            op += sprintf(op, "&%X", result.swinum);
        break;
    case '%':
        *op++='{';
        { t_value w = instr&0xFFFF;
        int i=0;
        while (w) {
            int j;
            while (!(w&(1ul<<i))) ++i;
            for (j=i+1; w&(1ul<<j); ++j) ;
            --j;
            /* registers [i..j] */
            op = append(op, regnames[i]);
            if (j-i) {
                *op++ = (j-i>1) ? '-' : ',';
                op = append(op, regnames[j]);
            }
            i=j; w=(w>>(j+1))<<(j+1);
            if (w) *op++=',';
        }
        }
        *op++='}';
        if (instr&(1<<22)) *op++='^';
        break;
    case '&':
        // address target = ((addr+8 + ((((int)instr)<<8)>>6)) & 0x03FFFFFC) | ( addr&0xFC000000) ;
        { t_address target = ((t_address) addr ) + 8 + ((t_address) ((((int)instr)<<8) >>6 )) ;
        result.addrstart = op;
        op = sub_hex8(op, target);
        result.target_type = target_Code;
        result.target      = target;
        }
        break;
    case '\'':
lPling:
        if (instr&Wbit) *op++='!';
        break;
    case '(':
        *op++ = (char)('0'+fpn);
        break;
    case ')':
        { t_value w = (instr>>20)&15;
        if (w>=10) { *op++='1'; *op++=(char)('0'-10+w); }
        else *op++=(char)(w+'0');
        }
        break;

    case '*':
    case '.':
        if (instr&Ibit) {
            /* immediate constant */
            t_value imm8 = (instr&255);
            t_value rot  = (instr>>7)&30;
            //if (rot && !(imm8&3) && c=='*') {
            //  /* Funny immediate const. Guaranteed not '.', btw */
            //  *op++='#'; // *op++='&';
            //  *op++='0'; // added in 2.04 to indicate this is a hex value
            //  *op++='x'; //   ditto
            //  *op++="0123456789ABCDEF"[imm8>>4];
            //  *op++="0123456789ABCDEF"[imm8&15];
            //  *op++=',';
            //  op = num(op, rot, 10);
            //}
            //else {
            imm8 = (imm8>>rot) | (imm8<<(32-rot));
            if (c=='*') {
                *op++='#';
                if (imm8>256 && ((imm8&(imm8-1))==0)) {
                    /* only one bit set, and that later than bit 8.
                    * Represent as 1<<... .
                    */
                    //op = append(op,"1<<");
                    { int n=0;
                    while (!(imm8&15)) { n+=4; imm8=imm8>>4; }
                    /* Now imm8 is 1, 2, 4 or 8. */
                    n += (0x30002010 >> 4*(imm8-1))&15;
                    n= 1<<n ;
                    op = yhex8(op, n);
                    }

                }
                else {
                    if (((int)imm8)<0 && ((int)imm8)>-100) {
                        *op++='-'; imm8=-imm8;
                    }
                    op = num(op, imm8, 10);
                }
            }
            else {
                t_address a = addr+8;
                if (instr&(1<<22)) a-=imm8; else a+=imm8;
                result.addrstart=op;
                op = xhex8(op, a);
                result.target=a; result.target_type=target_Unknown;
            }
            //}
        }
        else {
            /* rotated register */
            const char * rot = "LSL\0LSR\0ASR\0ROR" + ((instr&(3<<5)) >> 3);
            op = append(op, regnames[instr&15]);
            if (instr&(1<<4)) {
                /* register rotation */
                if (instr&(1<<7)) goto ljUndefined;
                *op++=','; if (oflags&disopt_CommaSpace) *op++=' ';
                op = append(op,rot); *op++=' ';
                op = append(op,regnames[(instr&(15<<8))>>8]);
            }
            else {
                /* constant rotation */
                t_value n = instr&(31<<7);
                if (!n) {
                    if (!(instr&(3<<5))) break;
                    else if ((instr&(3<<5))==(3<<5)) {
                        op = append(op, ",RRX");
                        break;
                    }
                    else n=32<<7;
                }
                *op++ = ','; if (oflags&disopt_CommaSpace) *op++=' ';
                op = num(append(append(op,rot),"#"),n>>7,32);
            }
        }
        break;
    case '+':
        if (instr&(1<<3)) {
            t_value w = instr&7;
            *op++='#';
            if (w<6) *op++=(char)('0'+w);
            else op = append(op, w==6 ? "0.5" : "10");
        }
        else {
            *op++='f';
            *op++=(char)('0'+(instr&7));
        }
        break;
    case ',':
        *op++=',';
        if (oflags&disopt_CommaSpace) *op++=' ';
        break;
    case '-':
        { t_value w = instr&(7<<5);
        if (w) {
            *op++=',';
            if (oflags&disopt_CommaSpace) *op++=' ';
            *op++ = (char)('0'+(w>>5));
        }
        }
        break;
    case '/':
        result.addrstart = op;
        *op++='[';

        op = append(op, regnames[(instr&RNbits)>>16]);

        if (!(instr&Pbit)) *op++=']';

        *op++=','; 

        if (oflags&disopt_CommaSpace) *op++=' ';

        /* For following, NB that bit 25 is always 0 for LDC, SFM etc */
        if (instr&Ibit) {
            /* shifted offset */
            if (!(instr&Ubit)) *op++='-';
            /* We're going to transfer to '*', basically. The stupid
            * thing is that the meaning of bit 25 is reversed there;
            * I don't know why the designers of the ARM did that.
            */
            instr ^= Ibit;
            if (instr&(1<<4)) {

                if (is_v4 && !(instr&(15<<8))) {
                    ip = (instr&Pbit) ? "0]" : "0";
                    break;
                }
            }
            /* Need a ] iff it was pre-indexed; and an optional ! iff
            * it's pre-indexed *or* a copro instruction,
            * except that FPU operations don't need the !. Bletch.
            */
            if (instr&Pbit) ip="*]'";
            else if (instr&(1<<27)) {
                if (CP_is(1) || CP_is(2)) {
                    if (!(instr&Wbit)) goto lkUndefined;
                    ip="*";
                }
                else ip="*'";
            }
            else ip="*";
        }
        else {
            /* immediate offset */
            t_value offset;
            if (instr&(1<<27)) {      /* LDF or LFM or similar */
                offset = (instr&255)<<2;
            }

            else if (is_v4) offset = (instr&15) + ((instr&(15<<8))>>4);
            else {            /* LDR or STR */
                offset = instr&0xFFF;
            }

            if ( offset == 0 ){
                if (oflags&disopt_CommaSpace) op-- ;
                op-- ; *op++=']'; goto lPling; }

            *op++='#';
            if (!(instr&Ubit)) 
            {
                if (offset) *op++='-';
                else result.oddbits=1;
                result.offset = -offset;
            }
            else result.offset = offset;

            op = num(op, offset, 10);
            if (RN_is(15) && (instr&Pbit)) 
            {
                /* Immediate, pre-indexed and PC-relative. Set target. */
                result.target_type = poss_tt;
                result.target      = (instr&Ubit) ? addr+8 + offset
                    : addr+8 - offset;
                if (!(instr&Wbit)) 
                {
                    /* no writeback, either. Use friendly form. */
                    op = ahex8(result.addrstart, result.target);
                    break;
                }
            }
            if (instr&Pbit) { *op++=']'; goto lPling; }
            else if (instr&(1<<27)) {
                if (CP_is(1) || CP_is(2)) {
                    if (!(instr&Wbit)) goto llUndefined;
                }
                else goto lPling;
            }
        }
        break;

    case '0': case '1': case '2': case '3': case '4':
        op = append(op, regnames[(instr>>(4*(c-'0')))&15]);
        break;
    case '5': case '6': case '7': case '8': case '9':
        *op++='f';
        *op++=(char)('0' + ((instr>>(4*(c-'5')))&7));
        break;
    case ':':
        *op++ = (char)('0' + ((instr>>21)&7));
        break;
    case ';':
        op = reg(op, 'p', instr>>8);
        break;
    default:
        if (c<=5)
            op = reg(op, 'c', instr >> (4*(c-1)));
        else *op++ = c;
        }
    }
    *op=0;
    }
    }

    /* DONE! */

    return &result;
}

//------------------------------------------------------------------------------------------------------------
static void iscomment(FILE *outfile, t_address addr)
{
    if (options.flags & (disopt_comment_lines|disopt_nullsub_call))
    {
        fprintf(outfile,"//");
    }
}

t_address addr, last_used_addr;

static void disassemble1(t_address start, t_value length)
{
    t_value w;

    free(dcd_list);
    dcd_list = new_list();
    free(branch_list);
    branch_list = new_list();

    // Do three passes; but don't generate any code
    int pass;
    for ( pass = 1 ; pass <=3 ; pass++ )
    {
        if ( pass == 2 ) 
        {
            struct lnode* lptr = dcd_list->head;
            while ( lptr != NULL  ) 
            {		
                addr = (t_address) lptr->address ;
                w = fwval(fw,adr2idx(fw,addr));
                lptr->data = w ;
                lptr = lptr->next ;
            }
        }
        else    // pass 1 & 3
        {
            addr = start ;
            t_value word_count = 0 ;

            while (word_count < length )
            {
                w = fwval(fw,adr2idx(fw,addr));
                instr_disassemble(w, addr, &options);

                struct lnode* lptr = l_search(dcd_list,addr);
                if (!lptr) 
                    last_used_addr = addr;

                word_count++ ;
                addr += 4;
            }
        }
    }
}

static void disassemble(FILE *outfile, t_address start, t_value length)
{
    t_value w;

    int dcd_mode_on = 0;

    // Only need 1 pass here - assumes disassemble1 called previously
    addr = start ;
    t_value word_count = 0 ;

    while (word_count < length )
    {
        w = fwval(fw,adr2idx(fw,addr));

        pInstruction instr = instr_disassemble(w, addr, &options);

        if (l_search(branch_list, addr))
        {
            fprintf(outfile,"\n\"loc_%08X:\\n\"\n", addr);
            dcd_mode_on = 0;
        }	
        iscomment(outfile,addr);
        struct lnode* lptr = l_search(dcd_list,addr);
        if ( lptr  || dcd_mode_on ) 
        {
            if ((options.flags & disopt_exclude_dcd) == 0)
                fprintf(outfile,"\"dword_%8.8X  DCD 0x%X \\n\"\n", addr , w);
            dcd_mode_on = 1;
            /*
            t_value aword ;
            int i ;
            unsigned char ch ;
            aword = lptr->data ;
            for ( i=0 ; i< 4 ; i++ )
            {
            ch = aword & 0xFF ;
            if ( (ch>=0x20) && ( ch < 0x80) ) fprintf(outfile," %c" , ch );
            else fprintf(outfile,"_" );
            aword = aword >> 8 ;
            }
            fprintf(outfile, "\n" ) ;
            */
        }	
        else 
        {
            if (instr->undefined || instr->badbits || instr->oddbits) {
                fprintf(outfile,"Error: ");
                if (instr->undefined) fprintf(outfile,"[---undefined instr---] 0x%8.8X     ", w);
                if (instr->badbits) fprintf(outfile,  "[---illegal bits---] 0x%8.8X        ", w);
                if (instr->oddbits) fprintf(outfile,  "[---unexpected bits---] 0x%8.8X     ", w);
                if ( !((instr->undefined) || (instr->badbits) || (instr->oddbits)) ) 
                    fprintf(outfile,  "[---unknown error---] 0x%8.8X       ", w);
                if ( options.flags & disopt_print_address_mode)
                {
                    fprintf(outfile,"// rom:%.8x  0x%8.8X \n", addr, w);
                }								
                else fprintf(outfile,"\n");													
            }
            else
            {
                strcat( instr->text, " \\n\"") ;
                if ( options.flags & disopt_indent_mneumonics_mode) fprintf(outfile,"      ");
                if ( options.flags & disopt_print_address_mode)
                {
                    while ( strlen(instr->text) < 40 ) strcat( instr->text, " ") ;
                    fprintf(outfile,"\"    %s // rom:%.8x  0x%8.8X", instr->text, addr, w);
                }								
                else fprintf(outfile,"\"    %s", instr->text);

                if ((options.flags & disopt_patch_branch) || (options.flags & disopt_patch_value))
                {
                    fprintf(outfile,"  // --> Patched. Old value = 0x%X.", patch_old_val);
                    if ((options.flags & disopt_patch_comment) && patch_comment)
                    {
                        fprintf(outfile, " %s", patch_comment);
                    }
                }
                else if ((options.flags & disopt_patch_comment) && patch_comment)
                {
                    fprintf(outfile, "  // %s", patch_comment);
                }
                else if (options.flags & disopt_nullsub_call)
                {
                    fprintf(outfile,"  // --> Nullsub call removed.");
                }
                fprintf(outfile,"\n");
            }
        }

        word_count++ ;
        addr += 4;
    }
}

static t_address find_end(t_address start)
{
    int i;
    start = adr2idx(fw,start);
    for (i=0; i<500; i++, start++)
        if ((fwval(fw,start+1) & 0xFFFF4000) == 0xE92D4000)  // STMFD SP!, {...,LR}
        {
            int j;
            for (j=0; j<50; j++, start--)
            {
                if ((fwval(fw,start) & 0xFF000000) == 0xEA000000)  // B
                {
                    return idx2adr(fw,start);
                }
                if ((fwval(fw,start) & 0xFFFF8000) == 0xE8BD8000)  // LDMFD SP!, {...,PC}
                {
                    return idx2adr(fw,start);
                }
                if ((fwval(fw,start) & 0xFFFFFFF0) == 0xE12FFF10)  // BX
                {
                    return idx2adr(fw,start);
                }
                if ((fwval(fw,start) & 0xFFFFF000) == 0xE49DF000)  // LDR PC,[SP,...
                {
                    return idx2adr(fw,start);
                }
            }
            return 0;
        }
    return 0;
}

//------------------------------------------------------------------------------------------------------------

void swiname(t_value w, char * s, size_t sz) { return; }

//------------------------------------------------------------------------------------------------------------
// Parsing for instruction file
int largc;
char largs[20][256];
char *last_line;
char token[1024];

char* skip_space(char* c)
{
    while (*c && ((*c == ' ') || (*c == '\t') || (*c == '='))) c++;
    return c;
}

char* skip_token(char* c)
{
    while (*c && (*c != ' ') && (*c != '\t') && (*c != '=')) c++;
    return c;
}

char* skip_string(char* c)
{
    while (*c && (*c != '"')) c++;
    return c;
}

char* next_token(char *line)
{
    token[0] = 0;
    char *c = skip_space(line);
    char *n;
    if (*c)
    {
        if (*c == '"')
        {
            c++;
            n = skip_string(c);
            strncpy(token, c, n-c);
            token[n-c] = 0;
            return skip_space(n+1);
        }
        else
        {
            n = skip_token(c);
            strncpy(token, c, n-c);
            token[n-c] = 0;
            return skip_space(n);
        }
    }
    return c;
}

void parse_line(char *line)
{
    last_line = line;
    largc = 0;
    largs[largc][0] = 0;
    while (line && *line)
    {
        line = next_token(line);
        strcpy(largs[largc++], token);
    }
}

char* next_line(char *line)
{
    char *nxt = strchr(line,'\r');
    if (nxt != 0)
    {
        *nxt++ = 0;
        if (*nxt == '\n')
            nxt++;
    }
    else
    {
        nxt = strchr(line,'\n');
        if (nxt != 0)
            *nxt++ = 0;
    }
    return nxt;
}

void print_args()
{
    int n;
    for (n=0; n<largc; n++) fprintf(stderr,"\t%d %s\n",n,largs[n]);
}

//------------------------------------------------------------------------------------------------------------

// Globals used for instruction processing
FILE *outfile;
int direct_copy;
t_address func_end;
int in_func;

//------------------------------------------------------------------------------------------------------------

#define NULL_OP     0
#define FILE_OP     1
#define ENDFILE_OP  2
#define COPY_OP     3
#define COPY_LINE   4
#define FUNC_OP     5
#define ENDFUNC_OP  6
#define ASM_OP      7
#define ENDASM_OP   8
#define FW_OP       9
#define PATCHSUB_OP 10
#define PATCHVAL_OP 11
#define REM_OP      12
#define SKIP_OP     13
#define CONTFW_OP   14

typedef struct _op
{
    struct _op  *next;

    int         operation;
    char        *source;

    char        *name;
    char        *comment;
    int         prelabel;
    t_address   func_start;
    t_address   func_end;
    int         func_len;
    int         patch_ref;
    t_address   fw_start;
    t_address   fw_end;
    int         fw_func_end_offset;
    int         fw_is_func_end_offset;
    int         fw_len;
    t_address   patch_new_val;
    int         skip_len;
} op;

op *op_head, *op_tail;

void set_op_name(op *p, char *nm)
{
    if (nm)
    {
        p->name = malloc(strlen(nm)+1);
        strcpy(p->name,nm);
    }
    else
    {
        p->name = 0;
    }
}

void set_op_comment(op *p, char *s)
{
    if (s)
    {
        p->comment = malloc(strlen(s)+1);
        strcpy(p->comment,s);
    }
    else
    {
        p->comment = 0;
    }
}

op *new_op(int type)
{
    op *p = malloc(sizeof(op));

    p->operation = type;

    p->source = malloc(strlen(last_line)+1);
    strcpy(p->source,last_line);

    p->name = 0;
    p->comment = 0;
    p->prelabel = 0;
    p->func_start = 0;
    p->func_end = 0;
    p->func_len = 0;
    p->patch_ref = -1;
    p->fw_start = 0;
    p->fw_end = 0;
    p->fw_func_end_offset = 0;
    p->fw_is_func_end_offset = 0;
    p->fw_len = -1;
    p->patch_new_val = 0;
    p->skip_len = 0;

    if (op_tail)
    {
        op_tail->next = p;
    }
    else
    {
        op_head = p;
    }

    op_tail = p;
    p->next = 0;

    return p;
}

void chk_args(int count, char *msg, op *p)
{
    if (largc != count+1)
    {
        fprintf(stderr,"ERROR - %s\n",msg);
        fprintf(stderr,"SOURCE - %s\n",p->source);
        exit(1);
    }
}

//------------------------------------------------------------------------------------------------------------

// Open an output file
void parse_FILE()
{
    op *p = new_op(FILE_OP);
    chk_args(1,"Missing FILE name",0);
    set_op_name(p,largs[1]);
}

// Close output file
void parse_ENDFILE()
{
    new_op(ENDFILE_OP);
}

// Direct copy input to output file
void parse_COPY()
{
    op *p = new_op(COPY_OP);
    int n;

    // Check if copy goes before or after the current instruction address label
    for (n=1; n<largc; n++)
    {
        if (strcmp(largs[n],"prelabel") == 0)
            p->prelabel = 1;
    }

    direct_copy = 1;

    // Check if the copy is from another source file - if so just copy that file
    for (n=1; n<largc; n++)
    {
        if (strcmp(largs[n],"file") == 0)
        {
            set_op_name(p,largs[++n]);
            direct_copy = 0;
        }
    }
}

// Start a new Function disassembly:
//  - sets up addresses & length
//  - does pass 1 & 2 of the disassembly to get the labels
//  - writes the function start to the source
void parse_FUNC()
{
    op *p = new_op(FUNC_OP);
    int n;

    for (n=1; n<largc; n++)
    {
        if (strcmp(largs[n], "name") == 0)
        {
            set_op_name(p,largs[++n]);
        }
        else if (strcmp(largs[n], "start") == 0)
        {
            p->func_start = strtoul(largs[++n],0,0);
        }
        else if (strcmp(largs[n], "end") == 0)
        {
            p->func_end = strtoul(largs[++n],0,0);
        }
        else if (strcmp(largs[n], "length") == 0)
        {
            p->func_len = strtoul(largs[++n],0,0);
        }
        else if (strcmp(largs[n], "ref") == 0)
        {
            p->patch_ref = strtol(largs[++n],0,0);
        }
        else if (strcmp(largs[n], "sig") == 0)
        {
            osig *sig = find_sig(stubs, largs[++n]);
            if (sig == 0) chk_args(-1,"Can't find firmware function for 'sig='",p);
            p->func_start = sig->val;
            p->name = sig->nm;
        }
        else
        {
            chk_args(-1,"Invalid FUNC argument",p);
        }
    }
}

// End function, writes the function end to the file
void parse_ENDFUNC()
{
    new_op(ENDFUNC_OP);
}

// Writes the 'asm...' stuff to the file
void parse_ASM()
{
    new_op(ASM_OP);
}

// Ends the 'asm...' block
void parse_ENDASM()
{
    op *p = new_op(ENDASM_OP);
    int n;

    // Check if copy goes before or after the current instruction address label
    for (n=1; n<largc; n++)
    {
        if (strcmp(largs[n],"prelabel") == 0)
            p->prelabel = 1;
    }
}

// Disassemble a block of firmware code to the file
void parse_FW()
{
    op *p = new_op(FW_OP);
    int n;

    for (n=1; n<largc; n++)
    {
        switch (largs[n][0])
        {
        case '^':
            p->fw_start = strtoul(largs[n]+1,0,0);
            break;
        case '-':
            p->fw_end = strtoul(largs[n]+1,0,0);
            break;
        case '$':
            p->fw_func_end_offset = strtol(largs[n]+1,0,0) * 4;
            p->fw_is_func_end_offset = 1;
            break;
        default:
            p->fw_len = strtoul(largs[n],0,0);
            if (p->fw_len == 0) p->fw_len++;
            break;
        }
    }

    if ((p->fw_start != 0) && (p->fw_end != 0))
        p->fw_len = (p->fw_end - p->fw_start) / 4 + 1;
}

// Disassemble and patch a single instruction that references another sub_XXXXXXXX
// The instruction can be B/BL/LDR etc.
void parse_PATCHSUB()
{
    op *p = new_op(PATCHSUB_OP);
    int n;

    for (n=1; n<largc; n++)
    {
        if (strcmp(largs[n], "name") == 0)
        {
            set_op_name(p,largs[++n]);
        }
        else if (strcmp(largs[n], "ref") == 0)
        {
            p->patch_ref = strtoul(largs[++n],0,0);
        }
        else if (strcmp(largs[n], "comment") == 0)
        {
            set_op_comment(p,largs[++n]);
        }
        else
        {
            chk_args(-1,"Invalid PATCHSUB argument",p);
        }
    }
}

// Disassemble and patch a single instruction, replacing an immediate value
void parse_PATCHVAL()
{
    op *p = new_op(PATCHVAL_OP);
    int n;

    for (n=1; n<largc; n++)
    {
        if (strcmp(largs[n], "value") == 0)
        {
            p->patch_new_val = strtoul(largs[++n],0,0);
        }
        else if (strcmp(largs[n], "comment") == 0)
        {
            set_op_comment(p,largs[++n]);
        }
        else
        {
            chk_args(-1,"Invalid PATCHVAL argument",p);
        }
    }
}

// Disassemble and comment out a single instruction
// An optional comment can be added to the line with the reason for removal
void parse_REM()
{
    op *p = new_op(REM_OP);

    if (largc > 1)
    {
            set_op_comment(p,largs[1]);
    }
}

// Skip N words in the firmware - used to skip over DCD in the middle of a function
void parse_SKIP()
{
    op *p = new_op(SKIP_OP);

    if (largc > 1)
        p->skip_len = strtol(largs[1],0,0);
    else
        p->skip_len = 1;
}

// Generate a B instruction to jump back to the firmware code at the current address
void parse_CONTFW()
{
    new_op(CONTFW_OP);
}

//------------------------------------------------------------------------------------------------------------

void op_prelabel(op *p)
{
    // If after then write label to output and remove from list (so it doesn't get written twice)
    if (in_func && (p->prelabel == 0) && (addr <= options.end_address))
    {
        if (l_search(branch_list, addr))
        {
            fprintf(outfile,"\n\"loc_%08X:\\n\"\n", addr) ;	
            l_remove(branch_list, addr);
        }
    }
}

// Direct copy input to output file
void op_COPY(op *p)
{
    int x;

    op_prelabel(p);

    // Check if the copy is from another source file - if so just copy that file
    if (p->name)
    {
        FILE *fp = fopen(p->name,"r");
        if (!fp)
        {
            fprintf(stderr,"Can't open file '%s'\n",p->name);
            exit(1);
        }

        char buf[1024];
        do
        {
            x = fread(buf,1,1024,fp);
            if (x > 0) fwrite(buf,1,x,outfile);
        } while (x > 0);

        fclose(fp);
        direct_copy = 0;
    }
}

// Start a new Function disassembly:
//  - sets up addresses & length
//  - does pass 1 & 2 of the disassembly to get the labels
//  - writes the function start to the source
void op_FUNC(op *p)
{
    t_address func_start;
    int func_len;
    char func_name[256];

    *func_name = 0;

    func_start = p->func_start;
    func_end = p->func_end;
    func_len = p->func_len;

    if (p->name)
        strcpy(func_name, p->name);

    if (p->patch_ref >= 0)
    {
        func_start = patch_ref_address[p->patch_ref];
        strcpy(func_name, patch_ref_name[p->patch_ref]);
    }

    in_func = 1;

    if (func_start == 0) chk_args(-1,"Missing FUNC start address",p);

    if ((func_end == 0) && (func_len == 0))
    {
        op *n = p->next;
        int cont = 1;
        while (n && cont)
        {
            switch (n->operation)
            {
            case FW_OP:
                if (n->fw_is_func_end_offset)
                {
                    cont = 0;
                    func_len = 0;
                }
                else
                {
                    func_len += n->fw_len;
                }
                break;
            case PATCHSUB_OP:
            case PATCHVAL_OP:
            case REM_OP:
                func_len++;
                break;
            case SKIP_OP:
                func_len += n->skip_len;
                break;
            case ENDFUNC_OP:
                cont = 0;
                break;
            }
            n = n->next;
        }

        if (func_len == 0)
        {
            func_end = find_end(func_start);
            if (func_end == 0)
                chk_args(-1,"Missing FUNC end address or length",p);
        }
    }

    if ((func_end == 0) && (func_len > 0))
        func_end = func_start + func_len * 4 - 4;
    if ((func_len == 0) && (func_end > 0))
        func_len = (func_end - func_start) / 4 + 1;
    if (func_end < func_start) chk_args(-1,"FUNC start > end",p);
    if (func_len != ((func_end - func_start) / 4 + 1)) chk_args(-1,"FUNC start/end/length mismatch",p);

    if (*func_name == 0)
        sprintf(func_name, "sub_%08X_my", func_start);

    options.start_address = func_start;
    options.end_address   = func_end;

    options.flags |= disopt_remember_branches;
    disassemble1(func_start, func_len);
    options.flags &= ~disopt_remember_branches;

    fprintf(outfile,"\n/*************************************************************/");
    fprintf(outfile,"\n//** %s @ 0x%08X - 0x%08X, length=%d\n", func_name, func_start, last_used_addr, (last_used_addr - func_start) / 4 + 1 ) ;
    fprintf(outfile,"void __attribute__((naked,noinline)) %s() {\n", func_name);

    addr = func_start;
}

// Disassemble a block of firmware code to the file
void op_FW(op *p)
{
    t_address start_address = addr;
    t_address end_address = addr;

    if (p->fw_start > 0)
        start_address = p->fw_start;
    if (p->fw_end > 0)
        end_address = p->fw_end;
    if (p->fw_is_func_end_offset)
        end_address = func_end + p->fw_func_end_offset;
    if (p->fw_len > 0)
        end_address = start_address + p->fw_len * 4 - 4;

    disassemble(outfile, start_address, (end_address + 4 - start_address) / 4);
}

// Disassemble and patch a single instruction that references another sub_XXXXXXXX
// The instruction can be B/BL/LDR etc.
void op_PATCHSUB(op *p)
{
    patch_func_name = p->name;
    save_patch_ref = p->patch_ref;
    patch_comment = p->comment;
    if (patch_comment)
    {
        options.flags |= disopt_patch_comment;
    }

    options.flags |= disopt_patch_branch;
    disassemble(outfile, addr, 1);
    options.flags &= ~(disopt_patch_branch|disopt_patch_comment);
}

// Disassemble and patch a single instruction, replacing an immediate value
void op_PATCHVAL(op *p)
{
    patch_new_val = p->patch_new_val;
    patch_comment = p->comment;
    if (patch_comment)
    {
        options.flags |= disopt_patch_comment;
    }

    options.flags |= disopt_patch_value;
    disassemble(outfile, addr, 1);
    options.flags &= ~(disopt_patch_value|disopt_patch_comment);
}

// Disassemble and comment out a single instruction
// An optional comment can be added to the line with the reason for removal
void op_REM(op *p)
{
    patch_comment = p->comment;
    if (patch_comment)
    {
        options.flags |= disopt_patch_comment;
    }

    options.flags |= disopt_comment_lines;
    disassemble(outfile, addr, 1);
    options.flags &= ~(disopt_comment_lines|disopt_patch_comment);
}

//------------------------------------------------------------------------------------------------------------

// Process operation on current line
void do_ops(op *p)
{
    switch (p->operation)
    {
    case FILE_OP:
        // Open an output file
        outfile = fopen(p->name, "w");
        fprintf(outfile, "/*\n * %s - auto-generated by CHDK code_gen.\n */\n", p->name);
        break;
    case ENDFILE_OP:
        // Close output file
        if (outfile != stdout)
        {
            fclose(outfile);
            outfile = stdout;
        }
        break;
    case COPY_OP:
        op_COPY(p);
        break;
    case COPY_LINE:
        fprintf(outfile, "%s\n", p->comment);
        break;
    case FUNC_OP:
        op_FUNC(p);
        break;
    case ENDFUNC_OP:
        // End function, writes the function end to the file
        fprintf(outfile,"}\n");
        in_func = 0;
        break;
    case ASM_OP:
        // Writes the 'asm...' stuff to the file
        fprintf(outfile,"asm volatile (\n");
        break;
    case ENDASM_OP:
        // Ends the 'asm...' block
        op_prelabel(p);
        fprintf(outfile,");\n");
        break;
    case FW_OP:
        op_FW(p);
        break;
    case PATCHSUB_OP:
        op_PATCHSUB(p);
        break;
    case PATCHVAL_OP:
        op_PATCHVAL(p);
        break;
    case REM_OP:
        op_REM(p);
        break;
    case SKIP_OP:
        // Skip N words in the firmware - used to skip over DCD in the middle of a function
        addr += (p->skip_len * 4);
        break;
    case CONTFW_OP:
        // Generate a B instruction to jump back to the firmware code at the current address
        fprintf(outfile,"\"    B       sub_%08X \\n\"  // Continue in firmware\n",addr);
        break;
    }
}

// Process an operation
int run_op(char *name, void (*func)())
{
    if (strcmp(largs[0], name) == 0)
    {
        func();
        return 1;
    }
    return 0;
}

// Pre-Process operation on current line
void parse_ops()
{
    if (largc > 0)
    {
        if (run_op("FILE",      parse_FILE))       return;
        if (run_op("ENDFILE",   parse_ENDFILE))    return;
        if (run_op(">>>",       parse_COPY))       return;
        if (run_op("FUNC",      parse_FUNC))       return;
        if (run_op("ENDFUNC",   parse_ENDFUNC))    return;
        if (run_op("ASM",       parse_ASM))        return;
        if (run_op("ENDASM",    parse_ENDASM))     return;
        if (run_op("FW",        parse_FW))         return;
        if (run_op("PATCHSUB",  parse_PATCHSUB))   return;
        if (run_op("PATCHVAL",  parse_PATCHVAL))   return;
        if (run_op("REM",       parse_REM))        return;
        if (run_op("SKIP",      parse_SKIP))       return;
        if (run_op("->FW",      parse_CONTFW))     return;
    }
}

//------------------------------------------------------------------------------------------------------------

int main(int ac, const char * av[]) 
{
    // Check number of args
    if (ac < 4)
    {
        fprintf(stderr,"Usage: code_gen ROMBASE code_gen.txt PRIMARY.BIN [ALT_ROMBASE]\n");
        exit(1);
    }

    // Get ROMBASE value
    options.ROM_start = strtoul(av[1],0,0);
    if (options.ROM_start == 0)
    {
        fprintf(stderr,"Invalid ROMBASE.\n");
        exit(1);
    }

    // Get instruction file length
    struct stat st;
    if (stat(av[2],&st) != 0)
    {
        fprintf(stderr, "Failed to stat \"%s\".\n", av[2]);
        exit(1);
    }
    size_t len = st.st_size;

    // Open & read instruction file
    FILE *fp = fopen(av[2], "rb");
    if (!fp)
    {
        fprintf(stderr, "Failed to open \"%s\".\n", av[2]);
        exit(1);
    }

    // Allocate block for instruction file
    char *def = malloc(len+1);
    if (def == 0)
    {
        fprintf(stderr, "Not enough memory.\n");
        exit(1);
    }

    // Read instruction file
    size_t n = fread(def, 1, len, fp);
    def[n] = 0;
    fclose(fp);

    // Open Firmware dump file
    fw = malloc(sizeof(firmware));
    load_firmware(fw, av[3], av[1], (ac==5)?av[4]:0);

    // Load function name/address values from stubs files
    load_stubs("stubs_entry.S", 0);
    load_stubs("stubs_entry_2.S", 0);   // Load second so values override stubs_entry.S

    outfile = stdout;
    direct_copy = 0;
    in_func = 0;

    op_head = op_tail = 0;

    // Pre-Process
    char *line = def;
    while ((line != 0) && (*line != 0))
    {
        char *nxt = next_line(line);

        // Check if just copying from input file to output file
        if (direct_copy)
        {
            // Check if end of copy
            if (strncmp(line,"<<<",3) == 0)
            {
                direct_copy = 0;
            }
            else
            {
                op *p = new_op(COPY_LINE);
                set_op_comment(p,line);
            }
        }
        else
        {
            parse_line(line);
            parse_ops();
        }

        line = nxt;
    }

    // Process
    op *p = op_head;
    while (p)
    {
        do_ops(p);
        p = p->next;
    }

    if (outfile != stdout)
        fclose(outfile);

    return 0;
}
