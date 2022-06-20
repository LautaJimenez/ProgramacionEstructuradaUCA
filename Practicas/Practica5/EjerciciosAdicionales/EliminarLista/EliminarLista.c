#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct sNodo
{
    int Valor;
    struct sNodo *Siguiente;
};

typedef struct sNodo *tNodo;

void AgregarValorALista(tNodo *Lista, int Valor){

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }

    else{
        AgregarValorALista(&(*Lista)->Siguiente,Valor);
    }
}

void EliminarLista(tNodo *Lista){

    if(*Lista != NULL){
        EliminarLista(&(*Lista)->Siguiente);
        tNodo Auxiliar = *Lista;
        *Lista = Auxiliar->Siguiente;
        free(Auxiliar);
    }
}


void ImprimirLista(tNodo Lista){

    if(Lista != NULL){
        if(Lista->Siguiente != NULL){
            printf("%d - ",Lista->Valor);
        }
        else{
            printf("%d",Lista->Valor);
        }
        
        ImprimirLista(Lista->Siguiente);
    }
}


int main(){

    tNodo Lista = NULL;
    AgregarValorALista(&Lista,32);
    AgregarValorALista(&Lista,2);
    AgregarValorALista(&Lista,4);
    AgregarValorALista(&Lista,623);
    AgregarValorALista(&Lista,11);
    AgregarValorALista(&Lista,51);
    
    printf("La lista es: \n\n");

    ImprimirLista(Lista);
    EliminarLista(&Lista);


    if(Lista == NULL){
        printf("\n\nLa lista esta vacia!");
    }
    return 0;
}