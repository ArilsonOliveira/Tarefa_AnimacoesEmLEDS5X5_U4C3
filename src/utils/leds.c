#include <stdlib.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "ws2812.pio.h"

#define MAX_LEDS 25
static int sm = 0;
static PIO pio = pio0;
static int LED_COUNT = 0;
static uint32_t grb[MAX_LEDS];

static void rgb_to_grb(uint32_t porcentColors[][3]) {
    for (int i = 0; i < LED_COUNT; i++) {
        uint8_t r = porcentColors[i][0] != 0 ?  255 * (porcentColors[i][0] / 100.0): 0; // Calcular R
        uint8_t g = porcentColors[i][1] != 0 ? 255 * (porcentColors[i][1] / 100.0): 0; // Calcular G
        uint8_t b = porcentColors[i][2] != 0 ? 255 * (porcentColors[i][2] / 100.0): 0; // Calcular B
        grb[i] = (g << 16) | (r << 8) | b;             // Combinar em formato GRB
    }
}
void Leds_Init_Config(uint pin_leds, int sizeLeds){
    LED_COUNT = sizeLeds;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset,pin_leds, 800000, false);
    for (int i = 0; i < LED_COUNT; i++) {
        pio_sm_put_blocking(pio, sm,0);
    }
}
// Função para enviar dados para todos os LEDs de uma vez

void Leds_Show_All(uint32_t porcentColors[][3], bool active) {
    if(active) rgb_to_grb(porcentColors);
    for (int i = 0; i < LED_COUNT; i++) {
        if (active) {
            pio_sm_put_blocking(pio, sm, grb[i] << 8u); // Shift para ajustar ao protocolo
        }else{
            pio_sm_put_blocking(pio, sm,0);
        }
    }
    sleep_us(10); // Pulso de reset (>10µs)
}


