#include "leds.h"
#include "buzzer.h"

// letra A
static uint32_t letra_A[][3] = {
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 1 (da direita para a esquerda)
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 2 (da esquerda para a direita)
    {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, // Linha 3 (da direita para a esquerda)
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 4 (da esquerda para a direita)
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 0}   // Linha 5 (da direita para a esquerda)
};
// letra B
static uint32_t letra_B[][3] = {
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 4, 50},  // Linha 1
    {1, 0, 50}, {1, 1, 0}, {1, 2, 0}, {1, 3, 0}, {1, 4, 50},  // Linha 2
    {2, 0, 0}, {2, 1, 50}, {2, 2, 50}, {2, 3, 50}, {2, 4, 50},  // Linha 3
    {3, 0, 50}, {3, 1, 0}, {3, 2, 0}, {3, 3, 0}, {3, 4, 50},  // Linha 4
    {4, 0, 0}, {4, 1, 50}, {4, 2, 50}, {4, 3, 50}, {4, 4, 50}   // Linha 5
};

// Letra C
static uint32_t letra_C[][3] = {
    {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50},  // Linha 1
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 3
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}   // Linha 5
};
// letra D

static uint32_t letra_D[][3] = {
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50},  // Linha 1
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 2
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 3
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 4
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}   // Linha 5
};

// letra E

static uint32_t letra_E[][3] = {
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}   // Linha 5
};

// E
 static uint32_t frame_1[][3] = {
    {0, 0, 0}, {0, 0, 00}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 0}, {0, 0, 00}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}
} ;

// E |

static uint32_t frame_2[][3] = {
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},    // Linha 2
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},    // Linha 4
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}
}  ;

// E |*

static uint32_t frame_3[][3] = {
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}
}  ;

// E |*|
static uint32_t frame_4[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}
}  ;


// Para todas as outras letras, crie matrizes similares respeitando o formato da matriz zig-zag.

// Função para animar todas as letras do alfabeto em sequência
 /*   void exibir_alfabeto() {
    static uint32_t *letras[] = {letra_A // Add matriz para B, C, ... Z };
    int letras_count = sizeof(letras) / sizeof(letras[0]);

    for (int i = 0; i < letras_count; i++) {
        Leds_Show_All(letras[i], true);
        sleep_ms(500); // Tempo de exibição para cada letra
    }
}    */

void exibir_letra_A() {
    // Leds_Show_All(letra_A, true); // Mostra a matriz da letra "A"
    //sleep_ms(500);               // Tempo de exibição da letra
    //Leds_Show_All(letra_B, true);
    //sleep_ms(500);
    //Leds_Show_All(letra_C, true);
    //sleep_ms(500);
    //Leds_Show_All(letra_D, true);
    //sleep_ms(500);
    Leds_Show_All(letra_E, true);
    sleep_ms(500);
    Leds_Show_All(frame_2, true);
    sleep_ms(500);
    Leds_Show_All(frame_3, true);
    sleep_ms(500);
    Leds_Show_All(frame_4, true);
    sleep_ms(500);
}
