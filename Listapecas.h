#include <stdio.h>
#include <stdlib.h>
struct pecas{
    int lado1;
    int lado2;
};

typedef struct elemento* Pecas;

Pecas* cria_lista();

void libera_lista(Pecas* pe);

int insere_final(Pecas* pe, struct pecas pel);

int insere_ordenada(Pecas* pe, struct pecas pel);

int removendo(Pecas* pe, int ladoA, int ladoB);

int tamanho(Pecas* pe);

void libera_lista(Pecas *pe);

int elemento_posicao(Pecas* pe, int pos, struct pecas *pec);


