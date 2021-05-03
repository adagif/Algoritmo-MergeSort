
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void imprimir(int vetor[]){
	int i;
	printf("\n\n");
	for(i=0;i<TAM;i++){
		printf("%d ",vetor[i]);
	}
	printf("\n\n");
}
//une os dois subvetores criados ao dividir o principal
void merge(int vetor[TAM],int indiceEsquerda,int meio,int indiceDireita){
	int i,j,k;

	int n1 = meio- indiceEsquerda + 1;
	int n2 = indiceDireita - meio;

	int vetorEsquerda[n1];	
	int vetorDireita[n2];

	//passando os valores do vetor principal para o auxiliar
	for(i=0;i<n1;i++){
		vetorEsquerda[i] = vetor[indiceEsquerda+i];
	}

	for(j=0;j<n2;j++){
		vetorDireita[j] = vetor[meio + 1 + j];
	}
	k=indiceEsquerda;
	i=0; 
	j=0;

	while(i<n1 && j <n2){
		//Caso o valor da esquerda seja menor
		if(vetorEsquerda[i]<= vetorDireita[j]){
			vetor[k] = vetorEsquerda[i];
			i++;
		}
		else{
			vetor[k] = vetorDireita[j];
			j++;
		}
		k++; // Aumenta o indice de posicionamento do vetor

	}
	//Verificação: caso falte algum elemento no vetor
	while(i<n1){
		vetor[k] = vetorEsquerda[i];
		i++;
		k++;
	}

	while(j<n2){
		vetor[k] = vetorDireita[j];
		j++;
		k++;
	}

}

void mergeSort(int vetor[TAM],int indiceEsquerda, int indiceDireita ){

	int meio;
	if(indiceEsquerda < indiceDireita){
		meio = indiceEsquerda + (indiceDireita - indiceEsquerda)/2;
		mergeSort(vetor,indiceEsquerda,meio);
		mergeSort(vetor,meio+1,indiceDireita);
		merge(vetor,indiceEsquerda,meio,indiceDireita);
	}
}


int main(){
	int vetor[TAM] = {6,5,2,1,3,4,7,9,8,10};
	printf("\nAntes: ");
	imprimir(vetor);

	mergeSort(vetor,0,TAM-1);

	printf("\nDepois: ");
	imprimir(vetor);

	return 0;
}