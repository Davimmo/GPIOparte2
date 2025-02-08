#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define TECLA_D 5  // Defina o pino correspondente à tecla D
#define LED 15     // Defina o pino de um LED para testar a tecla D

void configurar_pinos() {
    gpio_init(TECLA_D);
    gpio_set_dir(TECLA_D, GPIO_IN);
    gpio_pull_up(TECLA_D);  // Habilita o resistor pull-up interno

    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
}

void loop() {
    while (1) {
        if (gpio_get(TECLA_D) == 0) {  // Se a tecla D for pressionada
            gpio_put(LED, 1);          // Liga o LED
            printf("Tecla D pressionada!\n");
        } else {
            gpio_put(LED, 0);          // Desliga o LED
        }
        sleep_ms(100);  // Pequeno atraso para evitar leituras erradas
    }
}

int main() {
    stdio_init_all();
    configurar_pinos();
    loop();
    return 0;
}
