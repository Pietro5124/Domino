#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void opcoesMenu()
{
    int escolha,SimNao[1];
    int lado1,lado2;
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

        defineLados(lado1,lado2,status);
        opcoesEmbaralhaOuArrumar(SimNao);

	    switch(SimNao[0])
	    {
        case 0: defineLados(lado1,lado2,status);
                mostraPecas(lado1,lado2);
                break;

        case 1: embaralhaPeca(pecasDomino,aux);
                mostraPecas(lado1,lado2);
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

