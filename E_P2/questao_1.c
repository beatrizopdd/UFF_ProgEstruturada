#include <stdio.h>
#include <stdlib.h>

/* 1 - a */
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

/*  busca, insere e imprime */
int busca(int elem, lista *L, lista **preNOH) {
  
  L = L->prox;
  (*preNOH) = L;
  
  while ((L != NULL)) {
    
    if (elem == L->elemento)
      return 1;
      
    else if ((elem > L->elemento) && (elem < L->elemento+10))
      if (SUBbusca(elem, L->sublista) == 0) {
        (*preNOH) = L;
        return 0;
        
      } else 
        return 1;
    
    L = L->proximo;  
  }
  
  return 0;
}

/*  busca, insere e imprime */
int SUBbusca(int elem, lista *cabeca) {
  
  (*preNOH) = cabeca;
  while (cabeca != NULL) {
    if ((elem >= cabeca->elemento) && (elem < cabeca->elemento+10))
      
  }
  
  return 0;
}

int main() {

  lista *cabeca = (lista*) malloc(sizeof(lista));
  cabeca->sublista = NULL;
  cabeca->proximo = NULL;
  
  /* fazer o while pra preencher */
  
  

  return 0;
}