#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <stdint.h> 
#include <stdbool.h>

#define LED_COUNT 25
#define LED_PIN 7
#define BUZZER_A 10
#define BUZZER_B 21
#define delay 400  
#define RED 200,0,0
#define GREEN 0,200,0
#define BLUE 0,0,200
#define TEMPO_NOTA 100 

struct pixel_t {
  uint8_t G, R, B;
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t;

void npInitLEDs(uint32_t pin);  
void npSetLEDColor(const uint32_t index, const uint8_t r, const uint8_t g, const uint8_t b);  // Altera a cor de um LED específico
void npClearAllLEDs();  // Limpa todos os LEDs
void npUpdateLEDs();  // Atualiza os LEDs com as cores definidas

void play_tone(uint32_t buzzer, int frequency, int duration, int volume);
int generateApple();
void moveSnake();
void drawSnake();
void finalAnimation();
void snake_game();

#endif 
