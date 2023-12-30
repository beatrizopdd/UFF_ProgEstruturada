#include <stdio.h>
#include <stdlib.h>

typedef struct noh {
   int info; // o conteudo do nó pode ser literalmente qualquer coisa inclusive outra estrutura só de infos
   struct noh *prox; // seta pro próximo noh (isso é obrigatório)
} Lista;

void imprimeLista(Lista *lista) {
    Lista *auxiliar = lista;
    while (auxiliar != NULL) {
        printf("%d ", auxiliar->info);
        auxiliar = auxiliar->prox;
    }
}

Lista *criaNoh(int numero) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = numero;
    novo->prox = NULL;

    return novo;
}

Lista *insereNoFim(Lista *lista, int numero) {
    if (lista == NULL) // se a lista estiver vazia
        lista = criaNoh(numero);

    else { // caso contrário voce busca o final
        Lista *auxiliar = lista;
        while (auxiliar->prox != NULL) // enquanto o proximo elemento não for vazio, avança
            auxiliar = auxiliar->prox;
        // se saiu é pq o próximo noh do atual tem uma vaga
        auxiliar->prox = criaNoh(numero);
    }

    return lista; // se não retornar voce nunca vai ter uma lista
}

Lista *insereOrdenado(Lista *lista, int numero) {
    if (lista == NULL) // se a lista estiver vazia
        lista = criaNoh(numero);

    else { // caso contrário voce busca o final
        Lista *auxiliar = lista;
        /* IMPORTANTE
            o && e a posição das condições protegem o programa de dar erro
            se auxiliar->prox = null e o programa testar auxiliar->prox->info (NULL->info) isso da erro
            se o programa testa a primeira condição e ela é FALSA ele nem testa a próxima;
            Prova: basta uma condição falsa pra que tudo seja falso */
        while (auxiliar->prox != NULL && (auxiliar->prox)->info < numero)
            auxiliar = auxiliar->prox;

        Lista *novo = criaNoh(numero);

        // caso o primeiro elemento já seja maior
        if (numero < auxiliar->info) {
            novo->prox = auxiliar;
            lista = novo;
            /* [1] em [5]-null
               [1]-[5]-null
               lista = [1]-[5]-null
            */

        } else {
            novo->prox = auxiliar->prox;
            auxiliar->prox = novo;
            /* [4] em [3]-[5]-null
               auxiliar = [3]
               [4]-[5]-null
               [3]-[4]-[5]-null
            */
        }
    }
    return lista;
}

Lista *removeElemento(Lista *lista, int numero) {
    Lista *auxiliar = lista;

    // se for o primeiro elemento
    if (auxiliar != NULL && auxiliar->info == numero) {
        Lista *deletado = auxiliar;
        lista = auxiliar->prox;
        free(deletado); // tirando o noh da memoria

    } else {
        while (auxiliar != NULL && auxiliar->prox != NULL && auxiliar->prox->info != numero)
            auxiliar = auxiliar->prox;

        if (auxiliar == NULL || auxiliar->prox == NULL)
            printf("\n%d nao esta na lista!", numero);

        else {
            Lista *deletado = auxiliar->prox;
            auxiliar->prox = deletado->prox;
            free(deletado); // tirando o noh da memoria
        }

    }

    return lista;
}

int main() {

    int vetor[6] = {5, 2, 4, 1, 3, 6};
    Lista *listaNaoOrdenada = NULL;
    Lista *listaOrdenada = NULL;

    for (int i = 0; i < 6; i++) {
        listaNaoOrdenada = insereNoFim(listaNaoOrdenada, vetor[i]);
        listaOrdenada = insereOrdenado(listaOrdenada, vetor[i]);
    }

    printf("LISTAS ORIGINAIS");
    printf("\nLista nao ordenada\n");
    imprimeLista(listaNaoOrdenada);
    printf("\nLista ordenada\n");
    imprimeLista(listaOrdenada);

    printf("\n\nLISTAS SEM 1");
    listaNaoOrdenada = removeElemento(listaNaoOrdenada, 1);
    printf("\nLista nao ordenada\n");
    imprimeLista(listaNaoOrdenada);

    listaOrdenada = removeElemento(listaOrdenada, 1);
    printf("\nLista ordenada\n");
    imprimeLista(listaOrdenada);

    printf("\n\nLISTAS SEM 30");
    listaNaoOrdenada = removeElemento(listaNaoOrdenada, 30);
    printf("\nLista nao ordenada\n");
    imprimeLista(listaNaoOrdenada);

    listaOrdenada = removeElemento(listaOrdenada, 30);
    printf("\nLista ordenada\n");
    imprimeLista(listaOrdenada);

    return 0;
}