# Projeto Raspberry Pi Pico W - Interface com Teclado Matricial e Periféricos

# Vídeo sobre utilização do projeto: https://youtu.be/bacr5Y2bLQw


Este projeto utiliza a Raspberry Pi Pico para interagir com um teclado matricial 4x4, dois buzzers e uma matriz de LEDs 5x5. O sistema permite a detecção de teclas pressionadas e a execução de diferentes funções associadas a cada tecla. Este projeto, desenvolvido no contexto do **EmbarcaTech**, tem como objetivo explorar os terminais GPIO do microcontrolador **RP2040** da placa **Raspberry Pi Pico W**. Através de uma integração com o simulador **Wokwi** no **Visual Studio Code**, é possível realizar a simulação e verificação do funcionamento dos pinos GPIO para controle dos LEDs e dos buzzers.

## Funcionalidades
- Leitura de teclado matricial 4x4
- Controle de buzzer
- Controle de LEDs NeoPixel
- Execução de funções associadas a teclas
- Modo bootloader via tecla especial

## Hardware Utilizado
- Raspberry Pi Pico
- Teclado matricial 4x4
- Buzzer
- LEDs NeoPixel
- Fios e conexões

## Dependências
Este código faz uso da SDK do Raspberry Pi Pico. Para compilar e rodar, certifique-se de ter instalado:
- SDK do Raspberry Pi Pico W
- CMake
- Extensão Wokwi

## Como Usar
1. Conecte os periféricos conforme definido nos pinos.
2. Compile e carregue o firmware na Raspberry Pi Pico.
3. A placa iniciará a leitura do teclado e executará as funções associadas a cada tecla.
4. Para entrar no modo bootloader, pressione a tecla '*'.

## Mapeamento de Teclas
As teclas do teclado matricial são associadas às seguintes funções:
- **1** - Executa a função `principal()`
- **2** - Executa a função `Yuri()`
- **3** - Executa a função `davi()`
- **4** - Executa a função `animacao_nuvem()`
- **5** - Executa a função `snake_game()`
- **A** - Desliga todos os LEDs
- **B** - Deixa todos os LEDs na cor azul em 100% da potência
- **C** - Deixa todos os LEDs na cor vermelha em 80% da potência
- **D** - Deixa todos os LEDs na cor verde em 50% da potência 
- **#** - Deixa todos os LEDs na cor branca em 20% da potência
- ***** - Reinicia a Raspberry Pi Pico em modo bootloader

## Compilação e Upload
1. Clone este repositório.
2. Compile o código utilizando o CMake.
3. Copie o arquivo `.uf2` gerado para a unidade da Raspberry Pi Pico em modo bootloader.

## Autores
- **Davi Bezerra Cavalcanti**
- **João Vitor Maciel Lima**
- **Jaime Fernandes dos Reis Neto**
- **Maria Bianca Vitoria Coelho Marinho de Lima**
- **Yuri Reis Silva**
- **José Ricardo de Souza Santos (zrcrd)**

