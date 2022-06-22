#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// En este ejercicio, se recibe un archivo csv, con informacion (DNI,Nombre,Apellido y fecha de Nacimiento), se carga en una lista, y se ordena segun la opcion elegida.

struct sFecha{
	
	int Dia, Mes, Anio;
};

typedef struct sFecha tFecha;

struct sContenido{
	
	int DNI;
	char *Nombre;
	char *Apellido;
	tFecha FechaDeNacimiento;
	
};

typedef struct sContenido tContenido;

struct sNodo{
	
	tContenido Contenido;
	struct sNodo *Siguiente;
	
};

typedef struct sNodo *tNodo;

// FUNCIONES DE CARGA

void LeerCadenaDeArchivo(FILE *Archivo, char **Cadena, char Separador){
	
	char Caracter;
	int i = 0;
	
	*(Cadena) = malloc(sizeof(char));
	
	if(!feof(Archivo)){
		Caracter = fgetc(Archivo);
	}
	
	while(Caracter != Separador && !feof(Archivo)){
		
		(*(Cadena))[i] = Caracter;
		i++;
		*(Cadena) = realloc(*(Cadena),sizeof(char) * (i+1));
		Caracter = fgetc(Archivo);
	}
	
	(*(Cadena))[i] = '\0';
	
}
	
void CargarALista(tNodo *Lista, tContenido Contenido){
	
	if(*Lista == NULL){
		*Lista = malloc(sizeof(struct sNodo));
		(*Lista)->Contenido = Contenido;
		(*Lista)->Siguiente = NULL;
	}
	else{
		CargarALista(&(*Lista)->Siguiente,Contenido);
	}
	
	
}


void CargarArchivoEnLista(tNodo *Lista, char *NombreArchivo){
		
	FILE *Archivo = fopen(NombreArchivo,"r");
	tContenido ContenidoAuxiliar = {0};
	int FechaAuxiliar;
	
	while(!feof(Archivo)){
		
		fscanf(Archivo,"%d,",&ContenidoAuxiliar.DNI);
		LeerCadenaDeArchivo(Archivo,&ContenidoAuxiliar.Apellido,',');
		LeerCadenaDeArchivo(Archivo,&ContenidoAuxiliar.Nombre,',');
		fscanf(Archivo,"%d\n",&FechaAuxiliar);
		
		ContenidoAuxiliar.FechaDeNacimiento.Dia = FechaAuxiliar%100;
		ContenidoAuxiliar.FechaDeNacimiento.Mes = (FechaAuxiliar/100)%100;
		ContenidoAuxiliar.FechaDeNacimiento.Anio = FechaAuxiliar/10000;
		
		CargarALista(Lista,ContenidoAuxiliar);
		
	}
}
	
	
// FUNCIONES DE ORDENAMIENTO
	
void OrdenarListaPorDNI(tNodo *ListaAuxiliar, tContenido Contenido, int Ordenamiento){
	
	tNodo Auxiliar = malloc(sizeof(struct sNodo));
	
	if(Ordenamiento == 1){ // Se ordena de manera ascendente
		
		if(*ListaAuxiliar == NULL || (*ListaAuxiliar)->Contenido.DNI > Contenido.DNI){
			
			Auxiliar->Contenido = Contenido;
			Auxiliar->Siguiente = *ListaAuxiliar;
			*ListaAuxiliar = Auxiliar;
			
		}
		
		else{
			OrdenarListaPorDNI(&(*ListaAuxiliar)->Siguiente,Contenido,Ordenamiento);
		}
	}
	
	if(Ordenamiento == 2){ // Se ordena de manera ascendente
		if(*ListaAuxiliar == NULL || (*ListaAuxiliar)->Contenido.DNI < Contenido.DNI){
			
			Auxiliar->Contenido = Contenido;
			Auxiliar->Siguiente = *ListaAuxiliar;
			*ListaAuxiliar = Auxiliar;
			
		}
		
		else{
			OrdenarListaPorDNI(&(*ListaAuxiliar)->Siguiente,Contenido,Ordenamiento);
		}
	}
}
	
