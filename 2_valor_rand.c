#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n_rodadas = 17, i;
    int pon[17];

    srand(time(NULL));
    for(i = 0; i < n_rodadas; i++){
        pon[i] = (rand() % 201) + (-100);
    }

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