#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
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
	
	printf("Digite o CPF a ser cadastrado: "); //coletando irformações
	scanf("%s" , cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salva o valor da váriavel
	fclose(file); // fecha a váriavel
	
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
    //fechando váriavel
    
    printf("Digite o CPF a ser consultado: "); //coletando irformações
    scanf("%s" ,cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Não foi possível abrir o arquivo, não localizado!\n"); //resposta ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s" , conteudo);
		printf("\n\n");
	}
	
	system("pause"); // deixando a página aberta ao leitor
}

int deletar()
{
	//abrindo string
    char cpf[40];
   //fechando string
   
    printf("Digite o CPF do usuário a ser deletado: "); //coletando irformações
    scanf("%s",cpf);
   
    remove(cpf); //deletar
   
    FILE *file;
    file = fopen(cpf, "r");
   
    if(file == NULL); //comparar irformações
    {
    	printf("O usuário não foi encontrado no sistema!\n "); //resposta caso não tenha usuário registrado
    	system("pause");
    }
}

int main()
{ 
    int opcao=0; //definição de váriaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {


	 system("cls");
	 
     setlocale(LC_ALL, "Portuguese");  //definição de lingugem
    
     printf("### Cartório da EBAC ###\n\n"); //inicio menu
     printf("Escolha a Opção desejada no menu:\n\n");
     printf("\t1 - Registrar nomes\n");
     printf("\t2 - Consultar nomes\n");
     printf("\t3 - Deletar nomes\n");
     printf("Opção: "); //fim do menu
      
     scanf("%d" , &opcao); //armazenando escolha do usuário   
     
     system("cls");
    
     switch(opcao)
       {
      	  case 1:
    	  registro(); //puxa função
          break;
		
		  case 2:
		  consultar();
		  break;
		
		  case 3:
		  deletar();
		  break;
		
	  	  default:
		  printf("Está opção não está dísponivel!\n");
		  system("pause");
		  break;
		
	
       }
    }
}
   
