#include "pico/stdlib.h"
#include "leds.h"

static uint32_t frame_girafa0[][3] = {
    {80, 80, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {80, 80, 0}, {80, 80, 0},
    {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {80, 80, 0}, {0, 10, 0}
};

static uint32_t frame_girafa1[][3] = {
    {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0},
    {0, 10, 0}, {80, 80, 0}, {80, 80, 0}, {80, 80, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0},
    {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {80, 80, 0}
};

static uint32_t frame_girafa2[][3] = {
    {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {80, 80, 0},
    {80, 80, 0}, {80, 80, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0},
    {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0},
    {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0}
};

static uint32_t frame_girafa3[][3] = {
    {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0},
    {80, 80, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0},
    {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0},
    {80, 80, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0}
};

static uint32_t frame_girafa4[][3] = {
    {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0},
    {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {80, 80, 0},
    {0, 10, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0}, {0, 10, 0},
    {0, 10, 0}, {0, 10, 0}, {0, 10, 0}, {80, 80, 0}, {0, 10, 0},
    {0, 10, 0}, {80, 80, 0}, {80, 80, 0}, {0, 10, 0}, {0, 10, 0}
};



void movimento_girafa() {

    
    Leds_Show_All(frame_girafa0, true);
    sleep_ms(500);
    Leds_Show_All(frame_girafa1, true);
    sleep_ms(500);
    Leds_Show_All(frame_girafa2, true);
    sleep_ms(500);
    Leds_Show_All(frame_girafa3, true);
    sleep_ms(500);
    Leds_Show_All(frame_girafa4, true);
    sleep_ms(500);
    Leds_Show_All(frame_girafa0, true);
    sleep_ms(500);
    Leds_Show_All(frame_girafa1, true);
    sleep_ms(500); 
}
