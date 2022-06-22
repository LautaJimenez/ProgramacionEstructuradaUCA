#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct sFecha{
    int Dia,Mes,Anio;
};

typedef struct sFecha tFecha;

struct sContenido{
    int DNI;
    char *Nombre;
    char *Apellido;
    tFecha FechaDeNacimiento;
};

typedef struct sContenido tContenido;

struct sNodo{
    tContenido Contenido;
    struct sNodo *Siguiente;
};

typedef struct sNodo *tNodo;

void LeerCadenaDeArchivo(FILE *Archivo, char **Cadena, char Separador){

    char Caracter;
    int i = 0;

    *(Cadena) = malloc(sizeof(char));

    if(!feof(Archivo)){
        Caracter = fgetc(Archivo);
    }

    while(Caracter != Separador && !feof(Archivo)){
        (*(Cadena))[i] = Caracter;
        i++;
        *(Cadena) = realloc(*(Cadena),sizeof(char) * (i+1));
        Caracter = fgetc(Archivo);
    }

    (*(Cadena))[i] = '\0';

}

void CargarALista(tNodo *Lista, tContenido Contenido){

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Contenido = Contenido;
        (*Lista)->Siguiente = NULL;
    }

    else{
        CargarALista(&(*Lista)->Siguiente,Contenido);
    }
}

void ImprimirLista(tNodo Lista){

    if(Lista != NULL){
        printf("%-10d %-20s %-20s %-5d %-5d %-5d\n",Lista->Contenido.DNI,Lista->Contenido.Nombre,Lista->Contenido.Apellido,Lista->Contenido.FechaDeNacimiento.Dia,Lista->Contenido.FechaDeNacimiento.Mes,Lista->Contenido.FechaDeNacimiento.Anio);
        ImprimirLista(Lista->Siguiente);
    }
}

void AgregarArchivoALista(char *NombreArchivo, tNodo *Lista){

    FILE *Archivo = fopen(NombreArchivo,"r");
    
    tContenido Auxiliar = {0};
    int FechaNAC;

    while(!feof(Archivo)){
        fscanf(Archivo,"%d,",&Auxiliar.DNI);
        LeerCadenaDeArchivo(Archivo,&Auxiliar.Apellido,',');
        LeerCadenaDeArchivo(Archivo,&Auxiliar.Nombre,',');
        fscanf(Archivo,"%d\n",&FechaNAC);

        Auxiliar.FechaDeNacimiento.Dia = FechaNAC%100;
        Auxiliar.FechaDeNacimiento.Mes = (FechaNAC/100)%100;
        Auxiliar.FechaDeNacimiento.Anio = FechaNAC/10000;

        CargarALista(Lista,Auxiliar);
    }
}

void OrdenarListaPorDNI(tNodo *ListaAuxiliar, tContenido Contenido){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || Contenido.DNI < (*ListaAuxiliar)->Contenido.DNI){
        
        Auxiliar->Contenido = Contenido;
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    
    else{
        OrdenarListaPorDNI(&(*ListaAuxiliar)->Siguiente,Contenido);
    }
}

void OrdenarPorNombre(tNodo *ListaAuxiliar, tContenido Contenido){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Nombre,Contenido.Nombre) > 0){
        Auxiliar->Contenido = Contenido;
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    else{
        OrdenarPorNombre(&(*ListaAuxiliar)->Siguiente,Contenido);
    }
}

void OrdenarPorApellido(tNodo *ListaAuxiliar, tContenido Contenido){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Apellido,Contenido.Apellido) > 0){
        Auxiliar->Contenido = Contenido;
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    else{
        OrdenarPorApellido(&(*ListaAuxiliar)->Siguiente,Contenido);
    }
}

void OrdenarLista(tNodo *Lista,int Opcion){

    tNodo Auxiliar = NULL;

    while(*Lista != NULL){
        if (Opcion == 1){
            OrdenarListaPorDNI(&Auxiliar,(*Lista)->Contenido);
            *Lista = (*Lista)->Siguiente;
        }
        
        else if(Opcion == 2){
            OrdenarPorNombre(&Auxiliar,(*Lista)->Contenido);
            *Lista = (*Lista)->Siguiente;
        }
        else if(Opcion == 3){
             
            OrdenarPorApellido(&Auxiliar,(*Lista)->Contenido);
            *Lista = (*Lista)->Siguiente;
        }
    }

    *Lista = Auxiliar;
}

void ImprimirCabeceras(){
    printf("\n%-10s %-20s %-20s %-5s %-5s %-5s\n\n","DNI","Nombre","Apellido","Dia","Mes","Anio");    
}

int main(){

    tNodo Lista = NULL;
    
    AgregarArchivoALista("Informacion.txt",&Lista);
    
    ImprimirCabeceras();
    ImprimirLista(Lista);

    int Opcion;
    printf("\n\nIngrese la opcion: ");
    scanf("%d",&Opcion);
    
    OrdenarLista(&Lista,Opcion);
    ImprimirCabeceras();
    ImprimirLista(Lista);
    
    return 0;
}