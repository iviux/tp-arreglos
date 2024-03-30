#include "array.h"

void salir(char *q)
{
    printf("\nPresione una tecla para continuar editando el arreglo, q para salir.");
    fflush(stdin);
    *q = getch();

    system("cls");
}

void queArreglo(Arreglo *a)
{
    printf("Ingrese el numero de arreglo que desea crear o modificar: ");
    scanf("%d", &(a->N));
    a->N = a->N - 1;
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
    a->C =(char **)malloc(50*sizeof(char));
    a->V =(int **)malloc(50*sizeof(int));
    a->F =(float **)malloc(50*sizeof(float));

    printf("Que tipo de arreglo se va a usar? (c, i, f, r)\n");
    fflush(stdin);
    a->tipo = getch();

    while(a->tipo != 'c' && a->tipo != 'i' && a->tipo != 'f' && a->tipo != 'r')
    {
        printf("\033[F\033[K");
        printf("Valor incorrecto, que tipo de arreglo se va a usar? (c, i, f, r)\n");
        fflush(stdin);
        a->tipo = getch();
    }

    a->T = tam();
    cargarArreglo(a);

}

void cargarArreglo(Arreglo *a)
{
    if (a->tipo == 'c')
    {
        a->C =(char **)realloc(a->C, ((a->T*a->N)+ 1)*sizeof(char));

        int i;

        for (i = 0; i < a->T; i++)
        {
            printf("Ingrese un caracter: ");
            fflush(stdin);
            scanf("%c", &(a->C[i][a->N]));
            printf("\033[F\033[K");
        }

        a->C[i + 1] = '\0';
    }
    else if (a->tipo == 'i')
    {
        a->V =(int **)realloc(a->V, (a->T*a->N)*sizeof(int));

        for (int i = 0; i < a->T; i++)
        {
            printf("Ingrese un numero entero: ");
            scanf("%d", &a->V[i][a->N]);
            printf("\033[F\033[K");
        }
    }
    else if (a->tipo == 'f')
    {
        a->F =(float **)realloc(a->F, (a->T*a->N)*sizeof(float));

        for (int i = 0; i < a->T; i++)
        {
            printf("Ingrese un float: ");
            scanf("%f", &a->F[i][a->N]);
            printf("\033[F\033[K");
        }
    }
    else if (a->tipo == 'r')
    {
        a->F =(float **)realloc(a->F, (a->T*a->N)*sizeof(float));

        srand(time(NULL));

        for (int i = 0; i < a->T; i++)
        {
            a->F[i][a->N] =(double) rand() / RAND_MAX * 10;
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
    if (a->tipo == 'i')
    {
        int suma = 0;

        for (int i = 0; i < a->T; i++)
        {
            suma += a->V[i];
        }

        printf("\n\nLa suma de los elementos del arreglo es %d.", suma);
    }
    else if (a->tipo == 'f' || a->tipo == 'r')
    {
        float suma = 0;

        for (int i = 0; i < a->T; i++)
        {
            suma += a->F[i];
        }

        printf("\n\nLa suma de los elementos del arreglo es %.2f", suma);
    }


}

void arregloAPila(Arreglo *a, Pila *p)
{
    for (int i = 0; i < a->T; i++)
    {
        apilar(p, a->V[i]);
    }

    printf("Arreglo:\n\n");
    mostrarArreglo(a);

    printf("\nPILITA:\n");
    mostrar(p);
}

void buscar(Arreglo *a)
{
    int flag = 0;
    printf("Que elemento desea buscar en el arreglo? ");

    if (a->tipo == 'i')
    {
        int n = 0;

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
            printf("\nEl elemento %d no se encuentra en el arreglo.\n", n);
            mostrarArreglo(a);
        }
        else
        {
            printf("\nEl elemento %d se encuentra en el arreglo.\n", n);
            mostrarArreglo(a);
        }
    }
    else if (a->tipo == 'c')
    {
        char n;

        fflush(stdin);
        scanf("%c",&n);

        for (int i = 0; i < a->T; i++)
        {
            if (a->C[i] == n)
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl elemento %c no se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
        else
        {
            printf("\nEl elemento %c se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
    }
    else if (a->tipo == 'f')
    {
        float n = 0;

        scanf("%f",&n);

        for (int i = 0; i < a->T; i++)
        {
            if (a->F[i] == n)
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl elemento %.2f no se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
        else
        {
            printf("\nEl elemento %.2f se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
    }
}

void ordenarArreglo (Arreglo *a)
{
    printf("Con que metodo desea invertir el arreglo? (i, s) \n");
    fflush(stdin);
    char o = getch();

    while (o != 'i' && o != 's')
    {
        printf("\033[F\033[K");
        printf("Valor incorrecto, con que metodo desea invertir el arreglo? (i, s) \n");
        fflush(stdin);
        o = getch();
    }


    if (o == 's')
    {
        if (a->tipo == 'c')
        {
            char ordenada;

            for (int i = 0; i < a->T; i++)
            {
                ordenada = a->C[i];
                for (int j = i; j < a->T; j++)
                {
                    if (a->C[j] < ordenada)
                    {
                        ordenada = a->C[j];
                        a->C[j] = a->C[i];
                        a->C[i] = ordenada;
                    }
                }
            }
        }
        else if (a->tipo == 'i')
        {
            int ordenada = 0;

            for (int i = 0; i < a->T; i++)
            {
                ordenada = a->V[i];
                for (int j = i; j < a->T; j++)
                {
                    if (a->V[j] < ordenada)
                    {
                        ordenada = a->V[j];
                        a->V[j] = a->V[i];
                        a->V[i] = ordenada;
                    }
                }
            }
        }
        else
        {
            float ordenada = 0;

            for (int i = 0; i < a->T; i++)
            {
                ordenada = a->F[0];
                for (int j = i; j < a->T; j++)
                {
                    if (a->F[j] < ordenada)
                    {
                        a->F[j-1] = a->F[j];
                        a->F[j] = ordenada;
                    }
                }
            }
        }
    }
    else
    {
        if (a->tipo == 'c')
        {
            char ordenada;

            for (int i = 1; i < a->T; i++)
            {
                ordenada = a->C[i];
                int j = i - 1;

                while (j >= 0 && a->C[j] > ordenada)
                {
                    a->C[j + 1] = a->C[j];
                    j--;
                }

                a->C[j + 1] = ordenada;
            }
        }
        else if (a->tipo == 'i')
        {
            int ordenada;

            for (int i = 1; i < a->T; i++)
            {
                ordenada = a->V[i];
                int j = i - 1;

                while (j >= 0 && a->V[j] > ordenada)
                {
                    a->V[j + 1] = a->V[j];
                    j--;
                }

                a->V[j + 1] = ordenada;
            }
        }
        else
        {
            float ordenada;

            for (int i = 1; i < a->T; i++)
            {
                ordenada = a->F[i];
                int j = i - 1;

                while (j >= 0 && a->F[j] > ordenada)
                {
                    a->F[j + 1] = a->F[j];
                    j--;
                }

                a->F[j + 1] = ordenada;
            }
        }
    }

}

void insertarArreglo(Arreglo *a)
{
    int ins = 0, t = 0;

    if (a->tipo == 'c')
    {
        char temp;

        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = a->T;
        a->T += ins;

        a->C =(char *)realloc(a->C, (a->T + 1)*sizeof(char));

        for (int i = t; i < a->T; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            fflush(stdin);
            scanf("%c", &temp);
            a->C[i] = temp;
        }
        a->C[a->T] = '\0';

    }
    else if (a->tipo == 'i')
    {
        int temp = 0;

        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = a->T;
        a->T += ins;

        a->V =(int *)realloc(a->V, a->T*sizeof(int));

        for (int i = t; i < a->T; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            scanf("%d", &temp);
            a->V[i] = temp;
        }
    }
    else
    {
        float temp = 0;

        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = a->T;
        a->T += ins;

        a->F =(float *)realloc(a->F, a->T*sizeof(float));

        for (int i = t; i < a->T; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            scanf("%f", &temp);
            a->F[i] = temp;
        }
    }

    printf("Se cargaron %d elementos en el arreglo.", ins);

}

void buscarMayorArreglo(Arreglo *a)
{
    if (a->tipo == 'c')
    {
        char mayor;
        mayor = a->C[0];

        for (int i = 0; i < a->T; i++)
        {
            if (a->C[i] > mayor)
            {
                mayor = a->C[i];
            }
        }

        printf("El mayor elemento del arreglo es: %c\n", mayor);
    }
    else if (a->tipo == 'i')
    {
        int mayor;
        mayor = a->V[0];

        for (int i = 0; i < a->T; i++)
        {
            if (a->V[i] > mayor)
            {
                mayor = a->V[i];
            }
        }

        printf("El mayor elemento del arreglo es: %d\n", mayor);
    }
    else
    {
        float mayor;
        mayor = a->F[0];

        for (int i = 0; i < a->T; i++)
        {
            if (a->F[i] > mayor)
            {
                mayor = a->F[i];
            }
        }

        printf("El mayor elemento del arreglo es: %.2f\n", mayor);
    }
}

void esCapicua(Arreglo *a)
{
    if (a->tipo == 'c')
    {
        int flag = 0;

        for (int i = 0; i < a->T; i++)
        {
            if (a->C[i] != a->C[a->T - (i + 1)])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl arreglo es capicúa.\n");
        }
        else
        {
            printf("\nEl arreglo no es capicúa.\n");
        }
    }
    else if (a->tipo == 'i')
    {
        int flag = 0;

        for (int i = 0; i < a->T; i++)
        {
            if (a->V[i] != a->V[a->T - (i + 1)])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl arreglo es capicúa.\n");
        }
        else
        {
            printf("\nEl arreglo no es capicúa.\n");
        }
    }
    else
    {
        int flag = 0;

        for (int i = 0; i < a->T; i++)
        {
            if (a->F[i] != a->F[a->T - (i + 1)])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl arreglo es capicúa.\n");
        }
        else
        {
            printf("\nEl arreglo no es capicúa.\n");
        }
    }
}

void invertirArreglo(Arreglo *a)
{
    if (a->tipo == 'c')
    {
        for (int i = 0; i < a->T; i++)
        {
            a->C[i] = a->C[i] + a->C[a->T - (i+1)];

            a->C[a->T - (i+1)] = a->C[i] - a->C[a->T - (i+1)];

            a->C[i] = a->C[i] - a->C[a->T - (i+1)];
        }
    }
    else if (a->tipo == 'i')
    {
        int valoresInvertidos[a->T];

        for (int i = 0; i < a->T; i++)
        {
            valoresInvertidos[i] = a->V[a->T - (i + 1)];
        }
        for (int i = 0; i < a->T; i++)
        {
            a->V[i] = valoresInvertidos[i];
        }
    }
    else
    {
        float valoresInvertidos[a->T];

        for (int i = 0; i < a->T; i++)
        {
            valoresInvertidos[i] = a->F[a->T - (i + 1)];
        }
        for (int i = 0; i < a->T; i++)
        {
            a->F[i] = valoresInvertidos[i];
        }
    }
}
