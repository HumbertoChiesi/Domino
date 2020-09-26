/*
Arquivo Main.c: 
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: implementacao das funcoes do view.h.

*/


#include "dominoView.h"

char menu_inicial(){
    char aux;
    printf("\n============================\n");
    printf("Bem-vind ao Domino Nitro Fin\n");
    printf("============================\n");
    printf("\n (1) - Ver as pecas ordenadas\n (2) - Ver as pecas na embaralhadas\n (3) - Comecar a jogar \n (4) - Sair\n\n");
    aux = getchar();
    return aux;
}

void erro(){
    printf("\nOpcao Invalida. Escolha novamente uma das opcoes disponiveis.\n");
}

void mostrar_pecas(tipo_peca p[28]){
    int indice =0;
    for(int i =1; i<=4; i++){
        for(int j= 1; j<=7; j++){
            //imprimindo o domino na sequencia ordenada.
            printf("%2d. [%d|%d] ", indice+1, p[indice].lado1, p[indice].lado2);
            indice++;
        }
        printf("\n");
    }
    
}

char menu_secundario(){


    int opc;
    printf("Jogo de Dominó (Nitro Fin)\n\n");
    printf("(1) - Iniciar novo Jogo\n");
    printf("(2) - Continuar a Jogar\n");
    printf("(3) - Salvar Jogo\n");
    printf("(4) - Regras do Jogo\n");
    printf("(5) - Sair\n");

    opc = getchar();

    return opc;

}

int menu_jogar_inicio(){
    //int
    int aux;
    printf("Jogo de Dominó (Nitro Fin)\n\n");
    printf("Selecione o numero de jogadores para distribuir as pecas: \n");
    printf("(1) - Apenas 1 jogador\n");
    printf("(2) - 2 Jogadores\n");
    scanf("%d", &aux);

    return aux;
}

int menu_jogar(int is_distribuir){
    int aux;
    printf("\n==========================\n");
    printf("(1) - Iniciar Jogo \n");
    printf("(2) - Distribuir as pecas\n");
    printf("(3) - Voltar\n");
    if(is_distribuir ==0){
        printf("Pecas nao distribuidas ainda!\n");
    }else{
        printf("Pecas ja distribuidas\n");
    }
    scanf("%d", &aux);

    return aux;
}

void erro_distribuicao_pecas(){
    printf("\nAs pecas nao foram distribuidas ainda! Impossivel comecar a jogar\n");
}

void comecou_jogo(tipo_peca p[28], tipo_mesa mesa){
    printf("\n\nComprar: [x|x]\n");
    int pp = 0, nPP=0, nPI=0, n, r, i;
    while (p[pp].posicao != 3){pp++;}
    int m1=p[pp].lado1, m2=p[pp].lado2;
    tipo_peca pecas_par[28];
    tipo_peca pecas_impar[28];

    for (int i = 0; i < 28; i++) {
        r=0;
        n = p[i].posicao;
        if((n%2)==0 && n>=4){
            r = (n/2)-2;
            pecas_par[r]=p[i];
            nPP++;
        }
        else if ((n%2)==1 && n>=5){
            while (n>5){
                n = n-2;
                r++;
            }
            pecas_impar[r]=p[i];
            nPI++;
        }
    }
    for (i = nPI; i > 0; i--) {printf("[%d|%d] ", pecas_impar[i-1].lado1 , pecas_impar[i-1].lado2);}

    if(nPI > 0){
        if(m1 == pecas_impar[0].lado1 || m1 == pecas_impar[0].lado2){
            printf("[%d|%d] ", m1, m2);
        } else printf("[%d|%d] ", m2, m1);
    }
    else if(nPP > 0){
        if(m2 == pecas_par[0].lado1 || m2 == pecas_par[0].lado2){
            printf("[%d|%d] ", m1, m2);
        } else printf("[%d|%d] ", m2, m1);
    } else printf("[%d|%d] ", m1, m2);

    for (i = 0; i < nPP; i++) {printf("[%d|%d] ", pecas_par[i].lado1 , pecas_par[i].lado2);}
    printf("\n");
}

int jogo_menu(){
    int aux;
    printf("\n\n(1) - Pecas Jogador 1\n(2) - Pecas Jogador 2\n(3) - Voltar\n");
    scanf("%d", &aux);
    return aux;
}

int mostrar_pecas_jogo(tipo_peca p[28], int jogador){
    int aux;
    int i, indice =1;
    for(i =0; i<28; i++){
        if(p[i].posicao == jogador){
            printf("%2d-[%d|%d] ", indice,p[i].lado1, p[i].lado2);
            indice += 1;
        }
    }
    printf(" (0)-Para Comprar uma Peca\n");
    scanf("%d", &aux);

    return aux; 
}

void jodada_sucedida(int jogada){
    if(jogada == 1){
        printf("\nJogada Realizada Com Sucesso\n");
    }else{
        printf("\nJogada invalida, tente novamente\n");
    }
    
}