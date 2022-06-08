#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TERMINADOR '\0'
#define TAM 100

int esVocal(char Caracter){

    if(Caracter == 'A' || Caracter == 'a' || Caracter == 'E' || Caracter == 'e' || Caracter == 'I' || Caracter == 'i' || Caracter == 'O' || Caracter == 'o' ||
    Caracter == 'U' || Caracter == 'u'){
        return 1;
    }
    else{
        return 0;
    }
}

int contarVocales(char * Texto){

    int Resultado = 0;
    
    if(Texto != NULL && *Texto != TERMINADOR){
        if(esVocal(*Texto)){
            Resultado = 1 + contarVocales(Texto+1);
        }
        else{
            Resultado = contarVocales(Texto+1);
        }
    }

    return Resultado;

}

int main(){

    char Texto[TAM] = {0};
    strcpy(Texto,"Hola me llamo Lautaro");
    printf("Las vocales de la frase '%s' son %d.",Texto,contarVocales(Texto));

    return 0;
}