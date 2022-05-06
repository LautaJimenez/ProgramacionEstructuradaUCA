#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TERMINADOR 0

int EstaEnArreglo(int Numero, int Arreglo[TAM]);
void CargarArreglo(int Arreglo[TAM]);
int EsPositivo(int Numero);
void ImprimirArreglo(int Arreglo[TAM]);
	

int main() {
	int Arreglo[TAM] = {0};
	CargarArreglo(Arreglo);
	printf("\nEl arreglo es: ");
	ImprimirArreglo(Arreglo);
	return 0;
}

void CargarArreglo(int Arreglo[TAM]){
	
	int i = 0;
	int Auxiliar;
	
	printf("[%d]: ",i);
	if(i < TAM-1){
		scanf("%d",&Auxiliar);
	}
	
	while(Auxiliar != TERMINADOR && i < TAM-1){
		
		if(EsPositivo(Auxiliar) && (EstaEnArreglo(Auxiliar,Arreglo) == 0)){
			Arreglo[i] = Auxiliar;
			i++;
		}
		printf("[%d]: ",i);
		
		if(i < TAM-1){
			scanf("%d",&Auxiliar);
		}
	}
	Arreglo[i] = TERMINADOR;
}


int EsPositivo(int Numero){
	
	if(Numero > 0){
		return 1;
	}
	else{
		return 0;
	}
}

int EstaEnArreglo(int Numero, int Arreglo[TAM]){
	
	int i;
	
	for(i=0; Arreglo[i] != TERMINADOR && i<TAM;i++){
		if(Numero == Arreglo[i]){
			return 1;
		}
	}
	return 0;
	
}
	
void ImprimirArreglo(int Arreglo[TAM]){
	
	int i;
	
	for(i = 0; Arreglo[i] != TERMINADOR && i < TAM; i++){
		if(i < TAM-1 && i != 0){
			printf(" | ");}
		printf("%d",Arreglo[i]);
	}
	
	
}
