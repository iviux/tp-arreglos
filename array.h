#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define Arreglo struct _Arreglo
#include "pila.h"

struct _Arreglo
{
    int T;
    int *V;
};

void salir(int *q);
void nuevoArreglo (Arreglo *a);
void cargarArreglo(int *a, int t);
void cargarArrayRan(float *a, int t);
int tam();
void mostrarArreglo(Arreglo *a);
void sumarArreglo(Arreglo *a);
void sumarArrayFloat(float *a, int t);
void arregloAPila(Arreglo *a, Pila *p);
void buscar(Arreglo *a, int n);

#endif // ARRAY_H_INCLUDED
