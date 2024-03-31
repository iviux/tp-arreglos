#include <stdio.h>
#include <stdlib.h>
#define Arreglo struct _Arreglo
#define INDEX a->N
#define TIPO a->tipo
#define TAM a->T
#include "pila.h"


struct _Arreglo
{
    char tipo;
    int N;
    int *T;
    char **C;
    int **V;
    float **F;
};

void salir(char *q);
void queArreglo(Arreglo *a);
void nuevoArreglo (Arreglo *a);
void cargarArreglo(Arreglo *a);
int tam();
void reasignMem(Arreglo *a);
void mostrarArreglo(Arreglo *a);
void sumarArreglo(Arreglo *a);
void arregloAPila(Arreglo *a, Pila *p);
void buscar(Arreglo *a);
void insertarArreglo(Arreglo *a);
void ordenarArreglo (Arreglo *a);
void buscarMayorArreglo(Arreglo *a);
void esCapicua(Arreglo *a);
void invertirArreglo(Arreglo *a);
