#include <stdio.h>
#include <stdlib.h>

/* ESTRUTURA DA LISTA */
struct subNOH {
  int elemento;
  struct subNOH *proximo;
};

struct NOH {
  int elemento;
  struct subNOH *sublista;
  struct NOH *proximo;
};

typedef struct subNOH subLista;
typedef struct NOH lista;

/* BUSCA */
int busca(lista L, int numero, lista *familia) {
  
  while((L != NULL) && (L.elemento < numero))
    L = L->prox;
    
  if((L != NULL) && (L.elemento != num)) {
    (*familia) = L;
    return 1;
  }
  
  return 0;
}

int subBusca() {
  
}

/* INSERE */
void insere(lista *L, int numero) {
  
  lista *familia;
  if(busca(L, numero, &familia) == 1) {
    
    sublista *anterior, *temp;
    if(subBusca(familia, numero, &anterior) == 0){
      
      temp = (subLista*)malloc(sizeof(subLista));
      temp->elemento = numero;
      temp->prox = anterior->prox;
      anterior->prox = temp;
      
    } else
      printf("O número já está na sublista");
    
  } else
    printf("O elemento não será inserido, não existe familia %d0 em L", numero);
    
}

int main() {

  
  
  

  return 0;
}
