//Cálculo do maior e menor saldo consecutivo

#include<stdio.h>
#include<locale.h>
#define TAM 17



int main(){
	int pon[TAM] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};
	int i, j, n_rodadas, auxiliar, saldo, maior_saldo, menor_saldo, inicio, fim;
	
	n_rodadas = TAM;
	
	/*- Cálculo do maior Saldo
	Para encontrar o maior saldo todo o vetor é percorrido, sendo que para cada posição, é verificado se o saldo a partir dessa é o maior (caso a soma
	a partir dessa vá aumentando a cada nova posição), e o maior encontrado, a partir da posição é então salvo e verificado, ao final das comparações, se 
	é o maior de todos.
	*/
	for(i = 0; i < n_rodadas; i++){
		if(pon[i] == 0){
			continue;
		}else if(i < n_rodadas - 1){ //Condição para verificar se o valor de 'i' é menor que a última posição do vetor, para que possam ser feitas as verificações
			j = i + 1;
			auxiliar = pon[i] + pon[j];
			saldo = pon[i];
			while(auxiliar > saldo){ //Caso 'auxiliar' seja maior que 'saldo', é indício que essa soma feita em auxiliar resulta em um saldo maior que o anterior calculado, logo o saldo é atualizado. É feito isso enquanto isso for verdadeiro
				saldo = saldo + pon[j];
				j ++;
				if(j < n_rodadas){ //Verificando se acaso a variável 'j' não ultrapassa o limite do vetor
					auxiliar = saldo + pon[j];
				}
			}
			
			if(i == 0){ //Condição para que, na primeira iteração (i == 0), a variável de verificação 'maior_saldo' seja inicializada com o primeiro saldo calculado
				maior_saldo = saldo;
				inicio = i + 1; //Variável que marca onde inicia essa sequência
				fim = j; //Variável que marca onde a sequência termina
			} else{
				if(saldo > maior_saldo){ //Caso o saldo calculado seja maior que o saldo considerado o maior anteriormente, esse passa a ser o maior saldo
					maior_saldo = saldo;
					inicio = i + 1;
					fim = j;
				}
			}
			
		} else{ //Caso chegue na última posição do vetor, seu valor também é comparado para verificar se esse é maior que o maior saldo encontrado anteriormente
			saldo = pon[i];
			if(saldo > maior_saldo){
				maior_saldo = saldo;
				inicio = i + 1;
				fim = j;
			}
		}
	}
	if(fim == inicio){ //Se o início da sequêcia for igual ao fim, é indício de que não se trata de uma sequência, mas sim de um valor, logo é impressa uma mensagem adequada
		printf("- O maior saldo eh %d, posicao %d", maior_saldo, inicio);
	} else{
		printf("- O maior saldo eh: %d, posicoes %d a %d", maior_saldo, inicio, fim);
	}
	
	
	/*- Cálculo do menor Saldo
	Para encontrar o menor saldo todo o vetor é percorrido, sendo que para cada posição, é verificado se o saldo a partir dessa é o menor (caso a soma
	a partir dessa vá diminuindo a cada nova posição), e o menor encontrado, a partir da posição é então salvo e verificado, ao final das comparações, se 
	é o menor de todos.
	*/
	for(i = 0; i < n_rodadas; i++){
		if(i < n_rodadas - 1){ //Condição para verificar se o valor de 'i' é menor que a última posição do vetor, para que possam ser feitas as verificações
			j = i + 1;
			auxiliar = pon[i] + pon[j];
			saldo = pon[i];
			while(auxiliar < saldo){ //Caso 'auxiliar' seja menor que 'saldo', é indício que essa soma feita em auxiliar resulta em um saldo menor que o anterior calculado, logo o saldo é atualizado. É feito isso enquanto isso for verdadeiro
				saldo = saldo + pon[j];
				j ++;
				if(j < n_rodadas){ //Verificando se acaso a variável 'j' não ultrapassa o limite do vetor
					auxiliar = saldo + pon[j];
				}
			}
			
			if(i == 0){ //Condição para que, na primeira iteração (i == 0), a variável de verificação 'menor_saldo' seja inicializada com o primeiro saldo calculado
				menor_saldo = saldo;
				inicio = i + 1; //Variável que marca onde inicia essa sequência
				fim = j; //Variável que marca onde a sequência termina
			} else{
				if(saldo < menor_saldo){ //Caso o saldo calculado seja menor que o saldo considerado o menor anteriormente, esse passa a ser o menor saldo
					menor_saldo = saldo;
					inicio = i + 1;
					fim = j;
				}
			}
			
		} else{ //Caso chegue na última posição do vetor, seu valor também é comparado para verificar se esse é menor que o menor saldo encontrado anteriormente
			saldo = pon[i];
			if(saldo < menor_saldo){
				menor_saldo = saldo;
				inicio = i + 1;
				fim = j;
			}
		}
	}
	if(inicio == fim){ //Se o início da sequêcia for igual ao fim, é indício de que não se trata de uma sequência, mas sim de um valor, logo é impressa uma mensagem adequada
		printf("\n- O menor saldo eh: %d, posicao %d", menor_saldo, inicio);
	} else{
		printf("\n- O menor saldo eh: %d, posicoes %d a %d", menor_saldo, inicio, fim);
	}
	
	return 0;
}
