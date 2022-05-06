#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MAX 50
#define N 100

struct s_persona{
    int DNI;
    char Nombre[MAX];
    char Pais[MAX];
};

typedef struct s_persona Persona;

void CargarArchivoEnEstructura(char NombreArchivo[], Persona PersonaNueva[N]){

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"r");

    int R, NumeroDNI, i = 0, Letra;

    char Caracter;

    R = fscanf(Archivo,"%d,",&NumeroDNI);

    while(R != EOF){

        PersonaNueva[i].DNI = NumeroDNI;

        char Nombre[MAX] = {0};
        char Pais[MAX] = {0};

        Caracter = fgetc(Archivo);
        Letra = 0;

        while(Caracter != ','){
            Nombre[Letra] = Caracter;
            Letra++;
            Caracter = fgetc(Archivo);
        }
        
        Caracter = fgetc(Archivo);
        Letra = 0;

        while(Caracter != '\n'){
            Pais[Letra] = Caracter;
            Letra++;
            Caracter = fgetc(Archivo);
        }

        strcpy(PersonaNueva[i].Nombre,Nombre);
        strcpy(PersonaNueva[i].Pais,Pais);

        i++;

        R = fscanf(Archivo,"%d,",&NumeroDNI);

    }

    PersonaNueva[i].DNI = EOF;
    fclose(Archivo);

}

void ImprimirEncabezado(){
    printf("%-20s %-20s %-20s\n","Documento","Nombre","Pais");

    for(int i = 0 ; i<60 ; i++){
        printf("-");
    }
    printf("\n");

}

void ImprimirEstructura(Persona PersonaNueva[N]){

    for(int i = 0 ; PersonaNueva[i].DNI != EOF ; i++){
        printf("%-20d %-20s %-20s\n",PersonaNueva[i].DNI,PersonaNueva[i].Nombre,PersonaNueva[i].Pais); 
    }
}

void OrdenarEstructuraPorDNI(char NombreArchivo[]){

    Persona PersonaNueva[N];
    Persona PersonaAuxiliar;

    CargarArchivoEnEstructura(NombreArchivo,PersonaNueva);

    for(int i = 0 ; PersonaNueva[i].DNI != EOF ; i++){
        for(int j = i+1 ; PersonaNueva[j].DNI != EOF ; j++){
            if(PersonaNueva[i].DNI > PersonaNueva[j].DNI){
                PersonaAuxiliar = PersonaNueva[i];
                PersonaNueva[i] = PersonaNueva[j];
                PersonaNueva[j] = PersonaAuxiliar; 
            }
        }
    }

    ImprimirEstructura(PersonaNueva);
}

void OrdenarEstructuraPorNombre(char NombreArchivo[]){

    Persona PersonaNueva[N];
    Persona PersonaAuxiliar;

    CargarArchivoEnEstructura(NombreArchivo,PersonaNueva);

    for(int i = 0 ; PersonaNueva[i].DNI != EOF ; i++){
        for(int j = i+1 ; PersonaNueva[j].DNI != EOF ; j++){
            if(strcmp(PersonaNueva[i].Nombre,PersonaNueva[j].Nombre)>0){
                PersonaAuxiliar = PersonaNueva[i];
                PersonaNueva[i] = PersonaNueva[j];
                PersonaNueva[j] = PersonaAuxiliar;
            }
        }
    }

     ImprimirEstructura(PersonaNueva);
}

void OrdenarEstructuraPorPais(char NombreArchivo[]){

    Persona PersonaNueva[N];
    Persona PersonaAuxiliar;

    CargarArchivoEnEstructura(NombreArchivo,PersonaNueva);

    for(int i = 0 ; PersonaNueva[i].DNI != EOF ; i++){
        for(int j = i+1 ; PersonaNueva[j].DNI != EOF ; j++){
            if(strcmp(PersonaNueva[i].Pais,PersonaNueva[j].Pais)>0){
                PersonaAuxiliar = PersonaNueva[i];
                PersonaNueva[i] = PersonaNueva[j];
                PersonaNueva[j] = PersonaAuxiliar;
            }
        }
    }
    ImprimirEstructura(PersonaNueva);
}

void Menu(char NombreArchivo[]){

    int Opcion;
    
    printf("\n\nElegir una de las siguientes opciones: \n\n");
    printf("1 : Ver listado por nombre.\n");
    printf("2 : Ver listado por documento.\n");
    printf("3 : Ver listado por pais.\n");
    printf("4 : Salir del programa.\n");
    printf("Opcion: ");
    scanf("%d",&Opcion);

    while(Opcion != 4){
        if(Opcion == 1){
        OrdenarEstructuraPorNombre(NombreArchivo);
        }
        if(Opcion == 2){
        OrdenarEstructuraPorDNI(NombreArchivo);
        }
        if(Opcion == 3){
        OrdenarEstructuraPorPais(NombreArchivo);
        }

        printf("\n\nElegir una de las siguientes opciones: \n\n");
        printf("1 : Ver listado por nombre.\n");
        printf("2 : Ver listado por documento.\n");
        printf("3 : Ver listado por pais.\n");
        printf("4 : Salir del programa.\n");
        printf("Opcion: ");
        scanf("%d",&Opcion);
    }
}

int main(){
    Menu("personas.txt");
    return 0;
}