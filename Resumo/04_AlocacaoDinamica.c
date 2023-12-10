#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("]");
}

void imprimeTurma(int linhas, int colunas, double **matriz) {
    for (int i = 0; i < linhas; i++) {
        printf("Aluno %d: [ ", i+1);
        for (int j = 0; j < colunas; j++)
            printf("%.2f ", matriz[i][j]);
        printf("]\n");
    }
}

int main() {

    // o vetor agora é um ponteiro pra espaços de memória que guardam um tipo
    int *vetor;
    int tamanho;

    printf("Quantos numeros? >>");
    scanf("%d", &tamanho);
    printf("Ok, %d numeros\n", tamanho);

    // typecast é converter forçadamente o tipo do dado
    // malloc retorna um void*
    // sizeof retorna o tamanho do tipo
    // nome-do-vetor = (typecast para o tipo do vetor) malloc(qtd-de-espaços * sizeof(tipo do elemento))
    vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
        vetor[i] = i*2;

    imprimeVetor(vetor, tamanho);

    /* APLICAÇÃO */
    double **turma;
    int alunos;
    int provas;

    printf("\nQuantos alunos? >>");
    scanf("%d", &alunos);
    printf("Ok, %d alunos\n", alunos);

    // exemplo 5 alunos ->> turma = {{}, {}, {}, {}, {}}
    turma = (double**) malloc(alunos * sizeof(double*));

    printf("Quantas provas? >>");
    scanf("%d", &provas);
    printf("Ok, %d provas\n", provas);

    for (int a = 0; a < alunos; a++) {
        printf("Aluno %d:", a+1);
        // exemplo 2 provas ->> turma[5] = {{X, X}, {X, X}, {X, X}, {X, X}, {X, X}}
        turma[a] = (double*) malloc(provas * sizeof(double));
        for (int p = 0; p < provas; p++) // se o for/while/if tiver apenas uma instrução pode tirar as {}
            scanf(" %lf", &turma[a][p]);
    }

    printf("\n");
    imprimeTurma(alunos, provas, turma);

    return 0;
}