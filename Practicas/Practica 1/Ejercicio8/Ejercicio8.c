#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 3
#define C 3

int IngresarValor(int f, int c);
void CargarMatriz(int Matriz[F][C]);
void ImprimirMatriz(int Matriz[F][C]);
void TransponerMatriz(int Matriz[F][C],	int MatrizAuxiliar[F][C]);

int main() {
	
	int Matriz[F][C] = {0};
	int MatrizAuxiliar[F][C] = {0};
	
	CargarMatriz(Matriz);
	printf("\n");
	ImprimirMatriz(Matriz);
	TransponerMatriz(Matriz,MatrizAuxiliar);
	printf("\n");
	ImprimirMatriz(MatrizAuxiliar);
	
	return 0;
}

int IngresarValor(int f, int c){
	
	int Valor;
	
	printf("[%d] [%d]: ",f,c);
	scanf("%d",&Valor);
	return Valor;
}


void CargarMatriz(int Matriz[F][C]){
	
	int f, c;
	
	for(f = 0; f<F; f++){
		for(c = 0; c<C; c++){
			Matriz[f][c] = IngresarValor(f,c);
		}
	}
}
	
void ImprimirMatriz(int Matriz[F][C]){
	
	int f, c;
	
	for(f=0;f<F;f++){
		for(c=0;c<C;c++){
			printf("%4d",Matriz[f][c]);
		}
		printf("\n");
	}
}

void TransponerMatriz(int Matriz[F][C],	int MatrizAuxiliar[F][C]){
	
	int f, c;
	
	for(f=0;f<F;f++){
		for(c=0;c<C;c++){
			MatrizAuxiliar[f][c] = Matriz[c][f];
		}
	}
	
	
}
