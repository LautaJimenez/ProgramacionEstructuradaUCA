#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int restoRecursivo(int a, int b){

    int resultado = a;

    if(a-b>=0){

        resultado = restoRecursivo(a-b,b);
    }

    return resultado;
}


int main(){

    int a = 7;
    int b = 3;

    printf("El resto de la division entre %d y %d es: %d",a,b,restoRecursivo(a,b));


    return 0;
}