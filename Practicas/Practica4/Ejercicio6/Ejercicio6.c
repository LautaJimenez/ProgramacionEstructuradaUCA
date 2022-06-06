#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TERMINADOR 0

int *DireccionMinimaRecursiva(int *Arreglo){

    int *Minimo = NULL;
    int *MinimoRecursivo = NULL;

    Minimo = Arreglo;

    if(*Arreglo != TERMINADOR){
        
        MinimoRecursivo = DireccionMinimaRecursiva(Arreglo+1);

        if((*MinimoRecursivo)<(*Minimo) && *(Arreglo+1) != TERMINADOR){
            Minimo = MinimoRecursivo;
        }
    }
    return Minimo;
}

void OrdenarArreglo(int *Arreglo){

    int *MinimoRecursivo;

    if(*Arreglo != TERMINADOR){
        MinimoRecursivo = DireccionMinimaRecursiva(Arreglo);
        Intercambio(Arreglo,MinimoRecursivo);
        OrdenarArreglo(Arreglo + 1);
    }
}

void Intercambio(int *A, int *B){
    
    int Aux;

    Aux = *A;
    *A = *B;
    *B = Aux;
}

void ImprimirArreglo(char *str, int *Arreglo){

    printf("\n%s\n",str);

    for(int i = 0 ; Arreglo[i] != TERMINADOR ; i++){
        if(Arreglo[i+1] != TERMINADOR){
            printf("%d - ",Arreglo[i]);
        }
        else{
            printf("%d",Arreglo[i]);
        }
    }
}

int main(){
    
    int Arreglo[6] = {18,33,12,56,8,TERMINADOR};
    
    ImprimirArreglo("Arreglo sin ordenar: ",Arreglo);
    
    OrdenarArreglo(Arreglo);

    ImprimirArreglo("Arreglo ordenado: ",Arreglo);
    return 0;
}