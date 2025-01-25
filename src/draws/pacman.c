#include "leds.h"
#include "buzzer.h"
#include "pacman.h"


//Frames do Pacman
static uint32_t pacman_open_mouth[][3] = {
    {0, 0, 0}, {50,50,0}, {50,50,0}, {50,50,0}, {0, 0, 0},
    {50,50,0}, {0,0,0}, {0, 0, 0}, {50,50,0}, {50,50,0},
    {0,0,0}, {0,0,0},{50,50,0}, {0,0,0}, {50,50,0},
    {50,50,0}, {0,0,0}, {0, 0, 80}, {50,50,0}, {50,50,0},
    {0, 0, 0}, {50,50,0}, {50,50,0}, {50,50,0}, {0, 0, 0}
};
static uint32_t pacman_closed_mouth[][3] = {
    {0, 0, 0}, {50,50,0}, {50,50,0}, {50,50,0}, {0, 0, 0},
    {50,50,0}, {0,0,0}, {0, 0, 0}, {0,0,0}, {50,50,0},
    {80,80,0}, {80,80,0},{50,50,0}, {0,0,0}, {50,50,0},
    {50,50,0}, {0,0,0}, {0, 0, 50}, {0,0,0}, {50,50,0},
    {0, 0, 0}, {50,50,0}, {50,50,0}, {50,50,0}, {0, 0, 0}
};

//Frames do Ghost
static uint32_t ghost_frame0[][3] = {
    {0, 0, 50}, {0,0,0}, {0,0,50}, {0,0,0}, {0, 0, 50},
    {0,0,50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0,0,50},
    {0,0,50}, {0,0,0}, {0,0,0}, {0, 0, 0}, {0,0,50},
    {0,0,50}, {50,0,0},  {0,0,0}, {50,0,0}, {0, 0, 50},
    {0, 0, 0}, {0,0,50}, {0,0,50}, {0,0,50}, {0, 0, 0}
};

static uint32_t ghost_frame1[][3] = {
    {0,50,0}, {0,0,0}, {0,50,0}, {0,0,0}, {0,50,0},
    {0,50,0}, {0,50,0}, {0,50,0}, {0,50,0}, {0,50,0},
    {0,50,0}, {0,0,0}, {0,0,0}, {0, 0, 0}, {0,50,0},
    {0,50,0}, {0,0,50},  {0,0,0}, {0,0,50}, {0,50,0},
    {0, 0, 0}, {0,50,0}, {0,50,0}, {0,50,0}, {0, 0, 0}
};

static uint32_t ghost_frame2[][3] = {
    {50,0,0}, {0,0,0}, {50,0,0}, {0,0,0}, {50,0,0},
    {50,0,0}, {50,0,0}, {50,0,0}, {50,0,0}, {50,0,0},
    {50,0,0}, {0,0,0}, {0,0,0}, {0, 0, 0}, {50,0,0},
    {50,0,0}, {0,50,0},  {0,0,0}, {0,50,0}, {50,0,0},
    {0, 0, 0}, {50,0,0}, {50,0,0}, {50,0,0}, {0, 0, 0}
};

//Todos os Frames
// Array com as frequências (em Hz) dos sons característicos do Pac-Man
int pacmanFrequencies[] = {440, 494, 523, 587, 659, 698, 784, 880, 988, 1047,1175,1319,1397,1568,1760,1976,2637,2794,3136,3520,3951,4186,4699,5237};
// Array com as durações correspondentes (em ms) para cada frequência
int pacmanDurations[] = {200,200,200,100,150,200,150,300,100,200,150,150,200,250,150,350,120,150,180,200,250,150,100,300};
// Frequências (em Hz) do som quando o Pac-Man come os fantasmas
int pacmanEatGhostFrequencies[] = {523,523,659,784,880,880,784,659,523,523,};
// Durações correspondentes para cada nota (em ms)
int pacmanEatGhostDurations[] = {100,100,100,100,100,100,100,100,100,100,};


void Draw_Pac_man(uint pin_buzzer){
    controlar_buzzer(pin_buzzer, true);

    Leds_Show_All(pacman_closed_mouth, true);

    tocar(pin_buzzer, pacmanFrequencies, pacmanDurations, 24);

    Leds_Show_All(pacman_open_mouth, true);
    sleep_ms(500);
    Leds_Show_All(pacman_closed_mouth, true);

    tocar(pin_buzzer, pacmanEatGhostFrequencies, pacmanEatGhostDurations, 9);
    sleep_ms(500);
    int framesGhost = 5;
    for (size_t i = 0; i < framesGhost; i++){
        Leds_Show_All(ghost_frame0, true);
        sleep_ms(300);
        Leds_Show_All(ghost_frame1, true);
        sleep_ms(300);
        Leds_Show_All(ghost_frame2, true);
        sleep_ms(300);
    }
    sleep_ms(200);
    controlar_buzzer(pin_buzzer, false);
}