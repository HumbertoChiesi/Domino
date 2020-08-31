#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Estrutura que define uma peca do domino
struct pecas{
    int lado1;
    int lado2;
};

//funcao para embaralhar as pecas
void embaralharPecas(struct pecas *vet, int tamanho){
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++){
        int r = rand() % tamanho;

        struct pecas auxiliar = vet[i];
        vet[i] = vet[r];
        vet[r] = auxiliar;
    }
}

//funcao para imprimir as pecas
void mostrarPecas(struct pecas p[], int tamanho){
    char caux;
    int indice =0;

    printf("Deseja ver todas as pecas? (1 se sim, 0 se nao)\n");
    while(1){
        scanf("%s", &caux);
        if(caux == '1'){
            while (indice < tamanho){
                //imprimindo o domino na sequencia ordenada.
                printf("%2d. [%d|%d]\t", indice+1, p[indice].lado1, p[indice].lado2);
                indice++;
                if(indice % 7 == 0){
                    printf("\n");
                }
            }


            break;
        }
        else if (caux == '0'){
            break;
        }
        printf("Digite novamente se deseja ver as pecas: (1 se sim, 0 se nao)\n");
    }
}

//funcao que cria as pecas, ou seja, atribui valores para as pecas.
void criarPecas(struct pecas p[]){
    int index = 0;
    for(int i=0; i<=6; i++){
        for(int j =i; j<=6; j++){
            p[index].lado1 = i;
            p[index].lado2 =j;
            index++;
        }
    }
}

int main (void){

    //Definindo variaveis que serao usadas durante o programa.
    struct pecas pecas[28];
    struct pecas pecas_embaralhadas[28];

    //Criando as pecas do domino.
    criarPecas(pecas);

    //Copiando o array de pecas para as pecas organizadas, para que tenhamos um array com as pecas em ordem e um outro com as pecas embaralhadas.
    for(int i =0; i<28; i++){
        pecas_embaralhadas[i]=pecas[i];
    }

    //mostrando pecas
    mostrarPecas(pecas, 28);

    //embaralhando as pecas
    embaralharPecas(pecas_embaralhadas, 28);

}
