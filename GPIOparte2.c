#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
<<<<<<< HEAD
#include "giroflex.h"
=======
#include "pico/bootrom.h"
>>>>>>> 595a3f4abc28d3acbe27802d895766bb94aa5365
#include "ani.h"

#define LED_PIN 7

#define BUZZER 21

<<<<<<< HEAD
#define BUZZER_PIN 21 // Porta associada ao Buzzer
#define linhas 4      // Definindo Linhas da Matriz
#define colunas 4     // Definindo colunas da Matriz
=======
#define BUZZER_PIN 21 //Porta associada ao Buzzer
#define linhas 4  // Definindo Linhas da Matriz
#define colunas 4 // Definindo colunas da Matriz

//rotina da interrupção
static void gpio_irq_handler(uint gpio, uint32_t events){
    printf("Interrupção ocorreu no pino %d, no evento %d\n", gpio, events);
    printf("HABILITANDO O MODO GRAVAÇÃO");
	reset_usb_boot(0,0); //habilita o modo de gravação do microcontrolador
}

>>>>>>> 595a3f4abc28d3acbe27802d895766bb94aa5365

// Criação de matriz para ler linha e coluna do programa.
const uint8_t PINOS_DA_LINHA[linhas] = {8, 28, 6, 5};
const uint8_t PINOS_DA_COLUNA[colunas] = {4, 3, 2, 1};

<<<<<<< HEAD
=======


>>>>>>> 595a3f4abc28d3acbe27802d895766bb94aa5365
const char key_map[linhas][colunas] = { // criação da função para fazer o mapeamento de teclas nas linhas e colunas
    {'1', '2', '3', 'A'},

    {'4', '5', '6', 'B'},

    {'7', '8', '9', 'C'},

    {'*', '0', '#', 'D'}};

void init_gpio()
{

    // Inicializar buzzer como saída
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0); // Inicialmente desligado
}

// Função para acionar periféricos
void control_output(uint gpio, bool state)
{
    gpio_put(gpio, state);
}

void keypad_init()
{
    // Implementacao dos LEDS

    for (int i = 0; i < linhas; i++)
    { // percorre as linhas
        gpio_init(PINOS_DA_LINHA[i]);
        gpio_set_dir(PINOS_DA_LINHA[i], GPIO_OUT);
        gpio_put(PINOS_DA_LINHA[i], 0);
    }
    for (int j = 0; j < colunas; j++)
    { // percorre as colunas
        gpio_init(PINOS_DA_COLUNA[j]);
        gpio_set_dir(PINOS_DA_COLUNA[j], GPIO_OUT);
        gpio_put(PINOS_DA_COLUNA[j], 0);
    }
}
char read_keypad()
{
    for (int linha = 0; linha < linhas; linha++)
    {
        gpio_put(PINOS_DA_LINHA[linha], 1);
        for (int coluna = 0; coluna < colunas; coluna++)
        {
            if (gpio_get(PINOS_DA_COLUNA[coluna]))
            {
                gpio_put(PINOS_DA_LINHA[linha], 0);
                return key_map[linha][coluna];
            }
        }
        gpio_put(PINOS_DA_LINHA[linha], 0);
    }
    return '\0';
}

void buzz(uint freq, uint tempo)
{

    uint slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    uint channel = pwm_gpio_to_channel(BUZZER_PIN);

    // Configurando a frequência
    uint32_t clock_freq = 125000000;
    uint32_t divider = clock_freq / freq / 65536 + 1;
    uint32_t top = clock_freq / (divider * freq);

    // Configurando as repetições
    pwm_set_clkdiv(slice_num, divider);
    pwm_set_wrap(slice_num, top - 1);
    pwm_set_chan_level(slice_num, channel, top / 2);
    pwm_set_enabled(slice_num, true);

    sleep_ms(tempo);

    pwm_set_enabled(slice_num, false);
}

int main()
{

    stdio_init_all();
    keypad_init();

    // Inicializa entradas e saídas.
    stdio_init_all();

    // Inicializa matriz de LEDs NeoPixel.
    npInit(LED_PIN);
    npClear();
    npWrite();
    sleep_ms(500);




    while (true)
    {

        char key = read_keypad();
        if (key != '\0')
        {
            printf("Tecla pressionada: %c\n", key);

            switch (key)
            {
            case '1':

                principal();

                break;
            case '2':

<<<<<<< HEAD
                Yuri();

                break;
            case '3':
=======
                
                
                break;
            case '3':
                
                davi();
>>>>>>> 595a3f4abc28d3acbe27802d895766bb94aa5365

                break;

            case '4':

                animacao_nuvem();

                break;

            case '5':

                break;

            case '6':

                break;

            case 'B':
<<<<<<< HEAD
=======
                tecla_b();
                break;
>>>>>>> 595a3f4abc28d3acbe27802d895766bb94aa5365

                break;
            case '7':
                
                break;
            case '8':

                break;

            case '9':

                break;

            case 'C':

<<<<<<< HEAD
                break;
            case '*':

=======
                tecla_c();
                
                break;
            case '*':
                reset_usb_boot(0, 0); // Reinicia o Raspberry em modo bootloader
                
>>>>>>> 595a3f4abc28d3acbe27802d895766bb94aa5365
                break;
            case '0':

                break;

            case '#':
                gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
                buzz(550, 500); // Frequência de 550Hz por um tempo de 500ms
                sleep_ms(500);

                // Buzzers

                break;

            case 'A':
                // Todos os leds serão desligados
                npClear();
                npWrite();

                break;

            case 'D':

                break;
            default:

                break;
            }
        }
        sleep_ms(100);
    }
    return 0;
}