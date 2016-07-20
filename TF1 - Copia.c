#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define NOME 100
#define CPF 12
#define TELEFONE 15



typedef struct 
{
	int teto;
	float valor;
	float valorBonificar;
	
	
} tBonus;

typedef struct 
{
	
	char cpf[CPF];
	float valorCompra;
	int compraCancelada;
	tBonus bonus;
	
} tCompra;

typedef struct 
{
	char nome[NOME];
	char cpf[CPF];
	char telefone[TELEFONE];
	int bonus;
	float totalCompras;
	tCompra ultimaCompra;
	
} tCliente;

/*PROTÓTIPO DAS FUNÇÕES*/

void inBonus(); //Função criada para inicialiar valores(Teto=1000, valor de 1 bonus=R$0.50, valor para bonificação=R$100,00)

//Funções -> MENU PRINCIPAL
int menuPrincipal(); //Função criada para imprimir na tela as opções do MENU PRINCIPAL

//Funções -> 1 - MENU CONFIGURAR BONUS
void menuConfiguraBonus();  //Função criada para imprimir na tela as opções do MENU CONFIGURAR BONUS
void alteraTeto(); //Função 1 - Alterar Teto
void alterarBonus(); //Função 2 - Alterar valor de 1 bonus
void alterarReceberBonus(); //Função 3 - Alterara valor para receber bonus

//Funções -> 2 - CADASTRAR CLIENTE
void cadastraCliente(); //Função criada para imprimir na tela as opções do MENU CADASTRAR CLIENTE

//Funções -> 3 - MENU ALTERAR CLIENTE
void menuAlteraCliente(); //Função criada para imprimir na tela as opções do MENU ALTERA CLIENTE
void alteraCadastroCliente(); //Função criada para verificar se o CPF já foi cadastrado
void alteraCadastroCPF(); //Função criada para alterar o CPF no cadastro do cliente
void alteraCadastroNome(); //Função criada para alterar o NOME no cadastro do cliente
void alteraCadastroTelefone(); //Função criada para alterar o TELEFONE no cadastro do cliente

int main()
{
	
	int opcao, controleC=0; 
	tBonus altera;
	tBonus *pAltera; //Ponteiro para funções (Alterar TETO, Alterar VALOR BONUS, Alterar VALOR RECEBER BONUS)
	
	pAltera = &altera;
	
	int *p1 = &controleC; //Ponteiro criado para controlar funções CADASTRO e ALTERAR clientes(É iniciado com o valor 0)
	tCliente vetCliente[MAX]; //Vetor de elementos do tipo tCliente

	inBonus(&altera); //Chamada da função inBonus(Valores padrões iniciados). Nesta função é passado o endereço da variavel "altera"
	
	
	
	
	
	do{
		opcao = menuPrincipal(pAltera, p1);
		
	switch(opcao)
	{
	case 1: menuConfiguraBonus(pAltera); break;
	case 2: cadastraCliente(vetCliente, p1); break;
	case 3: alteraCadastroCliente(vetCliente, p1); break;
	case 4: break;
	case 5: break;
	case 6: break;
	case 7: break;
	case 8: break;
	case 9: break;
	case 0:	break;							
		
	}	
		
		
	}while(opcao!=0);
	
	return 0;
}

void inBonus(tBonus *p){ //Definição para inicializar valores de campos da estrutura tBonus(Teto, valor, valorBonificar)
	//  "->" quando for usar ponteiro
	p->teto=1000;
	p->valor=0.50;
	p->valorBonificar=100.00;
}

int menuPrincipal(tBonus *p)
{
	printf("**************************************************************************\n");
	printf("Teto: %d | Valor de 1 bonus:  R$%.2f | Valor Bonificar: R$%.2f\n\n", p->teto,p->valor,p->valorBonificar);
	int opcao;
	
	printf("****************************##################****************************\n");
	printf("****************************# MENU PRINCIPAL #****************************\n");
	printf("****************************##################****************************\n\n");
	printf("01 - Configurar bonus\n");
	printf("02 - Cadastrar cliente\n");
	printf("03 - Alterar cadastro do cliente\n");
	printf("04 - Efetivar compra\n");
	printf("05 - Cancelar compra\n");
	printf("06 - Consultar bonus\n");
	printf("07 - Listar dados de todos os clientes\n");
	printf("08 - Listar bonus de todos os clientes\n");
	printf("09 - Listar os clientes que realizaram um valor total em compras\n");
	printf("inferior, superior ou igual a um valor.\n");
	printf("00 - Sair\n");
	printf("\nDigite uma opcao do menu:");
	scanf("%d", &opcao);
	
	while((opcao<0)||(opcao>9))
	{
		printf("Voce digitou uma opcao invalida. Digite novamente:");
		scanf("%d", &opcao);
	}
	
		
	system("cls");
	return opcao;
	
}

