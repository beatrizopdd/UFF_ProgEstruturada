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


int busca(lista *L, int numero, lista **anterior) {
  
  lista *auxL = L->proximo; 
  /* SALVA A POSIÇÃO ANTERIOR A QUE O ALVO DEVE ENTRAR */
  (*anterior) = L; 
  
  /* A POSIÇÃO NÃO ESTIVER VAZIA E O ELEMENTO DELA FOR MENOR QUE O ALVO*/
  while ((auxL != NULL) && (auxL->elemento < numero)) { 
    (*anterior) = auxL;
    auxL = auxL->proximo;
  }
  
  if ((auxL != NULL) && (auxL->elemento == numero)) { 
    return 1;
  }
  
  return 0;
}

int subBusca(subLista *S, int numero, subLista **anterior) {
  
  subLista *auxS;
  auxS = S;
  /* SALVA A POSIÇÃO ANTERIOR A QUE O NÚMERO DEVE ENTRAR */
  (*anterior) = NULL; 
  
  /* A POSIÇÃO NÃO ESTIVER VAZIA E O ELEMENTO DELA FOR MENOR QUE O ALVO*/
  while((auxS != NULL) && (auxS->elemento < numero)) { 
    (*anterior) = auxS;
    auxS = auxS->proximo;
  }
  
  if((auxS != NULL) && (auxS->elemento == numero)) {
    return 1;
  }
  
  return 0;
}

/* INSERE */
void insereLista(lista *L, int numero) {
  
  lista *anterior, *nohNovo;
  
  if(busca(L, numero, &anterior) == 0) {
  
    nohNovo = (lista*)malloc(sizeof(lista));
    
    nohNovo->elemento = numero;
    nohNovo->sublista = NULL;
    nohNovo->proximo  = anterior->proximo;
    
    anterior->proximo = nohNovo;
  
  } else
    printf("\nEstá na lista");
  
}

void insereSubLista(lista *L, int numero) {
  
  int dezena = (numero /10) * 10;
  lista *familia;
  subLista *anterior, *nohNovo, *subL;
  
  if (busca(L, dezena, &familia) == 1) {
    
    /* VAI TE DAR A ANTERIOR A DEZENA ENTÃO VOCÊ AVANÇA */
    familia = familia->proximo;
    /* ENTRA NA SUBLISTA DA POSIÇÃO */ 
    subL = familia->sublista; 
    
    /* SE NÃO ESTIVER NA SUBLISTA */
    if (subBusca(subL, numero, &anterior) == 0) { 
    
      nohNovo = (subLista*)malloc(sizeof(subLista));
      nohNovo->elemento = numero;
      
      /* SE NÃO TIVER UM ELEMENTO ANTES DELE */
      if(anterior == NULL) { 
        nohNovo->proximo = NULL;
        familia->sublista = nohNovo;
        
      } else {
        nohNovo->proximo = anterior->proximo;
        anterior->proximo = nohNovo;
      }
      
    } else
        printf("\nEstá na sublista");
    
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

  lista *L = (lista*)malloc(sizeof(lista));
  L->proximo = NULL;
  L->sublista = NULL;
  
  int list[5] = {10,20,100,130};
  int subs[8] = {11,14,19,23,29,101,107,132};
  
  /* Preenchendo a lista principal */
  for(int i = 0; i < 4; i++) 
    insereLista(L, list[i]);
  /* Preenchendo as sublistas */
  for(int j = 0; j < 8; j++) 
    insereSubLista(L, subs[j]);
    
  /*
  int list[4] = {10,20,100,130};
  int subs[4] = {19, 23, 101, 132};
  
  /* Preenchendo a lista principal 
  for(int i = 0; i < 4; i++) {
    insereLista(L, list[i]);
    /* Preenchendo as sublistas 
    insereSubLista(L, subs[i]);
  }
  */
  
  imprime(L->proximo);
  
  return 0;
}
