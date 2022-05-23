#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int divisionRecursiva(int a,int b){

    int Contador = 0;
    
    if(a>=b){
        Contador = 1 + divisionRecursiva(a-b,b);
    }
    return Contador;

}

int main(){

    int a = 10;
    int b = 2;

    printf("La division entre %d y %d es: %d",a,b,divisionRecursiva(a,b));

    return 0;
}