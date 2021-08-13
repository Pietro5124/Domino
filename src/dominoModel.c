#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

int defineLados(int lado1,int lado2,char status)
{
    int k = 0,j = 0, i = 1;

    for(j;j<7;j++)
    {
        k=j;
        for(k;k<7;k++)
        {
            pecasDomino[i].lado1 = j;
            pecasDomino[i].lado2 = k;
            i++;
        }
    }
    return lado1,lado2,status;
}
void embaralhaPeca(pecas pecasDomino[],pecas aux[])
{
    srand(time(NULL));
    int r;

    for (int i=1; i <= 28; i++)
    {
        r = rand() % 29;

        aux[0] = pecasDomino[i];
        pecasDomino[i] = pecasDomino[r];
        pecasDomino[r] = aux[0];
    }
}

int opcoesEmbaralhaOuArrumar(int SimNao[])
{
    qualOpcao();
    scanf("%d",&SimNao[0]);

    return SimNao;
}
