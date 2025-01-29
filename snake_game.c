#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "ws2818b.pio.h"
#include "snake_game.h"  // Incluir o header para as variáveis externas

// Variáveis globais
npLED_t leds[LED_COUNT];
PIO np_pio;
uint sm;

int snake[LED_COUNT];
int snake_length = 1;
int snake_direction = 1;
int apple_position = 10;
bool game_over = false;
int speed_factor = 0;  // Acelerador da velocidade da cobra

// Função para tocar buzzer
void play_tone(uint buzzer, int frequency, int duration, int volume) {
    if (frequency == 0) {
        sleep_ms(duration);
        return;
    }

    uint slice = pwm_gpio_to_slice_num(buzzer);
    pwm_set_clkdiv(slice, 4.0f);

    uint32_t wrap = clock_get_hz(clk_sys) / (frequency * 4);
    pwm_set_wrap(slice, wrap);

    uint16_t duty_cycle = (wrap * volume) / 100; 
    pwm_set_gpio_level(buzzer, duty_cycle);
    pwm_set_enabled(slice, true);

    sleep_ms(duration);
    pwm_set_enabled(slice, false);
    sleep_ms(50);
}

void npInitLEDs(uint pin) { 
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0) {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true);
    }
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);
    for (uint i = 0; i < LED_COUNT; ++i) {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

void npSetLEDColor(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}

void npClearAllLEDs() {  
    for (uint i = 0; i < LED_COUNT; ++i)
        npSetLEDColor(i, 0, 0, 0);
}

void npUpdateLEDs() {  
    for (uint i = 0; i < LED_COUNT; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100);
}

int generateApple() {
    int new_apple_position;
    bool valid_position = false;
    
    if (snake_length >= LED_COUNT) {
        return -1; // Indicar que já não há mais espaço pra maçã
    }

    while (!valid_position) {
        new_apple_position = rand() % LED_COUNT;
        valid_position = true;
        for (int i = 0; i < snake_length; i++) {
            if (snake[i] == new_apple_position) {
                valid_position = false;
                break;
            }
        }
    }
    return new_apple_position;
}

void moveSnake() {
    // Move o corpo da cobra para frente
    for (int i = snake_length; i > 0; --i) {
        snake[i] = snake[i - 1]; 
    }

    // Move a cabeça na direção correta
    if (snake_direction == 1) { 
        snake[0] = (snake[0] + 1) % LED_COUNT;
    } else if (snake_direction == -1) {
        snake[0] = (snake[0] - 1 + LED_COUNT) % LED_COUNT;
    }

    // Verifica se comeu a maçã
    if (snake[0] == apple_position) {
        if (snake_length < LED_COUNT) { 
            // Cresce até ocupar todos os espaços
            snake_length++;
            // Aumenta a velocidade
            speed_factor++;  
        }
          //gerar outra maçã
        apple_position = generateApple();
        play_tone(BUZZER_A, 1331, TEMPO_NOTA, 80);
        play_tone(BUZZER_B, 1600, TEMPO_NOTA, 80);
    }

    // Verifica se a cobra colidiu consigo mesma
    for (int i = 1; i < snake_length; i++) {
        if (snake[0] == snake[i]) {
            game_over = true;
            return;
        }
    }
}

void drawSnake() {
    npClearAllLEDs();
    if (snake_length > 0) {
        npSetLEDColor(snake[0], 0x00, 0x00, 0xFF); // Cabeça azul
    }
    for (int i = 1; i < snake_length; i++) {
        npSetLEDColor(snake[i], 0xFF, 0x00, 0x00); // Corpo vermelho
    }
    if (apple_position != -1) {
        npSetLEDColor(apple_position, 0x00, 0xFF, 0x00); // Maçã verde
    }
    npUpdateLEDs();
}

// Animação final 
void finalAnimation() {
    for (int i = 0; i < 5; i++) {
        npClearAllLEDs();
        npUpdateLEDs();
        play_tone(BUZZER_A, 1000, 100, 80);
        sleep_ms(200);
        
        for (int j = 0; j < LED_COUNT; j++) {
            npSetLEDColor(j, rand() % 255, rand() % 255, rand() % 255);
        }
        npUpdateLEDs();
        play_tone(BUZZER_B, 1500, 100, 80);
        sleep_ms(200);
    }
    npClearAllLEDs();
    npUpdateLEDs();
    sleep_ms(2000);
}

void snake_game() {
    while (!game_over) {
        moveSnake();
        drawSnake();
        int delay = 1000; 
        //acelera a cobra à medida que cresce
        int current_delay = delay - (speed_factor * 20);  
        if (current_delay < 50) {
            current_delay = 50;
        }

        sleep_ms(current_delay);

        // Verificar se tem mais espaço para gerar uma maçã
        if (snake_length >= LED_COUNT && apple_position == -1) {
            game_over = true;
        }
    }

    // Se a cobra ocupou todos os espaços, executa a animação final
    if (snake_length >= LED_COUNT && apple_position == -1) {
        finalAnimation();
    }

    // Reiniciar o jogo
    npClearAllLEDs();
    npUpdateLEDs();
    sleep_ms(2000);
    snake_length = 1;
    snake_direction = 1;
    apple_position = generateApple();
    speed_factor = 0;  
    game_over = false;
}

int main() {
    stdio_init_all();
    npInitLEDs(LED_PIN);  
    gpio_set_function(BUZZER_A, GPIO_FUNC_PWM);
    gpio_set_function(BUZZER_B, GPIO_FUNC_PWM);
    snake[0] = 0;
    
    while (true) { // Loop infinito para reiniciar o jogo
        apple_position = generateApple();
        snake_length = 1;
        snake_direction = 1;
        game_over = false;
        snake_game();
    }

    return 0;
}
