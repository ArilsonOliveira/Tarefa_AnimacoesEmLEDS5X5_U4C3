#include "pico/stdlib.h"
#include "raio.h"
#include "leds.h"


static uint32_t frame_raio0[][3] = {

};

static uint32_t frame_raio1[][3] = {

};

static uint32_t frame_raio2[][3] = {

};

static uint32_t frame_raio3[][3] = {

};

void animacao_raio() {
    Leds_Show_All(frame_raio0, true);
    sleep_ms(300);
    Leds_Show_All(frame_raio1, true);
    sleep_ms(300);
    Leds_Show_All(frame_raio2, true);
    sleep_ms(300);
    Leds_Show_All(frame_raio3, true);
    sleep_ms(300);
    Leds_Show_All(frame_raio0, true);
    sleep_ms(300);
}
