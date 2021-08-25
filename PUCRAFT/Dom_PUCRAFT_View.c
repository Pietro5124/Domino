#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "Dom_PUCRAFT_View.h"
#include "Dom_PUCRAFT_Controller.h"
#include "Dom_PUCRAFT_Model.h"

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
	printf("    #	1) Iniciar novo Jogo(JxJ)	            #\n");
	printf("    #	2) Iniciar novo Jogo(JxC)		    #\n");
	printf("    #	3) Continuar a Jogar			    #\n");
	printf("    #	4) Salvar Jogo				    #\n");
	printf("    #	5) Carregar Jogo			    #\n");
	printf("    #	6) Regras do Jogo			    #\n");
	printf("    #	7) Sair do Jogo				    #\n");
	printf("    #	8) Creditos				    #\n");
	printf("    #################################################\n");

    printf("\nOpcao selecionada:");

	scanf("%d",&escolha);

	return escolha;
}

int subMenu()
{
    int opcao;

    printf("Qual acao voce deseja realizar agora? \n [1] = Jogar \n [2] = Comprar \n [3] = Passar \n [4] = Regras \n [5] = Esconder a mao \n [6] = Mostrar mao \n [7] = Sair para o menu.\n\n");

    printf("\nOpcao selecionada:");
    scanf("%d",&opcao);

    return opcao;
}

int qualLado()
{
    int resposta;

    printf("\nQual lado da mesa voce deseja jogar a peca? (1 = Esquerda) (2 = Direita)\n");

    printf("\nOpcao selecionada:");
    scanf("%d",&resposta);

    return resposta;
}

void mostrarMao(int jogador)
{
    int i = 1,cont = 1;
    printf("=============\n");
    printf("  JOGADOR %d  ",jogador);
    printf("\n=============\n");
    for(i;i<=28;i++)
    {
        if(pecasDomino[i].status==jogador)
        {
            printf("%d.|%d/%d|  ",cont,pecasDomino[i].lado1,pecasDomino[i].lado2);
            cont++;
        }
    }

    printf("\n\n");
}

void apresentaMesa()
{
    printf("\n    MESA\n");
    printf("==============\n\n");

    for(int cont=1;cont<=mesa[0].numeroDePecas;cont++)
    {
        printf("|%d/%d| ",mesa[cont].ladoE,mesa[cont].ladoD);
    }

    printf("\n\n==============");

    printf("\n\n");
}

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

void qualOpcao()
{
    printf("\nQual opcao voce deseja fazer: nao embaralhas(0) ou embaralhar(1), para caso queira voltar ao menu digite(2)\n");
    printf("\nOpcao selecionada:");
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
		printf("\n\nHerobrine diz: Capuccino melhor que cafe. \n\n");
}

void vitoria() //(EM MANUTEN��O)
{
printf("\n==============================\n");
printf("PARABENS JOGADOR,VOCE GANHOU!!");
printf("\n==============================\n");
printf("    AQUI ESTA SEU PREMIO");
printf("\n           ||          \n");
printf("           ||          \n");
printf("           ||          \n");
printf("           ||          \n");
printf("         __||__       \n");
printf("         \\    /       ");
printf("\n          \\  /       ");
printf("\n           \\/       ");
printf("\n       ___________    \n");
printf("      '._==_==_=_.'  \n");
printf("      .-\\:      /-.  \n");
printf("     | (|:.     |) | \n");
printf("      '-|:.     |-'  \n");
printf("        \\::.    /     \n");
printf("         '::. .'      \n");
printf("           ) (        \n");
printf("         _.' '._      \n");
}

void regras()
{
        printf("\n\n_____________________________ R E G R A S _____________________________ \n\n");
		printf("--> Inicio da Partida:\n-Sao compradas 7 pedras por ");
		printf("jogador. As 14 pedras restantes serao \nusadas para comprar ");
		printf("no caso do jogador nao ter a pedra da vez.\n_______________________________________________________________________\n\n");
		printf("--> Regra Numero 1:\nO jogador com a maior pedra (6-6) comeca o jogo,");
		printf(" colocando-a na mesa.\nCaso nenhum dos jogadores tenha a pedra 6x6, inicia");
		printf(" o 5x5, 4x4, 3x3,\n2x2, 1x1, 0x0 ou a pedra com maior numero de pontos, ");
		printf("nesta ordem.\n_______________________________________________________________________\n\n");
		printf("--> Regra Numero 2:\nCada jogador deve tentar encaixar uma de suas pedras ");
		printf("nas extremidades\ndo jogo na mesa.\nQuando o jogador nao consegue encaixar uma pedra, ");
		printf("ele compra uma da pilha.\n_______________________________________________________________________\n\n");
		printf("--> Regra Numero 3:\nO jogo acaba quando algum jogador fica sem pedras na\n");
		printf("mao, ou o jogo fica fechado.\n_______________________________________________________________________\n\n\n\n");
}

void aviso()
{
    printf("\n==========================================\n");
    printf("AVISO : Por favor escolha uma opcao valida!");
    printf("\n==========================================\n");
}
