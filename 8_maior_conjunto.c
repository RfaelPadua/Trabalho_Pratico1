//Cálculo do maior conjunto de jogadas com maior pontuação

#include<stdio.h>
#include<stdlib.h>
#define TAM 17



int main(){
	int pon[TAM] = {70, -67, -10, 34, 23, 65, 87, 9, 0, -10, 4, 10, 20, 30, 9, -5, -10};
	int i, j, soma, maior_soma, maior_conju, auxiliar, inicio, fim;
	
	//'for' que percorre todo o vetor para fazer as verificações em todas as posições
	for(i = 0; i < TAM; i++){
		if(pon[i] == 0){
			continue; //Caso o valor do vetor na iteção 'i' seja 0, a mesma é ignorada, uma vez que a soma começando por ela não altera nada
		}
		//Inicializando as variáveis
		soma = pon[i];
		maior_soma = soma;
		auxiliar = i; //Variável que é inicializada com 'i' e caso seja encontrada uma maior soma a partir de 'i', a mesma é atualizada com o valor de 'j'
		//'for' que percorre todo o vetor a partir da posição seguinte a determnada por 'i' e que controla um acumulador que soma as posições
		for(j = i + 1; j < TAM; j++){
			soma += pon[j]; //Acumulador
			
			//Caso a soma com o valor do vetor na posição 'j' seja maior que uma soma considerada a maior anteriormente, essa maior soma é atualizada
			if(soma > maior_soma){
				maior_soma = soma;
				auxiliar = j; //Variável que guarda o valor de 'j', que corresponde ao fim da sequência que gerou a maior soma
			}
		}
		
		//Caso esteja na primeira iteração, a variável que compreende o conjunto com os maiores valores é inicialiada com a maior soma encontrada para essa iteração
		if(i == 0){
			maior_conju = maior_soma;
		} else{
			//Se a maior soma encontrada para essa iteração for maior que o conjunto considerado o maior anteriormente, o mesmo é atualizado com essa (DEVE SER >=)
			if(maior_soma > maior_conju){
				maior_conju = maior_soma;
				inicio = i; //Variável que guarda o valor de 'i', que corresponde ao início do conjunto (sequência que gerou a maior soma)
				fim = auxiliar; //Variável que corresponde ao fim do conjunto
			}
		}
	}
	//Se o início da sequêcia for igual ao fim, é indício de que não se trata de uma sequência, mas sim de um valor, logo é impressa uma mensagem adequada
	if(inicio == fim){
		printf("Nao ha um conjunto com as jogadas de maior pontuacao.");
		printf("\nLogo, a jogada com a melhor pontuacao eh: %d, posicao %d", maior_conju, inicio);
	} else{
		printf("O conjunto de jogadas com a maior pontuacao eh: %d, posicoes %d a %d", maior_conju, inicio + 1, fim + 1);
	}
	
	return 0;
}
