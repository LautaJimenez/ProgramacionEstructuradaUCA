#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct s_texto
{
    char *Texto;
    unsigned int Longitud;
};

typedef struct s_texto t_texto;

//Funciones del ejercicio 10 (CargarStrDinamico y CargarTexto):

int CargarStrDinamico(char **Frase){

    char Letra;
    int i = 0;

    *Frase = malloc(sizeof(char));

    printf("Ingresar Frase: ");

    Letra = getchar();

    while(Letra != '\n'){
        
        *(*Frase + i) = Letra;
        i++;
        
        *Frase = realloc(*Frase,sizeof(char) * (i+1));

        Letra = getchar();

    }

    int LargoDeFrase = i;

    *(*Frase + i) = '\0';

    return LargoDeFrase;

}

t_texto CargarTexto(){

    t_texto Texto;

    char *Frase;

    Texto.Longitud = CargarStrDinamico(&Frase);
    Texto.Texto = Frase;

    return Texto;

}

// A)

void IngresarFrases(t_texto ** Textos){

    t_texto TextoNuevo;
    int ContadoDeTextos = 0;

    *Textos = malloc(sizeof(t_texto));

    TextoNuevo = CargarTexto();

    while(TextoNuevo.Longitud != 0){
        
        *(*Textos + ContadoDeTextos) = TextoNuevo;

        ContadoDeTextos++;
        
        *Textos = realloc(*Textos,sizeof(t_texto)*(ContadoDeTextos+1));
    
        TextoNuevo = CargarTexto();
    }

    (*(*Textos + ContadoDeTextos)).Texto = NULL;

}

// B)

void OrdenarAlfabeticamente(t_texto *Textos){

    int i,j;

    t_texto TextoAuxiliar;

    for(int i = 0 ; (*(Textos+i)).Texto != NULL ; i++){
        for(int j = i+1 ; (*(Textos+j)).Texto != NULL ; j++){
            if(strcmp(((*(Textos+i)).Texto),((*(Textos+j)).Texto)) > 0){
                TextoAuxiliar = (*(Textos+i));
                (*(Textos+i)) = (*(Textos+j));
                (*(Textos+j)) = TextoAuxiliar;
            }
        }
    }
}

// C)

void ImprimirEstructura(t_texto *Textos){

    printf("\nLas frases ingresadas fueron las siguientes: \n");
    for(int i = 0 ; Textos[i].Longitud != 0 && Textos[i].Texto != NULL ; i++){
        printf("%d : %s\n",i+1,Textos[i].Texto);
    }
}

// D)

void AgregarTextoAArchivo(t_texto Textos){

    FILE *Archivo = fopen("FrasesConLongitud.csv","a");

    int i = 0;
    char Letra;

    fprintf(Archivo,"%d,",Textos.Longitud);

    Letra = Textos.Texto[i];


    while(Letra != '\0' && i < Textos.Longitud){
        fputc(Letra,Archivo);
        i++;
        Letra = Textos.Texto[i];
        
    }

    fputc('\n',Archivo);

    fclose(Archivo);

}

void AgregarEstructuraAArchivo(t_texto *Textos){


    for(int i = 0 ; (*(Textos)).Texto != NULL ; i++){
        
        AgregarTextoAArchivo(*(Textos+i));
    }
}

int main(){

    t_texto *Textos = NULL;

    IngresarFrases(&Textos);
    OrdenarAlfabeticamente(Textos);
    ImprimirEstructura(Textos);
    AgregarEstructuraAArchivo(Textos);
    
    return 0;
}