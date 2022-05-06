#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int operacion(double numero1, double numero2, char simbolo);

int main() {
	
	double Numero1;
	double Numero2;
	char Simbolo;
	
	printf("Ingrese el primer número: ");
	scanf("%lf",&Numero1);
	printf("Ingrese el segundo número: ");
	scanf("%lf",&Numero2);
	printf("Ingrese una operación [ + - / * ]: ");
	fflush(stdin); //Limpio el archivo stdin.
	Simbolo = getchar();
	operacion(Numero1,Numero2,Simbolo);
	
	return 0;
}

int operacion(double Numero1,double Numero2,char Simbolo){
	
	double resultado;
	
	if(Simbolo == '+'){
		resultado = Numero1 + Numero2;
	}
	if(Simbolo == '-'){
		resultado = Numero1 - Numero2;
	}
	if(Simbolo == '*'){
		resultado = Numero1 * Numero2;
	}
	if(Simbolo == '/'){
		resultado = Numero1 / Numero2;
	}
	
	return	printf("\n\n%.2lf %c %.2lf = %.2lf",Numero1,Simbolo,Numero2,resultado);
	
	
}

