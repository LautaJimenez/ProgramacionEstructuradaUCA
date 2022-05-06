#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

struct s_carta
{
    int Numero,Valor;
    char Palo;
};

typedef struct s_carta t_carta;

void OrdenarCartas(t_carta *PunteroCarta1,t_carta *PunteroCarta2,t_carta *PunteroCarta3){

    t_carta CartaAuxiliar;

    if((*PunteroCarta1).Valor < (*PunteroCarta2).Valor){
        CartaAuxiliar = *PunteroCarta1;
        *PunteroCarta1 = *PunteroCarta2;
        *PunteroCarta2 = CartaAuxiliar;
    }

    if((*PunteroCarta1).Valor < (*PunteroCarta3).Valor){
        CartaAuxiliar = *PunteroCarta1;
        *PunteroCarta1 = *PunteroCarta3;
        *PunteroCarta3 = CartaAuxiliar;
    }

    if((*PunteroCarta2).Valor < (*PunteroCarta3).Valor){
        CartaAuxiliar = *PunteroCarta2;
        *PunteroCarta2 = *PunteroCarta3;
        *PunteroCarta3 = CartaAuxiliar;
    }
}

int main(){

    t_carta Carta1, Carta2, Carta3;

    Carta1.Numero = 6;
    Carta1.Valor = 3;
    Carta1.Palo = 'B';

    Carta2.Numero = 7;
    Carta2.Valor = 10;
    Carta2.Palo = 'E';

    Carta3.Numero = 3;
    Carta3.Valor = 9;
    Carta3.Palo = 'C';

    printf("Cartas sin ordenar: \n\n");
    printf("Numero: %d. Valor: %d. Palo: %c\n",Carta1.Numero,Carta1.Valor,Carta1.Palo);
    printf("Numero: %d. Valor: %d. Palo: %c\n",Carta2.Numero,Carta2.Valor,Carta2.Palo);
    printf("Numero: %d. Valor: %d. Palo: %c\n",Carta3.Numero,Carta3.Valor,Carta3.Palo);

    OrdenarCartas(&Carta1,&Carta2,&Carta3);

    printf("\nCartas ordenadas: \n\n");
    printf("Numero: %d. Valor: %d. Palo: %c\n",Carta1.Numero,Carta1.Valor,Carta1.Palo);
    printf("Numero: %d. Valor: %d. Palo: %c\n",Carta2.Numero,Carta2.Valor,Carta2.Palo);
    printf("Numero: %d. Valor: %d. Palo: %c\n",Carta3.Numero,Carta3.Valor,Carta3.Palo);
    return 0;
}

