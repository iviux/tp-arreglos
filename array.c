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
    printf("Que tipo de arreglo se va a usar? (c, i, f)\n");
    fflush(stdin);
    a->tipo = getch();

    while(a->tipo != 'c' && a->tipo != 'i' && a->tipo != 'f')
    {
        printf("Valor incorrecto, que tipo de arreglo se va a usar? (c, i, f)");
        fflush(stdin);
        a->tipo = getch();
    }

    a->V =(int *)malloc(50*sizeof(int));
    a->T = tam();
    a->V =(int *)realloc(a->V, a->T*sizeof(int));
    free(a->V);

    if (a->tipo == 'i')
    {
        cargarArreglo(a->V, a->T);
    }
    else if (r == 'c')
    {
        cargarArregloC(a->C, a->T);
    }
    else if (r == 'f')
    {
        cargarArregloF(a->F, a->T);
    }
}


void cargarArreglo(int *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("Ingrese un numero entero: ");
        scanf("%d", &a[i]);
    }
    printf("\nEl arreglo fue cargado con %d elementos.\n", t);

}

void cargarArregloC(char *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("Ingrese un caracter: ");
        scanf("%c", &a[i]);
    }
    printf("\nEl arreglo fue cargado con %d elementos.\n", t);

}

void cargarArregloF(float *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("Ingrese un float: ");
        scanf("%f", &a[i]);
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
    printf("\n");
    return t;
}

void mostrarArreglo(Arreglo *a)
{
    for (int i = 0; i < a->T; i++)
    {
        printf("| %d ", a->V[i]);
    }
    printf("\n\n");
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

void buscar(Arreglo *a)
{
    int n = 0;
    int flag = 0;

    printf("Que elemento desea buscar en el arreglo? ");
    scanf("%d",&n);

    for (int i = 0; i < a->T; i++)
    {
        if (a->V[i] == n)
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("\nEl elemento %d no se encuentra en el arreglo.", n);
    }
    else
    {
        printf("\nEl elemento %d se encuentra en el arreglo.", n);
    }
}
