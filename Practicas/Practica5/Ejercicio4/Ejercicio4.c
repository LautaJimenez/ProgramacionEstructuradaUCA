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

int AgregarALista(tNodo *Lista, int Valor){

    if(*Lista == NULL){

        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }
    else{
        AgregarALista(&(*Lista)->Siguiente,Valor);
    }
}

void EliminarListaEntera(tNodo *Lista){

    if(*Lista != NULL){

        EliminarListaEntera(&(*Lista)->Siguiente);
        tNodo Auxiliar = *Lista;
        *Lista = Auxiliar->Siguiente;
        free(Auxiliar);
    }

}

void ImprimirLista(tNodo Lista){

    if(Lista == NULL){
        printf("La lista esta vacia.");
    }

    if(Lista != NULL){
        printf("%d - ",Lista->Valor);
        ImprimirLista(Lista->Siguiente);
    }

}

int main(){

    tNodo Lista = NULL;

    AgregarALista(&Lista,2);
    AgregarALista(&Lista,5);
    AgregarALista(&Lista,15);
    AgregarALista(&Lista,7);

    EliminarListaEntera(&Lista);
    ImprimirLista(Lista);

    return 0;
}