#include "array.h"

void salir(char *q)
{
    // Funcion para decidir si se desea seguir editando un arreglo o volver a la seleccion

    printf("\nPresione una tecla para continuar editando el arreglo, q para salir.");
    fflush(stdin);
    *q = getch();

    system("cls");
}

void queArreglo(Arreglo *a)
{
    // Funcion para crear un arreglo o seleccionar un arreglo existente.
    static int n = 0;
    // Control para que solo se pueda ingresar a arreglos existentes o crear el arreglo consecutivo al ultimo creado

    do
    {
        system("cls");
        printf("Ingrese el numero de arreglo que desea crear o modificar: ");
        scanf("%d", &(INDEX));
    }
    while (INDEX > n + 1 || INDEX < 0);

    INDEX = INDEX -1;

    // Si el numero del arreglo es igual al indice de arreglos existentes, incremento el indice

    if (INDEX == n)
    {
        n++;
    }
}


int tam()
{
    // Funcion para que el usuario seleccione el tamaño del arreglo

    int t;
    printf("Ingrese el tamaño de su arreglo: ");
    scanf("%d", &t);
    printf("\n");
    return t;
}

void nuevoArreglo (Arreglo *a)
{
    TAM =(int *)malloc(2*sizeof(int));

    INDEX = 0;

    if(TIPO == 'c')
    {
        a->C =(char **)malloc(50*sizeof(char));
    }
    else if (TIPO == 'i')
    {
        a->V =(int **)malloc(50*sizeof(int));
    }
    else
    {
        a->F =(float **)malloc(50*sizeof(float));
    }

    printf("Que tipo de arreglo se va a usar? (c, i, f, r)\n");
    fflush(stdin);
    TIPO = getch();

    while(TIPO != 'c' && TIPO != 'i' && TIPO != 'f' && TIPO != 'r')
    {
        printf("\033[F\033[K");
        printf("Valor incorrecto, que tipo de arreglo se va a usar? (c, i, f, r)\n");
        fflush(stdin);
        TIPO = getch();
    }
}

void reasignMem(Arreglo *a)
{
    int suma = 0;

    for (int i = 0; i < (INDEX + 1); i++)
    {
        suma += TAM[i];
    }

    if(TIPO == 'c')
    {
        a->C = (char **)realloc(a->C, (INDEX + 1) * sizeof(char));
        for (int i = 0; i < INDEX + 1; ++i)
        {
            a->C[i] =(char *)realloc (a->C, (suma + (INDEX + 1))*sizeof(char));
        }
    }
    else if (TIPO == 'i')
    {
        a->V =(int **)realloc (a->V, suma*sizeof(int));
    }
    else if (TIPO == 'f' || TIPO == 'r')
    {
        a->F =(float **)realloc(a->F, suma*sizeof(float));
    }

    TAM =(int *)realloc (TAM, (INDEX+2)*sizeof(int));
}

void cargarArreglo(Arreglo *a)
{
    // Establezco el tamaño que va a tener el arreglo seleccionado (INDEX = indice de arreglo)
    TAM[INDEX] = tam();
//    printf("TAMAÑO %d\n", TAM[INDEX]);

    reasignMem(a);

    int mem = (int)sizeof(*a)/sizeof(char);

    if (TIPO == 'c')
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un caracter: ");
            fflush(stdin);
            scanf("%c", &(a->C[i][INDEX]));
//            printf("\033[F\033[K");
            printf("memoria %d, tamaño %d, fila %d, columna %d, valor %c\n", mem, TAM[INDEX], i, INDEX, a->C[i][INDEX]);
        }

        a->C[TAM[INDEX]][INDEX] = '\0';
    }
    else if (TIPO == 'i')
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un numero entero: ");
            scanf("%d", &(a->V[i][INDEX]));
            printf("\033[F\033[K");
        }
    }
    else if (TIPO == 'f')
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un float: ");
            scanf("%f", &(a->F[i][INDEX]));
            printf("\033[F\033[K");
        }
    }
    else if (TIPO == 'r')
    {
        srand(time(NULL));

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            a->F[i][INDEX] =(double) rand() / RAND_MAX * 10;
        }
    }

    printf("\nEl arreglo fue cargado con %d elementos.\n", TAM[INDEX]);
}

