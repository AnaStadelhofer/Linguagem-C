// FEITO POR ANA CAROLINA
#include"biblio.h"
#include<iostream>
#include <windows.h>
#include<conio.h>

using namespace std;

// VARIAVEIS GLOBAIS

int const TAM = 100;
int qtd =2, i, escolha, amostra_selecionada;
int mes[TAM], dia[TAM], ano[TAM];
float temp[TAM];
// VALIDAÇÃO DE AMOSTRAS
void validar_mes(int mes[]);
void validar_dia(int dia[]);
void validar_ano(int ano[]);
void validar_temp(float temp[]);

float temperatura_media (float temp[], int qtd); // 1
float temp_mais_Alta(float temp[], int qtd); // 2
float temp_mais_baixa(float temp[], int qtd); // 3
int qtd_temp_negativa(float temp[], int qtd); // 4
int qtd_temp_positiva(float temp[], int qtd); //5
void temp_quinz_seis(float temp[], int mes[], int dia[], int qtd); // 6
int ano_mais_frio(float temp[], int ano[], int qtd); // 7
int mes_mais_quente(float temp[], int mes[], int qtd); //8
int dias_abaixo_media(float temp[], int qtd); // 9
void todas_amostra(float temp[],int mes[], int dia[], int ano[],int qtd); // 10
void amostra_especifica(float temp[],int mes[], int dia[], int ano[],int qtd); // 11

main(){
	setlocale(LC_ALL,"Portuguese");	
	cout<<"\n\t Quantas amostras dejesa cadastrar? "; 
 	cin>>qtd;
	for(i=0; i<qtd; i++) {
	
	cout<<"\n\n\t =================="<<i+1<<"a Amostra ==================\n\n";
	cout<<"\n\t Informe o "<<i +1<<"a Mês: ";
	cin>>mes[i];
	validar_mes(mes);
	cout<<"\n\t Informe o "<<i +1<<"a Dia: ";
	cin>>dia[i];
	validar_dia(dia);
	cout<<"\n\t Informe o "<<i +1<<"a Ano: ";
	cin>>ano[i];
	validar_ano(ano);
	cout<<"\n\t Informe o "<<i +1<<"a Temperatura: ";
	cin>>temp[i];
	validar_temp(temp);
	}
	
	do{
	 system ("cls");
	 
	 cout<<"\n\t ============================================  ";
	 cout<<"\n\t\t\a\a  PROGRAMA DAS TEMPERRATURAS  ";
	 cout<<"\n\t ============================================  ";
	 cout<<"\n\t [1] - TEMPERATURA MEDIA";
	 cout<<"\n\t [2] - TEMPERATURA MAIS ALTA";
	 cout<<"\n\t [3] - TEMPERATURA MAIS BAIXA";
	 cout<<"\n\t [4] - QUANTIDADE DE TEMPERATURA NEGATIVA";
	 cout<<"\n\t [5] - QUANTIDADE DE TEMPERATURA POSITIVA";
	 cout<<"\n\t [6] - TEMPERATURA DO DIA 15 DO 6";
	 cout<<"\n\t [7] - ANO MAIS FRIO";
	 cout<<"\n\t [8] - MES MAIS QUENTE";
	 cout<<"\n\t [9] - QUANTIDADE DE DIAS QUE A TEMPERATURA FICOU ABAIXO DA MEDIA";
	 cout<<"\n\t [10] - TODAS AS TEMPERATURAS";
	 cout<<"\n\t [11] - IMPRIMIR A TEMPERATURA SOLICITADA";
	 cout<<"\n\t [12] - FIM";
	 cout<<"\n\t SUA ESCOLHA É: ";
	 cin>>escolha;

	switch(escolha) {
		case 1:{ // TEMP MEDIA
			float result;
			cout<<"\n\t\t ======== Média das temperatura ========"; 
          	result = temperatura_media (temp, qtd);
           	cout<<"\n\n\t A média das temperturas é: "<<result;
			getch();
			break;
		}
		case 2:{ // TEMP + ALTA
			float result;
			cout<<"\n\t\t ======== Temperatura mais alta, ta calor... ========"; 
            result = temp_mais_Alta(temp, qtd);
            cout<<"\n\n\t A temperatura mais alta é: "<<result;
			getch();
			break;
		}
		case 3:{ // TEMP + BAIXA
			float result;
			cout<<"\n\t\t ======== Temperatura mais baixa, ta um friozinho... ========"; 
			result = temp_mais_baixa(temp,qtd);
			cout<<"\n\n\t A temperatura mais baixa é: "<<result;
			getch();
			break;
		}
		case 4:{ //QTD NEGATIVA
			int result;
			cout<<"\n\t\t ======== Quantidade de temperatura negativas ========"; 
            result = qtd_temp_negativa(temp, qtd);
            cout<<"\n\n\t Total de temperaturas negativas: "<<result;
			getch();
			break;
		}
		case 5:{ // QTD POSITIVA
			int result;
			cout<<"\n\t\t ======== Quantidade de temperatura positivas ========"; 
            result = qtd_temp_positiva(temp, qtd);
            cout<<"\n\n\t Total de temperaturas positivas: "<<result;
			getch();
			break;
		}
		case 6:{ // TEMP 15/06
			cout<<"\n\t ======== Temperaturas do dia 15/06 ========"; 
            temp_quinz_seis(temp, mes, dia, qtd);
			getch();
			break;
		}
		case 7:{ // ANO COM TEMP + BAIXO
			int result;
			cout<<"\n\t\t ======== Ano que teve a temperatura mais baixa ========";
            result = ano_mais_frio(temp,ano,qtd);
            cout<<"\n\n\t O ano mais frio foi: "<<result;
			getch();
			break;
		}
		case 8:{ // MES MAIS QUENTE
			int result;
			cout<<"\n\t\t ======== Mês mais quente, bem vindo ao Brasil... ========"; 
            result = mes_mais_quente(temp, mes, qtd);
            cout<<"\n\n\t Mês mais quente foi: "<<result;
			getch();
			break;
		}
		case 9:{ // DIAS TEMP ABAIXO DA MEDIA ---- ARRUMAR
			int result, dias_abaixo;
			cout<<"\n\t\t ======== Quantos dias a temperatura ficou abaixo da média ========";
			result = dias_abaixo_media(temp, qtd);
            cout<<"\n\n\t Quantidade de dias abaixo da média: "<<result;
			getch();
			break;
		}
		case 10:{ // TODAS AMOSTRAS
			cout<<"\n\t\t ======== Todas amostras coletadas ========\n"; 
            todas_amostra(temp, mes, dia, ano, qtd);
            getch();
			break;
		}
		case 11:{ // AMOSTRA ESPECIFICA
			cout<<"\n\t\t ======== Amostra especifica ========\n"; 
            amostra_especifica(temp, mes, dia, ano, qtd);
			getch();
			break;
		}
		case 12:{
			cout<<"\n\t Tchauzinho...";
			escolha = 13;
			break;
		}
	}}while(escolha != 13);	
}// FIM MAIN

