/* Faça um programa para somar os múltiplos de N maiores do que 100 e menores do que 200 */

#include <stdio.h>

int exe8() {

  int N, multiplo, soma = 0;
  scanf("%d", &N);

  multiplo = N + N * (100 / N);
  while (multiplo < 200) {
    soma += multiplo;
    multiplo += N;
  }
  
  printf("O somatório é %d", soma);
  
  return 0;
}