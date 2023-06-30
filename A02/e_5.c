/* Ler 2 números reais e perguntar ao usuário qual operação ele deseja realizar. */

#include <stdio.h>

int main(){

  float v1, v2, resultado;
  char operacao;

  printf("Digite dois números: ");
  scanf("%f %f", &v1, &v2);

  printf("Digite a operação: \n");
  printf("+: adição\n");
  printf("-: subtração\n");
  printf("/: divisão\n");
  printf("*: multiplicação\n");
  scanf("\n %c", &operacao);

  if (operacao == '+') {
    resultado = v1 + v2;
    printf("Resultado = %f", resultado);
  } 
  else if (operacao == '-') {
    resultado = v1 - v2;
    printf("Resultado = %f", resultado);
  } 
  else if (operacao == '/') {
    resultado = v1 / v2;
    printf("Resultado = %f", resultado);
  } 
  else if (operacao == '*') {
    resultado = v1 * v2;
    printf("Resultado = %f", resultado);
  } 
  
  return 0;
}
