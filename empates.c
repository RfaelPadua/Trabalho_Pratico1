#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> //Biblioteca para trabalhar com variável booleana



int main() {
    int i, j, cont, n_rodadas, menu1;
    int tempEmpate, tempOcorrencia; //Variáveis do bloco "Ordenando os empates e suas ocorrências em ordem decrescente"
    bool haEmpates = false;
    
    printf("Quantas rodadas? ");
    scanf(" %d", &n_rodadas);
    system("cls");
    
    int pon[n_rodadas], empates[n_rodadas], ocorrencias[n_rodadas];
    
    //Como o vetor 'ocorrencias' funcionará como um contador, ele deverá ser inicializado com 0, para todas suas posições
    for(i = 0; i < n_rodadas; i++){
    	ocorrencias[i] = 0;
	}
    
    printf("Selecione uma das opcoes a seguir\n");
    printf("1. Gerar valores aleatorios\n");
    printf("2. Inserir valores manualmente\n");
    scanf(" %d", &menu1);
    system("cls");
    
    if(menu1 == 1){
        srand(time(NULL));
        for(i = 0; i < n_rodadas; i++){
            pon[i] = (rand() % 201) + (-100);
        }
    }else if(menu1 == 2){
    	for(i = 0; i < n_rodadas; i++){
        	printf("Insira o valor da %d rodada: ", i + 1);
            scanf(" %d", &pon[i]);
        }
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
    system("pause");
    system("cls");
    
    /*
	VETOR DE EXEMPLO: 70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10
	2, 3, 2
	*/
    
	//Definindo todas as posições do vetor de empates para o menor número possível
    for (i = 0; i < n_rodadas; i++) {
        empates[i] = INT_MIN;
    }
    
    // Encontrando as rodadas empatadas e armazenando no vetor de empates
    for (i = 0; i < n_rodadas; i++) {
        for (j = i + 1; j < n_rodadas; j++) {
            if (pon[i] == pon[j]) {
                empates[i] = pon[i];
                empates[j] = pon[i];
                haEmpates = true;
            }
        }
    }
    
    if (haEmpates == true) {
        printf("Empates:\n\n");
        
        // Contando as ocorrências de cada empate
        for (i = 0; i < n_rodadas; i++) {
            if (empates[i] != INT_MIN) {
                ocorrencias[i]++;
                for (j = i + 1; j < n_rodadas; j++) {
                    if (empates[i] == empates[j]) {
                        ocorrencias[i]++;
                    }
                }
            }
        }
        
        // Ordenando os empates e suas ocorrências em ordem decrescente
        for (i = 0; i < n_rodadas - 1; i++) {
            for (j = 0; j < n_rodadas - i - 1; j++) {
                if (ocorrencias[j] < ocorrencias[j + 1]) {
                    // Trocando a posição dos empates
                    tempEmpate = empates[j];
                    empates[j] = empates[j + 1];
                    empates[j + 1] = tempEmpate;
                    
                    // Trocando a posição das ocorrências
                    tempOcorrencia = ocorrencias[j];
                    ocorrencias[j] = ocorrencias[j + 1];
                    ocorrencias[j + 1] = tempOcorrencia;
                }
            }
        }
        
        // Exibindo os empates em ordem decrescente pela quantidade de ocorrências
        for (i = 0; i < n_rodadas; i++) {
            if (empates[i] != INT_MIN) {
                cont = 1;
                
                // Verificando se o empate já foi contado anteriormente
                for (j = 0; j < i; j++) {
                    if (empates[i] == empates[j]) {
                        cont = 0;
                        break;
                    }
                }
                
                // Imprimindo o empate e a quantidade
                if (cont == 1) {
                    printf("%4d (%d vezes)\n", empates[i], ocorrencias[i]);
                }
            }
        }
    }
    else {
        printf("Nao houve empates.\n");
    }
    
    return 0;
}

