#ifndef LEDS_H
#define LEDS_H

#include "pico/stdlib.h"
void Leds_Init_Config(uint pin_leds, int sizeLeds);
void Leds_Show_All(uint32_t porcentColors[][3], bool active);
#endif