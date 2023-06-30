/* Faça um programa que leia N números inteiros e informe se é perfeito ou não. Crie uma função lógica que retorne 0 ou 1*/

#include <stdio.h>

int num_perfeito(int num) {
  
  int soma = 1;
  for (int i = 2; i <= num/2; i++) {
    if (num % i == 0) {
      soma += i;
    }
  }

  if (num == soma)
    return 1;
  else
    return 0;
  
}

int main() {
  
  int N, numero;
  printf("Quantos números? ");
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    printf("\nDigite um número: ");
    scanf(" %d", &numero);

    if (num_perfeito(numero))
      printf("É perfeito!");  
    else
      printf("Não é perfeito!");
  }
  
}
