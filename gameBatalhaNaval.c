#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>
#include<string.h>
#define N 11
struct placar {
	char nome[30];
	int pontos_M; 
	int pontos_J;
	
}ponto;



//FUNÇÕES 
void iniciatabuleiro_jogador(int tabuleiro_jogador[][N]);
void iniciatabuleiro_maquina(int tabuleiro_maquina[][N]);

void posicionar_navios_jogador(int tabuleiro_jogador[][N]);
void posicionar_navios_maquina(int tabuleiro_jogador[][N]);
void mostrartabuleiro_jogador(int tabuleiro_jogador[][N]);
void mostrartabuleiro_maquina(int tabuleiro_maquina[][N]);

void localizacao_embarcaçoes_maquina(int tabuleiro_jogador[][N], int naviomaquina[][N]);
void localizacao_embarcaçoes_jogador(int tabuleiro_jogador[N][N], int naviojogador[][N]);
void _sleep(x);
int acertou_jogador(int tiro[2], int naviomaquina[][2], int tabuleirofacil[][2]);
int acertou_maquina(int tiro[2], int naviojogador[][2], int tabuleiro_maquina[][2]);
void placar();


//FUNÇÕES TIRO
void dartiro_jogador(int tiro[2], int x, int naviomaquina[][2]);
void dartiro_maquina(int tiro[2], int x, int naviojogador[][2]);
void placar_j();

int main() {
	int i, j, opc, tiro[2]; //Variáveis usadas em todos ou quase todos os modos
	int tabuleiro_jogador[N][N], naviojogador[N][N], naviomaquina[N][N], tabuleiro_maquina[N][N]; //Variaveis 
	char sair="";
	char name[15];
	system("cls");
	printf("\tSEU NOME: ");
	fflush(stdin);
	fgets(ponto.nome,30,stdin);
	

	do {
		
		system("cls");
		printf("\t\t\tBATALHA NAVAL\n\n");
		printf("\t1 - JOGAR\n");
		printf("\t3 - INSTRUCOES\n");
		printf("\t5 - SAIR\n");
		printf("\tOpcao: ");
		fflush(stdin);
		scanf_s("%d", &opc);
		

		switch (opc) {
		case 1: //Jogar
			system("cls");
			printf("\t\t\tBATALHA NAVAL\n\n");
			printf("\t1 - FACIL 10x10\n");
			printf("\t3 - DIFICL 15x15\n");
			printf("\t4 - VOLTAR\n");
			printf("\tOpcao: ");
			fflush(stdin);
			scanf_s("%d", &opc);
			switch (opc) {
			case 1: //Facil
				

				system("cls");
				iniciatabuleiro_jogador(tabuleiro_jogador);

				posicionar_navios_maquina(tabuleiro_jogador);
				//Sleep(2000);
				localizacao_embarcaçoes_maquina(tabuleiro_jogador, naviomaquina);
				iniciatabuleiro_jogador(tabuleiro_jogador);
				system("cls");

				iniciatabuleiro_maquina(tabuleiro_maquina);

				posicionar_navios_jogador(tabuleiro_jogador);
				localizacao_embarcaçoes_jogador(tabuleiro_jogador, naviojogador);
				system("cls");


				//Vai começar o jogo
				mostrartabuleiro_jogador(tabuleiro_jogador);
				Sleep(2000);

				iniciatabuleiro_jogador(tabuleiro_jogador); //o que o jogar vê para tentar acertar o navio da maquina
				iniciatabuleiro_maquina(tabuleiro_maquina);// o que a maquina atira para acertar o jogador
				system("cls");

				//começa a atirar
				int a = 0,acertou, acertou_m;
				do {
					mostrartabuleiro_jogador(tabuleiro_jogador);

					dartiro_jogador(tiro, N,tabuleiro_jogador);
					system("cls");
					acertou=acertou_jogador(tiro, naviomaquina, tabuleiro_jogador);
					mostrartabuleiro_jogador(tabuleiro_jogador);
					while (acertou == 1) {
						dartiro_jogador(tiro, N, tabuleiro_jogador);
						system("cls");
						acertou = acertou_jogador(tiro, naviomaquina, tabuleiro_jogador);
						mostrartabuleiro_jogador(tabuleiro_jogador);
					}
					Sleep(5000);
					system("cls");

					mostrartabuleiro_maquina(tabuleiro_maquina);
					dartiro_maquina(tiro, N,tabuleiro_maquina);
					acertou_m= acertou_maquina(tiro, naviojogador, tabuleiro_maquina);
					mostrartabuleiro_maquina(tabuleiro_maquina);
					while (acertou == 1) {
						dartiro_maquina(tiro, N, tabuleiro_maquina);
						system("cls");
						acertou = acertou_jogador(tiro, naviomaquina, tabuleiro_jogador);
						mostrartabuleiro_jogador(tabuleiro_jogador);
					}
					Sleep(5000);
					system("cls");

					a++;

				} while (a < 30);

				printf("\n\n\n\n\n\n");

				system("pause");
				break;


			case 3: //Difícil
				

				break;

			case 4: //Voltar
				break;

			default:
				system("cls");
				printf("Opcao Invalida!!!\n\n");
				system("pause");
				break;
			}
			break;



		case 3: //Instruções
			system("cls");
			puts("\t\t\tBATALHA NAVAL\n\n\tA cada rodada, entre com dois numeros, o numero da linha e o numero da  coluna onde quer dar o tiro. Depois eh so esperar pra ver se acertou, ou a dica.\n\tO jogo possui modo facil e dificil, no modo facil o campo de batalha    sera menor, serao 3 navios para destruir e havera dicas. Ja no modo dificil sera um campo maior com 6 barcos e sem dicas.\n\n");
			puts("Legenda:\n~: Agua no bloco, ainda nao foi dado o tiro.\n*: Tiro dado, nao ha nada ali.\nX: Tiro dado, havia um navio ali.\n");
			system("pause");
			break;


		case 5: //Sair
			system("cls");
			do {
				printf("Deseja sair(s/n): ");
				fflush(stdin);
				sair = getchar();
			} while (sair != 's' && sair != 'n');
			if (sair == 's') {
				puts("\n\n\t\tSAINDO!!\n\n");
				exit(0);
			}
			else {
				continue;
			}
			break;

		default:
			system("cls");
			printf("Opcao Invalida!!!!\n\n");
			system("pause");
			break;
		}
	} while (sair != 's');

	return 0;


}


