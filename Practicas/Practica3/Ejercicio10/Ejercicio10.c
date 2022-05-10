#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct s_texto
{
    char *txt;
    unsigned int longitud;
};

typedef struct s_texto t_texto;

int CargarStringDinamico(char **Frase){

    int i = 0;
    char Letra;

    *Frase = malloc(sizeof(char));

    //if(Frase == NULL){return NULL;}

    printf("Escribe la frase: ");

    Letra = getchar();

    while(Letra != '\n'){
        
        *(*Frase + i) = Letra;
        
        i++;

        *Frase = realloc(*Frase,(sizeof(char)*(i+1)));

        //if(Frase == NULL){return NULL;}

        Letra = getchar();
    }

    int LargoDeLaFrase = i;
    
    *(*Frase + i) = '\0';

    return LargoDeLaFrase;

}

t_texto CargarTexto(){

    t_texto Texto;

    char *Frase = NULL;
    int LargoDeLaFrase;
    
    Texto.longitud = CargarStringDinamico(&Frase);
    Texto.txt = Frase;

    return Texto;

}

void EscribirArchivoDeTexto(const char *NombreArchivo, t_texto Texto){

    FILE *Archivo = fopen(NombreArchivo,"w");

    fprintf(Archivo,"%d,",Texto.longitud);

    char Letra;
    int i = 0;

    Letra = Texto.txt[i];

    while(Letra != '\0'){
        fputc(Letra,Archivo);
        i++;
        Letra = Texto.txt[i];
    }

    fputc('\n',Archivo);
}

int main(){

    EscribirArchivoDeTexto("FrasesConLongitud.csv",CargarTexto());
    return 0;
}
