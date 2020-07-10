//Agenda que permite armazenar o cadastro de, no máximo, 5 clientes por vez.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//Estruturas
struct cliente {
	char nome[100], numero[100], email[100];
	int codigo;
};

//Protótipo das funções e variáveis globais
int j, l, w, h, q, f;
void criarlista();
void lerlista();
int verificar(int l);
FILE *arq;
struct cliente ficha[5];


//Função principal
int main (){
	//Declaração de variáveis
	int op1;
	int op;
	//Declaração de funções e arquivos
	setlocale(LC_ALL, "");
	arq = fopen("lista.txt", "w+");
	if (arq == NULL){
		printf(" \n Ocorreu um erro : o arquivo não foi criado! \n ");
	} else {
		//Processamento
		rewind(arq);
		j = 0;
		w = 0;
		q = 1;
		op1 = 6;
		while (op1 == 6){
			op = 3; //Inicializa a variável para não armazenar o valor da última escolha.
			printf(" \n************************Menu de opções************************ \n ");
			printf("\n *Digite 1 para adicionar um novo cliente");
			printf("\n *Digite 2 para ver todos os clientes cadastrados");
			printf("\n *Digite 0 para encerrar o programa \n ");
			printf("\n Digite sua opção: ");
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
						printf(" \n Erro: opção inválida! \n ");
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
	//Declaração de variáveis
	int i;
	//Processamento do arquivo
	arq = fopen("lista.txt", "a");
	if (arq == NULL){
		printf(" \n Ocorreu um erro : o arquivo não foi criado! \n ");
	} else {
		for(h=q;h<=5;h++){
			if (w>=5){ //Verificação de segurança, caso algo dê errado
				printf(" \n Agenda lotada! \n ");
				h = 5;
				system("pause");
				system("cls");
			} else {
				w++;//Contadora/limitadora de adição dos clientes
				
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
						
				l = h; //Inicializa l com valor de h para não ter erro com lixo de memória
				h = verificar(h);
						
				if (w>=5){
					system("cls");
					printf(" \n Agenda lotada! \n ");
					system("pause");
					system("cls");
				}
			}
		}
		h = f-1; //Passa o valor de onde o vetor parou -1 posição, assim na função lerlista teremos todos os valores preenchidos impressos
		q = f; // Armazena a posição	
		j = 1; //Faz a checagem para ver se essa função foi executada ao menos uma vez	
	} 
	fclose(arq);
}

void lerlista(){
	//Declaração de variáveis
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
				printf("\n Código: %d \n", ficha[h].codigo);
				printf("\n Nome: %s \n", ficha[h].nome);
				printf("\n Telefone: %s \n", ficha[h].numero);
				printf("\n E-mail: %s \n", ficha[h].email);
				printf(" \n*************************************************************** \n");

				h++;//Faz as varíveis que tem como índice o h serem exibidas, evitando aparecer só uma
			}
			h = r; //Retoma o antigo valor de h para quando executar novamente, ter a ordem em criarlista
		}
	}
	fclose(arq);
}

int verificar (int l){
	//Declaração de variáveis
	int op3, op4;
	//Processamento
	op3 = 3;
	op4 = 3; 
	while(op4 == 3){
		printf(" \n*************************************************************** \n");
		printf(" \n Gostaria de adicionar mais algum cliente ? \n 1 - Sim \n 2 - Não \n " );
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
				printf(" \n Erro : opção inválida! \n ");
				system("pause");
				system("cls");
			break;
		}
	}
	return (l);
}


