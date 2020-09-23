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
        char posicao; //0 esta disponivel para compra //1 esta na mesa //2 esta com um dos jogadores //3 esta com o outro jogador
};
typedef struct pecas tipo_peca;

void cria_pecas(tipo_peca p[28]);
void embaralhar(tipo_peca *vet, int tamanho);

#endif 