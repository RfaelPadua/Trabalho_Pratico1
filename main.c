#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int n_rodadas, menu1, menu2, i, j;
    int flag = 0, flag2 = 0;
    
    //Menu inicial
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t------------------------------\n");
    printf("\t\t\t\t|                            |\n");
    printf("\t\t\t\t|    JOGO DOS CEM ERROS      |\n");
    printf("\t\t\t\t|                            |\n");
    printf("\t\t\t\t------------------------------\n");
    printf("\n\n\n\n\n\n\n\n");
    system("pause");
    system("cls");

    //Definir quantas rodadas.
    printf("Quantas rodadas? ");
    scanf(" %d", &n_rodadas);

    system("cls");

    int pon[n_rodadas];
    int pon_aux[n_rodadas];


    do{
        //Primeiro Menu, para definir os valores de cada rodada.
        flag2 = 0;
        printf("Selecione uma das opcoes a seguir\n");
        printf("1. Gerar valores aleatorios\n");
        printf("2. Inserir valores manualmente\n");
        scanf(" %d", &menu1);
        system("cls");

        
        if(menu1 == 1){ //Usar a função rand, usando "time" como semente.
            srand(time(NULL));
            for(i = 0; i < n_rodadas; i++){
                pon[i] = (rand() % 201) + (-100);
            }
        }else if(menu1 == 2){
            for(i = 0; i < n_rodadas; i++){ //Perguntar para o usuario os valores de cada rodada.
                printf("Insira o valor da %d rodada: ", i + 1);
                scanf(" %d", &pon[i]);
            }
        }else{ //Se o usuario nao escolher entre 1 e 2, pare esse iteração e va para a prox.
            continue;
        }
        
        //Estabelecer um vetor aux, um que posso ser modificado sem atrapalhar outras funcoes
        for(i = 0; i < n_rodadas; i++){
            pon_aux[i] = pon[i];
        }

        //Layout para demonstrar a fita
        printf("\nRod ");
        for(i = 0; i < n_rodadas; i++){
            printf("|%4d ", i+1);
        }
        printf("|\n");

        printf("Pon ");
        for(i = 0; i < n_rodadas; i++){
            printf("|%4d ", pon[i]);
        }
        printf("|\n\n");
            
        system("pause");
        system("cls");
        

        do{ //Segundo menu
            printf("Selecione uma das opcoes a seguir\n");
            printf("1. Imprimir a fita com as jogados do jogador.\n");
            printf("2. Mostrar o maior e menor saldo consecutivo.\n");
            printf("3. O Valor de uma posicao especifica.\n");
            printf("4. Mostrar empates.\n");
            printf("5. Mostrar o maior conjunto de jogadas com a maior pontuacao.\n");
            printf("6. Limpar a fita e inserir valores novos.\n");
            printf("7. Sair do programa.\n");
            scanf(" %d", &menu2);

            switch (menu2){
            case 1:
                system("cls");

                //Layout para demonstrar a fita
                printf("\nRod ");
                for(i = 0; i < n_rodadas; i++){
                    printf("|%4d ", i+1);
                }
                printf("|\n");

                printf("Pon ");
                for(i = 0; i < n_rodadas; i++){
                    printf("|%4d ", pon[i]);
                }
                printf("|\n\n");
                system("pause");
                
                break;
            case 2:
                system("cls");
                printf("2. Mostrar o maior e menor saldo consecutivo.\n");
                system("pause");
                break;
            case 3:
                system("cls");
                int cont = 0, aux, menu3;

                do{
                printf("Qual posicao? ");
                scanf(" %d", &menu3);
                }while(menu3 < 0 || menu3 > n_rodadas);

                do{
                    cont = 0;
                    for(i = 0; i < (n_rodadas - 1); i++){
                        if(pon_aux[i] < pon_aux[i + 1]){
                            aux = pon_aux[i];
                            pon_aux[i] = pon_aux[i + 1];
                            pon_aux[i + 1] = aux;
                        }else{
                            cont++;
                        }
                    }
                }while(cont < n_rodadas - 1);

                printf("A %d melhor rodada foi com o valor %d.\n", menu3, pon_aux[menu3 - 1]);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("4. Mostrar empates.\n");
                system("pause");
                break;
            case 5:
                system("cls");
                printf("5. Mostrar o maior conjunto de jogadas com a maior pontuacao.\n");
                system("pause");
                break;
            case 6:
                system("cls");
                flag2 = 1;
                break;
            case 7:
                system("cls");
                printf("7. Sair do programa.\n");
                return 0;
                break;
            default:
                system("cls");
                printf("Resposta invalida\n");
                system("pause");
                break;
        }

        system("cls");

        }while(flag2 != 1);
    
    }while(flag != 1);

    return 0;
}
