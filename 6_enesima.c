#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, aux, cont = 0, menu3;
    int n_rodadas = 17;
    int pon[17] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};
    int pon_aux[17] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};

    printf("Qual posicao? ");                   //Pergunta para o usuario qual melhor pontuacao ele quer.
    scanf(" %d", &menu3);

    do{
        cont = 0;                                //Variavel de controle, para saber quantos pares estao ordem certa.
        for(i = 0; i < n_rodadas - 1; i++){
            if(pon_aux[i] < pon_aux[i + 1]){   //Percorre o vetor em pares, colocando em ordem se necessario
                aux = pon_aux[i];
                pon_aux[i] = pon_aux[i + 1];
                pon_aux[i + 1] = aux;
            }else{
                cont++;                          //Se o par estiver na ordem certa, incrementa a variavel de controle
            }
        }
    }while(cont < n_rodadas - 1);                //Percorre o vetor ate a variavel de controle for igual a quantidades de pares.

    printf("A %d melhor rodada foi com o valor %d.\n", menu3, pon_aux[menu3 - 1]);

    return 0;
}
