#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

//------------------------------------------------------------------------------------------------------------

#define MAX_MATCHES (64)

//------------------------------------------------------------------------------------------------------------

FILE *out_fp;

//------------------------------------------------------------------------------------------------------------

// Load original stubs_entry_2.s to compare results to

typedef struct _osig
{
    char        nm[100];
    uint32_t    val;
	char		sval[100];
    int         pct;
    struct _osig *nxt;
} osig;

osig *stubs2 = 0;

void print_stubs(osig *p)
{
    while (p)
    {
        fprintf(out_fp,"//%s 0x%08x (%s) %d\n",p->nm,p->val,p->sval,p->pct);
        p = p->nxt;
    }
}

int read_line(FILE *f, char *buf)
{
    int eof = 0;
    int len = 0;
    while (1)
    {
        if (fread(buf,1,1,f) != 1) { eof = 1; break; }
        if ((*buf == 0x0A) || (*buf == 0x0D)) break;
        len++; 
        buf++;
    }
    *buf = 0;
    return (eof == 0) || (len > 0);
}

char* get_str(char *s, char *d)
{
    while ((*s == ' ') || (*s == '\t') || (*s == ',')) s++;
    while (*s && (*s != ' ') && (*s != '\t') && (*s != ',') && (*s != ')'))
    {
        *d++ = *s++;
    }
	while (*s && (*s != ',') && (*s != ')'))
	{
		if (*s == '+')
		{
			*d++ = *s++;
			while ((*s == ' ') || (*s == '\t') || (*s == ',')) s++;
			while (*s && (*s != ' ') && (*s != '\t') && (*s != ',') && (*s != ')'))
			{
				*d++ = *s++;
			}
		}
		else s++;
	}
    *d = 0;
    return s;
}

void add_sig(char *nm, char *val, int pct, osig **hdr)
{
    osig *p = malloc(sizeof(osig));
    strcpy(p->nm, nm);
	strcpy(p->sval, val);
    p->pct = pct;
    p->nxt = *hdr;
    *hdr = p;

	uint32_t v = 0, n = 0;
	if ((strncmp(val,"0x",2) == 0) || (strncmp(val,"0X",2) == 0))
	{
		while (val)
		{
			sscanf(val,"%x",&n);
			v += n;
			val = strchr(val,'+');
			if (val) val++;
		}
	}
	else
	{
		sscanf(val,"%d",&v);
	}

	p->val = v;
}

osig* find_sig(osig* p, const char *nm)
{
    while (p)
    {
        if (strcmp(p->nm, nm) == 0) return p;
        p = p->nxt;
    }
    return 0;
}

osig* find_sig_val(osig* p, uint32_t val)
{
    while (p)
    {
        if (p->val == val) return p;
        p = p->nxt;
    }
    return 0;
}

void load_stubs2()
{
    FILE *f = fopen("stubs_entry_2.S", "rb");

    if (f == NULL) return;

    char line[500];
    char nm[100];
    char val[12];
    int pct = 100;
    char *s;

    while (read_line(f,line))
    {
		int off = 7;
        s = strstr(line, "NHSTUB(");
		if (s == 0) { off = 6; s = strstr(line, "NSTUB("); }
		if (s == 0) { off = 4; s = strstr(line, "DEF("); }
        if (s != 0)
        {
            char *c = strstr(line, "//");
            if ((c == 0) || (c > s))
            {
                s = get_str(s+off,nm);
                get_str(s,val);
                add_sig(nm, val, pct, &stubs2);
                pct = 100;
                continue;
            }
        }
    }
}

//------------------------------------------------------------------------------------------------------------

typedef struct {
    uint32_t ptr;
    uint32_t fail;
    uint32_t success;
} Match;

typedef struct {
    uint32_t offs;
    uint32_t value;
    uint32_t mask;
} FuncSig;

typedef struct {
    const char *name;
    FuncSig *sig;
} FuncsList;

typedef struct bufrange {
    uint32_t *p;
    int off;
    int len;
    struct bufrange* next;
} BufRange;

BufRange *br, *last;

void addBufRange(uint32_t *p, int o, int l)
{
    BufRange *n = malloc(sizeof(BufRange));
    n->p = p;
    n->off = o;
    n->len = l;
    n->next = 0;
    if (br == 0)
    {
        br = n;
    }
    else
    {
        last->next = n;
    }
    last = n;
}

#include "signatures_vxworks.h"

int match_compare(const Match *p1, const Match *p2)
{
    /* NOTE: If a function has *more* matches, it will be prefered, even if it has a lower percent matches */
    if (p1->success > p2->success){
        return -1;
    } else
        if (p1->success < p2->success){
            return 1;
        } else {
            if (p1->fail < p2->fail){
                return -1;
            } else
                if (p1->fail > p2->fail){
                    return 1;
                }
        }

        /* scores are equal. prefer lower address */

        if (p1->ptr < p2->ptr){
            return -1;
        } else
            if (p1->ptr > p2->ptr){
                return 1;
            }

            return 0;
}

