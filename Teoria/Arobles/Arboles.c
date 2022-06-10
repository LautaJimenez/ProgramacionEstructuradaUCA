#include <stdio.h>
#include <stdlib.h>

// Un arbol es una estructura de datos, que tiene un ordenamiento jerarquico. Tiene un nodo raiz que despues se divide en 2 nodos hijos (Como un arbol genealogico). Por lo tanto, el nodo tiene 3 partes.

// Las 3 partes del nodo son: El contenido, el puntero a izquierda, y el puntero a derecha.

// Los valores de los nodos nunca se repiten.

//________________________________________________________________________________________________________________________________________________________

// Nodo de un arbol:

struct s_nodo_bin
{
    struct s_nodo_bin* izquierda;
    int valor;
    struct s_nodo_bin* derecha;
};
typedef struct s_nodo_bin* t_nodo_bin;

//________________________________________________________________________________________________________________________________________________________

int main(){

    

    return 0;
}