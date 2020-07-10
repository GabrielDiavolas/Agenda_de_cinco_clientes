//Agenda que permite armazenar o cadastro de, no m�ximo, 5 clientes por vez.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Estruturas
struct cliente {
	char nome[100], numero[100], email[100];
	int codigo;
};

//Prot�tipo das fun��es e vari�veis globais
int j, l, w, h, q, f;
void criarlista();
void lerlista();
int verificar(int l);
FILE *arq;
struct cliente ficha[5];


//Fun��o principal
int main (){
	//Declara��o de vari�veis
	int op1;
	int op;
	//Declara��o de fun��es e arquivos
	setlocale(LC_ALL, "");
	arq = fopen("lista.txt", "w+");
	if (arq == NULL){
		printf(" \n Ocorreu um erro : o arquivo n�o foi criado! \n ");
	} else {
		//Processamento
		rewind(arq);
		j = 0;
		w = 0;
		q = 1;
		op1 = 6;
		while (op1 == 6){
			op = 3; //Inicializa a vari�vel para n�o armazenar o valor da �ltima escolha.
			printf(" \n************************Menu de op��es************************ \n ");
			printf("\n *Digite 1 para adicionar um novo cliente");
			printf("\n *Digite 2 para ver todos os clientes cadastrados");
			printf("\n *Digite 0 para encerrar o programa \n ");
			printf("\n Digite sua op��o: ");
			scanf("%d", &op);
			fflush(stdin);
			system("cls");

			if (op == 1){
				if (w>=5){
					printf(" \n Agenda lotada! \n ");
					system("pause");
					system("cls");
				} else {
					criarlista();
				}
			} else {
				if (op == 2){
					system("cls");
					lerlista();
					system("pause");
					system("cls");
				} else {
					if (op == 0){
						printf(" \n Encerrando o programa ... \n ");
						op1 = 2;
					} else {
						system("cls");
						printf(" \n Erro: op��o inv�lida! \n ");
						system("pause");
						system("cls");
					}
				} 
			}

		}
	}
	fclose(arq);
	return (0);
}

void criarlista(){
	//Declara��o de vari�veis
	int i;
	//Processamento do arquivo
	arq = fopen("lista.txt", "a");
	if (arq == NULL){
		printf(" \n Ocorreu um erro : o arquivo n�o foi criado! \n ");
	} else {
		for(h=q;h<=5;h++){
			if (w>=5){ //Verifica��o de seguran�a, caso algo d� errado
				printf(" \n Agenda lotada! \n ");
				h = 5;
				system("pause");
				system("cls");
			} else {
				w++;//Contadora/limitadora de adi��o dos clientes
				
				printf(" \n***************************Cliente_%d**************************** \n", h);
				printf("\n Digite o nome do cliente:\n ");
				gets(ficha[h].nome);
				fwrite(ficha[h].nome, 100, 1, arq);
				fflush(stdin);
										
				printf("\n Digite o telefone do cliente:\n ");
				gets(ficha[h].numero);
				fwrite(ficha[h].numero, 100, 1, arq);
				fflush(stdin);
										
				printf("\n Digite o e-mail do cliente: \n ");
				gets(ficha[h].email);
				fwrite(ficha[h].email, 100, 1, arq);
				fflush(stdin);
			
				ficha[h].codigo = h;
				system("cls");
		
				f = h+1; //Armazena o valor de onde o vetor parou
						
				l = h; //Inicializa l com valor de h para n�o ter erro com lixo de mem�ria
				h = verificar(h);
						
				if (w>=5){
					system("cls");
					printf(" \n Agenda lotada! \n ");
					system("pause");
					system("cls");
				}
			}
		}
		h = f-1; //Passa o valor de onde o vetor parou -1 posi��o, assim na fun��o lerlista teremos todos os valores preenchidos impressos
		q = f; // Armazena a posi��o	
		j = 1; //Faz a checagem para ver se essa fun��o foi executada ao menos uma vez	
	} 
	fclose(arq);
}

void lerlista(){
	//Declara��o de vari�veis
	int k, i, r;
	//Processamento do arquivo
	arq = fopen("lista.txt", "r");
	if (arq == NULL){
		printf( " \n Lista vazia! \n " );
	}else {
		k = j;
		if (k == 0){
			system("cls");
			printf(" \n Agenda vazia! \n " );
		} else {
			 r = h; // Armazena o valor de h
			 h = 1; // Inicializa h para exibir em ordem
			for(i=1; i<=r; i++){			
				fread(ficha[h].nome, 100, 1, arq);
				fread(ficha[h].numero, 100, 1, arq);
				fread(ficha[h].email, 100, 1, arq);

				printf(" \n***************************Cliente_%d*************************** \n", i);
				printf("\n C�digo: %d \n", ficha[h].codigo);
				printf("\n Nome: %s \n", ficha[h].nome);
				printf("\n Telefone: %s \n", ficha[h].numero);
				printf("\n E-mail: %s \n", ficha[h].email);
				printf(" \n*************************************************************** \n");

				h++;//Faz as var�veis que tem como �ndice o h serem exibidas, evitando aparecer s� uma
			}
			h = r; //Retoma o antigo valor de h para quando executar novamente, ter a ordem em criarlista
		}
	}
	fclose(arq);
}

int verificar (int l){
	//Declara��o de vari�veis
	int op3, op4;
	//Processamento
	op3 = 3;
	op4 = 3; 
	while(op4 == 3){
		printf(" \n*************************************************************** \n");
		printf(" \n Gostaria de adicionar mais algum cliente ? \n 1 - Sim \n 2 - N�o \n " );
		scanf("%d", &op3);
		fflush(stdin);
		
		switch (op3){
			case 1 : //Aceitou adicionar +1 cliente
				op4 = 2;
				system("cls");
			break;

			case 2 : //Rejeitou adicionar +1 cliente
				op4 = 2;
				l = 6;
				system("cls");
			break;

			default : //Digitou algo diferente de 2 e 1
				system("cls"); 
				printf(" \n Erro : op��o inv�lida! \n ");
				system("pause");
				system("cls");
			break;
		}
	}
	return (l);
}


