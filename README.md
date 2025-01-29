# GPIOparte2

_______________________________________________________________________________________________
JJaime Fernandes Dos Reis Neto

# Snake Game com Matriz de LEDs WS2812 e Raspberry Pi Pico W

Este projeto implementa uma versão do clássico jogo Snake utilizando uma matriz de LEDs WS2812, controlada por um Raspberry Pi Pico W. O jogo inclui efeitos de iluminação, controle de velocidade e sons emitidos pelo um buzzer.

## Funcionalidades

- **Matriz de LEDs (5x5)**: A cobra é representada por LEDs que muda de cor conforme a posição
  - Cabeça: Azul
  - Corpo: Vermelho
  - Maçã: Verde.
- **Aceleração Progressiva**: A velocidade da cobra aumenta à medida que ela coome a maça e cresce.
- **Som**: Tons são tocados ao consumir uma maçã e durante a animação final.
- **Animação Final**: Quando a cobra preenche toda a matriz, uma sequência de cores é exibida, acompanhada por sons.
- **Reinício Automático**: O jogo reinicia automaticamente ao término.

## Pinos Utilizados

| Função      | GPIO  |
|-------------|-------|
| Matriz LEDs | 7     |
| Buzzer A    | 10    |
| Buzzer B    | 21    |


## Como Funciona

1. **Inicialização**: 
   - LEDs são inicializados com a cor apagada.
   - A cobra inicia na posição inicial e uma maçã é gerada aleatoriamente.
2. **Movimento**:
   - A cobra se move continuamente, mudando de direção ao consumir maçãs.
   - Quando a cobra come uma maçã:
     - Ela cresce.
     - Um som é tocado.
     - Uma nova maçã é gerada.
   - Se a cobra colidir consigo mesma ou preencher toda a matriz, o jogo termina.
3. **Fim do Jogo**:
   - Ao preencher toda a matriz, uma animação final é exibida.
   - O jogo é reiniciado automaticamente.
