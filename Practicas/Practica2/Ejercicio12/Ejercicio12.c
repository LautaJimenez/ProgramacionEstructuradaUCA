#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MASCARA 32 //Cantidad de caracteres

char CambiarLetra(char Letra){

    return Letra ^ MASCARA; // El operador ^, si hay dos 1, te convierte a 0. 97("a") ^ 32(CantidadDeLetras) = 65("A").

} 

int main(){

    printf("%c",CambiarLetra('a'));
    return 0;
}