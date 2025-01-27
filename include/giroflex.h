#ifndef GIROFLEX_H
#define GIROFLEX_H


void npInit(uint pin);
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);

void npClear();
void npWrite();

void LED_VERMELHO();
void LED_AZUL();
void PrimeiraInstancia();
void LED_TRIPLO_VERMELHO();
void LED_TRIPLO_AZUL();
void BRANCO();
#endif