/* TA ERRADO EU SÓ NÃO TERMINEI */
#include <stdio.h>
#define TAM 10

struct Lista {
  int elementos[TAM];
  int total;
};
typedef struct Lista lista;

/* Busca binária (só funciona em lista ordenada) */
int busca(lista L, int num, int meio) {
  
  if (L.elementos[meio] == num)
    return meio;
    
  else if (L.elementos[meio] > num)
    busca(L, num, meio/2);
  
  else if (L.elementos[meio] < num)
    busca(L, num, ((meio + L.total)/2));
    
  return (-1);
}

/* Inserção ordenada */
void push(lista *L, int num) {
  
  int posicao;
  
  if (L->total < TAM) {
    posicao = busca(L, num, L.total/2);
    if (posicao == -1) {
    L->elementos[L->total] = num;
    L->total += 1;
  
  } else
    printf("Lista cheia!\n");
    
}


int main() {
  int vetor[10] = {0, 5, 4, 1, 20, 3, 2, 6, 15, 7}; /*pytutor não admite input*/

  lista L;
  L.total = 0;
  
  /* Preenchendo a lista */
  for (int i = 0; i < TAM; i++)
    push(&L, vetor[i]);
  
  return 0;  
}
