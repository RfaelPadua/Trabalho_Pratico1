//C�lculo do maior e menor saldo consecutivo

#include<stdio.h>
#include<locale.h>
#define TAM 17



int main(){
	int pon[TAM] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};
	int i, j, n_rodadas, auxiliar, saldo, maior_saldo, menor_saldo, inicio, fim;
	
	n_rodadas = TAM;
	
	/*- C�lculo do maior Saldo
	Para encontrar o maior saldo todo o vetor � percorrido, sendo que para cada posi��o, � verificado se o saldo a partir dessa � o maior (caso a soma
	a partir dessa v� aumentando a cada nova posi��o), e o maior encontrado, a partir da posi��o � ent�o salvo e verificado, ao final das compara��es, se 
	� o maior de todos.
	*/
	for(i = 0; i < n_rodadas; i++){
		if(pon[i] == 0){
			continue;
		}else if(i < n_rodadas - 1){ //Condi��o para verificar se o valor de 'i' � menor que a �ltima posi��o do vetor, para que possam ser feitas as verifica��es
			j = i + 1;
			auxiliar = pon[i] + pon[j];
			saldo = pon[i];
			while(auxiliar > saldo){ //Caso 'auxiliar' seja maior que 'saldo', � ind�cio que essa soma feita em auxiliar resulta em um saldo maior que o anterior calculado, logo o saldo � atualizado. � feito isso enquanto isso for verdadeiro
				saldo = saldo + pon[j];
				j ++;
				if(j < n_rodadas){ //Verificando se acaso a vari�vel 'j' n�o ultrapassa o limite do vetor
					auxiliar = saldo + pon[j];
				}
			}
			
			if(i == 0){ //Condi��o para que, na primeira itera��o (i == 0), a vari�vel de verifica��o 'maior_saldo' seja inicializada com o primeiro saldo calculado
				maior_saldo = saldo;
				inicio = i + 1; //Vari�vel que marca onde inicia essa sequ�ncia
				fim = j; //Vari�vel que marca onde a sequ�ncia termina
			} else{
				if(saldo > maior_saldo){ //Caso o saldo calculado seja maior que o saldo considerado o maior anteriormente, esse passa a ser o maior saldo
					maior_saldo = saldo;
					inicio = i + 1;
					fim = j;
				}
			}
			
		} else{ //Caso chegue na �ltima posi��o do vetor, seu valor tamb�m � comparado para verificar se esse � maior que o maior saldo encontrado anteriormente
			saldo = pon[i];
			if(saldo > maior_saldo){
				maior_saldo = saldo;
				inicio = i + 1;
				fim = j;
			}
		}
	}
	if(fim == inicio){ //Se o in�cio da sequ�cia for igual ao fim, � ind�cio de que n�o se trata de uma sequ�ncia, mas sim de um valor, logo � impressa uma mensagem adequada
		printf("- O maior saldo eh %d, posicao %d", maior_saldo, inicio);
	} else{
		printf("- O maior saldo eh: %d, posicoes %d a %d", maior_saldo, inicio, fim);
	}
	
	
	/*- C�lculo do menor Saldo
	Para encontrar o menor saldo todo o vetor � percorrido, sendo que para cada posi��o, � verificado se o saldo a partir dessa � o menor (caso a soma
	a partir dessa v� diminuindo a cada nova posi��o), e o menor encontrado, a partir da posi��o � ent�o salvo e verificado, ao final das compara��es, se 
	� o menor de todos.
	*/
	for(i = 0; i < n_rodadas; i++){
		if(i < n_rodadas - 1){ //Condi��o para verificar se o valor de 'i' � menor que a �ltima posi��o do vetor, para que possam ser feitas as verifica��es
			j = i + 1;
			auxiliar = pon[i] + pon[j];
			saldo = pon[i];
			while(auxiliar < saldo){ //Caso 'auxiliar' seja menor que 'saldo', � ind�cio que essa soma feita em auxiliar resulta em um saldo menor que o anterior calculado, logo o saldo � atualizado. � feito isso enquanto isso for verdadeiro
				saldo = saldo + pon[j];
				j ++;
				if(j < n_rodadas){ //Verificando se acaso a vari�vel 'j' n�o ultrapassa o limite do vetor
					auxiliar = saldo + pon[j];
				}
			}
			
			if(i == 0){ //Condi��o para que, na primeira itera��o (i == 0), a vari�vel de verifica��o 'menor_saldo' seja inicializada com o primeiro saldo calculado
				menor_saldo = saldo;
				inicio = i + 1; //Vari�vel que marca onde inicia essa sequ�ncia
				fim = j; //Vari�vel que marca onde a sequ�ncia termina
			} else{
				if(saldo < menor_saldo){ //Caso o saldo calculado seja menor que o saldo considerado o menor anteriormente, esse passa a ser o menor saldo
					menor_saldo = saldo;
					inicio = i + 1;
					fim = j;
				}
			}
			
		} else{ //Caso chegue na �ltima posi��o do vetor, seu valor tamb�m � comparado para verificar se esse � menor que o menor saldo encontrado anteriormente
			saldo = pon[i];
			if(saldo < menor_saldo){
				menor_saldo = saldo;
				inicio = i + 1;
				fim = j;
			}
		}
	}
	if(inicio == fim){ //Se o in�cio da sequ�cia for igual ao fim, � ind�cio de que n�o se trata de uma sequ�ncia, mas sim de um valor, logo � impressa uma mensagem adequada
		printf("\n- O menor saldo eh: %d, posicao %d", menor_saldo, inicio);
	} else{
		printf("\n- O menor saldo eh: %d, posicoes %d a %d", menor_saldo, inicio, fim);
	}
	
	return 0;
}