//Função para iniciar o tabuleiro com valor "-1" que eh quando nao deu neunhum tiro
void iniciatabuleiro_jogador(int tabuleiro_jogador[][N]) {

	int l, c;

	for (l = 0; l <= N; l++) {
		for (c = 1; c <= N; c++) {
			tabuleiro_jogador[l][c] = -1;
		}
	}

}

void iniciatabuleiro_maquina(int tabuleiro_maquina[][N]) {

	int l, c;

	for (l = 0; l <= N; l++) {
		for (c = 1; c <= N; c++) {
			tabuleiro_maquina[l][c] = -1;
		}
	}

}

//Função para mostrar tabuleiro | = agua, X = tiro errado, - = acertou navio
void mostrartabuleiro_jogador(int tabuleiro_jogador[][N]) {

	int l, c;
	placar_j();
	printf("\n\n\t\t\t  1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10\n\n");
	

	for (l = 1; l < N; l++) {
		printf("\t\t%d ", l);
		for (c = 1; c < N; c++) {
			if (tabuleiro_jogador[l][c] == -1)
				printf("\t | ");
			if (tabuleiro_jogador[l][c] == 0)
				printf("\t - ");
			if (tabuleiro_jogador[l][c] == 1)
				printf("\t X ");
		}
		printf("\n\n");
	}

}

void mostrartabuleiro_maquina(int tabuleiro_maquina[][N]) {

	int l, c;
	placar_j();
	printf("\n\t\t\t  1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10\n");

	for (l = 1; l < N; l++) {
		printf("\t\t%d ", l);
		for (c = 1; c < N; c++) {
			if (tabuleiro_maquina[l][c] == -1)
				printf("\t m ");
			if (tabuleiro_maquina[l][c] == 0)
				printf("\t - ");
			if (tabuleiro_maquina[l][c] == 1)
				printf("\t X ");
		}
		printf("\n\n");
	}
	printf("Maquina jogando\n");
}

//Posicionar_navios DO JOGADOR ///////////////////////////////////////////////////////////////

