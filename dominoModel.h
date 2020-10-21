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
        int lado1;              //valor do lado 1 da peca
        int lado2;              //valor do lado 2 da peca
        int status;             //indica onde a peca esta no jogo(Mesa, Baralho, Jogador 1 ou 2)
};

typedef struct pecas peca;

struct mesa{
        int lado_par;           //que valor esta no lado par da mesa (ponta direita da mesa)
        int lado_impar;         //que valor esta no lado impar da mesa (ponta esquerda da mesa)
        int njogadores;         //numero de jogadores do jogo
        int jogador_vantagem;   //qual jogador (1 ou 2) jogou a primeira peca no jogo
        int turno;              //indica de qual Jogador eh o turno
};

typedef struct mesa mesa;

void cria_pecas(peca p[28]);

void embaralhar(peca vet[], int tamanho);

void distribuir_pecas(peca pecas_embaralhadas[28]);

int primeira_peca(peca p[28], mesa *m);

int comprar(peca p[28], int jogador);

int verificar_compra(peca p[28]);

int verificar_jogada(mesa *m, peca p[28], int jogador, int escolha);

void coloca_lado_escolhido(mesa *m, peca p[28], int jogador, int escolha, int lado);

void trocar_lado_peca(peca *p);

int trocar_turno(int turno);

int verificar_vitoria(peca p[28], mesa m, int jogadorVantagem);

int jogada_computador(mesa *m, peca p[28]);

int verificar_peca_jogavel(peca p, mesa m);

void reseta_status(peca p[28]);

#endif
