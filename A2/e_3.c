/* Ler 3 números e dizer o maior deles */

#include <stdio.h>

int main(){

  int n1, n2, n3;

  printf("Digite 3 numeros: \n");
  scanf("%d %d %d", &n1, &n2, &n3);

  if (n1 >= n2 && n1 >= n3)
    printf("%d", n1);
    
  else if (n2 >= n1 && n2 >= n3)
    printf("%d", n2);
  
  else
    printf("%d", n3);
  
  return 0;
}
