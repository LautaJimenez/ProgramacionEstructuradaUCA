#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int multiplicacionRecursiva(int a, int b){

    int resultado;

    if(b!=0){
        resultado =  a + (multiplicacionRecursiva(a,b-1));
    }

    else{
        resultado = 0;
    }

    return resultado;
}


int main(){

    int a = 10;
    int b = 5;
    
    printf("La multiplicacion entre %d y %d es: %d",a,b,multiplicacionRecursiva(a,b));

    return 0;
}