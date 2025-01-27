#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include "configGpios.h"
#include "tecladoMatricial4x4.h"
#include "leds.h"
#include "buzzer.h"
#include "pacman.h"
#include "colorido.h"
#include "rosto.h"
#include "pato.h"
#include "girafa.h"
#include "chuva.h"
#include "embarcatech.h"
#include "contagem.h"
#include "ledsBrancos.h"
#include "raio.h"
#include "leds_verde.h"


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
        case '0':
            contagem();
            break;
        case '1':
            chuva_pixels();
            break;
        case '2':
            exibir_embarcatech();
            break;
        case '3':
            raio();
            break;
        case '4':
            Draw_Pac_man(BUZZER_PIN);
            break;
        case '6':
            animacao_rosto();
            break;
        case '7':
            movimento_girafa();
            break;
        case '8':
            animacao_pato();
            break;
        case '9':
            colorido();
            break;
        case 'B':
            teclaB();
            break;
        case 'C': 
            teclaC();
            break;
        case 'D': 
            leds_verde();
            break;
        case '*':
            printf("Entrando no modo de gravação via USB...\n");
            sleep_ms(1000); // Pequeno delay para garantir que a mensagem seja exibida antes do reboot
            printf("1...\n");
            sleep_ms(1000);
            printf("2...\n");
            sleep_ms(1000);
            printf("3...\n");
            sleep_ms(1000);
            printf("Rebootando...\n");
            reset_usb_boot(0, 0); // Reboot para modo de gravação
            break;
        case '#':
            Draw_Leds_Writes();
            break;
        default:
            Leds_Show_All(NULL, false);
            break;
        }
    }
    return 0;
}

