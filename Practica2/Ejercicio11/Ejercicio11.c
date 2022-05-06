#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MASCARA 0

void DevolverEnteroDeUnChar(unsigned char Caracter1, unsigned char Caracter2, unsigned char Caracter3, unsigned char Caracter4){

    int Resultado1, Resultado2, Resultado3, Resultado4;

    Resultado1 = Caracter1 | MASCARA;

    Resultado2 = Caracter2 | MASCARA;
    Resultado3 = Caracter3 | MASCARA;
    Resultado4 = Caracter4 | MASCARA;

    printf("%c: %d\n%c: %d\n%c: %d\n%c: %d\n",Caracter1,Resultado1,Caracter2,Resultado2,Caracter3,Resultado3,Caracter4,Resultado4);

}

int main(){

    DevolverEnteroDeUnChar('!','B','C','D');
    return 0;
}