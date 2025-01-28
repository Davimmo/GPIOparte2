#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ani.h"
// Biblioteca gerada pelo arquivo .pio durante compilação.


// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7

#define vermelho 255, 0, 0
#define branco 255, 255, 255
#define azul 0, 0, 255



void principal(){
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