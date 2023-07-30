#include <stdio.h>
#define MAX 10

struct LISTA {
  int elemento[MAX];
  int total;
};
typedef struct LISTA tLista;

int menu() {

  int opcao;
  
  do {
    printf("\nDigite uma opção \n(1) Inserir elemento \n(2) Remover elemento \n(3) Mostrar lista \n(4) Finalizar programa \n");
    scanf(" %d", &opcao);
  } while (opcao < 1 || opcao > 4);
  
  return opcao;
}

int busca(tLista *lista, int elemento, int *posicao) {

  int i = 0;
  
  /* indice menor que o tamanho da lista E elemento menor que o conteúdo atual */
  while (i < lista->total && elemento > lista->elemento[i])
    i++;
  
  *posicao = i;

  /* chegou no final == não encontrou */
  if (lista->total == i)
    return 0;
  
  /* não chegou no final */
  else
    /* o elemento dessa posição é o que eu busco == encontrou*/
    if (elemento == lista->elemento[i])
      return 1;
      
    else
      return 0;
}

void insereL(tLista *lista, int elemento) {
  int P;

  if (busca(lista, elemento, &P) == 1)
    printf("\nEstá na lista na ṕosição %d!", P);
  
  else {
    /* passando todos os elementos pós P para a próxima posição */
    for (int i = lista->total; i > P; i--)
      lista->elemento[i] = lista->elemento[i-1];
    
    lista->elemento[P] = elemento;
    lista->total++;
  }
  
}

void removeL(tLista *lista, int elemento) {
  int P;
  
  if (busca(lista, elemento, &P) == 1) {
    /* passa todos os elementos pós P para frente */
    for (int i = P; i < lista->total - 1; i++)
      lista->elemento[i] = lista->elemento[i+1];
    
    lista->total--;
    
  } else 
    printf("\nNão está na lista!");
  
}


int main() {
  
  tLista lista;
  lista.total = 4;
  int operacao, elem = 0;

  lista.elemento[0] = 4;
  lista.elemento[1] = 6;
  lista.elemento[2] = 52;
  lista.elemento[3] = 200;

  /*operacao = menu();*/

  /*printf("\nDigite um numero para inserir: ");
  scanf(" %d", &elem);*/
  elem = 5;
  insereL(&lista, elem);
      
  /*printf("\nDigite um numero para remover: ");
  scanf(" %d", &elem);*/
  elem = 200;
  removeL(&lista, elem);
    
  printf("[ ");
  for (int i = 0; i < lista.total; i++) {
    printf("%d ", lista.elemento[i]);
  }
  printf("]\n");
  
  /*printf("\nDigite um numero para inserir: ");
  scanf(" %d", &elem);*/
  elem = 52;
  insereL(&lista, elem);
      
  /*printf("\nDigite um numero para remover: ");
  scanf(" %d", &elem);*/
  elem = 13;
  removeL(&lista, elem);   
  
  printf("\nFIM DO PROGRAMA!");
  
  return 0;
}
