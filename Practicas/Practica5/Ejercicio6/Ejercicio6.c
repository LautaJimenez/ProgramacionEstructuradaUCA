#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 40

struct sDatos{
    int DNI;
    char Nombre[TAM];
    char Apellido[TAM];
};
typedef struct sDatos Datos;

struct sNodo{

    Datos Informacion;
    struct sNodo *Siguiente; 

};
typedef struct sNodo *Nodo;

void AgregarALista(Nodo *Lista, int DNI, char Nombre[TAM], char Apellido[TAM]){

    if(*Lista == NULL){
        
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Informacion.DNI = DNI;
        strcpy((*Lista)->Informacion.Nombre,Nombre);
        strcpy((*Lista)->Informacion.Apellido,Apellido);
        (*Lista)->Siguiente = NULL;
    }
    else{
        AgregarALista(&(*Lista)->Siguiente,DNI,Nombre,Apellido);
    }

}

void CargarLista(Nodo *Lista, char NombreArchivo[TAM]){

    FILE *Archivo = fopen(NombreArchivo,"r");

    int DNI;

    fscanf(Archivo,"%d,",&DNI);
    
    while(!feof(Archivo)){ //Hasta que el archivo no este en END OF FILE
        
        char Caracter;
        char Nombre[TAM] = {0};
        char Apellido[TAM] = {0};

        Caracter = fgetc(Archivo);
        for(int i = 0; Caracter != ','; i++){           //Leo el nombre
            Nombre[i] = Caracter;
            Caracter = fgetc(Archivo);
        }

        Caracter = fgetc(Archivo);
        for(int i = 0; Caracter != '\n'; i++){           //Leo el apellido
            Apellido[i] = Caracter;
            Caracter = fgetc(Archivo);
        }

    AgregarALista(Lista,DNI,Nombre,Apellido);

    fscanf(Archivo,"%d,",&DNI);

    }
}

void ImprimirLista(Nodo Lista){

    if(Lista != NULL){
        printf("%-10d %-10s %-10s\n",Lista->Informacion.DNI,Lista->Informacion.Nombre,Lista->Informacion.Apellido);
        ImprimirLista(Lista->Siguiente);
    }
}

void OrdenarListaPorDNI(Nodo *ListaAuxiliar, int DNI, char Nombre[TAM], char Apellido[TAM]){

    Nodo Auxiliar = malloc(sizeof(struct sNodo));
    
    if(*ListaAuxiliar == NULL || DNI<(*ListaAuxiliar)->Informacion.DNI){
        
        Auxiliar->Informacion.DNI = DNI;
        strcpy(Auxiliar->Informacion.Nombre,Nombre);
        strcpy(Auxiliar->Informacion.Apellido,Apellido);
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }

    else{
        OrdenarListaPorDNI(&(*ListaAuxiliar)->Siguiente,DNI,Nombre,Apellido);
    }

}

void OrdenarListaPorNombre(Nodo *ListaAuxiliar, int DNI, char Nombre[TAM], char Apellido[TAM]){

    Nodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Informacion.Nombre,Nombre) == 1){
        Auxiliar->Informacion.DNI = DNI;
        strcpy(Auxiliar->Informacion.Nombre,Nombre);
        strcpy(Auxiliar->Informacion.Apellido,Apellido);
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }

    else{
        OrdenarListaPorNombre(&(*ListaAuxiliar)->Siguiente,DNI,Nombre,Apellido);
    }
}

void OrdenarListaPorApellido(Nodo *ListaAuxiliar, int DNI, char Nombre[TAM], char Apellido[TAM]){

    Nodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Informacion.Apellido, Apellido) == 1){
        Auxiliar->Informacion.DNI = DNI;
        strcpy(Auxiliar->Informacion.Apellido,Apellido);
        strcpy(Auxiliar->Informacion.Nombre,Nombre);
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    else{
        OrdenarListaPorApellido(&(*ListaAuxiliar)->Siguiente,DNI,Nombre,Apellido);
    }

}

void OrdenarLista(Nodo *Lista, int Opcion){

    Nodo Auxiliar = NULL;
    while(*Lista != NULL){
        if(Opcion == 1){
            OrdenarListaPorDNI(&Auxiliar,(*Lista)->Informacion.DNI,(*Lista)->Informacion.Nombre,(*Lista)->Informacion.Apellido);
            *Lista = (*Lista)->Siguiente;
        }
        
        else if(Opcion == 2){
            OrdenarListaPorNombre(&Auxiliar,(*Lista)->Informacion.DNI,(*Lista)->Informacion.Nombre,(*Lista)->Informacion.Apellido);
            *Lista = (*Lista)->Siguiente;
        }
        else if(Opcion == 3){
            OrdenarListaPorApellido(&Auxiliar,(*Lista)->Informacion.DNI,(*Lista)->Informacion.Nombre,(*Lista)->Informacion.Apellido);
            *Lista = (*Lista)->Siguiente;
        }
    }
    *Lista = Auxiliar;
}


int main(){

    Nodo Lista = NULL;
    CargarLista(&Lista,"Informacion.csv");
    
    printf("Lista SIN ordenar: \n\n");
    ImprimirLista(Lista);

    int Opcion;

    printf("\nIngrese el valor por el que desea ordenar: \n\n1 = DNI \n2 = Nombre \n3 = Apellido\n\nSeleccione la opcion: ");
    scanf("%d",&Opcion);
    OrdenarLista(&Lista,Opcion);
    
    if(Opcion == 1){
        printf("\nLista ordenada por DNI: \n\n");
    }
    
    else if(Opcion == 2){
        printf("\nLista ordenada por nombre: \n\n");
    }
    else if(Opcion == 3){
        printf("\nLista ordenada por apellido: \n\n");
    }
    ImprimirLista(Lista);
    return 0;
}