void mostrarArreglo(Arreglo *a)
{
    if (TIPO == 'c')
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("| %c", a->C[i][INDEX]);
        }
        printf("\n\n");
    }
    else if (TIPO == 'i')
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("| %d ", a->V[i][INDEX]);
        }
        printf("\n\n");
    }
    else
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("| %.2f ", a->F[i][INDEX]);
        }
        printf("\n\n");
    }
}

void sumarArreglo(Arreglo *a)
{
    if (TIPO == 'i')
    {
        int suma = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            suma += a->V[i][INDEX];
        }

        printf("\n\nLa suma de los elementos del arreglo es %d.", suma);
    }
    else if (TIPO == 'f' || TIPO == 'r')
    {
        float suma = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            suma += a->F[i][INDEX];
        }

        printf("\n\nLa suma de los elementos del arreglo es %.2f", suma);
    }


}

void arregloAPila(Arreglo *a, Pila *p)
{
    for (int i = 0; i < TAM[INDEX]; i++)
    {
        apilar(p, a->V[i][INDEX]);
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

    if (TIPO == 'i')
    {
        int n = 0;

        scanf("%d",&n);

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->V[i][INDEX] == n)
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
    else if (TIPO == 'c')
    {
        char n;

        fflush(stdin);
        scanf("%c",&n);

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->C[i][INDEX] == n)
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
    else if (TIPO == 'f')
    {
        float n = 0;

        scanf("%f",&n);

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->F[i][INDEX] == n)
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
        if (TIPO == 'c')
        {
            char ordenada;

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                ordenada = a->C[i][INDEX];
                for (int j = i; j < TAM[INDEX]; j++)
                {
                    if (a->C[j][INDEX] < ordenada)
                    {
                        ordenada = a->C[j][INDEX];
                        a->C[j][INDEX] = a->C[i][INDEX];
                        a->C[i][INDEX] = ordenada;
                    }
                }
            }
        }
        else if (TIPO == 'i')
        {
            int ordenada = 0;

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                ordenada = a->V[i][INDEX];
                for (int j = i; j < TAM[INDEX]; j++)
                {
                    if (a->V[j][INDEX] < ordenada)
                    {
                        ordenada = a->V[j][INDEX];
                        a->V[j][INDEX] = a->V[i][INDEX];
                        a->V[i][INDEX] = ordenada;
                    }
                }
            }
        }
        else
        {
            float ordenada = 0;

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                ordenada = a->F[i][INDEX];
                for (int j = i; j < TAM[INDEX]; j++)
                {
                    if (a->F[j][INDEX] < ordenada)
                    {
                        ordenada = a->F[j][INDEX];
                        a->F[j][INDEX] = a->F[i][INDEX];
                        a->F[i][INDEX] = ordenada;
                    }
                }
            }
        }
    }
    else
    {
        if (TIPO == 'c')
        {
            char ordenada;

            for (int i = 1; i < TAM[INDEX]; i++)
            {
                ordenada = a->C[i][INDEX];
                int j = i - 1;

                while (j >= 0 && a->C[j][INDEX] > ordenada)
                {
                    a->C[j + 1][INDEX] = a->C[j][INDEX];
                    j--;
                }

                a->C[j + 1][INDEX] = ordenada;
            }
        }
        else if (TIPO == 'i')
        {
            int ordenada;

            for (int i = 1; i < TAM[INDEX]; i++)
            {
                ordenada = a->V[i][INDEX];
                int j = i - 1;

                while (j >= 0 && a->V[j][INDEX] > ordenada)
                {
                    a->V[j + 1][INDEX] = a->V[j][INDEX];
                    j--;
                }

                a->V[j + 1][INDEX] = ordenada;
            }
        }
        else
        {
            float ordenada;

            for (int i = 1; i < TAM[INDEX]; i++)
            {
                ordenada = a->F[i][INDEX];
                int j = i - 1;

                while (j >= 0 && a->F[j][INDEX] > ordenada)
                {
                    a->F[j + 1][INDEX] = a->F[j][INDEX];
                    j--;
                }

                a->F[j + 1][INDEX] = ordenada;
            }
        }
    }

}

