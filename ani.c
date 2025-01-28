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
#define RED 250, 0, 0
#define BLUE 0, 0, 250

// Definição de pixel GRB
struct pixel_t
{
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
void npInit(uint pin)
{

    // Cria programa PIO.
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;

    // Toma posse de uma máquina PIO.
    sm = pio_claim_unused_sm(np_pio, false);
    if (sm < 0)
    {
        np_pio = pio1;
        sm = pio_claim_unused_sm(np_pio, true); // Se nenhuma máquina estiver livre, panic!
    }

    // Inicia programa na máquina PIO obtida.
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    // Limpa buffer de pixels.
    for (uint i = 0; i < LED_COUNT; ++i)
    {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

/**
 * Atribui uma cor RGB a um LED.
 */
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b)
{
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}

/**
 * Limpa o buffer de pixels.
 */
void npClear()
{
    for (uint i = 0; i < LED_COUNT; ++i)
        npSetLED(i, 0, 0, 0);
}

/**
 * Escreve os dados do buffer nos LEDs.
 */
void npWrite()
{
    // Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
    for (uint i = 0; i < LED_COUNT; ++i)
    {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

void Yuri(){

    // Aqui, você desenha nos LEDs.

    // frame 1:
    npSetLED(0, RED);
    npSetLED(9, RED);
    npSetLED(20, RED);
    npWrite();
    sleep_ms(delay);
    npClear();

    // frame 2:
    npSetLED(0, RED);
    npSetLED(1, RED);
    npSetLED(8, RED);
    npSetLED(10, RED);
    npSetLED(20, RED);
    npSetLED(21, RED);
    npWrite();
    sleep_ms(delay);
    npClear();

    // frame 3:
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

    // frame 4:
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

    // frame 5:
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

    // frame 6:
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

    // frame 7:
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

    // frame 8:
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

    // frame 9:
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

    // frame 10:
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

    // frame 11:
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

    // frame 12:
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

    // frame 13:
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

    // frame 14:
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

    // frame 15:
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

    // frame 16:
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

    // frame 17:
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

    // frame 18:
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

    // frame 19:
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

    // frame 20:
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

    // frame 21:
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

    // frame 22:
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

    // frame 23:
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

    // frame 24:
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

    // frame 24:
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

    npWrite(); // Escreve os dados nos LEDs.
}


//mapeamento "zig-zag" na matriz
int getIndex(int x, int y){
	if(y%2 == 0){
		return 24-(y * 5 + x);
	}else{
		return 24-(y * 5 + (4-x));
	}
}


void animacao_nuvem(){
        //frame 1
        int animacao_pt1[5][5][3]={
            {{0,0,255}, {0,255,0}, {0,0,255}, {0,0,255}, {0,0,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}, {255,255,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}},
            {{0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}}};
        for(int linha = 0; linha<5; linha++){
            for(int coluna = 0; coluna <5; coluna++){
                int posição = getIndex(linha, coluna);
                npSetLED(posição, animacao_pt1[coluna][linha][0],animacao_pt1[coluna][linha][1],animacao_pt1[coluna][linha][2]);
            }
        }
        npWrite();
        sleep_ms(500);
        npClear();

        //frame 2
        int animacao_pt2[5][5][3]={
            {{0,0,255}, {0,255,0}, {0,0,255}, {0,0,255}, {255,255,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {255,255,255}, {255,255,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}},
            {{0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}}};
        for(int linha = 0; linha<5; linha++){
            for(int coluna = 0; coluna <5; coluna++){
                int posição = getIndex(linha, coluna);
                npSetLED(posição, animacao_pt2[coluna][linha][0],animacao_pt2[coluna][linha][1],animacao_pt2[coluna][linha][2]);
            }
        }
        npWrite();
        sleep_ms(500);
        npClear();

        //frame 3
        int animacao_pt3[5][5][3]={
            {{0,0,255}, {0,255,0}, {0,0,255}, {255,255,255}, {255,255,255}},
            {{0,255,0}, {0,255,0}, {255,255,255}, {255,255,255}, {255,255,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}},
            {{0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}}}; 
        for(int linha = 0; linha<5; linha++){
            for(int coluna = 0; coluna <5; coluna++){
                int posição = getIndex(linha, coluna);
                npSetLED(posição, animacao_pt3[coluna][linha][0],animacao_pt3[coluna][linha][1],animacao_pt3[coluna][linha][2]);
            }
        }
        npWrite();
        sleep_ms(500);
        npClear();

        //frame 4
        int animacao_pt4[5][5][3]={
            {{0,0,255}, {0,255,0}, {255,255,255}, {255,255,255}, {0,0,255}},
            {{0,255,0}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}},
            {{0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}}};
        for(int linha = 0; linha<5; linha++){
            for(int coluna = 0; coluna <5; coluna++){
                int posição = getIndex(linha, coluna);
                npSetLED(posição, animacao_pt4[coluna][linha][0],animacao_pt4[coluna][linha][1],animacao_pt4[coluna][linha][2]);
            }
        }
        npWrite();
        sleep_ms(500);
        npClear();

        //frame 5
        int animacao_pt5[5][5][3]={
            {{0,0,255}, {255,255,255}, {255,255,255}, {0,0,255}, {0,0,255}},
            {{255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {0,0,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}},
            {{0,0,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}},
            {{0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}}};
        for(int linha = 0; linha<5; linha++){
            for(int coluna = 0; coluna <5; coluna++){
                int posição = getIndex(linha, coluna);
                npSetLED(posição, animacao_pt5[coluna][linha][0],animacao_pt5[coluna][linha][1],animacao_pt5[coluna][linha][2]);
            }
        }
        npWrite();
        sleep_ms(500);

        npClear();
        sleep_ms(500);
        npWrite();
}

void tecla_c(){
    int vermelho[5][5][3]={
        {{204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}},
        {{204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}},
        {{204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}},
        {{204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}},
        {{204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}, {204,0,0}},
        };
    for(int linha = 0; linha<5; linha++){
            for(int coluna = 0; coluna <5; coluna++){
                int posição = getIndex(linha, coluna);
                npSetLED(posição, vermelho[coluna][linha][0],vermelho[coluna][linha][1],vermelho[coluna][linha][2]);
            }
        }
    npWrite();
    sleep_ms(4000);
    npClear();
    sleep_ms(4000);
    npWrite();
}

void tecla_b(){
    npClear();
    int i=0;
    for(i=0;i<25;i++){
        npSetLED(i,0,0,255);
    }
    npWrite();
}


void davi(){
    //frame 0:
    npSetLED(12,255,0,0);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 1:
    npSetLED(6,255,0,0);
    npSetLED(7,255,0,0);
    npSetLED(8,255,0,0); 
    npSetLED(11,255,0,0); 
    npSetLED(13,255,0,0); 
    npSetLED(16,255,0,0); 
    npSetLED(17,255,0,0); 
    npSetLED(18,255,0,0);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 2:
    npSetLED(0,255,0,0);
    npSetLED(1,255,0,0);
    npSetLED(2,255,0,0); 
    npSetLED(3,255,0,0); 
    npSetLED(4,255,0,0); 
    npSetLED(5,255,0,0); 
    npSetLED(9,255,0,0); 
    npSetLED(10,255,0,0);
    npSetLED(14,255,0,0);
    npSetLED(15,255,0,0);
    npSetLED(19,255,0,0);
    npSetLED(20,255,0,0);
    npSetLED(21,255,0,0);
    npSetLED(22,255,0,0);
    npSetLED(23,255,0,0);
    npSetLED(24,255,0,0);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 3:
    npSetLED(12,255,0,0);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 4:
    npSetLED(6,255,0,0);
    npSetLED(7,255,0,0);
    npSetLED(8,255,0,0); 
    npSetLED(11,255,0,0); 
    npSetLED(13,255,0,0); 
    npSetLED(16,255,0,0); 
    npSetLED(17,255,0,0); 
    npSetLED(18,255,0,0);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 5:
    npSetLED(0,255,0,0);
    npSetLED(1,255,0,0);
    npSetLED(2,255,0,0); 
    npSetLED(3,255,0,0); 
    npSetLED(4,255,0,0); 
    npSetLED(5,255,0,0); 
    npSetLED(9,255,0,0); 
    npSetLED(10,255,0,0);
    npSetLED(14,255,0,0);
    npSetLED(15,255,0,0);
    npSetLED(19,255,0,0);
    npSetLED(20,255,0,0);
    npSetLED(21,255,0,0);
    npSetLED(22,255,0,0);
    npSetLED(23,255,0,0);
    npSetLED(24,255,0,0);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 6:
    npSetLED(12,0,0,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 7:
    npSetLED(6,0,0,255);
    npSetLED(7,0,0,255);
    npSetLED(8,0,0,255); 
    npSetLED(11,0,0,255); 
    npSetLED(13,0,0,255); 
    npSetLED(16,0,0,255); 
    npSetLED(17,0,0,255); 
    npSetLED(18,0,0,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 8:
    npSetLED(0,0,0,255);
    npSetLED(1,0,0,255);
    npSetLED(2,0,0,255); 
    npSetLED(3,0,0,255); 
    npSetLED(4,0,0,255); 
    npSetLED(5,0,0,255); 
    npSetLED(9,0,0,255); 
    npSetLED(10,0,0,255);
    npSetLED(14,0,0,255);
    npSetLED(15,0,0,255);
    npSetLED(19,0,0,255);
    npSetLED(20,0,0,255);
    npSetLED(21,0,0,255);
    npSetLED(22,0,0,255);
    npSetLED(23,0,0,255);
    npSetLED(24,0,0,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 9:
    npSetLED(12,0,0,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 10:
    npSetLED(6,0,0,255);
    npSetLED(7,0,0,255);
    npSetLED(8,0,0,255); 
    npSetLED(11,0,0,255); 
    npSetLED(13,0,0,255); 
    npSetLED(16,0,0,255); 
    npSetLED(17,0,0,255); 
    npSetLED(18,0,0,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 11:
    npSetLED(0,0,0,255);
    npSetLED(1,0,0,255);
    npSetLED(2,0,0,255); 
    npSetLED(3,0,0,255); 
    npSetLED(4,0,0,255); 
    npSetLED(5,0,0,255); 
    npSetLED(9,0,0,255); 
    npSetLED(10,0,0,255);
    npSetLED(14,0,0,255);
    npSetLED(15,0,0,255);
    npSetLED(19,0,0,255);
    npSetLED(20,0,0,255);
    npSetLED(21,0,0,255);
    npSetLED(22,0,0,255);
    npSetLED(23,0,0,255);
    npSetLED(24,0,0,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 12
    npSetLED(0,255,255,255);
    
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 13
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 14
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 15
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
     
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 16
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 17
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 18
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
      
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 19
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 20
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
  
    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 21
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(9,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    
    //frame 22
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    //frame 23
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    //frame 24
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    //frame 25
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    //frame 26
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    //frame 27
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    //frame 28
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 29
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 30
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);


    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 31
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);
    npSetLED(19,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 32
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);
    npSetLED(19,255,255,255);
    npSetLED(20,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 33
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);
    npSetLED(19,255,255,255);
    npSetLED(20,255,255,255);
    npSetLED(21,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 34
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);
    npSetLED(19,255,255,255);
    npSetLED(20,255,255,255);
    npSetLED(21,255,255,255);
    npSetLED(22,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 35
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);
    npSetLED(19,255,255,255);
    npSetLED(20,255,255,255);
    npSetLED(21,255,255,255);
    npSetLED(22,255,255,255);
    npSetLED(23,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 36
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);
    npSetLED(19,255,255,255);
    npSetLED(20,255,255,255);
    npSetLED(21,255,255,255);
    npSetLED(22,255,255,255);
    npSetLED(23,255,255,255);
    npSetLED(24,255,255,255);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 37
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,255,255,255);
    npSetLED(16,255,255,255);
    npSetLED(17,255,255,255);
    npSetLED(18,255,255,255);
    npSetLED(19,255,255,255);
    npSetLED(20,200,200,200);
    npSetLED(21,200,200,200);
    npSetLED(22,200,200,200);
    npSetLED(23,200,200,200);
    npSetLED(24,200,200,200);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 38
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,255,255,255);
    npSetLED(11,255,255,255);
    npSetLED(12,255,255,255);
    npSetLED(13,255,255,255);
    npSetLED(14,255,255,255);
    npSetLED(15,200,200,200);
    npSetLED(16,200,200,200);
    npSetLED(17,200,200,200);
    npSetLED(18,200,200,200);
    npSetLED(19,200,200,200);
    npSetLED(20,100,100,100);
    npSetLED(21,100,100,100);
    npSetLED(22,100,100,100);
    npSetLED(23,100,100,100);
    npSetLED(24,100,100,100);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 39
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,255,255,255);
    npSetLED(6,255,255,255);
    npSetLED(7,255,255,255);
    npSetLED(8,255,255,255);
    npSetLED(9,255,255,255);
    npSetLED(10,200,200,200);
    npSetLED(11,200,200,200);
    npSetLED(12,200,200,200);
    npSetLED(13,200,200,200);
    npSetLED(14,200,200,200);
    npSetLED(15,100,100,100);
    npSetLED(16,100,100,100);
    npSetLED(17,100,100,100);
    npSetLED(18,100,100,100);
    npSetLED(19,100,100,100);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    
    //frame 40
    npSetLED(0,255,255,255);
    npSetLED(1,255,255,255);
    npSetLED(2,255,255,255);
    npSetLED(3,255,255,255);
    npSetLED(4,255,255,255);
    npSetLED(5,200,200,200);
    npSetLED(6,200,200,200);
    npSetLED(7,200,200,200);
    npSetLED(8,200,200,200);
    npSetLED(9,200,200,200);
    npSetLED(10,100,100,100);
    npSetLED(11,100,100,100);
    npSetLED(12,100,100,100);
    npSetLED(13,100,100,100);
    npSetLED(14,100,100,100);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //frame 41
    npSetLED(0,200,200,200);
    npSetLED(1,200,200,200);
    npSetLED(2,200,200,200);
    npSetLED(3,200,200,200);
    npSetLED(4,200,200,200);
    npSetLED(5,100,100,100);
    npSetLED(6,100,100,100);
    npSetLED(7,100,100,100);
    npSetLED(8,100,100,100);
    npSetLED(9,100,100,100);

    npWrite(); 
    sleep_ms(delay);
    npClear();
    
    //frame 42
    npSetLED(0,100,100,100);
    npSetLED(1,100,100,100);
    npSetLED(2,100,100,100);
    npSetLED(3,100,100,100);
    npSetLED(4,100,100,100);

    npWrite(); 
    sleep_ms(delay);
    npClear();

    //Frame 43
    npWrite();
    sleep_ms(400);
    
}
