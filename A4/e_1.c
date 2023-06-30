/* Faça um programa imprima na tela um Menu que permita o usuário escolher as seguintes operações: +, -, /, * */

#include <stdio.h>

void menu(void);
void operacoes(char op, float A, float B);
void adicao(float A, float B);
void subtracao(float A, float B);
void multiplicacao(float A, float B);
void divisao(float A, float B);

int main() {

  float num1, num2, resultado;
  char operador;
  
  do {
    
    menu();
    printf("-> ");
    scanf(" %c", &operador);

    if (operador == '+' || operador == '-' || operador == '*' || operador == '/') {
      printf("Digite dois números: ");
      scanf(" %f %f", &num1, &num2);
    }
    operacoes(operador, num1, num2);
    
  } while (operador != '!');

  printf("Fim do programa!");

  return 0;
}

void menu(void) {
  printf("\nEscolha uma operação:\n");
  printf("(+) Adição\n");
  printf("(-) Subtração\n");
  printf("(*) Multiplicação\n");
  printf("(/) Divisão\n");
  printf("(!) Sair\n");
}

void adicao(float A, float B) {
  printf("%.2f + %.2f = %.2f", A, B, A+B);
}

void subtracao(float A, float B) {
  printf("%.2f - %.2f = %.2f", A, B, A-B);
}

void multiplicacao(float A, float B) {
  printf("%.2f * %.2f = %.2f", A, B, A*B);
}

void divisao(float A, float B) {
  if (A != 0 && B != 0)
    printf("%.2f / %.2f = %.2f", A, B, A/B);
  else 
    printf("Divisão por 0!");
}

void operacoes(char op, float A, float B) {
  switch (op) {
      case '+':
        adicao(A, B);
        break;
      
      case '-':
        subtracao(A, B);
        break;
      
      case '*':
        multiplicacao(A, B);
        break;
      
      case '/':
        divisao(A, B);
        break;
      
      case '!':
        break;
      
      default:
        printf("Operador inválido!");
    }  
}
