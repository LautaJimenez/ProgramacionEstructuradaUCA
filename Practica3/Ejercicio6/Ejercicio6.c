#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int n,o,p;
    char p1[26],p2[50];
    double a,b,c;
    
} t_varios;

void IntercambiarEstructuras(t_varios *Estructura1, t_varios *Estructura2){

    t_varios EstructuraAuxiliar;

    EstructuraAuxiliar = *Estructura1;
    *Estructura1 = *Estructura2;
    *Estructura2 = EstructuraAuxiliar;

}


int main(){

    t_varios Estructura1;
    t_varios Estructura2;

    // Carga de datos de Estructura1:

    Estructura1.n = 1;
    Estructura1.o = 2;
    Estructura1.p = 3;

    strcpy(Estructura1.p1,"Lautaro");
    strcpy(Estructura1.p2,"Jimenez");

    Estructura1.a = 1.5;
    Estructura1.b = 2.5;
    Estructura1.c = 3.5;

    // Carga de datos de Estructura2:

    Estructura2.n = 4;
    Estructura2.o = 5;
    Estructura2.p = 6;

    strcpy(Estructura2.p1,"Lionel");
    strcpy(Estructura2.p2,"Messi");

    Estructura2.a = 4.5;
    Estructura2.b = 5.5;
    Estructura2.c = 6.5;

    printf("Estructuras sin intercambiar:\n\n");
    printf("Estructura 1:\n\nEnteros: %d - %d - %d",Estructura1.n,Estructura1.o,Estructura1.p);
    printf("\nPalabras: %s - %s",Estructura1.p1,Estructura1.p2);
    printf("\nNumeros Reales: %.1lf - %.1lf - %.1lf",Estructura1.a,Estructura1.b,Estructura1.c);

    printf("\n\nEstructura 2:\n\nEnteros: %d - %d - %d",Estructura2.n,Estructura2.o,Estructura2.p);
    printf("\nPalabras: %s - %s",Estructura2.p1,Estructura2.p2);
    printf("\nNumeros Reales: %.1lf - %.1lf - %.1lf",Estructura2.a,Estructura2.b,Estructura2.c);

    IntercambiarEstructuras(&Estructura1,&Estructura2);

    printf("\n\nEstructuras intercambiadas:\n\n");
    printf("Estructura 1:\n\nEnteros: %d - %d - %d",Estructura1.n,Estructura1.o,Estructura1.p);
    printf("\nPalabras: %s - %s",Estructura1.p1,Estructura1.p2);
    printf("\nNumeros Reales: %.1lf - %.1lf - %.1lf",Estructura1.a,Estructura1.b,Estructura1.c);

    printf("\n\nEstructura 2:\n\nEnteros: %d - %d - %d",Estructura2.n,Estructura2.o,Estructura2.p);
    printf("\nPalabras: %s - %s",Estructura2.p1,Estructura2.p2);
    printf("\nNumeros Reales: %.1lf - %.1lf - %.1lf",Estructura2.a,Estructura2.b,Estructura2.c);
 
    // ANEXO (Calcular el tamanio de la estructura manualmente y con sizeof)

    // Variables de tipo int tienen 4 bytes, variables de tipo char tienen 1 byte, variables de tipo double tienen 8 bytes.

    int Tamanio = 4*3 + 26 + 50 + 8*3;

    printf("\n\nEl tamanio de la estructura calculado manualmente es: %d",Tamanio);

    printf("\n\nEl tamanio de la estructura con sizeof es: %d",sizeof(Estructura1));



    return 0;
}