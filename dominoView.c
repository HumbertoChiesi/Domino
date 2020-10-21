/*
Arquivo Main.c:
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: implementacao das funcoes do view.h.

*/


#include "dominoView.h"

//funcao imprime o menu inicial do Domino
char menu_inicial(){
    char aux;
    printf("\n============================\n");
    printf("Bem-vindo ao Domino Nitro Fin\n");
    printf("============================\n");
    printf("\n (1) - Iniciar Jogo(2 Jogadores)\n (2) - Iniciar Jogo(contra o computador\n (3) - Retomar Jogo Interrompido\n"
           " (4) - Regras do Jogo\n (5) - Salvar o Jogo\n (6) - Recuperar o Jogo\n (0) - Sair\n Opcao:");
    aux = getchar();
    return aux;
}

//funcao imprime mensagem de erro para opcao invalida
void erro(){
    printf("\n==>Opcao Invalida. Escolha novamente uma das opcoes disponiveis.\n");
}

//funcao imprime mesa do Domino
void imprime_mesa(peca p[28], int jogador){
    int pp = 0, nPP=0, nPI=0, n, r, i, indice;

    printf("\n----------------------\nMesa:\n");
    printf("Pecas Jogador %d: ", trocar_turno(jogador));
    for (int i = 0; i < 28; ++i) {
        if (p[i].status == trocar_turno(jogador)){printf("[x|x] ");}
    }
    printf("\n");

    while (p[pp].status != 3){pp++;}
    int m1=p[pp].lado1, m2=p[pp].lado2;

    peca pecas_par[28];
    peca pecas_impar[28];

    for (i = 0; i < 28; i++) {
        r=0;
        n = p[i].status;
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
    i=1;
    while (i < ((nPI+nPP)*6+11) && i < 119){printf("="); i++;}
    printf("=\n|| ");
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
    printf("||\n");
    i=0;
    while (i < ((nPI+nPP)*6+11) && i < 120){printf("="); i++;}

    indice = 1;
    printf("\nPecas Jogador %d: ", jogador);
    for(i =0; i<28; i++){
        if(p[i].status == jogador){
            printf("%2d-[%d|%d] ", indice,p[i].lado1, p[i].lado2);
            indice += 1;
        }
    }
    printf("\n----------------------");
}

//Funcao imprime menu de opcoes do Jogador e devolve a opcao escolhida
int jogo_menu(){
    int aux;
    printf("\n(1) - Jogar\n(2) - Comprar\n(3) - Passar\n(4) - Voltar\nOpcao:");
    scanf("%d", &aux);
    return aux;
}

//Funcao imprime mensagem de sucesso ou falha da jogada
void jogada_sucedida(int jogada){
    if(jogada==1){
        printf("\n==>Jogada Realizada Com Sucesso!\n");
    }else{
        printf("\n==>Jogada invalida, tente novamente\n");
    }
}

//Funcao imprime mensagem de escolha de peca e devolve o numero da peca escolhida
int opc_jogada(){
    int opc;
    printf("Escolha peca para jogar(0 para desistir de jogar):");
    scanf("%d", &opc);
    return opc;
}

void erro_passar_turno(){
    printf("\n==>Passagem de turno somente quando nao ha mais pecas disponiveis para compra!\n");
}

//Funcao imprime as regras do Domino
void imprimir_regras(){
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("        REGRAS DO DOMINO:\n\n");
    printf("*Cada jogador pega sete pecas e pode comprar quando precisar de uma peca para  jogar e quantas vezes for \n"
           "    necessario.\n\n");
    printf("*O jogador que tiver a peca com os numeros repetidos mais altos inicia o jogo(o jogador que comeca a partida\n"
           "    leva vantagem).\n\n");
    printf("*Os jogadores devem colocarpecas que tenham os mesmos numeros das pecas que se encontram na ponta do jogo\n\n");
    printf("*Cada jogador, no seu turno, deve colocar uma das suas pecas em uma das 2 extremidades abertas de forma que\n"
           "    os pontos de um do  lados coincida com os pontos da extremidade onde esta sendo colocada.\n\n");
    printf("*Se  um  jogador  nao  puder  jogar,  devera comprar do  monte tantas pecas como forem necessarias.\n"
           "    Se nao houver pecas no monte, passara o turno ao seguinte jogador.\n\n");
    printf("*Quando  um  jogador  coloca  sua  ultima  pedra  na  mesa, o jogador ganha a partida.\n\n");
    printf("*Em caso de nenhum dos jogadores conseguir continuar a partida ela esta fechada, os jogadores entao contarao\n"
           "     os pontos das pedras que ficaram e o jogador com menos pontos vence.\n\n");
    printf("*Se os jogadores tiverem os mesmos pontos, entao o jogogador que tem vantagem, neste caso, vence o jogo.\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
}

//Funcao imprime mensagem de vitoria
void vitoria(int jogador){
    printf("\n===========================\nJogador %d venceu, Parabens!!\n===========================\n", jogador);
}

//Funcao imprime sucesso ou falha da compra de uma peca
void erro_comprar(int n){
    if (n == 0){printf("\n==>Sem pecas disponiveis para compra!\n");}
    else printf("\n==>Peca comprada!\n");

}

//Funcao imprime mensagem de erro se nenhum jogo foi iniciado ainda
void erro_retomar_jogo(){
    printf("\n==>Nenhum Jogo foi Iniciado Ainda!!\n");
}

//Funcao imprime mensagem de escolha de lado da peca e devolve inteiro indicando lado escolhido
int escolher_lado(){
    int opc;
    printf("1-Esquerda 2-Direita 0-Desistir:");
    scanf("%d", &opc);
    if (opc<0 || opc > 2){erro();}
    return opc;
}

//Funcao imprime mensagem de erro ao nao poder abrir o arquivo
void erro_abrir_arquivo(){
    printf("ERRO AO ABRIR O ARQUIVO");
}

//Funcao imprime mensagem de erro ao nao poder ler o arquivo
void erro_leitura(){
    printf("Erro na leitura do arquivo");
}

//Funcao imprime mensagem de erro ao nao poder gravar o arquivo
void erro_gravacao(){
    printf("Erro na gravacao do arquivo");
}

void mensagem_computador(int jogada, peca p[28]){
    if (jogada == 1){
        printf("\n==> Computador comprou uma peca!\n");
    }
    else if (jogada == 2){
        printf("\n==> Nada a comprar, o computador passou a vez!\n");
    }
    else {
        printf("\n==> O computador jogou a peca [%d|%d] !\n", p[jogada/10].lado1, p[jogada/10].lado2);
    }
}