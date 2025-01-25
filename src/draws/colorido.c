#include "leds.h"
#include "colorido.h"

// Frames para os LEDs passando por várias cores
static uint32_t frame0[][3] = {
    {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
    {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
    {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
    {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255},
    {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}, {0, 0, 255}
};

static uint32_t frame1[][3] = {
    {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0},
    {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0},
    {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0},
    {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0},
    {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}
};

static uint32_t frame2[][3] = {
    {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0},
    {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0},
    {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0},
    {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0},
    {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}
};

static uint32_t frame3[][3] = {
    {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0},
    {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0},
    {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0},
    {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0},
    {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}
};

static uint32_t frame4[][3] = {
    {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180},
    {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180},
    {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180},
    {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180},
    {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180}, {255, 105, 180}
};

// Frame5 com todos os LEDs apagados
static uint32_t frame5[][3] = {
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

    Leds_Show_All(frame4, true);  // Rosa
    sleep_ms(500);

    // Preenchendo os LEDs com branco, um de cada vez, começando com todos apagados (frame5)
    for (int i = 0; i < 25; i++) {
        // Mudar o frame5 para branco em uma posição específica
        frame5[i][0] = 255;  // R
        frame5[i][1] = 255;  // G
        frame5[i][2] = 255;  // B

        // Atualiza todos os LEDs com o frame atualizado
        Leds_Show_All(frame5, true);
        sleep_ms(200);  // Pausa de 200ms entre cada atualização
    }

    // Desligando os LEDs, um de cada vez, começando com todos acesos (frame5)
    for (int i = 0; i < 25; i++) {
        // Mudar o frame5 para branco em uma posição específica
        frame5[i][0] = 0;  // R
        frame5[i][1] = 0;  // G
        frame5[i][2] = 0;  // B

        // Atualiza todos os LEDs com o frame atualizado
        Leds_Show_All(frame5, true);
        sleep_ms(200);  // Pausa de 200ms entre cada atualização
    }
}
