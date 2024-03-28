#include <stdio.h>
#include <stdlib.h>
#define Arreglo struct _Arreglo
#include "pila.h"

struct _Arreglo
{
    char tipo;
    int T;
    char *C;
    int *V;
    float *F;
};

void salir(char *q);
void nuevoArreglo (Arreglo *a);
void cargarArreglo(Arreglo *a);
int tam();
void mostrarArreglo(Arreglo *a);
void sumarArreglo(Arreglo *a);
void arregloAPila(Arreglo *a, Pila *p);
void buscar(Arreglo *a);

