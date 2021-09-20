#include<stdio.h>
#include<stdlib.h>
#include"ordena.h"

void selection(int vet[],int tamanho);
void insertion(int vet[],int tamanho);
void bolha(int vet[],int tamanho);
void mergesort(int *v, int n);
void sort(int *vet, int *c, int i, int f);
void merge(int *vet, int *c, int i, int m, int f);
void quick_sort(int *a, int left, int right);
void imprimi_num(int vet[], int tamanho);
void shellSort(int *vet, int tamanho);
void salva_arq(int vet[]);
void cocktail_sort(int vet[], int tamanho);

main() {
	int i, tamanho=20;
	int escolha;
    int vet[20];
    srand(time(NULL));
    vet[i] = (int *) malloc(tamanho * sizeof(int));
    do{
    printf("\n\n\a Escolha um metodo de ordenação...");
    printf("\n\a [1] - Selection");
    printf("\n\a [2] - Insertion");
    printf("\n\a [3] - Bolha");
    printf("\n\a [4] - Merge");
    printf("\n\a [5] - Quick");
    printf("\n\a [6] - Shell Sort");
    printf("\n\a [7] - Cocktail Sort \n");
    printf("\n\a Digite um número: ");
    scanf("%d", &escolha);
    if((escolha < 1) || (escolha > 7)) {
    	printf("\n\a Número invalido!");
	}
	}while((escolha < 1) || (escolha > 7));
    
    for(i = 0; i < tamanho; i++){
        vet[i] = rand() % 100;
    }
    
    switch(escolha) {
    	case  1:
    	// Funciona
    		selection(vet, tamanho);
    		imprimi_num(vet, tamanho);
			break;
		case 2: 
		// Funciona
			insertion(vet, tamanho);
			imprimi_num(vet, tamanho);
			break;
			
		case 3: 
		// Funciona
			bolha(vet, tamanho);
			imprimi_num(vet, tamanho);
			break;
		
		case 4: 
		// Funciona
			mergesort(vet, tamanho);
			imprimi_num(vet, tamanho);
			break;
		case 5: 
		// Funciona
			quick_sort(vet, 0, tamanho - 1);
			imprimi_num(vet, tamanho);
			break;
		case 6:
		// Funciona
			shellSort(vet, tamanho);
			imprimi_num(vet, tamanho);
		break;
		case 7:
		// Funciona
			cocktail_sort(vet, tamanho);
			imprimi_num(vet, tamanho);
			break;		
	}
	FILE *fp;
    char vet1[]="Numeros Sorteados.txt";
    if (vet == NULL){
        printf("Erro ao alocar vetor");
        return 0;       
    }
    fp=fopen(vet1,"w");
    for (i=0; i<tamanho; i++){ 
    	fprintf(fp,"Posição %i - %d \n", i+1, vet[i]);
    }
    fclose(fp);	
}

void imprimi_num(int vet[], int tamanho) {
	int i;
	for(i = 0; i < tamanho; i++){	
		printf("\a %i - %d \n", i+1, vet[i]);
	}
}
