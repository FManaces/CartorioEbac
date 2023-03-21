#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>//biblioteca de textopor regi�o
#include <string.h>//biblioteca de string

int main()
{
	int opcao=0; //definindo vari�veis
	
	int laco=1;
	for(laco=1;laco=1;)
	{
	
		
		system("cls");

		setlocale (LC_ALL, "Portuguese_Brazil.1252"); //DEFININDO LINGUAGEM.
	
	
		printf("Cart�rio de Registo EBAC\n\n");
		printf("Escolha a op��o desejada:\n");//MENU INICIO.
		printf("\t1 -Registrar Nomes\n");
		printf("\t2 -Consultar nomes\n");
		printf("\t3 -Deletar registro\n");
		printf("\t4 -Sair\n\n");
		printf("Op��o:");
	
	
		scanf("%d",&opcao);//inicio de sele��o
	
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
			printf(" Op��o Inv�lida!\n");
			system("pause");
			break;
    	}
   	}
}

int registro()//fun��o respons�vel por cadastrar novos usu�rios ao sistema
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

int consulta()//fun��o respons�vel por consultar usu�rio j� criados
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
		printf("CPF n�o encontrado no sistema!\n");
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\n Informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");

}

int deletar()//fun��o repons�vel por deletar usu�rio
{
	setlocale (LC_ALL, "Portuguese_Brazil.1252");
	
	char CPF[40];
		
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",CPF);
	
	remove(CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sitema. \n");
		system("pause");
	}
		
}

