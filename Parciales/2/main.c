#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define DIMENSION 24

float promedioTemperaturas(int array[], int v);
void cargarPilaBajoPromedio(int array[], int v,float promedio, Pila*pila);
int main(int argc, char *argv[])
{
    int selected;

    int arrayTemperaturas[DIMENSION];
    int v=0;

    float promedio=0;

    Pila pila;
    inicpila(&pila);
    int tempMinimaPila=0;
    int posMaximaArray=0;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            cargaTemperatura(arrayTemperaturas,&v);
            mostrarTemperaturas(arrayTemperaturas,v);
            promedio=promedioTemperaturas(arrayTemperaturas,v);
            printf("Promedio de temperaturas: %.2f \n",promedio);
            cargarPilaBajoPromedio(arrayTemperaturas,v,promedio,&pila);
            printf("Pila cargada con las temperaturas menores al promedio: %.2f",promedio);
            mostrar(&pila);
            tempMinimaPila=buscarTemperaturaMinimaEnPila(pila);
            printf("Temperatura min de la pila: %d \n",tempMinimaPila);

            posMaximaArray=posicionTemperaturaMaxima(arrayTemperaturas,v);
            printf("Posicion de la temperatura maxima del arreglo: %d \n",posMaximaArray);



            system("PAUSE");
            break;
        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");

            break;
        }

    }
    while(selected!=0);

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
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}

void cargaTemperatura(int array[], int*v)
{

    char respuesta;
    int dato;

    do
    {
        printf("Ingrese una temperatura en la hora %d:00 hs: ",*v);
        scanf("%d",&dato);
        if(dato>60 || dato<-45)
        {
            printf("Dato fuera de los parametros -45 y 60\n");
            printf("Ingrese nuevamente\n");
        }
        else
        {
            array[*v]=dato;
            (*v)++;
        }

        if (*v >= DIMENSION)
        {
            printf("Limite alcanzado.\n");
            break;
        }

        printf("Desea continuar? s/n");
        scanf(" %c",&respuesta);
    }
    while(respuesta!='n'&& respuesta!='N'&& *v<DIMENSION);

}

void mostrarTemperaturas(int array[], int v)
{
    printf("Temperaturas ([%d] totales)\n",v);
    for(int i=0; i<v; i++)
    {
        printf("[%d] - ",array[i]);
        if((i+1)%8 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

float promedioTemperaturas(int array[], int v){
    float promedio=0;
    int suma=sumaTemperaturas(array,v);
    promedio=(float)suma/v;

    return promedio;
}

int sumaTemperaturas(int array[], int v){
    int suma=0;

    for(int i=0;i<v;i++){
        suma+=array[i];
    }

    return suma;
}

void cargarPilaBajoPromedio(int array[], int v,float promedio, Pila*pila){
    for(int i=0;i<v;i++){
        if (array[i]<promedio){
            apilar(pila,array[i]);
        }
    }

}

int buscarTemperaturaMinimaEnPila(Pila pila){
    int menor=tope(&pila);
    while(!pilavacia(&pila)){
        if(tope(&pila)<menor){
            menor=tope(&pila);
        }
        desapilar(&pila);
    }
    return menor;
}

int posicionTemperaturaMaxima(int array[],int v){
    int pos=0;
    int mayor=array[0];

    for(int i=1;i<v;i++){
        if(array[i]>mayor){
            mayor = array[i];
            pos=i;
        }
    }
    return pos;
}
