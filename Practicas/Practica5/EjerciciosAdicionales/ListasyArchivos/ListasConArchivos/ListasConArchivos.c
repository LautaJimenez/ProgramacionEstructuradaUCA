#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Este programa lee un archivo, y lo carga en una lista. Y luego, se ordena la lista. TERMINAR DE ORDENAR LA LISTA!

struct sFecha{
    int Dia, Mes, Anio;
};
typedef struct sFecha tFecha;

struct sContenido{
    int DNI;
    char *Apellido;
    char *Nombre;
    tFecha FechaDeNacimiento;
};

typedef struct sContenido tContenido;

struct sNodo{
    tContenido Contenido;
    struct sNodo *Siguiente;
};

typedef struct sNodo *tNodo;

void LeerCadenaDeArchivo(FILE *Archivo, char ** Cadena, char Separador){

    char Caracter;
    int i = 0;

    *(Cadena) = malloc(sizeof(char));

    if(!feof(Archivo)){
        Caracter = fgetc(Archivo);
    }

    while(!feof(Archivo) && Caracter != Separador){
        (*(Cadena))[i] = Caracter;
        i++;
        *(Cadena) = realloc(*(Cadena),sizeof(char)*(i+1));
        Caracter = fgetc(Archivo);
    }

    (*(Cadena))[i] = '\0';
}

void OrdenarPorDNI(tNodo *Lista,tContenido Contenido){

    tNodo Auxiliar = NULL;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Contenido = Contenido;
        (*Lista)->Siguiente = NULL;
    }

    else{
        if((*Lista)->Contenido.DNI > Contenido.DNI){
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Siguiente = (*Lista);
            Auxiliar->Contenido = Contenido;
            (*Lista) = Auxiliar;
        }
        else{
            OrdenarPorDNI(&(*Lista)->Siguiente,Contenido);
        }
    }
}

void OrdenarPorNombre(tNodo *Lista,tContenido Contenido){

    tNodo Auxiliar = NULL;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Contenido = Contenido;
        (*Lista)->Siguiente = NULL;
    }

    else{
        if(strcmp((*Lista)->Contenido.Nombre,Contenido.Nombre) > 0){
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Siguiente = (*Lista);
            Auxiliar->Contenido = Contenido;
            (*Lista) = Auxiliar;
        }
        else{
            OrdenarPorNombre(&(*Lista)->Siguiente,Contenido);
        }
    }
}

void OrdenarPorApellido(tNodo *Lista,tContenido Contenido){

    tNodo Auxiliar = NULL;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Contenido = Contenido;
        (*Lista)->Siguiente = NULL;
    }

    else{
        if(strcmp((*Lista)->Contenido.Apellido,Contenido.Apellido) > 0){
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Siguiente = (*Lista);
            Auxiliar->Contenido = Contenido;
            (*Lista) = Auxiliar;
        }
        else{
            OrdenarPorApellido(&(*Lista)->Siguiente,Contenido);
        }
    }
}

void OrdenarLista(tNodo *Lista, tContenido Contenido, int Opcion){
    
    if(Opcion == 1){
            OrdenarPorDNI(Lista,Contenido);
        }
        else if(Opcion == 2){
            OrdenarPorNombre(Lista,Contenido);
        }
        else if(Opcion == 3){
            OrdenarPorApellido(Lista,Contenido);
        }
}

void CargarEnListaOrdenadaDesdeArchivo(tNodo *Lista, char *NombreArchivo, int Opcion){

    FILE *Archivo = fopen(NombreArchivo,"r");

    tContenido Contenido = {0};
    int FechaAuxiliar;

    while(!feof(Archivo)){
        fscanf(Archivo,"%d,",(&Contenido.DNI));
        LeerCadenaDeArchivo(Archivo,(&Contenido.Apellido),',');
        LeerCadenaDeArchivo(Archivo,(&Contenido.Nombre),',');
        fscanf(Archivo,"%d\n",&FechaAuxiliar);

        Contenido.FechaDeNacimiento.Dia = FechaAuxiliar%100;
        Contenido.FechaDeNacimiento.Mes = (FechaAuxiliar/100)%100;
        Contenido.FechaDeNacimiento.Anio = FechaAuxiliar/10000;

        OrdenarLista(Lista,Contenido,Opcion);
        
    }
}

void ImprimirLista(tNodo Lista){

    if(Lista != NULL){
        printf("%-20s %-20s %-10d %-5d %-5d %-5d\n",Lista->Contenido.Nombre,Lista->Contenido.Apellido,Lista->Contenido.DNI,Lista->Contenido.FechaDeNacimiento.Dia,Lista->Contenido.FechaDeNacimiento.Mes,Lista->Contenido.FechaDeNacimiento.Anio);
    }
    ImprimirLista(Lista->Siguiente);
}

int main(){

    tNodo Lista = NULL;
    int Opcion;
    printf("Ingrese opcion para imprimir la lista: \n\n1: Por DNI\n2: Por nombre\n3: Por apellido");
    printf("\n\nIngrese opcion: ");
    scanf("%d",&Opcion);

    CargarEnListaOrdenadaDesdeArchivo(&Lista,"Informacion.txt",Opcion);
    printf("\n%-20s %-20s %-10s %-5s %-5s %-5s\n\n","Nombre","Apellido","DNI","Dia","Mes","Anio");
    ImprimirLista(Lista);

    return 0;
}