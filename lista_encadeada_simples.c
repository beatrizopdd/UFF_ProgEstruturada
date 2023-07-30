#include <stdio.h>
#include <stdlib.h>

struct NOH {
  int elemento;
  struct NOH *prox;
};
typedef struct NOH lista;

/* Verifica se o número está na lista */
int busca(lista *L, int num, lista **anterior) {
    
    lista *nohAux = L->prox;
    /* Se estiver vazia, o nó anterior é o nó cabeça */
    (*anterior) = L;
    
    if (nohAux != NULL) {
      
      /* Enquanto não estiver no nó do número e não for o penúltimo nó */
      while ((nohAux->elemento != num) && (nohAux->prox != NULL)) {
          (*anterior) = nohAux;
          nohAux = nohAux->prox;
      }
      
      /* Se encontrou o nó do número, o nó anterior já está salvo */
      if (nohAux->elemento == num)
          return 1;
      
      /* Se não tem o número, então ele tem que ser inserido no final e o anterior é o último */ 
      (*anterior) = nohAux;
    }

    return 0;
}

/* Insere (de forma não ordenada) o número no fim da lista */
void push(lista *L, int num) {
  
    lista *nohNovo, *anterior;
  
    if (busca(L, num, &anterior) == 0) {
        
        nohNovo = (lista*)malloc(sizeof(lista));
        nohNovo->elemento = num;
        nohNovo->prox = NULL;
        
        anterior->prox = nohNovo;
        
    } else
        printf("\nJá está na lista!");
    
}

/* Remove o número */
int pop(lista *L, int num) {
  
    int lixo;
    lista *anterior, *deletado, *proximo;
  
    if (busca(L, num, &anterior) == 1) {
        
        deletado = anterior->prox;
        
        lixo = deletado->elemento;
        proximo = deletado->prox;
        
        anterior->prox = proximo;
        
        free(deletado);
        
    } else {
        lixo = -1;
        printf("\nNão está na lista!");
    }
  
    return lixo;
}

/* Imprime a lista */
void print(lista *L) {
  
    printf("\n");
    while (L != NULL) {
        printf("%d ", L->elemento);
        L = L->prox;
    }
     
}

int main() {
    int vetor[5] = {0, 5, 4, 1, 6}; /*pytutor não admite input*/

    lista *L = (lista*)malloc(sizeof(lista));
    L->prox = NULL;
  
    /* Preenchendo a lista */
    for (int i = 0; i < 5; i++)
        push(L, vetor[i]);
    
    print(L->prox);
    
    /* Esvaziando a lista */
    printf("\nSai %d", pop(L, 1));
    printf("\nSai %d", pop(L, 7));
    
    print(L->prox);
      
    /* Preenchendo parcialmente a lista*/
    push(L, 5);
    push(L, 10);
    
    print(L->prox);
      
    return 0;  
}
