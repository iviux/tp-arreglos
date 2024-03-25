#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "pila.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    int r = 0;
    char q = NULL;

    do
    {
        printf("Trabajo Practico de Funciones con Arreglos.\n\n");
        printf("Seleccione el ejercicio que desea visualizar: \n\n");
        printf("1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo.\n");
        printf("2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla. \n");
        printf("3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.\n");
        printf("4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.\n");
        printf("5. Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100.\n");
        printf("6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres. \n");
        printf("7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.\n");
        printf("8. Realizar una función que obtenga el máximo carácter de un arreglo dado.\n");
        printf("9. Realizar una función que determine si un arreglo es capicúa. \n");
        printf("10. Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)\n");
        printf("11. Ordenar un arreglo según los siguientes métodos: a) Selección b) Inserción\n");
        printf("12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente. \n");
        printf("13. Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.\n");

        fflush(stdin);
        scanf("%d", &r);
        system("cls");

        switch(r)
        {
            case 1:
            {
                do
                {
                    printf("1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo.\n\n");
                    int t = tam();
                    int arreglo[t];
                    cargarArray(&arreglo, t);
                    mostrarArray(&arreglo, t);


                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 2:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 3:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 4:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 5:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 6:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 7:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 8:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 9:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 10:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 11:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 12:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
                }
                while(q != 'q');

                r = 0;
                system("cls");
                break;
            }
            case 13:
            {
                do
                {

                    printf("\nPresione una tecla para continuar, q para salir.");
                    fflush(stdin);
                    q = getch();

                    system("cls");
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
    } while(r == 0);
    return 0;
}
