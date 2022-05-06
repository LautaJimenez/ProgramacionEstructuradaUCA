#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MASCARA 1
#define CANTIDAD 100

int CantidadDeBitsEnUno(unsigned int Numero){

    int Contador = 0;
    int Resultado;

    for(int i = 0 ; i < CANTIDAD ; i++){
        
        Resultado = Numero & MASCARA; //Compara el numero con la máscara 1.

        if(Resultado == 1){
            Contador++;
        }

        Numero = Numero>>1; // Desplaza el numero 1 bit hacia la derecha.

    }

    return Contador;
}

int main(){

    printf("%d",CantidadDeBitsEnUno(32));
    return 0;
} 