#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço de memória
#include <locale.h>//biblioteca de textopor região
#include <string.h>//biblioteca de string

int main()
{
	int opcao=0; //definindo variáveis
	
	int laco=1;
	for(laco=1;laco=1;)
	{
	
		
		system("cls");

		setlocale (LC_ALL, "Portuguese_Brazil.1252"); //DEFININDO LINGUAGEM.
	
	
		printf("Cartório de Registo EBAC\n\n");
		printf("Escolha a opção desejada:\n");//MENU INICIO.
		printf("\t1 -Registrar Nomes\n");
		printf("\t2 -Consultar nomes\n");
		printf("\t3 -Deletar registro\n");
		printf("\t4 -Sair\n\n");
		printf("Opção:");
	
	
		scanf("%d",&opcao);//inicio de seleção
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			case 2:	
			consulta();
			break;
			case 3:
			deletar();
			break;
			case 4:
			printf("Pbrigado por utilizar.");
			return 0;
			break;
			default:
			printf(" Opção Inválida!\n");
			system("pause");
			break;
    	}
   	}
}

int registro()//função responsável por cadastrar novos usuários ao sistema
{
	setlocale (LC_ALL, "Portuguese_Brazil.1252");
	
	
	char arquivo[40];
	char CPF[40];
	char Nome[10];
	char Sobrenome[40];
	char Cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s", CPF);
	
	strcpy(arquivo, CPF);//responsavel por copiar os valores das string
	
	FILE*file;//cria arquivo
	
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,CPF);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s",Nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s",Sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,Sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,"; Cargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:\n");
	scanf("%s",Cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,Cargo);
	fclose(file);
	
	system("pause");
}

int consulta()//função responsável por consultar usuário já criados
{
	setlocale (LC_ALL, "Portuguese_Brazil.1252");
	
	char CPF[40];
	char conteudo[200];
	
	printf("Digite o cpf a sesr consultado: ");
	scanf("%s",CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("CPF não encontrado no sistema!\n");
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\n Informações do usuário: ");
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");

}

int deletar()//função reponsável por deletar usuário
{
	setlocale (LC_ALL, "Portuguese_Brazil.1252");
	
	char CPF[40];
		
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no sitema. \n");
		system("pause");
	}
		
}

