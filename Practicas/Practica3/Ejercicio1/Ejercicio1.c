#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void IntercambiarValoresEntrePunteros(int *Numero1 , int *Numero2){

    int NumeroAuxiliar;

    NumeroAuxiliar = *Numero1;
    *Numero1 = *Numero2;
    *Numero2 = NumeroAuxiliar;
}


int main(){

    int Numero1 = 10;
    int Numero2 = 99;

    printf("Numero 1 [%p]: %d\n",&Numero1,Numero1);
    printf("Numero 2 [%p]: %d\n",&Numero2,Numero2);
    
    IntercambiarValoresEntrePunteros(&Numero1,&Numero2);

    printf("\n\nLos numeros intercambiados son:\n\n");
    printf("Numero 1 [%p]: %d\n",&Numero1,Numero1);
    printf("Numero 2 [%p]: %d\n",&Numero2,Numero2);
    return 0;
}