/*
Arquivo Main.c:
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: Implementacao das funcoes da biblioteca controller.h.

*/


#include "dominoController.h"
void limpar_buffer(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
void menu_jogo(peca p[28],mesa *m){
    char opc;
    int jogada;
    int verificar_fim;
    do{
      verificar_fim = verificar_vitoria(p, *m, m->jogador_vantagem);
      if (verificar_fim){vitoria(verificar_fim); break;}
      comecou_jogo(p, *m);
      mostrar_pecas_jogo(p, m->turno);
      limpar_buffer();
      opc = jogo_menu();
      switch (opc) {
          case '1':
              jogada = opc_jogada();
              if (jogada){jodada_sucedida(verificar_jogada(m, p, m->turno, jogada));}
              break;
          case '2':
              if (comprar(p, m->turno, m) == 0){erro_comprar(m, m->turno);}
              break;
          case '3':
              break;
          default:
              erro();
              break;
      }
    }while(opc != '3');
}

void executar_domino(){
    int aux = 0;
    char opc;
    peca pecas[28];
    mesa m;

    cria_pecas(pecas);

    do{
        opc = menu_inicial();
        switch (opc) {
            case '0':
                break;
            case '1':
                aux = 1;
                m.njogadores = 2;
                reseta_status(pecas);
                embaralhar(pecas, 28);
                distribuir_pecas(pecas);
                primeira_peca(pecas, &m);
                menu_jogo(pecas, &m);
                break;
            case '2':
                aux = 1;
                m.njogadores = 1;
                reseta_status(pecas);
                embaralhar(pecas, 28);
                distribuir_pecas(pecas);
                primeira_peca(pecas, &m);
                menu_jogo(pecas, &m);
                break;
            case '3':
                if (aux){menu_jogo(pecas, &m);}
                else erro_retomar_jogo();
                break;
            case '4':
                imprimir_regras();
                break;
            case '5':
                break;
            case '6':
                break;
            default:
                erro();
                break;
        }
        limpar_buffer();
    }while (opc != '0');
}
