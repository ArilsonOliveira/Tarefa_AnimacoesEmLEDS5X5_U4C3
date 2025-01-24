#ifndef CONFIGGPIOS_H
#define CONFIGGPIOS_H

#include "pico/stdlib.h"

void inicializar_perifericos(uint pins_matriz_leds, uint pino_Buzzer, uint PINS_RGB[3], int *pins_rows_keypad, int *pins_columns_keypad);

#endif