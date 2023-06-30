/* Faça um programa que leia o número de registro de um funcionário e o seu salário. Sabendo que na empresa dois funcionários que recebem o mesmo salário, escreva o número de quem recebe mais. O final da entrada é marcado por numero < 0 */

#include <stdio.h>

int main() {

  int registro, mregistro;
  float salario, msalario = 0;

  scanf("%d", &registro);
  while (registro > 0) {
    
    printf("registro válido digite o salário\n");
    scanf("%f", &salario);
    if (salario > msalario) {
      mregistro = registro;
      msalario = salario;
    }
    
    scanf("%d", &registro);
  }

  printf("o funcionário %d recebe o maior salario de %d", mregistro, msalario);
  
  return 0;
}
