#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "array.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    int r = 0;
    char q = NULL;
    Arreglo arreglo;

    do
    {

        queArreglo(&arreglo);

        do
        {
            system("cls");
            printf("Trabajo Practico de Funciones con Arreglos.\n\n");
            printf("Seleccione el ejercicio que desea visualizar: \n\n");
            printf("1. Crear un Arreglo.\n");
            printf("2. Mostrar el Arreglo.\n");
            printf("3. Sumar el Arreglo.\n");
            printf("4. Copiar Arreglo a Pila.\n");
            printf("5. Sumar Arreglo de float random.\n");
            printf("6. Buscar elemento en el arreglo. \n");
            printf("7. Agregar un elemento y ordenar Arreglo.\n");
            printf("8. Buscar el mayor elemento.\n");
            printf("9. Determinar si el arreglo es capicúa \n");
            printf("10. Invertir el arreglo\n");
            printf("11. Ordenar el Arreglo\n");
            printf("12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente. \n");
            printf("13. Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.\n");

            fflush(stdin);
            scanf("%d", &r);
            system("cls");

            switch(r)
            {
                case 1:
                {
                    printf("1. Crear un Arreglo.\n\n");

                    nuevoArreglo(&arreglo);

                    break;
                }
                case 2:
                {
                    printf("2. Mostrar el Arreglo.\n\n");

                    mostrarArreglo(&arreglo);

                    break;
                }
                case 3:
                {
                    printf("3. Sumar el Arreglo.\n\n");

                    sumarArreglo(&arreglo);

                    break;
                }
                case 4:
                {
                    printf("4. Copiar Arreglo a Pila.\n\n");

                    Pila pilita;
                    inicpila(&pilita);

                    arregloAPila(&arreglo, &pilita);

                    break;
                }
                case 5:
                {
                    printf("5. Sumar Arreglo de float random.\n\n");

                    sumarArreglo(&arreglo);

                    break;
                }
                case 6:
                {
                    printf("6. Buscar elemento en el arreglo. \n\n");

                    buscar(&arreglo);

                    break;
                }
                case 7:
                {
                    printf("7. Agregar un elemento.\n\n");

                    ordenarArreglo(&arreglo);
                    insertarArreglo(&arreglo);

                    break;
                }
                case 8:
                {
                    printf("8. Buscar el mayor elemento.\n\n");

                    buscarMayorArreglo(&arreglo);

                    break;
                }
                case 9:
                {
                    printf("9. Determinar si el Arreglo es capicúa \n\n");

                    esCapicua(&arreglo);

                    break;
                }
                case 10:
                {
                    printf("10. Invertir el Arreglo\n\n");

                    invertirArreglo(&arreglo);

                    break;
                }
                case 11:
                {
                    printf("11. Ordenar el Arreglo\n\n");

                    ordenarArreglo(&arreglo);

                    break;
                }
                case 12:
                {

                    break;
                }
                case 13:
                {
                    do
                    {

                        salir(&q);
                    }
                    while(q != 'q');

                    r = 0;
                    system("cls");
                    break;
                }

                default:
                {
                    printf("El numero de ejercicio es inexistente.\n\n");
                    r = 0;
                }
            }

            salir(&q);

        } while(q != 'q');
    } while (q == 'q');


    return 0;
}
