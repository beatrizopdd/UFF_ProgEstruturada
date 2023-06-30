/* Faça um programa que calcule o valor de E 
E = 1 + 1/(1!) + 1/(2!) + ... + 1/(N!)*/
#include <stdio.h>

int main() {

  int N, fat = 1;
  float E = 1;
  
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    fat *= i;
    E += (1.0 / fat);
  }

  printf("o valor de E para N=%d é %.4f", N, E);

  return 0;
}

/* o 1.0 na linha 14 serve pra transformar a variável fat em float*/
