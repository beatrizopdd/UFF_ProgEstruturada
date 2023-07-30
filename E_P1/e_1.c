#include <stdio.h>

struct tipoEmpresa {
  char cargo[40];
  float salario;
};
typedef struct tipoEmpresa Empregados;

int main() {
  
  int N;
  float M;
  
  printf("\nDigite a quantidade de empregados: ");
  scanf(" %d", &N);

  Empregados vetEmp[N];

  for (int i = 0; i < N; i++) {
    printf("\nDigite o cargo: ");
    scanf(" %s", vetEmp[i].cargo);
    
    printf("\nDigite o salario: ");
    scanf(" %f", &vetEmp[i].salario);

    M += vetEmp[i].salario;
  }
  
  M /= N;
  
  printf("\nA media é %.2f", M);
  for (int i = 0; i < N; i++) {
    if (vetEmp[i].salario > M)
      printf("\nO cargo %s recebe mais que a media.", vetEmp[i].cargo);
  }

  return 0;
}

