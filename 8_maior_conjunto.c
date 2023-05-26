//C�lculo do maior conjunto de jogadas com maior pontua��o

#include<stdio.h>
#include<stdlib.h>
#define TAM 17



int main(){
	int pon[TAM] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};
	int i, j, soma, maior_soma, maior_conju, auxiliar, inicio, fim;
	
	//'for' que percorre todo o vetor para fazer as verifica��es em todas as posi��es
	for(i = 0; i < TAM; i++){
		if(pon[i] == 0){
			continue; //Caso o valor do vetor na ite��o 'i' seja 0, a mesma � ignorada, uma vez que a soma come�ando por ela n�o altera nada
		}
		//Inicializando as vari�veis
		soma = pon[i];
		maior_soma = soma;
		auxiliar = i; //Vari�vel que � inicializada com 'i' e caso seja encontrada uma maior soma a partir de 'i', a mesma � atualizada com o valor de 'j'
		//'for' que percorre todo o vetor a partir da posi��o seguinte a determnada por 'i' e que controla um acumulador que soma as posi��es
		for(j = i + 1; j < TAM; j++){
			soma += pon[j]; //Acumulador
			
			//Caso a soma com o valor do vetor na posi��o 'j' seja maior que uma soma considerada a maior anteriormente, essa maior soma � atualizada
			if(soma > maior_soma){
				maior_soma = soma;
				auxiliar = j; //Vari�vel que guarda o valor de 'j', que corresponde ao fim da sequ�ncia que gerou a maior soma
			}
		}
		
		//Caso esteja na primeira itera��o, a vari�vel que compreende o conjunto com os maiores valores � inicialiada com a maior soma encontrada para essa itera��o
		if(i == 0){
			maior_conju = maior_soma;
		} else{
			//Se a maior soma encontrada para essa itera��o for maior que o conjunto considerado o maior anteriormente, o mesmo � atualizado com essa (DEVE SER >=)
			if(maior_soma > maior_conju){
				maior_conju = maior_soma;
				inicio = i; //Vari�vel que guarda o valor de 'i', que corresponde ao in�cio do conjunto (sequ�ncia que gerou a maior soma)
				fim = auxiliar; //Vari�vel que corresponde ao fim do conjunto
			}
		}
	}
	//Se o in�cio da sequ�cia for igual ao fim, � ind�cio de que n�o se trata de uma sequ�ncia, mas sim de um valor, logo � impressa uma mensagem adequada
	if(inicio == fim){
		printf("Nao ha um conjunto com as jogadas de maior pontuacao.");
		printf("\nLogo, a jogada com a melhor pontuacao eh: %d, posicao %d", maior_conju, inicio);
	} else{
		printf("O conjunto de jogadas com a maior pontuacao eh: %d, posicoes %d a %d", maior_conju, inicio + 1, fim + 1);
	}
	
	return 0;
}
