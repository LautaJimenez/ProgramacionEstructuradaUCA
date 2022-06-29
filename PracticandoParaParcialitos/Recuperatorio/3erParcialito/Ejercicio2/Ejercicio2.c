#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct sPersona{
    int Edad;
    char *Nombre;
    char *Apellido;

};
typedef struct sPersona tPersona;

struct sNodo{

    tPersona Persona;
    struct sNodo *Siguiente;

};
typedef struct sNodo *tNodo;

void ObtenerCadenaDeArchivo(FILE *Archivo, char **Cadena, char Separador){

    char Caracter;
    int i = 0;
    *(Cadena) = malloc(sizeof(char));

    if(!feof(Archivo)){
        Caracter = fgetc(Archivo);
    }

    while(!feof(Archivo) && Caracter != Separador){

        (*(Cadena))[i] = Caracter;
        i++;
        *(Cadena) = realloc(*(Cadena),sizeof(char) * (i+1));
        Caracter = fgetc(Archivo);
    }
    (*(Cadena))[i] = '\0';
}

// Cargar contenido del archivo a la lista sin ordenar.

void CargarALista(tNodo *Lista, tPersona PersonaAuxiliar){

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Persona = PersonaAuxiliar;
        (*Lista)->Siguiente = NULL;
    }
    else{
        CargarALista(&(*Lista)->Siguiente,PersonaAuxiliar);
    }
}

// Cargar contenido del archivo a la lista ordenado pro edad.

void CargarAListaOrdenadoPorEdad(tNodo *Lista,tPersona PersonaAuxiliar){

    tNodo Auxiliar = NULL;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Persona = PersonaAuxiliar;
        (*Lista)->Siguiente = NULL;
    }
    else{
        if((*Lista)->Persona.Edad > PersonaAuxiliar.Edad){
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Persona = PersonaAuxiliar;
            Auxiliar->Siguiente = (*Lista);
            (*Lista) = Auxiliar;
        }
        else{
            CargarAListaOrdenadoPorEdad(&(*Lista)->Siguiente,PersonaAuxiliar);
        }
    }
}

// Cargar contenido del archivo ordenado por nombre alfabeticamente.

void CargarAListaOrdenadoPorNombre(tNodo * Lista, tPersona PersonaAuxiliar){

    tNodo Auxiliar = NULL;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Persona = PersonaAuxiliar;
        (*Lista)->Siguiente = NULL;
    }
    else{
        if(strcmp((*Lista)->Persona.Nombre,PersonaAuxiliar.Nombre)>0){
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Persona = PersonaAuxiliar;
            Auxiliar->Siguiente = *Lista;
            *Lista = Auxiliar;
        }
        else{
            CargarAListaOrdenadoPorNombre(&(*Lista)->Siguiente,PersonaAuxiliar);
        }
    }
}

// Cargar contenido del archivo a la lista ordenado por apellido.

void CargarAListaOrdenadoPorApellido(tNodo *Lista, tPersona PersonaAuxiliar){

    tNodo Auxiliar = NULL;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Persona = PersonaAuxiliar;
        (*Lista)->Siguiente = NULL;
    }
    else{
        if(strcmp((*Lista)->Persona.Apellido,PersonaAuxiliar.Apellido) > 0){
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Persona = PersonaAuxiliar;
            Auxiliar->Siguiente = *Lista;
            *Lista = Auxiliar;
        }
        else{
            CargarAListaOrdenadoPorApellido(&(*Lista)->Siguiente,PersonaAuxiliar);
        }
    }
}


void CargarArchivoALista(char *NombreArchivo, tNodo *Lista){

    FILE *Archivo = fopen(NombreArchivo,"r");
    tPersona PersonaAuxiliar = {0};

    while(!feof(Archivo)){
        fscanf(Archivo,"%d,",&PersonaAuxiliar.Edad);
        ObtenerCadenaDeArchivo(Archivo,&PersonaAuxiliar.Nombre,',');
        ObtenerCadenaDeArchivo(Archivo,&PersonaAuxiliar.Apellido,'\n');

        //CargarALista(Lista,PersonaAuxiliar);
        //CargarAListaOrdenadoPorEdad(Lista,PersonaAuxiliar);
        //CargarAListaOrdenadoPorNombre(Lista,PersonaAuxiliar);
        CargarAListaOrdenadoPorApellido(Lista,PersonaAuxiliar);
    }
}

void ImprimirLista(tNodo Lista){

    if(Lista != NULL){
        printf("%-4d %-10s %-10s\n",Lista->Persona.Edad,Lista->Persona.Nombre,Lista->Persona.Apellido);
        ImprimirLista(Lista->Siguiente);
    }
}

void ImprimirCabeceras(){
    printf("%-4s %-10s %-10s\n\n","Edad","Nombre","Apellido");
}


int main(){

    tNodo Lista = NULL;
    CargarArchivoALista("Personas.txt",&Lista);
    ImprimirCabeceras();
    ImprimirLista(Lista);
    return 0;
}