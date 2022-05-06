#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h> 

#define CANTIDAD 10
#define COLUMNAS 2
#define FILAS 10



struct s_punto {
	
	int a;
	int b;
	
};

typedef struct s_punto t_punto;

void CargarPuntosEnArreglo(struct s_punto ArregloDePuntos[CANTIDAD],char NombreDeArchivo[]){
	
	FILE *Archivo;
	
	Archivo = fopen(NombreDeArchivo,"r");
	
	int i;
	
	for(i = 0 ; fscanf(Archivo,"%d,%d,",&ArregloDePuntos[i].a,&ArregloDePuntos[i].b) != EOF && i < FILAS; i++){};
	
	fclose(Archivo);
	
}
	


float DarNormaDe(struct s_punto Punto){
	
	return sqrt(pow(Punto.a,2)+pow(Punto.b,2));
	
}

void DistanciaMinimaEntreDosPuntosConsecutivos(struct s_punto ArregloDePuntos[CANTIDAD]){
	
	struct s_punto PuntoDeDiferencia;
	
	int i,Punto1A,Punto1B,Punto2A,Punto2B;
	float DistanciaEntrePuntos, DistanciaMinima;
	
	PuntoDeDiferencia.a = ArregloDePuntos[0].a - ArregloDePuntos[1].a;
	PuntoDeDiferencia.b = ArregloDePuntos[0].b - ArregloDePuntos[1].b;
	DistanciaMinima = DarNormaDe(PuntoDeDiferencia);
	
	for(i = 0 ; i<CANTIDAD-1 ; i++){
		
		PuntoDeDiferencia.a = ArregloDePuntos[i].a - ArregloDePuntos[i+1].a;
		PuntoDeDiferencia.b = ArregloDePuntos[i].b - ArregloDePuntos[i+1].b;
		DistanciaEntrePuntos = DarNormaDe(PuntoDeDiferencia);
		printf("La distancia entre los puntos (%d ; %d) y (%d ; %d) es: %.2f\n\n",ArregloDePuntos[i].a,ArregloDePuntos[i].b,ArregloDePuntos[i+1].a,ArregloDePuntos[i+1].b,DistanciaEntrePuntos);
		
		if(DistanciaEntrePuntos<DistanciaMinima){
			DistanciaMinima = DistanciaEntrePuntos;
			Punto1A = ArregloDePuntos[i].a;
			Punto1B = ArregloDePuntos[i].b;
			Punto2A = ArregloDePuntos[i+1].a;
			Punto2B = ArregloDePuntos[i+1].b;
		}
	
	}
	
	printf("La distancia minima es: %.2f, y es entre los puntos (%d ; %d) y (%d ; %d).",DistanciaMinima,Punto1A,Punto1B,Punto2A,Punto2B);
	
}
	
int main() {
		
	t_punto ArregloDePuntos[CANTIDAD];
		
	CargarPuntosEnArreglo(ArregloDePuntos,"puntos.txt");
	DistanciaMinimaEntreDosPuntosConsecutivos(ArregloDePuntos);
	return 0;
}

