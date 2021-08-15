#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "Dom_PUCRAFT_View.h"
#include "Dom_PUCRAFT_Controller.h"
#include "Dom_PUCRAFT_Model.h"

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
        r = rand() % 28;

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

void comprar()
{
    int i,j;

    for(i=1; i <= 7;i++)
    {
        pecasDomino[i].mao1 = pecasDomino[i].lado1;

        pecasDomino[i].mao11 = pecasDomino[i].lado2;

    }

    for(j=8; j <= 14;j++)
    {
        pecasDomino[j].mao2 = pecasDomino[j].lado1;
        pecasDomino[j].mao22 = pecasDomino[j].lado2;
    }
}
