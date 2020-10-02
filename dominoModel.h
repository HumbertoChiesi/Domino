/*
Arquivo model.h:
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: Arquivo de biblioteca com as funcoes disponiveis para o model. Parte responsavel pela manipulacao de dados.

*/

#ifndef DOMINOMODEL_H_
#define DOMINOMODEL_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




struct pecas{
        int lado1;
        int lado2;
        int status; //0 esta disponivel para compra //1 esta com o primeiro jogador //2 esta com o segundo jogador //3 esta no centro da mesa
};

typedef struct pecas peca;

struct mesa{

        int lado_par;
        int lado_impar;
        int njogadores;
        int turno;
};

typedef struct mesa mesa;

void cria_pecas(peca p[28]);

void embaralhar(peca vet[], int tamanho);

void distribuir_pecas(peca pecas_embaralhadas[28]);

int primeira_peca(peca p[28], mesa *m);

int comprar(peca p[28], int jogador, mesa *m);

int verificar_jogada(mesa *m, peca p[28], int jogador, int escolha);

void trocar_lado_peca(peca *p);

int trocar_turno(int turno);

int verificar_vitoria(peca p[28], mesa m, int jogadorVantagem);

int verificar_peca_jogavel(peca p, mesa m);

int verificar_compra(peca p[28]);

#endif
