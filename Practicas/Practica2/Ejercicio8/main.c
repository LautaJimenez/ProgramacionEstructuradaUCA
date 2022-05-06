#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MASCARA 128 // 10000000 = 0b10000000

void RepresentarBinarioDeChar(char Caracter){

    int Contador, Resultado;

    for(Contador = 0 ; Contador<8 ; Contador++){

        Resultado = Caracter & MASCARA;

        if(Resultado == MASCARA){
            printf("1");
        }
        else{
            printf("0");
        }
        Caracter = Caracter << 1;
    }  
    printf("\n");
}

int main(){

    RepresentarBinarioDeChar('c');
    RepresentarBinarioDeChar('C');

    return 0;
}