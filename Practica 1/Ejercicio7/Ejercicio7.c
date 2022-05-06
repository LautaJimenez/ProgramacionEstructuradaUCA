#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 4
#define C 4

int IngresarValor(int f, int c);
void CargarMatriz(int Matriz[F][C]);
void ImprimirMatriz(int Matriz[F][C]);
double PromedioDeMatriz(int Matriz[F][C]);


int main() {
	
	int Matriz[F][C] = {0};
	
	CargarMatriz(Matriz);
	ImprimirMatriz(Matriz);
	printf("El promedio de la matriz es: %lf",PromedioDeMatriz(Matriz));
	
	
	return 0;
}

int IngresarValor(int f, int c){
	
	int Valor;
	
	printf("[%d] [%d]: ",f,c);
	scanf("%d",&Valor);
	return Valor;
	
}

void CargarMatriz(int Matriz[F][C]){
	
	int f = 0;
	int c = 0;
	
	for(f = 0; f<F; f++){
		for(c = 0; c<C; c++){
			Matriz[f][c] = IngresarValor(f,c);
		}
	}
	
}

void ImprimirMatriz(int Matriz[F][C]){
	
	int f,c;
	
	for(f=0;f<F;f++){
		for(c=0;c<C;c++){
			printf("%4d",Matriz[f][c]);
			if(c<C-1){
				printf(" | ");
			}
		}
		printf("\n");
	}

}
	
double PromedioDeMatriz(int Matriz[F][C]){
	
	int f,c;
	int Suma = 0;
	double Promedio;
	
	
	for(f=0;f<F;f++){
		for(c=0;c<C;c++){
			Suma += Matriz[f][c];
		}
	}
	
	Promedio = (Suma) / (F*C);
	return Promedio;
	
}
