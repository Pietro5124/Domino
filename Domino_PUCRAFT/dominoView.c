#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void mostraPecas()
{
    int l;

    for(int l=1;l<=28;l++)
    {
    printf("|%d/%d| ",pecasDomino[l].lado1,pecasDomino[l].lado2);
    printf("Status da peca :%d\n",pecasDomino[l].status);
    }
    printf("\n");
}

int menu(int escolha)
{
	printf("    #################################################\n");
	printf("    #     _                  _           _	    #\n");
	printf("    #    | |                (_)         /_/         #\n");
	printf("    #  __| |  ___  _ __ ___  _ _ __ ___ _	    #\n");
	printf("    # / _` | / _ \\| '_ ` _ \\| | '_ \\ / _ \\	    #\n");
	printf("    # |(_| |  (_) | | | | | | | | | | (_) |	    #\n");
	printf("    # \\__,_| \\___/|_| |_| |_|_|_| |_|\\___/          #\n");
	printf("    #						    #\n");
	printf("    #	1) Iniciar novo Jogo			    #\n");
	printf("    #	2) Continuar a Jogar			    #\n");
	printf("    #	3) Salvar Jogo				    #\n");
	printf("    #	4) Carregar Jogo			    #\n");
	printf("    #	5) Regras do Jogo			    #\n");
	printf("    #	6) Sair do Jogo				    #\n");
	printf("    #	7) Creditos				    #\n");
	printf("    #################################################\n");

	scanf("%d",&escolha);

	return escolha;
}

void regras()
{
        printf("\n\n_____________________________ R E G R A S _____________________________ \n\n");
		printf("--> Inicio da Partida:\n-Sao compradas 7 pedras por ");
		printf("jogador. As 14 pedras restantes serao \nusadas para comprar ");
		printf("no caso do jogador nao ter a pedra da vez.\n_______________________________________________________________________\n\n");
		printf("--> Regra Numero 1:\nO jogador com a maior pedra (6-6) comeca o jogo,");
		printf(" colocando-a na mesa.\nCaso nenhum dos jogadores tenha a pedra 6x6, inicia");
		printf("o 5x5, 4x4, 3x3,\n2x2, 1x1, 0x0 ou a pedra com maior numero de pontos, ");
		printf("nesta ordem.\n_______________________________________________________________________\n\n");
		printf("--> Regra Numero 2:\nCada jogador deve tentar encaixar uma de suas pedras ");
		printf("nas extremidades\ndo jogo na mesa.\nQuando o jogador consegue encaixar uma pedra, ");
		printf("ele compra uma da pilha.\n_______________________________________________________________________\n\n");
		printf("--> Regra Numero 3:\nO jogo acaba quando algum jogador fica sem pedras na\n");
		printf("mao, ou o jogo fica fechado.\n_______________________________________________________________________\n\n\n\n");
}

void creditos()
{
        printf("\n\n\n_________________ PUCRAFT & CO. _________________\n\n");
		printf("MIGUEL MARTINAZZO\nSERGIO TAGAWA\nPIETRO GIORGI\nGUSTAVO SCAGLIONE\n\n");
		printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
		printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
		printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
		printf("&&&&#//////////////////////////#&&&&&\n");
		printf("&&////////////////////////////////&&&\n");
		printf("///////////////////////////////((((((\n");
		printf("//////////////////((//////////////(((\n");
		printf("////,        ,//////(((        ,////(\n");
		printf("////,        ,/////////        .////(\n");
		printf("((///////////(##%%%%%%###////////(((((((\n");
		printf("(((((////##################////((((((\n");
		printf("(((((((////##############////((((((((\n");
		printf("(((((((((((((((((((((((((((((((((((((%\n");
		printf("@@@@@@@@@@@@@@@@%%%%%%%@@@@@@@@@@@@@@@@@@\n");
		printf("\n\nHerobrine diz: Nescau e melhor que Toddy. \n\n");
}

void qualOpcao()
{
    printf("\nQual opcao voce deseja fazer: nao embaralhas(0) ou embaralhar(1), para caso queira voltar ao menu digite(2)\n");
}

void mostrarMao1()
{
    int i;
    printf("\nMao jogador 1:\n");

    for(i=1;i<=7;i++)
    {
        printf("|%d/%d| ",pecasDomino[i].mao1,pecasDomino[i].mao11);
        printf("Status da peca :%d\n",pecasDomino[i].status);
    }

    printf("\n\n");
}

void mostrarMao2()
{
    int j;

    printf("\nMao jogador 2:\n");

    for(j=1;j<8;j++)
    {
        printf("|%d/%d| ",pecasDomino[j].mao2,pecasDomino[j].mao22);
        printf("Status da peca :%d\n",pecasDomino[j+7].status);
    }
    printf("\n\n");
}

void apresentaMesa(int peca1,int peca2)
{
    printf("|%d/%d|",pecasDomino[peca1].mao1,pecasDomino[peca1].mao11);

    printf("|%d/%d|",pecasDomino[peca2].mao2,pecasDomino[peca2].mao22);
}
