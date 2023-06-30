#include <stdio.h>
#include <stdlib.h>
#define jogadas 10

void imprime_jogadas(int *vetor) {
  printf("[");
  for (int i = 0; i < 13; i++) {
    printf(" %d", vetor[i]);
  }
  printf("]\n");
}

void preenche_jogadas(int *D) {
  int d1, d2, soma;
  for (int i = 0; i < jogadas; i++) {
    d1 = (rand() % 6) + 1;
    d2 = (rand() % 6) + 1;
    soma = d1 + d2;
    
    D[soma] += 1;
    printf("%d %d\n", d1, d2);
  }
}

void porcentagem(int *D) {
  int P;
  for (int i = 2; i < 13; i++) {
    P = (D[i] / jogadas) * 100;
    printf("O número %d aparece %d de 100", D[i], P);
  }
}

int main(){
  srand(time(NULL));
  
  int dados[13];
  for (int i = 0; i < 13; i++) 
    dados[i] = 0;
  
  preenche_jogadas(dados);
  imprime_jogadas(dados);
  porcentagem(dados);
  return 0;
}
