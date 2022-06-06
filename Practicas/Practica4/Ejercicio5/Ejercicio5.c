#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TERMINADOR 0

// A)

int maximoRecursivo(int *arreglo){
    
    int maximo, maximoR;

    maximo = *arreglo;

    if(*arreglo != TERMINADOR){
        arreglo++;
        maximoR = maximoRecursivo(arreglo);
        if(maximoR>maximo && *arreglo != TERMINADOR){
            maximo = maximoR;
        }
    }

    return maximo;
}   

//B)

int *memoriaMaxR(int *arreglo){

    int *maximo = NULL;
    int *maximoR = NULL;

    maximo = arreglo;

    if(*arreglo != TERMINADOR){
        arreglo++;
        maximoR = memoriaMaxR(arreglo);
        
        if(*maximoR>*maximo && *arreglo != TERMINADOR){

            maximo = maximoR;
        } 
    }

    return maximo;
}

int main(){

    int arreglo[6] = {1,2,33,4,5,TERMINADOR};
    printf("El maximo recursivo del arreglo es: %d",maximoRecursivo(arreglo));
    printf("\n\nLa direccion de memoria del maximo recursivo del arreglo es: %p",memoriaMaxR(arreglo));
    return 0;
}