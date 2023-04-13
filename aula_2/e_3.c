/* Ler 3 números e dizer o maior deles */

#include <stdio.h>

int exe3(){

  int n1,n2,n3;

  printf("dita 3 numero ai pfvzinho \n");
  scanf("%d %d %d", &n1, &n2, &n3);

  if (n1 >= n2 && n1 >= n3)
    printf("%d", n1);
  else if (n2 >= n1 && n2 >= n3)
    printf("%d", n2);
  else
    printf("%d", n3);
  
  return 0;
}
