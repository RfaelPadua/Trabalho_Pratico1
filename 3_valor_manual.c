#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n_rodadas = 17;
    int pon[17];

    for(i = 0; i < n_rodadas; i++){ // Laco para pedir para o usuario o valor de cada rodada.
        printf("Insira o valor da %d rodada: ", i + 1);
        scanf(" %d", &pon[i]);
    }
    
    //Layout de impressao
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
    
    return 0;
}
