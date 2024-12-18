#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do us�ario
	scanf("%s", cpf); //refere-se a string/ salvar na string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); // Salva o valor da variavel (Escreve o CPF no arquivo)
	fclose(file); //Fecha o arquivo
	   
    file = fopen(arquivo, "a"); //Abre o arquivo em modo de adi��o (�a�)
    fprintf(file,","); //Adiciona o nome ao arquivo, precedido por uma v�rgula
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
		   
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo com o nome do CPF para leitura
	
	if(file == NULL) // Verifica se o arquivo foi aberto corretamente. Se n�o, exibe uma mensagem de erro
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Verifica se o arquivo foi aberto corretamente. Se n�o, exibe uma mensagem de erro
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
    	
	}
    
    
    
}

int indisponivel()
{
    printf("Essa op��o n�o est� disponivel!\n");
    system("pause");	
}



int main() //Fun��o principal //Ponto de entrada do programa
    {
	int opcao=0; //Definindo as vari�ves 
	int laco=1; //Declara��o e inicializa��o da vari�vel "laco"
	
	for(laco=1;laco=1;) //Loop infinito, pois a condi��o laco=1 � sempre verdadeira
	
	{
	
	    system("cls"); //Limpa e finaliza o programa caso n�o tenha mais op��es 
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da Ebac ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n"); //printf: Exibe o menu de op��es para o usu�rio
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("op��o: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
   	    system("cls"); //Limpa e finaliza o programa caso n�o tenha mais op��es 
   	    
   	    
   	    switch(opcao) //Avalia a vari�vel "opcao" e executa o bloco de c�digo correspondente // Inicio da sele��o
   	    {
   	    	case 1:
   	    	registro(); //Chamada de fun��es
			break; //Exibe uma mensagem de erro se a op��o n�o for v�lida
			
			case 2:
			consulta();
			break;
			
			case 3:	
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0; 
			break;	
	    	
	    	default:
	    	indisponivel();
	    	break;
	    } //Fim da sele��o
   	    	
    }		
       
}
	
	
	

