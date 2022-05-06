#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 12
#define C 31


void CargarMatriz(int Matriz[F][C], char NombreDeArchivo[]);
void ImprimirMatrizDeNumeros(int Matriz[F][C]);
void TemperaturaMinimayMaxima(int Matriz[F][C]);
void PromedioAnual(int Matriz[F][C]);
void PromedioMensual(int Matriz[F][C]);
void CantidadTotalDeDias(int Matriz[F][C], char NombreDeArchivo[]);


int main(){
	
	int MatrizDeTemperaturas[F][C] = {0};
	int MatrizDeDiasTotales[F][C] = {0};
	CargarMatriz(MatrizDeTemperaturas,"temperaturas.txt");
	ImprimirMatrizDeNumeros(MatrizDeTemperaturas);
	printf("\n");
	TemperaturaMinimayMaxima(MatrizDeTemperaturas);
	printf("\n");
	PromedioAnual(MatrizDeTemperaturas);
	PromedioMensual(MatrizDeTemperaturas);
	CantidadTotalDeDias(MatrizDeDiasTotales, "diasMedidos.txt");
	return 0;
}

void CargarMatriz(int Matriz[F][C], char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila;
	
	for(Fila = 0 ; fscanf(Archivo, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
						&Matriz[Fila][0],&Matriz[Fila][1],&Matriz[Fila][2],&Matriz[Fila][3],
						&Matriz[Fila][4],&Matriz[Fila][5],&Matriz[Fila][6],&Matriz[Fila][7],
						&Matriz[Fila][8],&Matriz[Fila][9],&Matriz[Fila][10],&Matriz[Fila][11],
						&Matriz[Fila][12],&Matriz[Fila][13],&Matriz[Fila][14],&Matriz[Fila][15],
						&Matriz[Fila][16],&Matriz[Fila][17],&Matriz[Fila][18],&Matriz[Fila][19],
						&Matriz[Fila][20],&Matriz[Fila][21],&Matriz[Fila][22],&Matriz[Fila][23],
						&Matriz[Fila][24],&Matriz[Fila][25],&Matriz[Fila][26],&Matriz[Fila][27],
						&Matriz[Fila][28],&Matriz[Fila][29],&Matriz[Fila][30]) != EOF && Fila<F ; Fila++);
	
	fclose(Archivo);
}

void ImprimirMatrizDeNumeros(int Matriz[F][C]){
	
	int Fila, Columna;
		
	for(Fila = 0 ; Fila<F && Matriz[Fila][0] != EOF ; Fila++){
		for(Columna = 0 ; Columna<C && Matriz[Fila][Columna] != EOF; Columna++){
			printf("%d\t",Matriz[Fila][Columna]);
		}
		printf("\n\n\n");
	}	
}
	
void TemperaturaMinimayMaxima(int Matriz[F][C]){
	
	int Minima = Matriz[0][0];
	int Maxima = Matriz[0][0];
	
	int Fila, Columna;
	
	for(Fila = 0 ; Fila<F ; Fila++){
		for(Columna = 0 ; Columna<C ; Columna++){
			if(Matriz[Fila][Columna]>Maxima){
				Maxima = Matriz[Fila][Columna];
			}
			if(Matriz[Fila][Columna]<Minima){
				Minima = Matriz[Fila][Columna];
			}
		}
	}
	
	printf("La temperatura maxima anual es: %d\nLa temperatura minima anual es: %d",Maxima,Minima);
}
	
void PromedioAnual(int Matriz[F][C]){
	
	float Promedio;
	int Suma = 0;
	int Contador = 0;
	
	int Fila, Columna;
	
	for(Fila = 0 ; Fila<F ; Fila++){
		for(Columna = 0 ; Columna<C ; Columna++){
			Suma += Matriz[Fila][Columna];
			Contador++;
		}
	}
	
	Promedio = Suma/Contador; 
	
	printf("El promedio anual es: %.2f",Promedio);
}
	
void PromedioMensual(int Matriz[F][C]){
	
	char MesCaluroso[20] = {0};
	char MesFrio[20] = {0};
	
	
	float Maximo = 0;
	float Minimo = 100;
	
	float Promedio;
	
	int Fila, Columna;
	
	for(Fila = 0 ; Fila<F ; Fila++){
		int Cantidad = 0;
		int Suma = 0;
		for(Columna = 0 ; Columna<C ; Columna++){
			Suma += Matriz[Fila][Columna];
			Cantidad++;
		}
		
		Promedio = Suma/Cantidad;
		
		if(Fila == 0){
			printf("\n\nEnero: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Enero");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Enero");
			}
		}
		if(Fila == 1){
			printf("Febrero: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Febrero");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Febrero");
			}
		}
		if(Fila == 2){
			printf("Marzo: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Marzo");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Marzo");
			}
		}	
		if(Fila == 3){
			printf("Abril: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Abril");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Abril");
			}
		}	
		if(Fila == 4){
			printf("Mayo: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Mayo");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Mayo");
			}
		}	
		if(Fila == 5){
			printf("Junio: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Junio");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Junio");
			}
		}	
		if(Fila == 6){
			printf("Julio: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Julio");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Julio");
			}
		}	
		if(Fila == 7){
			printf("Agosto: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Agosto");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Agosto");
			}
		}
		if(Fila == 8){
			printf("Septiembre: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Septiembre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Septiembre");
			}
		}
		if(Fila == 9){
			printf("Octubre: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Octubre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Octubre");
			}
		}
		if(Fila == 10){
			printf("Noviembre: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Noviembre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Noviembre");
			}
		}	
		if(Fila == 11){
			printf("Diciembre: %.2f\n",Promedio);
			
			if(Promedio>Maximo){
				Maximo = Promedio;
				strcpy(MesCaluroso,"Diciembre");
			}
			if(Promedio<Minimo){
				Minimo = Promedio;
				strcpy(MesFrio,"Diciembre");
			}
		}
	}


	

	printf("\nEl mes mas caluroso es: %s. Con un promedio de %.2f",MesCaluroso,Maximo);
	printf("\nEl mes mas frio es: %s. Con un promedio de %.2f",MesFrio,Minimo);
}

void CantidadTotalDeDias(int Matriz[F][C], char NombreDeArchivo[]){
	
	FILE *Archivo;
	Archivo = fopen(NombreDeArchivo,"r");
	
	int Fila,Columna;
	int Suma = 0;
	
	for(Fila = 0 ; Fila<F && fscanf(Archivo,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",	&Matriz[Fila][0],&Matriz[Fila][1],&Matriz[Fila][2],
																					&Matriz[Fila][3],&Matriz[Fila][4],&Matriz[Fila][5],
																					&Matriz[Fila][6],&Matriz[Fila][7],&Matriz[Fila][8],	
																					&Matriz[Fila][9],&Matriz[Fila][10],&Matriz[Fila][11]) != EOF ; Fila++);
	
	for(Fila = 0 ; Fila<F && Matriz[F][0] != EOF ; Fila++){
		for(Columna = 0 ; Columna<C ; Columna++){
			Suma += Matriz[Fila][Columna];
		}
	}
	
	printf("\n\nLos dias totales calculados son: %d",Suma);
	
	
}
