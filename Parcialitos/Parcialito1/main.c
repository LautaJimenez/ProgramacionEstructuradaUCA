#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 100
#define C 100

void CargarArchivoEnMatrizDeTexto(char MatrizDeTexto[F][C], char NombreDeArchivo[]);
void ImprimirMatrizDeTexto(char MatrizDeTexto[F][C]);
void OrdenarMatrizAlfabeticamente(char MatrizDeTexto[F][C]);

int main()
{
    char MatrizDeInsumos[F][C] = {0};
    CargarArchivoEnMatrizDeTexto(MatrizDeInsumos,"insumos.txt");
    OrdenarMatrizAlfabeticamente(MatrizDeInsumos);
    ImprimirMatrizDeTexto(MatrizDeInsumos);
    return 0;
}

void CargarArchivoEnMatrizDeTexto(char MatrizDeTexto[F][C], char NombreDeArchivo[]){

    FILE *Archivo;
    Archivo = fopen(NombreDeArchivo,"r");

    int Fila,Columna;

    char Caracter;

    Caracter = fgetc(Archivo);

    for(Fila = 0 ; Caracter != EOF && Fila<F ; Fila++){
        for(Columna = 0 ; Caracter != EOF && Columna<C ; Columna++){
            MatrizDeTexto[Fila][Columna] = Caracter;
            Caracter = fgetc(Archivo);
        }
        MatrizDeTexto[Fila][Columna] = '\0';
    }
    MatrizDeTexto[Fila][0] = '\0';
}

void ImprimirMatrizDeTexto(char MatrizDeTexto[F][C]){

    int Fila;

    for(Fila = 0 ; Fila<F && MatrizDeTexto[Fila][0] != '\0' ; Fila++){

        printf("%s",MatrizDeTexto[Fila]);
    }
}

void OrdenarMatrizAlfabeticamente(char MatrizDeTexto[F][C]){

    int i,j;
    char Auxiliar[F];

    for(i = 0 ; i<F && MatrizDeTexto[i][0] != '\0' ; i++){
        for(j = i+1 ; j<F && MatrizDeTexto[j][0] != '\0' ; j++){
            if(strcmp(MatrizDeTexto[i],MatrizDeTexto[j])>0){

                strcpy(Auxiliar,MatrizDeTexto[i]);
                strcpy(MatrizDeTexto[i],MatrizDeTexto[j]);
                strcpy(MatrizDeTexto[j],Auxiliar);
            }
        }
    }
}
