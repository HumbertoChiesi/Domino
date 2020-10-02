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

void num_jogadores(mesa *mesa){
    do{
        limpar_buffer();
        mesa->njogadores = menu_jogar_inicio();
        if(mesa->njogadores == 1 || mesa->njogadores == 2){
            break;
        }else{
            erro();
        }

    }while(mesa->njogadores != 1 || mesa->njogadores != 2);
}
void jogar(peca p[], mesa *mesa){


    int aux_peca_inicial, verificar_fim;
    aux_peca_inicial = primeira_peca(p, mesa);

    int opc_jogo;

    do{
        verificar_fim = verificar_vitoria(p, *mesa, aux_peca_inicial);
        if (verificar_fim){
            vitoria(verificar_fim);
            break;
        }
        comecou_jogo(p, *mesa, aux_peca_inicial);
        limpar_buffer();
        opc_jogo = jogo_menu();
        switch(opc_jogo){
            case 1:{
                int escolha;
                limpar_buffer();
                escolha = mostrar_pecas_jogo(p, 1);
                if(escolha == 0){
                    if (comprar(p, 1, mesa)==0){erro_comprar();}

                }
                else if (escolha == 1){
                    break;
                } else{
                    int jogada_sucesso;
                    jogada_sucesso = verificar_jogada(mesa, p, 1, escolha);
                    jodada_sucedida(jogada_sucesso);

                }
                break;
            }
            case 2:{
                int escolha;
                limpar_buffer();
                escolha = mostrar_pecas_jogo(p, 2);
                if(escolha == 0){
                    if (comprar(p, 2, mesa)==0){erro_comprar();}

                }
                else if (escolha == 1){
                    break;
                } else{
                    int jogada_sucesso;
                    jogada_sucesso = verificar_jogada(mesa, p, 2, escolha);
                    jodada_sucedida(jogada_sucesso);

                }
                break;
            }
            case 3:
                    break;

            default:{
                    erro();
            }
        }
    }while(opc_jogo != 3);


}

void iniciar_jogo(peca p[], mesa *mesa){

    int distribuir = 0;
    int jogar_opcao;
    do{
        limpar_buffer();
        jogar_opcao = menu_jogar(distribuir);

        if(jogar_opcao == 1){
            if (distribuir){
                jogar(p, mesa);
            } else erro_distribuicao_pecas();

        }else if (jogar_opcao == 2){

            distribuir = 1;
            distribuir_pecas(p);

        }else if (jogar_opcao==3){}
        else erro();


    }while(jogar_opcao != 3);

}



void executar_domino(){

    char caux;
    peca p [28];
    mesa mesa;



    cria_pecas(p);


    do{


        limpar_buffer();

        caux = menu_inicial();

        switch (caux)
        {
            case '1':{

                mostrar_pecas_ordenadas();
                break;
            }
            case '2':{

                embaralhar(p, 28);
                mostrar_pecas(p);
                break;
            }
            case '3':{

                embaralhar(p, 28);
                char caux2;

                do{

                    limpar_buffer();
                    caux2 = menu_secundario();

                    switch (caux2){

                        case '1':{

                            num_jogadores(&mesa);
                            iniciar_jogo(p, &mesa);

                            break;
                        }
                        case '2':
                            //alguma funcao para abrir o FILE salvo;
                            break;
                        case '3':
                            //alguma funcao para salvar o jogo FILE
                            break;

                        case '4':
                            imprimir_regras();
                            break;
                        case '5':
                            break;
                        default:{
                            erro();
                            break;
                        }
                    }


                }while(caux2 != '5');

            case '4':
                break;

            default:
                erro();
            }
        }


    }while(caux != '4');


}
