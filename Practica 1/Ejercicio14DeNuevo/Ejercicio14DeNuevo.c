#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 12
#define C 31

void CargarArchivoNumericoEnMatriz(int MatrizDeTemperaturas[F][C], char NombreDeArchivo[]);
void ImprimirMatrizDeArchivosNumericos(int MatrizDeTemperaturas[F][C]);
void ValorMinimoMaximoyPromedio(int MatrizDeTemperaturas[F][C]);
void ValorPromedioDeTemperaturaMensual(int MatrizDeTemperaturas[F][C], int MatrizDeDiasMedidos[F][C]);


int main() {
	
	int MatrizDeTemperaturas[F][C] = {0};
	int MatrizDeDiasMedidos[F][C] = {0};
	CargarArchivoNumericoEnMatriz(MatrizDeTemperaturas,"temperaturas.txt");
	CargarArchivoNumericoEnMatriz(MatrizDeDiasMedidos,"diasMedidos.txt");
	ImprimirMatrizDeArchivosNumericos(MatrizDeTemperaturas);
	ValorMinimoMaximoyPromedio(MatrizDeTemperaturas);
	ValorPromedioDeTemperaturaMensual(MatrizDeTemperaturas,MatrizDeDiasMedidos);
	
	return 0;
}

void CargarArchivoNumericoEnMatriz(int MatrizDeTemperaturas[F][C], char NombreDeArchivo[]){
	
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila;
	
	for(Fila = 0 ; Fila<F && fscanf(Archivo,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&MatrizDeTemperaturas[Fila][0],&MatrizDeTemperaturas[Fila][1],&MatrizDeTemperaturas[Fila][2],
																					&MatrizDeTemperaturas[Fila][3],&MatrizDeTemperaturas[Fila][4],&MatrizDeTemperaturas[Fila][5],
																					&MatrizDeTemperaturas[Fila][6],&MatrizDeTemperaturas[Fila][7],&MatrizDeTemperaturas[Fila][8],
																					&MatrizDeTemperaturas[Fila][9],&MatrizDeTemperaturas[Fila][10],&MatrizDeTemperaturas[Fila][11],
																					&MatrizDeTemperaturas[Fila][12],&MatrizDeTemperaturas[Fila][13],&MatrizDeTemperaturas[Fila][14],
																					&MatrizDeTemperaturas[Fila][15],&MatrizDeTemperaturas[Fila][16],&MatrizDeTemperaturas[Fila][17],
																					&MatrizDeTemperaturas[Fila][18],&MatrizDeTemperaturas[Fila][19],&MatrizDeTemperaturas[Fila][20],
																					&MatrizDeTemperaturas[Fila][21],&MatrizDeTemperaturas[Fila][22],&MatrizDeTemperaturas[Fila][23],
																					&MatrizDeTemperaturas[Fila][24],&MatrizDeTemperaturas[Fila][25],&MatrizDeTemperaturas[Fila][26],
																					&MatrizDeTemperaturas[Fila][27],&MatrizDeTemperaturas[Fila][28],&MatrizDeTemperaturas[Fila][29],&MatrizDeTemperaturas[Fila][30]
																					) != EOF ;Fila++);
}
	
void ImprimirMatrizDeArchivosNumericos(int MatrizDeTemperaturas[F][C]){
	
	int Fila,Columna;
	
	for(Fila = 0 ; Fila<F && MatrizDeTemperaturas[Fila][0] != EOF; Fila++){
		for(Columna = 0 ; Columna<C && MatrizDeTemperaturas[Fila][Columna] != EOF ; Columna++){
			printf("%d ",MatrizDeTemperaturas[Fila][Columna]);
			
		}
		printf("\n");
	}
}

int CantidadDeDiasTotales(int MatrizDeDiasMedidos[F][C], char NombreDeArchivo[]){
	
	int CantidadTotalesDeDias = 0;
	
	FILE *Archivo;
	Archivo = fopen("diasMedidos.txt","r");
	
	int Fila;
	
	for(Fila = 0 ; Fila<F && fscanf(Archivo,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",	&MatrizDeDiasMedidos[Fila][0],&MatrizDeDiasMedidos[Fila][1],&MatrizDeDiasMedidos[Fila][2],
																					&MatrizDeDiasMedidos[Fila][3],&MatrizDeDiasMedidos[Fila][4],&MatrizDeDiasMedidos[Fila][5],
																					&MatrizDeDiasMedidos[Fila][6],&MatrizDeDiasMedidos[Fila][7],&MatrizDeDiasMedidos[Fila][8],
																					&MatrizDeDiasMedidos[Fila][9],&MatrizDeDiasMedidos[Fila][10],&MatrizDeDiasMedidos[Fila][11]) != EOF ; Fila++);
	
	CantidadTotalesDeDias = 	MatrizDeDiasMedidos[0][0] + MatrizDeDiasMedidos[0][1] + MatrizDeDiasMedidos[0][2] + MatrizDeDiasMedidos[0][3] + MatrizDeDiasMedidos[0][4] + MatrizDeDiasMedidos[0][5] +
		
	MatrizDeDiasMedidos[0][6] + MatrizDeDiasMedidos[0][7] + MatrizDeDiasMedidos[0][8] + MatrizDeDiasMedidos[0][9] + MatrizDeDiasMedidos[0][10] + MatrizDeDiasMedidos[0][11];
	
	
	return CantidadTotalesDeDias;
}
	
