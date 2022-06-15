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

void InsertarOrdenado(int Valor, tNodo *Lista){

    tNodo NodoAuxiliar;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }

    else{
        if((*Lista)->Valor > Valor){
        NodoAuxiliar = malloc(sizeof(struct sNodo));
        NodoAuxiliar->Valor = Valor;
        NodoAuxiliar->Siguiente = (*Lista);
        (*Lista) = NodoAuxiliar;
        }

        else{
            InsertarOrdenado(Valor,&(*Lista)->Siguiente);
        }
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

    InsertarOrdenado(7,&Lista);
    InsertarOrdenado(13,&Lista);
    InsertarOrdenado(2,&Lista);
    InsertarOrdenado(5,&Lista);
    InsertarOrdenado(16,&Lista);
    InsertarOrdenado(4,&Lista);

    ImprimirLista(Lista);
    return 0;
}