#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "configGpios.h"
#include "tecladoMatricial4x4.h"
#include "leds.h"
#include "buzzer.h"
#include "pacman.h"

#define PIN_LEDS 7   // Pino de controle
#define LED_COUNT 25 // Número de LEDs na fita
#define BUZZER_PIN 21

static uint PINS_RGB[3] = {13, 11, 12};

static int PINS_ROWS_KEYPAD[4] = {17, 18, 19, 20}; // Pinos das linhas do teclado
static int PINS_COLUMNS_KEYPAD[4] = {16, 9, 8, 4}; // Pinos das colunas do teclado

int main()
{
    stdio_init_all();
    Leds_Init_Config(PIN_LEDS, LED_COUNT);
    inicializar_perifericos(PIN_LEDS, BUZZER_PIN, PINS_RGB, PINS_ROWS_KEYPAD, PINS_COLUMNS_KEYPAD);
    // Draw_Init_Config(LED_COUNT);
    while (true){
        char key = Get_Key_clicked(PINS_ROWS_KEYPAD, PINS_COLUMNS_KEYPAD);
        switch (key){
        case '4':
            // Array com as frequências (em Hz) dos sons característicos do Pac-Man
            const int pacmanFrequencies[] = {440, 494, 523, 587, 659, 698, 784, 880, 988, 1047,1175,1319,1397,1568,1760,1976,2637,2794,3136,3520,3951,4186,4699,5237};
            // Array com as durações correspondentes (em ms) para cada frequência
            const int pacmanDurations[] = {150,150,200,100,150,200,150,300,100,200,150,150,200,250,150,350,120,150,180,200,250,150,100,300};
            controlar_buzzer(BUZZER_PIN, true);
            tocar(BUZZER_PIN, pacmanFrequencies, pacmanDurations, 24);
            Draw_Pac_man();
            // Frequências (em Hz) do som quando o Pac-Man come os fantasmas
            const int pacmanEatGhostFrequencies[] = {523,523,659,784,880,880,784,659,523,523,};
            // Durações correspondentes para cada nota (em ms)
            const int pacmanEatGhostDurations[] = {100,100,100,100,100,100,100,100,100,100,};
            tocar(BUZZER_PIN, pacmanEatGhostFrequencies, pacmanEatGhostDurations, 9);
            controlar_buzzer(BUZZER_PIN, false);
            sleep_ms(1000);
            break;
        default:
            Leds_Show_All(NULL, false);
            break;
        }
        // Draw_Pac_man();
    }
    return 0;
}
