#include "pico/stdlib.h"
#include "tecladoMatricial4x4.h"

// Mapeamento do teclado matricial 4x4 para os caracteres correspondentes
static const char map_keypad[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
// Função para capturar a tecla pressionada no teclado matricial
char Get_Key_clicked(int pins_rows[4], int pins_columns[4]) {
    static char last_key = 'n'; // Armazena a última tecla pressionada ('n' indica nenhuma tecla)
    char current_key = 'n';         // Variável para armazenar a tecla atualmente detectada
    // Percorre todas as colunas do teclado
    for (int column = 0; column < 4; column++) {
        gpio_put(pins_columns[column], 0); // Ativa a coluna atual (define como LOW)
        // Percorre todas as linhas do teclado
        for (int row = 0; row < 4; row++) {
            // Verifica se uma tecla na interseção da linha e coluna foi pressionada
            if (gpio_get(pins_rows[row]) == 0) { 
                current_key = map_keypad[3 - row][column]; // Mapeia a tecla pressionada com base na matriz
                // Aguarda até que a tecla seja liberada (debounce)
                while (gpio_get(pins_rows[row]) == 0) { 
                    sleep_ms(10); // Pequena pausa para evitar erros de leitura
                }
                break; // Sai do loop de linhas se uma tecla foi pressionada
            }
        }

        gpio_put(pins_columns[column], 1); // Desativa a coluna atual (define como HIGH)

        // Sai do loop de colunas se uma tecla foi detectada
        if (current_key != 'n')
            break;
    }
    // Atualiza a última tecla pressionada somente se for diferente da anterior
    if (current_key != 'n' && current_key != last_key) {
        last_key = current_key;
    }
    return current_key; // Retorna a tecla detectada ou 'n' se nenhuma tecla foi pressionada
}
