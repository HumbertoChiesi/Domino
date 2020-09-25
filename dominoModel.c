/*
Arquivo Main.c: 
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: implementacao da biblioteca model.h.

*/

#include "dominoModel.h"

//responsavel pela criacao de pecas
void cria_pecas(tipo_peca p[28]){
    //variaveis
    int index = 0;

    for(int i=0; i<=6; i++){
        for(int j =i; j<=6; j++){
            p[index].lado1 = i;
            p[index].lado2 =j;
            index++;
            
        }
    }

}

//funcao para embaralhar as pecas
void embaralhar(tipo_peca *vet, int tamanho){
    srand(time(NULL));
	for (int i = 0; i < tamanho; i++)
	{
		int r = rand() % tamanho;

		struct pecas auxiliar = vet[i];
		vet[i] = vet[r];
		vet[r] = auxiliar;
	}
}

void distribuir_pecas(tipo_peca pecas_embaralhadas[28]){
    int i;
    for(i =0; i <7; i++){
        pecas_embaralhadas[i].posicao = 1;
    }
    for(i =7; i <14; i++){
        pecas_embaralhadas[i].posicao = 2;
    }
}

int primeira_peca(tipo_peca p[28])
{
    int i = 0, somaAux;
    while(p[i].posicao != 1 && p[i].posicao != 2){i++;}
    int maior = p[i].lado1 + p[i].lado2, pm = i;
    int maiorI = -1, pmi = -1;

    for(int c = i; c < 28; c++)
    {
        if (p[c].posicao == 1 || p[c].posicao == 2)
        {
            somaAux = p[c].lado1 + p[c].lado2;
            if(p[c].lado1 == p[c].lado2)
            {
                if (somaAux > maiorI)
                {
                    maiorI = somaAux;
                    pmi = c;
                }
            }
            else
            {
                if (somaAux > maior)
                {
                    maior = somaAux;
                    pm = c;
                }
            }
        }
    }
    if (pmi == -1)
    {
        return pm;
    } else return pmi;
}