void posicionar_navios_jogador(int tabuleiro_jogador[][N]) {

	int a, b, l, c, aprovado_n, aprovado_p, aprovado_h, barcos, lado, opc;
	a = 0; b = 0; aprovado_n = 0; aprovado_p = 0; aprovado_h = 0; barcos = 0;
	int barcos_maquina[32][32]; //2 navios, 1 porta avioes e 2 hidroaviões

	printf("\n\n\t\t\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10\n");

	for (l = 1; l < N; l++) {
		printf("\t\t%d ", l);
		for (c = 1; c < N; c++) {
			if (tabuleiro_jogador[l][c] == -1)
				printf("\t | ");
			if (tabuleiro_jogador[l][c] == 0)
				printf("\ - ");
			if (tabuleiro_jogador[l][c] == 1)
				printf("\t [] ");
		}
		printf("\n\n");
	}


	/////// NAVIO
	do {
		printf("porta navios\n");
		printf("Informe a linha\n");
		scanf_s("%d", &a);
		printf("Informe a coluna\n");
		scanf_s("%d", &b);


		printf("em que direcao sera contruido o restante do navio \n");
		printf("\t 0 - esqueda\n");
		printf("\t 1 - direita\n");
		printf("\t 2 - cima\n");
		printf("\t 3 - baixo\n");
		printf("\t Opcao: ");
		fflush(stdin);
		scanf_s("%d", &opc);
		switch (opc) {
		case 0:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b - 1] != 1 &
				tabuleiro_jogador[a][b - 2] != 1 &
				b - 2 > 0)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b - 1] = 1;
				tabuleiro_jogador[a][b - 2] = 1;
				aprovado_n++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 1:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b + 1] != 1 &
				tabuleiro_jogador[a][b + 2] != 1 &
				b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b + 1] = 1;
				tabuleiro_jogador[a][b + 2] = 1;
				aprovado_n++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 2:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b] != 1 &
				tabuleiro_jogador[a - 2][b] != 1 &
				a - 2 > 0)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b] = 1;
				tabuleiro_jogador[a - 2][b] = 1;
				aprovado_n++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 3:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a + 1][b] != 1 &
				tabuleiro_jogador[a + 2][b] != 1 &
				a + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a + 1][b] = 1;
				tabuleiro_jogador[a + 2][b] = 1;
				aprovado_n++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		}


	} while (aprovado_n < 2);

	/////porta avioes
	do {
		printf("porta avioes\n");
		printf("Informe a linha\n");
		scanf_s("%d", &a);
		printf("Informe a coluna\n");
		scanf_s("%d", &b);


		printf("em que direcao sera contruido o restante do navio \n");
		printf("\t 0 - esqueda\n");
		printf("\t 1 - direita\n");
		printf("\t 2 - cima\n");
		printf("\t 3 - baixo\n");
		printf("\t Opcao: ");
		fflush(stdin);
		scanf_s("%d", &opc);
		switch (opc) {
		case 0:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b - 1] != 1 &
				tabuleiro_jogador[a][b - 2] != 1 &
				tabuleiro_jogador[a][b - 3] != 1 &
				b - 3 > 0)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b - 1] = 1;
				tabuleiro_jogador[a][b - 2] = 1;
				tabuleiro_jogador[a][b - 3] = 1;
				aprovado_p++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 1:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b + 1] != 1 &
				tabuleiro_jogador[a][b + 2] != 1 &
				tabuleiro_jogador[a][b + 3] != 1 &
				b + 3 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b + 1] = 1;
				tabuleiro_jogador[a][b + 2] = 1;
				tabuleiro_jogador[a][b + 3] = 1;
				aprovado_p++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 2:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b] != 1 &
				tabuleiro_jogador[a - 2][b] != 1 &
				tabuleiro_jogador[a - 3][b] != 1 &
				a - 3 > 0)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b] = 1;
				tabuleiro_jogador[a - 2][b] = 1;
				tabuleiro_jogador[a - 3][b] = 1;
				aprovado_p++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 3:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a + 1][b] != 1 &
				tabuleiro_jogador[a + 2][b] != 1 &
				tabuleiro_jogador[a + 3][b] != 1 &
				a + 3 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a + 1][b] = 1;
				tabuleiro_jogador[a + 2][b] = 1;
				tabuleiro_jogador[a + 3][b] = 1;
				aprovado_p++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		}

	} while (aprovado_p < 1);

	/////// H
	do {
		printf("Informe a linha\n");
		scanf_s("%d", &a);
		printf("Informe a coluna\n");
		scanf_s("%d", &b);


		printf("em que direcao sera contruido o restante do navio \n");
		printf("\t 0 - esqueda\n");
		printf("\t 1 - direita\n");
		printf("\t 2 - cima\n");
		printf("\t 3 - baixo\n");
		printf("\t Opcao: ");
		fflush(stdin);
		scanf_s("%d", &opc);
		switch (opc) {
		case 0:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b - 1] != 1 &
				tabuleiro_jogador[a - 1][b] != 1 &
				tabuleiro_jogador[a - 2][b] != 1 &
				a - 2 > 0)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b - 1] = 1;
				tabuleiro_jogador[a - 2][b] = 1;
				aprovado_h++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 1:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a + 1][b + 1] != 1 &
				tabuleiro_jogador[a + 1][b] != 1 &
				tabuleiro_jogador[a + 2][b] != 1 &
				a + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a + 1][b + 1] = 1;
				tabuleiro_jogador[a + 2][b] = 1;
				aprovado_h++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 2:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b - 1] != 1 &
				tabuleiro_jogador[a][b - 1] != 1 &
				tabuleiro_jogador[a][b - 2] != 1 &
				b - 2 > 0)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b - 1] = 1;
				tabuleiro_jogador[a][b - 2] = 1;
				aprovado_h++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);
			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		case 3:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a + 1][b + 1] != 1 &
				tabuleiro_jogador[a][b + 1] != 1 &
				tabuleiro_jogador[a][b + 2] != 1 &
				b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a + 1][b + 1] = 1;
				tabuleiro_jogador[a][b + 2] = 1;
				aprovado_h++;
				system("cls");
				mostrartabuleiro_jogador(tabuleiro_jogador);

			}
			else {
				printf("Não foi possivél colocar na posicao passada: ");
			}

			break;
		}


	} while (aprovado_h < 2);


	printf("saiu");
	printf("\n\n\t\t\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10\n");

	for (l = 1; l < N; l++) {
		printf("\t\t%d ", l);
		for (c = 1; c < N; c++) {
			if (tabuleiro_jogador[l][c] == -1)
				printf("\t ~ ");
			if (tabuleiro_jogador[l][c] == 0)
				printf("\ - ");
			if (tabuleiro_jogador[l][c] == 1)
				printf("\t [] ");
		}
		printf("\n\n");
	}



}


