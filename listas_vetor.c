#include <stdio.h>
#define TAM 5

struct Lista {
  int elementos[TAM];
  int total;
};
typedef struct Lista lista;

/* Verifica se o número está na lista */
int busca(lista L, int num) {
  
  for (int i = 0; i < L.total; i++)
    if (L.elementos[i] == num)
      return i;
  
  return (-1);
}

/* Insere (de forma não ordenada) o número no fim da lista */
void push(lista *L, int num) {
  
  if (L->total < TAM)
  
  	if (busca(*L, num) == -1) {
    	L->elementos[L->total] = num;
    	L->total += 1;
    } else
    	printf("Já está na lista!\n");
  
  else
    printf("Lista cheia!\n");
    
}

/* Remove o número */
int pop(lista *L, int num) {
  
  int lixo, posicao = busca(*L, num);
  
  if (posicao > -1) {
    lixo = L->elementos[posicao];
    L->total -= 1;
    for (int i = posicao; i < L->total; i++)
      L->elementos[i] = L->elementos[i+1];
      
  } else {
    lixo = -1;
    printf("Não está na lista!\n");
  }
  
  return lixo;
}

/* Imprime a lista */
void print(lista L) {
  
  for (int i = 0; i < L.total; i++)
    printf("%d ", L.elementos[i]);
    
  printf("\n"); 
}

int main() {
  int vetor[20] = {0, 5, 4, 1, 20, 3, 2, 6, 15, 7}; /*pytutor não admite input*/

  lista L;
  L.total = 0;
  
  /* Preenchendo a lista */
  for (int i = 0; i < TAM; i++)
    push(&L, vetor[i]);
    
  print(L);
  
  /* Esvaziando a lista */
  printf("Sai %d\n", pop(&L, 1));
  print(L);
  
  printf("Sai %d\n", pop(&L, 7));
  print(L);
  
  /* Preenchendo parcialmente a lista*/
  push(&L, 55);
  print(L);
  
  push(&L, 100);
  print(L);
  
  return 0;  
}
