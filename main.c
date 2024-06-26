#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "array.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    int r = 0;
    char q;
    Arreglo arreglo;
    nuevoArreglo(&arreglo);

    do
    {
        system("cls");
        printf("Ingrese el numero de arreglo que desea editar: \n");

        selecArreglo(&arreglo);

        do
        {
            system("cls");
            printf("Trabajo Practico de Funciones con Arreglos.\n\n");
            printf("Seleccione el ejercicio que desea visualizar: \n\n");
            printf("  0) Seleccionar Arreglo.\n");
            printf("  1) Cargar el Arreglo.\n");
            printf("  2) Mostrar el Arreglo.\n");
            printf("  3) Sumar el Arreglo.\n");
            printf("  4) Copiar Arreglo a Pila.\n");
            printf("  5) Sumar Arreglo de float random.\n");
            printf("  6) Buscar elemento en el arreglo. \n");
            printf("  7) Agregar un elemento.\n");
            printf("  8) Buscar el mayor elemento.\n");
            printf("  9) Determinar si el arreglo es capic�a.\n");
            printf(" 10) Invertir el arreglo.\n");
            printf(" 11) Ordenar el Arreglo.\n");
            printf(" 12) Combinar Arreglos.\n");
            printf(" 13) Sumar elementos anteriores al �ndice.\n");

            fflush(stdin);
            scanf("%d", &r);
            system("cls");

            switch(r)
            {
                case 0:
                {
                    q = 'q';

                    break;
                }
                case 1:
                {
                    printf("1) Cargar el Arreglo.\n\n");

                    cargarArreglo(&arreglo);
                    mostrarArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 2:
                {
                    printf("2) Mostrar el Arreglo.\n\n");

                    mostrarArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 3:
                {
                    printf("3) Sumar el Arreglo.\n\n");

                    sumarArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 4:
                {
                    printf("4) Copiar Arreglo a Pila.\n\n");

                    Pila pilita;
                    inicpila(&pilita);

                    arregloAPila(&arreglo, &pilita);

                    salir(&q);

                    break;
                }
                case 5:
                {
                    printf("5) Sumar Arreglo de float random.\n\n");

                    sumarArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 6:
                {
                    printf("6) Buscar elemento en el arreglo. \n\n");

                    buscar(&arreglo);

                    salir(&q);

                    break;
                }
                case 7:
                {
                    printf("7) Agregar un elemento.\n\n");

                    insertarArreglo(&arreglo);
                    mostrarArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 8:
                {
                    printf("8) Buscar el mayor elemento.\n\n");

                    buscarMayorArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 9:
                {
                    printf("9) Determinar si el Arreglo es capic�a \n\n");

                    esCapicua(&arreglo);

                    salir(&q);

                    break;
                }
                case 10:
                {
                    printf("10) Invertir el Arreglo\n\n");

                    invertirArreglo(&arreglo);
                    mostrarArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 11:
                {
                    printf("11) Ordenar el Arreglo\n\n");

                    ordenarArreglo(&arreglo);
                    mostrarArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 12:
                {
                    printf(" 12) Combinar Arreglos. \n\n");

                    combinarArreglos(&arreglo);
                    selecArreglo(&arreglo);

                    salir(&q);

                    break;
                }
                case 13:
                {

                    printf(" 13) Sumar elementos anteriores al �ndice.\n");

                    sumarAnteriores(&arreglo);

                    salir(&q);

                    break;
                }

                default:
                {

                }
            }

        }while(q != 'q');

    } while(q == 'q');



    return 0;
}
