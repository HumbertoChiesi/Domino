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
void imprime_mesa(peca p[28]);
char jogo_menu();
void mostrar_pecas_jogo(peca p[28], int jogador);
void imprimir_regras();
void jogada_sucedida(int jogada);
void vitoria(int jogador);
void erro_comprar(int n);
int opc_jogada();
void erro_retomar_jogo();
int escolher_lado();

#endif 
