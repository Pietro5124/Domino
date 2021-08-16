#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "dominoView.h"
#include "dominoController.h"
#include "dominoModel.h"

void defineLados()
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
            pecasDomino[i].status = 0;
        }
    }
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
        pecasDomino[i].status = 0;
    }
}

int opcoesEmbaralhaOuArrumar(int SimNao[])
{
    qualOpcao();
    scanf("%d",&SimNao[0]);

    return SimNao[0];
}

void comprar()
{
    int i,j;

    for(i=1; i <= 7;i++)
    {
        pecasDomino[i].mao1 = pecasDomino[i].lado1;

        pecasDomino[i].mao11 = pecasDomino[i].lado2;

        pecasDomino[i].status = 1;
    }

    for(j=8; j <= 14;j++)
    {
        pecasDomino[j-7].mao2 = pecasDomino[j].lado1;
        pecasDomino[j-7].mao22 = pecasDomino[j].lado2;

        pecasDomino[j].status = 2;
    }
}

int jogar1(int peca1)
{

    scanf("%d",&peca1);

    pecasDomino[peca1].status = 3;

    return peca1;
}

int jogar2(int peca2)
{

    scanf("%d",&peca2);

    pecasDomino[peca2].status = 3;

    return peca2;
}
