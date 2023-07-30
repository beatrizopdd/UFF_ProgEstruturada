/* Leia N números inteiros e escreva o somatório dos múltiplos de 3 e a média dos pares */

#include <stdio.h>
#define N 5

int main() {

  int numero, index = 0;
  int soma2 = 0, qtdP = 0;
  int soma3 = 0;
  float media;
  
  printf("Quantos números inteiros? ");
  /*scanf("%d", &N);*/
  
  int numeros[N] = {2, 7, 8, 9, 27}; 
  
  do {
    
    printf("\nDigite um número:");
    /*scanf(" &d", &numero);*/
    numero = numeros[index];
    
    if (numero % 3 == 0) 
      soma3 += numero;

    if (numero % 2 == 0) {
      soma2 += numero;
      qtdP += 1;
    }
    
    index += 1;
      
  } while (index < N);
  
  media = (soma2 * 1.0) / qtdP;
    
  printf("\nSomatório dos múltiplos de 3 = %d \nMédia dos pares = %.1f", soma3, media);

  return 0;
}
