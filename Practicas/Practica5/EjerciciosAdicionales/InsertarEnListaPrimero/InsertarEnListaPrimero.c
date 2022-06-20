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

void InsertarEnListaPrimero(tNodo *Lista, int Valor){

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
    InsertarEnListaPrimero(&Lista,5);
    InsertarEnListaPrimero(&Lista,2);
    InsertarEnListaPrimero(&Lista,76);
    InsertarEnListaPrimero(&Lista,11);
    InsertarEnListaPrimero(&Lista,62);
    InsertarEnListaPrimero(&Lista,823);
    InsertarEnListaPrimero(&Lista,246);
    
    printf("Lista:\n\n");
    ImprimirLista(Lista);

    return 0;
}