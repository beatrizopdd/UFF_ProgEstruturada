#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cria uma estrtura com esses atributos
struct felino {
    char sexo;
    int idade;
    char nome[50];
    char cor[50];
};
// da um apelido para a estrtura pra facilitar chamar, caso contrário você ficaria chamando como struct felino
typedef struct felino Gato;

// já cria com o apelido definido
typedef struct canino {
    char sexo;
    int idade;
    char nome[50];
} Cachorro;

int main() {

    // acesso os atributos do tipo Gato com '.' pois não é um ponteiro
    Gato garfield;
    strcpy(garfield.nome, "Garfield"); // C não faz atribuição direta de String
    strcpy(garfield.cor, "Amarelo");
    garfield.idade = 18;
    garfield.sexo = 'M';

    Gato marie;
    strcpy(marie.nome, "Marie");
    strcpy(marie.cor, "Branco");
    marie.idade = 18;
    marie.sexo = 'F';

    // vetor com ponteiros os espaços de memória que guardam os gatos
    Gato* feiraDeAdocao[2] = {&garfield, &marie};

    for (int i = 0; i < 2; i++) {
        Gato* opcao = feiraDeAdocao[i];
        printf("\n%s\n", opcao->nome); // para acessar os atributos de um ponteiro usamos '->'
        printf("sexo: %c\n", opcao->sexo);
        printf("idade: %d\n", opcao->idade);
        printf("cor: %s\n", opcao->cor);
    }

    Cachorro caozinho;
    strcpy(caozinho.nome, feiraDeAdocao[0]->nome);
    caozinho.sexo = feiraDeAdocao[0]->sexo;
    caozinho.idade = feiraDeAdocao[0]->idade;

    printf("\n%s\n", caozinho.nome);
    printf("sexo: %c\n", caozinho.sexo);
    printf("idade: %d\n", caozinho.idade);
    return 0;
}
