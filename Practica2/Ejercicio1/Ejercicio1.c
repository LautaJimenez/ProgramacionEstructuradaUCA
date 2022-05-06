#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h> 


struct s_punto
{
	int a;
	int b;
};

typedef struct s_punto t_punto;

void CargarEstructuras(t_punto punto);
void MedirDistancia(t_punto punto1,t_punto punto2);

int main(){
	
	t_punto punto1;
	t_punto punto2;
	
	printf("\nIngrese la primer coordenada del primer punto: ");
	scanf("%d",&punto1.a);
	printf("\nIngrese la segunda coordenada del primer punto: ");
	scanf("%d",&punto1.b);
	
	printf("\nIngrese la primer coordenada del segundo punto: ");
	scanf("%d",&punto2.a);
	printf("\nIngrese la segunda coordenada del segundo punto: ");
	scanf("%d",&punto2.b);
	
	MedirDistancia(punto1,punto2);
	
	return 0;
}

	
void MedirDistancia(t_punto punto1,t_punto punto2){
	
	double ResultadoDePunto1;
	double ResultadoDePunto2;
	
	int x1,y1,x2,y2;
	
	x1 = punto1.a;
	y1 = punto1.b;
	x2 = punto2.a;
	y2 = punto2.b;
	
	ResultadoDePunto1 = sqrt(pow(x1,2)+pow(y1,2));
	ResultadoDePunto2 = sqrt(pow(x2,2)+pow(y2,2));
	
	if(ResultadoDePunto1>ResultadoDePunto2){
		printf("\nEl punto más lejano es el punto 1 -> (%d ; %d)",punto1.a,punto1.b);
	}else{
		printf("\nEl punto más lejano es el punto 2 -> (%d ; %d)",punto2.a,punto2.b);
	}
	
	
	
	
	
	
}