// FUNÇÕES VALIDAÇÃO

// VALIDAR DIA
void validar_dia(int dia[]) {
	
	do{
	if((dia[i] < 1) || (dia[i] > 30)) {
		cout<<"\n\t Tente novamente...";
		cout<<"\n\t Informe o Dia: ";
		cin>>dia[i];
	}} while((dia[i] < 1) || (dia[i] > 30));
}
// FUNÇÃO MES VALIDAR
void validar_mes(int mes[]){
	
	do{
	if((mes[i] < 1) || (mes[i] > 12)) {
		cout<<"\n\t Mês inválido, tente novamente...";
		cout<<"\n\t Informe o Mês: ";
		cin>>mes[i];
	}} while((mes[i] < 1) || (mes[i] > 12));	
}
// FUNÇÃO ANO VALIDAR
void validar_ano(int ano[]){
	
	do{
	if((ano[i] < 1850) || (ano[i] > 2021)) {
		cout<<"\n\t Ano inválido, tente novamente...";
		cout<<"\n\t Informe o Ano: ";
		cin>>ano[i];
	}} while((ano[i] < 1850) || (ano[i] > 2021));	
}

// FUNÇÃO TEMPERATURA VALIDAR
void validar_temp(float temp[]){

	do{
	if((temp[i] < -50) || (temp[i] > 65)) {
		cout<<"\n\t Temperatura inválida, tente novamente...";
		cout<<"\n\t Informe a Temperatura: ";
		cin>>temp[i];
	}} while((temp[i] < -50) || (temp[i] > 65));	
}

