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

void gravar_jogo(peca pecas[28], mesa *m){
    FILE *fp;
    int i = 0;

    if((fp = fopen("DOMINO", "w")) == NULL){
        printf("ERRO AO ABRIR O ARQUIVO");
        return;
    }

    if (fwrite(&*m, sizeof(struct mesa), 1, fp) != 1){
        printf("Erro na gravacao do arquivo");
    }

    while (i<28){
        if (fwrite(&pecas[i], sizeof(peca), 1, fp) != 1){
            printf("Erro na gravacao do arquivo");
        }
        i++;
    }
    fclose(fp);
}

int carregar_jogo(peca pecas[28], mesa *m){
    FILE *fp;
    int i;

    if((fp = fopen("DOMINO", "r")) == NULL)
    {
        printf("O arquivo DOMINO nao pode ser aberto");
        return 0;
    }

    i = 0;
    if (fread(&*m, sizeof(struct mesa), 1, fp)  != 1){
        printf("Erro na leitura do arquivo");
    }
    while (!feof(fp))    //ou (TRUE)
    {
        if (fread(&pecas[i], sizeof(peca), 1, fp)  != 1)
        {
            if(feof(fp))
                break;
            printf("Erro na leitura do arquivo");
            break;
        }
        i++;
    }
    fclose(fp);
    return 1;
}

void menu_jogo(peca p[28],mesa *m){
    char opc;
    int jogada, lado_escolhido, aux_jogada;
    int verificar_fim;

    do{
      verificar_fim = verificar_vitoria(p, *m, m->jogador_vantagem);
      if (verificar_fim){vitoria(verificar_fim); break;}
      imprime_mesa(p);
      mostrar_pecas_jogo(p, m->turno);
      limpar_buffer();
      opc = jogo_menu();
      switch (opc) {
          case '1':
              jogada = opc_jogada();
              aux_jogada = verificar_jogada(m, p, m->turno, jogada);
              if (jogada){
                  if(aux_jogada == 2){
                      limpar_buffer();
                      lado_escolhido = escolher_lado();
                      coloca_lado_escolhido(m, p, m->turno, jogada, lado_escolhido);
                      if (lado_escolhido == 1 || lado_escolhido == 2){jogada_sucedida(1);}
                  } else jogada_sucedida(aux_jogada);
              }
              break;
          case '2':
              erro_comprar(comprar(p, m->turno));
              break;
          case '3':
              if (verificar_compra(p) == 0){m->turno = trocar_turno(m->turno);}
              else printf("\n==>Passagem de turno somente quando nao ha mais pecas para compra!\n");
              break;
          case '4':
              break;
          default:
              erro();
              break;
      }
    }while(opc != '4');
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
                if (aux){gravar_jogo(pecas, &m);}
                else erro_retomar_jogo();
                break;
            case '6':
                aux = carregar_jogo(pecas, &m);
                break;
            default:
                erro();
                break;
        }
        limpar_buffer();
    }while (opc != '0');
}

