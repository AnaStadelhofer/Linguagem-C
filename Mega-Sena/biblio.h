#include<iostream>
#include "cores.h"
#include <time.h>

using namespace std;

// LOGO CAIXA MEGA SENA
void logo_caixa(int qtd){
	system("color 10");
	textcolor(WHITE);
cout<< "\n====================================================================================================" ;
cout<< "\n=                                                                                                  =" ;
cout<< "\n=   ********************************************************************************************   =" ;
cout<< "\n=   ********************************************************************************************   =" ;
cout<< "\n=   ********************************************************************************************   =" ;
cout<< "\n=   *******************&@@@@@@@@@@@@@@@@@@@@@@@@@@@*************###########################*****   =" ;
cout<< "\n=   ********************@@@@@@@@@@@@@@@@@@@@@@@@@@@@***********###########################******   =" ;
cout<< "\n=   **********************@@@@@@@@@@@@@@@@@@@@@@@@@@@(******############################********   =" ;
cout<< "\n=   ***********************@@@@@@@@@@@@@@@@@@@@@@@@@@@@***###########################***********   =" ;
cout<< "\n=   ************************%@@@@@@@@@@@@@@@@@@@@@@@@@@@###########################*************   =" ;
cout<< "\n=   **************************@@@@@@@@@@@@@@@@@@@@@@@@@@@#######################(***************   =" ;
cout<< "\n=   ***************************@@@@@@@@@@@@@@@@@@@@@@@@@@@%###################******************   =" ;
cout<< "\n=   ****************************@@@@@@@@@@@@@@@@@@@@@@@@@@@@################********************   =" ;
cout<< "\n=   *****************************#@@@@@@@@@@@@@@@@@@@@@@@@@@@############/**********************   =" ;
cout<< "\n=   *******************************@@@@@@@@@@@@@@@@@@@@@@@@@@@#########******* =============== *   =" ;
cout<< "\n=   ********************************@@@@@@@@@@@@@@@@@@@@@@@@@@@&#####********* [  APERTE EM  ] *   =" ;
cout<< "\n=   *********************************@@@@@@@@@@@@@@@@@@@@@@@@@@@@#************ [   QUALQUER  ] *   =" ;
cout<< "\n=   ************************************************************************** [    TECLA    ] *   =" ;
cout<< "\n=   *******************************###########################@@************** =============== *   =" ;
cout<< "\n=   ****************************(###########################@@@@@*************                 *   =" ;
cout<< "\n=   *************************###########################&@@@@@@@@*******************************   =" ;
cout<< "\n=   ************************###########################@@@@@@@@@@@@%****************************   =" ;
cout<< "\n=   *********************############################@@@@@@@@@@@@@@@@***************************   =" ;
cout<< "\n=   *******************###########################@@@@@@@@@@@@@@@@@@@@**************************   =" ;
cout<< "\n=   ****************/###########################@@@@@@@@@@@@@@@@@@@@@@@*************************   =" ;
cout<< "\n=   *************###########################%@@@@@@@@@@@@@@@@@@@@@@@@@@&************************   =" ;
cout<< "\n=   ************###########################***&@@@@@@@@@@@@@@@@@@@@@@@@@@@**********************   =" ;
cout<< "\n=   *********(###########################******/@@@@@@@@@@@@@@@@@@@@@@@@@@@*********************   =" ;
cout<< "\n=   *******###########################/**********@@@@@@@@@@@@@@@@@@@@@@@@@@@/*******************   =" ;
cout<< "\n=   ****/###########################**************@@@@@@@@@@@@@@@@@@@@@@@@@@@@******************   =" ;
cout<< "\n=   ********************************************************************************************   =" ;
cout<< "\n=   ********************************************************************************************   =" ;
cout<< "\n=                                                                                                  =" ;
cout<< "\n====================================================================================================" ;
}
// NUMERO DO USUARIO ALEATORIO
void num_aleatorio(int num[], int qtd){
	int i;
	for(i=0; i<qtd; i++){ // Número aleatorio
					num[i] = (rand()%60)+1;
	          	} 
}
// REFAZ OS NUMEROS REPETIDOS DO USUARIO
void refazer_sorteio_num_repetido(int qtd, int num[]) {
	int i, j, f;
	for(f=0; f<qtd; f++){
		for (i=0; i<qtd; i++){
				      for(j=i+1; j<qtd; j++) {
				          if (num[i] == num[j])
				              num[i] = (rand()%60)+1;
				      }}}
}
// ARRUMA OS NUMEROS DA PESSOA EM ORDEM CRESCENTE
void arrumar_num_ordem_crescente(int qtd, int num[], int aux) {
	int i, j;
	  // ARRUMAR EM ORDEM CRESCENTE
				for(i=0; i<qtd; i++) {
				    for(j=i+1;j<qtd; j++) { // sempre 1 elemento à frente 
				      // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
				      if (num[i] > num[j]) {
				         aux = num[i];
				         num[i] = num[j];
				         num[j] = aux;
				      }}} // fim da ordenação  
}
// MOSTRA OS VALORES DE SEUS NUMEROS TODOS COLORIDOS E BUNITOS
void imprimir_valores_ordenados(int qtd, int num[]) {
	int i;
 	for(i=0; i<qtd; i++){ 
					if(i % 2 == 0) {
						textcolor(GREEN);
						cout<<" "<<num[i];
					}
					if(i % 2 == 1) {
						textcolor(RED);
						cout<<" "<<num[i];
					}
	          	} 
}
// FAZ O SORTEIO DOS NUMEROS PARA GANHAR O PREMIO TOP E ORDENA ELES
void sorteio_numero_megasena(int sorteio[], int aux, int qtd){
	int i, j;
	srand(time(NULL));  // função que inicializa o gerador de números randômicos
    			srand((unsigned)time(NULL));
			    	for(i=0; i<6; i++) {
			    	sorteio[i] = (rand()%60)+1;	
			   		} // FIM DO SORTEIO E COMEÇO DA ORDENAÇÃO
			    	for(i=0; i<6; i++) {
				    for(j=i+1;j<6; j++) { // sempre 1 elemento à frente 
				      // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
				      if (sorteio[i] > sorteio[j]) {
				         aux = sorteio[i];
				         sorteio[i] = sorteio[j];
				         sorteio[j] = aux;
				      }}} // FIM DA ORDENAÇÃO
			}
