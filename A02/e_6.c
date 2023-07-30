/* Ler 2 números reais e escolher uma operação */

#include <stdio.h>

int main() {

  float num1, num2, resultado;
  char operacao;

  scanf("%f %f\n", &num1, &num2);
  scanf("%c", &operacao);

  switch(operacao) {

    case '+':
      printf("Resultado= %.2f", num1 + num2);
      break;
      
    case '-':
      printf("Resultado= %.2f", num1 - num2);
      break;
      
    case '*':
      printf("Resultado= %.2f", num1 * num2);
      break;
      
    case '/':
      printf("Resultado= %.2f", num1 / num2);
      break;
      
    default:
      printf("Operação inválida");  
    
  }
  
  return 0;
}
