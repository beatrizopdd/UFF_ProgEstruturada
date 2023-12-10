#include <stdio.h>
#define TAM 6

struct Fila {
  int elementos[TAM];
  int i, f, t;
};

typedef struct Fila fila;

/* Insere no fim da fila */
void push(fila *F, int num) {

  if (F->t < TAM) {
      
    F->elementos[F->f] = num;  
    F->f = (F->f + 1) % TAM; /* exemplo: TAM=4  F->f=4  novo_F->f=0*/
    F->t += 1;  
    
  } else
    printf("Fila cheia!\n");
    
}

/* Remove do inicio da fila e retorna o número */
int pop(fila *F) {
  
  int num;
  if (F->t > 0) {
       
    num = F->elementos[F->i];  
    F->i = (F->i + 1) % TAM; /* exemplo: TAM=4  F->i=4  novo_F->i=0*/
    F->t -= 1; 
    
  } else {
    num = -1;
    printf("Fila vazia!\n");
  }
  
  return num;
  
}

/* Imprime cada elemento do inicio até o fim da fila */
void print(fila F) {
  
  int indice = F.i;
  for (int i = 0; i < F.t; i++) {
  
    printf("%d ", F.elementos[indice]);
    
    /* Se a primeira parte da lista já chegou no final, vai pro começo (que é onde começa a segunda parte)*/
    if (indice == (TAM-1))
      indice = 0;
      
    else
      indice += 1;
  }
  
  printf("\n");
  
}

int main() {
  int vetor[8] = {6, 7, 1, 2, 3, 4, 5}; /*pytutor não admite input*/

  fila F;
  F.i = 0;
  F.f = 0;
  F.t = 0;
  
  /* Preenchendo parcialmente a fila*/
  for (int i = 2; i < 7; i++)
    push(&F, vetor[i]);
    
  print(F);
  
  /* Esvaziando parcialmente a fila */
  for (int j = 0; j < 3; j++) 
    printf("Sai %d\n", pop(&F));
  
  print(F);
  
  /* Preenchendo parcialmente a fila*/
  for (int k = 0; k < 5; k++)
    push(&F, vetor[k]);
    
  print(F);
  
  return 0;  
}
