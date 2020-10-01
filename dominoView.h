/*
Arquivo Main.c: 
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: Arquivo de biblioteca responsavel pelas funcoes disponiveis no view. Parte em que o programa aparece visualmente para o usuario.

*/

#ifndef DOMINOVIEW_H_
#define DOMINOVIEW_H_

#include "dominoModel.h"

char menu_inicial();
void erro();
void mostrar_pecas_ordenadas();
void mostrar_pecas(peca p[28]);
char menu_secundario();
int menu_jogar_inicio();
int menu_distribuir_pecas();
int menu_jogar(int is_distribuir);
void erro_distribuicao_pecas();
void comecou_jogo(peca p[28], mesa mesa, int meio);
int jogo_menu();
int mostrar_pecas_jogo(peca p[28], int jogador);
void imprimir_regras();
void jodada_sucedida(int jogada);


#endif 
