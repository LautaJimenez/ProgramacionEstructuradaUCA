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

void AgregarValorEnLista(tNodo *Lista, int Valor){

    if(*Lista == NULL){
        *Lista = malloc(sizeof(struct sNodo));
        (*Lista)->Valor = Valor;
        (*Lista)->Siguiente = NULL;
    }
    else{
        AgregarValorEnLista(&(*Lista)->Siguiente,Valor);
    }
}

void EliminarValorDeLista(tNodo *Lista, int Valor){

    tNodo Auxiliar;
    int ContadorBorrados = 0;

    if(*Lista == NULL){
        printf("Error al eliminar el valor, ya que es una lista vacia.\n");
    }


    if((*Lista)->Valor == Valor && ContadorBorrados == 0){
        Auxiliar = (*Lista);
        (*Lista) = (*Lista)->Siguiente;
        free(Auxiliar);   
    }
    else{
        EliminarValorDeLista(&(*Lista)->Siguiente,Valor);
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

    AgregarValorEnLista(&Lista,7);
    AgregarValorEnLista(&Lista,89);
    AgregarValorEnLista(&Lista,22);
    AgregarValorEnLista(&Lista,3);
    AgregarValorEnLista(&Lista,47);
    AgregarValorEnLista(&Lista,1);
    AgregarValorEnLista(&Lista,63);
    AgregarValorEnLista(&Lista,3);

    printf("La lista sin eliminar valores es: \n");
    ImprimirLista(Lista);

    EliminarValorDeLista(&Lista,3);
    EliminarValorDeLista(&Lista,1);

    printf("\n\nLa lista con valores eliminados es: \n");
    ImprimirLista(Lista);

    return 0;
}