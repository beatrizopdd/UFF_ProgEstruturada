/* Faça um programa que leia uma lista de números inteiros e que informe ao final a quantidade de números pares e impares encontrados */

#include <stdio.h>

int main() {
  
  int numero, pares = 0, impares = 0;

  scanf(" %d", &numero);
  while (numero != 0) {
    if (numero % 2 == 0) 
      pares += 1;
    else 
      impares += 1;

    scanf(" %d", &numero);
  }

  printf("\npares = %d, impares = %d", pares, impares);
  
  return 0;
}
