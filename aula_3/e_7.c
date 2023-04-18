/* Faça um programa para somar múltiplos de N menores que 200 */

#include <stdio.h>
int exe7() {

  int N, multiplo, soma = 0;
  scanf("%d", &N);
  
  multiplo = N;
  while (multiplo < 200) {
    /* if (multiplo % N == 0) soma += multiplo;
    multiplo += 1; */
    
    soma += multiplo;
    multiplo += N;
    
  }

  printf("A soma dos múltiplos de %d é igual a %d", N, soma);
  
  return 0;
}