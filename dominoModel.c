/*
Arquivo Main.c:
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: implementacao da biblioteca model.h.

*/

#include "dominoModel.h"

//responsavel pela criacao de pecas
void cria_pecas(peca p[28]){
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

//Reseta os status de todas as pecas do Domino
void reseta_status(peca p[28]){
    int i;
    for (i = 0; i < 28; ++i) {p[i].status = 0;}
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

//Distribui 7 pecas para o Jogador 1 e 7 pecas para o Jogador 2
void distribuir_pecas(peca p[28]){
    int i;
    for(i =0; i <7; i++){
        p[i].status = 1;
    }
    for(i =7; i <14; i++){
        p[i].status = 2;
    }
}

//Analisa de acordo com as regras do Domino que jogador tem a primeira peca e coloca a peca na mesa
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
        return m->jogador_vantagem;     //retorna qual jogador(1 ou 2) tem vantagem
    }
    else{
        m->turno = trocar_turno(p[pmi].status);
        m->jogador_vantagem = p[pmi].status;
        p[pmi].status=3;
        m->lado_impar =p[pmi].lado1;
        m->lado_par=p[pmi].lado2;
        return m->jogador_vantagem;     //retorna qual jogador(1 ou 2) tem vantagem
    }
}

//Compra uma peca para o Jogador que foi passado no parametro
int comprar(peca p[28], int jogador){
    int i;
    for(i =0; i<28; i++){
        if(p[i].status == 0){
            p[i].status = jogador;
            return 1;   //retorna 1 se foi possivel comprar a peca
        }
    }
    return 0;           //retorna 0 se nao foi possivel comprar a peca
}

//Recebe uma peca escolhida pelo Jogador colocando ela na mesa se possivel
int verificar_jogada(mesa *m, peca p[28], int jogador, int escolha){
    int contador = 1, contador_par = 0, contador_impar = 0, i, peca_jogada;
    int lado_impar=0, lado_par=0;

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
        lado_impar = 1;
    }
    else if(p[peca_jogada].lado2 == m->lado_impar){
        lado_impar = 1;
    }
    if(p[peca_jogada].lado1 == m->lado_par){
        lado_par = 1;
    }
    else if (p[peca_jogada].lado2 == m->lado_par){
        trocar_lado_peca(&p[peca_jogada]);
        lado_par = 1;
    }

    if ((lado_impar+lado_par)==1){
        if (lado_par){
            p[peca_jogada].status = 4 + (2*contador_par);
            m->lado_par = p[peca_jogada].lado2;
            m->turno = trocar_turno(jogador);
            return 1;   //retorna 1 se a jogada eh valida e a peca foi colocada na mesa
        } else{
            p[peca_jogada].status = 5 + (2*contador_impar);
            m->lado_impar = p[peca_jogada].lado1;
            m->turno = trocar_turno(jogador);
            return 1;   //retorna 1 se a jogada eh valida e a peca foi colocada na mesa
        }
    }
    else if ((lado_impar+lado_par)==2){return 2;}       //retorna 2 se a peca pode ser jogada nos 2 lados da mesa
    else return 0;      //retorna 0 se nao eh uma jogada valida
}

//Se a peca escolhida poder ser colocada nos dois lados da mesa coloca a peca no lado da mesa escolhido pelo Jogador
void coloca_lado_escolhido(mesa *m, peca p[28], int jogador, int escolha, int lado){
    if (lado < 1 || lado > 2){return;}

    int contador = 1, contador_par = 0, contador_impar = 0, i, peca_jogada;

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

    if (lado == 2){
        if (p[peca_jogada].lado2 == m->lado_par){trocar_lado_peca(&p[peca_jogada]);}
        p[peca_jogada].status = 4 + (2*contador_par);
        m->lado_par = p[peca_jogada].lado2;
        m->turno = trocar_turno(jogador);
    }
    else if (lado == 1){
        if(p[peca_jogada].lado1 == m->lado_impar){trocar_lado_peca(&p[peca_jogada]);}
        p[peca_jogada].status = 5 + (2*contador_impar);
        m->lado_impar = p[peca_jogada].lado1;
        m->turno = trocar_turno(jogador);
    }
}

//Troca o lado da peca, lado 1 vira lado 2 e lado 2 vira lado 1
void trocar_lado_peca(peca *p){
    int aux = p->lado1;
    p->lado1 = p->lado2;
    p->lado2 = aux;
}

//Troca o turno de Jogada para o outro Jogador
int trocar_turno(int turno){
    if(turno == 1){
        return 2;       //retorna 2 se o turno era 1
    } else return 1;    //retorna 1 se o turno era 2
}

//Verifica se algum dos Jogadores venceram a partida
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
    if(somaJ1 == 0 && nPecasJ1 == 0){return -1;}        //retorna -1 se o jogador 1 ganhou a partida
    if(somaJ2 == 0 && nPecasJ2 == 0){return -2;}        //retorna -2 se o jogador 2 ganhou a partida
    if ((pecaJogavel1+pecaJogavel2)==0 && verificar_compra(p) == 0){
        if (somaJ1<somaJ2){return (somaJ1*1000 + somaJ2)*2;}    //retorna um numero que indica que o jogador 1 ganhou e a pontuacao de cada jogador
        if(somaJ2<somaJ1){return (somaJ1*1000 + somaJ2)*2+1;}   //retorna um numero que indica que o jogador 2 ganhou e a pontuacao de cada jogador
        if(somaJ1==somaJ2){return (somaJ1*1000 + somaJ2)*2 + (jogadorVantagem-1);}      //retorna um numero que indica que o jogador com vantagem ganhou e a pontuacao de cada jogador
    }
    return 0;       //retorna 0 se nenhum jogador ganhou o jogo ainda
}

int jogada_computador(mesa *m, peca p[28]){
    int i, opc = 0, aux;
    for (i = 0;i<28; i++) {
        if (p[i].status == 2){
            opc++;
            aux = verificar_jogada(m, p, 2, opc);
            if (aux == 1){
                return i * 10;      //retorna o indice da peca jogada pelo computador * 10
            }
            else if (aux == 2){
                coloca_lado_escolhido(m, p, 2, opc, 1);
                return i * 10;      //retorna o indice da peca jogada pelo computador * 10
            }
        }
    }

    if (comprar(p, 2)){
        return 1;       //retorna 1 se o computador comprou uma peca
    } else {
        m->turno = 1;
        return 2;       //retorna 2 se o computador passa o turno
    }
}

//Verifica se eh possivel jogar uma peca
int verificar_peca_jogavel(peca p, mesa m){
    int l1 = p.lado1;
    int l2 = p.lado2;
    if(l1 == m.lado_impar || l1 == m.lado_par || l2 == m.lado_impar || l2 == m.lado_par){
        return 1;       //retorna 1 se a peca eh jogavel
    } else return 0;    //retonra 0 se nao eh possivel jogar a peca
}

//Verifica se ainda ha pecas disponiveis para compra
int verificar_compra(peca p[28]){
    int i;
    for (i = 0; i < 28; i++) {
        if (p[i].status == 0){return 1;}    //retorna 1 se ha pecas disponiveis para compra
    }
    return 0;       //retorna 0 se nao ha mais pecas disponiveis para compra
}
