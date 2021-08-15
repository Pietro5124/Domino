#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "Dom_PUCRAFT_View.h"
#include "Dom_PUCRAFT_Controller.h"
#include "Dom_PUCRAFT_Model.h"

typedef struct peca{

    int lado1,lado2;
    char status;
    int mao1,mao11,mao2,mao22;

}pecas;

pecas pecasDomino[29];
pecas aux[29];

int defineLados(int lado1,int lado2,char status);
void embaralhaPeca(pecas pecasDomino[],pecas aux[]);
int opcoesEmbaralhaOuArrumar(int SimNao[]);
void comprar();

#endif // MODEL_H_INCLUDED
