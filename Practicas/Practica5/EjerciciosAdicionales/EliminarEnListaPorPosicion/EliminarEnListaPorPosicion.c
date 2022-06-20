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

void AgregarValor(tNodo *Lista, int Valor){

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }

    else{
        AgregarValor(&(*Lista)->Siguiente,Valor);
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

void EliminarEnListaPorPosicion(tNodo *Lista, int Posicion){

    int Valor;
    tNodo Auxiliar;

    if(*Lista != NULL){
        if(Posicion > 0){
            EliminarEnListaPorPosicion(&(*Lista)->Siguiente,Posicion-1);
        }
        if(Posicion == 0){
            Auxiliar = (*Lista);
            (*Lista) = (*Lista)->Siguiente;
            free(Auxiliar);
        }
    }

}

int main(){

    tNodo Lista = NULL;

    AgregarValor(&Lista,12);
    AgregarValor(&Lista,4);
    AgregarValor(&Lista,11);
    AgregarValor(&Lista,654);
    AgregarValor(&Lista,125);
    AgregarValor(&Lista,76);

    printf("Lista original: \n\n");

    ImprimirLista(Lista);

    EliminarEnListaPorPosicion(&Lista,3);
    printf("\n\nLista modificada: \n\n");
    ImprimirLista(Lista);


    return 0;
}