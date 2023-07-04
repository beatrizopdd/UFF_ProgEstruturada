#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMP 4

typedef char nome[10];

struct NOH {
    nome pessoa;
    int amigos;
    struct NOH *prox;
};

typedef struct NOH empresa;

empresa *cria_lista(nome *vetP, int matR[EMP][EMP]) {

  empresa *C, *U, *N;
  int qtd;
  
  C = (empresa*)malloc(sizeof(empresa));
  C->prox = NULL;
  U = C;
  
  for(int i = 0; i < EMP; i++) {
    qtd = 0;
    for(int j = 0; j < EMP; j++) {
      if(matR[i][j] == 1)
        qtd++;
    }
    N = (empresa*)malloc(sizeof(empresa));
    strcpy(N->pessoa, vetP[i]);
    N->amigos = qtd;
    N->prox = NULL;
    U->prox = N;
    U = N;
    
  }
  return C;  
}

int main() {

  nome vetPessoas[EMP] = {{'A','n','a'}, {'J','o','a','o'}, {'L','i','a'}, {'J','o','s','e'}};
  int matRelacoes[EMP][EMP] = {{0,1,1,0},{1,0,0,1},{1,0,0,1},{0,1,0,0}};
  
  empresa *E = (empresa*)malloc(sizeof(empresa)), *temp;
  E->prox = NULL;
  
  /* Preenche o vetPessoas com os nomes
  for(int i = 0; i < EMP; i++) {
    printf("Digite um nome: ");
    scanf("%s ", vetPessoas[i]);
  } 
  */
  
  /* Preenche o vetRelacoes com as amizades
  for(int i = 0; i < EMP; i++) {
    printf("Amizades de %s: ", vetPessoas[i]);
    for(int j = i+1; j < EMP; j++) {
      scanf("%d ", matRelacoes[i][j]);
    }
  } 
  */
  
  E = cria_lista(vetPessoas, matRelacoes);

  printf("\nRELACOES\n");
  temp = E->prox;
  while (temp != NULL) {
    printf("%s (%d)\n", temp->pessoa, temp->amigos);
    temp = temp->prox;
  }

  return 0;
}
