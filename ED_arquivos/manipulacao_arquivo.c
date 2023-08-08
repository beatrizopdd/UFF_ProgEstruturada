#include <stdio.h>
#include <string.h>


void imprimir_texto(FILE *texto) {

	char linha[200];
	
	/* %s pega a linha até o primeiro espaço em branco    */
	/* %[^\n] pega a linha até a primeira quebra de linha */
	
	while (fscanf(texto, "%[^\n]\n", linha) != -1)
		printf("%s\n", linha);
		
}

void escrever_texto(FILE *texto) {

	char goleiros[][100] = {"25 - Matheus Cunha", "1 - Santos", "17 - Rossi"};
	char zagueiros[][100] = {"3  Rodrigo Caio", "4 - Léo Pereira", "23 - David Luiz", "15 - Fabrício Bruno", "30 - Pablo"};
	char latDireitos[][100] = {"34 - Matheuzinho", "2 - Varela", "43 - Wesley"};
	char latEsquerdos[][100] = {"16 - Filipe Luís", "6 - Ayrton Lucas"};
	char volantes[][100] = {"8 - Thiago Maia", "5 - Erick", "20 - Gerson", "21 - Allan"};
	char meias[][100] = {"7 - Everton Ribeiro", "14 - De Arrascaeta", "29 - Victor Hugo", "42 - Matheus França"};
	char atacantes[][100] = {"10 - Gabi", "27 - Bruno Henrique", "9 - Pedro", "11 - Everton", "22 - Luiz Araújo"};

	fprintf(texto, "GOLEIROS\n");
	for (int i = 0; i < 3; i++)
		fprintf(texto, "%s\n", goleiros[i]);
	fprintf(texto, "------------------------\n");
	
	fprintf(texto, "ZAGUEIROS\n");
	for (int i = 0; i < 5; i++)
		fprintf(texto, "%s\n", zagueiros[i]);
	fprintf(texto, "------------------------\n");
	
	fprintf(texto, "LATERAIS DIREITOS\n");
	for (int i = 0; i < 3; i++)
		fprintf(texto, "%s\n", latDireitos[i]);
	fprintf(texto, "------------------------\n");
		
	fprintf(texto, "LATERAIS ESQUERDOS\n");
	for (int i = 0; i < 2; i++)
		fprintf(texto, "%s\n",latEsquerdos[i]);
	fprintf(texto, "------------------------\n");
	
	fprintf(texto, "VOLANTES\n");
	for (int i = 0; i < 4; i++)
		fprintf(texto, "%s\n", volantes[i]);
	fprintf(texto, "------------------------\n");
	
	fprintf(texto, "MEIAS\n");
	for (int i = 0; i < 4; i++)
		fprintf(texto, "%s\n", meias[i]);
	fprintf(texto, "------------------------\n");
	
	fprintf(texto, "ATACANTES\n");
	for (int i = 0; i < 5; i++)
		fprintf(texto, "%s\n", atacantes[i]);
	fprintf(texto, "------------------------\n");
	
}



void copiar_texto(FILE *texto) {

	FILE *flaflu = fopen("hino_FlaFlu.txt", "a+");
	char linha[100], original[100], resto[50];
	
	while (fscanf(texto, "%[^\n]\n", linha) != -1) {
		
		strcpy(original, linha);
		char *palavra = strtok(linha, " ");
		int tamanhoP = 0, tamanhoL = 0, tamanhoR = 0; 
		
		while (palavra != NULL) {
			
			tamanhoP = strlen(palavra) + 1;
			
			if ((strcmp(palavra, "Fluminense") == 0) || (strcmp(palavra, "Tricolor") == 0)) {
			
				tamanhoR = tamanhoL + tamanhoP - 1;
				strcpy(resto, original+tamanhoR);
								
				if (strcmp(palavra, "Fluminense") == 0) 
					strcpy(original+tamanhoL, "*FLAMENGO* ");
				
				if (strcmp(palavra, "Tricolor") == 0)
					strcpy(original+tamanhoL, "FLAMENGO ");
			
				strcpy(original+tamanhoR, resto);
			
			}
			
			palavra = strtok(palavra+tamanhoP, " ");
			tamanhoL += tamanhoP;
			
		}
		
		fprintf(flaflu, "%s\n", original);
		
	}
	
	fclose(flaflu);
	
}

void imprimir_texto_inverso(FILE *texto) {

	char linha[200];
	
	if ((fscanf(texto, "%[^\n]\n", linha) != -1))
		imprimir_texto_inverso(texto);
		printf("%s\n", linha);
}

int main() {

	/* "r" = modo de leitura; se o arquivo não existir ou der erro retorna NULL 
	   "r+" = modo atualização (grava e lê); se o arquivo não existir ou der erro retorna NULL
	   
	   "w" = modo de gravação; se o arquivo existir apaga tudo que tem nele
	   "w+" = modo atualização (grava e lê); se o arquivo existir apaga tudo que tem nele
	   
	   "a" = modo atualização (grava e lê); se o arquivo não existir ou der erro retorna NULL
	   "a+" = modo atualização (grava e lê); se o arquivo não existir ele cria
	*/
	
	FILE *botafogo = fopen("hino_botafogo.txt", "r");
	FILE *elenco = fopen("elenco_flamengo.txt", "w");
	FILE *fluminense = fopen("hino_fluminense.txt", "r");
	FILE *vasco = fopen("hino_vasco.txt", "r");
	FILE *flamengo = fopen("hino_flamengo.txt", "r");
	
	if (botafogo != NULL) 
		imprimir_texto(botafogo);
	else
		printf("ERRO AO ABRIR O ARQUIVO BOTAFOGO\n");
	
	
	if (elenco != NULL) {
		escrever_texto(elenco);
		imprimir_texto(elenco);
	} else
		printf("ERRO AO ABRIR O ARQUIVO ELENCO DO FLAMENGO\n");
		
		
	if (fluminense != NULL) 
		copiar_texto(fluminense);
	else
		printf("ERRO AO ABRIR O ARQUIVO FLUMINENSE\n");
	
	
	if (vasco != NULL) 
		imprimir_texto_inverso(vasco);
	else
		printf("ERRO AO ABRIR O ARQUIVO VASCO\n");	
		
		
	if (flamengo != NULL) 
		printf("Nunca vai acontecer\n");
	else
		printf("ERRO AO ABRIR O ARQUIVO FLAMENGO\n");	
		
		
	fclose(botafogo);
	fclose(elenco);
	fclose(vasco);
	fclose(fluminense);
		
	return 0;
}
