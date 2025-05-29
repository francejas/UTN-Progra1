#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define MAX 24

int cargarArreglo(int arreglo[], int v);
float promedio (int arreglo[], int v);

int main()
{
    int arregloTemperatura[MAX];
    int v=0;

    Pila menores;
    inicpila(&menores);

    float promedioArreglo=0;

    //1
    v=cargarArreglo(arregloTemperatura,v);
    mostrarArreglo(arregloTemperatura,v);


    //2
    promedioArreglo=promedio(arregloTemperatura,v);
    printf("\n");
    printf("%.2f",promedioArreglo);
    //3
    pasarApila(&menores,arregloTemperatura,v,promedioArreglo);
    printf("Arreglo sin:\n");
    mostrarArreglo(arregloTemperatura,v);
    printf("Pila \n");
    mostrar(&menores);

    return 0;
}

int cargarArreglo(int arreglo[], int v)
{
    char control;
    int dato=0;
    do
    {
        printf("Ingrese un dato al arreglo: ");
        fflush(stdin);
        scanf("%d",&dato);
        if(dato>-45 && dato<60)
        {
            arreglo[v]=dato;
            v++;
        }
        else
        {
            printf("Dato incorrecto \n");
        }
        printf("Desea seguir ? (s/n)\n");
        fflush(stdin);
        scanf(" %c",&control);
    }
    while((control=='s' || control=='S')&& v<MAX);

    return v;
}

void mostrarArreglo(int arreglo[], int v)
{
    int contador=0;

    for(int i=0; i<v; i++)
    {
        printf(" %d |",arreglo[i]);
        contador++;
        if(contador==8 || contador==16 )
        {
            printf("\n");
        }

    }


}


float promedio (int arreglo[], int v)
{
    float promedio=0;
    int suma=sumaArreglo(arreglo,v);
    promedio=(float)suma/v;

    return promedio;
}

int sumaArreglo(int arreglo[], int v)
{
    int suma=0;
    for(int i =0; i<v; i++)
    {
        suma+=arreglo[i];
    }
    return suma;
}

void pasarApila(Pila *menores,int arregloTemperatura[],int v,float promedioArreglo)
{
    Pila aux;
    inicpila(&aux);

    int i =0;

    while(i<v){
        apilar(&aux,arregloTemperatura[i]);
        i++;
    }
    v=0;
    while(!pilavacia(&aux)){
        if(tope(&aux)<promedioArreglo){
            apilar(menores,desapilar(&aux));
        } else {
            arregloTemperatura[v]=tope(&aux);
            desapilar(&aux);
            v++;
        }
    }
    
    for(int i =0;i<v;i++){
        if(arregloTemperatura[i]<promedioArreglo){
            apilar(menores,arregloTemperatura[i]);
        }
    }
}
