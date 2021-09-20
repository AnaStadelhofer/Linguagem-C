// SELECÃO OBS: NÃO É O LIVRO NÃO
// ele vai buscar o proximo menor numero para adicionar na sequencia, ele vai percorrer todo o vetor para isso
void selection(int vet[],int tamanho){
	int i, j, aux, menor;
	  
		for(i = 0; i < tamanho-1; i++) {
			menor = i;
			for(j = i+1; j < tamanho; j++) {
				if(vet[j] < vet[menor]) {
					menor = j;
				}
			}
		aux = vet[i]; vet[i] = vet[menor]; vet[menor] = aux; //troca
		}
}

//// INSERIR :3

void insertion(int vet[],int tamanho) {
	// Ele começa da esquerda e vai indo para a direita, se o valor da direita é menor ele troca de lugar, se maior ele continua no lugar e faz a verificação dnv
	// Se ele for menor ele faz uma verificação com os numeros que já passaram tbm
	int i, aux, j;
	for(i = 1; i < tamanho; i++){
		aux = vet[i];
		j = i - 1;
		while(j >= 0 && vet[j] > aux) {
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = aux;
	}
		vet[j] = aux;
}	

//// BOLHINHA


void bolha(int vet[],int tamanho) {
	// Esse metodo vai comparando dois elementos a dois elementos, tipo a com b, b com c...
	int i, j, aux;
	// coloca em ordem crescente (1,2,3...) 
	for( i = 0; i < tamanho; i++ )
  	{
    	for( j = i + 1; j < tamanho; j++ ) // sempre 1 elemento à frente
    	{
      		// se i maior que i+1 então vai passar para a frente
      		if ( vet[i] > vet[j] )
      		{
         		aux = vet[i];
         		vet[i] = vet[j];
         		vet[j] = aux;
      		}
    	}
  	} // Acabou a ordebaçaõ :)
}

//// MERGE SORT ----------------------------------------------------------
// Ele vai dividindo os numeros em pares e ordendando, dpois junta eles de novo e ordena e assim vai indo
void mergesort(int *vet, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(vet, c, 0, n - 1);
  free(c);
}

//  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
//  O vetor c é utilizado internamente durante a ordenação.

void sort(int *vet, int *c, int i, int f) {
  if (i >= f) return;
  int m = (i + f) / 2;
  sort(vet, c, i, m);
  sort(vet, c, m + 1, f);
  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (vet[m] <= vet[m + 1]) return;
  merge(vet, c, i, m, f);
}

void merge(int *vet, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = vet[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] <= c[ic]) vet[z++] = c[iv++];
    else vet[z++] = c[ic++];
  }
  while (iv <= m) vet[z++] = c[iv++];
  while (ic <= f) vet[z++] = c[ic++];
}


// utiliza a divisão e conquista, ele divide o problema em pequenas partes e fazer uma ordenação por partes (tipo, divide em dois e ordena os dois do menor para maior e depois junta eles dnv)
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

// parecido com inserção, porem ele troca por valores longe do principal
void shellSort(int *vet, int tamanho) {
    int i , j , value;
    int gap = 1;
    while(gap < tamanho) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < tamanho; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}

// Ele pega o maior numero e coloca na direita e depois faz a busca de novo
 void cocktail_sort(int vet[], int tamanho) {
    int length,bottom,top, swapped,i,aux;
    length=tamanho;
    bottom = 0;
    top = length - 1;
    swapped = 0; 
    while(swapped == 0 && bottom < top)//Se não houver troca de posições ou o ponteiro que
    {                                   //sobe ultrapassar o que desce, o vetor esta ordenado
        swapped = 1; 
        //Este for é a “ida” para a direita
        for(i = bottom; i < top; i = i + 1)
        {
            if(vet[i] > vet[i + 1])   //indo pra direita:testa se o próximo é maior
            {   //indo pra direita:se o proximo é maior que o atual,
                //troca as posições
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                swapped = 0;
            }
        }//fecha for
        // diminui o  `top` porque o elemento com o maior valor 
        // já está na direita (atual posição top)
        top = top - 1; 
        //Este for é a “ida” para a esquerda
        for(i = top; i > bottom; i = i - 1)
        {  if(vet[i] < vet[i - 1]) 
            {
                aux=vet[i];
                vet[i]=vet[i-1];
                vet[i-1]=aux;
                swapped = 0;
            }
        }
        //aumenta o `bottom` porque o menor valor já está
        //na posição inicial (bottom) 
        bottom = bottom + 1;  
    }//fecha while 
 }// fim da funçao