void OrdenarListaPorNombre(tNodo *ListaAuxiliar,tContenido Contenido, int Ordenamiento){
	
	tNodo Auxiliar = malloc(sizeof(struct sNodo));
	
	if(Ordenamiento == 1){ // Se ordena de manera ascendente
		
		if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Nombre,Contenido.Nombre) > 0){
			
			Auxiliar->Contenido = Contenido;
			Auxiliar->Siguiente = *ListaAuxiliar;
			*ListaAuxiliar = Auxiliar;
		}
		else{
			OrdenarListaPorNombre(&(*ListaAuxiliar)->Siguiente,Contenido,Ordenamiento);
		}
		
	}
	
	if(Ordenamiento == 2){ // Se ordena de manera descendente
		
		if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Nombre,Contenido.Nombre) < 0){
			
			Auxiliar->Contenido = Contenido;
			Auxiliar->Siguiente = *ListaAuxiliar;
			*ListaAuxiliar = Auxiliar;
		}
		else{
			OrdenarListaPorNombre(&(*ListaAuxiliar)->Siguiente,Contenido,Ordenamiento);
		}
	}
}
	
void OrdenarListaPorApellido(tNodo *ListaAuxiliar, tContenido Contenido, int Ordenamiento){
	
	tNodo Auxiliar = malloc(sizeof(struct sNodo));
	
	if(Ordenamiento == 1){
			
		if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Apellido,Contenido.Apellido) > 0){
		
			Auxiliar->Contenido = Contenido;
			Auxiliar->Siguiente = *ListaAuxiliar;
			*ListaAuxiliar = Auxiliar;
		}
		else{
			OrdenarListaPorApellido(&(*ListaAuxiliar)->Siguiente,Contenido,Ordenamiento);
		}
	}
	
	if(Ordenamiento == 2){
		
		if(*ListaAuxiliar == NULL || strcmp((*ListaAuxiliar)->Contenido.Apellido,Contenido.Apellido) < 0){
			
			Auxiliar->Contenido = Contenido;
			Auxiliar->Siguiente = *ListaAuxiliar;
			*ListaAuxiliar = Auxiliar;
		}
		else{
			OrdenarListaPorApellido(&(*ListaAuxiliar)->Siguiente,Contenido,Ordenamiento);
		}
	}
	
	
}
	

void OrdenarLista(tNodo *Lista, int Opcion, int Ordenamiento){
	
	tNodo ListaAuxiliar = NULL;
	
	while(*Lista != NULL){
		
		if(Opcion == 1){
			OrdenarListaPorDNI(&ListaAuxiliar,(*Lista)->Contenido,Ordenamiento);
			*Lista = (*Lista)->Siguiente;
		}
		
		if(Opcion == 2){
			OrdenarListaPorNombre(&ListaAuxiliar,(*Lista)->Contenido,Ordenamiento);
			*Lista = (*Lista)->Siguiente;
			
		}
		
		if(Opcion == 3){
			OrdenarListaPorApellido(&ListaAuxiliar,(*Lista)->Contenido,Ordenamiento);
			*Lista = (*Lista)->Siguiente;
			}
		}
	
	*Lista = ListaAuxiliar;
}
	
	
// FUNCIONES DE IMPRESION
	
void ImprimirCabeceras(){
	
	printf("%-10s %-20s %-20s %-5s %-5s %-5s\n\n","DNI","Nombre","Apellido","Dia","Mes","Anio");
	
}
	
	
void ImprimirLista(tNodo Lista){
	
	if(Lista != NULL){
		
		printf("%-10d %-20s %-20s %-5d %-5d %-5d\n",Lista->Contenido.DNI,Lista->Contenido.Nombre,Lista->Contenido.Apellido,Lista->Contenido.FechaDeNacimiento.Dia,Lista->Contenido.FechaDeNacimiento.Mes,Lista->Contenido.FechaDeNacimiento.Anio);
		ImprimirLista(Lista->Siguiente);
	}
}


int main(){
	
	tNodo Lista = NULL;
	CargarArchivoEnLista(&Lista,"Informacion.txt");
	ImprimirCabeceras();
	ImprimirLista(Lista);
	
	int Opcion, Ordenamiento;
	
	printf("\nIngrese que campo desea ordenar:\n\n1: DNI\n2: Nombre\n3: Apellido\n\nOpcion: ");
	scanf("%d",&Opcion);
	
	printf("\nIngrese si desea ordenar ascendente o descendente:\n\n1: Ascendente\n2: Descdencende\n\nOpcion: ");
	scanf("%d",&Ordenamiento);
	
	OrdenarLista(&Lista,Opcion,Ordenamiento);
	
	printf("\n");
	
	ImprimirLista(Lista);

	
	
	return 0;
}
