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

  empresa *cabeca, *final, *nohNovo;
  int qtd;
  
  cabeca = (empresa*)malloc(sizeof(empresa));
  cabeca->prox = NULL;
  final = cabeca;
  
  for(int i = 0; i < EMP; i++) {
  
    qtd = 0;
    for(int j = 0; j < EMP; j++) {
      if(matR[i][j] == 1)
        qtd++;
    }
    
    nohNovo = (empresa*)malloc(sizeof(empresa));
    
    strcpy(nohNovo->pessoa, vetP[i]);
    nohNovo->amigos = qtd;
    nohNovo->prox = NULL;
    
    final->prox = nohNovo;
    final = nohNovo;
    
  }
  
  return cabeca;  
}

int main() {

  nome vetPessoas[EMP] = {{'A','n','a'}, {'J','o','a','o'}, {'L','i','a'}, {'J','o','s','e'}};
  int matRelacoes[EMP][EMP] = {{0,1,1,0},{1,0,0,1},{1,0,0,1},{0,1,0,0}};
  
  empresa *E, *aux;
  
  /* Preenche o vetPessoas com os nomes e preenche o matRelacoes com as amizades
  for (int i = 0; i < EMP; i++) {
    printf("\nDigite um nome: ");
    scanf("%s ", vetPessoas[i]);
    
    printf("\nAmizades de %s: ", vetPessoas[i]);
    for (int j = 0; j < EMP; j++) {
      scanf("%d ", matRelacoes[i][j]);
  } */
  
  E = cria_lista(vetPessoas, matRelacoes);
  
  temp = E->prox;

  printf("\nRELACOES\n");
  while (temp != NULL) {
    printf("%s (%d)\n", temp->pessoa, temp->amigos);
    temp = temp->prox;
  }

  return 0;
}
