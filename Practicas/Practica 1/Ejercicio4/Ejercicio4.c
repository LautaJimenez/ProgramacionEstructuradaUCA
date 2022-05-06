#include <stdio.h>
#include <stdlib.h>

#define TAM 11
#define TERMINADOR 0

void CargarArreglo(int Arreglo[TAM]);
void ImprimirArreglo(int Arreglo[TAM]);
void InvertirArreglo(int Arreglo[TAM]);
int LargoArreglo(int Arreglo[TAM]);

int main(){
	
	int Arreglo[TAM] = {0};
	
	CargarArreglo(Arreglo);
	InvertirArreglo(Arreglo);
	printf("\n\n El arreglo es: ");
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
		Arreglo[i] = Auxiliar;
		i++;
		printf("[%d]: ",i);
		
		if(i < TAM-1){
			scanf("%d",&Auxiliar); 
		}
	}
	Arreglo[i] = TERMINADOR;
}

void ImprimirArreglo(int Arreglo[TAM]){
	
	int i;
	
	for(i=0; Arreglo[i] != TERMINADOR && i < TAM; i++){
		if(i<=TAM-2 && i!= 0){
			printf(" | ");
		}
		printf("%d",Arreglo[i]);
	}
}


//VER FUNCION!!
	
void InvertirArreglo(int Arreglo[TAM]){
	
	int i;
	int j;
	int Auxiliar;
	int CantidadDeNumeros = LargoArreglo(Arreglo);
	
	for(i=0; i<CantidadDeNumeros-1; i++){
		for(j=i+1; j<CantidadDeNumeros; j++){
			if(Arreglo[i]>Arreglo[j]){
				Auxiliar = Arreglo[i];
				Arreglo[i] = Arreglo[j];
				Arreglo[j] = Auxiliar;
			}
		}
	}
}
	
int LargoArreglo(int Arreglo[TAM]){
	
	int i;
	
	for(i=0;i<TAM-1 && Arreglo[i]!=TERMINADOR;i++){
	}
	return i;
}
