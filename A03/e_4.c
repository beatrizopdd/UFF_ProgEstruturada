/* POR ALGUM MOTIVO DA MUITO ERRADO */
/* Leia N números inteiros e escreva o somatório dos múltiplos de 3 e a média dos pares */

#include <stdio.h>

int main() {

  int N, numero, soma3;
  float soma2, qtdP = 0;
  printf("Quantos números inteiros? ");
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    printf("Digite um número: ");
    scanf(" &d", &numero);
  }
  
  /*
  do {
    
    printf("Digite um número:");
    scanf(" &d", &numero);
    
    
    if (numero % 3 == 0) 
      soma3 += numero;

    if (numero % 2 == 0) {
      qtdP += 1;
      soma2 += numero;
    }
    
    index += 1;
      
  } while (index < N);
  */
    
  printf("\nSomatório dos múltiplos de 3 = %d \nMédia dos pares = %.3f", soma3, soma2/qtdP);

  return 0;
} 