void menuConfiguraBonus(tBonus *pAltera)
{
	int opcao;
	
	
	printf("***************************####################***************************\n");
	printf("***************************# CONFIGURAR BONUS #****************************\n");
	printf("***************************####################***************************\n\n");
	printf("1 - Alterar teto\n");
	printf("2 - Alterar valor de um bonus\n");
	printf("3 - Alterar valor para receber bonus\n");
	printf("0 - Sair\n");
	printf("\nDigite uma opcao do menu:");
	scanf("%d", &opcao);
	
	while((opcao<0)||(opcao>3)){
		
		printf("Opcao digitada invalida. Digite novamente:");
		scanf("%d", &opcao);
	}
	
	switch(opcao){
		
	case 1: system("cls"); alteraTeto(pAltera); break;
	case 2: system("cls"); alterarBonus(pAltera);break;
	case 3: system("cls"); alterarReceberBonus(pAltera); break;
	case 0: system("cls"); menuPrincipal(pAltera); break;	
		
	}
	
  	

}

void alteraTeto(tBonus *p){ //A função recebe  do ponteiro(*p) os valores passados pela função chamadora

	printf("\n****************************ALTERAR TETO****************************\n");
	printf("Qual o novo valor do teto?\n");
	scanf("%d", &p->teto);
	
	while(p->teto<0){
	
	printf("Erro: valor negativo. Digite novamente:\n");
	scanf("%d", &p->teto);
}	

 	 system("cls");
	
}


void alterarBonus(tBonus *p){ //A função recebe  do ponteiro(*p) os valores passados pela função chamadora
	
	printf("\n****************************ALTERAR BONUS****************************\n");
	printf("Qual novo valor de um bonus?\n");
	scanf("%f", &p->valor);
	while(p->valor<0){
		printf("ERRO: valor negativo. Digite novamente:n");
	scanf("%f", &p->valor);
		
	}
	
	 system("cls");
	
}
void alterarReceberBonus(tBonus *p){ //A função recebe  do ponteiro(*p) os valores passados pela função chamadora
	
	printf("\n****************************ALTERAR RECEBER BONUS****************************\n");
	
	printf("Qual novo valor para receber bonus?\n");
	scanf("%f", &p->valorBonificar);
	while(p->valorBonificar<0){
		printf("ERRO: valor negativo. Digite novamente:\n");
	scanf("%f", &p->valorBonificar);
		
	}
	
	 system("cls");
}

void cadastraCliente(tCliente vetCliente[MAX], int *p){ 
	
	int i, flag;
	
	printf("****************************######################****************************\n");
	printf("****************************# CADASTRAR CLIENTES #****************************\n");
	printf("****************************######################****************************\n\n");
	
	printf("Qual o CPF?\n");
	//fgets(vetCliente[(*p)].nome, CPF, stdin);
	scanf("%s", vetCliente[(*p)].cpf );
	

	
	for(i = 0; i < (*p); i++) //Compara se os CPFs são iguais;
	{
		if(strcmp(vetCliente[(*p)].cpf, vetCliente[i].cpf) == 0) //Compara o CPF informado com os já cadastrados;
		{
			

			printf("\n---------------------------\n");
			printf("ERRO!! CPF JA CADASTRADO!!\n");
			printf("---------------------------\n\n");
			
			flag = 0;
			
		}
		
	}
	
	if(flag != 0)
	{
		
	printf("Qual o nome?\n");
	//fgets(vetCliente[(*p)].nome, NOME, stdin);
	scanf("%s", vetCliente[(*p)].nome );
	
	printf("Qual o telefone?\n");
	//fgets(vetCliente[(*p)].telefone, TELEFONE ,stdin);
	scanf("%s", vetCliente[(*p)].telefone );


		(*p)++; //A cada cadastro efetuado com sucesso é feito o incremento do valor 1 no ponteiro
		printf("\n-------------------------------\n");
		printf("CADASTRO EFETUADO COM SUCESSO!!\n");
		printf("-------------------------------\n");
		
	}
}


void alteraCadastroCliente(tCliente vetCliente[MAX], int *p){
	
	
		
}

void menuAlteraCliente(tCliente vetCliente[MAX], int *p){
	
	int opcao;
	
	printf("***************************####################***************************\n");
	printf("***************************# ALTERAR CLIENTE  #***************************\n");
	printf("***************************####################***************************\n\n");
	printf("1 - Alterar CPF\n");
	printf("2 - Alterar NOME\n");
	printf("3 - Alterar TELEFONE\n");
	printf("0 - Voltar ao MENU PRINCIPAL\n");
	printf("\nDigite uma opcao do menu:");
	scanf("%d", &opcao);
	
	while((opcao<0)||(opcao>3)){
		
		printf("Opcao digitada invalida. Digite novamente:");
		scanf("%d", &opcao);
	}
	
	switch(opcao){
		
	case 1: system("cls"); alteraCadastroCPF(vetCliente, p); break;
	case 2: system("cls"); alteraCadastroNome(vetCliente, p); break;
	case 3: system("cls"); alteraCadastroTelefone(vetCliente, p); break;
	case 0: break;
		
	}
	
	
}

void alteraCadastroCPF(tCliente vetCliente[MAX], int *p){
	
	printf("\n****************************ALTERAR CPF****************************\n");
	printf("Qual o novo CPF?\n");
	
}

void alteraCadastroNome(){
	
}

void alteraCadastroTelefone(){
	
}