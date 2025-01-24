#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "configGpios.h"

#define FREQUENCIA_BUZZER 350 // Frequência do buzzer em Hz
static void config_pin(uint pin, bool INorOUT){
    gpio_init(pin);
    gpio_set_dir(pin, INorOUT);
}
// Função para inicializar periféricos
void inicializar_perifericos(uint pins_matriz_leds, uint pino_Buzzer, uint PINS_RGB[3], int *pins_rows_keypad, int *pins_columns_keypad){
    config_pin(PINS_RGB[0], GPIO_OUT);
    config_pin(PINS_RGB[1], GPIO_OUT);
    config_pin(PINS_RGB[2], GPIO_OUT);

    gpio_set_function(pino_Buzzer, GPIO_FUNC_PWM);
    int slice_num = pwm_gpio_to_slice_num(pino_Buzzer);

    uint32_t freq_sistema = clock_get_hz(clk_sys); // Frequência do sistema
    uint16_t wrap_valor = freq_sistema / FREQUENCIA_BUZZER - 1; // Define o valor de wrap
    pwm_set_wrap(slice_num, wrap_valor);
    pwm_set_gpio_level(pino_Buzzer, wrap_valor / 2); // Define duty cycle de 50%

    for (int i = 0; i < 4; i++){
        config_pin(pins_columns_keypad[i], GPIO_OUT);
        gpio_put(pins_columns_keypad[i], 1); // Inicializa como desativado
        config_pin(pins_rows_keypad[i], GPIO_IN);
        gpio_pull_up(pins_rows_keypad[i]); // Habilita pull-up
    }
}
