#include <stdio.h>
#include <stdlib.h>

/* ESTRUTURA DA LISTA */
struct subNOH {
  int elemento;
  struct subNOH *proximo;
};
typedef struct subNOH subLista;

struct NOH {
  int elemento;
  subLista *sublista;
  struct NOH *proximo;
};
typedef struct NOH lista;

/* BUSCA */
int busca(lista *L, int numero, lista **anterior) {
  
  lista *auxL, *auxA;
  auxL = L->proximo; 
  auxA = L; /* SALVA A POSIÇÃO ANTERIOR A QUE O ALVO DEVE ENTRAR */
  
  while((auxL != NULL) && (auxL->elemento < numero)) { /* A POSIÇÃO NÃO ESTIVER VAZIA E O ELEMENTO DELA FOR MENOR QUE O ALVO*/
    auxA = auxL;
    auxL = auxL->proximo;
  }
  
  (*anterior) = auxA;
  
  if((auxL != NULL) && (auxL->elemento == numero)) { 
    printf("\nEstá na lista");
    return 1;
  }
  
  return 0;
}

int subBusca(subLista *S, int numero, subLista **anterior) {
  
  subLista *auxS, *auxA;
  auxS = S;
  auxA = NULL; /* SALVA A POSIÇÃO ANTERIOR A QUE O NÚMERO DEVE ENTRAR */
  
  while((auxS != NULL) && (auxS->elemento < numero)) { /* A POSIÇÃO NÃO ESTIVER VAZIA E O ELEMENTO DELA FOR MENOR QUE O ALVO*/
    auxA = auxS;
    auxS = auxS->proximo;
  }
  
  (*anterior) = auxA;
  
  if((auxS != NULL) && (auxS->elemento == numero)) {
    return 1;
  }
  
  return 0;
}

/* INSERE */
void insereLista(lista *L, int numero) {
  
  lista *anterior, *temp;
  
  if(busca(L, numero, &anterior) == 0) {
    temp = (lista*)malloc(sizeof(lista));
    temp->elemento = numero;
    temp->sublista = NULL;
    temp->proximo  = anterior->proximo;
    anterior->proximo = temp;
  }
  
}

void insereSubLista(lista *L, int numero) {
  
  lista *familia;
  subLista *anterior, *temp, *auxS;
  int dezena = (numero /10) * 10;
  
  if(busca(L, dezena, &familia) == 1) {
    
    familia = familia->proximo; /* VAI TE DAR A ANTERIOR A DEZENA ENTÃO VOCÊ AVANÇA */
    auxS = familia->sublista; /* ENTRA NA SUBLISTA DA POSIÇÃO */
    
    if(subBusca(auxS, numero, &anterior) == 0) { /* SE NÃO ESTIVER NA SUBLISTA */
      temp = (subLista*)malloc(sizeof(subLista));
      temp->elemento = numero;
      
      if(anterior == NULL) { /* SE NÃO TIVER UM ELEMENTO ANTES DELE */
        temp->proximo = NULL;
        familia->sublista = temp;
        
      } else {
        temp->proximo = anterior->proximo;
        anterior->proximo = temp;
      }
      
    }
    
  } else
    printf("\nA família não existe!");
  
}


/* IMPRIME */
void imprime(lista *L) {

  subLista *familia;
  while(L != NULL) {
    printf("\n%d -> ", L->elemento);
    
    familia = L->sublista;
    while(familia != NULL) {
      printf("%d ", (familia->elemento));
      familia = familia->proximo;
    }
    L = L->proximo;
    
  }
  
}

int main() {

  /*
  int list[5] = {10,20,100,130};
  int subs[4][3] = {{11,14,19}, {23,29}, {101,107,0}, {132,0,0}};
  */
  
  int list[4] = {10,20,100,130};
  int subs[4] = {19, 23, 101, 132};
  
  lista *L = (lista*)malloc(sizeof(lista));
  L->proximo = NULL;
  L->sublista = NULL;
  
  /* Preenchendo a lista principal */
  for(int i = 0; i < 4; i++) {
    insereLista(L, list[i]);
    /* Preenchendo as sublistas */
    insereSubLista(L, subs[i]);
  }
  
  imprime(L->proximo);
  
  return 0;
}
