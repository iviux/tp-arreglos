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
        printf("1. Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros y permita que el usuario ingrese valores al mismo por teclado. La funci�n debe retornar la cantidad de elementos cargados en el arreglo.\n");
        printf("2. Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y los muestre por pantalla. \n");
        printf("3. Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y calcule la suma de sus elementos.\n");
        printf("4. Hacer una funci�n que reciba como par�metro un arreglo, la cantidad de elementos (v�lidos) cargados en �l y una Pila. La funci�n debe copiar los elementos del arreglo en la pila.\n");
        printf("5. Realizar una funci�n que sume los elementos de un arreglo de n�meros reales (float) de dimensi�n 100.\n");
        printf("6. Realizar una funci�n que indique si un elemento dado se encuentra en un arreglo de caracteres. \n");
        printf("7. Realizar una funci�n que inserte un car�cter en un arreglo ordenado alfab�ticamente, conservando el orden.\n");
        printf("8. Realizar una funci�n que obtenga el m�ximo car�cter de un arreglo dado.\n");
        printf("9. Realizar una funci�n que determine si un arreglo es capic�a. \n");
        printf("10. Realizar una funci�n que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)\n");
        printf("11. Ordenar un arreglo seg�n los siguientes m�todos: a) Selecci�n b) Inserci�n\n");
        printf("12. Dados dos arreglos ordenados alfab�ticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo tambi�n ordenado alfab�ticamente. \n");
        printf("13. Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al �ndice actual: {1,6,12,19,27}.\n");

        fflush(stdin);
        scanf("%d", &r);
        system("cls");

        switch(r)
        {
            case 1:
            {
                do
                {
                    printf("1. Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros y permita que el usuario ingrese valores al mismo por teclado. La funci�n debe retornar la cantidad de elementos cargados en el arreglo.\n\n");
                    int t = tam();
                    int arreglo[t];
                    cargarArray(&arreglo, t);

                    salir(&q);
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
                    printf("2. Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y los muestre por pantalla. \n");

                    int t = tam();
                    int arreglo[t];
                    cargarArray(&arreglo, t);
                    mostrarArray(&arreglo, t);

                   salir(&q);
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
                    printf("3. Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y calcule la suma de sus elementos.\n");

                    int t = tam();
                    int arreglo[t];
                    cargarArray(&arreglo, t);
                    mostrarArray(&arreglo, t);
                    sumarArray(&arreglo, t);


                    salir(&q);
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
                    printf("4. Hacer una funci�n que reciba como par�metro un arreglo, la cantidad de elementos (v�lidos) cargados en �l y una Pila. La funci�n debe copiar los elementos del arreglo en la pila.\n");

                    Pila pilita;
                    inicpila(&pilita);

                    int t = tam();
                    int arreglo[t];
                    cargarArray(&arreglo, t);
                    mostrarArray(&arreglo, t);
                    arrayAPila(&arreglo, t, &pilita);

                    printf("\nPILITA:\n");
                    mostrar(&pilita);

                    salir(&q);
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
                    printf("5. Realizar una funci�n que sume los elementos de un arreglo de n�meros reales (float) de dimensi�n 100.\n");

                    int t = 100;
                    float arreglo[t];
                    cargarArrayRan(&arreglo, t);
                    sumarArrayFloat(&arreglo, t);
                    salir(&q);
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
                    printf("6. Realizar una funci�n que indique si un elemento dado se encuentra en un arreglo de caracteres. \n");

                    int t = tam();
                    int arreglo[t];
                    cargarArray(&arreglo, t);
                    mostrarArray(&arreglo, t);
//                    buscar(&arreglo, t);

                    salir(&q);
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

                    salir(&q);
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

                    salir(&q);
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

                    salir(&q);
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

                    salir(&q);
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

                    salir(&q);
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

                    salir(&q);
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
    } while(r == 0);
    return 0;
}
