#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define F 10
#define C 10


void CargarMatrizDeTexto(char Matriz[F][C]);
void ImprimirMatrizDeTexto(char Matriz[F][C]);
void OrdenarMatrizDeTexto(char Matriz[F][C]);

int main() {

	char Matriz[F][C] = {0};
	printf("Ingresar matriz: \n\n");
	
	CargarMatrizDeTexto(Matriz);
	printf("La matriz impresa es: \n\n");
	ImprimirMatrizDeTexto(Matriz);
	printf("La matriz ordenada es: \n\n");
	OrdenarMatrizDeTexto(Matriz);
	ImprimirMatrizDeTexto(Matriz);
	
	return 0;
}

void CargarMatrizDeTexto(char Matriz[F][C]){
	
	int f, c;
	char Caracter;
	Caracter = getche();
	
	
	for(f=0;f<F && Caracter != '\r';f++){
		for(c=0;c<C && Caracter != '\r';c++){
			Matriz[f][c] = Caracter;
			Caracter = getche();
		}
		Matriz[f][c] = '\0';
		printf("\n");
		Caracter = getche();
	}
	Matriz[f][c] = '\0';
}

void ImprimirMatrizDeTexto(char Matriz[F][C]){
	
	int f, c;
	
	for(f=0; f<F && Matriz[f][0] != '\0'; f++){
		for(c=0; c<C && Matriz[f][c] != '\0'; c++){
			printf("%c",Matriz[f][c]);
		}
		printf("\n");
	}	
}
	
void OrdenarMatrizDeTexto(char Matriz[F][C]){
	
	char Auxiliar[C];
	int f = 0, c = 0;
	
	for(f=0;f<F && Matriz[f][0] != '\0'; f++){
		for(c = f+1; c<C && Matriz[c][0] != '\0'; c++){
			
			if(strcmp(Matriz[f],Matriz[c])>0){
				
				strcpy(Auxiliar,Matriz[f]);
				strcpy(Matriz[f],Matriz[c]);
				strcpy(Matriz[c],Auxiliar);
			}
		}
	}
}
