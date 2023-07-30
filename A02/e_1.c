/* Ler 3 notas e escrever a média aritmética */

#include <stdio.h>

int main() {

  float nota1, nota2, nota3, media;
  
  /*scanf("%f %f %f", &nota1, &nota2, &nota3);*/
  nota1 = 6.75; 
  nota2 = 9.5;
  nota3 = 3.4;
  
  media = (nota1 + nota2 + nota3) / 3;
  
  printf("Média final = %f", media);
  
  return 0;
}
