#include <stdio.h>
#include <stdlib.h>

struct NOH {
  int elemento;
  struct NOH *proximo;
};
typedef struct NOH tnoh;

int busca(int elem, tnoh *L) {
  
  while (L != NULL) {
    if (L->elemento == elem)
      return 1;
    L = L->proximo;
  }
  
  return 0;
}

tnoh *insere(int elem, tnoh *L) {

  if (busca(elem, L)) 
    printf("\nJá está na lista");
    
  else {
    /* cria um nó, preenche o elemento e transforma ele no primeiro nó fazendo apontar pro resto da lista */
    tnoh *novoNoh = (tnoh*)malloc(sizeof(tnoh)); 
    novoNoh->elemento = elem;
    novoNoh->proximo = L;
    L = novoNoh;
  }
  
  return L;
}

void imprime(tnoh *L) {

  printf("\n[ ");
  
  while (L != NULL) {
    printf("%d ", L->elemento);
    L = L->proximo;
  }
  
  printf("]");
}

void intersecao(tnoh *L1, tnoh *L2) {

  printf("\n[ ");
  
  while (L1 != NULL) {
    /* se o elemento da lista 1 esiver na lista 2 */
    if (busca(L1->elemento, L2))
      printf("%d ", L1->elemento);
    L1 = L1->proximo;
  }
  
  printf("]");
}

void uniao(tnoh *L1, tnoh *L2) {

  printf("\n[ ");
  
  while (L1 != NULL) {
    printf("%d ", L1->elemento);
    L1 = L1->proximo;
  }
  
  while (L2 != NULL) {
    /* se não estiver n alista 1, ou seja, não tiver sido impresso */
    if (busca(L2->elemento, L1) == 0)
      printf("%d ", L2->elemento);
    L2 = L2->proximo;
  }
  
  printf("]");
}

int main() {
  tnoh *lista1, *lista2;
  lista1 = NULL;
  lista2 = NULL;
  
  /* escolhendo esses números pois o pytutor não tem input*/
  int num = 5;
  printf("Lista 1");
  while (num < 10){
    num += 1;
    lista1 = insere(num, lista1);
  }
  
  imprime(lista1);

  num = 4;
  printf("Lista 2");
  while (num < 10){
    num += 2;
    lista2 = insere(num, lista2);
  }
  
  imprime(lista2);

  printf("\nIntersecao de L1 com L2");
  intersecao(lista1, lista2);

  printf("\nUniao de L1 com L2");
  uniao(lista1, lista2);
  
  return 0;
}
