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

void InsertarEnListaPorPosicion(tNodo *Lista, int Valor, int Posicion){

    if(*Lista == NULL || Posicion == 0){
        tNodo Auxiliar;

        if(*Lista == NULL){
            *Lista = malloc(sizeof(struct sNodo));
            (*Lista)->Valor = Valor;
            (*Lista)->Siguiente = NULL;
        }

        else{
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Valor = Valor;
            Auxiliar->Siguiente = (*Lista);
            (*Lista) = Auxiliar;
        }
    }

    else{
        InsertarEnListaPorPosicion(&(*Lista)->Siguiente,Valor,Posicion-1);
    }
}

void AgregarALista(tNodo *Lista, int Valor){

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }
    else{
        AgregarALista(&(*Lista)->Siguiente,Valor);
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

    InsertarEnListaPorPosicion(&Lista,1,0);
    InsertarEnListaPorPosicion(&Lista,3,2);
    InsertarEnListaPorPosicion(&Lista,4,1);
    InsertarEnListaPorPosicion(&Lista,7,4);
    InsertarEnListaPorPosicion(&Lista,21,3);
    InsertarEnListaPorPosicion(&Lista,5,5);

    printf("Lista:\n\n");

    ImprimirLista(Lista);
    return 0;
}