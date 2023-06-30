/* Escreve a série de Fibonnacci cujo último termo seja menor ou igual a N */

#include <stdio.h>

int main() {

  int N, soma, anterior = 0, atual = 1;

  do {
    printf("digite um N positivo\n");
    scanf("%d", &N);
  } while(N <= 0);

  printf("%d %d ", anterior, atual);

  soma = atual + anterior;
  while(soma <= N) {
    printf("%d ", soma);
    anterior = atual;
    atual = soma;
    soma = atual + anterior;
    
  }
  
  return 0;
}
