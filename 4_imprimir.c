#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n_rodadas = 17;
    int pon[17] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};

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

    return 0;
}
