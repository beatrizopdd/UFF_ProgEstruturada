#include <stdio.h>
#define MAX 100

struct LISTA {
  int elemento[MAX];
  int total;
};

typedef struct LISTA tLista;

int menu() {
  int opcao;
  do {
    printf("Digite uma opção \n(1) Inserir elemento \n(2) Remover elemento \n(3) Mostrar lista \n(4) Finalizar programa \n");
    scanf(" %d", &opcao);
  } while (1 > opcao || 4 < opcao);
  
  return opcao;
}

int busca(tLista *lista, int elemento, int *posicao) {
  int i = 0;
  while (i < lista->total && elemento > lista->elemento[i])
    i++;
  *posicao = i;

  if (lista->total == i)
    return 1;
  else
    if (elemento == lista->elemento[i])
      return 0;
    else
      return 1;
}

void insereL(tLista *lista, int elemento) {
  int P;

  if (busca(lista, elemento, &P) == 0)
    printf("Está na lista na ṕosição %d!", P);
  
  else {
    for (int i = lista->total; i > P; i--)
      lista->elemento[i] = lista->elemento[i-1];
    
    lista->elemento[P] = elemento;
    lista->total++;
  }
}

void removeL(tLista *lista, int elemento) {
  int P;
  
  if (busca(lista, elemento, &P) == 0) {
    for (int i = P; i < lista->total - 1; i++)
      lista->elemento[i] = lista->elemento[i+1];
    
    lista->total--;
    
  } else 
    printf("Não está na lista!");
  
}


int main() {
  tLista lista;
  lista.total = 4;
  int oper, elem = 0;

  lista.elemento[0] = 4;
  lista.elemento[1] = 6;
  lista.elemento[2] = 52;
  lista.elemento[3] = 200;

  do {
    oper = menu();

    if (oper == 1) {
      do {
        insereL(&lista, elem);
        printf("Digite um numero para inserir: ");
        scanf(" %d", &elem);
      } while (elem >= 0);
    } else if (oper == 2) {
      
      printf("Digite um numero para remover: ");
      scanf(" %d", &elem);
      removeL(&lista, elem);
    
    } else if (oper == 3) {
      
      printf("[ ");
      for (int i = 0; i < lista.total; i++) {
        printf("%d ", lista.elemento[i]);
      }
      printf("]\n");
      
    }
    
  } while (oper != 4);
  printf("FIM DO PROGRAMA!");
  
  return 0;
}
