#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "Dom_PUCRAFT_Controller.h"
#include "Dom_PUCRAFT_Model.h"

typedef struct peca{

    int lado1,lado2; //Lado Esquerdo e Direito da pe�a na m�o do jogador e na pilha.
    int status; //Status define onde esta a pe�a sendo: [0 = Pilha] [1 = Jogador1] [2 = Jogador2] [3 = M�o] [4 = Mesa].

}pecas; //Este struct � tudo o que tem haver com o jogador.

typedef struct m{

    int ladoE,ladoD; //Lado Esquerdo e Direito da pe�a na mesa.
    int numeroDePecas; //Numero de pe�as total na mesa.
    int mao; //Esta varivel � um contador de quantas pe�as tem na m�o do jogador.

}tabuleiro; //Este struct � tudo o que tem haver com a mesa.

pecas pecasDomino[29]; //Todas as pe�as do domino, s�o 28 no totais, colocamos 29 para numerarmos de 1 a 28.
pecas aux[29]; //Vari�vel auxiliar.

tabuleiro mesa[29]; //Total de pe�as que pode ter na mesa, sendo 28 no total, colocamos 29 pelo motivo citado acima.

int opcoesEmbaralhaOuArrumar(); //Essa fun��o scaneia se a pessoa deseja embaralhar ou n�o.
int definirComeco(); //Define qual vai ser o jogador que ira iniciar, colocando sua pe�a ja na mesa.
int troca(int); //Efetua uma troca. Ex: x[0] = 1 , y[0] = 2 ap�s essa fun��o ficaria x[0] = 2 , y[0] = 1;

void embaralhaPeca(pecas pecasDomino[],pecas aux[]); //Essa fun��o embaralha as pe�as da pilha.
void inverteLado(int,int); //Esta fun��o troca o lado da pr�pria pe�a caso seja necessario para se adaptar a mesa.
void comprar(int); //Uma fun��o que efetua a compra.
void jogar(int); //Tudo por tras da op��o jogar est� dentro dest� fun��o.

void distribuirPeca(); //Distrui as pe�as para os jogadores.
void defineLados(); //Define o lado de cada pe�a, ou seja, organiza a pilha em ordem correta.

#endif // MODEL_H_INCLUDED
