#include "array.h"

void cargarArray(int *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("\nIngrese un numero entero: ");
        scanf("%d", &a[i]);
    }
    printf("\nEl arreglo fue cargado con %d elementos.", t);
}
int tam()
{
    int t;
    printf("Ingrese el tama�o de su arreglo: ");
    scanf("%d", &t);
    return t;
}
//
//int nuevoArray()
//{
//    int t = 0;
//    printf("Declare el tama�o del nuevo arreglo: ");
//    scanf("%d", &t);
//    int a[t];
//    cargarArray(&a, t);
//
//    return a;
//}
void mostrarArray(int *a, int t)
{
    for (int i = 0; i < t; i++)
    {
        printf("| %d ", a[i]);
    }
}


