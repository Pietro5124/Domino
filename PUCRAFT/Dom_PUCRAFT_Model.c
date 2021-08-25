#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "Dom_PUCRAFT_Controller.h"
#include "Dom_PUCRAFT_Model.h"

int opcoesEmbaralhaOuArrumar()
{
    int SimNao;

    scanf("%d",&SimNao);

    return SimNao;
}

int definirComeco()
{
        int maior=0;
        int aux;

        for(int i=1; i <=28;i++) //Passando por todas a pe�as.
        {   //Verificando qual � a maior pe�a e na m�o de qual jogador est�.
            if (((pecasDomino[i].status == 1)||(pecasDomino[i].status == 2))&&((pecasDomino[i].lado1==pecasDomino[i].lado2)&&(pecasDomino[maior].lado1<=pecasDomino[i].lado1)))
            {
               maior=i;
            }
        }
        //Igualando a primeira pe�a da mesa a maior pe�a definida anteriormente.
        mesa[1].ladoE = pecasDomino[maior].lado1;
        mesa[1].ladoD = pecasDomino[maior].lado2;

        mesa[0].numeroDePecas = 1; //Definindo inicialmente o tamanho da mesa como 1.

        aux = pecasDomino[maior].status; //Definindo o aux como o mesmo valor de status pois vamos colocar essa pe�a na mesa.

        pecasDomino[maior].status = 4; //Colocando a pe�a na mesa.

        return(aux);
}

int troca(int aux)
{
   if(aux == 1)
    {
        aux = 2;
    }else
    {
        aux = 1;
    }

    return aux;
}

void embaralhaPeca(pecas pecasDomino[],pecas aux[])
{
    srand(time(NULL)); //Gerando uma seed aleat�ria.
    int r;

    for (int i=1; i <= 28; i++)
    {
        r = rand() % 28; //Gerando valores aleat�rios at� 28.

        //Fazendo uma troca.
        aux[0] = pecasDomino[i];
        pecasDomino[i] = pecasDomino[r];
        pecasDomino[r] = aux[0];
        //Definindo todas as pe�as como na pilha.
        pecasDomino[i].status = 0;
    }
}

void inverteLado(int ladoMesa,int aux2)
{
    int aux;

   if(pecasDomino[aux2].lado2 != mesa[2].ladoE && ladoMesa == 1) //Testando para ver se as pe�as podem se conectar.
   {
        aux = mesa[1].ladoE;
        mesa[1].ladoE = mesa[1].ladoD;
        mesa[1].ladoD = aux;

   }else if((pecasDomino[aux2].lado1 != mesa[mesa[0].numeroDePecas].ladoD) && (ladoMesa == 2))//Testando para ver se as pe�as podem se conectar.
   {
        aux = mesa[mesa[0].numeroDePecas+1].ladoE;
        mesa[mesa[0].numeroDePecas+1].ladoE = mesa[mesa[0].numeroDePecas+1].ladoD;
        mesa[mesa[0].numeroDePecas+1].ladoD = aux;
   }
}

void comprar(int jogador)
{
    int j = 1,i;
    int aux[29];

    //Estamos definindo o aux como a m�o atual do jogador atual.
    for(i=1;i<=28;i++)
    {
        if(pecasDomino[i].status==3)
        {
            aux[j] = i;
            j++;
        }
    }
    //Defindo que a pe�a que estava na pilha est� na m�o do jogador.
    pecasDomino[aux[1]].status = jogador;
}

void jogar(int jogador)
{
    int i[1],j = 1,k = mesa[0].numeroDePecas+1;
    int aux[30],aux2;
    int ladoMesa,peca;

    while(1)
    {

    printf("\nEscolha o numero da peca que deseja jogar:");

    scanf("%d",&peca);
    //Estamos definindo o aux como a m�o atual do jogador atual.
    for(i[0]=1;i[0]<=28;i[0]++)
    {
        if(pecasDomino[i[0]].status==jogador)
        {
            aux[j] = i[0];
            j++;
        }
    }
    //Tirando a pe�a da m�o do jogador.
    mesa[jogador].mao = j-1;
    aux2 = aux[peca];
    //Teste para ver se a pe�a � v�lida ou n�o.
    if(mesa[mesa[0].numeroDePecas].ladoD == pecasDomino[aux[peca]].lado1 || mesa[mesa[0].numeroDePecas].ladoD == pecasDomino[aux[peca]].lado2 || mesa[1].ladoE == pecasDomino[aux[peca]].lado2 || mesa[1].ladoE == pecasDomino[aux[peca]].lado1)
    {
    //Pegando o lado que a pessoa escolheu.
    ladoMesa = qualLado();
    //Se for o lado esquerdo entra nesse if.
    if(ladoMesa == 1 && (mesa[1].ladoE == pecasDomino[aux[peca]].lado2 || mesa[1].ladoE == pecasDomino[aux[peca]].lado1) )
    {

        for(k;k>1;k--)
        {
           mesa[k] = mesa[k-1];
        }

        mesa[1].ladoE = pecasDomino[aux2].lado1;
        mesa[1].ladoD = pecasDomino[aux2].lado2;

        inverteLado(ladoMesa,aux2);
    //Sen�o entra nesse if se for lado direito.
    }else if(ladoMesa == 2 && (mesa[mesa[0].numeroDePecas].ladoD == pecasDomino[aux[peca]].lado2 || mesa[mesa[0].numeroDePecas].ladoD == pecasDomino[aux[peca]].lado1))
    {
        mesa[mesa[0].numeroDePecas+1].ladoE = pecasDomino[aux[peca]].lado1;
        mesa[mesa[0].numeroDePecas+1].ladoD = pecasDomino[aux[peca]].lado2;

        inverteLado(ladoMesa,aux2);
    }else //Se n�o poder entrar em nenhum dos lado a pe�a ser� invalida.
    {
        aviso();
        continue;
    }
    //Mudando o status da pe�a para a mesa.
    pecasDomino[aux[peca]].status = 4;
    //Aumentando o tamanho da mesa.
    mesa[0].numeroDePecas++;

    break;
    }
    else //Caso a pe�a seja invalida logo de cara entra aqui.
    {
        aviso();
        continue;
    }
    }
    return;
}

void distribuirPeca()
{
    int i,j;

    for(i=1; i <=28;i++)
    {
        if(i<=7)
        {
            pecasDomino[i].status = 1; //Pe�as para o jogador 1.

        }
        if(i>=8 && i<=14)
        {
            pecasDomino[i].status = 2; //Pe�as para o jogador 2.
        }
        if(i>14)
        {
            pecasDomino[i].status = 3; //Pe�as para a pilha.
        }

    }
}

void defineLados()
{
    int k = 0,j = 0, i = 1;

    for(j;j<7;j++)
    {
        k=j;
        for(k;k<7;k++) //Definindo os lados de cada pe�a, organizando elas.
        {
            pecasDomino[i].lado1 = j;
            pecasDomino[i].lado2 = k;
            i++;
            pecasDomino[i].status = 0;
        }
    }
}
