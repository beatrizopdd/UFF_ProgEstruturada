#include <stdio.h>

void imprimeConteudo(int a, int b, int c, int *p) {
    printf("\nCONTEUDO DE CADA VARIAVEL\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("ponteiro: %p\n", p);
}

void trocaSemPonteiro(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void trocaComPonteiro(int *a, int *b) {
    int temp = *a; // temp guarda o conteúdo do ponteiro pra a
    *a = *b; // o conteúdo do ponteiro pra a recebe o conteúdo do ponteiro pra b
    *b = temp; // o conteúdo do ponteiro pra b recebe temp
}

int main() {

    int a = -1;
    int b = -2;
    int c = -3;
    int *ponteiro;

    imprimeConteudo(a, b, c, ponteiro);

    printf("\n>> a recebe 5");
    a = 5;
    imprimeConteudo(a, b, c, ponteiro);

    printf("\n>> b recebe a \n>> ponteiro recebe endereco de a");
    b = a;
    ponteiro = &a;
    imprimeConteudo(a, b, c, ponteiro);

    printf("\n>> b recebe 7 \n>> conteudo de ponteiro recebe 9");
    b = 7;
    *ponteiro = 9;
    imprimeConteudo(a, b, c, ponteiro);

    printf("\n>> c recebe o conteudo do ponteiro + 1");
    c = *ponteiro + 1;
    imprimeConteudo(a, b, c, ponteiro);

    printf("\nRESULTADO \n");
    printf("ponteiro   | endereco: %p | conteudo: %p | conteudo do conteudo: %d\n", &ponteiro, ponteiro, *ponteiro);
    printf("a          | endereco: %p | conteudo: %d\n", &a, a);
    printf("b          | endereco: %p | conteudo: %d\n", &b, b);
    printf("c          | endereco: %p | conteudo: %d\n", &c, c);

    /* APLICACÃO */
    int menor = 50;
    int maior = 25;

    trocaSemPonteiro(menor, maior);
    printf("\nSEM PONTEIRO:\n menor = %d\n maior = %d", menor, maior);

    trocaComPonteiro(&menor, &maior); // o endereço da variável
    printf("\nCOM PONTEIRO:\n menor = %d\n maior = %d\n", menor, maior);

    return 0;
}