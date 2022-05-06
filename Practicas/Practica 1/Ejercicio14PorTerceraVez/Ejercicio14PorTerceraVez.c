#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 12
#define C 31

void CargarArchivoDeTemperaturasEnMatriz(float MatrizDeTemperaturas[F][C],char NombreDeArchivo[]);
void ImprimirMatrizDeArchivosNumericos(float MatrizDeTemperaturas[F][C]);
float CantidadDeDiasTotales(float MatrizDeDiasMedidos[F][C],char NombreDeArchivo[]);
void TemperaturaMinimaMaximayPromedioAnual(float MatrizDeTemperaturas[F][C],float MatrizDeDiasMedidos[F][C]);
void MesMasCalurosoMesMasFrioyPromedioMensual(float MatrizDeTemperaturas[F][C], float MatrizDeDiasMedidos[F][C]);

int main() {
	
	float MatrizDeTemperaturas[F][C] = {0};
	float MatrizDeDiasMedidos[F][C] = {0};
	CargarArchivoDeTemperaturasEnMatriz(MatrizDeTemperaturas,"temperaturas.txt");
	ImprimirMatrizDeArchivosNumericos(MatrizDeTemperaturas);
	TemperaturaMinimaMaximayPromedioAnual(MatrizDeTemperaturas,MatrizDeDiasMedidos);
	MesMasCalurosoMesMasFrioyPromedioMensual(MatrizDeTemperaturas,MatrizDeDiasMedidos);
	return 0;
}

void CargarArchivoDeTemperaturasEnMatriz(float MatrizDeTemperaturas[F][C],char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila;
	
	for(Fila = 0 ; Fila<F && fscanf(Archivo,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
									&MatrizDeTemperaturas[Fila][0],&MatrizDeTemperaturas[Fila][1],&MatrizDeTemperaturas[Fila][2],&MatrizDeTemperaturas[Fila][3],
									&MatrizDeTemperaturas[Fila][4],&MatrizDeTemperaturas[Fila][5],&MatrizDeTemperaturas[Fila][6],&MatrizDeTemperaturas[Fila][7],
									&MatrizDeTemperaturas[Fila][8],&MatrizDeTemperaturas[Fila][9],&MatrizDeTemperaturas[Fila][10],&MatrizDeTemperaturas[Fila][11],
									&MatrizDeTemperaturas[Fila][12],&MatrizDeTemperaturas[Fila][13],&MatrizDeTemperaturas[Fila][14],&MatrizDeTemperaturas[Fila][15],
									&MatrizDeTemperaturas[Fila][16],&MatrizDeTemperaturas[Fila][17],&MatrizDeTemperaturas[Fila][18],&MatrizDeTemperaturas[Fila][19],
									&MatrizDeTemperaturas[Fila][20],&MatrizDeTemperaturas[Fila][21],&MatrizDeTemperaturas[Fila][22],&MatrizDeTemperaturas[Fila][23],
									&MatrizDeTemperaturas[Fila][24],&MatrizDeTemperaturas[Fila][25],&MatrizDeTemperaturas[Fila][26],&MatrizDeTemperaturas[Fila][27],
									&MatrizDeTemperaturas[Fila][28],&MatrizDeTemperaturas[Fila][29],&MatrizDeTemperaturas[Fila][30]) != EOF ; Fila++);
	
	MatrizDeTemperaturas[Fila][0] = EOF;

	fclose(Archivo);
}
	
void ImprimirMatrizDeArchivosNumericos(float MatrizDeTemperaturas[F][C]){
	
	int Fila, Columna;
	
	for(Fila = 0 ; MatrizDeTemperaturas[Fila][0] != EOF ; Fila++){
		for(Columna = 0 ; MatrizDeTemperaturas[Fila][Columna] != EOF && Columna<C ; Columna++){
			printf("%.1f ",MatrizDeTemperaturas[Fila][Columna]);
		}
	printf("\n\n");
	}
	printf("\n__________________________________________________________________________________________________________________________________________________________________________________\n\n");
}

float CantidadDeDiasTotales(float MatrizDeDiasMedidos[F][C],char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila, Columna;
	int Cantidad = 0;
	
	for(Fila = 0 ; Fila<F && fscanf(Archivo,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",	&MatrizDeDiasMedidos[Fila][0],&MatrizDeDiasMedidos[Fila][1],&MatrizDeDiasMedidos[Fila][2],
																					&MatrizDeDiasMedidos[Fila][3],&MatrizDeDiasMedidos[Fila][4],&MatrizDeDiasMedidos[Fila][5],
																					&MatrizDeDiasMedidos[Fila][6],&MatrizDeDiasMedidos[Fila][7],&MatrizDeDiasMedidos[Fila][8],
																					&MatrizDeDiasMedidos[Fila][9],&MatrizDeDiasMedidos[Fila][10],&MatrizDeDiasMedidos[Fila][11]) != EOF ; Fila++);

	MatrizDeDiasMedidos[Fila][0] = EOF;
	
	for(Fila = 0 ; Fila<F && MatrizDeDiasMedidos[Fila][0] != EOF ; Fila++){
		for(Columna = 0 ; Columna<C && MatrizDeDiasMedidos[Fila][Columna] != EOF ; Columna++){
			Cantidad += MatrizDeDiasMedidos[Fila][Columna];
		}
	}
	
	return Cantidad;
}

