#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define N 5
#define MAX 50

struct s_persona
{
    int DNI;
    char Nombre[MAX];
    char Pais[MAX];
};

typedef struct s_persona Persona;

void CargarString(char String[MAX]){

    char Caracter;
    int i;

    Caracter = getche();

    for(i = 0 ; Caracter != '\r' && i < MAX-1 ; i++){

        String[i] = Caracter;
        Caracter = getche();
    }
    String[i] = '\0';
}


void CargarPersonasEnArchivo(char NombreArchivo[], Persona PersonaNueva){

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"a");

    fprintf(Archivo,"%d,%s,%s\n",PersonaNueva.DNI,PersonaNueva.Nombre,PersonaNueva.Pais);

}

void CargarPersonas(){

    Persona PersonaNueva;
    int Contador = 0;

    printf("\nIngresar DNI (o 0 para terminar): ");
    scanf("%d",&PersonaNueva.DNI);

    while(PersonaNueva.DNI != 0 && Contador<N){

        printf("Ingrese nombre de la persona: ");
        CargarString(&PersonaNueva.Nombre);


        printf("\nIngrese pais de la persona: ");
        CargarString(&PersonaNueva.Pais);
        Contador++;

        CargarPersonasEnArchivo("personas.txt",PersonaNueva);

        if(Contador<N && PersonaNueva.DNI != 0){
            printf("\nIngresar DNI (o 0 para terminar): ");
            scanf("%d",&PersonaNueva.DNI);
        }
    }
}

int main(){

    CargarPersonas();
    return 0;
}
