#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main(int argc, char *argv[])
{
    int selected;
    int numeroEntero;
    int factorial;
    int potencia;
    int base;
    int exponente;

    int arregloEnteros[MAX]= {4,3,2,1,2,3,4};
    int vEnteros=7;
    int flag;
    int suma;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            printf("Ingrese base:");
            scanf("%d",&numeroEntero);
            factorial=factorialRecursivo(numeroEntero);
            printf("!%d=%d\n",numeroEntero,factorial);
            system("PAUSE");
            break;
        case 2:
            printf("Ingrese base:");
            scanf("%d",&base);
            printf("Ingrese exponente:");
            scanf("%d",&exponente);
            potencia=potenciaRecursivo(base, exponente);
            printf("%d^%d=%d\n",base,exponente,potencia);
            system("PAUSE");
            break;
        case 3:
            printf("El arreglo de forma iterativa:\n");
            mostrarArregloIterativo(arregloEnteros,vEnteros);
            printf("El arreglo de forma recursiva:\n");
            muestraArregloRecursivo(arregloEnteros,vEnteros,0);
            system("PAUSE");
            break;
        case 4:
            printf("Arreglo:\n");
            mostrarArregloIterativo(arregloEnteros,vEnteros);
            printf("Arreglo invertido recursivo:\n");
            mostrarArregloInvertidoRecursivo(arregloEnteros,vEnteros,0);
            system("PAUSE");
            break;
        case 5:
            flag=capicuaRecursivo(arregloEnteros,0,vEnteros);
            if(flag==1)
            {
                printf("El arreglo es capicua:\n");
                mostrarArregloIterativo(arregloEnteros,vEnteros);
            }
            else
            {
                printf("El arreglo NO es capicua:\n");
                mostrarArregloIterativo(arregloEnteros,vEnteros);
            }
            system("PAUSE");
            break;
        case 6:
            printf("Arreglo:\n");
            mostrarArregloIterativo(arregloEnteros,vEnteros);
            suma=sumaArregloRecursivo(arregloEnteros,vEnteros,0);
            printf("Suma = %d",suma);
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
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1- Calcular el factorial de un número en forma recursiva.");
    printf("\n2- Calcular la potencia de un número en forma recursiva.");
    printf("\n3- Recorrer un arreglo y mostrar sus elementos en forma recursiva.");
    printf("\n4- Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).");
    printf("\n5- Verificar si el arreglo es capicua (recursivo).");
    printf("\n6- Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}

int factorialRecursivo(int num)
{
    int rta=0;
    if(num==0)
    {
        rta=1;
    }
    else
    {
        rta=num*factorialRecursivo(num-1);
    }
    return rta;
}

int potenciaRecursivo(int base, int exponente)
{
    int rta=0;
    if(exponente==0)
    {
        rta=1;
    }
    else
    {
        rta=base*potenciaRecursivo(base,exponente-1);
    }

    return rta;
}
void mostrarArregloIterativo(int array[], int v)
{
    printf("Contenido del arreglo (%d elementos):\n[", v);

    for(int i = 0; i < v; i++)
    {
        printf("%d", array[i]);
        if(i < v - 1)
        {
            printf(", ");
        }
    }

    printf("]\n");
}

void muestraArregloRecursivo(int array[], int v,int i)
{
    if(i<v)
    {
        printf("%d | ", array[i]);
        muestraArregloRecursivo(array,v,i+1);
    }
}
void mostrarArregloInvertidoRecursivo(int array[], int v, int i)
{
    if(i < v)
    {
        mostrarArregloInvertidoRecursivo(array, v, i + 1);
        printf("%d | ", array[i]);
    }
}

int capicuaRecursivo(int array[],int i, int j)
{
    int rta;
    if(i<j)
    {
        if(array[i]==array[j])
        {
            rta=capicuaRecursivo(array,i+1,j-1);
        }
        else
        {
            rta=0;
        }

    }
    else
    {
        rta=1;
    }
    return rta;
}

int sumaArregloRecursivo(int array[],int v, int i)
{
    int suma=0;
    if(i<v){
        suma=array[i]+sumaArregloRecursivo(array,v,i+1);
    }
    return suma;
}
