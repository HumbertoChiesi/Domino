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
            p[index].posicao =0;
            index++;
        }
    }

}

//funcao para embaralhar as pecas
void embaralhar(tipo_peca vet[28], int tamanho){
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

int primeira_peca(tipo_peca p[28], tipo_mesa *m)
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
    if (pmi == -1){
        p[pm].posicao=3;
        m->lado_impar =p[pm].lado1;
        m->lado_par=p[pm].lado2;
        return pm;
    }
    else{
        p[pmi].posicao=3;
        m->lado_impar =p[pmi].lado1;
        m->lado_par=p[pmi].lado2;
        return pmi;
    }
}

void mudar_posicao(tipo_peca p[28], int indice, int posicao){
    p[indice].posicao = posicao;
}

int jogada(tipo_mesa *mesa, tipo_peca p[28], int jogador, int escolha){
    
    int i, j, contador =0, contador_impar_par =0, aux;

    for(i =0; i<28; i++){
        if(p[i].posicao == jogador){
           
            contador += 1;
            if(contador == escolha){
                
                if(p[i].lado1 == mesa->lado_impar || p[i].lado2 == mesa->lado_impar){
                    
                    for(j =0; j<28; j++){
                        
                        if((p[j].posicao %2) != 0 && p[j].posicao > 3 ){
                            
                            contador_impar_par += 1;
                        }
                    }

                    p[i].posicao = 5 + (2 * contador_impar_par);
                    

                    if(p[i].lado1 == mesa->lado_impar){
                        aux = p[i].lado1;
                        p[i].lado1 = p[i].lado2;
                        p[i].lado2 = aux;
                        mesa->lado_impar = p[i].lado2;
                    }else{
                        mesa->lado_impar = p[i].lado1;
                        
                    }
                    return 1;
                }
                if(p[i].lado1 == mesa->lado_par || p[i].lado2 == mesa->lado_par){
                    
                    for(j =0; j<28; j++){
                        if((p[j].posicao %2) == 0 && p[j].posicao > 3){
                            
                            contador_impar_par += 1;
                        }
                    }
                    p[i].posicao = (2 * contador_impar_par) + 4;
                    if(p[i].lado1 == mesa->lado_par){
                        mesa->lado_par = p[i].lado2;
                    }else{
                        aux = p[i].lado1;
                        p[i].lado1 = p[i].lado2;
                        p[i].lado2 = aux;
                        mesa->lado_par = p[i].lado1;
                    }
                    return 1;
                }
                
            }
            
        }

    }


    return 0;
}

void comprar(tipo_peca p[28], int jogador){
    int i;
    for(i =0; i<28; i++){
        if(p[i].posicao == 0){
            p[i].posicao = jogador;
            break;
        }
    }
}