// REFAZ NUMEROS REPETIDOS DO NUM PREMIADO
void sorteio_repetido(int qtd, int sorteio[]) {
	int i, j, f;
	for (i=0; i<qtd; i++){
				    for(j=i+1; j<qtd; j++){
				    	if(sorteio[i] == sorteio[j])
				            sorteio[i] = (rand()%60)+1;
				      }}}
// EXIBI RESULTADOS SORTEIO
void exibi_sorteio(int sorteio[]){
	int i;
	for(i=0;i<6; i++){
					textcolor(LIGHT_BLUE);
					cout<<" "<<sorteio[i];
				}
}
////////////////////

void resultado_megasena(int qtd, int sorteio[], int num[]){
	int i, j, contador=0;
	for(i=0; i<qtd; i++){
		for(j=0; j<6; j++){
			if(sorteio[j] == num[i])
			contador++;
				
		}}
					cout<<"\n ACERTOS "<<contador;	
	}

// CASE 2
// INFORMAR NUM PROPRIO DO USUARIO
void num_proprio(int num[], int qtd){
	int i;
	for(i=0; i<qtd; i++){
		do { // VALIDA O NÚMERO ESCOLHIDO
			cout<<"\n Qual seu "<<i+1<<"a número? ";
			cin>>num[i];
				if((num[i] < 0) || (num[i] > 60)) {
					cout<<"\n Número invalido, digite outro.";
					cout<<"\n Qual seu "<<i+1<<"a número? ";
					cin>>num[i];
				}} while((num[i] < 0) || (num[i] > 60)); // TERMINO DA VALIDAÇÃO
		}}
// VALIDAÇÃO DO NUM PROPRIO, SE REPETIU
int confirmar_num_repetido_case2(int num[],int qtd){
	int i, j, contrepetiu=0;
		for (i=0; i<qtd; i++){
				      for(j=i+1; j<qtd; j++){
				          if(num[i] == num[j])
				             contrepetiu++; 
				      }}
		return(contrepetiu);
}
// EXIBIR NUM PROPRIO DO USUARIO
void exibir_num_proprio(int num[], int qtd) {
	int i;
	for(i=0; i<qtd; i++){
		if(i % 2 == 0) {
			textcolor(BROWN);
			cout<<" "<<num[i];
		}
		if(i % 2 == 1) {
			textcolor(LIGHT_BLUE);
			cout<<" "<<num[i];
		}
	}	
}

finaliza_programa(int escolha){
	textcolor(LIGHT_BLUE);
	cout<<"\n\n Tchauzinho... \n\n\n";
}
