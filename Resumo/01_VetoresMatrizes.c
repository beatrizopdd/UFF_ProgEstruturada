#include <stdio.h>

//pode ignorar esse trecho, coloquei como função pra não poluir a main
void imprimeVetor(char *vetor, int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++)
        printf("%c ", vetor[i]);
    printf("]");
}

//pode ignorar esse trecho
void imprimeMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        printf("[ ");
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);
        printf("]\n");
    }
}

//pode ignorar esse trecho
void imprimeTurma(int linhas, int colunas, double matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        printf("[ ");
        for (int j = 0; j < colunas; j++)
            printf("%.2f ", matriz[i][j]);
        printf("]\n");
    }
}

int main() {

    /*
        - não existe append em C
        - não existe size/len em C
        - por esses motivos você deve criar o vetor/a matriz de tamanho maior ou igual ao que você precisa
    */

    // (tipo dos elementos) nome[numero de elementos]
    char vetor[5];
    vetor[0] = 'a';
    vetor[1] = 'e';
    vetor[2] = 'i';
    vetor[3] = 'o';
    vetor[4] = 'u';

    printf("Vetor:\n");
    imprimeVetor(vetor, 5);

    // (tipo dos elementos) nome[numero de vetores][numero de elementos de cada vetor]
    int matriz[5][5];
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {
            matriz[l][c] = l + c + 1; // nome[indice da linha][indice da coluna]
        }
    }

    printf("\n\nMatriz:\n");
    imprimeMatriz(5, 5, matriz);

    /* APLICAÇÃO */
    double turma[3][2] = {{2.5, 9.5}, {9.3, 6.0}, {7.0, 8.0}};

    printf("\nNotas dos alunos: \n");
    imprimeTurma(3,2, turma);

    printf("\nMedia dos alunos:");
    for (int a = 0; a < 3; a++) {
        printf("\nAluno %d: ", a+1);
        double media = 0;
        for (int n = 0; n < 2; n++)
            media += turma[a][n];
        printf("%.2f", media/2);
    }

    return 0;
}