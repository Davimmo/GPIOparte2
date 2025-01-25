#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7
#define delay 500
#define RED 200,0,0
#define BLUE 0,0,200

// Definição de pixel GRB
struct pixel_t {
  uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome de "struct pixel_t" para "npLED_t" por clareza.

// Declaração do buffer de pixels que formam a matriz.
npLED_t leds[LED_COUNT];

// Variáveis para uso da máquina PIO.
PIO np_pio;
uint sm;

/**
 * Inicializa a máquina PIO para controle da matriz de LEDs.
 */
void npInit(uint pin) {

    // Cria programa PIO.
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;

    // Toma posse de uma máquina PIO.
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0) {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true); // Se nenhuma máquina estiver livre, panic!
    }

    // Inicia programa na máquina PIO obtida.
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    // Limpa buffer de pixels.
    for (uint i = 0; i < LED_COUNT; ++i) {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
    }

    /**
     * Atribui uma cor RGB a um LED.
     */
    void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
    }

    /**
     * Limpa o buffer de pixels.
     */
    void npClear() {
    for (uint i = 0; i < LED_COUNT; ++i)
        npSetLED(i, 0, 0, 0);
    }

    /**
     * Escreve os dados do buffer nos LEDs.
     */
    void npWrite() {
    // Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
    for (uint i = 0; i < LED_COUNT; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
    }

   void ani(){

    // Inicializa entradas e saídas.
    stdio_init_all();

    // Inicializa matriz de LEDs NeoPixel.
    npInit(LED_PIN);
    npClear();

    // Aqui, você desenha nos LEDs.
    while(true){
        //frame 1:
        npSetLED(0, RED);
        npSetLED(9, RED);
        npSetLED(20, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 2:
        npSetLED(0, RED);
        npSetLED(1, RED);
        npSetLED(8, RED);
        npSetLED(10, RED);
        npSetLED(20, RED);
        npSetLED(21, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 3:
        npSetLED(0, RED);
        npSetLED(1, RED);
        npSetLED(2, RED);
        npSetLED(7, RED);
        npSetLED(11, RED);
        npSetLED(19, RED);
        npSetLED(20, RED);
        npSetLED(21, RED);
        npSetLED(22, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 4:
        npSetLED(1, RED);
        npSetLED(2, RED);
        npSetLED(3, RED);
        npSetLED(6, RED);
        npSetLED(12, RED);
        npSetLED(18, RED);
        npSetLED(21, RED);
        npSetLED(22, RED);
        npSetLED(23, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 5:
        npSetLED(2, RED);
        npSetLED(3, RED);
        npSetLED(4, RED);
        npSetLED(5, RED);
        npSetLED(13, RED);
        npSetLED(17, RED);
        npSetLED(22, RED);
        npSetLED(23, RED);
        npSetLED(24, RED);
        npSetLED(0, RED);
        npSetLED(9, RED);
        npSetLED(10, RED);
        npSetLED(19, RED);
        npSetLED(20, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();
        

        //frame 6:
        npSetLED(4, RED);
        npSetLED(3, RED);
        npSetLED(14, RED);
        npSetLED(16, RED);
        npSetLED(23, RED);
        npSetLED(24, RED);
        npSetLED(0, RED);
        npSetLED(1, RED);
        npSetLED(8, RED);
        npSetLED(18, RED);
        npSetLED(21, RED);
        npSetLED(11, RED);
        npSetLED(20, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 7:
        npSetLED(4, RED);
        npSetLED(15, RED);
        npSetLED(24, RED);
        npSetLED(0, RED);
        npSetLED(1, RED);
        npSetLED(2, RED);
        npSetLED(7, RED);
        npSetLED(12, RED);
        npSetLED(17, RED);
        npSetLED(22, RED);
        npSetLED(21, RED);
        npSetLED(19, RED);
        npSetLED(20, RED);
        npSetLED(10, RED);
        npSetLED(9, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 8:
        npSetLED(1, RED);
        npSetLED(2, RED);
        npSetLED(3, RED);
        npSetLED(6, RED);
        npSetLED(13, RED);
        npSetLED(16, RED);
        npSetLED(23, RED);
        npSetLED(22, RED);
        npSetLED(21, RED);
        npSetLED(18, RED);
        npSetLED(11, RED);
        npSetLED(8, RED);
        npSetLED(1, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();


        //frame 9:
        npSetLED(0, RED);
        npSetLED(9, RED);
        npSetLED(20, RED);
        npSetLED(2, RED);
        npSetLED(3, RED);
        npSetLED(4, RED);
        npSetLED(5, RED);
        npSetLED(14, RED);
        npSetLED(15, RED);
        npSetLED(24, RED);
        npSetLED(23, RED);
        npSetLED(22, RED);
        npSetLED(17, RED);
        npSetLED(12, RED);
        npSetLED(7, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 10:
        npSetLED(3, RED);
        npSetLED(4, RED);
        npSetLED(6, RED);
        npSetLED(13, RED);
        npSetLED(16, RED);
        npSetLED(23, RED);
        npSetLED(24, RED);
        npSetLED(21, RED);
        npSetLED(20, RED);
        npSetLED(10, RED);
        npSetLED(8, RED);
        npSetLED(1, RED);
        npSetLED(0, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 11:
        npSetLED(5, RED);
        npSetLED(4, RED);
        npSetLED(14, RED);
        npSetLED(15, RED);
        npSetLED(24, RED);
        npSetLED(22, RED);
        npSetLED(21, RED);
        npSetLED(20, RED);
        npSetLED(19, RED);
        npSetLED(11, RED);
        npSetLED(7, RED);
        npSetLED(0, RED);
        npSetLED(1, RED);
        npSetLED(2, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 12:
        npSetLED(1, RED);
        npSetLED(2, RED);
        npSetLED(3, RED);
        npSetLED(6, RED);
        npSetLED(12, RED);
        npSetLED(18, RED);
        npSetLED(21, RED);
        npSetLED(22, RED);
        npSetLED(23, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 13:
        npSetLED(2, RED);
        npSetLED(3, RED);
        npSetLED(4, RED);
        npSetLED(5, RED);
        npSetLED(13, RED);
        npSetLED(17, RED);
        npSetLED(22, RED);
        npSetLED(23, RED);
        npSetLED(24, RED);
        npSetLED(10, RED);
        npSetLED(19, RED);
        npSetLED(20, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 14:
        npSetLED(24, RED);
        npSetLED(23, RED);
        npSetLED(16, RED);
        npSetLED(14, RED);
        npSetLED(4, RED);
        npSetLED(3, RED);
        npSetLED(21, RED);
        npSetLED(18, RED);
        npSetLED(11, RED);
        npSetLED(10, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 15:
        npSetLED(24, RED);
        npSetLED(15, RED);
        npSetLED(4, RED);
        npSetLED(22, RED);
        npSetLED(17, RED);
        npSetLED(11, RED);
        npSetLED(12, RED);
        npSetLED(10, RED);
        npSetLED(19, RED);
        npSetLED(9, RED);
        npSetLED(20, RED);
        npSetLED(0, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 16:
        npSetLED(23, RED);
        npSetLED(16, RED);
        npSetLED(13, RED);
        npSetLED(12, RED);
        npSetLED(21, RED);
        npSetLED(11, RED);
        npSetLED(18, RED);
        npSetLED(8, RED);
        npSetLED(1, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 17:
        npSetLED(23, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, RED);
        npSetLED(12, RED);
        npSetLED(21, RED);
        npSetLED(11, RED);
        npSetLED(18, RED);
        npSetLED(8, RED);
        npSetLED(1, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 18:
        npSetLED(23, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, RED);
        npSetLED(11, RED);
        npSetLED(18, RED);
        npSetLED(8, RED);
        npSetLED(1, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 19:
        npSetLED(23, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, RED);
        npSetLED(11, BLUE);
        npSetLED(18, RED);
        npSetLED(8, RED);
        npSetLED(1, RED);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 20:
        npSetLED(23, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, RED);
        npSetLED(11, BLUE);
        npSetLED(18, RED);
        npSetLED(8, BLUE);
        npSetLED(1, BLUE);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 21:
        npSetLED(23, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, BLUE);
        npSetLED(11, BLUE);
        npSetLED(18, BLUE);
        npSetLED(8, BLUE);
        npSetLED(1, BLUE);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 22:
        npSetLED(23, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, BLUE);
        npSetLED(18, BLUE);
        npSetLED(8, BLUE);
        npSetLED(1, BLUE);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 23:
        npSetLED(23, BLUE);
        npSetLED(22, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, BLUE);
        npSetLED(18, BLUE);
        npSetLED(8, BLUE);
        npSetLED(1, BLUE);
        npWrite(); 
        sleep_ms(delay);
        npClear();

        //frame 24:
        npSetLED(23, BLUE);
        npSetLED(22, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, BLUE);
        npSetLED(2, BLUE);
        npSetLED(8, BLUE);
        npSetLED(1, BLUE);
        npWrite(); 
        sleep_ms(delay);
        npClear();


        //frame 24:
        npSetLED(23, BLUE);
        npSetLED(22, BLUE);
        npSetLED(16, BLUE);
        npSetLED(13, BLUE);
        npSetLED(12, BLUE);
        npSetLED(21, BLUE);
        npSetLED(2, BLUE);
        npSetLED(8, BLUE);
        npSetLED(1, BLUE);
        npSetLED(11, BLUE);
        npSetLED(3, BLUE);
        npWrite(); 
        sleep_ms(delay);
        npClear();
        
    
       sleep_ms(4000);
    }


    npWrite(); // Escreve os dados nos LEDs.

    // Não faz mais nada. Loop infinito.
    while (true) {
        sleep_ms(1000);
    }
}
