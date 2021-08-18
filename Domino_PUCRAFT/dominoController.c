#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void opcoesMenu()
{
    int escolha,SimNao[3],jogo;
    int lado1,lado2,mao1,mao2,peca1,peca2,jogador;
    char status;

    while(escolha != 6)
    {
    if(escolha != 1)
    {
        escolha = menu(escolha);
    }

	switch(escolha)
	{
	case 1://usar fout=fopen("data.txt","w"); para criar um txt que simboliza o save

        defineLados();
        decideJogadores();
        opcoesEmbaralhaOuArrumar(SimNao);

	    switch(SimNao[0])
	    {
        case 0: defineLados();
                mostraPecas();
                break;

        case 1: embaralhaPeca(pecasDomino,aux);
                mostraPecas();
                comprar();
                jogador=definircomeco();
                printf("%d",jogador);
                jogador=1;
                while(jogador<=3)
                {
                    apresentaMesa();
                    mostrarMao(jogador);
                    jogador++;

                }




                break;

        case 2: escolha = 8;

        default:break;
	    }

		break;
	case 2:

		break;

	case 3:

		break;
	case 4:
		//usar fin=fopen("data.txt","r"); para carregar um txt
		break;
	case 5: //Regras

		regras();
        break;
	case 6: //Finalizar programa
		break;
	case 7: //Creditos

        creditos();
		break;
	default: break;

	}
	}
}

