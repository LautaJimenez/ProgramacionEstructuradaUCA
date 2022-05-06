#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define NA 5
#define NM 10
#define ENTER '\r'

typedef struct
{
    char Nombre[100];
    int Legajo, Materias[30];
} t_alumno;

typedef struct
{
    char Nombre[100];
    int Codigo;
} t_materia;

typedef struct
{
    int LegajoAlumno;
    int CodigoMateria,Nota;
} t_nota;

// 1)

void CargarAlumnosEnEstructura(t_alumno Alumno[NA]){

    int NumeroDeLegajo , CodigoMateria , i, j;
    char NombreAlumno[30] = {0};
    char Caracter;
    int Letra;

    printf("\nIngrese numero de legajo o 0 para terminar: ");
    scanf("%d",&NumeroDeLegajo);   

    for(i = 0 ; NumeroDeLegajo != 0 && i<NA ; i++){
        
        Alumno[i].Legajo = NumeroDeLegajo;

        printf("\n\nIngrese nombre del alumno: ");
        
        Caracter = getche();
        Letra = 0; 

        while(Caracter != ENTER){
            NombreAlumno[Letra] = Caracter;
            Letra++;
            Caracter = getche();
            
        }
        NombreAlumno[Letra] = '\0';

        strcpy(Alumno[i].Nombre,NombreAlumno);

        printf("\n\nIngrese codigo de la materia o '-1' para no cargar mas: ");
        scanf("%d",&CodigoMateria);

        for(j = 0 ; CodigoMateria != -1 && j<30; j++){
            Alumno[i].Materias[j] = CodigoMateria;
            printf("\n\nIngrese codigo de la materia o '-1' para no cargar mas: ");
            scanf("%d",&CodigoMateria);
        }
        Alumno[i].Materias[j] = -1;

        printf("\n\nIngrese numero de legajo o 0 para terminar: ");
        scanf("%d",&NumeroDeLegajo);
    }
    Alumno[i].Legajo = -1;
}

void CargarAlumnosEnArchivo(char NombreArchivo[]){

    t_alumno Alumno[NA];

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"a");

    CargarAlumnosEnEstructura(Alumno);

    for(int i = 0 ; Alumno[i].Legajo != -1 && i<NA ; i++){
        fprintf(Archivo,"%d,%s,",Alumno[i].Legajo,Alumno[i].Nombre);
        for(int j = 0 ; Alumno[i].Materias[j] != -1 ; j++){
            if(Alumno[i].Materias[j+1] == -1){
                fprintf(Archivo,"%d\n",Alumno[i].Materias[j]);
            }
            else{fprintf(Archivo,"%d,",Alumno[i].Materias[j]);}
        }    
    }

    fclose(Archivo);
}

// 2)

void CargarMateriasEnEstructura(t_materia Materias[NM]){

    char Caracter;
    char NombreMateria[100];
    int Letra, i, CodigoMateria;

    printf("\n\nIngrese el codigo de la materia: ");
    scanf("%d",&CodigoMateria);

    for(i = 0 ; CodigoMateria != 0 ; i++){
        Materias[i].Codigo = CodigoMateria;

        printf("\n\nIngrese el nombre de la materia: ");
        
        Caracter = getche();
        Letra = 0;

        while(Caracter != ENTER){
            NombreMateria[Letra] = Caracter;
            Caracter = getche();
            Letra++;
    }
    NombreMateria[Letra] = '\0';

    strcpy(Materias[i].Nombre,NombreMateria);
    
    printf("\n\nIngrese el codigo de la materia: ");
    scanf("%d",&CodigoMateria);

    }

    Materias[i].Codigo = -1;
}

void CargarMateriasEnArchivo(char NombreArchivo[]){

    t_materia Materias[NM];

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"a");

    CargarMateriasEnEstructura(Materias);

    for(int i = 0; Materias[i].Codigo != -1 ; i++){
        fprintf(Archivo,"%s,%d\n",Materias[i].Nombre,Materias[i].Codigo);
    }

    fclose(Archivo);

}

// 3)

void CargarAlumnosEnEstructuras(char NombreArchivo[], t_alumno Alumnos[NA]){

    FILE *Archivo;
    Archivo = fopen(NombreArchivo,"r");

    for(int i = 0 ; fscanf(Archivo,"%d,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                    &Alumnos[i].Legajo,&Alumnos[i].Nombre,&Alumnos[i].Materias[0],&Alumnos[i].Materias[1],&Alumnos[i].Materias[2],
                    &Alumnos[i].Materias[3],&Alumnos[i].Materias[4],&Alumnos[i].Materias[5],&Alumnos[i].Materias[6],
                    &Alumnos[i].Materias[7],&Alumnos[i].Materias[8],&Alumnos[i].Materias[9],&Alumnos[i].Materias[10],
                    &Alumnos[i].Materias[11],&Alumnos[i].Materias[12],&Alumnos[i].Materias[13],&Alumnos[i].Materias[14],
                    &Alumnos[i].Materias[15],&Alumnos[i].Materias[16],&Alumnos[i].Materias[17],&Alumnos[i].Materias[18],
                    &Alumnos[i].Materias[19],&Alumnos[i].Materias[20],&Alumnos[i].Materias[21],&Alumnos[i].Materias[22],
                    &Alumnos[i].Materias[23],&Alumnos[i].Materias[24],&Alumnos[i].Materias[25],&Alumnos[i].Materias[26],
                    &Alumnos[i].Materias[27],&Alumnos[i].Materias[28],&Alumnos[i].Materias[29]) != EOF && i<NA ; i++){  
    }

    for(int i = 0 ; Alumnos[i].Legajo != 0 ; i++){

        printf("\n%-20d %-20s %-20d",Alumnos[i].Legajo,Alumnos[i].Nombre,Alumnos[i].Materias);

    }
    fclose(Archivo);
}

int main(){

    //CargarAlumnosEnArchivo("alumnos.txt");
    
    //printf("\n\n");
    
    //CargarMateriasEnArchivo("materias.txt");   
    
    //Para el punto 3 y 4, hacer las mismas funciones, pero inversas -> Pasar de archivo a una estructura de alumnos y materias.
    
    t_alumno Alumnos[NA];

    CargarAlumnosEnEstructuras("alumnos.txt",Alumnos);

    return 0;
}
