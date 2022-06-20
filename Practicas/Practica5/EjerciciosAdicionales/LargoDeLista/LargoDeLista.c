#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct sNodo{
    
    int Valor;
    struct sNodo *Siguiente;
};

typedef struct sNodo *tNodo;

int LargoDeLista(tNodo Lista){

    int Cantidad = 0;

    while(Lista != NULL){
        Cantidad++;
        Lista = (Lista->Siguiente);
    }
    return Cantidad;
}


void InsertarEnListaUltimo(tNodo *Lista, int Valor){

    if(*Lista == NULL){

        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }
    else{
        InsertarEnListaUltimo(&(*Lista)->Siguiente,Valor);
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
    
    InsertarEnListaUltimo(&Lista,13);
    InsertarEnListaUltimo(&Lista,8);
    InsertarEnListaUltimo(&Lista,2);
    InsertarEnListaUltimo(&Lista,11);
    InsertarEnListaUltimo(&Lista,45);
    printf("Lista: \n\n");
    ImprimirLista(Lista);

    printf("\n\nEl largo de la lista es: %d",LargoDeLista(Lista));

    return 0;
}