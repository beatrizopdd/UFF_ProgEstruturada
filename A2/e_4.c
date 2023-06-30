/* Ler 3 números reais e checar se é um triângulo. Caso seja, checar se é equilátero, escaleno ou isosceles. */

#include <stdio.h>

int main(){

  int n1, n2, n3;

  printf("Digite 3 numeros: \n");
  scanf("%d %d %d", &n1, &n2, &n3);

  if (n1 + n2 > n3 && n3 + n2 > n1 && n1 + n3 > n2){
    printf("Sim é um triangulo \n");
    
    if (n1 == n2 && n1 == n3)
      printf("Equilátero");
      
    else if (n1 != n2 && n2 != n3 && n3 != n1)
      printf("Escaleno");
      
    else
      printf("Isósceles");
  
  } else
    printf("Não é um triangulo\n");

  return 0;
}
