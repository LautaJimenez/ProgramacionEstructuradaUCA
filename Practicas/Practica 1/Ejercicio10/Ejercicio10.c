#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 15
#define C 30
#define MAX 100

void CargarMatrizDeTextoDeArchivo(char Matriz[F][C],char NombreDeArchivo[MAX]);
void ImprimirMatrizDeTexto(char Matriz[F][C]);

int main() {
	
	char Matriz[F][C] = {0};
	CargarMatrizDeTextoDeArchivo(Matriz,"equipos.txt");
	ImprimirMatrizDeTexto(Matriz);
	return 0;
}

void CargarMatrizDeTextoDeArchivo(char Matriz[F][C],char NombreDeArchivo[MAX]){
	
	char Caracter;
	int f,c;
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	if(Archivo == NULL){
		printf("El archivo no se puede abrir!");
	}
	
	if(Archivo != NULL){
		
		Caracter = fgetc(Archivo);
		
		for(f=0; Caracter != EOF && f<F; f++){
			for(c=0;Caracter != EOF && Caracter != '\n' && c<C; c++){
				Matriz[f][c] = Caracter;
				Caracter = fgetc(Archivo);
			}
			Matriz[f][c] = '\0';
			Caracter = fgetc(Archivo);
		}
		
	}
}
	
void ImprimirMatrizDeTexto(char Matriz[F][C]){
	
	int f,c;
	
	for(f=0; f<F && Matriz[f][0] != '\0' ;f++){
		for(c=0; c<C && Matriz[f][c] != '\0'; c++){
			printf("%c",Matriz[f][c]);
		}
	printf("\n");
	}
	
}
