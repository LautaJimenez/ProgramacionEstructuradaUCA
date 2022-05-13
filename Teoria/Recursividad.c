#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------------------------------------------------------------------------------

/*
void FuncionRecursiva(int Contador){
    
    printf("%s\n","Hola"); //Si el printf esta afuera del if, te imprime una vez mas.
    if(Contador != 0){
        FuncionRecursiva(Contador-1);
    }
    
}

int main(){
    FuncionRecursiva(5);
    return 0;
}

*/

/* Otra opción

void FuncionRecursiva(int Contador){
    
    printf("%s\n","Hola");
    if(Contador < 5){
        FuncionRecursiva(Contador+1);
    }
    
}

int main(){
    FuncionRecursiva(0);
    return 0;
}

*/

// ------------------------------------------------------------------------------------------------------------------------------

/*
void FuncionRecursiva(int Contador){
    
    //Si el printf esta afuera del if, te imprime una vez mas.
    if(Contador != 0){
        FuncionRecursiva(Contador-1);
        printf("%s\n","Hola");
        printf("%s\n","Chau");
    }
    
}

int main(){
    FuncionRecursiva(3);
    return 0;
}
*/

// ------------------------------------------------------------------------------------------------------------------------------

/*

void FuncionRecursiva(int Contador){
    
    if(Contador != 0){
        printf("Posicion: %d -> %s\n",Contador,"Hola");
        FuncionRecursiva(Contador-1); //Primero te imprime 3 hola, y despues 3 chau. Despues de imprimir los 3 hola, vuelve a la llamada anterior
                                        // quedandose en el renglon del printf chau.
        printf("Posicion: %d -> %s\n",Contador,"Chau");
    }
}

int main(){
    FuncionRecursiva(3);
    return 0;
}

*/

// ------------------------------------------------------------------------------------------------------------------------------

/*
//Sumar numero pasado por parametro.

int SumarNumerosRecursivo(int Numero){

    //Caso base:

    if(Numero != 0){

        return Numero + SumarNumerosRecursivo(Numero-1); //3+2+1
    }

    else{
        return 0; // Te retorna 0 si el numero es cero.
    }
}

int main(){
    printf("%d",SumarNumerosRecursivo(3)); // 3+2+1
    return 0;
}
*/

/*
//Otra opcion: 

int SumarNumerosRecursivo(int Numero){

    //Caso base:

    int Resultado;

    if(Numero != 0){

        Resultado = Numero + SumarNumerosRecursivo(Numero-1); //3 + 2 + 1
    }
    
    else{
        Resultado = 0; // Te retorna 0 si el numero es cero.
    }

    return Resultado;
}

int main(){
    printf("%d",SumarNumerosRecursivo(3)); // 3+2+1
    return 0;
}

*/

// ------------------------------------------------------------------------------------------------------------------------------

/*
int MultiplicacionRecursiva(int a, int b){

    int Resultado;

    if(b != 0){

        Resultado = a + MultiplicacionRecursiva(a,b-1);
    }
    else{
        Resultado = 0;
    }

    return Resultado;

}

int main(){

    int a = 7;
    int b = 3;

    printf("El resultado es: %d",MultiplicacionRecursiva(a,b));

    return 0;
}
*/

// ------------------------------------------------------------------------------------------------------------------------------

// CLASE 13/05

/*

//Ejercicio 4 de la guia

void invertirArreglo(int *arreglo, int t){

    int aux;
    if(t>1){
        aux = arreglo[t-1];
        arreglo[t-1] = arreglo[0];
        arreglo[0] = aux;
        invertirArreglo(arreglo+1,t-2);
    }
}

void ImprimirArreglo(int *arreglo,int t){

    for(int i = 0 ; i<t ; i++){
        if(i == t-1){
            printf("%d",arreglo[i]);
        }
        else{
            printf("%d - ",arreglo[i]);
        }      
    }
    printf("\n");
}

int main(){

    int arreglo[6] = {1,2,3,4,5,6};
    printf("El arreglo original es: ");
    ImprimirArreglo(arreglo,6);
    
    invertirArreglo(arreglo,6); 
    printf("El arreglo invertido es: ");
    ImprimirArreglo(arreglo,6);

}
*/

// ------------------------------------------------------------------------------------------------------------------------------

/*

// Ejercicio 5

//A) 

#define TERMINADOR 0

int maxR(int *arreglo){

    int max, maximoRecursivo;

    max = *arreglo;

    if(*arreglo != TERMINADOR){
        arreglo++;                      // Te desplaza una posicion en el arreglo.
        maximoRecursivo = maxR(arreglo);
        if(maximoRecursivo>max && *arreglo != TERMINADOR){
            max = maximoRecursivo;
        }
    }

    return max;

}

//B)

int *memoriaMaxR(int *arreglo){

    int *max = NULL;
    int * maximoRecursivo = NULL;
    max = arreglo;

    if(*arreglo != TERMINADOR){
        arreglo++;                      // Te desplaza una posicion en el arreglo.
        maximoRecursivo = memoriaMaxR(arreglo);
        if(*maximoRecursivo>*max && *arreglo != TERMINADOR){
            max = maximoRecursivo;
        }
    }
    return max;
}

//A')

int minR(int *arreglo){

    int min, minimoRecursivo;

    min = *arreglo;

    if(*arreglo != TERMINADOR){
        arreglo++;                      // Te desplaza una posicion en el arreglo.
        minimoRecursivo = minR(arreglo);
        if(minimoRecursivo<min && *arreglo != TERMINADOR){
            min = minimoRecursivo;
        }
    }

    return min;

}

//B')

int *memoriaMinR(int *arreglo){

    int *min = NULL;
    int * minimoRecursivo = NULL;
    min = arreglo;

    if(*arreglo != TERMINADOR){
        arreglo++;                      // Te desplaza una posicion en el arreglo.
        minimoRecursivo = memoriaMinR(arreglo);
        if(*minimoRecursivo<*min && *arreglo != TERMINADOR){
            min = minimoRecursivo;
        }
    }
    return min;
}

int main(){

    int arreglo[6] = {1,88,3,-4,5,TERMINADOR};
    printf("El maximo numero del arreglo es: %d\n",maxR(arreglo));
    printf("La direccion de memoria del maximo numero del arreglo es: %p",memoriaMaxR(arreglo));

    printf("\n\nEl minimo numero del arreglo es: %d\n",minR(arreglo));
    printf("La direccion de memoria del minimo numero del arreglo es: %p",memoriaMinR(arreglo));

}

*/

// ------------------------------------------------------------------------------------------------------------------------------
