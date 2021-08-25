#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include "Dom_PUCRAFT_View.h"
#include "Dom_PUCRAFT_Controller.h"
#include "Dom_PUCRAFT_Model.h"

int menu(); //Printando o menu e devolvendo a op��o escolhida.
int subMenu(); //Printando o submenu e devolvendo a op��o escolhida.
int qualLado(); //Printando o menu de qual lado o jogador escolheu e devolvendo a op��o escolhida.

void mostrarMao(int); //Printando printando a m�o do jogador.

void apresentaMesa(); //Printando printando a mesa.
void mostraPecas(); //Printando as pe�as.
void qualOpcao(); //Printando as op�oes que tem.
void creditos(); //Printando os cr�ditos.
void vitoria(); //Printando a recompensa por ganhar . . . (SEGREDO).
void regras(); //Printando as regras.
void aviso(); //Printando um aviso caso a pessoa tenha feito algo errado.


#endif // VIEW_H_INCLUDED
