#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIMENSION 100



// Prototipos de funciones
int menu();
int cargaArray(int array[], int v, int max_dim);
void muestraArreglo(int array[], int v);
int sumaElementosArray(int array[], int v);
void pasarArrayAPila(Pila *pila, int array[], int v);
int cargaArrayFloat(float array[], int v, int max_dim);
void muestraArregloFloat(float array[], int v);
float sumaElementosArrayFloat(float array[], int v);
int contieneCaracter(char array[], int v, char dato);
char encontrarMaximoCaracter (char array[], int v );
int intercalarArreglosOrdenados (char array1[],int a,char array2[],int b,char array3[],int v);

int main(int argc, char *argv[])
{
    int selected;

    Pila pila0;

    inicpila(&pila0);


    int arrayEnteros[DIMENSION];
    float arrayFloat[DIMENSION];
    char arrayChar[DIMENSION];
    int v = 0;

    char arrayCharCargado[DIMENSION] = {'a', 'c', 'e', 'g'};
    int validosCharCargado =4;

    int arrayEnterosCargado[DIMENSION]= {4,2,5,6,1};
    int validosEnterosCargado=5;

    char arrayCharCargado2[DIMENSION]= {'b','d','f','h','i'};
    int validosCharCargado2 = 5;

    int arrayVector[DIMENSION]= {1,5,6,7,8};
    int validosVector=5;

    char datoChar;
    char caracter;


    do
    {
        selected = menu();
        switch (selected)
        {
        case 1:
            v = cargaArray(arrayEnteros, v, DIMENSION);
            printf("\n");
            muestraArreglo(arrayEnteros, v);
            system("PAUSE");
            break;
        case 2:
            v = cargaArray(arrayEnteros, v, DIMENSION);
            printf("\n");
            muestraArreglo(arrayEnteros, v);
            system("PAUSE");
            break;
        case 3:
            v = cargaArray(arrayEnteros, v, DIMENSION);
            printf("\n");
            muestraArreglo(arrayEnteros, v);
            int suma=sumaElementosArray(arrayEnteros,v);
            printf("Suma de los elementos del array: %d \n",suma);
            system("PAUSE");
            break;
        case 4:
            v = cargaArray(arrayEnteros, v, DIMENSION);
            printf("\n");
            muestraArreglo(arrayEnteros, v);
            pasarArrayAPila(&pila0,arrayEnteros,v);
            printf("Pila: \n");
            mostrar(&pila0);
            system("PAUSE");
            break;
        case 5:
            v = cargaArrayFloat(arrayFloat,v,DIMENSION);
            printf("\n");
            muestraArregloFloat(arrayFloat, v);

            //porqe aca si pongo suma no anda ??

            float sumaFloat=sumaElementosArrayFloat(arrayFloat,v);
            printf("Suma de los elementos del array: %.2f \n",sumaFloat);

            system("PAUSE");
            break;
        case 6:
            v = cargaArrayChar(arrayChar,v,DIMENSION);
            //sacar dato por datoChar y preguntar qe es lo mas correcto
            char dato;
            muestraArregloChar(arrayChar, v);
            printf("Ingrese un caracter a buscar: ");
            scanf(" %c",&dato);
            if (contieneCaracter(arrayChar,v,dato))
            {
                printf("El dato %c se encuentra en el arreglo \n",dato);
            }
            else
            {
                printf("El dato %c NO se encuentra en el arreglo \n",dato);
            }
            system("PAUSE");
            break;
        case 7:
            muestraArregloChar(arrayCharCargado,validosCharCargado);
            printf("Ingrese un caracter a insertar en el arreglo \n");
            scanf(" %c",&datoChar);
            insertarOrdenadoChar(arrayCharCargado,&validosCharCargado,datoChar);
            printf("Arreglo con el caracter insertado: \n");
            muestraArregloChar(arrayCharCargado,validosCharCargado);
            system("PAUSE");
            break;
        case 8:
            caracter = encontrarMaximoCaracter(arrayCharCargado,validosCharCargado);
            printf("El maximo caracter del arreglo es: %c \n",caracter);

            system("PAUSE");
            break;
        case 9:
            v = cargaArray(arrayEnteros, v, DIMENSION);
            printf("\n");
            muestraArreglo(arrayEnteros, v);
            int esCapicua=esCapicuaArreglo(arrayEnteros,v);
            if (esCapicua==1)
            {
                printf("El array SI es capicua. \n");
            }
            else
            {
                printf("El array NO es capicua. \n");
            }

            system("PAUSE");
            break;
        case 10:
            printf("Arreglo antes de invertir; \n");
            muestraArregloChar(arrayCharCargado,validosCharCargado);
            invertirElementos(arrayCharCargado, validosCharCargado);
            printf("Arreglo invertido: \n");
            muestraArregloChar(arrayCharCargado,validosCharCargado);
            system("PAUSE");
            break;
        case 11:
            printf("Arreglo antes de ordenar por seleccion: \n");
            muestraArreglo(arrayEnterosCargado,validosEnterosCargado);
            ordenamientoSeleccion(arrayEnterosCargado,validosEnterosCargado);
            printf("Arreglo despues de ordenar: \n");
            muestraArreglo(arrayEnterosCargado,validosEnterosCargado);
            system("PAUSE");
            break;
        case 12:
            printf("Arreglo antes de ordenar por insercion: \n");
            muestraArreglo(arrayEnterosCargado,validosEnterosCargado);
            ordenamientoInsercion(arrayEnterosCargado,validosEnterosCargado);
            printf("Arreglo despues de ordenar por insercion: \n");
            muestraArreglo(arrayEnterosCargado,validosEnterosCargado);
            system("PAUSE");
            break;
        case 13:
            printf("Arreglo numero 1: \n");
            muestraArregloChar(arrayCharCargado,validosCharCargado);
            printf("Arreglo numero 2: \n");
            muestraArregloChar(arrayCharCargado2,validosCharCargado2);
            v = intercalarArreglosOrdenados(arrayCharCargado,validosCharCargado,arrayCharCargado2,validosCharCargado2,arrayChar,v);
            printf("Arreglo 1 y 2: \n");
            muestraArregloChar(arrayChar,v);
            system("PAUSE");
            break;
        case 14:
            printf("Arreglo vector:  /n");
            muestraArreglo(arrayVector,validosVector);
            v=acumuladoAnterior(arrayVector,validosVector,arrayEnteros,v);
            printf("Arreglo acumulado");
            muestraArreglo(arrayEnteros,v);
            system("PAUSE");
            break;
        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        default:
            printf("\nOpci�n no v�lida. Intente nuevamente.\n");
            system("PAUSE");
            break;
        }
    }
    while (selected != 0);
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
    printf("\n1- Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros y permita que el usuario ingrese valores al mismo por teclado.");
    printf("\n2- Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y los muestre por pantalla.");
    printf("\n3- Hacer una funci�n que reciba como par�metro un arreglo y la cantidad de elementos (v�lidos) cargados en �l y calcule la suma de sus elementos.");
    printf("\n4- Hacer una funci�n que reciba como par�metro un arreglo, la cantidad de elementos (v�lidos) cargados en �l y una Pila. La funci�n debe copiar los elementos del arreglo en la pila.");
    printf("\n5- Realizar una funci�n que sume los elementos de un arreglo de n�meros reales (float) de dimensi�n 100. (se recomienda hacer una funci�n para cargar y otra para mostrar para este tipo de dato asociado al arreglo).");
    printf("\n6- Realizar una funci�n que indique si un elemento dado se encuentra en un arreglo de caracteres.");
    printf("\n7- Realizar una funci�n que inserte un car�cter en un arreglo ordenado alfab�ticamente, conservando el orden.");
    printf("\n8- Realizar una función que obtenga el máximo carácter de un arreglo dado.");
    printf("\n9- Realizar una función que determine si un arreglo es capicúa.");
    printf("\n10- Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar).");
    printf("\n11- Ordenamiento por Seleccion.");
    printf("\n12- Ordenamiento por Inserción.");
    printf("\n13- Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.");
    printf("\n14- Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.");
    printf("\n0- SALIR");
    printf("\n\nIngrese su elecci�n: ");
    scanf("%d", &input);
    return input;
}

