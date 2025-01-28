#ifndef GIROFLEX
#define GIROFLEX



void Giroflex();

void npInit(uint pin);
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);

void npClear();
void npWrite();


#endif
