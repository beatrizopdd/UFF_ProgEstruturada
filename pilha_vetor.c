#include <stdio.h>
#define TAM 5

struct Pilha {
  int elementos[TAM];
  int altura;
};
typedef struct Pilha pilha;


/* Insere no topo da pilha */
void push(pilha *P, int num) {
  
  if (P->altura < (TAM-1)) {
    P->altura += 1;
    P->elementos[P->altura] = num;
    
  } else
    printf("Pilha cheia!\n");
    
}

/* Remove do topo da lista e retorna o número */
int pop(pilha *P) {
  
  int num; 
  if (P->altura > -1) {
    num = P->elementos[P->altura];
    P->altura -= 1;
    
  } else {
    num = -1;
    printf("Pilha vazia!\n");
  }
  
  return num; 
  
}

/* Imprime cada elemento de cima para baixo */
void print(pilha P) {
  
  for (int i = P.altura; i >= 0; i--)
    printf("%d\n", P.elementos[i]);
    
}

int main() {
  int vetor[8] = {0, 2, 5, 8, 12, 24, 42, 65}; /*pytutor não admite input*/
  
  pilha P;
  P.altura = -1;
  
  /* Preenchendo  a pilha (TAM+1 pra testar o aviso de limite da pilha)*/
  for (int i = 0; i < (TAM+1); i++)
    push(&P, vetor[i]);
  
  /* Imprimindo a pilha */
  print(P);
  
  /* Esvaziando a pilha */
  for (int i = 0; i < (TAM+1); i++)
    printf("Sai %d;\n", pop(&P));

  return 0;  
}
