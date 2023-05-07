# T2 - Estrutura de dados - Pilhas

## Questão 01 (5,0 pontos)
Elabore uma unidade sintática para representar a estrutura de dados pilha
implementada usando a técnica de alocação dinâmica de memória e implemente, no mínimo, as rotinas
para criar uma pilha, destruir uma pilha, verificar se uma pilha está vazia, recuperar o número de
elementos de uma pilha, verificar a ocorrência de um determinado elemento, recuperar o elemento de
determinada posição, recuperar o elemento do topo, empilhar, desempilhar e mostrar os elementos.

Considere que o elemento do topo de uma pilha ocupa a posição lógica 1 e que os elementos da pilha possam
ser de quaisquer tipos (genérico, portanto).

## Questão 02 (5,0 pontos)
Desenvolva um editor onde serão calculadas expressões aritméticas
formadas por constantes numéricas (inteiras e/ou reais) e pelos operadores de adição, subtração,
multiplicação e divisão, fazendo uso, necessariamente, da pilha implementada, para os cálculos.

Os comandos disponíveis para calcular as expressões aritméticas são:

|Comando            |Função                                                   |
|-------------------|---------------------------------------------------------|
|INICIO             |inicializa o programa                                    |
|ZERA               |(re)inicializa a expressao aritmetica                    |
|SOMA(valor)        |soma valor com o valor da expressão aritmética           |
|SUBTRAI(valor)     |subtrai valor com o valor da expressão                   |
|MULTIPLICA(valor)  |multiplica valor com o valor da expressão                |
|DIVIDE(valor)      |divide valor com o valor da expressão                    |
|PARCELAS           |exibe os valores de cada parcela da expressão aritmética |
|IGUAL              |exibe o resultado da avaliação da expressão artirmética  |
|FIM                |Finaliza o programa                                      |

Emitir a mensagem ** COMANDO INVÁLIDO **, caso seja digitado algum comando não disponível ou com
algum erro léxico/sintático (fazer o tratamento da entrada realizada pelo usuário).
Para a expressão aritmética `3 + 15 – 2.00 + 11`, tem-se a sequência de comandos
```
INICIO
ZERA
SOMA (3)
SOMA (15)
SUBTRAI (2.00)
IGUAL { exibe o valor 16.00 }
SOMA (11)
IGUAL { exibe o valor 27.00 }
PARCELAS { exibe os valores 18, 16.00 e 27.00 }
FIM
```