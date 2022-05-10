#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
    int a,b;
}t_dosint;

void IntercambiarValoresEntrePunteros(int *Numero1, int *Numero2){

    int NumeroAuxiliar;

    NumeroAuxiliar = *Numero1;
    *Numero1 = *Numero2;
    *Numero2 = NumeroAuxiliar;

}

void IntercambiarValores(t_dosint DosEnteros){

    printf("Valores originales: \n\nA : %d - B : %d",DosEnteros.a,DosEnteros.b);
    
    IntercambiarValoresEntrePunteros(&DosEnteros.a,&DosEnteros.b);

    printf("\n\nValores intercambiados: \n\nA : %d - B : %d",DosEnteros.a,DosEnteros.b);

}

int main(){

    t_dosint DosEnteros;

    DosEnteros.a = 10;
    DosEnteros.b = 99;

    IntercambiarValores(DosEnteros);
    return 0;
}