//Posicionar_navios da MAQUINA
void posicionar_navios_maquina(int tabuleiro_jogador[][N]) {

	int a, b, l, c, aprovado_n, aprovado_p, aprovado_h, barcos, lado, opc;
	a = 0; b = 0; aprovado_n = 0; aprovado_p = 0; aprovado_h = 0; barcos = 0;


	srand(time(NULL));

	a = rand() % 10;
	b = rand() % 10;

	a++;
	b++;

	//printf("%i \n", a, b);
	/////// NAVIO
	do {
		a = rand() % 10;
		b = rand() % 10;

		lado = rand() % 4;
		opc = lado;
		switch (opc) {
		case 0:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b - 1] != 1 &
				tabuleiro_jogador[a][b - 2] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b - 1] = 1;
				tabuleiro_jogador[a][b - 2] = 1;
				aprovado_n++;
			}

			break;
		case 1:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b + 1] != 1 &
				tabuleiro_jogador[a][b + 2] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b + 1] = 1;
				tabuleiro_jogador[a][b + 2] = 1;
				aprovado_n++;
			}

			break;
		case 2:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b] != 1 &
				tabuleiro_jogador[a - 2][b] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b] = 1;
				tabuleiro_jogador[a - 2][b] = 1;
				aprovado_n++;
			}

			break;
		case 3:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a + 1][b] != 1 &
				tabuleiro_jogador[a + 2][b] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a + 1][b] = 1;
				tabuleiro_jogador[a + 2][b] = 1;
				aprovado_n++;
			}

			break;
		}


	} while (aprovado_n < 2);

	/////porta avioes
	do {
		a = rand() % 10;
		b = rand() % 10;

		lado = rand() % 4;
		opc = lado;
		switch (opc) {
		case 0:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b - 1] != 1 &
				tabuleiro_jogador[a][b - 2] != 1 &
				tabuleiro_jogador[a][b - 3] != 1 &
				a - 3 > 0 & a + 3 < 11 &
				b - 3 > 0 & b + 3 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b - 1] = 1;
				tabuleiro_jogador[a][b - 2] = 1;
				tabuleiro_jogador[a][b - 3] = 1;
				aprovado_p++;
			}

			break;
		case 1:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a][b + 1] != 1 &
				tabuleiro_jogador[a][b + 2] != 1 &
				tabuleiro_jogador[a][b + 3] != 1 &
				a - 3 > 0 & a + 3 < 11 &
				b - 3 > 0 & b + 3 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a][b - 1] = 1;
				tabuleiro_jogador[a][b - 2] = 1;
				tabuleiro_jogador[a][b - 3] = 1;
				aprovado_p++;
			}

			break;
		case 2:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b] != 1 &
				tabuleiro_jogador[a - 2][b] != 1 &
				tabuleiro_jogador[a - 3][b] != 1 &
				a - 3 > 0 & a + 3 < 11 &
				b - 3 > 0 & b + 3 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b] = 1;
				tabuleiro_jogador[a - 2][b] = 1;
				tabuleiro_jogador[a - 3][b] = 1;
				aprovado_p++;
			}

			break;
		case 3:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a + 1][b] != 1 &
				tabuleiro_jogador[a + 2][b] != 1 &
				tabuleiro_jogador[a + 3][b] != 1 &
				a - 3 > 0 & a + 3 < 11 &
				b - 3 > 0 & b + 3 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a + 1][b] = 1;
				tabuleiro_jogador[a + 2][b] = 1;
				tabuleiro_jogador[a + 3][b] = 1;
				aprovado_p++;
			}

			break;
		}

	} while (aprovado_p < 1);

	/////// H
	do {
		a = rand() % 10;
		b = rand() % 10;

		a += 4;
		b += 5;
		a = a % 10;
		b = b % 10;

		lado = rand() % 4;
		opc = lado;
		switch (opc) {
		case 0:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b - 1] != 1 &
				tabuleiro_jogador[a - 1][b - 2] != 1 &
				tabuleiro_jogador[a][b - 1] != 1 &
				tabuleiro_jogador[a][b - 2] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b - 1] = 1;
				tabuleiro_jogador[a][b - 2] = 1;
				aprovado_h++;
			}

			break;
		case 1:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b + 1] != 1 &
				tabuleiro_jogador[a - 1][b + 2] != 1 &
				tabuleiro_jogador[a][b + 1] != 1 &
				tabuleiro_jogador[a][b + 2] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b + 1] = 1;
				tabuleiro_jogador[a][b + 2] = 1;
				aprovado_h++;
			}

			break;
		case 2:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a - 1][b - 1] != 1 &
				tabuleiro_jogador[a - 1][b - 2] != 1 &
				tabuleiro_jogador[a - 2][b] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a - 1][b - 1] = 1;
				tabuleiro_jogador[a - 2][b] = 1;
				aprovado_h++;
			}

			break;
		case 3:
			if (tabuleiro_jogador[a][b] != 1 &
				tabuleiro_jogador[a + 1][b + 1] != 1 &
				tabuleiro_jogador[a + 1][b + 2] != 1 &
				tabuleiro_jogador[a + 1][b] != 1 &
				tabuleiro_jogador[a + 2][b] != 1 &
				a - 2 > 0 & a + 2 < 11 &
				b - 2 > 0 & b + 2 < 11)
			{
				tabuleiro_jogador[a][b] = 1;
				tabuleiro_jogador[a + 1][b + 1] = 1;
				tabuleiro_jogador[a + 2][b] = 1;
				aprovado_h++;

			}

			break;
		}


	} while (aprovado_h < 2);


	printf("saiu");
	printf("\n\n\t\t\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10\n");

	for (l = 1; l < N; l++) {
		printf("\t\t%d ", l);
		for (c = 1; c < N; c++) {
			if (tabuleiro_jogador[l][c] == -1)
				printf("\t ~ ");
			if (tabuleiro_jogador[l][c] == 0)
				printf("\t - ");
			if (tabuleiro_jogador[l][c] == 1)
				printf("\t [] ");
			if (tabuleiro_jogador[l][c] == 3)
				printf("\t 3 ");
		}
		printf("\n\n");
	}



}

