#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void opcoesMenu()
{
    int escolha,SimNao[3],opcao[1];
    int lado1,lado2,peca,jogador;
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
        //decideJogadores();
        opcoesEmbaralhaOuArrumar(SimNao);

	    switch(SimNao[0])
	    {
        case 0: defineLados();
                mostraPecas();
                break;

        case 1: embaralhaPeca(pecasDomino,aux);
                mostraPecas();
                distribuirPeca();
                jogador=definirComeco();
                printf("\n|Jogador que ira iniciar sera :%d| \n\n",jogador);

                jogador = troca(jogador);

                while(jogador != 5)
                {
                    apresentaMesa();
                    mostrarMao(jogador);

                    subMenu(opcao);

                    switch(opcao[0])
                    {
                        case 1: jogar(jogador);

                                if(jogador == 1)
                                {
                                    jogador = 2;
                                }else if(jogador == 2)
                                {
                                    jogador = 1;
                                }

                                break;

                        case 2: comprar();
                                break;

                        case 3: passar();
                                break;

                        case 4: jogador = 5;
                                escolha = 8;
                                break;
                    }
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

