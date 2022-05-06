#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

int *EntregarDireccionDeMemoria(int *ArregloDeEnteros,int Posicion){

    return ArregloDeEnteros + Posicion;

}

int main(){
    int ArregloDeEnteros[10];

    printf("Direccion de memoria del arreglo: %p\n",ArregloDeEnteros);

    int *DireccionDeMemoria = EntregarDireccionDeMemoria(ArregloDeEnteros,1);

    printf("Direccion de memoria de la posicion del arreglo: %p",DireccionDeMemoria);

    return 0;
}