void TemperaturaMinimaMaximayPromedioAnual(float MatrizDeTemperaturas[F][C],float MatrizDeDiasMedidos[F][C]){
	
	
	float DiasTotales = CantidadDeDiasTotales(MatrizDeDiasMedidos,"diasMedidos.txt");
	float Minimo = 99999999;
	float Maximo = -99999999;
	int Fila,Columna;
	float SumaDeTemperaturas = 0;
	
	printf("La cantidad de días totales en todo el año es: %.0f días.",DiasTotales);
	
	for(Fila = 0 ; Fila<F && MatrizDeTemperaturas[Fila][0] != EOF ; Fila++){
		
		for(Columna = 0 ; Columna<C && MatrizDeTemperaturas[Fila][Columna] != EOF ; Columna++){
			SumaDeTemperaturas += MatrizDeTemperaturas[Fila][Columna];
			
			if(MatrizDeTemperaturas[Fila][Columna] > Maximo){
				Maximo = MatrizDeTemperaturas[Fila][Columna];
			}
			if(MatrizDeTemperaturas[Fila][Columna] < Minimo){
				Minimo = MatrizDeTemperaturas[Fila][Columna];
			}
			
		}
		
	}
	float PromedioAnual = SumaDeTemperaturas/DiasTotales;
	
	printf("\n\nEl valor mínimo de temperatura es de: %.1f °C",Minimo);
	printf("\n\nEl valor máximo de temperatura es de: %.1f °C",Maximo);
	printf("\n\nEl promedio anual de temperatura es de: %.1f °C",PromedioAnual);

}

void MesMasCalurosoMesMasFrioyPromedioMensual(float MatrizDeTemperaturas[F][C], float MatrizDeDiasMedidos[F][C]){
	
	float Minimo = 99999999;
	float Maximo = -99999999;
	float CantidadDeDiasMensuales;
	float PromedioMensual;
	
	int Fila,Columna;
	
	char NombreDeMesMinimo[20] = {0};
	char NombreDeMesMaximo[20] = {0};
	
	for(Fila = 0 ; MatrizDeTemperaturas[Fila][0] != EOF && Fila<F ; Fila++){
		
		CantidadDeDiasMensuales = MatrizDeDiasMedidos[0][Fila];
		float SumaDeTemperaturasMensuales = 0;
		
		for(Columna = 0 ; MatrizDeTemperaturas[Fila][Columna] != EOF && Columna<C ; Columna++){
			SumaDeTemperaturasMensuales += MatrizDeTemperaturas[Fila][Columna];
		}
	
		PromedioMensual = SumaDeTemperaturasMensuales/CantidadDeDiasMensuales;
		
		if(Fila == 0){
			printf("\n\nEl promedio de temperaturas de Enero es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Enero");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
					strcpy(NombreDeMesMinimo,"Enero");
			}
		}
		
		if(Fila == 1){ 
			printf("\nEl promedio de temperaturas de Febrero es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Febrero");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Febrero");
			}
		}
		if(Fila == 2){
			printf("\nEl promedio de temperaturas de Marzo es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Marzo");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Marzo");
			}
		}

		if(Fila == 3){
			printf("\nEl promedio de temperaturas de Abril es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Abril");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Abril");
			}
		}
		if(Fila == 4){
			printf("\nEl promedio de temperaturas de Mayo es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Mayo");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Mayo");
			}
		}

		if(Fila == 5){
			printf("\nEl promedio de temperaturas de Junio es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Junio");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Junio");
			}
		}
		if(Fila == 6){
			printf("\nEl promedio de temperaturas de Julio es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Julio");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Julio");
			}
		}
		if(Fila == 7){
			printf("\nEl promedio de temperaturas de Agosto es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Agosto");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Agosto");
			}
		}
		if(Fila == 8){
			printf("\nEl promedio de temperaturas de Septiembre es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Septiembre");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Septiembre");
			}
		}
		if(Fila == 9){
			printf("\nEl promedio de temperaturas de Octubre es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Octubre");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Octubre");
			}
		}
		if(Fila == 10){
			printf("\nEl promedio de temperaturas de Noviembre es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Noviembre");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Noviembre");
			}
		}
		if(Fila == 11){
			printf("\nEl promedio de temperaturas de Diciembre es de: %.1f °C",PromedioMensual);
			
			if(PromedioMensual>Maximo){
				Maximo = PromedioMensual;
				strcpy(NombreDeMesMaximo,"Diciembre");
			}
			
			if(PromedioMensual<Minimo){
				Minimo = PromedioMensual;
				strcpy(NombreDeMesMinimo,"Diciembre");
			}
		}
		
	}
	
	printf("\n\nLa temperatura promedio máxima es de :%.1f °C, y corresponde al mes de %s.",Maximo,NombreDeMesMaximo);
	printf("\nLa temperatura promedio mínima es de :%.1f °C, y corresponde al mes de %s.",Minimo,NombreDeMesMinimo);
}
