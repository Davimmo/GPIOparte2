#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

#define LED_PIN 2 // Pino de dados para a matriz de LEDs
#define NUM_LEDS 25 // Quantidade de LEDs na matriz 5x5

typedef struct {
    uint8_t r, g, b;
} Color;

// Função para configurar a matriz de LEDs
void set_leds(Color color, PIO pio, uint sm) {
    uint32_t rgb_value = (color.g << 16) | (color.r << 8) | color.b;
    for (int i = 0; i < NUM_LEDS; i++) {
        pio_sm_put_blocking(pio, sm, rgb_value << 8u);
    }
}

// Função principal
int main() {
    stdio_init_all();
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, LED_PIN, 800000, false);

    while (true) {
        // Aqui você detectaria a tecla "D" no teclado matricial
        // Simulando uma tecla D pressionada:
        bool key_d_pressed = true;

        if (key_d_pressed) {
            // Cor verde com 50% de luminosidade
            Color green = { .r = 0, .g = 127, .b = 0 }; // 127 de intensidade (50%)
            set_leds(green, pio, sm);
        }

        sleep_ms(100); // Pequeno delay
    }

    return 0;
}

#include <stdint.h>

#define NEW_PISKEL_FRAME_COUNT 5
#define NEW_PISKEL_FRAME_WIDTH 5
#define NEW_PISKEL_FRAME_HEIGHT 5

/* Piskel data for "New Piskel" */

static const uint32_t new_piskel_data[5][25] = {
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0002ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff0002ff, 0x00000000, 0xff0002ff, 0x00000000, 
0x00000000, 0xff0002ff, 0xff0002ff, 0xff0002ff, 0x00000000, 
0x00000000, 0x00000000, 0xff0002ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0xff0002ff, 0xff0002ff, 0x00000000, 0xff0002ff, 0xff0002ff, 
0xff0002ff, 0xff0002ff, 0xff0002ff, 0xff0002ff, 0xff0002ff, 
0xff0002ff, 0xff0002ff, 0xff0002ff, 0xff0002ff, 0xff0002ff, 
0x00000000, 0xff0002ff, 0xff0002ff, 0xff0002ff, 0x00000000, 
0x00000000, 0x00000000, 0xff0002ff, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xff0002ff, 0x00000000, 0xff0002ff, 0x00000000, 
0x00000000, 0xff0002ff, 0xff0002ff, 0xff0002ff, 0x00000000, 
0x00000000, 0x00000000, 0xff0002ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xff0002ff, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
}
};
