/*
Arquivo Main.c:
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: Implementacao das funcoes da biblioteca controller.h.

*/


#include "dominoController.h"

//Limpa o buffer
void limpar_buffer(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

//Grava o Jogo Atual em um arquivo
void gravar_jogo(peca pecas[28], mesa *m){
    FILE *fp;
    int i = 0;

    if((fp = fopen("DOMINO", "wb")) == NULL){
        erro_abrir_arquivo();
        return;
    }

    if (fwrite(&*m, sizeof(struct mesa), 1, fp) != 1){
        erro_gravacao();
    }

    while (i<28){
        if (fwrite(&pecas[i], sizeof(peca), 1, fp) != 1){
            erro_gravacao();
        }
        i++;
    }
    fclose(fp);
}

//Carrega o Jogo salvo no arquivo
int carregar_jogo(peca pecas[28], mesa *m){
    FILE *fp;
    int i;

    if((fp = fopen("DOMINO", "rb")) == NULL)
    {
        erro_abrir_arquivo();
        return 0;
    }

    i = 0;
    if (fread(&*m, sizeof(struct mesa), 1, fp)  != 1){
        erro_leitura();
    }
    while (!feof(fp))
    {
        if (fread(&pecas[i], sizeof(peca), 1, fp)  != 1)
        {
            if(feof(fp))
                break;
            erro_leitura();
            break;
        }
        i++;
    }
    fclose(fp);
    return 1;
}

//menu do jogo Domino
void menu_jogo(peca p[28],mesa *m){
    //inicializacao das variaveis
    char opc;
    int jogada, lado_escolhido, aux_jogada;
    int verificar_fim;

    //loop do jogo
    do{
      //verifica se algum jogador ganhou a partida quebrando o loop se verdadeiro
      verificar_fim = verificar_vitoria(p, *m, m->jogador_vantagem);
      if (verificar_fim){vitoria(verificar_fim); break;}

      imprime_mesa(p, m->turno);
      limpar_buffer();
      opc = jogo_menu();

      switch (opc) {
          case '1':                 //Jogador escolhe um peca para jogar
              jogada = opc_jogada();

              if (jogada){          //verifica se o jogador nao escolheu 0 (opcao para desistir da jogada)
                  aux_jogada = verificar_jogada(m, p, m->turno, jogada);

                  /*verifica se a peca pode ser colocada nos dois lados da mesa, entrando no else quando a jogada eh
                   valida e pode apenas ser colocada em um lado  da mesa ou quando a jogada eh invalida */
                  if(aux_jogada == 2){
                      limpar_buffer();
                      lado_escolhido = escolher_lado();

                      coloca_lado_escolhido(m, p, m->turno, jogada, lado_escolhido);
                      if (lado_escolhido == 1 || lado_escolhido == 2){jogada_sucedida(1);}
                  }
                  else jogada_sucedida(aux_jogada);
              }
              break;

          case '2':                 //Compra uma peca se possivel
              erro_comprar(comprar(p, m->turno));
              break;

          case '3':                 //Passa o turno se nao ha mais pecas disponiveis para compra
              if (verificar_compra(p) == 0){m->turno = trocar_turno(m->turno);}
              else erro_passar_turno();
              break;

          case '4':                 //quebra o loop e volta ao menu inicial
              break;

          default:                  //Pega qualquer opcao invalida dada pelo usuario
              erro();
              break;
      }
    }while(opc != '4');
}

//menu inicial do Domino
void executar_domino(){
    //inicializacao de variaveis e estruturas
    int aux = 0;        //variavel usada para verificar se algum jogo ja foi iniciado
    char opc;
    peca pecas[28];
    mesa m;

    cria_pecas(pecas);

    //Loop menu inicial
    do{
        opc = menu_inicial();   //opcao escolhida pelo usuario
        switch (opc) {
            case '0':           //encerra o Domino
                break;

            case '1':           //Inicia um novo jogo de Domino com 2 jogadores
                aux = 1;
                m.njogadores = 2;
                reseta_status(pecas);
                embaralhar(pecas, 28);
                distribuir_pecas(pecas);
                primeira_peca(pecas, &m);
                menu_jogo(pecas, &m);
                break;

            case '2':           //Inicia um novo jogo de Domino com 1 jogador
                aux = 1;
                m.njogadores = 1;
                reseta_status(pecas);
                embaralhar(pecas, 28);
                distribuir_pecas(pecas);
                primeira_peca(pecas, &m);
                menu_jogo(pecas, &m);
                break;

            case '3':           //Retoma o jogo interrompido se existente
                if (aux){menu_jogo(pecas, &m);}
                else erro_retomar_jogo();
                break;

            case '4':           //Imprime as regras do domino
                imprimir_regras();
                break;

            case '5':           //Salva o jogo atual se existente
                if (aux){gravar_jogo(pecas, &m);}
                else erro_retomar_jogo();
                break;

            case '6':           //Recupera jogo salvo no arquivo se existente
                aux = carregar_jogo(pecas, &m);
                break;

            default:            //Pega qualquer opcao invalida dada pelo usuario
                erro();
                break;
        }
        limpar_buffer();       
    }while (opc != '0');
}

