/* Faça um programa que leia as idades dos nadadores de uma academia e informe a sua categoria.*/

char* categoria(int idade) {
  if (idade <= 4) 
    return "Baby";
  
  else if (idade <= 12) 
    return "Criança";
    
  else if (idade <= 30) 
    return "Jovem";
    
  else if (idade <= 60) 
    return "Adulto";
    
  else 
    return "Master";
}

int main() {

  int idade;
  char *turma;

  do {
    printf("\nDigite uma idade: ");
    scanf(" %d", &idade);

    if (idade >= 0) {
      turma = categoria(idade);
      printf("\nSua categoria é %s", turma);
    }
    
  } while (idade >= 0);

  return 0;
}