int cargaArray(int array[], int v, int max_dim)
{
    char respuesta;
    do
    {

        printf("Ingrese un valor al arreglo, en la posicion a[%d]: ", v);
        scanf("%d", &array[v]);
        v++;
        printf("\nDesea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c", &respuesta);
    }
    while ((respuesta == 's' || respuesta == 'S') && v < max_dim);

    return v;
}

void muestraArreglo(int array[], int v)
{

    printf("Su arreglo:\n");

    for (int i = 0; i < v; i++)
    {
        printf("%d | ", array[i]);
    }
    printf("\n");
}

int sumaElementosArray (int array[], int v)
{
    int suma=0;
    for (int i=0; i<v; i++)
    {
        suma=suma+array[i];
    }

    return suma;
}

void pasarArrayAPila (Pila *pila, int array[], int v)
{

    for (int i=0; i<v; i++)
    {
        apilar(pila, array[i]);
    }

}

int cargaArrayFloat(float array[], int v, int max_dim)
{
    char respuesta;
    do
    {
        printf("Ingrese un valor al arreglo, en la posicion a[%d]: ", v);
        fflush(stdin);
        scanf("%f", &array[v]);
        v++;
        printf("\nDesea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c", &respuesta);
    }
    while ((respuesta == 's' || respuesta == 'S') && v < max_dim);

    return v;
}

