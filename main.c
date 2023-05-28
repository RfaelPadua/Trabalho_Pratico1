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

    printf("Quantas rodadas? ");//Pedir para o usuario definar a quantidade de rodadas;
    scanf(" %d", &n_rodadas);

    system("cls");

    int pon[n_rodadas];//Criar o vetor referente as pontuacoes das rodadas.
    int pon_aux[n_rodadas];


    do{
        //Primeiro Menu, para definir os valores de cada rodada.
        flag2 = 0;
        printf("Selecione uma das opcoes a seguir\n");
        printf("1. Gerar valores aleatorios\n");
        printf("2. Inserir valores manualmente\n");
        scanf(" %d", &menu1);
        system("cls");

        
        if(menu1 == 1){ 
            srand(time(NULL)); // definir a semente "time" para gerar os numeros aleatorios.
            for(i = 0; i < n_rodadas; i++){
                pon[i] = (rand() % 201) + (-100); // Gerar numero aleatorio no range de -100 a 100, usando a funcao rand
            }                                     // (rand() % 201) + (-100)
                                                  //Gera 201 numeros possiveis de 0 a 200 / -100 para ajustar o intervalo para -100 a 100.

        }else if(menu1 == 2){
            for(i = 0; i < n_rodadas; i++){ //Laco para pedir para o usuario o valor de cada rodada.
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
        printf("\nRod ");         // cabecalho da fita, Rod = rodada.
        for(i = 0; i < n_rodadas; i++){
            printf("|%4d ", i+1); // %4d para reservar 4 espaços para a impressao dos numeros,
        }                         //ja que o maior quantidade de digitos possivel na fita eh em -100
        printf("|\n");

        printf("Pon ");           // cabecalho da fita, Pon = Pontuacao.
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

                printf("\nRod ");// cabecalho da fita, Rod = rodada.
                for(i = 0; i < n_rodadas; i++){
                    printf("|%4d ", i+1); // %4d para reservar 4 espaços para a impressao dos numeros,
                }                         //ja que o maior quantidade de digitos possivel na fita eh em -100
                printf("|\n");

                printf("Pon ");// cabecalho da fita, Pon = Pontuacao.
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

                printf("Qual posicao? ");                   //Pergunta para o usuario qual melhor pontuacao ele quer.
                scanf(" %d", &menu3);

                do{
                    cont = 0;                                //Variavel de controle, para saber quantos pares estao ordem certa.
                    for(i = 0; i < n_rodadas - 1; i++){
                        if(pon_aux[i] < pon_aux[i + 1]){    //Percorre o vetor em pares, colocando em ordem se necessario
                            aux = pon_aux[i];
                            pon_aux[i] = pon_aux[i + 1];
                            pon_aux[i + 1] = aux;
                        }else{
                            cont++;                          //Se o par estiver na ordem certa, incrementa a variavel de controle
                        }
                    }
                }while(cont < n_rodadas - 1);                //Percorre o vetor ate a variavel de controle for igual a quantidades de pares.

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
