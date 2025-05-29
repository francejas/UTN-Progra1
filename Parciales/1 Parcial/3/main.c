#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

#define DIMENSION 5
//Prototipado
void cargarDatos(int array[],int array2[], int*vCodigos);
//void mostrarArray(codigosISBN,vCodigos);

int main()
{
    Pila Policial;
    Pila Romance;
    Pila Terror;

    inicpila(&Policial);
    inicpila(&Romance);
    inicpila(&Terror);

    int vPolicial=0;
    int vRomance=0;
    int vTerror=0;


    int codigosISBN[DIMENSION];
    int vCodigos=0;

    int generosLibros[DIMENSION];
    int vGeneros=0;

    cargarDatos(codigosISBN,generosLibros,&vCodigos);
    mostrarArray(codigosISBN,generosLibros,vCodigos);
    clasificarPorGenero(codigosISBN,generosLibros,vCodigos,&Policial,&Romance,&Terror,&vPolicial,&vRomance,&vTerror);
    printf("Pila policial, %d",vPolicial);
    mostrar(&Policial);
    printf("Pila romance, %d",vRomance);
    mostrar(&Romance);
    printf("Pila terror, %d",vTerror);
    mostrar(&Terror);



    system("PAUSE");
    return 0;
}

void cargarDatos(int array[],int array2[], int*vCodigos)
{
    int respuesta;
    srand(time(NULL));
    for(int i=0; i<DIMENSION; i++)
    {
        array[i]=rand() % 100+1;
        (*vCodigos)++;
        printf("Ingrese calificacion para el libro n%d, codigo[%d] \n",(i+1),array[i]);
        printf("1 Policial, 2 Romance, 3 Terror \n");
        scanf("%d",&respuesta);

        if (respuesta != 1 && respuesta != 2 && respuesta != 3)
        {
            printf("ERROR");
        }
        else if(respuesta==1)
        {
            array2[i]=1;
        }
        else if(respuesta==2)
        {
            array2[i]=2;
        }
        else
        {
            array2[i]=3;
        }
    }


}

void mostrarArray(int array[],int array2[],int vCodigos)
{
    for(int i =0; i<vCodigos; i++)
    {
        printf("Libro %d, codigo [%d], tema: %d \n",(i+1),array[i],array2[i]);

    }
}

void clasificarPorGenero(int array[],int array2[],int vCodigos, Pila *Policial,Pila *Romance,Pila *Terror,int *vPolicial,int *vRomance,int *vTerror)
{
    for(int i=0; i<vCodigos; i++)
    {
        if(array2[i]==1)
        {
            apilar(Policial,array[i]);
            (*vPolicial)++;
        }
        else if (array2[i]==2)
        {
            apilar(Romance,array[i]);
            (*vRomance)++;
        }
        else
        {
            apilar(Terror,array[i]);
            (*vTerror)++;
        }
    }

}
