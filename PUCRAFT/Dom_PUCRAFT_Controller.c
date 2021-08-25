#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "Dom_PUCRAFT_View.h"
#include "Dom_PUCRAFT_Controller.h"
#include "Dom_PUCRAFT_Model.h"

void opcoesMenu()
{
    int escolha,simNao,opcao;
    int lado1,lado2,peca,jogador;
    char status;

    while(escolha != 7) //Loop para ficar no menu principal.
    {
    if(escolha != 1) //Para quando voc� come�ar o jogo n�o ficar mostrando o menu.
    {
        escolha = menu(escolha);
    }

	switch(escolha) //Menu principal.
	{
	case 1:

        defineLados();
        qualOpcao();
        simNao = opcoesEmbaralhaOuArrumar();

	    switch(simNao) //Op��es para caso queira embaralhar, arrumar ou voltar ao menu principal.
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

                while(jogador != 3 && mesa[jogador].mao != 1) //Fica no submenu enquanto n�o acabar o jogo ou o jogador escolher acabar.
                {
                    apresentaMesa();
                    if(opcao != 5)
                    {
                      mostrarMao(jogador);
                    }

                    opcao = subMenu();

                    switch(opcao) //Submenu do jogo.
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

                        case 2: comprar(jogador);
                                break;

                        case 3: jogador = troca(jogador);
                                break;

                        case 4: regras();
                                break;


                        case 5: system("cls");
                                break;

                        case 6:
                                break;

                        case 7: jogador = 3;
                                escolha = 9;
                                break;
                    }

                   if(mesa[jogador].mao == 1)
                {
                    vitoria();
                    jogador = 3;
                    break;
                } //Est� em manuten��o.
                }

        case 2: escolha = 9;

        default:break;
	    }

		break;

	case 2: //Joga contra o computador (EM MANUTEN��O)

		break;

    case 3: //Continuar o jogo (EM MANUTEN��O)

        break;

	case 4: //Salvar o jogo (EM MANUTEN��O)

		break;

	case 5: //Carregar o jogo (EM MANUTEN��O)

		break;

	case 6: //Regras

		regras();

        break;

	case 7: //Finalizar programa

		break;

	case 8: //Creditos

        creditos();

		break;

	default: break;

	}
	}
}

