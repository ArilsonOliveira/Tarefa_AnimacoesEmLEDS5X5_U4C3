/*
Codigo responsavel por fazer a animação 
de um rosto feliz e um rosto triste
*/


#include "pico/stdlib.h"
#include "leds.h"

static uint32_t frame0[][3] = {
    {0, 0, 0}, {50, 0, 0}, {50, 0, 0}, {50, 0, 0}, {0, 0, 0},
    {50, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {50, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {50, 0, 0}, {0, 0, 0}, {50, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
};

static uint32_t frame1[][3] = {
    {50, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {50, 0, 0},
    {0, 0, 0}, {50, 0, 0}, {50, 0, 0}, {50, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {50, 0, 0}, {0, 0, 0}, {50, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
};


void animacao_rosto() {

    for (int i = 0; i < 4; i++) {

        Leds_Show_All(frame0, true);
        sleep_ms(500);

        Leds_Show_All(frame1, true);
        sleep_ms(500);


    }

}

