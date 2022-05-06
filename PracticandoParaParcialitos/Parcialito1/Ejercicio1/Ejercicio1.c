// El ejercicio se trata de contar cuantas vocales tiene los strings que se encuentran en el archivo stock.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100
#define F 100

void CargarArchivoEnMatrizDeTexto(char MatrizDeTexto[F][C],char NombreDeArchivo[]);
void ContadorDeVocales(char MatrizDeTexto[F][C]);
int EsVocal(char Caracter);

int main() {
	
	char MatrizDeTexto[F][C] = {0};
	CargarArchivoEnMatrizDeTexto(MatrizDeTexto,"stock.txt");
	ContadorDeVocales(MatrizDeTexto);
	return 0;
}

void CargarArchivoEnMatrizDeTexto(char MatrizDeTexto[F][C],char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	char Caracter;
	int Fila,Columna,Cantidad,R;
	
	Caracter = fgetc(Archivo);
	
	for(Fila = 0 ; Fila<F && Caracter != EOF ; Fila++){
		for(Columna = 0 ; Columna<C && Caracter != EOF && Caracter != ',' && Caracter != '\n' ; Columna++){
			MatrizDeTexto[Fila][Columna] = Caracter;
			Caracter = fgetc(Archivo);
		}
		MatrizDeTexto[Fila][Columna] = '\0';
		
		R = fscanf(Archivo,"%d\n",&Cantidad);
		
		Caracter = fgetc(Archivo);
	}
	MatrizDeTexto[Fila][Columna] = '\0';
}
	
	int EsVocal(char Caracter){
		if(Caracter == 'a' || Caracter == 'e' || Caracter == 'i' || Caracter == 'o' || Caracter == 'u' || Caracter == 'A' || Caracter == 'E' || Caracter == 'I' || Caracter == 'O' || Caracter == 'U'){
			return 1;
		}
		else{
			return 0;
		}
	}
		
void ContadorDeVocales(char MatrizDeTexto[F][C]){
			
			int Fila,Columna;
			
			FILE *Archivo;
			Archivo = fopen("vocales.txt","w");
			
			for(Fila = 0 ; MatrizDeTexto[Fila][0] != '\0' && Fila<F ; Fila++){
				
				int Contador = 0;
				
				for(Columna = 0 ; MatrizDeTexto[Fila][Columna] != '\0' && Columna<C ; Columna++){
					if(EsVocal(MatrizDeTexto[Fila][Columna])){
						Contador += 1;
					}
				}
				
				fprintf(Archivo,"La frase: \"%s\" contiene %d vocales.\n\n",MatrizDeTexto[Fila],Contador);
				
			}
			fclose(Archivo);
	}
	
