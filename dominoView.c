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
            printf("%2d. [%d|%d]\t", indice+1, p[indice].lado1, p[indice].lado2);
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
    printf("(5) - Voltar ao menu inicial\n");

    opc = getchar();

    return opc;

}

int menu_jogar_inicio(){
	int aux;
    printf("Jogo de Dominó (Nitro Fin)\n\n");
    printf("Selecione o numero de jogadores: \n");
    printf("(1) - Apenas 1 jogador\n");
    printf("(2) - 2 Jogadores\n");
    aux = getchar();

    return aux;
}
