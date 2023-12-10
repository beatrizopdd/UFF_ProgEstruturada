#include <stdio.h>
#include <stdlib.h>

struct NOH {
  int elemento;
  struct NOH *prox;
};
typedef struct NOH pilha;

/* Insere o número no topo da pilha */
void push(pilha *P, int num) {
  
    pilha *nohNovo, *final;
  
    final = P;
    
    while (final->prox != NULL)
        final = final->prox;
    
    nohNovo = (pilha*)malloc(sizeof(pilha));
    nohNovo->elemento = num;
    nohNovo->prox = NULL;
    
    final->prox = nohNovo;
    
}

/* Remove o número do final da pilha */
int pop(pilha *Cabeca) {
  
    int lixo = -1;
    pilha *deletado, *novoFinal;
    
    deletado = Cabeca->prox;
    
    if (deletado != NULL) {
    
        while (deletado->prox != NULL) {
            novoFinal = deletado;
            deletado = deletado->prox;
        }
        
        novoFinal->prox = NULL;
        lixo = deletado->elemento;
        free(deletado);
    }
  
    return lixo;
}

/* Imprime a pilha */
void print(pilha *P) {
  
    printf("\n---\n"); 
    while (P != NULL) {
        printf("%d \n", P->elemento);
        P = P->prox;
    }
    printf("---"); 
}

int main() {
    int vetor[5] = {0, 1, 2, 3, 4}; /*pytutor não admite input*/

    pilha *P = (pilha*)malloc(sizeof(pilha));
    P->prox = NULL;
  
    /* Preenchendo a pilha */
    for (int i = 0; i < 5; i++)
        push(P, vetor[i]);
    
    print(P->prox);
    
    /* Esvaziando a pilha */
    printf("\nSai %d", pop(P));
    printf("\nSai %d", pop(P));
    
    print(P->prox);
      
    /* Preenchendo parcialmente a pilha*/
    push(P, 5);
    push(P, 8);
    
    print(P->prox);
      
    return 0;  
}
