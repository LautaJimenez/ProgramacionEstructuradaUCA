#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void *RedondearNumero(double *PunteroDelNumeroReal){

    double NumeroReal = *PunteroDelNumeroReal;
    int NumeroEntero = NumeroReal;

    printf("Direccion de memoria del numero real %.2lf: %p\n\n",*PunteroDelNumeroReal,PunteroDelNumeroReal);
    printf("Direccion de memoria del numero real auxiliar %.2lf: %p\n\n",NumeroReal,&NumeroReal);
    printf("Direccion de memoria del numero entero %d: %p\n\n",NumeroEntero,&NumeroEntero);

    if((NumeroReal-NumeroEntero) != 0){
        *PunteroDelNumeroReal = NumeroEntero+1;
    }
}

int main(){

    double NumeroReal = 1.99;
    RedondearNumero(&NumeroReal);
    printf("El numero redondeado es %.0lf. Su direccion de memoria es: %p\n\n",NumeroReal,&NumeroReal);

    return 0;
}