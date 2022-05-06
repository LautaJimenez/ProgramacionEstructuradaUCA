#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 10
#define C 16

void CargarMatrizDeNumerosDeArchivo(int Matriz[F][C],char NombreDeArchivo[]);
void CargarMatrizDeTextoDeArchivo(char Matriz[F][C],char NombreDeArchivo[]);
void ImprimirTabla(int MatrizDeDatos[F][C], char MatrizCabecera[F][C], char MatrizEquipos[F][C], int fila, int columna);
void OrdenarTabla(char MatrizEquipos[F][C], int MatrizDeDatos[F][C], int ValorColumna, int ValorNumerico);

int main() {
	
	int MatrizDeDatos[F][C] = {0};
	char MatrizCabecera[F][C] = {0};
	char MatrizEquipos[F][C] = {0};
	
	CargarMatrizDeTextoDeArchivo(MatrizCabecera,"cabeceras.txt");
	CargarMatrizDeNumerosDeArchivo(MatrizDeDatos,"puntos.txt");
	CargarMatrizDeTextoDeArchivo(MatrizEquipos,"equipos.txt");
	//OrdenarTabla(MatrizEquipos, MatrizDeDatos, 0, 1);
	ImprimirTabla(MatrizDeDatos,MatrizCabecera,MatrizEquipos,6,8);
	
	return 0;
}

void CargarMatrizDeNumerosDeArchivo(int Matriz[F][C],char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila;
	int Numero1,Numero2,Numero3,Numero4,Numero5,Numero6,Numero7,Numero8;
	
	for(Fila = 0 ; Fila<F && fscanf(Archivo,"%d,%d,%d,%d,%d,%d,%d,%d",&Numero1,&Numero2,&Numero3,&Numero4,&Numero5,&Numero6,&Numero7,&Numero8) != EOF ; Fila++){
		
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
	
void CargarMatrizDeTextoDeArchivo(char Matriz[F][C],char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila, Columna;
	char Caracter;
	
	if(Archivo == NULL){
		printf("Error al abrir el archivo...");
	}
	
	Caracter = fgetc(Archivo);
	
	for(Fila = 0 ; Caracter != EOF ; Fila++){
		for(Columna = 0 ; Caracter != EOF && Caracter != '\n' ; Columna++){
			Matriz[Fila][Columna] = Caracter;
			Caracter = fgetc(Archivo);
		}
		Matriz[Fila][Columna] = '\0';
		Caracter = fgetc(Archivo);
	}
	Matriz[Fila][Columna] = '\0';
	fclose(Archivo);
}
	
/*void OrdenarTabla(char MatrizEquipos[F][C], int MatrizDeDatos[F][C], int ValorColumna, int ValorNumerico){*/
	
/*	int i,j;*/
/*	char Auxiliar[C];*/
/*	int MatrizAuxiliar[F][C] = {0};*/
	
/*	for(i = 0 ; i<F && MatrizDeDatos[i][0] != EOF && ValorNumerico == 1 ; i++){*/
/*		for(j = i+1 ; j<F && MatrizDeDatos[j][0] != EOF ; j++){*/
				
/*			if(MatrizDeDatos[i][ValorColumna]>MatrizDeDatos[j][ValorColumna]){*/
					
/*				MatrizAuxiliar = MatrizDeDatos[i];*/
/*				MatrizDeDatos[i] = MatrizDeDatos[j];*/
/*				MatrizDeDatos[j] = MatrizAuxiliar;*/
					
/*				strcpy(Auxiliar,MatrizEquipos[i]);*/
/*				strcpy(MatrizEquipos[i],MatrizEquipos[j]);*/
/*				strcpy(MatrizEquipos[j],Auxiliar);*/
/*				}*/
/*			}*/
/*		}*/
	
/*	for(i = 0 ; i<F && MatrizDeDatos[i][0] != EOF && ValorNumerico == 0; i++){*/
/*		for(j = i+1 ; j<F && MatrizDeDatos[i][0] != EOF ; j++){*/
/*			if(MatrizDeDatos[i][ValorColumna]<MatrizDeDatos[j][ValorColumna]){*/
/*				MatrizAuxiliar = MatrizDeDatos[i];*/
/*				MatrizDeDatos[i] = MatrizDeDatos[j];*/
/*				MatrizDeDatos[j] = MatrizAuxiliar;*/
					
/*				strcpy(Auxiliar,MatrizEquipos[i]);*/
/*				strcpy(MatrizEquipos[i],MatrizEquipos[j]);*/
/*				strcpy(MatrizEquipos[j],Auxiliar);*/

	
	
	

void ImprimirTabla(int MatrizDeDatos[F][C], char MatrizCabecera[F][C], char MatrizEquipos[F][C], int fila, int columna){
	
	int Fila, Columna;
	
	for(Fila = 0 ; Fila<columna+1; Fila++){
		printf("%-20s",MatrizCabecera[Fila]);
	}
	
	printf("\n____________________________________________________________________________________________________________________________________________________________________________\n");
	
	for(Fila = 0; Fila<fila ; Fila++){
		
		printf("%-20s",MatrizEquipos[Fila]);
		
		for(Columna = 0 ; Columna<columna ; Columna++){
			
			if(MatrizDeDatos[Fila][Columna] > 0 && Columna == 7){
				
				printf("+%-19d",MatrizDeDatos[Fila][Columna]);
			}
			
			else{
				printf("%-20d",MatrizDeDatos[Fila][Columna]);
			}
		}		
		printf("\n");
	}
}
	
