#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h> 

#define CantidadDeEquipos 100
#define FILA 100
#define COLUMNA 100

struct DatosEquipo
{
    char NombreEquipo[50];
    int PartidosGanados;
    int PartidosEmpatados;
    int PartidosPerdidos;
    int GolesAFavor;
    int GolesEnContra;
};

void CargarDatosDeEquiposEnEstructura(char NombreDeArchivo1[],char NombreDeArchivo2[],struct DatosEquipo ArregloDeEquipos[CantidadDeEquipos]){

    FILE *ArchivoEquipos;
    ArchivoEquipos = fopen(NombreDeArchivo1,"r");

    FILE *ArchivoPuntos;
    ArchivoPuntos = fopen(NombreDeArchivo2,"r");

    int Fila;

    for(Fila = 0 ; Fila<CantidadDeEquipos && fscanf(ArchivoEquipos,"%s\n",&ArregloDeEquipos[Fila].NombreEquipo) != EOF ; Fila++){
        fscanf(ArchivoPuntos,"%d,%d,%d,%d,%d\n",&ArregloDeEquipos[Fila].PartidosGanados,&ArregloDeEquipos[Fila].PartidosEmpatados,
                                                    &ArregloDeEquipos[Fila].PartidosPerdidos,&ArregloDeEquipos[Fila].GolesAFavor,
                                                    &ArregloDeEquipos[Fila].GolesEnContra);
        }
    
    ArregloDeEquipos[Fila].NombreEquipo[0] = '\0';

    fclose(ArchivoEquipos);
    fclose(ArchivoPuntos);
}


void ImprimirTabla(char NombreArchivo[], struct DatosEquipo ArregloDeEquipos[CantidadDeEquipos]){


    int Fila;

    int Puntos, PartidoJugados, DiferenciaDeGoles;

    char Palabra[20];

    FILE *ArchivoCabeceras;

    ArchivoCabeceras = fopen(NombreArchivo,"r");

    for(Fila = 0 ; fscanf(ArchivoCabeceras,"%s",Palabra) != EOF ; Fila++){
        printf("%-20s",Palabra);

    }
    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(Fila = 0 ; ArregloDeEquipos[Fila].NombreEquipo[0] != '\0' ; Fila++){

        Puntos = (ArregloDeEquipos[Fila].PartidosGanados * 3) + ArregloDeEquipos[Fila].PartidosEmpatados;
        PartidoJugados = ArregloDeEquipos[Fila].PartidosGanados + ArregloDeEquipos[Fila].PartidosEmpatados + ArregloDeEquipos[Fila].PartidosPerdidos;
        DiferenciaDeGoles = ArregloDeEquipos[Fila].GolesAFavor - ArregloDeEquipos[Fila].GolesEnContra;

        

        printf("%-20s",(ArregloDeEquipos[Fila].NombreEquipo));
        printf("%-20d",Puntos);
        printf("%-20d",PartidoJugados);
        printf("%-20d",(ArregloDeEquipos[Fila].PartidosGanados));
        printf("%-20d",(ArregloDeEquipos[Fila].PartidosEmpatados));
        printf("%-20d",(ArregloDeEquipos[Fila].PartidosPerdidos));
        printf("%-20d",(ArregloDeEquipos[Fila].GolesAFavor));
        printf("%-20d",(ArregloDeEquipos[Fila].GolesEnContra));
        if(DiferenciaDeGoles>0){
            printf("+%-20d",DiferenciaDeGoles);
        }
        else{printf("%-20d",DiferenciaDeGoles);}
        
        printf("\n");
    }

}




int main(){

	struct DatosEquipo ArregloDeEquipos[CantidadDeEquipos];  

    CargarDatosDeEquiposEnEstructura("equipos.txt","puntos.txt",ArregloDeEquipos);
    ImprimirTabla("cabeceras.txt",ArregloDeEquipos);
    return 0;
}
