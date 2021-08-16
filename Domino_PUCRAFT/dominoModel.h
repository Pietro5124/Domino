#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

typedef struct peca{

    int lado1,lado2;
    int status;
    int mao1,mao11,mao2,mao22;

}pecas;

typedef struct m{

    int ladoE,ladoD;

}tabuleiro;

pecas pecasDomino[29];
pecas aux[29];

tabuleiro mesa[28];

void defineLados();
void embaralhaPeca(pecas pecasDomino[],pecas aux[]);
int opcoesEmbaralhaOuArrumar(int SimNao[]);
void comprar();
int jogar1(int peca1);
int jogar2(int peca2);

#endif // MODEL_H_INCLUDED
