#include <stdio.h>
#include "Listapecas.c"

int main(void){
    Pecas* peca;
    peca = cria_lista();
    int f;

    struct pecas auxiliar_pecas;

    //criando as pecas
    for(int i =0; i <=6; i++){
        for(int j = i; j<=6; j++){
            auxiliar_pecas.lado1 = i;
            auxiliar_pecas.lado2 = j;
            f = insere_final(peca, auxiliar_pecas);
            if( f == 1){
                printf("i = %d j = %d\n", i,j);
            }
        }
    }

    for(int i =0; i< 28; i++){
        f = elemento_posicao(peca, i, &auxiliar_pecas);
        printf("peca: %d %d\n", auxiliar_pecas.lado1, auxiliar_pecas.lado2);
    }
    //embaralhando as pecas:
    
    
}