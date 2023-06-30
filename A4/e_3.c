/* Faça um programa que leia N números inteiros e informe se é primo*/

#include <stdio.h>

int num_primo(int num) {
  for (int i = 2; i <= num/2; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  
  int N, numero;
  printf("Quantos números? ");
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    printf("\nDigite um número: ");
    scanf(" %d", &numero);

    if (num_primo(numero))
      printf("É primo!");  
    else
      printf("Não é primo!");
  }
  
}
