#ifndef SHUTDOWN_H
#define SHUTDOWN_H

/*
 reboot, optionally loading a different binary
 see lib/armutil/reboot.c for documentation
*/
int reboot(const char *bootfile);           // ARM code
void camera_shutdown_in_a_second(void);
void disable_shutdown();
void enable_shutdown();
void __attribute__((noreturn)) shutdown();

#endif

