#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void mostraPecas();
int menu(int escolha);
void regras();
void creditos();
void qualOpcao();
void mostrarMao(int);
void apresentaMesa();
int subMenu(int opcao[]);

#endif // VIEW_H_INCLUDED
