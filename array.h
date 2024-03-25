#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void salir(int *q);
void cargarArray(int *a, int t);
void cargarArrayRan(float *a, int t);
int tam();
void mostrarArray(int *a, int t);
void sumarArray(int *a, int t);
void sumarArrayFloat(float *a, int t);
void arrayAPila(int *a, int t, P_Pila p);

#endif // ARRAY_H_INCLUDED
