#include <stdio.h>
#define TAM 5

struct Lista {
  int elementos[TAM];
  int total;
};
typedef struct Lista lista;

/* Verifica se o número está na lista */
int busca(lista L, int num, int *pos) {

  while ((L.total > 0) && ((*pos) < L.total)) {
    
      if (L.elementos[(*pos)] == num)
        return 1;    
      if (L.elementos[(*pos)] > num)
        return 0;
        
      (*pos)++; 
  }
  
  return 0;
}

/* Insere o número na lista ordenada */
void push(lista *L, int num) {

  int verificaBusca, pos = 0, ultimaPos;

  if (L->total < TAM) {

    verificaBusca = busca(*L, num, &pos);
    
    if (verificaBusca == 0) {
      
      ultimaPos = L->total;
      
      /* Passa pra trás os números posteriores a posição */
      for (int i = ultimaPos; i > pos; i--)
        L->elementos[i] = L->elementos[i-1];
        
      L->elementos[pos] = num;
      L->total = ultimaPos + 1;
      
    } else
      printf("Já está na lista!\n");
    
  } else
    printf("Lista cheia!\n");

}

/* Remove o número */
int pop(lista *L, int num) {

  int lixo, pos = 0, ultimaPos;
  int verificaBusca = busca(*L, num, &pos);
  
  if (verificaBusca == 1) {
    
    lixo = L->elementos[pos];
    ultimaPos = L->total - 1;
      
    /* Passa pra frente os número posteriores a posição*/
    for (int i = pos; i < ultimaPos; i++)
      L->elementos[i] = L->elementos[i+1];
    
    L->total = ultimaPos;
    
  } else {
    lixo = -1;
    printf("Não está na lista!\n");
  }
  
  return lixo;
}

/* Imprime a lista */
void imprime(lista L) {

  for (int i = 0; i < L.total; i++)
    printf("%d ", L.elementos[i]);
  
  printf("\n"); 
}

int main() {
  int vetor[10] = {0, 5, 4, 1, 20, 3, 2, 6, 15, 7}; /*pytutor não admite input*/
  
  lista L;
  L.total = 0;
  
  /* Preenchendo a lista */
  for (int i = 0; i < TAM; i++)
    push(&L, vetor[i]);
  
  imprime(L);
  
  /* Esvaziando a lista */
  printf("Sai %d\n", pop(&L, 4));
  imprime(L);
  
  printf("Sai %d\n", pop(&L, 7));
  imprime(L);
  
  /* Preenchendo parcialmente a lista*/
  push(&L, 13);
  imprime(L);
  
  push(&L, 10);
  imprime(L);
  
  return 0;  
}
