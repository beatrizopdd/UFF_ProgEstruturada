#include <stdio.h>

// (tipo do que a função retorna) nome(parametros)
void deTrasPraFrente(char vetor[], int inicio, int tamanho) {
    // enquanto o começo for menor que o tamanho
    // chama pro proximo
    // o proximo executa
    // volta pro que chamou
    // executa o que chamou
    if (inicio < tamanho) {
        deTrasPraFrente(vetor, inicio+1, tamanho);
        printf("%c\n", vetor[inicio]);
    }
}

void deFrentePraTras(char vetor[], int inicio, int tamanho) {
    if (inicio < tamanho) {
        printf("%c\n", vetor[inicio]);
        deFrentePraTras(vetor, inicio+1, tamanho);
    }
}

int soma(int vetor[], int inicio, int tamanho) {
    if (inicio < tamanho) {
        return (vetor[inicio] + soma(vetor, inicio+1, tamanho));
    } else
        return 0;
}

int main() {

    char vogais[5] = {'u', 'o', 'i', 'e', 'a'};
    deTrasPraFrente(vogais, 0, 5);
    printf("\n");
    deFrentePraTras(vogais, 0, 5);

    int numeros[6] = {1, 2, 1, 0, 1, 3};
    int resultado = soma(numeros, 0, 6);
    printf("\nSoma = %d\n",resultado);

    return 0;
}