//Função para guardar a localização dos navios da Maquina
void localizacao_embarcaçoes_maquina(int tabuleiro_jogador[][N], int naviomaquina[][N]) {
	int j = 0;
	int l = 0;
	for (l = 0; l < N; l++) {
		for (j = 0; j < N; j++) {
			naviomaquina[l][j] = tabuleiro_jogador[l][j];
		}
	}

	//printf("%i valor", naviomaquina[2][2]);
	//Sleep(5000);
}

//Função para guardar a localização dos navios do jogador
void localizacao_embarcaçoes_jogador(int tabuleiro_jogador[][N], int naviojogador[][N]) {
	int j = 0;
	int l = 0;
	for (l = 0; l < N; l++) {
		for (j = 0; j < N; j++) {
			naviojogador[l][j] = tabuleiro_jogador[l][j];
		}
	}

	//printf("%i valor", naviojogador[2][2]);
}

//Função para mostrar se acertou ou errou
int acertou_jogador(int tiro[2], int naviomaquina[][N], int tabuleiro_jogador[][N]) {
	int a, b;
	a = tiro[0];
	b = tiro[1];


	if (naviomaquina[a][b] == 1) {
		printf("\n\t\t\tVoce acertou o tiro (%d,%d)\n\n", tiro[0], tiro[1]);
		tabuleiro_jogador[a][b] = 1;
		ponto.pontos_J ++;
		return 1;
	}
	else {
		printf("\nErrou voce nao atingiu nenhuma embarcacao, tiro (%d,%d) \n", tiro[0], tiro[1]);
		tabuleiro_jogador[a][b] = 0;
		return 0;
	}
	
}

