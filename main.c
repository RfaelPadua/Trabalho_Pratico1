#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int n_rodadas, r1, r2, i, j;
    int flag = 0, flag2 = 0;
    

    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t------------------------------\n");
    printf("\t\t\t\t|                            |\n");
    printf("\t\t\t\t|    JOGO DOS CEM ERROS      |\n");
    printf("\t\t\t\t|                            |\n");
    printf("\t\t\t\t------------------------------\n");
    printf("\n\n\n\n\n\n\n\n");
    system("pause");
    system("cls");

    printf("Quantas rodadas? ");
    scanf(" %d", &n_rodadas);

    system("cls");

    int pon[n_rodadas];

    do{
        flag2 = 0;
        printf("Selecione uma das opcoes a seguir\n");
        printf("1. Gerar valores aleatorios\n");
        printf("2. Inserir valores manualmente\n");
        scanf(" %d", &r1);
        system("cls");

        if(r1 == 1)
        {
            srand(time(NULL));
            for(i = 0; i < n_rodadas; i++)
            {
                pon[i] = (rand() % 201) + (-100);
            }
        }
        else if(r1 == 2)
        {
            for(i = 0; i < n_rodadas; i++)
            {
                printf("Insira o valor da %d rodada: ", i + 1);
                scanf(" %d", &pon[i]);
            }
        }else{
            continue;
        }
        printf("Rod ");

        for(i = 0; i < n_rodadas; i++){
            printf("|%4d| ", i+1);
        }
        printf("\n");

        printf("Pon ");
        for(i = 0; i < n_rodadas; i++){
            printf("|%4d| ", pon[i]);
        }
            printf("\n");
            
            system("pause");
            system("cls");
        

        do{
            printf("Selecione uma das opcoes a seguir\n");
            printf("1. Imprimir a fita com as jogados do jogador.\n");
            printf("2. Mostrar o maior e menor saldo consecutivo.\n");
            printf("3. O Valor de uma posicao especifica.\n");
            printf("4. Mostrar empates.\n");
            printf("5. Mostrar o maior conjunto de jogadas com a maior pontuacao.\n");
            printf("6. Limpar a fita e inserir valores novos.\n");
            printf("7. Sair do programa.\n");
            scanf(" %d", &r2);

            switch (r2)
            {
            case 1:
                system("cls");
                for(i = 0; i < n_rodadas; i++)
                {
                    printf("%d ", pon[i]);
                }
                printf("\n");
                system("pause");
                break;
            case 2:
                system("cls");
                printf("2. Mostrar o maior e menor saldo consecutivo.\n");
                system("pause");
                break;
            case 3:
                system("cls");
                printf("3. O Valor de uma posicao especifica.\n");
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
