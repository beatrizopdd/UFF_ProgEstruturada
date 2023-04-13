/* Ler a base e a altura de um triângulo e calcular a área */

#include <stdio.h>

int main(){

  float base, altura, area;

  scanf("%f %f", &base, &altura);

  area = (base * altura) / 2; 

  printf("Área = %f", area);
  
  return 0;
}