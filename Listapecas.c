#include <stdio.h>
#include <stdlib.h>
#include "Listapecas.h"

//definicao do como eh a minha lista de pecas
struct elemento{
    struct pecas info;
    struct elemento *prox;
};

typedef struct elemento Elem;

Pecas* cria_lista(){
    Pecas* pe = (Pecas*) malloc (sizeof(Pecas));
    if(pe != NULL){
        *pe = NULL;
    }
    return pe;
}

void libera_lista(Pecas *pe){
    if(pe != NULL){
        Elem *no;
        while((*pe) != NULL){
            no = *pe;
            *pe = (*pe)->prox;
            free(no);
        }
        free(pe);
    }
}

int tamanho_lista(Pecas *pe){
    if(pe == NULL){
        return 0;
    }
    int cont =0;
    Elem *no = *pe;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int insere_final(Pecas *pe, struct pecas pel){
    if(pe == NULL){
        return 0;
    }
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->info = pel;
    no->prox = NULL;
    if((*pe) == NULL){
        *pe = no;
    }else{
        Elem *aux;
        aux = *pe;
        while ((aux->prox != NULL)){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_ordenada(Pecas* pe, struct pecas pel){
    if(pe == NULL){
        return 0;
    }
    Elem * no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->info = pel;
    if((*pe) == NULL){
        no->prox = NULL;
        *pe = no;
        return 1;
    }else{
        Elem *ant, *atual = *pe;
        while(atual != NULL && (atual->info.lado1 + atual->info.lado2) < (pel.lado1 +pel.lado2)){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *pe){
            no->prox = (*pe);
            *pe = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        
        return 1;
        
    }
    
}

int removendo(Pecas *pe, int ladoA, int ladoB){
    if(pe == NULL){
        return 0;
    }
    if((*pe) == NULL){
        return 0;
    }
    Elem *ant, *no = *pe;
    while( no != NULL && no->info.lado1 != ladoA && no->info.lado2 != ladoB){
        ant = no;
        no = no->prox;
    }
    if( no == NULL){ //esse elemento nao existe
        return 0;
    }

    if(no == *pe){
        *pe = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    
    return 1;

}

int elemento_posicao(Pecas* pe, int pos, struct pecas *pec){
    if(pe == NULL || pos< 0){
        return 0;
    }
    Elem *no = *pe;
    int i =0;
    while(no != NULL && i <pos){
        i++;
        no=no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *pec = no->info;
        return 1;
    }
    
    
}