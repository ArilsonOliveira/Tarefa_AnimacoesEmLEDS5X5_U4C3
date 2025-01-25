#include "leds.h"
#include "buzzer.h"



// Cada frame da animação de chuva de pixels
static uint32_t chuva_frame0[][3] = {                               // - - - - *
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},         // - - - * -   OK
    {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},         // - - * - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0},         // - * - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0},         // * - - - -
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}          
};

static uint32_t chuva_frame1[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0},     // - - - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0},     // - - - - *  OK
    {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - - * -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},     // - - * - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}       // - * - - -
};

static uint32_t chuva_frame2[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0},     // - - - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0},     // - - - - - OK
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - - - *
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},      // - - - * -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}       // - - * - -
};

static uint32_t chuva_frame3[][3] = {
    {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},     // - - - - -  OK
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},      // - - - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},      // - - - - *
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}       // - - - * -
};

static uint32_t chuva_frame4[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - * - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // * - - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - - - -
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0}      // - - - - -
};

static uint32_t chuva_frame5[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - * - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - * - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},     // * - - - -
    {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - - - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0}      // - - - - -
};

static uint32_t chuva_frame6[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - - * -
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},     // - - * - -
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0},     // - * - - -
    {0, 0, 5}, {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0},     // * - - - -
    {0, 0, 0}, {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}      // - - - - -
};

/* --------------------------------------------------------------
    Função para executar a animação da chuva de pixels uma vez
void chuva_pixels() {
    static uint32_t *frames[] = {chuva_frame0, chuva_frame1, chuva_frame2, chuva_frame3, chuva_frame4, chuva_frame5, chuva_frame6};
    int frame_count = sizeof(frames) / sizeof(frames[0]);

    for (size_t i = 0; i < frame_count; i++) {
        Leds_Show_All(frames[i], true);
        sleep_ms(200); // Atraso entre os frames
    }
} */

/*--------------------------------------------------------------------------
// Função para executar a animação da chuva de pixels em loop infinito
void chuva_pixels() {
    static uint32_t *frames[] = {chuva_frame0, chuva_frame1, chuva_frame2, chuva_frame3, chuva_frame4, chuva_frame5, chuva_frame6};
    int frame_count = sizeof(frames) / sizeof(frames[0]);

    while (true) { // Loop infinito
        for (size_t i = 0; i < frame_count; i++) {
            Leds_Show_All(frames[i], true);
            sleep_ms(200); // Atraso entre os frames
        }
    }
} */

//------------------------------------------------------------------------
//Função para aparecer 5 repetições do loop
void chuva_pixels() {
    static uint32_t *frames[] = {chuva_frame0, chuva_frame1, chuva_frame2, chuva_frame3, chuva_frame4, chuva_frame5, chuva_frame6};
    int frame_count = sizeof(frames) / sizeof(frames[0]);
    int repetitions = 5; // Número de repetições desejadas

    for (int r = 0; r < repetitions; r++) { // Loop externo para controlar as repetições
        for (size_t i = 0; i < frame_count; i++) {
            Leds_Show_All(frames[i], true);
            sleep_ms(100); // Atraso entre os frames
        }
    }
}  