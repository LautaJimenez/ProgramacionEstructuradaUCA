#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 50
#define C 50

void CargarMatrizDeNumerosDeArchivo(int Matriz[F][C],char NombreDeArchivo[]);
void ImprimirMatrizDeNumeros(int Matriz[F][C], int fil, int col);

int main() {
	
	int Matriz[F][C] = {0};
	
	CargarMatrizDeNumerosDeArchivo(Matriz,"puntos.txt");
	ImprimirMatrizDeNumeros(Matriz,6,8);
	return 0;
}

void CargarMatrizDeNumerosDeArchivo(int Matriz[F][C],char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila;
	int Numero1,Numero2,Numero3,Numero4,Numero5,Numero6,Numero7,Numero8;
	
	for(Fila = 0; Fila<F && fscanf(Archivo,"%d,%d,%d,%d,%d,%d,%d,%d",&Numero1,&Numero2,&Numero3,&Numero4,&Numero5,&Numero6,&Numero7,&Numero8) != EOF; Fila++){
		Matriz[Fila][0] = Numero1;
		Matriz[Fila][1] = Numero2;
		Matriz[Fila][2] = Numero3;
		Matriz[Fila][3] = Numero4;
		Matriz[Fila][4] = Numero5;
		Matriz[Fila][5] = Numero6;
		Matriz[Fila][6] = Numero7;
		Matriz[Fila][7] = Numero8;
	}
	Matriz[Fila][0] = EOF;
	
	fclose(Archivo);
}

void ImprimirMatrizDeNumeros(int Matriz[F][C], int fil, int col){
	
	int Fila, Columna;
	
	for(Fila = 0; Fila<fil && Matriz[Fila][0] != EOF ; Fila++){
		for(Columna = 0; Columna<col ; Columna++){
			if(Columna == 7 && Matriz[Fila][Columna] > 0){
				printf("+%d\t",Matriz[Fila][Columna]);
			}
			else{
				printf("%d\t",Matriz[Fila][Columna]);
			}
		}
		printf("\n");		
	}

}
