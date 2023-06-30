#include <stdio.h>

struct DMA {
  int dia, mes, ano;
};
typedef struct DMA data;

int comparaAno(data d1, data d2) {

  int anos = d2.ano - d1.ano;
  if ((d2.mes < d1.mes) || (d2.mes == d1.mes && d2.dia < d1.dia))
    anos--;

  return anos;
}

int e_2() {
  data d1, d2;

  printf("Digite a primeira data: ");
  scanf(" %d/%d/%d", &d1.dia, &d1.mes, &d1.ano);
  printf("Digite a segunda data: ");
  scanf(" %d/%d/%d", &d2.dia, &d2.mes, &d2.ano);

  printf("Passaram %d anos completos", comparaAno(d1, d2));
}