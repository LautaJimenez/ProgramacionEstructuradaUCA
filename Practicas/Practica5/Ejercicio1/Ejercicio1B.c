#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct sPersona{
    int DNI;
    char *Nombre;
    char *Apellido;
};

typedef struct sPersona tPersona;

struct sNodo
{
    tPersona Personas;
    struct sNodo *Siguiente;
};

typedef struct sNodo* tNodo;

void CargarNombreEnPersona(tPersona Persona){
    
    Persona.Nombre = NULL;
    char Caracter;
    int i = 0;

    printf("Ingrese nombre: ");

    Persona.Nombre = malloc(sizeof(char));

    Caracter = getchar();
    while(Caracter != '\n'){
        Persona.Nombre[i] = Caracter;
        Persona.Nombre = realloc(Persona.Nombre,(i+1)*sizeof(char));
        Caracter = getchar();
    }

    Persona.Nombre[i] = '\0';
}

void CargarApellidoEnPersona(tPersona Persona){
    
    Persona.Apellido = NULL;
    char Caracter;
    int i = 0;

    printf("Ingrese apellido: ");

    Persona.Apellido = malloc(sizeof(char));

    Caracter = getchar();
    while(Caracter != '\n'){
        Persona.Apellido[i] = Caracter;
        Persona.Apellido = realloc(Persona.Apellido,(i+1)*sizeof(char));
        Caracter = getchar();
    }

    Persona.Apellido[i] = '\0';
}

void CargarPersona(tPersona Persona){

    printf("Ingrese DNI: ");
    scanf("%d",&(Persona.DNI));

    fflush(stdin); //Hago fflsuh asi limpio el buffer, sino no me deja ingresar el nombre.
    printf("\n"); 
    CargarNombreEnPersona(Persona);
    fflush(stdin);
    printf("\n");
    CargarApellidoEnPersona(Persona);
 
}

void AgregarPersonaEnLista(tNodo* Lista){
    
    tPersona Persona;

    if(*Lista == NULL){

        *Lista = malloc(sizeof(struct sNodo));
        CargarPersona(Persona);
        (*Lista)->Personas = Persona;
        (*Lista)->Siguiente = NULL;
    }
    
    else{
        AgregarPersonaEnLista(&((*Lista)->Siguiente));
    }
}

void ImprimirLista(tNodo Lista){

    if(Lista != NULL){
        printf("Nombre: %s. Apellido: %s. DNI: %d ",(Lista)->Personas.Nombre,(Lista)->Personas.Apellido,(Lista)->Personas.DNI);
        ImprimirLista(Lista->Siguiente);
    }
}


int main(){

    // No se imprime correctamente. Repasar.

    tNodo ListaDePersonas;
    ListaDePersonas = NULL;

    AgregarPersonaEnLista(&ListaDePersonas);
    printf("\n");
    AgregarPersonaEnLista(&ListaDePersonas);

    printf("---------- LISTA ----------\n");
    ImprimirLista(ListaDePersonas); 

    return 0;
}