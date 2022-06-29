#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct sFecha{

    int Dia, Mes, Anio;

};

typedef struct sFecha tFecha;

struct sInformacion{
    
    int DNI;
    char *Nombre;
    char *Apellido;
    tFecha FechaDeNacimiento;

};

typedef struct sInformacion tInformacion;

struct sNodo{

    tInformacion Contenido;
    struct sNodo *Siguiente;
};

typedef struct sNodo *tNodo;

void ObtenerCadenaDeArchivo(FILE *Archivo,char ** Cadena, char Separador){

    char Caracter;
    int i = 0;

    *(Cadena) = malloc(sizeof(char));

    if(!feof(Archivo)){
        Caracter = fgetc(Archivo);
    }

    while(Caracter != Separador && !feof(Archivo)){
        (*(Cadena))[i] = Caracter;
        i++; 
        *(Cadena) = realloc(*(Cadena),sizeof(char)*(i+1));
        Caracter = fgetc(Archivo);
    }

    (*(Cadena))[i] = '\0';
}

void CargarALista( tInformacion ContenidoAuxiliar,tNodo *Lista){

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Contenido = ContenidoAuxiliar;
        (*Lista)->Siguiente = NULL;
    }
    else{
        CargarALista(ContenidoAuxiliar,&(*Lista)->Siguiente);
    }
}

void CargarArchivoEnLista(char *NombreArchivo, tNodo *Lista){

    FILE *Archivo = fopen(NombreArchivo,"r");
    tInformacion ContenidoAuxiliar = {0};
    int FechaDeNacimientoAuxiliar;

    while(!feof(Archivo)){
  
        fscanf(Archivo,"%d,",&ContenidoAuxiliar.DNI);  
        
        ObtenerCadenaDeArchivo(Archivo,&ContenidoAuxiliar.Apellido,',');
        ObtenerCadenaDeArchivo(Archivo,&ContenidoAuxiliar.Nombre,',');
        fscanf(Archivo,"%d\n",&FechaDeNacimientoAuxiliar);

        ContenidoAuxiliar.FechaDeNacimiento.Dia = FechaDeNacimientoAuxiliar%100;
        ContenidoAuxiliar.FechaDeNacimiento.Mes = (FechaDeNacimientoAuxiliar/100)%100;
        ContenidoAuxiliar.FechaDeNacimiento.Anio = FechaDeNacimientoAuxiliar/10000;

        CargarALista(ContenidoAuxiliar,Lista);
    }
}

// FUNCIONES DE ORDENAMIENTO

void OrdenarListaPorDNI(tNodo *ListaAuxiliar, tInformacion Contenido){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || (*ListaAuxiliar)->Contenido.DNI > Contenido.DNI){
        Auxiliar->Contenido = Contenido;
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    else{
        OrdenarListaPorDNI(&(*ListaAuxiliar)->Siguiente,Contenido);
    }
}

void OrdenarListaPorNombre(tNodo *ListaAuxiliar, tInformacion Contenido){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));
    if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Nombre,Contenido.Nombre)>0){
        Auxiliar->Contenido = Contenido;
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    else{
        OrdenarListaPorNombre(&(*ListaAuxiliar)->Siguiente,Contenido);
    }
}

void OrdenarListaPorApellido(tNodo *ListaAuxiliar, tInformacion Contenido){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Apellido,Contenido.Apellido)>0){
        Auxiliar->Contenido = Contenido;
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    else{
        OrdenarListaPorApellido(&(*ListaAuxiliar)->Siguiente,Contenido);
    }
}

void OrdenarListaPorAnio(tNodo *ListaAuxiliar,tInformacion Contenido){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));

    if(*ListaAuxiliar == NULL || (*ListaAuxiliar)->Contenido.FechaDeNacimiento.Anio > Contenido.FechaDeNacimiento.Anio){
        Auxiliar->Contenido = Contenido;
        Auxiliar->Siguiente = *ListaAuxiliar;
        *ListaAuxiliar = Auxiliar;
    }
    else{
        OrdenarListaPorAnio(&(*ListaAuxiliar)->Siguiente,Contenido);
    }


}

void OrdenarLista(int Opcion, tNodo *Lista){

    tNodo ListaAuxiliar = NULL;

    while(*Lista != NULL){

        if(Opcion == 1){
            OrdenarListaPorDNI(&ListaAuxiliar,(*Lista)->Contenido);
            *Lista = (*Lista)->Siguiente;
        }
        if(Opcion == 2){
            OrdenarListaPorNombre(&ListaAuxiliar,(*Lista)->Contenido);
            *Lista = (*Lista)->Siguiente;
        }
        if(Opcion == 3){
            OrdenarListaPorApellido(&ListaAuxiliar,(*Lista)->Contenido);
            *Lista = (*Lista)->Siguiente;
        }
        if(Opcion == 4){
            OrdenarListaPorAnio(&ListaAuxiliar,(*Lista)->Contenido);
            *Lista = (*Lista)->Siguiente;
        }
    }
    *Lista = ListaAuxiliar;
}

// Funcion de eliminar de la lista.

void EliminarDeLaListaPorValor(tNodo *Lista,int Inferior, int Superior){

    tNodo Auxiliar = NULL;
      
    if(*Lista != NULL){
    
        if((*Lista)->Contenido.FechaDeNacimiento.Anio > Inferior && (*Lista)->Contenido.FechaDeNacimiento.Anio < Superior){
            Auxiliar = (*Lista);
            *Lista = (*Lista)->Siguiente;
            free(Auxiliar);  
        }
    
        else{
            EliminarDeLaListaPorValor(&(*Lista)->Siguiente,Inferior,Superior);
        }
    }
}

// FUNCIONES DE IMPRESION

void ImprimirCabeceras(){
    printf("%-10s %-12s %-12s %s\n\n","DNI","Nombre","Apellido","Fecha de nacimiento");
}

void ImprimirLista(tNodo Lista){

    if(Lista != NULL){
        printf("%-10d %-12s %-12s %d/%d/%d\n",Lista->Contenido.DNI,Lista->Contenido.Nombre,Lista->Contenido.Apellido,Lista->Contenido.FechaDeNacimiento.Dia,Lista->Contenido.FechaDeNacimiento.Mes,Lista->Contenido.FechaDeNacimiento.Anio);
        ImprimirLista(Lista->Siguiente);
    }  
}



int main(){

    tNodo Lista = NULL;
    CargarArchivoEnLista("Informacion.txt",&Lista);
    
    ImprimirCabeceras();
    ImprimirLista(Lista);

    int Opcion;
    printf("Elige la opcion para ordenar la lista:\n\n1: Por DNI\n2: Por nombre\n3: Por apellido\n4: Por año de nacimiento\n\nOpcion: ");
    scanf("%d",&Opcion);

    OrdenarLista(Opcion,&Lista);

    printf("\n");
    ImprimirCabeceras();
    ImprimirLista(Lista);

    // Se tienen que eliminar las personas que nacieron entre 1968 (sin incluir) y 2000 (sin incluir).

    EliminarDeLaListaPorValor(&Lista,1968,2000);
    printf("\n\n");
    ImprimirCabeceras();
    ImprimirLista(Lista);

    return 0;
}

