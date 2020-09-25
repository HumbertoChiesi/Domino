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

                    //algum outro menu para distribuir as pecas e criar a mesa
                    while (1){
                        limpar_buffer();
                        mesa.njogadores = menu_jogar_inicio();
                        if(mesa.njogadores == 1 || mesa.njogadores == 2){
                            break;
                        }else{
                            erro();
                        }                 

                    }

                    int jogar;
                    int is_distribuir = 0;
                    while (1){
                        jogar = menu_jogar(is_distribuir);
                        if(jogar == 1 && is_distribuir == 1){

                            
                            //funcao vai ter q achar qual peca de qual jogador vai pra mesa
                            //Chamar a mesa com a peca no meio ja
                            
                        }else if (jogar == 2 && is_distribuir ==0){

                            is_distribuir == 1;
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
    setbuf(stdin, NULL);
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
