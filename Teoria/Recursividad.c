#include <stdio.h>
#include <stdlib.h>


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