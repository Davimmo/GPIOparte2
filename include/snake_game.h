// snake_game.h

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <stdint.h>  // Para uint32_t, uint8_t, etc.
#include <stdbool.h> // Para o tipo bool

// Definições de constantes
#define LED_COUNT 25   // Exemplo, ajuste conforme necessário
#define LED_PIN 0      // Pino onde o LED está conectado
#define BUZZER_A 2     // Pino do buzzer A
#define BUZZER_B 3     // Pino do buzzer B
#define TEMPO_NOTA 100 // Duração da nota

// Tipos de dados
typedef struct {
    uint8_t R;
    uint8_t G;
    uint8_t B;
} npLED_t;

typedef struct {
    int snake[LED_COUNT];    // Posições dos segmentos da cobra
    int snake_length;        // Comprimento da cobra
    int snake_direction;     // Direção da cobra
    int apple_position;      // Posição da maçã
    bool game_over;          // Flag de fim de jogo
    int speed_factor;        // Fator de velocidade
} GameState;

// Declaração de funções
void play_tone(uint buzzer, int frequency, int duration, int volume);
void npInitLEDs(uint pin);
void npSetLEDColor(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void npClearAllLEDs();
void npUpdateLEDs();
int generateApple();
void moveSnake();
void drawSnake();
void finalAnimation();
void snake_game();

// Variáveis globais
extern npLED_t leds[LED_COUNT];
extern PIO np_pio;
extern uint sm;
extern GameState game_state;

#endif // SNAKE_GAME_H
