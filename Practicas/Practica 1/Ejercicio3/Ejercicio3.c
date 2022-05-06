#include <stdio.h>
#include <conio.h>

#define N 100

void leer(char Texto[N]);
void Reemplazar(char Texto[N], char AReemplazar, char DeReemplazo);



int main() {
	char Texto[N];
	char AReemplazar;
	char DeReemplazo;
	printf("Ingrese texto: ");
	leer(Texto);
	
	printf("\nIngrese caracter a reemplazar: ");
	AReemplazar = getche();
	printf("\nIngrese caracter de reemplazo: ");
	DeReemplazo = getche();
	Reemplazar(Texto,AReemplazar,DeReemplazo);
	printf("\nResultado: %s",Texto);
	return 0;
}

void leer(char Texto [N]){
	char Caracter;
	int i = 0;
	Caracter = getche();
	while(Caracter != '\r'){
		Texto[i] = Caracter;
		i ++;
		Caracter = getche();
		
	Texto[i] = '\0';
	}
}

void Reemplazar(char Texto[N], char AReemplazar, char DeReemplazo){
	int i;
	for(i=0;i<99;i++){
		if(Texto[i] == AReemplazar){
			Texto[i] = DeReemplazo;
		}
	}
}
