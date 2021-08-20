#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

typedef struct peca{

    int lado1,lado2;
    int status;

}pecas;

typedef struct m{

    int ladoE,ladoD;
    int numeroDePecas;

}tabuleiro;

pecas pecasDomino[29];
pecas aux[29];

tabuleiro mesa[29];

void defineLados();
void embaralhaPeca(pecas pecasDomino[],pecas aux[]);
int opcoesEmbaralhaOuArrumar(int SimNao[]);
void distribuirPeca();
void comprar();
void decideJogadores();
int definirComeco();
void jogar(int);
void passar();
int troca(int);


#endif // MODEL_H_INCLUDED
