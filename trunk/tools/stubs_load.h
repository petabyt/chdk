
// Functions for loading stubs and other source files, storing and searching for values contained within.

// Structure for storing a value from a stubs (or other) file
typedef struct _osig
{
    char        nm[100];    // Name
    uint32_t    val;        // Value
	char		sval[100];  // String version of value
    int         pct;        // Used for processing modemap entries
    struct _osig *nxt;      // next list entry
} osig;

// Global variables for storage
extern osig *stubs;
extern osig *stubs_min;
extern osig *modemap;

extern int min_focus_len;
extern int max_focus_len;

// Functions for accessing saved values
osig* find_sig(osig* p, const char *nm);
osig* find_sig_val(osig* p, uint32_t val);

// Functions for loading files
void load_stubs(char *name, int exclude_comments);
void load_stubs_min();
void load_modemap();
void load_platform();
