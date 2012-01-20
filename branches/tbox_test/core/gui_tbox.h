#ifndef TEXTBOX_H
#define TEXTBOX_H

struct libtextbox_sym {
	int version;
    int (*textbox_init)(int title, int msg, char* defaultstr, unsigned int maxsize, void (*on_select)(const char* newstr));
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