void insertarArreglo(Arreglo *a)
{
    int ins = 0, t = 0;

    if (TIPO == 'c')
    {
        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = TAM[INDEX];
        TAM[INDEX] += ins;

        reasignMem(a);

        for (int i = t; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            fflush(stdin);
            scanf("%c", &(a->C[i][INDEX]));

        }
        a->C[TAM[INDEX]][INDEX] = '\0';

    }
    else if (TIPO == 'i')
    {
        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = TAM[INDEX];
        TAM[INDEX] += ins;

        reasignMem(a);

        for (int i = t; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            scanf("%d", &(a->V[i][INDEX]));
        }
    }
    else
    {
        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = TAM[INDEX];
        TAM[INDEX] += ins;

        reasignMem(a);

        for (int i = t; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            scanf("%f", &(a->F[i][INDEX]));
        }
    }

    printf("Se cargaron %d elementos en el arreglo.", ins);

}

void buscarMayorArreglo(Arreglo *a)
{
    if (TIPO == 'c')
    {
        char mayor;
        mayor = a->C[0][INDEX];

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->C[i][INDEX] > mayor)
            {
                mayor = a->C[i][INDEX];
            }
        }

        printf("El mayor elemento del arreglo es: %c\n", mayor);
    }
    else if (TIPO == 'i')
    {
        int mayor;
        mayor = a->V[0][INDEX];

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->V[i][INDEX] > mayor)
            {
                mayor = a->V[i][INDEX];
            }
        }

        printf("El mayor elemento del arreglo es: %d\n", mayor);
    }
    else
    {
        float mayor;
        mayor = a->F[0][INDEX];

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->F[i][INDEX] > mayor)
            {
                mayor = a->F[i][INDEX];
            }
        }

        printf("El mayor elemento del arreglo es: %.2f\n", mayor);
    }
}

void esCapicua(Arreglo *a)
{
    if (TIPO == 'c')
    {
        int flag = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->C[i][INDEX] != a->C[TAM[INDEX] - (i + 1)][INDEX])
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
    else if (TIPO == 'i')
    {
        int flag = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->V[i][INDEX] != a->V[TAM[INDEX] - (i + 1)][INDEX])
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

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->F[i][INDEX] != a->F[TAM[INDEX] - (i + 1)][INDEX])
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
    if (TIPO == 'c')
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            a->C[i][INDEX] = a->C[i][INDEX] + a->C[TAM[INDEX] - (i+1)][INDEX];

            a->C[TAM[INDEX] - (i+1)][INDEX] = a->C[i][INDEX] - a->C[TAM[INDEX] - (i+1)][INDEX];

            a->C[i][INDEX] = a->C[i][INDEX] - a->C[TAM[INDEX] - (i+1)][INDEX];
        }
    }
    else if (TIPO == 'i')
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            a->V[i][INDEX] = a->V[i][INDEX] + a->V[TAM[INDEX] - (i+1)][INDEX];

            a->V[TAM[INDEX] - (i+1)][INDEX] = a->V[i][INDEX] - a->V[TAM[INDEX] - (i+1)][INDEX];

            a->V[i][INDEX] = a->V[i][INDEX] - a->V[TAM[INDEX] - (i+1)][INDEX];
        }
    }
    else
    {
        for (int i = 0; i < TAM[INDEX]; i++)
        {
            a->F[i][INDEX] = a->F[i][INDEX] + a->F[TAM[INDEX] - (i+1)][INDEX];

            a->F[TAM[INDEX] - (i+1)][INDEX] = a->F[i][INDEX] - a->F[TAM[INDEX] - (i+1)][INDEX];

            a->F[i][INDEX] = a->F[i][INDEX] - a->F[TAM[INDEX] - (i+1)][INDEX];
        }
    }
}
