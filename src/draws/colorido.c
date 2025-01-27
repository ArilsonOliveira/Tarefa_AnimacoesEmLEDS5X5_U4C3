#include "leds.h"
#include "colorido.h"

// Frames para os LEDs passando por várias cores
static uint32_t frame0[][3] = {
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}
};

static uint32_t frame1[][3] = {
    {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
    {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
    {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
    {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
    {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}
};

static uint32_t frame2[][3] = {
    {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0},
    {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0},
    {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0},
    {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0},
    {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}
};

static uint32_t frame3[][3] = {
    {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0},
    {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0},
    {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0},
    {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0},
    {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}, {100, 100, 0}
};

static uint32_t frame4[][3] = {
    {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100},
    {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100},
    {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100},
    {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100},
    {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100}, {0, 100, 100}
};

static uint32_t frame5[][3] = {
    {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100},
    {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100},
    {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100},
    {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100},
    {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100}, {100, 0, 100}
};

// Frame6 com todos os LEDs apagados
static uint32_t frame6[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
};

// Função para exibir a animação de mudança de cores e preenchimento de pixels com branco, um por vez
void colorido() {
    // Alterando as cores dos quadrados de acordo com a sequência
    Leds_Show_All(frame0, true);  // Azul
    sleep_ms(500);

    Leds_Show_All(frame1, true);  // Vermelho
    sleep_ms(500);

    Leds_Show_All(frame2, true);  // Verde
    sleep_ms(500);

    Leds_Show_All(frame3, true);  // Amarelo
    sleep_ms(500);

    Leds_Show_All(frame4, true);  // Ciano
    sleep_ms(500);

    Leds_Show_All(frame5, true);  // Rosa
    sleep_ms(500);

    // Preenchendo os LEDs com branco, um de cada vez, começando com todos apagados (frame5)
    for (int i = 0; i < 25; i++) {
        // Mudar o frame6 para branco em uma posição específica
        frame6[i][0] = 100;  // R
        frame6[i][1] = 100;  // G
        frame6[i][2] = 100;  // B

        // Atualiza todos os LEDs com o frame atualizado
        Leds_Show_All(frame6, true);
        sleep_ms(200);  // Pausa de 200ms entre cada atualização
    }

    // Desligando os LEDs, um de cada vez, começando com todos acesos (frame5)
    for (int i = 0; i < 25; i++) {
        // Mudar o frame6 para branco em uma posição específica
        frame6[i][0] = 0;  // R
        frame6[i][1] = 0;  // G
        frame6[i][2] = 0;  // B

        // Atualiza todos os LEDs com o frame atualizado
        Leds_Show_All(frame6, true);
        sleep_ms(200);  // Pausa de 200ms entre cada atualização
    }
}
