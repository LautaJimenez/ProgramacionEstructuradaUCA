#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void invertirRecursivo(int *arreglo, int largo){

    int aux;

    if(largo>1){
        aux = arreglo[largo-1];
        arreglo[largo-1] = arreglo[0];
        arreglo[0] = aux;
        
        invertirRecursivo(arreglo+1,largo-2);
    }
}



void imprimirArreglo(int *arreglo, int largo){

    for(int i = 0 ; i<largo; i++){
        if(i<largo-1){
            printf("%d - ",arreglo[i]);
        }
        else if(i<largo){
            printf("%d",arreglo[i]);
        }
    }
}
int main(){

    int arreglo[6] = {1,2,3,4,5,6};
    printf("El arreglo sin invertir es: \n");
    imprimirArreglo(arreglo,6);
    printf("\n\nEl arreglo invertido es: \n");
    invertirRecursivo(arreglo,6);
    imprimirArreglo(arreglo,6); 
    return 0;
}