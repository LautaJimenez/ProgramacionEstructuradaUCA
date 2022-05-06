#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define N 100
#define MAX 50

struct s_persona
{
    int DNI;
    char Nombre[MAX];
    char Pais[MAX];
};

typedef struct s_persona Persona;

void CargarArchivoEnEstructura(char NombreArchivo[], Persona PersonaNueva[N]){

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"r");

    int NumeroDNI, Letra, R;
    int i = 0;
    char Caracter;

    R = fscanf(Archivo,"%d,",&NumeroDNI);

    while(R != EOF){

        PersonaNueva[i].DNI = NumeroDNI;
        
        char NombrePersona[MAX] = {0};
        char NombrePais[MAX] = {0};
        
        Caracter = fgetc(Archivo);
        Letra = 0;

        while(Caracter != ','){
            NombrePersona[Letra] = Caracter;
            Letra++;
            Caracter = fgetc(Archivo);
        }
        
        strcpy(PersonaNueva[i].Nombre,NombrePersona);

        Caracter = fgetc(Archivo);
        Letra = 0;

        while(Caracter != '\n'){
            NombrePais[Letra] = Caracter;
            Letra++;
            Caracter = fgetc(Archivo);
        }

        strcpy(PersonaNueva[i].Pais,NombrePais);

        i++;

        R = fscanf(Archivo,"%d,",&NumeroDNI);
        
    }
    PersonaNueva[i].DNI = EOF;

    fclose(Archivo);

}

void ImprimirArchivo(char NombreArchivo[]){

    Persona PersonaNueva[N];

    CargarArchivoEnEstructura(NombreArchivo,PersonaNueva);

        int i;

    printf("%-20s %-20s %-20s\n","DNI","Nombre","Pais");

    for(i = 0 ; i<60 ; i++){
        printf("-");
    }

    printf("\n");
	
    for(i = 0 ; PersonaNueva[i].DNI != EOF ; i++){
        printf("%-20d %-20s %-20s\n",PersonaNueva[i].DNI,PersonaNueva[i].Nombre,PersonaNueva[i].Pais);
    }
}


int main(){

    ImprimirArchivo("personas.txt");
    return 0;
}
