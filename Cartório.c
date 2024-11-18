#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usúario
	scanf("%s", cpf); //refere-se a string/ salvar na string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); // Salva o valor da variavel (Escreve o CPF no arquivo)
	fclose(file); //Fecha o arquivo
	   
    file = fopen(arquivo, "a"); //Abre o arquivo em modo de adição (“a”)
    fprintf(file,","); //Adiciona o nome ao arquivo, precedido por uma vírgula
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
	
	if(file == NULL) // Verifica se o arquivo foi aberto corretamente. Se não, exibe uma mensagem de erro
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Verifica se o arquivo foi aberto corretamente. Se não, exibe uma mensagem de erro
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
    	
	}
    
    
    
}

int indisponivel()
{
    printf("Essa opção não está disponivel!\n");
    system("pause");	
}



int main() //Função principal //Ponto de entrada do programa
    {
	int opcao=0; //Definindo as variáves 
	int laco=1; //Declaração e inicialização da variável "laco"
	
	for(laco=1;laco=1;) //Loop infinito, pois a condição laco=1 é sempre verdadeira
	
	{
	
	    system("cls"); //Limpa e finaliza o programa caso não tenha mais opções 
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da Ebac ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n"); //printf: Exibe o menu de opções para o usuário
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("opção: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
   	    system("cls"); //Limpa e finaliza o programa caso não tenha mais opções 
   	    
   	    
   	    switch(opcao) //Avalia a variável "opcao" e executa o bloco de código correspondente // Inicio da seleção
   	    {
   	    	case 1:
   	    	registro(); //Chamada de funções
			break; //Exibe uma mensagem de erro se a opção não for válida
			
			case 2:
			consulta();
			break;
			
			case 3:	
			deletar();
	    	break;
	    	
	    	default:
	    	indisponivel();
	    	break;
	    } //Fim da seleção
   	    	
    }		
       
}
	
	
	

