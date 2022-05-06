#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void *CargarStrDin(){

    int i = 0;
    char Letra;
    char* String = NULL;

    String = malloc(sizeof(char));

    if(String == NULL){ //No encuentra lugar en la memoria para poner el byte.
        return NULL;
    }

    printf("Cargar string: ");

    Letra = getchar();
    while(Letra != '\n'){
        *(String+i) = Letra; //String[i] = Letra;
        i++;
        String = realloc(String,(i+1)*sizeof(char));
        
        if(String == NULL){
            return NULL;
        }

        Letra = getchar();
    }
    
    *(String+i) = '\0'; // String[i] = '\0';

    return String;
}

int main(){

    printf("\nEl string cargado es: %s",CargarStrDin());

    return 0;
}