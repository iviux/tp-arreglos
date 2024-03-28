#include "array.h"

void salir(int *q)
{
    printf("\nPresione una tecla para continuar, q para salir.");
    fflush(stdin);
    *q = getch();

    system("cls");
}

int tam()
{
    int t;
    printf("Ingrese el tamaño de su arreglo: ");
    scanf("%d", &t);
    printf("\n");
    return t;
}

void nuevoArreglo (Arreglo *a)
{
    printf("Que tipo de arreglo se va a usar? (c, i, f, r)\n");
    fflush(stdin);
    a->tipo = getch();

    while(a->tipo != 'c' && a->tipo != 'i' && a->tipo != 'f' && a->tipo != 'r')
    {
        printf("Valor incorrecto, que tipo de arreglo se va a usar? (c, i, f, r)");
        fflush(stdin);
        a->tipo = getch();
    }

    a->V =(int *)malloc(50*sizeof(int));
    a->T = tam();
    a->V =(int *)realloc(a->V, a->T*sizeof(int));
    free(a->V);
    cargarArreglo(a);

}

void cargarArreglo(Arreglo *a)
{
    if (a->tipo == 'c')
    {
        for (int i = 0; i < a->T; i++)
        {
            printf("Ingrese un numero entero: ");
            scanf("%d", &a->C[i]);
        }
        a->C[i + 1] = 0;
    }
    else if (a->tipo == 'i')
    {
        for (int i = 0; i < a->T; i++)
        {
            printf("Ingrese un numero entero: ");
            scanf("%d", &a->V[i]);
        }
    }
    else if (a->tipo == 'f')
    {
        for (int i = 0; i < a->T; i++)
        {
            printf("Ingrese un numero entero: ");
            scanf("%d", &a->F[i]);
        }
    }
    else if (a->tipo == 'r')
    {
        srand(time(NULL));

        for (int i = 0; i < a->T; i++)
        {
            a->F[i] =(double) rand() / RAND_MAX * 10;
        }
    }

    printf("\nEl arreglo fue cargado con %d elementos.\n", a->T);
}

void mostrarArreglo(Arreglo *a)
{
    if (a->tipo == 'c')
    {
        for (int i = 0; i < a->T; i++)
        {
            printf("%c", a->C[i]);
        }
        printf("\n\n");
    }
    else if (a->tipo == 'i')
    {
        for (int i = 0; i < a->T; i++)
        {
            printf("| %d ", a->V[i]);
        }
        printf("\n\n");
    }
    else
    {
        for (int i = 0; i < a->T; i++)
        {
            printf("| %.2f ", a->F[i]);
        }
        printf("\n\n");
    }
}

void sumarArreglo(Arreglo *a)
{
    int suma = 0;

    if (a->tipo == 'c')
    {

    }

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
