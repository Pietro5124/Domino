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

void distribuirPeca()
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

int definirComeco()
{
        int maior=0;
        int aux;

        for(int i=1; i <=28;i++)
        {
            if (((pecasDomino[i].status == 1)||(pecasDomino[i].status == 2))&&((pecasDomino[i].lado1==pecasDomino[i].lado2)&&(maior<pecasDomino[i].lado1)))
            {
               maior=i;
            }
        }

        mesa[1].ladoE = pecasDomino[maior].lado1;
        mesa[1].ladoD = pecasDomino[maior].lado2;

        mesa[1].numeroDePecas = 1;

        aux = pecasDomino[maior].status;

        pecasDomino[maior].status = 4;

        return(aux);
}

void jogar(int jogador)
{
    int peca;

    scanf("%d",&peca);

    pecasDomino[peca].status = 4;

    mesa[1].numeroDePecas++;

    return;
}

void decideJogadores()
{
    printf("Quantos jogadores você gostaria de incluir?\n");

}

void comprar()
{

}

void passar()
{

}
