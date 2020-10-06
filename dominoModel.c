/*
Arquivo Main.c:
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: implementacao da biblioteca model.h.

*/

#include "dominoModel.h"

//responsavel pela criacao de pecas
void cria_pecas(peca p[28]){
    //variaveis
    int index = 0;

    for(int i=0; i<=6; i++){
        for(int j =i; j<=6; j++){
            p[index].lado1 = i;
            p[index].lado2 =j;
            p[index].status =0;
            index++;
        }
    }

}

void reseta_status(peca p[28]){
    int i;
    for (int i = 0; i < 28; ++i) {p[i].status = 0;}
}

//funcao para embaralhar as pecas
void embaralhar(peca vet[28], int tamanho){
    srand(time(NULL));
	for (int i = 0; i < tamanho; i++)
	{
		int r = rand() % tamanho;
        peca auxiliar = vet[i];
		vet[i] = vet[r];
		vet[r] = auxiliar;
	}
}

void distribuir_pecas(peca p[28]){
    int i;
    for(i =0; i <7; i++){
        p[i].status = 1;
    }
    for(i =7; i <14; i++){
        p[i].status = 2;
    }
}

int primeira_peca(peca p[28], mesa *m){
    int i = 0, somaAux;
    while(p[i].status != 1 && p[i].status != 2){i++;}
    int maior = p[i].lado1 + p[i].lado2, pm = i;
    int maiorI = -1, pmi = -1;

    for(int c = i; c < 28; c++){
        if (p[c].status == 1 || p[c].status == 2){
            somaAux = p[c].lado1 + p[c].lado2;
            if(p[c].lado1 == p[c].lado2){
                if (somaAux > maiorI){
                    maiorI = somaAux;
                    pmi = c;
                }
            }
            else{
                if (somaAux > maior){
                    maior = somaAux;
                    pm = c;
                }
            }
        }
    }
    if (pmi == -1){
        m->turno = trocar_turno(p[pm].status);
        m->jogador_vantagem = p[pm].status;
        p[pm].status=3;
        m->lado_impar =p[pm].lado1;
        m->lado_par=p[pm].lado2;
        return pm;
    }
    else{
        m->turno = trocar_turno(p[pmi].status);
        m->jogador_vantagem = p[pmi].status;
        p[pmi].status=3;
        m->lado_impar =p[pmi].lado1;
        m->lado_par=p[pmi].lado2;
        return pmi;
    }
}

int encontrar_primeira_peca(peca p[28]){
    int i = 0;
    while (i<28){
        if (p[i].status == 3){
            i++;
            return i;
        }
    }
}

int comprar(peca p[28], int jogador, mesa *m){
    int i;
    for(i =0; i<28; i++){
        if(p[i].status == 0){
            p[i].status = jogador;
            return 1;
        }
    }
    return 0;
}


int verificar_jogada(mesa *m, peca p[28], int jogador, int escolha){
    int contador = 1, contador_par = 0, contador_impar = 0, i, peca_jogada;

    if(jogador != m->turno){
        return 0;
    }

    for(i =0; i < 28; i++){
        if(p[i].status == jogador){
            if(contador == escolha){
                peca_jogada = i;
                contador++;
            } else{contador++; }
        }
        if((p[i].status %2) != 0 && p[i].status >3 ){
            contador_impar++;

        }else if ((p[i].status %2) == 0 && p[i].status >2){
            contador_par++;
        }
    }

    if(p[peca_jogada].lado1 == m->lado_impar){
        trocar_lado_peca(&p[peca_jogada]);
        p[peca_jogada].status = 5 + (2*contador_impar);
        m->lado_impar = p[peca_jogada].lado1;
        m->turno = trocar_turno(jogador);
        return 1;
    }
    else if(p[peca_jogada].lado2 == m->lado_impar){
        p[peca_jogada].status = 5 + (2*contador_impar);
        m->lado_impar = p[peca_jogada].lado1;
        m->turno = trocar_turno(jogador);
        return 1;
    }
    else if(p[peca_jogada].lado1 == m->lado_par){
        p[peca_jogada].status = 4 + (2*contador_par);
        m->lado_par = p[peca_jogada].lado2;
        m->turno = trocar_turno(jogador);
        return 1;
    }
    else if (p[peca_jogada].lado2 == m->lado_par){
        trocar_lado_peca(&p[peca_jogada]);
        p[peca_jogada].status = 4 + (2*contador_par);
        m->lado_par = p[peca_jogada].lado2;
        m->turno = trocar_turno(jogador);
        return 1;
    } else return 0;
}

void trocar_lado_peca(peca *p){
    int aux = p->lado1;
    p->lado1 = p->lado2;
    p->lado2 = aux;
}

int trocar_turno(int turno){
    if(turno == 1){
        return 2;
    } else return 1;
}

int verificar_vitoria(peca p[28], mesa m, int jogadorVantagem){
    int i, pecaJogavel1=0, pecaJogavel2=0, somaJ1=0, somaJ2=0, nPecasJ1=0, nPecasJ2=0;
    for(i = 0; i<28; i++){
        if (p[i].status == 1){
            nPecasJ1++;
            somaJ1 += p[i].lado1 + p[i].lado2;
            if (verificar_peca_jogavel(p[i], m)){
                pecaJogavel1++;
            }
        }
        else if (p[i].status == 2){
            nPecasJ2++;
            somaJ2 += p[i].lado1 + p[i].lado2;
            if (verificar_peca_jogavel(p[i], m)){
                pecaJogavel2++;
            }
        }
    }
    if(somaJ1 == 0 && nPecasJ1 == 0){return 1;}
    if(somaJ2 == 0 && nPecasJ2 == 0){return 2;}
    if ((pecaJogavel1+pecaJogavel2)==0 && verificar_compra(p) == 0){
        if (somaJ1<somaJ2){return 1;}
        if(somaJ2<somaJ1){return 2;}
        if(somaJ1==somaJ2){return jogadorVantagem;}
    }
    return 0;
}

int verificar_peca_jogavel(peca p, mesa m){
    int l1 = p.lado1;
    int l2 = p.lado2;
    if(l1 == m.lado_impar || l1 == m.lado_par || l2 == m.lado_impar || l2 == m.lado_par){
        return 1;
    } else return 0;
}

int verificar_compra(peca p[28]){
    int i;
    for (int i = 0; i < 28; i++) {
        if (p[i].status == 0){return 1;}
    }
    return 0;
}