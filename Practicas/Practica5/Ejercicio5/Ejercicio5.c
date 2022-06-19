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

struct sCola
{
    tNodo Frente;
    tNodo Final;
};
typedef struct sCola tCola;

void Push(tNodo *Pila, int Valor){

    tNodo NodoAuxiliar;
    NodoAuxiliar = malloc(sizeof(struct sNodo));

    NodoAuxiliar->Valor = Valor;
    NodoAuxiliar->Siguiente = *Pila;
    *Pila = NodoAuxiliar;
}

int Pop(tNodo *Pila){
    int Valor;

    tNodo NodoAuxiliar = *Pila;
    Valor = NodoAuxiliar->Valor;
    *Pila = NodoAuxiliar->Siguiente;
    free(NodoAuxiliar);
    return Valor;
}

void ImprimirPila(tNodo Pila){
    while(Pila != NULL){
        printf("%d - ",Pop(&Pila));
    }
}

void queue(tCola *Cola, int Valor){

    tNodo Auxiliar = malloc(sizeof(struct sNodo));
    Auxiliar->Valor = Valor;
    Auxiliar->Siguiente = NULL;

    if(Cola->Frente == NULL && Cola->Final == NULL){
        Cola->Frente = Auxiliar;
        Cola->Final = Auxiliar;
    }

    else{
        Cola->Final->Siguiente = Auxiliar;
        Cola->Final = Auxiliar;
    }
}

int dequeue(tCola *Cola){
    int Valor;

    tNodo Auxiliar = Cola->Frente;
    Cola->Frente = Cola->Frente->Siguiente;
    Valor = Auxiliar->Valor;

    free(Auxiliar);

    if(Cola->Frente == NULL){
        Cola->Final == NULL;
    }

    return Valor;
}

void ImprimirCola(tCola Cola){
    while(Cola.Final != NULL){
        printf("%d - ",dequeue(&Cola));
    }
}

int main(){

    tNodo Pila = NULL;
    Push(&Pila,4);
    Push(&Pila,7);
    Push(&Pila,1);
    Push(&Pila,44);
    Push(&Pila,53);
    
    printf("Elementos de la pila: \n");
    
    ImprimirPila(Pila);

    tCola Cola;
    Cola.Frente = NULL;
    Cola.Final = NULL;

    queue(&Cola,4);
    queue(&Cola,7);
    queue(&Cola,1);
    queue(&Cola,44);
    queue(&Cola,53);

    printf("\n\nElementos de la cola: \n");

    ImprimirCola(Cola);

}