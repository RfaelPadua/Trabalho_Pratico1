#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int fita[17] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};

    printf("Rod ");
    for(i = 0; i < 17; i++){
        printf("|%4d| ", i+1);
    }
    printf("\n");

    printf("Pon ");
    for(i = 0; i < 17; i++){
        printf("|%4d| ", fita[i]);
    }

    printf("\n");
    system("pause");

    return 0;
}
