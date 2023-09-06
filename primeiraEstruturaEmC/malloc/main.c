#include <stdio.h>
#include <malloc.h>
/*
+-------------------+-------------------------------------------------------------+
| Termo             | Descrição                                                   |
+-------------------+-------------------------------------------------------------+
| ponteiro          | Variável que aponta para um endereço na memória.            |
+-------------------+-------------------------------------------------------------+
| endereço de memória | Local onde a variável está armazenada.                    |
+-------------------+-------------------------------------------------------------+
| malloc            | Função que aloca memória dinamicamente.                     |
+-------------------+-------------------------------------------------------------+
| sizeof            | Operador que retorna a quantidade de bytes de um tipo.      |
+-------------------+-------------------------------------------------------------+
| *                 | Se usado à direita, indica que é uma variável que armazena  |
|                   | um ponteiro (ex: int* -> ponteiro para inteiro).            |
|                   | Se usado à esquerda, acessa o valor no endereço referenciado|
|                   | pela variável de ponteiro (ex: *y -> valor no endereço que  |
|                   | y está apontando).                                          |
+-------------------+-------------------------------------------------------------+
| &                 | Operador que retorna o endereço de uma variável.            |
+-------------------+-------------------------------------------------------------+
| (int*)            | Um cast para transformar um void* em int*.                  |
+-------------------+-------------------------------------------------------------+
*/


int main() {
  int* y = (int*) malloc(sizeof(int));
  *y = 20;
  int z = sizeof(int);
  printf("*y=i z=%i\n", *y, z);
  return 0;
}