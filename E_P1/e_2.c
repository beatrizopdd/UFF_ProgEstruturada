#include <stdio.h>

struct DMA {
  int dia, mes, ano;
};
typedef struct DMA data;

int comparaAno(data d1, data d2) {

  int anos = d2.ano - d1.ano;
  
  /* Exemplo da primeira restrição: 01/12/2010 e 01/11/2020 == 9 anos
                                    01/02/2010 e 01/01/2011 == 11 meses */
  /* Exemplo da segunda restrição: 30/10/2010 e 25/10/2011 ==  11 meses e 25 dias*/
  if ((d2.mes < d1.mes) || (d2.mes == d1.mes && d2.dia < d1.dia))
    anos--;

  return anos;
}

int main() {

  data d1, d2;

  printf("Digite a primeira data: ");
  scanf(" %d/%d/%d", &d1.dia, &d1.mes, &d1.ano);
  
  printf("Digite a segunda data: ");
  scanf(" %d/%d/%d", &d2.dia, &d2.mes, &d2.ano);

  printf("Passaram %d anos completos", comparaAno(d1, d2));
  
  return 0;
}
