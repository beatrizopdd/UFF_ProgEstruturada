/* Faça um programa que calcule o fatorial de N */
#include <stdio.h>

int main() {

  int N, fatorial = 1;
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    fatorial *= i;
  }
  
  printf("Fatorial de %d == %d", N, fatorial);

  return 0;
}
