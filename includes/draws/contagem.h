#ifndef CONTAGEM_H
#define CONTAGEM_H

#include "pico/stdlib.h"

/* função: contagem
   funcionamento: ao pressionar a tecla 0, os números de 1 a 5 aparecem na matriz de LEDs */
void contagem();

/* função: teclaB
   funcionamento: ao pressionar a tecla B, todos os LEDs são ligados na cor azul, 
   no nível de intensidade de 100% da luminosidade máxima */
void teclaB();

/* função: teclaC
   funcionamento: ao pressionar a tecla B, todos os LEDs são ligados na cor vermelha, 
   no nível de intensidade de 80% da luminosidade máxima */
void teclaC();

#endif