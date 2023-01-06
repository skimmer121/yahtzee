#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include "lab.h"


struct jogador {
	int dados[5];
	int valores[13];
	int opcoes[13];
	int escolha[13];
};

 void sair(void) {
	int n = 0;
	system("cls");
	printf("\t\t\t\tDeseja fechar o jogo?\n");
	printf("1-SIM\t\t\t 2-NAO");
	(void)scanf("%d", &n);
	if (n != 1 && n != 2) {
		system("cls");
		printf("escolha invalida");
		system("cls");
		sair();
	}
	else if (n == 1) {
		
		//return 0;					//saida do programa nao funciona ele volta para o menu
		
	}
	else if(n==2) {
		system("cls");
		
	}
}	//funçao para sair do programa


 menu(struct jogador *j) {
	int n = 0;
	printf("\t\tBEM VINDO AO YATZHEE DOS POBRES\n\n");
	printf(" 1-NOVO JOGO \n 2-CARREGAR JOGO \n 3-REGRAS DO JOGO \n 4-SAIR DO JOGO\n");
	(void)scanf("%d", &n);

	switch (n)
	{
	//novo jogo
	case 1: {
		system("cls");
		novojogo(j);

		break;
	}
	//carregar jogo
	case 2: {


		break;
	}
	//regras do jogo
	case 3: {
		//regrasjogo();

		break;
	}
	/*caso para sair do jogo*/
	case 4: {
		sair();
		if (n == 0) {
			return 0;
		}
		else {
			system("cls");
			menu(j);
		}
		break;
	}

	default:	
		system("cls");
		printf("Porfavor escolha uma opção valida"); 
		
		menu(j);
		
	}
		

}

 int novojogo(struct jogador *j) {
	int p = 0,i=0,pontos=0,total=0;
	 do {
		 system("cls");
		 lançardados(j);					//lança os dados
		 for (i = 0; i < 2; i++) {
			

			 escolherdado(j);
			
			 
			 
		 } 
		 
		 pontos=tabela(j,pontos,total);
		 total += pontos;

		 p++;
		 
		 printf("Ronda %d\n", p);
		 system("pause");
	 }while (p != 13);

	 printf("%d", pontos);
	 

 }
 
 int lançardados(struct jogador *j) {			//lança os dados e escreve o primeiro lançamento
	 int  i = 0;
	 for (i = 0; i < 5; i++) {
		 j->dados[i] = rand() % 6 + 1;

	 }
	 for (i = 0; i < 5; i++) {
		 printf("dado[%d] :%d\n", (i+1),j->dados[i]);
	 }
	
 }
 
 int escolherdado(struct jogador *j) {    //escolhe e relança os dados
	 int i ,a=0;
	 for (i = 0; i < 3; i++) {															//funçao para escolher os dados que quero relançar
		 for (i = 0; i < 5; i++) {
			 printf("deseja relançar o dado %d (1-sim 2-nao): ", i);
			 (void)scanf(" %d", &a);
			 if (a == 1) {
				 j->dados[i] = rand() % 6 + 1;
				 printf("%d\n", j->dados[i]);
			 }
			 else {
				 continue;
			 }
		 }
	 }
	
	 
 }
 void regrasjogo(void) {					//funçao para o menu das regras do jogo
	 system("cls");
	 printf("");





 }

int tabela(struct jogador *j,int pontos,int total) {
	int escolha=0;
	int i;
	int contagem[6] = { 0 };

	for (i = 0; i < 5; i++) {				//formula para o numero que cada dado tem e quantos sao
		contagem[j->dados[i] - 1]++;
	}



	
	system("cls");
	printf("1.UNS\t\t\t\n");
	printf("2.DOIS\n");
	printf("3.TRES\n");
	printf("4.QUATRO\n");		
	printf("5.CINCO\n");
	printf("6.SEIS\n");
	printf("7.TRIPLO\n");
	printf("8.QUADRA\n");
	printf("9.FULLHOUSE\n");
	printf("10.PEQUENA SEQUENCIA\n");
	printf("11.GRANDE SEQUENCIA\n");
	printf("12.CHANCE\n");
	printf("13.YAHTZEE\n");
	printf("\n");
	printf("+-----+\n");
	for (int i = 0; i < 5; i++) {
		printf("|  %d   |\n", j->dados[i]);
	}
	printf("+-----+\n");



	do {
		printf("Escolha onde quer colocar os seus pontos");
		(void)scanf("%d", &escolha);
		if (escolha < 1 || escolha>13) {
			printf("Opcao invalida escolha outra opcao");						//funçao para n permitir colocar pontos na mesma categoria
		}
		else if (j->escolha[escolha - 1] == 1) {
			printf("Essa opçao ja foi escolhida");
		}
	} while (escolha < 1 || escolha>13 || j->escolha[escolha - 1] == 1);

	j->escolha[escolha - 1] = 1;
	switch (escolha) {
		case 1:
			pontos = contagem[0];					//conta o numero de uns 
			break;
		case 2:
			pontos = contagem[1];
			break;
		case 3:
			pontos = contagem[2];
			break;
		case 4:
			pontos = contagem[3];
			break;
		case 5:
			pontos = contagem[4];
			break;
		case 6:
			pontos = contagem[5];
			break;
		case 7:
			for (i = 0; i < 6; i++) {
				if (contagem[i] >= 3) {
					pontos = (i + 1) * 3;
				}
			}

			break;
		case 8:
			for (i = 0; i < 6; i++) {
				if (contagem[i] >= 4) {
					pontos = (i + 1) * 4;
				}
			}
			break;
		case 9:
			for (i = 0; i < 6; i++) {
				if (contagem[i] == 3) {
					for (int o = 0; o < 6; o++) {
						if (contagem[0] == 2 && o!=i) {
							pontos = (i + 1) * 4;
						}
					}
					
				}
			}
			break;
		case 10:
			if ((contagem[0] >= 1 && contagem[1] >= 1 && contagem[2] >= 1 && contagem[3] >= 1) || 
				(contagem[1] >= 1 && contagem[2] >= 1 && contagem[3] >= 1 && contagem[4] >= 1) || (contagem[2] >= 1 && contagem[3] >= 1 && contagem[4] >= 1 && contagem[5] >= 1)) {
				pontos = 30;
			}


			break;
		case 11:
			if ((contagem[0] >= 1 && contagem[1] >= 1 && contagem[2] >= 1 && contagem[3] >= 1 && contagem[4] >= 1) ||
				(contagem[1] >= 1 && contagem[2] >= 1 && contagem[3] >= 1 && contagem[4] >= 1 && contagem[5] >= 1)) {
				pontos = 40;
			}
			break;
		case 12:
			for (i = 0; i < 6; i++) {
				pontos += contagem[i] * (i + 1);
			}
			break;
		case 13:
			
			break;
	}
		
	return pontos;
}





int main(void) {
	int i;
	struct jogador j;
	for (i = 0; i < 5; i++) {			//inicializaçao dos dados
		j.dados[i] = 0;
		
	}
	for (i = 0; i < 13; i++) {			//inicializaçao dos dados
		j.opcoes[i] = 0;
		j.escolha[i] = 0;
	}
	srand(time(NULL));
	menu(&j);
	printf("\n\n\n\n");
	system("pause");
	printf("\n\n\n\n");
	return 0 ;

	printf("\n\n\n\n");
}



