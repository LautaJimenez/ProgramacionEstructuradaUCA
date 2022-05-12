#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Este ejercicio es para mostrar el dia 11/05, ya que no se realizara el Parcialito 2, y se hace para practicar Estructuras, punteros y memoria dinamica.

// Consigna: Hacer el ejercicio de Equipos (Practica 2, Ejercicio 3), pero con estructuras dinamicas. 
// Agregar otro campo (Fecha, Promedios de gol, Tarjetas rojas, etc), y trabajarlos con bits.

struct s_equipo{

    char *Equipo;
    unsigned int Puntos, PartidosJugados, PartidosGanados, PartidosEmpatados, PartidosPerdidos, GolesAFavor, GolesEnContra, DiferenciaDeGol;
};

typedef struct s_equipo t_equipo;

void CargarNombreDeEquiposAEstructura(t_equipo ** Equipos){

    FILE *ArchivoEquipos = fopen("equipos.txt","r");
    
    char ** MatrizDeEquipos = NULL;
    char *NombreDeEquipo = NULL;
    char Caracter;

    Caracter = fgetc(ArchivoEquipos);

    MatrizDeEquipos = malloc(sizeof(char*));

    for(int i = 0 ; Caracter != EOF ; i++){
        
        int ContadorCaracteres = 0;
        NombreDeEquipo = malloc(sizeof(char));

        for(int j = 0 ; Caracter != '\n' ; j++){           
            
            NombreDeEquipo = realloc(NombreDeEquipo,sizeof(char)*(j+1));
            *(NombreDeEquipo + j) = Caracter;
            Caracter = fgetc(ArchivoEquipos); 
            ContadorCaracteres = j;         
        }
        
        NombreDeEquipo = realloc(NombreDeEquipo,sizeof(char)*(ContadorCaracteres+1));
        *(NombreDeEquipo + ContadorCaracteres+1) = '\0';
        
        MatrizDeEquipos = realloc(MatrizDeEquipos,sizeof(char*) * (i+1));

        *(MatrizDeEquipos + i) = NombreDeEquipo;

        Caracter = fgetc(ArchivoEquipos);

    }

    for(int Fila = 0 ; *(MatrizDeEquipos + Fila) != NULL ; Fila++){

        printf("%s\n",*(MatrizDeEquipos + Fila));

    }

    //Cargar en la estructura:

    // *Equipos = malloc(sizeof(t_equipo));
    // int ContadorDeEquipos = 0;

    // for(int Fila = 0 ; *(MatrizDeEquipos + Fila) != NULL ; Fila++){
        
    //     (*(*Equipos + Fila)).Equipo = *(MatrizDeEquipos + Fila);
    //     *Equipos = realloc(*Equipos,sizeof(t_equipo)*(Fila+1));
    //     ContadorDeEquipos = Fila;
    // }

    // (*(*Equipos + ContadorDeEquipos)).Equipo = NULL;


    fclose(ArchivoEquipos);
}

void ImprimirEstructura(t_equipo *Equipos){

    for(int i = 0 ; Equipos[i].Equipo != NULL ; i++){
        printf("%s\n",Equipos[i].Equipo);

    }

}

int main(){
    
    t_equipo *Equipos = NULL;
    CargarNombreDeEquiposAEstructura(&Equipos);
    ImprimirEstructura(Equipos);
    return 0;
}
