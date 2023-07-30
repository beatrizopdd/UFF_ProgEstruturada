#include <stdio.h>
#include <stdlib.h>

struct tipoEmpresa {
  char cargo[40];
  float salario;
};
typedef struct tipoEmpresa Empregados;

int main() {
  
  int N;
  float M;
  Empregados *vetEmp;
  
  printf("Digite a quantidade de empregados: ");
  scanf(" %d", &N);

  vetEmp = (Empregados*)malloc(N * sizeof(Empregados)) ;
  
  for (int i = 0; i < N; i++) {
    printf("Digite o cargo: ");
    scanf(" %s", vetEmp[i].cargo);
    
    printf("Digite o salario: ");
    scanf(" %f", &vetEmp[i].salario);

    M += vetEmp[i].salario;
  }
  
  M /= N;
  
  printf("A media é %.2f", M);
  for (int i = 0; i < N; i++) 
    if (vetEmp[i].salario > M)
      printf("O cargo %s recebe mais que a media.\n", vetEmp[i].cargo);

  return 0;
}
