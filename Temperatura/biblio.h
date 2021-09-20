#include<iostream>

using namespace std;

// CASE 1 TEMPERATURA MEDIA
float temperatura_media (float temp[], int qtd){
	float acumula, med=0;
	int i;
    for(i=0; i<qtd; i++) { 
		acumula=acumula+temp[i];
    }
    med=acumula/qtd;
    return(med);
}
// CASE 2 TEMP MAIS ALTA
float temp_mais_Alta(float temp[], int qtd){
	float maior_temp=0;
	int i;
    	for(i=0; i<qtd; i++) { 
    		if(i == 0) {
    			maior_temp = temp[i];
			}
      		if(temp[i] > maior_temp) {
				maior_temp = temp[i]; }
      		}
      return(maior_temp);
}
// CASE 3 TEMP MAIS BAIXA
float temp_mais_baixa(float temp[], int qtd){
	float menor_temp=0;
	int i;
    	for(i=0; i<qtd; i++) { 
    		if(i == 0) {
    			menor_temp = temp[i];
			}
      		if(temp[i] < menor_temp) {
				menor_temp = temp[i]; }
      		}
      return(menor_temp);
}
// CASE 4 QUANTIDADE DE TEMPERATURA NEGATIVA
int qtd_temp_negativa(float temp[], int qtd){
	int cont_neg=0, i;
	    for(i=0; i<qtd; i++) { 
	    if(temp[i] < 0) {
		cont_neg++;
	    }}
    return(cont_neg);
}
// CASE 5 QUANTIDADE DE TEMPERATURA POSITIVA
int qtd_temp_positiva(float temp[], int qtd){
	int cont_positivo=0, i;
	    for(i=0; i<qtd; i++) { 
	    if(temp[i] >= 0) {
		cont_positivo++;
	    }}
    return(cont_positivo);
}
// CASE 6 TEMP DOS DIA 15/06
void temp_quinz_seis(float temp[], int mes[], int dia[], int qtd){
	int i;
	for(i=0; i<qtd; i++) {
	if((dia[i] == 15) && (mes[i] == 6)){
		cout<<"\n\t Temperatura: "<<temp[i];
	}}
}
// CASE 7 ANO MAIS FRIO
int ano_mais_frio(float temp[], int ano[], int qtd){
	float dia_frio;
    int ano_frio,i;
    for(i=0; i<qtd; i++) {
    	if(i == 0){
    		ano_frio = ano[i];
    		dia_frio = temp[i];
		}
	    if(temp[i] < dia_frio)
	    ano_frio = ano[i];
		dia_frio = temp[i]; 
	}
    return(ano_frio);
}
// CASE 8 MES MAIS QUENTE
int mes_mais_quente(float temp[], int mes[], int qtd){
	float maior_temp;
    int mes_quente, i;
    for(i=0; i<qtd; i++) { 
    	if(i == 0){
	    	mes_quente = mes[i];
			maior_temp = temp[i];
		}
		if(temp[i] > maior_temp){
		    mes_quente = mes[i];
			maior_temp = temp[i];
    }}
    return(mes_quente);
}
// CASE 9 DIAS ABAIXO DA MEDIA
int dias_abaixo_media(float temp[], int qtd){
	float acumula=0, med=0;
	int i, qtd_abaixo;
    for(i=0; i<qtd; i++) { 
		acumula=acumula+temp[i];
    }
    med=acumula/qtd;
    cout<<"\n\t\t Média foi: "<<med;
    for(i=0; i<qtd; i++) { 
		if(temp[i] < med) {
			qtd_abaixo++;
	    }}
    return(qtd_abaixo); 
}
// CASE 10 TODAS AMOSTRAS COLETADAS
void todas_amostra(float temp[],int mes[], int dia[], int ano[],int qtd) {
	int i;
  for(i=0; i<qtd; i++)
  {
  	cout<<"\n";
  	cout<<"\n\t\t "<<i+1<<"a Amostra coletada";
  	cout<<"\n\t Dia: "<<dia[i];
  	cout<<"\n\t Mês: "<<mes[i];
  	cout<<"\n\t Ano: "<<ano[i];
  	cout<<"\n\t Temperatura: "<<temp[i]<<"°C";
  }
}  
// CASE 11 AMOSTRA ESPECIFICA
void amostra_especifica(float temp[],int mes[], int dia[], int ano[],int qtd){
	int i, amostra_selecionada;
	do{
		cout<<"\n\t\t Qual amostra você deseja saber? ";
		cin>>amostra_selecionada;
		amostra_selecionada = amostra_selecionada - 1;
		if((amostra_selecionada < 0) || (amostra_selecionada > qtd + 1)){
		cout<<"\n\t\t Amostra não cadastrada, informe novamente...";
		cout<<"\n\t\t Qual amostra você deseja saber? ";
		cin>>amostra_selecionada;	
		
	}}while((amostra_selecionada < 0) || (amostra_selecionada > qtd + 1));
		
		cout<<"\n\t\t "<<amostra_selecionada + 1<<"a Amostra coletada";
		cout<<"\n";
  		cout<<"\n\t Dia: "<<dia[amostra_selecionada];
  		cout<<"\n\t Mês: "<<mes[amostra_selecionada];
  		cout<<"\n\t Ano: "<<ano[amostra_selecionada];
  		cout<<"\n\t Temperatura: "<<temp[amostra_selecionada]<<" graus";
}


