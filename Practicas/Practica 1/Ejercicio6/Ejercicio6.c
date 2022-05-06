#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 100
#define TERMINADOR '\r'

void CargarTexto(char Arreglo[TAM]);
void ImprimirTexto(char Arreglo[TAM]);
void Normalizar(char Arreglo[TAM]);
void ConvertirAMayuscula(char Arreglo[TAM]);
void TerminaConPunto(char Arreglo[TAM]);
void UnSoloEspacio(char Arreglo[TAM]);

int main() {
	
	char Arreglo[TAM] = {0};
	CargarTexto(Arreglo);
	printf("\n\nEl texto es: ");
	ImprimirTexto(Arreglo);
	Normalizar(Arreglo);
	printf("\n\nEl texto normalizado es: ");
	ImprimirTexto(Arreglo);
	return 0;
}

void CargarTexto(char Arreglo[TAM]){
	
	int i = 0;
	char Caracter;
	
	printf("Ingrese texto: ");
	if(i < TAM-1){
		Caracter = getche();
	}
	
	while(i < TAM-1 && Caracter != '\r'){
		Arreglo[i] = Caracter;
		Caracter = getche();
		i++;
	}
	
	Arreglo[i] = '\0';
}

void ImprimirTexto(char Arreglo[TAM]){
	
	printf("%s",Arreglo);
	
}
	
void Normalizar(char Arreglo[TAM]){
	
	ConvertirAMayuscula(Arreglo);
	UnSoloEspacio(Arreglo);
	TerminaConPunto(Arreglo);
}
	
	
void ConvertirAMayuscula(char Arreglo[TAM]){
	
	if(Arreglo[0] >= 'a' && Arreglo[0] <= 'z'){
		
		Arreglo[0] = Arreglo[0] - 32;
	}
}
	
void UnSoloEspacio(char Arreglo[TAM]){
		
	int i;
	
	for(i=0; i < TAM-1 ; i++){
		while(Arreglo[i] == ' ' && Arreglo[i+1] == ' '){
			Arreglo[i+1] = Arreglo[i+2];
		}
	}
}
	
void TerminaConPunto(char Arreglo[TAM]){
	
	int i;
	for(i = 0; Arreglo[i] != '\0' && i < TAM-1; i++){
		
		if(Arreglo[i+1] == '\0' && Arreglo[i] != '.'){
			Arreglo[i+1] = '.';
			Arreglo[i+2] = '\0';
		}
	}	
}
