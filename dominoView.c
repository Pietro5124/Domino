#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void mostraPecas()
{
    int l;

    for(l=1;l<=28;l++)
    {
    printf("|%d/%d| ", pecasDomino[l].lado1, pecasDomino[l].lado2);
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

void mostrarMao(int jogador)
{
    int i;
    printf("=============\n");
    printf("  JOGADOR %d  ",jogador);
    printf("\n=============\n");
    for(i=1;i<=28;i++)
    {
        if(pecasDomino[i].status==jogador)
        {
            printf("|%d/%d|  ",pecasDomino[i].lado1,pecasDomino[i].lado2);
            printf("Status da peca :%d\n",pecasDomino[i].status);
        }
    }

    printf("\n\n");
}

void apresentaMesa()
{
    for(int cont=1;cont<=mesa[cont].numeroDePecas;cont++)
    {
        printf("|%d/%d| ",mesa[cont].ladoE,mesa[cont].ladoE);
    }

    printf("\n\n");
}

int subMenu(int opcao[])
{
    printf("Qual acao voce deseja realizar agora? [1] = Jogar [2] = Comprar [3] = Passar [4] = Sair para o menu.\n\n");
    scanf("%d",&opcao[0]);

    return opcao[0];
}
