#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void opcoesMenu()
{
    int escolha,SimNao[3],jogo;
    int lado1,lado2,mao1,mao2,peca1,peca2;
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
        opcoesEmbaralhaOuArrumar(SimNao);

	    switch(SimNao[0])
	    {
        case 0: defineLados();
                mostraPecas();
                break;

        case 1: embaralhaPeca(pecasDomino,aux);
                mostraPecas();

                jogo = 1;

                if(jogo == 1)
                {
                    comprar();
                    mostrarMao1();
                    mostrarMao2();
                }

                peca1 = jogar1(peca1);
                peca2 = jogar2(peca2);

                apresentaMesa(peca1,peca2);

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