void muestraArregloFloat(float array[], int v)
{
    printf("Su arreglo:\n");

    for(int i=0; i<v; i++)
    {
        printf("%.2f | ", array[i]);
    }
    printf("\n");
}

float sumaElementosArrayFloat(float array[], int v)
{
    float suma=0;

    for(int i=0; i<v; i++)
    {
        suma=suma+array[i];
    }
    return suma;
}

int cargaArrayChar(char array[], int v, int max_dim)
{
    char respuesta;

    do
    {
        printf("Ingrese un valor al arreglo, en la posicion a[%d]: ", v);
        fflush(stdin);
        scanf("%c", &array[v]);
        v++;
        printf("\nDesea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c", &respuesta);

    }
    while((respuesta=='s' || respuesta=='S') && v<max_dim);

    return v;
}

void muestraArregloChar (char array[], int v)
{
    printf("Su arreglo: \n");

    for (int i=0; i<v; i++)
    {
        printf("%c | ", array[i]);
    }
    printf("\n");
}


int contieneCaracter(char array[], int v, char dato)
{
    int flag=0;
    for (int i=0; i<v; i++)
    {
        if (array[i]== dato)
        {
            flag=1;
        }
    }

    return flag;
}


void insertarOrdenadoChar(char array[], int *v, char dato)
{
    //encontrar la posicion adecuada
    int i=0;
    while(i<*v && array[i]<dato)
    {
        i++;
    }
    //Mover los elementos a la derecha

    for(int j = *v - 1; j >= i; j--)
    {
        array[j + 1] = array[j];
    }
    array[i]=dato;
    (*v)++;
}

char encontrarMaximoCaracter (char array[], int v )
{
    char caracterMaximo=array[0];

    for(int i=0; i<v; i++)
    {
        if (caracterMaximo<array[i])
        {
            caracterMaximo=array[i];
        }
    }

    return caracterMaximo;
}

int esCapicuaArreglo (int array[], int v)
{
    int flag=0;

    for(int i=0; i<v/2; i++)
    {
        if (array[i]==array[v-1-i])
        {
            flag=1;
        }
    }

    return flag;
}

void invertirElementos (int array[], int v)
{

    for (int i=0; i<v/2; i++)
    {
        char temp = array[i];
        array[i]=array[v-1-i];
        array[v-1-i]=temp;
    }
}

void ordenamientoSeleccion (int array[], int v )
{
    int posMenor;
    int i=0;
    int aux;

    while(i<v-1)
    {
        posMenor=posicionMenor(array,v,i);
        aux=array[posMenor];
        array[posMenor]=array[i];
        array[i]=aux;
        i++;
    }
}

int posicionMenor (int array[], int v, int pos)
{
    int menor=array[pos];
    int posMenor=pos;
    //emepzamos desde la siguiente posicion
    int i=pos+1;


    while (i<v)
    {
        if (menor>array[i])
        {
            menor = array[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenamientoInsercion (int array[], int v)
{

    int u=0; //inicio

    while(u<v-1)
    {
        insertar(array,u,array[u+1]);
        u++; //luego de insertar aumenta el inicio +1
    }
}

void insertar (int array[], int u, int dato)
{
    int i=u; //ahora i es el inicio, qe va a ir disminuyendo

    while(i>=0 && dato<array[i])
    {
        array[i+1]=array[i];
        i--;
    }
    array[i+1]=dato;

}

int intercalarArreglosOrdenados (char array1[],int a,char array2[],int b,char array3[],int v)
{
    int i = 0;
    int j = 0;

    while (i<a && j<b)
    {
        if (array1[i]<array2[j])
        {
            array3[v++]=array1[i++];
        }
        else
        {
            array3[v++]=array2[j++];
        }
    }
    // Por si quedan elementos en alguno de los dos arrays, dado qe el while de arriba corta cuadno alguno de los 2 se queda sin datos
    while (i < a)
    {
        array3[v++] = array1[i++];
    }

    while (j < b)
    {
        array3[v++] = array2[j++];
    }


    return v;
}

int acumuladoAnterior (int array[], int v, int arrayAcumulado[], int validosAcumulado)
{

    int u=v-1;
    int a = 0 ;

    while(u>=0)
    {
        a = 0;
        for (int i = 0; i<=u; i++)
        {

            a+=array[i];
        }
    arrayAcumulado[u]=a;
    u--;
    validosAcumulado++;
    }

    return validosAcumulado;
}

