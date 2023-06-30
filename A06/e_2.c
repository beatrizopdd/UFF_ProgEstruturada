#include <stdlib.h>
#include <stdio.h>

int preenche_vetor(int *vet, int N) {
  for (int i = 0; i < N; i++) {
    printf("Digite um número: ");
    scanf("%d", &vet[i]);
  }
}

int num_diferentes(int *vet1, int *vet2, int N) {
  int diferentes = 0;
  for (int i = 0; i < N; i++) 
    if (vet1[i] != vet2[i]) 
      diferentes += 1;
  return diferentes;
}

int main(){
  
  int N, qtd, *vetor1, *vetor2;

  printf("Digite um N: ");
  scanf("%d", &N);
  
  vetor1 = (int*)malloc(N * sizeof(int));
  vetor2 = (int*)malloc(N * sizeof(int));

  preenche_vetor(vetor1, N);
  preenche_vetor(vetor2, N);

  qtd = num_diferentes(vetor1, vetor2, N);
  printf("Os vetores possuem %d numeros diferentes", qtd);
  
  return 0;
}
