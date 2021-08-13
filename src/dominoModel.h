#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

typedef struct peca{

    int lado1,lado2;
    char status;

}pecas;

pecas pecasDomino[29];
pecas aux[29];

int defineLados(int lado1,int lado2,char status);
void embaralhaPeca(pecas pecasDomino[],pecas aux[]);
int opcoesEmbaralhaOuArrumar(int SimNao[]);

#endif // MODEL_H_INCLUDED
