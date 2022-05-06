#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MASCARA 127 // 0b01111111 -> 01111111

char ShiftALaDerecha(char N){

    int Resultado = (N >> 1) & MASCARA;

    return Resultado;
}

int main(){

    printf("%d",ShiftALaDerecha(189));
    return 0;
}
