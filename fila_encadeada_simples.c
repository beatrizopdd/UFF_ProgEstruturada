#include <stdio.h>
#include <stdlib.h>

struct NOH {
  int elemento;
  struct NOH *prox;
};
typedef struct NOH fila;

/* Insere o número no fim da fila */
void push(fila *F, int num) {
  
    fila *nohNovo, *final;
  
    final = F;
    
    while (final->prox != NULL)
        final = final->prox;
    
    nohNovo = (fila*)malloc(sizeof(fila));
    nohNovo->elemento = num;
    nohNovo->prox = NULL;
    
    final->prox = nohNovo;
    
}

/* Remove o número do inicio da fila */
int pop(fila *Cabeca) {
  
    int lixo = -1;
    fila *deletado, *novoProx;
    
    deletado = Cabeca->prox;
    
    if (deletado != NULL) {
    
        novoProx = deletado->prox;
        Cabeca->prox = novoProx;
    
        lixo = deletado->elemento;
        free(deletado);
    }
  
    return lixo;
}

/* Imprime a fila */
void print(fila *F) {
  
    printf("\n");
    while (F != NULL) {
        printf("%d ", F->elemento);
        F = F->prox;
    }
     
}

int main() {
    int vetor[5] = {0, 1, 2, 3, 4}; /*pytutor não admite input*/

    fila *F = (fila*)malloc(sizeof(fila));
    F->prox = NULL;
  
    /* Preenchendo a fila */
    for (int i = 0; i < 5; i++)
        push(F, vetor[i]);
    
    print(F->prox);
    
    /* Esvaziando a fila */
    printf("\nSai %d", pop(F));
    printf("\nSai %d", pop(F));
    
    print(F->prox);
      
    /* Preenchendo parcialmente a fila*/
    push(F, 5);
    push(F, 7);
    
    print(F->prox);
      
    return 0;  
}
