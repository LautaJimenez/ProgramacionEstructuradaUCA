#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct sNodo
{
    int Valor;
    struct sNodo *Siguiente;
};

typedef struct sNodo* tNodo;

void AgregarNumeroALista(int Valor, tNodo* Lista){
    
    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }
    else{
        AgregarNumeroALista(Valor,&((*Lista)->Siguiente));
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

void ImprimirListaAlReves(tNodo Lista){

    if(Lista != NULL){
        ImprimirListaAlReves(Lista->Siguiente);
        printf("%d - ",Lista->Valor);
    }
}


int main(){

    tNodo ListaDeNumeros;
    ListaDeNumeros = NULL;

    AgregarNumeroALista(82,&ListaDeNumeros);
    AgregarNumeroALista(2,&ListaDeNumeros);
    AgregarNumeroALista(15,&ListaDeNumeros);
    AgregarNumeroALista(77,&ListaDeNumeros);   

    printf("---------- LISTA ----------\n");
    ImprimirLista(ListaDeNumeros); 
    printf("\n---------- LISTA REVERSA ----------\n");
    ImprimirListaAlReves(ListaDeNumeros);

    return 0;
}