#include <stdio.h>
#include <stdlib.h>
int operacion(float real);

int main(){
	float real;
	printf("Ingrese un número real: ");
	scanf("%f",&real);
	operacion(real);
	return 0;
}

int operacion(float numero){
	
	int a;
	int piso;
	int techo;
	
	a = numero;
	piso = numero;
	techo = numero+1;
	
	if(a-numero >= 0.5){
		a = a + 1;
	}
	
	if(a-numero < 0.5){
		a = a;
	}
	if(a-numero == 0){
		techo = a;
	}
	
	return printf("Redondeo: %d\nTecho: %d\nPiso: %d",a,techo,piso);
}
