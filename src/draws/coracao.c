#include "pico/stdlib.h"
#include "coracao.h"


static uint32_t frame_coracao1[][3] = {

};

static uint32_t frame_coracao2[][3] = {

};

static uint32_t frame_coracao3[][3] = {

};

static uint32_t frame_coracao4[][3] = {

};

static uint32_t frame_coracao5[][3] = {
 
};

void animacao_coracao() {
    Leds_Show_All(frame_coracao1, true);
    sleep_ms(500);
    Leds_Show_All(frame_coracao2, true);
    sleep_ms(500);
    Leds_Show_All(frame_coracao3, true);
    sleep_ms(500);
    Leds_Show_All(frame_coracao4, true);
    sleep_ms(500);
    Leds_Show_All(frame_coracao5, true);
    sleep_ms(500);
    Leds_Show_All(frame_coracao1, true);
    sleep_ms(500);
}
