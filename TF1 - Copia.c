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

/*PROT�TIPO DAS FUN��ES*/

void inBonus(); //Fun��o criada para inicialiar valores(Teto=1000, valor de 1 bonus=R$0.50, valor para bonifica��o=R$100,00)

//Fun��es -> MENU PRINCIPAL
int menuPrincipal(); //Fun��o criada para imprimir na tela as op��es do MENU PRINCIPAL

//Fun��es -> 1 - MENU CONFIGURAR BONUS
void menuConfiguraBonus();  //Fun��o criada para imprimir na tela as op��es do MENU CONFIGURAR BONUS
void alteraTeto(); //Fun��o 1 - Alterar Teto
void alterarBonus(); //Fun��o 2 - Alterar valor de 1 bonus
void alterarReceberBonus(); //Fun��o 3 - Alterara valor para receber bonus

//Fun��es -> 2 - CADASTRAR CLIENTE
void cadastraCliente(); //Fun��o criada para imprimir na tela as op��es do MENU CADASTRAR CLIENTE

//Fun��es -> 3 - MENU ALTERAR CLIENTE
void menuAlteraCliente(); //Fun��o criada para imprimir na tela as op��es do MENU ALTERA CLIENTE
void alteraCadastroCliente(); //Fun��o criada para verificar se o CPF j� foi cadastrado
void alteraCadastroCPF(); //Fun��o criada para alterar o CPF no cadastro do cliente
void alteraCadastroNome(); //Fun��o criada para alterar o NOME no cadastro do cliente
void alteraCadastroTelefone(); //Fun��o criada para alterar o TELEFONE no cadastro do cliente

int main()
{
	
	int opcao, controleC=0; 
	tBonus altera;
	tBonus *pAltera; //Ponteiro para fun��es (Alterar TETO, Alterar VALOR BONUS, Alterar VALOR RECEBER BONUS)
	
	pAltera = &altera;
	
	int *p1 = &controleC; //Ponteiro criado para controlar fun��es CADASTRO e ALTERAR clientes(� iniciado com o valor 0)
	tCliente vetCliente[MAX]; //Vetor de elementos do tipo tCliente

	inBonus(&altera); //Chamada da fun��o inBonus(Valores padr�es iniciados). Nesta fun��o � passado o endere�o da variavel "altera"
	
	
	
	
	
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

void inBonus(tBonus *p){ //Defini��o para inicializar valores de campos da estrutura tBonus(Teto, valor, valorBonificar)
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

void alteraTeto(tBonus *p){ //A fun��o recebe  do ponteiro(*p) os valores passados pela fun��o chamadora

	printf("\n****************************ALTERAR TETO****************************\n");
	printf("Qual o novo valor do teto?\n");
	scanf("%d", &p->teto);
	
	while(p->teto<0){
	
	printf("Erro: valor negativo. Digite novamente:\n");
	scanf("%d", &p->teto);
}	

 	 system("cls");
	
}


void alterarBonus(tBonus *p){ //A fun��o recebe  do ponteiro(*p) os valores passados pela fun��o chamadora
	
	printf("\n****************************ALTERAR BONUS****************************\n");
	printf("Qual novo valor de um bonus?\n");
	scanf("%f", &p->valor);
	while(p->valor<0){
		printf("ERRO: valor negativo. Digite novamente:n");
	scanf("%f", &p->valor);
		
	}
	
	 system("cls");
	
}
void alterarReceberBonus(tBonus *p){ //A fun��o recebe  do ponteiro(*p) os valores passados pela fun��o chamadora
	
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
	

	
	for(i = 0; i < (*p); i++) //Compara se os CPFs s�o iguais;
	{
		if(strcmp(vetCliente[(*p)].cpf, vetCliente[i].cpf) == 0) //Compara o CPF informado com os j� cadastrados;
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


		(*p)++; //A cada cadastro efetuado com sucesso � feito o incremento do valor 1 no ponteiro
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