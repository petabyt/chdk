#ifndef CORE_H
#define CORE_H

void core_spytask();

// In core/kbd.c
long kbd_process();

void core_rawdata_available();
void core_spytask_can_start();

#define NOISE_REDUCTION_AUTO_CANON      (0)
#define NOISE_REDUCTION_OFF             (1)
#define NOISE_REDUCTION_ON              (2)

int core_get_free_memory();

#endif

