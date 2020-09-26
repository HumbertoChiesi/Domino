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
        int posicao; //0 esta disponivel para compra //1 esta com o primeiro jogador //2 esta com o segundo jogador //3 esta no centro da mesa // 4 ate 2*n , ou seja, os numeros pares a partir do 4 estao do lado direito da mesa em ordem crescente // 5 ate 2*n +1, ou seja, os impares estao do lado esquerdo em ordem crescente
};

typedef struct pecas tipo_peca;

struct mesa{

        int lado_par;
        int lado_impar;
        int njogadores;

};

typedef struct mesa tipo_mesa;

void cria_pecas(tipo_peca p[28]);

void embaralhar(tipo_peca *vet, int tamanho);

void distribuir_pecas(tipo_peca pecas_embaralhadas[28]);

int primeira_peca(tipo_peca p[28], tipo_mesa *m);

void mudar_posicao(tipo_peca p[28], int indice, int posicao);

void comprar(tipo_peca p[28], int jogador);

int jogada(tipo_mesa *mesa, tipo_peca p[28], int jogador, int escolha);

#endif 