#ifndef __SPI_HELP_H__
#define __SPI_HELP_H__

#define SPI_BASE 2

#define CS_NONE 0
#define CS_DAC 2

#define deselect_chip(a) select_chip(0)
#define setup_sdcard(a) setup_select()

void setup_select();
void select_chip(int n);

#endif
