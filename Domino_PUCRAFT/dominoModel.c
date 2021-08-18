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

    for(i=1; i <=28;i++)
    {
        if(i<=7)
        {
            pecasDomino[i].status = 1;
        }
        if(i>=8 && i<=14)
        {
            pecasDomino[i].status = 2;
        }
        if(i>14)
        {
            pecasDomino[i].status = 3;
        }

    }
}
int definircomeco()
{
        int maior=0;
        for(int i=1; i <=28;i++)
        {
            if ((pecasDomino[i].status!=3)&&(pecasDomino[i].lado1==pecasDomino[i].lado2)&&(maior<pecasDomino[i].lado1))
            {
               maior=i;
            }
        }
        return(pecasDomino[maior].status);
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

void decideJogadores()
{
    printf("Quantos jogadores você gostaria de incluir?\n");

}

