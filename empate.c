#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, empate, valor;
    int pon[5] = {9, -10, 23, 9, -10};

    empate = 0;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
                if(pon[i] == pon[j]){
                    empate++;
                    valor = pon[i];
            }
        }
        if(empate > 1){
            printf("valor %d, %d vezes.\n", valor, empate);
        }
        empate = 0;
    }
    printf("%d", empate);

}