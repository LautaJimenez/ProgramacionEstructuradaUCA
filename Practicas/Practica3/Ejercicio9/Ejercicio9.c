#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char *subcadena(char *p, unsigned int i, unsigned int n){

    char *SubCadena = NULL;
    char Letra;
    int CantidadDeLetras = 0;
    int LongitudDeLaFrase = 0;
    int CantidadDeLetrasATomar = n;
    int CantidadDeLetrasATomarAux = 0;

    if(CantidadDeLetrasATomar < 0){
        CantidadDeLetrasATomarAux = -CantidadDeLetrasATomar;}

    while(p[LongitudDeLaFrase] != '\0'){
        LongitudDeLaFrase++;
    }
    
    SubCadena = malloc(sizeof(char));

    //Que se haga unicamente cuando i sea menor a la longitud de la frase.

    if(i < LongitudDeLaFrase){

        Letra = p[i];
        while(CantidadDeLetras < CantidadDeLetrasATomarAux){
            
            SubCadena[CantidadDeLetras] = Letra;
            CantidadDeLetras++;

            SubCadena = realloc(SubCadena,sizeof(char)*(CantidadDeLetras));

            if(CantidadDeLetrasATomar < 0){
                Letra = p[i-CantidadDeLetras];
            }
            else{
                Letra = p[i+CantidadDeLetras];
            }  
        }
    }

    SubCadena[CantidadDeLetras] = '\0';

    return SubCadena;
}

char * leerArch(const char* nomArch){
    
    char *Frase = NULL;
    int i = 0;
    char Letra;

    FILE *Archivo = fopen(nomArch,"r");

    Frase = malloc(sizeof(char));

    if(Frase == NULL){return NULL;}

    Letra = fgetc(Archivo);

    while(Letra != '\n'){
        Frase[i] = Letra;
        i++;
        Frase = realloc(Frase,sizeof(char)*(i+1));
        Letra = fgetc(Archivo);

        if(Frase == NULL){return NULL;}
    }

    Frase[i] = '\0';

    fclose(Archivo);

    return Frase;
}

int main(){

    char* str = NULL;
    char* subStr = NULL;
    
    int i=8, n=-4;
    
    str = leerArch("frase.txt");
    
    subStr = subcadena (str, i, n);
    
    printf("Para i = %d y n = %d ,Se encontro el substring: ", i,n);
    printf("%s", subStr);
    
    return 0;
}