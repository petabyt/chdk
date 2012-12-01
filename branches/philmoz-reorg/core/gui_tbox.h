#ifndef TEXTBOX_H
#define TEXTBOX_H

#define MAX_TEXT_SIZE   100

// Note: if using the text box module pass in a function to the 'on_select' parameter
// the text box will call this function with the user entered text in 'newstr'

// If supplied the 'input_buffer' array will be used to store the user input text,
// this will also be the address passed to 'on_select' in 'newstr' - in this case
// the calling function owns the data buffer. Ensure that the size of 'input_buffer'
// is at least 'maxsize + 1'.

// If 'input_buffer' is null then a local buffer in the module will be used to
// store the text, the maximum size of this buffer is MAX_TEXT_SIZE.
// In this case the module owns the buffer and the contents must be copied to local
// storage in the 'on_select' code.

struct libtextbox_sym {
	int version;
    int (*textbox_init)(int title, int msg, const char* defaultstr, unsigned int maxsize, void (*on_select)(const char* newstr), char *input_buffer);
};

// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern struct libtextbox_sym* libtextbox;
#else
	// This section is for module
#endif

extern struct libtextbox_sym* module_tbox_load();	// 0fail, addr-ok

#endif
