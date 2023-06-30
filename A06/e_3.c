#include <stdio.h>
#define N 4

void imprime(int matriz_amizade[N][N]) {
  for (int i = 0; i < N; i++) {
    printf("[");
    for (int j = 0; j < N; j++) {
      printf(" %d", matriz_amizade[i][j]);
    }
    printf("]\n");
  }
}

void preenche(int matriz_amizade[N][N]) {
  for (int i = 0; i < N; i++) {
    printf("\nLinha %d\n", i);
    for (int j = 0; j < N; j++) {
      printf("Digite a relaçao: ");
      scanf(" %d", &matriz_amizade[i][j]);
    }
  }
}

int compara(int matriz_amizade[N][N]) {
  int inconsistecia = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (matriz_amizade[i][j] != matriz_amizade[j][i])
        inconsistecia += 1;
    }
  }
  return inconsistecia;
}

int main() {
  int amizade[N][N], inconsistecia;
  preenche(amizade);
  inconsistecia = compara(amizade);
  imprime(amizade);
  printf("Possui %d inconsistencia", inconsistecia);
  return 0;
}
