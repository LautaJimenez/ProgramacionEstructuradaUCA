#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 10
#define C 18

void CargarArchivoEnMatrizDeTexto(char MatrizDeCabeceras[F][C], char NombreDeArchivo[]);
void ImprimirTabla(char MatrizDeCabeceras[F][C],char MatrizDeEquipos[F][C],int MatrizDeDatos[F][C]);
void CargarArchivoEnMatrizDeNumeros(int MatrizDeNumeros[F][C], char NombreDeArchivo[]);

int main(){
	
	char MatrizDeCabeceras[F][C] = {0};
	char MatrizDeEquipos[F][C] = {0};
	int MatrizDeDatos[F][C] = {0};
	CargarArchivoEnMatrizDeTexto(MatrizDeCabeceras,"cabeceras.txt");
	CargarArchivoEnMatrizDeTexto(MatrizDeEquipos,"equipos.txt");
	CargarArchivoEnMatrizDeNumeros(MatrizDeDatos,"puntos.txt");
	ImprimirTabla(MatrizDeCabeceras,MatrizDeEquipos,MatrizDeDatos);
	return 0;
}

void CargarArchivoEnMatrizDeTexto(char MatrizDeTexto[F][C], char NombreDeArchivo[]){
	
	FILE *Archivo;
	
	Archivo = fopen(NombreDeArchivo,"r");
	
	if(Archivo == NULL){
		printf("Error al abrir el archivo.");
	}
	
	int Fila,Columna;
	char Caracter;
	
	Caracter = fgetc(Archivo);
	
	for(Fila = 0 ; Fila<F && Caracter != EOF ; Fila++){
		for(Columna = 0 ; Columna<C && Caracter != EOF && Caracter != '\n' ; Columna++){
			MatrizDeTexto[Fila][Columna] = Caracter;
			Caracter = fgetc(Archivo);
		}
		MatrizDeTexto[Fila][Columna] = '\0';
		Caracter = fgetc(Archivo);
	}
	MatrizDeTexto[Fila][Columna] = '\0';
	fclose(Archivo);
}
	

	
	
	

void CargarArchivoEnMatrizDeNumeros(int MatrizDeNumeros[F][C], char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila,Numero0,Numero1,Numero2,Numero3,Numero4,Numero5,Numero6,Numero7;
	
	for(Fila = 0 ; Fila<F && fscanf(Archivo,"%d,%d,%d,%d,%d,%d,%d,%d",&Numero0,&Numero1,&Numero2,&Numero3,&Numero4,&Numero5,&Numero6,&Numero7) != EOF ; Fila++){
	
		MatrizDeNumeros[Fila][0] = Numero0;
		MatrizDeNumeros[Fila][1] = Numero1;
		MatrizDeNumeros[Fila][2] = Numero2;
		MatrizDeNumeros[Fila][3] = Numero3;
		MatrizDeNumeros[Fila][4] = Numero4;
		MatrizDeNumeros[Fila][5] = Numero5;
		MatrizDeNumeros[Fila][6] = Numero6;
		MatrizDeNumeros[Fila][7] = Numero7;
		MatrizDeNumeros[Fila][8] = EOF;
	}
	MatrizDeNumeros[Fila][0] = EOF;
	
	fclose(Archivo);
}
	
	
void ImprimirTabla(char MatrizDeCabeceras[F][C],char MatrizDeEquipos[F][C],int MatrizDeDatos[F][C]){
	
	int Fila,Columna;
	
	// Se imprime el titulo: 
	
	printf("%-20s",MatrizDeCabeceras[0]); //Se imprime la palabra equipos con mas margen.
	
	for(Fila = 1 ; Fila<F && MatrizDeCabeceras[Fila][0] != '\0' ; Fila++){
		printf("%6s",MatrizDeCabeceras[Fila]); //Se imprimen los distintos encabezados.
	}
	
	printf("\n______________________________________________________________________\n");
	
	for(Fila = 0 ; Fila<F && MatrizDeEquipos[Fila][0] != '\0' ; Fila++){
		
		printf("%-20s",MatrizDeEquipos[Fila]);
		
		for(Columna = 0 ; Columna<C && MatrizDeDatos[Fila][Columna] != EOF; Columna++){
			if(Columna == 7 && MatrizDeDatos[Fila][Columna]>0){
				printf("%+6d",MatrizDeDatos[Fila][Columna]);
			}
			else{
			printf("%6d",MatrizDeDatos[Fila][Columna]);
			}
		}
		printf("\n");
	}
}
