/*
Arquivo Main.c: 
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: Implementacao das funcoes da biblioteca controller.h.

*/


#include "dominoController.h"


void executar_domino(){

    char caux;
    tipo_peca p[28];
    tipo_peca aux [28];
    tipo_mesa mesa;
    
    

    cria_pecas(p);
    for(int i =0; i <28; i++){
        aux[i]= p[i];
    }
    
    while(1){
        limpar_buffer();
        caux = menu_inicial();

        switch (caux)
        {
        case '1':

            mostrar_pecas(p);
            break;
        
        case '2':

            embaralhar(aux, 28);
            mostrar_pecas(aux);
            break;

        case '3':

            embaralhar(aux, 28);
            limpar_buffer();
            char caux2;

            while(1){

                limpar_buffer(); 
                caux2 = menu_secundario();

                if(caux == '5'){
                    break;
                }

                switch (caux2){

                case '1':

                    
                    
                    while (1){
                        limpar_buffer();
                        mesa.njogadores = menu_jogar_inicio();
                        if(mesa.njogadores == 1 || mesa.njogadores == 2){
                            break;
                        }else{
                            erro();
                        }                 

                    }
                    int distribuir = 0;
                    int jogar;
                    while (1){
                        
                        
                        limpar_buffer();
                        jogar = menu_jogar(distribuir);
                        if(jogar == 1 && distribuir == 1){

                            int peca_mesa_inicio;
                            peca_mesa_inicio = primeira_peca(aux, &mesa);
                            mudar_posicao(aux, peca_mesa_inicio, 3);

                            

                            int opc_jogo;
                            int auxiliar_par =4;
                            int auxiliar_impar = 5;
                            while (1){
                                comecou_jogo(aux, mesa);
                                limpar_buffer();
                                opc_jogo = jogo_menu();
                                if( opc_jogo == 1){
                                    int escolha;
                                    limpar_buffer();
                                    escolha = mostrar_pecas_jogo(aux, 1);              
                                    if(escolha == 0){
                                        comprar(aux, 1);
                                    
                                    }else{
                                        int jogada_sucesso;
                                        limpar_buffer();
                                        jogada_sucesso = jogada(&mesa, aux, 1, escolha);
                                        jodada_sucedida(jogada_sucesso);
                                        
                                    }
                                    
                                }else if (opc_jogo == 2){
                                    int escolha;
                                    limpar_buffer();
                                    escolha = mostrar_pecas_jogo(aux, 2);
                                    if(escolha == 0){
                                        comprar(aux, 2);
                                        
                                    }else{
                                        int jogada_sucesso;
                                        limpar_buffer();
                                        jogada_sucesso = jogada(&mesa, aux, 2, escolha);
                                        jodada_sucedida(jogada_sucesso);
                                        
                                    }

                                }else if (opc_jogo == 3){
                                    break;
                                }else{
                                    erro();
                                }
                                
                            }
                            
                            

                            
                            //funcao vai ter q achar qual peca de qual jogador vai pra mesa
                            //Chamar a mesa com a peca no meio ja

                            
                        }else if (jogar == 2){

                            distribuir = 1;
                            distribuir_pecas(aux);

                        }else if (jogar == 3){

                            break;

                        }else if (jogar ==1){

                            erro_distribuicao_pecas();

                        }else{

                            erro();
                        
                        }
                        
                    }
                    
                    
                    break;
                
                case '2':
                    //alguma funcao para abrir o FILE salvo;
                    break;
                case '3':
                    //alguma funcao para salvar o jogo FILE
                    break;
                
                case '4':
                    //imprimir as regras do jogo
                    break;
                
                case '5':
                    break;
                
                default:
                    erro();
                    break;
                }
                break;
            }
        case '4':
            exit(0);
            break;

        default:
            erro();
        }

       

    }


}

void limpar_buffer(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
