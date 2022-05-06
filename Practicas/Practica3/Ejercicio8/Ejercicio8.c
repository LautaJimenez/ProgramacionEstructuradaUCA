#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char *CargarStrDin1(){

    char *String = NULL;
    char Letra;
    int i = 0;

    String = malloc(sizeof(char));

    if(String == NULL){return NULL;}

    printf("Cargar string: ");

    Letra = getchar();

    while(Letra != '\n'){
        
        *(String+i) = Letra;
        i++;
        String = realloc(String,(i+1)*sizeof(char));

        if(String == NULL){return NULL;}

        Letra = getchar();

    }

    *(String+i) = '\0';

    //printf("\nEl string cargado es: %s",String);

    return String;

}

void CargarStrDin2(char ** PunteroString){

    int i = 0;
    char Letra;

    *PunteroString = malloc(sizeof(char));

    if(PunteroString == NULL){return NULL;} 

    printf("Cargar string: ");

    Letra = getchar();

    while(Letra != '\n'){
        
        *(*PunteroString + i) = Letra;
        i++;
        
        *PunteroString = realloc(*PunteroString,(i+1)*sizeof(char));

        Letra = getchar();
    }

    *(*PunteroString+i) = '\0';

}

void EscribirArchivo(const char *NombreArchivo, char *String){

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"w");

    int i = 0;
    char Caracter;

    Caracter = *String;

    while(Caracter != '\0'){
        //fprintf(Archivo,"%c",Caracter);
        fputc(Caracter,Archivo);
        
        i++;

        Caracter = *(String+i);
    }
    fputc('\n',Archivo);
    //fprintf(Archivo,"\n");

    fclose(Archivo);
}

void ImprimirArchivo(const char* NombreArchivo){

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"r");

    char Caracter;
    int i = 0;

    printf("\nEl contenido del archivo es: ");

    Caracter = fgetc(Archivo);

    while(Caracter != EOF){
        printf("%c",Caracter);
        Caracter = fgetc(Archivo);
    }


}

int main(){
    
    char *String = NULL;
    
    //String = CargarStrDin1();
    
    CargarStrDin2(&String);
    //printf("El string cargado es: %s, y su direccion de memoria es: %p",String,&String);

    EscribirArchivo("frase.txt",String);
    ImprimirArchivo("frase.txt");    

    return 0;
}