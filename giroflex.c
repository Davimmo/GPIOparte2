#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino.
#define LED_CONTADOR_MAX 25
#define LED_PIN 7

#define vermelho 255, 0, 0
#define branco 255, 255, 255
#define azul 0, 0, 255

// Definição de pixel GRB
struct cor_t
{
    uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
};
typedef struct cor_t cor_t;
typedef cor_t npLED_t; // Mudança de nome de "struct cor_t" para "npLED_t"

// Declaração do buffer de pixels que formam a matriz.
npLED_t leds[LED_CONTADOR_MAX];

// Variáveis para uso da máquina PIO.
PIO np_pio;
uint sm;

/*
 Inicializa a máquina PIO para controle da matriz de LEDs.
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
    for (uint i = 0; i < LED_CONTADOR_MAX; ++i)
    {
        leds[i].R = 0;
        leds[i].G = 0;
        leds[i].B = 0;
    }
}

/*
    Atribui uma cor RGB a um LED.
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
    for (uint i = 0; i < LED_CONTADOR_MAX; ++i)
        npSetLED(i, 0, 0, 0);
}

/**
 * Escreve os dados do buffer nos LEDs.
 */
void npWrite()
{
    // Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
    for (uint i = 0; i < LED_CONTADOR_MAX; ++i)
    {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

void Giroflex(){
    for (int LED_VERMELHO = 0; LED_VERMELHO < 3; LED_VERMELHO++)
    {
        // Acende o LED
        npSetLED(0, vermelho);
        npWrite();
        sleep_ms(125); // Mantém o LED aceso por 500ms

        npSetLED(1, vermelho);
        npWrite();
        sleep_ms(125); // Mantém o LED aceso por 500ms

        npSetLED(2, vermelho);
        npWrite();
        sleep_ms(125); // Mantém o LED aceso por 500ms

        npSetLED(0, 0, 0, 0);
        npWrite();
        sleep_ms(125);
        // Apaga o LED
        npSetLED(1, 0, 0, 0);
        npWrite();
        sleep_ms(125); // Mantém o LED apagado por 500ms

        npSetLED(2, 0, 0, 0);
        npWrite();
        sleep_ms(125);
    }
    //AZUL
    npClear();
    sleep_ms(500);

        for (int LED_AZUL = 0; LED_AZUL < 3; LED_AZUL++)
    {

        npSetLED(4, azul); // ligar
        npWrite();
        sleep_ms(125);

        npSetLED(3, azul); // ligar
        npWrite();
        sleep_ms(125);

        npSetLED(2, azul); // ligar
        npWrite();
        sleep_ms(125);

        npSetLED(4, 0, 0, 0); // Desligar
        npWrite();
        sleep_ms(125);

        npSetLED(3, 0, 0, 0); // desligar
        npWrite();
        sleep_ms(125);

        npSetLED(2, 0, 0, 0); // desligar
        npWrite();
        sleep_ms(125);
    }
    //PRIMEIRA INSTANCIA

        for (int PrimeiraInstancia = 0; PrimeiraInstancia < 2; PrimeiraInstancia++)
    {
        npSetLED(10, vermelho);
        npWrite();
        sleep_ms(250);

        npSetLED(11, vermelho);
        npWrite();
        sleep_ms(250);

        npSetLED(14, azul);
        npWrite();
        sleep_ms(250);

        npSetLED(13, azul);
        npWrite();
        sleep_ms(250);
    }
    // TRIPLO LED VERMELHO

         for (int LED_TRIPLO_VERMELHO = 0; LED_TRIPLO_VERMELHO < 2; LED_TRIPLO_VERMELHO++)
    {

        npSetLED(10, vermelho);
        npWrite();
        sleep_ms(125);

        npSetLED(11, vermelho);
        npWrite();
        sleep_ms(125);

        npSetLED(11, 0, 0, 0);
        npWrite();
        sleep_ms(1000);

        npSetLED(10, vermelho);
        npWrite();
        sleep_ms(175);

        npSetLED(11, vermelho);
        npWrite();
        sleep_ms(175);

        npSetLED(10, 0, 0, 0);
        npWrite();
        sleep_ms(75);

        npSetLED(11, 0, 0, 0);
        npWrite();
        sleep_ms(75);

        npSetLED(10, vermelho);
        npWrite();
        sleep_ms(100);

        npSetLED(10, 0, 0, 0);
        npWrite();
        sleep_ms(100);

        npSetLED(11, vermelho);
        npWrite();
        sleep_ms(100);

        npSetLED(11, 0, 0, 0);
        npWrite();
        sleep_ms(100);

        npSetLED(12, branco);
        npWrite();
        sleep_ms(100);

        npSetLED(12, 0, 0, 0);
        npWrite();
        sleep_ms(100);
    }
    // TRIPLO LED AZUL

    for (int LED_TRIPLO_AZUL = 0; LED_TRIPLO_AZUL < 2; LED_TRIPLO_AZUL++)
    {

        npSetLED(14, azul);
        npWrite();
        sleep_ms(125);

        npSetLED(13, azul);
        npWrite();
        sleep_ms(125);

        npSetLED(13, azul); // ponto
        npWrite();
        sleep_ms(1000);

        npSetLED(14, azul); // Ligar
        npWrite();
        sleep_ms(175);

        npSetLED(13, azul); // Ligar
        npWrite();
        sleep_ms(175);

        npSetLED(14, 0, 0, 0); // Desliga
        npWrite();
        sleep_ms(75);

        npSetLED(13, 0, 0, 0); // Desliga
        npWrite();
        sleep_ms(75);

        npSetLED(14, azul); // Ligar
        npWrite();
        sleep_ms(100);

        npSetLED(14, 0, 0, 0); // Desliga
        npWrite();
        sleep_ms(100);

        npSetLED(13, azul);
        npWrite();
        sleep_ms(100);

        npSetLED(13, 0, 0, 0); // Desliga
        npWrite();
        sleep_ms(100);

        npSetLED(12, branco);
        npWrite();
        sleep_ms(100);

        npSetLED(12, 0, 0, 0);
        npWrite();
        sleep_ms(100);
    }
    // TRIPLO LED BRANCO


        for (int BRANCO = 0; BRANCO < 2; BRANCO++)
    {
        npSetLED(10, vermelho);
        npWrite();
        sleep_ms(250);

        npSetLED(11, vermelho);
        npWrite();
        sleep_ms(250);

        npSetLED(14, azul);
        npWrite();
        sleep_ms(250);

        npSetLED(13, azul);
        npWrite();
        sleep_ms(250);

        // divisao
        npSetLED(10, 0, 0, 0);
        npWrite();
        sleep_ms(120);

        npSetLED(11, 0, 0, 0);
        npWrite();
        sleep_ms(120);

        npSetLED(14, 0, 0, 0);
        npWrite();
        sleep_ms(120);

        npSetLED(13, 0, 0, 0);
        npWrite();
        sleep_ms(120);

        npSetLED(12, branco);
        npWrite();
        sleep_ms(75);

        npSetLED(12, 0, 0, 0);
        npWrite();
        sleep_ms(125);

        npSetLED(12, branco);
        npWrite();
        sleep_ms(75);

        npSetLED(12, 0, 0, 0);
        npWrite();
        sleep_ms(125);
    }
}