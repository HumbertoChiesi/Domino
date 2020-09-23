/*
Arquivo Main.c: 
Grupo: Matheus Madureira Fortunato, Humberto Chiesi Neto, Gustavo Fernandes Pacheco, Gustavo Fernandes Ramos Julio Ferreira
Descricao: Implementacao das funcoes da biblioteca controller.h.

*/


#include "dominoController.h"


void executar_domino(){

    char caux;
    int njogadores;
    struct pecas p[28];
    struct pecas aux [28];

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
            while(1){
                caux = menu_secundario();
                if(caux == '5'){
                    break;
                }
                switch (caux){
                case '1':
                    //algum outro menu para distribuir as pecas e criar a mesa
                    njogadores = menu_jogar_inicio();
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
