#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"
#include "math.h"


#define max 50


void mostrarArrayYerbaInvertido(int array[], int v);

int main()
{
    int arrayYerba[max];
    int v=0;

    int arrayPar[max];
    int vPar=0;

    Pila pilaImpar;
    inicpila(&pilaImpar);
    apilar(&pilaImpar,1);
    apilar(&pilaImpar,2);
    apilar(&pilaImpar,3);
    apilar(&pilaImpar,4);
    apilar(&pilaImpar,5);
    apilar(&pilaImpar,6);

    Pila valoresPlay;
    inicpila(&valoresPlay);
    int vPilaPlay=0;

    float peso= 1180.60;

    int promedio=0;
    int menor=0;

    //1
    vPilaPlay=cargarPilaPlay(&valoresPlay);
    printf("%d \n",vPilaPlay);
    printf("Valores play USD");
    mostrar(&valoresPlay);

    //2
    printf("Valores play PESOS");
    mostrarPreciosPeso(valoresPlay,peso);
    printf("\n");

    //3
    //porqe me pone un 1 ?
    printf("Array yerba: \n");
    cargarArrayYerbaRand(arrayYerba,&v);
    mostrarArrayYerba(arrayYerba,v);
    printf("\n");
    printf("Validos del array: %d \n",v);

    //4
    printf("Elementos invertidos: \n");
    mostrarArrayYerbaInvertido(arrayYerba,v);
    printf("\n");

    //5
    promedio=promedioArray(arrayYerba,v,promedio);
    printf("Promedio array: %d \n",promedio);
    //6
    eliminarMayoresPromedio(arrayYerba,&v,promedio);
    printf("Array con elementos eliminados: \n");
    printf("Validos nuevos del array: %d \n",v);
    mostrarArrayYerba(arrayYerba,v);

    //7
    printf("\n");
    printf("Pila con elemento menor eliminado:\n ");
    menor=menorElementoPila(&valoresPlay);
    mostrar(&valoresPlay);
    printf("Valor eliminado: %d",menor);

    //8
    printf("\n");
    printf("Pila original:\n");
    mostrar(&pilaImpar);
    printf("Arreglo con pares: \n");
    parImpar(arrayPar,&vPar,&pilaImpar);
    mostrarArrayYerba(arrayPar,vPar);
    printf("Pila impar:\n ");
    mostrar(&pilaImpar);
    printf("\n");


    system("PAUSE");
    return 0;
}

int cargarPilaPlay(Pila *pila )
{
    int dato;
    int v=0;
    char respuesta;

    do
    {
        printf("Ingrese valor usd para play,(entre 500 usd y 650 usd) \n");
        fflush(stdin);
        scanf("%d",&dato);

        if((dato>650) || (dato<500))
        {
            printf("Error, dato fuera de limites \n");
        }
        else
        {
            apilar(pila,dato);
            v++;
        }
        printf("Seguir ? s/n \n");
        fflush(stdin);
        scanf("%c",&respuesta);
    }
    while(respuesta!='n' && respuesta!='N' && v<500);

    return v;
}

void mostrarPreciosPeso (Pila origen, float peso)
{

    while(!pilavacia(&origen))
    {
        int dato=tope(&origen);
        float precio=(float)dato*peso;
        printf("$%.2f \n",precio);
        desapilar(&origen);
    }

}

void cargarArrayYerbaRand(int array[], int *v)
{
    srand(time(NULL));
    for(int i=0; i<max; i++)
    {
        int datoRand=rand()%(5500-3000+1)+3000;
        array[i]=datoRand;
        (*v)++;
    }
}

void mostrarArrayYerba(int array[], int v)
{
    for(int i =0; i<v; i++)
    {
        printf("$%d- ",array[i]);
    }
}

void mostrarArrayYerbaInvertido(int array[], int v)
{
    for(int i=v; i>0; i--)
    {
        printf("$%d- ",array[i]);


    }
}

int promedioArray(int array[],int v, int promedio)
{
    int suma=sumaElementosArray(array,v);
    promedio=suma/v;

    return promedio;
}

int sumaElementosArray(int array[], int v)
{
    int suma=0;
    for(int i =0; i<v; i++)
    {
        suma+=array[i];

    }
    return suma;
}


void eliminarMayoresPromedio(int array[],int *v,int promedio)
{
    Pila aux;
    inicpila(&aux);
    for(int i=0; i<*v; i++)
    {
        if(array[i]>promedio)
        {
            apilar(&aux,array[i]);
        }
        i++;
    }
    (*v)=0;
    while(!pilavacia(&aux))
    {
        int dato=tope(&aux);
        array[*v]=dato;
        desapilar(&aux);
        (*v)++;
    }
}

int menorElementoPila(Pila *pila)
{
    Pila aux;
    inicpila(&aux);

    int menor=tope(pila);

    while(!pilavacia(pila))
    {
        if(tope(pila)<menor)
        {
            menor=tope(pila);
        }
        apilar(&aux,desapilar(pila));
    }

    //armo sin el menor

    while(!pilavacia(&aux))
    {
        if(tope(&aux)!=menor)
        {
            apilar(pila,desapilar(&aux));
        }
        desapilar(&aux);
    }
    return menor;
}

int parImpar(int array[], int *v, Pila *pila){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila)){
        int dato=menorElementoPila(pila);
        if(dato % 2 == 0){
            array[*v]=dato;
            (*v)++;
        } else {
            apilar(&aux,dato);

        }
        desapilar(pila);
    }
    while(!pilavacia(&aux)){
        apilar(pila,desapilar(&aux));
    }

    return (*v)+1;

}
