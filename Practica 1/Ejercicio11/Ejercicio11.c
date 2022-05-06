#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define N 25
#define F 30
#define C 40
#define MAX 100

void CargarMatrizDeTextoEnArchivo(char Matriz[F][C], char NombreDeArchivo[MAX]);
void OrdenarMatrizDeTexto(char Matriz[F][C]);
void ImprimirMatriz(char Matriz[F][C]);

int main() {
	
	char Matriz[F][C] = {0};
	
	CargarMatrizDeTextoEnArchivo(Matriz,"equipos.txt");
	printf("La matriz original es: \n\n");
	ImprimirMatriz(Matriz);
	OrdenarMatrizDeTexto(Matriz);
	printf("\n\nLa matriz ordenada es: \n\n");
	ImprimirMatriz(Matriz);
	
	return 0;
}

void OrdenarMatrizDeTexto(char Matriz[F][C]){
	
	char Auxiliar[C];
	char i,j;
	
	for(i = 0 ; i<F && Matriz[i][0] != '\0' ; i++){
		for(j = i+1 ; j<F && Matriz[j][0] != '\0'; j++){
			if(strcmp(Matriz[i],Matriz[j])>0){
				strcpy(Auxiliar,Matriz[i]);
				strcpy(Matriz[i],Matriz[j]);
				strcpy(Matriz[j],Auxiliar);
			}
		}
	}	
}

void CargarMatrizDeTextoEnArchivo(char Matriz[F][C], char NombreDeArchivo[MAX]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int f,c;
	char Caracter;
	
	if(Archivo == NULL){
		printf("No se puede abrir el archivo!");
	}
	else{
		Caracter = fgetc(Archivo);
		for(f=0 ; f<F && Caracter != EOF ; f++){
			for(c=0 ; c<C && Caracter != EOF && Caracter != '\n' ; c++){
				Matriz[f][c] = Caracter;
				Caracter = fgetc(Archivo);
			}
			Matriz[f][c] = '\0';
			Caracter = fgetc(Archivo);
		}		
	}
}
	
void ImprimirMatriz(char Matriz[F][C]){
	
	int f,c;
	
	for(f=0 ; f<F && Matriz[f][0] != '\0' ; f++){
		for(c=0 ; c<C && Matriz[f][c] != '\0'; c++){
			printf("%c",Matriz[f][c]);
		}
		printf("\n");
	}
	
	
}

