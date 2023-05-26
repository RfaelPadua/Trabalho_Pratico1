#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n_rodadas = 17, i;
    int pon[17];

    srand(time(NULL)); // definir a semente "time" para gerar os numeros aleatorios.
    for(i = 0; i < n_rodadas; i++){
        pon[i] = (rand() % 201) + (-100); // Gerar numero aleatorio no range de -100 a 100, usando a funcao rand
    }                                     // (rand() % 201) + (-100)
                                          //Gera 201 numeros possiveis de 0 a 200 / -100 para ajustar o intervalo para -100 a 100.
    //Layout de Impressao
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
