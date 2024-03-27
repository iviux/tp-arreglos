#include "array.h"

void salir(int *q)
{
    printf("\nPresione una tecla para continuar, q para salir.");
    fflush(stdin);
    *q = getch();

    system("cls");
}

void nuevoArreglo (Arreglo *a)
{
    a->T = tam();
    a->V =(int *)malloc(a->T*sizeof(int));
    cargarArreglo(a->V, a->T);
}


void cargarArreglo(int *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("\nIngrese un numero entero: ");
        scanf("%d", &a[i]);
    }
    printf("\nEl arreglo fue cargado con %d elementos.\n", t);

}

void cargarArrayRan(float *a, int t)
{
    srand(time(NULL));

    for (int i = 0; i < t; i++)
    {
        a[i] =(double) rand() / RAND_MAX * 10;
        printf("| %.1f ", a[i]);
    }
    printf("\nEl arreglo fue cargado con %d elementos aleatorios.\n", t);

}

int tam()
{
    int t;
    printf("Ingrese el tamaño de su arreglo: ");
    scanf("%d", &t);
    return t;
}

void mostrarArreglo(Arreglo *a)
{
    for (int i = 0; i < a->T; i++)
    {
        printf("| %d ", a->V[i]);
    }
    printf("\n");
}

void sumarArreglo(Arreglo *a)
{
    int suma = 0;

    for (int i = 0; i < a->T; i++)
    {
        suma += a->V[i];
    }

    printf("\n\nLa suma de los elementos del arreglo es %d.", suma);
}

void sumarArrayFloat(float *a, int t)
{
    float suma = 0;

    for (int i = 0; i < t; i++)
    {
        suma += a[i];
    }

    printf("\n\nLa suma de los elementos del arreglo es %.2f.", suma);
}

void arregloAPila(Arreglo *a, Pila *p)
{
    for (int i = 0; i < a->T; i++)
    {
        apilar(p, a->V[i]);
    }
}

void buscar(Arreglo *a, int n)
{
    int flag = 0;

    for (int i = 0; i < a->T; i++)
    {
        if (a->V[i] == n)
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("El elemento %d no se encuentra en el arreglo.", n);
    }
    else
    {
        printf("El elemento %d se encuentra en el arreglo.", n);
    }
}