void usage()
{
    if (out_fp) fprintf(out_fp,"finsig <primary> <base> <outputfilename>\n");
    fprintf(stderr,"finsig <primary> <base> <outputfilename>\n");
    exit(1);
}

int main(int argc, char **argv)
{
    Match matches[MAX_MATCHES];
    uint32_t *buf, *p;
    FILE *f;
    int size;
    int i,j,k;
    int fail, success;
    uint32_t base;
    FuncSig *sig, *s;
    int count;
    int ret = 0;
    const char *curr_name;
    BufRange *n;

    clock_t t1 = clock();

    if (argc != 4)
        usage();

    out_fp = fopen(argv[3],"w");
    if (out_fp == NULL) usage();

    load_stubs2();
    //print_stubs(stubs2);

    f = fopen(argv[1], "r+b");

    if (f == NULL)
        usage();

    base = strtoul(argv[2], NULL, 0);

    fprintf(out_fp,"// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!\n");
    fprintf(out_fp,"#include \"stubs_asm.h\"\n\n");

    fseek(f,0,SEEK_END);
    size=ftell(f)/4;
    fseek(f,0,SEEK_SET);

    // Max sig size if 32, add extra space at end of buffer and fill with 0xFFFFFFFF
    // Allows sig matching past end of firmware without checking each time in the inner loop
    buf=malloc((size+32)*4);
    i = fread(buf, 4, size, f);
    fclose(f);
    memset(&buf[size],0xff,32*4);

    // Find all the valid ranges for checking (skips over large blocks of 0xFFFFFFFF)
    br = 0; last = 0;
    k = -1; j = 0;
    for (i = 0; i < size; i++)
    {
        if (buf[i] == 0xFFFFFFFF)   // Possible start of block to skip
        {
            if (k == -1)            // Mark start of possible skip block
            {
                k = i;
            }
        }
        else                        // Found end of block ?
        {
            if (k != -1)
            {
                if (i - k > 32)     // If block more than 32 words then we want to skip it
                {
                    if (k - j > 8)
                    {
                        // Add a range record for the previous valid range (ignore short ranges)
                        addBufRange(&buf[j],j,k - j);
                    }
                    j = i;          // Reset valid range start to current position
                }
                k = -1;             // Reset marker for skip block
            }
        }
    }
    // Add range for last valid block
    if (k != -1)    
    {
        if (k - j > 8)
        {
            addBufRange(&buf[j],j,k - j);
        }
    }
    else
    {
        if (i - j > 8)
        {
            addBufRange(&buf[j],j,i - j);
        }
    }

    for (k = 0; func_list[k].name; k++){

        count = 0;
        curr_name = func_list[k].name;

        while (1) {
            sig = func_list[k].sig;

            for (n = br; n != 0; n = n->next){
                for (p = n->p, i = 0; i < n->len; p++, i++){
                    fail = 0;
                    success = 0;
                    for (s = sig; s->offs != -1; s++){
                        if ((p[s->offs] & s->mask) != s->value){
                            fail++;
                        } else {
                            success++;
                        }
                    }
                    if (success > fail){
                        matches[count].ptr = base+((i+n->off)<<2);
                        matches[count].success = success;
                        matches[count].fail = fail;
                        count ++;
                        if (count >= MAX_MATCHES){
                            fprintf(out_fp,"// WARNING: too many matches for %s!\n", func_list[k].name);
                            break;
                        }
                    }
                }
            }

            // same name, so we have another version of the same function
            if ((func_list[k+1].name == NULL) || (strcmp(curr_name, func_list[k+1].name) != 0)) {
                break;
            }
            k++;
        }

        // find best match and report results
    	osig* ostub2 = find_sig(stubs2,curr_name);

        if (count == 0){
            fprintf(out_fp,"// ERROR: %s is not found!\n", curr_name);
            ret = 1;
        } else {
            if (count > 1){
                qsort(matches, count, sizeof(Match), (void*)match_compare);
            }

            if (matches->fail > 0)
                fprintf(out_fp,"// Best match: %d%%\n", matches->success*100/(matches->success+matches->fail));

            if (ostub2)
                fprintf(out_fp,"//NHSTUB(%s, 0x%x) -- stubs_entry_2.S = 0x%08x\n", curr_name, matches->ptr, ostub2->val);
            else
                fprintf(out_fp,"NHSTUB(%s, 0x%x)\n", curr_name, matches->ptr);

            for (i=1;i<count && matches[i].fail==matches[0].fail;i++){
                fprintf(out_fp,"// ALT: NHSTUB(%s, 0x%x) // %d/%d\n", curr_name, matches[i].ptr, matches[i].success, matches[i].fail);
            }
        }
    }

    clock_t t2 = clock();

    printf("Time to generate stubs %.2f seconds\n",(double)(t2-t1)/(double)CLOCKS_PER_SEC);

    fclose(out_fp);

    return ret;
}

