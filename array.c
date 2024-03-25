#include "array.h"

void salir(int *q)
{
    printf("\nPresione una tecla para continuar, q para salir.");
    fflush(stdin);
    *q = getch();

    system("cls");
}



void cargarArray(int *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("\nIngrese un numero entero: ");
        scanf("%d", &a[i]);
        while (a[i] > 100000)
        {
            printf("El numero ingresado es demasiado grande. Ingrese un numero entero:");
            scanf("%d", &a[i]);
        }
        a[i + 1] = '1000000';
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

void mostrarArray(int *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("| %d ", a[i]);
    }
    printf("\n");
}

void sumarArray(int *a, int t)
{
    int suma = 0;

    for (int i = 0; i < t; i++)
    {
        suma += a[i];
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

void arrayAPila(int *a, int t, P_Pila p)
{
    for (int i = 0; i < t; i++)
    {
        apilar(p, a[i]);
    }
}

//void buscar(int *a, int t)
//{
//    int flag = 0;
//
//    for (int i = 0; i < t; i++)
//    {
//        if (a[i] == )
//    }
//}
