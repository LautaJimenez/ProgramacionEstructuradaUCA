#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

typedef struct {
    int a,b,c;

}t_tres;

void ModificarEstructuraPorOrden(t_tres *Numeros){

    int NumeroAuxiliar;

    if((*Numeros).a > (*Numeros).b){
        NumeroAuxiliar = (*Numeros).a;
        (*Numeros).a = (*Numeros).b;
        (*Numeros).b = NumeroAuxiliar;
    }

    if((*Numeros).a > (*Numeros).c){
        NumeroAuxiliar = (*Numeros).a;
        (*Numeros).a = (*Numeros).c;
        (*Numeros).c = NumeroAuxiliar;
    }

    if((*Numeros).b > (*Numeros).c){
        NumeroAuxiliar = (*Numeros).b;
        (*Numeros).b = (*Numeros).c;
        (*Numeros).c = NumeroAuxiliar;
    }
}

int main(){


    t_tres Numeros;

    Numeros.a = 300;
    Numeros.b = 70; 
    Numeros.c = 100;
    
    printf("Numeros sin orden: %d - %d - %d\n\n",Numeros.a,Numeros.b,Numeros.c);
    
    ModificarEstructuraPorOrden(&Numeros);

    printf("Numeros ordenados: %d - %d - %d",Numeros.a,Numeros.b,Numeros.c);
}