void ValorMinimoMaximoyPromedio(int MatrizDeTemperaturas[F][C]){
	
	int Minimo = 999;
	int Maximo = 0;
	float Promedio;
	float Suma = 0;
	float CantidadTotalesDeDias = 0;
	int MatrizDeDiasMedidos[F][C] = {0};
	
	
	// Primero, saco la cantidad de dias que hay en el archivo diasMedidos.txt
	
	CantidadTotalesDeDias = CantidadDeDiasTotales(MatrizDeDiasMedidos,"diasMedidos.txt");

	// Calculo el maximo, minimo y el promedio.

	int Fila, Columna;
	
	for(Fila = 0 ; Fila<F && MatrizDeTemperaturas[Fila][0] != EOF ; Fila++){
		for(Columna = 0 ; Columna<C && MatrizDeTemperaturas[Fila][Columna] != EOF ; Columna++){
			Suma += MatrizDeTemperaturas[Fila][Columna];
			
			if(MatrizDeTemperaturas[Fila][Columna]>Maximo){
				Maximo = MatrizDeTemperaturas[Fila][Columna];
			}
			if(MatrizDeTemperaturas[Fila][Columna]<Minimo){
				Minimo = MatrizDeTemperaturas[Fila][Columna];
			}
		}
	}
	
	Promedio = Suma/CantidadTotalesDeDias;
	
	printf("\nLa temperatura anual maxima es: %d °C.",Maximo);
	printf("\nLa temperatura anual minima es: %d °C.",Minimo);
	printf("\nEl promedio anual es de: %.1f °C",Promedio);
	printf("\nLos dias totales calculados son: %.0f dias.",CantidadTotalesDeDias);
}

void ValorPromedioDeTemperaturaMensual(int MatrizDeTemperaturas[F][C], int MatrizDeDiasMedidos[F][C]){
	
	int Fila,Columna;
	float Promedio;
	float Minimo = 999;
	float Maximo = 0;
	int SumaDeDias = 0; 
	float DiasMensuales;
	char NombreDeMesMaximo[20] = {0};
	char NombreDeMesMinimo[20] = {0};
	
	for(Fila = 0 ; Fila<F && MatrizDeTemperaturas[Fila][0] != EOF ; Fila++){
		DiasMensuales = MatrizDeDiasMedidos[0][Fila];
		for(Columna = 0 ; Columna<C && MatrizDeTemperaturas[F][C] != EOF; Columna++){
			SumaDeDias += MatrizDeTemperaturas[Fila][Columna];
	}
		
		Promedio = SumaDeDias / DiasMensuales;
			
		if(Fila == 0){
			printf("\n\nPromedio de Enero: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Enero");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Enero");
			}
		}
		if(Fila == 1){
			printf("\nPromedio de Febrero: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Febrero");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Febrero");
			}
			
		}
		
		if(Fila == 2){
			printf("\nPromedio de Marzo: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Marzo");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Marzo");
			}
		}

		if(Fila == 3){
			printf("\nPromedio de Abril: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Abril");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Abril");
			}
			
		}
		
		if(Fila == 4){
			printf("\nPromedio de Mayo: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Mayo");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Mayo");
			}
			
		}
		if(Fila == 5){
			printf("\nPromedio de Junio: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Junio");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Junio");
			}
			
		}
		
		if(Fila == 6){
			printf("\nPromedio de Julio: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Julio");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Julio");
			}
			
		}
		
		if(Fila == 7){
			printf("\nPromedio de Agosto: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Agosto");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Agosto");
			}
			
		}
		
		if(Fila == 8){
			printf("\nPromedio de Septiembre: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Septiembre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Septiembre");
			}
			
		}
		
		if(Fila == 9){
			printf("\nPromedio de Octubre: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Octubre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Octubre");
			}
			
		}
		if(Fila == 10){
			printf("\nPromedio de Noviembre: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Noviembre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Noviembre");
			}
			
		}
		
		if(Fila == 11){
			printf("\nPromedio de Diciembre: %.1f°C",Promedio);
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(NombreDeMesMaximo,"Diciembre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(NombreDeMesMinimo,"Diciembre");
			}
			
		}
		
		SumaDeDias = 0;
	
		}
	printf("\n\nLa temperatura promedio maxima es de: %.1lf°C y corresponde al mes de %s.",Maximo,NombreDeMesMaximo);
	printf("\nLa temperatura promedio minima es de: %.1lf°C y corresponde al mes de %s.",Minimo,NombreDeMesMinimo);
	}