//Função para mostrar se acertou ou errou
int acertou_maquina(int tiro[2], int naviojogador[][N], int tabuleiro_maquina[][N]) {
	int a, b;
	a = tiro[0];
	b = tiro[1];

	if (naviojogador[a][b] == 1) {
		printf("\n\t\t\t A MAQUINA acertou o tiro (%d,%d)", tiro[0], tiro[1]);
		ponto.pontos_M ++;
		tabuleiro_maquina[a][b] = 1;
		return 1;
	}
	else {
		printf("\nA MAQUINA Errou nao atingiu nenhuma embarcacao,tiro (%d,%d)\n\n\n", tiro[0], tiro[1]);
		tabuleiro_maquina[a][b] = 0;
		return 0;
	}
	
}


//Função para validar e guardar localização do tiro
void dartiro_jogador(int tiro[2], int x, int tabuleiro_jogador[][N]) {
	int c;
	int valido = 0;

	do{

		printf(" atire no campo que acha que esta o navio do inimigo\n");
		printf("Linha: ");
		fflush(stdin);
		scanf_s("%d", &tiro[0]);
		if (tiro[0] < 1 || tiro[0] > x) {
			do {
				puts("Linha inexistente!!\n");
				printf("Informe a linha novamente: ");
				fflush(stdin);
				scanf_s("%d", &tiro[0]);
			} while (tiro[0] < 1 || tiro[0] > x);
		}


		printf("Coluna: ");
		scanf_s("%d", &tiro[1]);
		if (tiro[1] < 1 || tiro[1] > x) {
			do {
				puts("Coluna inexistente!!\n");
				printf("Informe a coluna novamente: ");
				fflush(stdin);
				scanf_s("%d", &tiro[1]);
			} while (tiro[1] < 1 || tiro[1] > x);
		}

			int a = tiro[0];
			int b = tiro[1];

			//printf(" o %i e %i \n", a,b);
			//printf(" o que compara %i", tabuleiro_maquina[2][2]);
			if (tabuleiro_jogador[a][b] !=1 & tabuleiro_jogador[a][b]  !=0) {
				valido = 1;
			}
			else {
				printf("O campo já foi utilizado %i , tente outro campo que você nao atirou ", tabuleiro_jogador[a][b]);
			}

	} while (valido == 0);

}

//Função para validar e guardar localização do tiro
void dartiro_maquina(int tiro[2],int x, int tabuleiro_maquina[][2]) {
	int valido = 0;

	srand(time(NULL));
	do {
		do {
			tiro[0] = rand() % 10;
			tiro[1] = rand() % 10;
		} while (tiro[0] == 0 | tiro[1]==0);

		int a = tiro[0];
		int b = tiro[1];

		if (tabuleiro_maquina[a][b] == -1) {
			valido = 1;
		}
		else {
			//printf("O campo já foi utilizado, tente outro campo que você nao atirou");
		}
	
	} while (valido==0);
	valido = 0;
}


void placar_j() {
	printf("\n %s-PONTOS DO JOGADOR : %i MAQUINA PONTOS : %i",  ponto.nome, ponto.pontos_J, ponto.pontos_M);

}
void placar_M() {
	printf("\nPONTOS DO MAQUINA : %i\n", ponto.pontos_M);
}