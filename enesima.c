#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, aux, cont = 0, menu3;
    int n_rodadas = 17;
    int pon[17] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};
    int vetoraux[17] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};

    printf("Qual posicao? ");
    scanf(" %d", &menu3);

    do{
        cont = 0;
        for(i = 0; i < (n_rodadas - 1); i++){
            if(vetoraux[i] < vetoraux[i + 1]){
                aux = vetoraux[i];
                vetoraux[i] = vetoraux[i + 1];
                vetoraux[i + 1] = aux;
            }else{
                cont++;
            }
        }
    }while(cont < 16);

    printf("A %d melhor rodada foi com o valor %d.\n", menu3, vetoraux[menu3 - 1]);

}