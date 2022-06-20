#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct sNodo{
    int Valor;
    struct sNodo *Siguiente;
};

typedef struct sNodo *tNodo;

void InsertarEnListaOrdenado(tNodo *Lista, int Valor){

    tNodo Auxiliar = NULL;

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }
    else{
        if((*Lista)->Valor > Valor){
            Auxiliar = malloc(sizeof(struct sNodo));
            Auxiliar->Valor = Valor;
            Auxiliar->Siguiente = (*Lista);
            (*Lista) = Auxiliar;
        }
        else{
            InsertarEnListaOrdenado(&(*Lista)->Siguiente,Valor);
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
    InsertarEnListaOrdenado(&Lista,13);
    InsertarEnListaOrdenado(&Lista,7);
    InsertarEnListaOrdenado(&Lista,3);
    InsertarEnListaOrdenado(&Lista,1);
    InsertarEnListaOrdenado(&Lista,11);
    InsertarEnListaOrdenado(&Lista,24);
    InsertarEnListaOrdenado(&Lista,20);
    ImprimirLista(Lista);
    return 0;
}