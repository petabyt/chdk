#include "stdlib.h"
#include "lang.h"

//-------------------------------------------------------------------

// Array of offsets to each string stored in the 'sbuf' array
static unsigned short *strings = NULL;
static int count = 0;

// Strings stored in one large umalloc'ed array rather than individually (reduces memory overhead)
// Previously when loading a language file a block of memory was allocated to read the file
// then another block was allocated for each string in the data read from the file, then the original
// block was freed. This version uses the same buffer to read the file and store the strings.
static char *sbuf = NULL;   
static int sbuflen = 0;

//-------------------------------------------------------------------
void lang_init(int num) {
    int i;

    // Free old buffer (should not happen since this is only called once at startup)
    if (strings)
    {
       ufree(strings);
       strings = 0;
       count = 0;
    }

    // Free old buffer (should not happen since this is only called once at startup)
    if (sbuf)
    {
        ufree(sbuf);
        sbuf = 0;
        sbuflen = 0;
    }

    // Allocate offset buffer
    ++num;
    strings = umalloc(num*sizeof(unsigned short));
    if (strings) {
        memset(strings, 0, num*sizeof(unsigned short));
        count = num;
    }
}

//-------------------------------------------------------------------
// Add a string to the buffer. String is cleaned up to convert special
// characters and the offset of the string in 'sbuf' is stored in the
// strings array.
static void lang_add_string(int num, char *str) {
    int f=0;
    char *p;

    if (num<count) {
       p = str;
       strings[num] = (unsigned short)(str - sbuf);
       if (p) {
           for (; *str; ++str) {
                if (f) {
                    if (*str == '"' || *str == '\\') *(p-1)=*str;
                    else if (*str == 'n') *(p-1)='\n';
                    else *p++=*str;
                    f = 0;
                } else {
                    *p++=*str;
                    if (*str == '\\') {
                        f = 1;
                    }
                }
           }
           *p=0;
       }
    }
}

//-------------------------------------------------------------------
// Parse the 'sbuf' memory and build the strings offset array
void lang_load_from_sbuf()
{
    char *p, *s, *e;
    int i;
    
    e = sbuf-1;
    while(e) {
        p = e+1;
        while (*p && (*p=='\r' || *p=='\n')) ++p;
        i = strtol(p, &e, 0);
        if (e!=p) {
            p = e;
            e = strpbrk(p, "\r\n");
            if (e) *e=0;
            while (*p && *p!='\"') ++p;
            if (*p) ++p;
            s = p;
            while (*p && (*p!='\"' || *(p-1)=='\\')) ++p;
            *p=0;
            lang_add_string(i, s);
        } else { //skip invalid line
            e = strpbrk(p, "\r\n");
            if (e) *e=0;
        }
    }
}

//-------------------------------------------------------------------
// Allocate a new 'sbuf' array if needed.
// If the existing one is large enough use it instead of getting a new block of memory.
int alloc_sbuf(int len)
{
    if (len > sbuflen)
    {
        if (sbuf) ufree(sbuf);
        sbuf = umalloc(len);
        if (sbuf)
        {
            sbuflen = len;
        }
    }
    return (sbuf != 0);
}
//-------------------------------------------------------------------
// Load the default language data from memory.
void lang_load_from_mem(char *buf) {
    if (alloc_sbuf(strlen(buf)+1))
    {
        memcpy(sbuf,buf,sbuflen);
        lang_load_from_sbuf();
    }
}

//-------------------------------------------------------------------
// Load language data from a file.
void lang_load_from_file(const char *filename) {
    int f, size;
    static struct stat st;
    char *buf;

    f = open(filename, O_RDONLY, 0777);
    if (f>=0) {
        size = (stat((char*)filename, &st)==0)?st.st_size:0;
        if (size) {
            if (alloc_sbuf(size+1))
            {
                size = read(f, sbuf, size);
                sbuf[size]=0;
                lang_load_from_sbuf();
            }
        }
        close(f);
    }
}

//-------------------------------------------------------------------
// Return the string corresponding to the 'str' index.
char* lang_str(int str) {
    if (str && str<0x1000) {
        return (strings && str<count && strings[str])?sbuf+strings[str]:"";
    } else { // not ID, just char*
        return (char*)str;
    }
}
