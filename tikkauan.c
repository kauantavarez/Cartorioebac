#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca banco de dados

int registro()
{
	//abrindo strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fechando strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando irforma��es
	scanf("%s" , cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salva o valor da v�riavel
	fclose(file); // fecha a v�riavel
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" , cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
    system("pause");
}

int consultar()
{
    setlocale(LC_ALL, "Portuguese");
    
    //abrindo strings
    char cpf[40];
    char conteudo[200];
    //fechando v�riavel
    
    printf("Digite o CPF a ser consultado: "); //coletando irforma��es
    scanf("%s" ,cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); //resposta ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s" , conteudo);
		printf("\n\n");
	}
	
	system("pause"); // deixando a p�gina aberta ao leitor
}

int deletar()
{
	//abrindo string
    char cpf[40];
   //fechando string
   
    printf("Digite o CPF do usu�rio a ser deletado: "); //coletando irforma��es
    scanf("%s",cpf);
   
    remove(cpf); //deletar
   
    FILE *file;
    file = fopen(cpf, "r");
   
    if(file == NULL); //comparar irforma��es
    {
    	printf("O usu�rio n�o foi encontrado no sistema!\n "); //resposta caso n�o tenha usu�rio registrado
    	system("pause");
    }
}

int main()
{ 
    int opcao=0; //defini��o de v�riaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {


	 system("cls");
	 
     setlocale(LC_ALL, "Portuguese");  //defini��o de lingugem
    
     printf("### Cart�rio da EBAC ###\n\n"); //inicio menu
     printf("Escolha a Op��o desejada no menu:\n\n");
     printf("\t1 - Registrar nomes\n");
     printf("\t2 - Consultar nomes\n");
     printf("\t3 - Deletar nomes\n");
     printf("Op��o: "); //fim do menu
      
     scanf("%d" , &opcao); //armazenando escolha do usu�rio   
     
     system("cls");
    
     switch(opcao)
       {
      	  case 1:
    	  registro(); //puxa fun��o
          break;
		
		  case 2:
		  consultar();
		  break;
		
		  case 3:
		  deletar();
		  break;
		
	  	  default:
		  printf("Est� op��o n�o est� d�sponivel!\n");
		  system("pause");
		  break;
		
	
       }
    }
}
   
