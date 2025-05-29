#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define max_dim 31

#define CANTIDAD 10
#define LARGO 30

// Declaraciones anticipadas de funciones
int menu();
void cargaArray(int array[], int *v);
void mostrarArray(int array[], int v);
int encontrarNombre(char array[CANTIDAD][LARGO], int cantPalabras, char nombre[]);

int main(int argc, char *argv[])
{
    int selected;
    int array[max_dim];
    int v = 0;

    int precipitacionTotal=0;
    float promedio=0;

    Pila pila;
    inicpila(&pila);

    char nombres[CANTIDAD][LARGO];
    int cantPalabras=0;

    char nombre[LARGO];

    do
    {
        selected = menu();
        switch (selected)
        {
        case 1:
            cargaArray(array, &v);
            mostrarArray(array, v);
            int cant=mayores(array,v,&pila);
            printf("\n Dias mayores a 4: %d \n",cant);
            totalPrecipitacion(array,v,&precipitacionTotal);
            printf("Precipitacion total: %d \n",precipitacionTotal);
            promedioPrecipitacion(v,precipitacionTotal,&promedio);
            printf("Precipitacion promedio: %.2f \n",promedio);

            system("PAUSE");
            break;
        case 2:
            //sin usar return
            cargarArrayNombres(nombres,&cantPalabras);
            mostrarArrayNombres(nombres,cantPalabras);
            system("PAUSE");
            break;
        case 3:
            printf("Ingrese un nombre a buscar: ");
            scanf("%s",nombre);
            int flag=encontrarNombre(nombres,cantPalabras,nombre);
            if (flag==1){
                printf("El nombre se encuentra en el arreglo.\n");
            } else {
                printf("El nombre NO se encuentra en el arreglo.\n");
            }
            system("PAUSE");
            break;
        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }

    }
    while (selected != 0);

    system("PAUSE");
    return 0;
}

int menu()
{
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1- Carga y análisis de precipitaciones");
    printf("\n2- Cargar y mostrar nombres");
    printf("\n3- Buscar nombre");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d", &input);
    return input;
}

void cargaArray(int array[], int *v)
{
    char respuesta;
    do
    {
        printf("Ingrese ml del dia [%d]: ", (*v + 1));
        scanf("%d", &array[*v]);
        (*v)++;

        printf("\nDesea continuar? s/n: ");
        fflush(stdin);
        scanf(" %c", &respuesta);  // El espacio antes de %c evita leer el salto de línea anterior

    }
    while ((respuesta != 'n' && respuesta != 'N') && (*v) < max_dim);
}

void mostrarArray(int array[], int v)
{
    for (int i = 0; i < v; i++)
    {
        printf("\nml del dia [%d]: %d", (i + 1), array[i]);
    }
}

int mayores(int array[],int v, Pila *pila)
{

    for(int i=0; i<v; i++)
    {
        if (array[i]>4)
        {
            apilar(pila, array[i]);
        }
    }
    int cant=cantDatosPila(*pila);

    return cant;
}

int cantDatosPila(Pila pila)
{
    int cant=0;
    while(!pilavacia(&pila))
    {
        desapilar(&pila);
        cant++;
    }
    return cant;
}

void totalPrecipitacion(int array[], int v, int *total)
{
    for(int i=0; i<v; i++)
    {
        (*total)+=array[i];
    }

}

void promedioPrecipitacion(int v, int total, float *promedio)
{

    (*promedio)=(float)total/v;
}

void cargarArrayNombres(char array[CANTIDAD][LARGO], int *cantPalabras)
{
    char respuesta;
    char palabra[LARGO];

    do
    {
        printf("Ingrese nombre: ");
        scanf("%s", palabra);

        if (strlen(palabra) >= LARGO)
        {
            printf("Exceso de caracteres, vuelva a ingresar\n");
        }
        else if (strlen(palabra) == 0)
        {
            printf("No ingreso ninguna palabra\n");
        }
        else
        {
            strcpy(array[*cantPalabras], palabra);
            (*cantPalabras)++;
        }

        // Validación de cantidad de nombres ingresados
        if (*cantPalabras >= CANTIDAD)
        {
            printf("Se alcanzó el límite de nombres (%d).\n", CANTIDAD);
            break;
        }

        printf("¿Desea seguir? s/n: ");
        scanf(" %c", &respuesta);  // espacio para limpiar el buffer

    }
    while ((respuesta != 'n' && respuesta != 'N') && *cantPalabras < CANTIDAD);
}

void mostrarArrayNombres(char array[CANTIDAD][LARGO], int cantPalabras)
{

    printf("\nArreglo de palabras (%d palabras):\n", cantPalabras);
    printf("---------------------------\n");

    for (int i = 0; i < cantPalabras; i++)
    {
        printf("%d: %s\n", i + 1, array[i]);
    }

    printf("---------------------------\n");
}

int encontrarNombre(char array[CANTIDAD][LARGO], int cantPalabras, char nombre[]){
    int flag=0;

    for (int i=0;i<cantPalabras;i++){
        if(strcmp(array[i],nombre)==0){
            flag=1;
        }
    }

    return flag;
}
