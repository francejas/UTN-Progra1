#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pila.h"

// Prototipos de funciones
int menu();
void cargarPILA(Pila *pila);
void pasarPILA(Pila *origen);
void pasarPilaOrdenada(Pila *origen);
int encontrarMenor (Pila *pila);
void ordenamientoSeleccion (Pila *origen);
int encontrarMenorElemento (Pila *pila);
void ordenamientoInsercion(Pila *pila);
void insertarElemento(Pila *pila, int dato);
int sumaTopeAnterior (Pila pila);
float promedioPila(Pila pila);
int sumaElementosPila(Pila pila);
int cantidadElementos(Pila pila);
float division (float a, float b);
int convertirPilaADecimal (Pila pila);

int main(int argc, char *argv[]) {
    int selected;
    Pila pila0,pilaOrdenadaMayorAMenor,pilaOrdenadaMenorAMayor;

    inicpila(&pila0);
    inicpila(&pilaOrdenadaMayorAMenor);
    inicpila(&pilaOrdenadaMenorAMayor);

    apilar(&pilaOrdenadaMayorAMenor,6);
    apilar(&pilaOrdenadaMayorAMenor,4);
    apilar(&pilaOrdenadaMayorAMenor,3);
    apilar(&pilaOrdenadaMayorAMenor,1);

    apilar(&pilaOrdenadaMenorAMayor,1);
    apilar(&pilaOrdenadaMenorAMayor,3);
    apilar(&pilaOrdenadaMenorAMayor,4);
    apilar(&pilaOrdenadaMenorAMayor,6);


    do {
        selected = menu();
        switch (selected) {
            case 1:
                inicpila(&pila0);
                cargarPILA(&pila0);
                system("PAUSE");
                break;
            case 2:
                inicpila(&pila0);
                cargarPILA(&pila0);
                pasarPILA(&pila0);
                system("PAUSE");
                break;
            case 3:
                inicpila(&pila0);
                cargarPILA(&pila0);
                pasarPilaOrdenada(&pila0);
                system("PAUSE");
                break;
            case 4:
                inicpila(&pila0);
                cargarPILA(&pila0);
                int menorElemento = encontrarMenor(&pila0);
                printf("El menor elemento es: %d \n", menorElemento);
                printf("La pila sin el menor elemento es: \n");
                mostrar(&pila0);
                system("PAUSE");
                break;
            case 5:
                inicpila(&pila0);
                cargarPILA(&pila0);
                ordenamientoSeleccion(&pila0);
                /*
                printf("Pila origen:");
                mostrar(&pila0);
                */
                system("PAUSE");
                break;
            case 6:
                printf("Pila ordenada de Menor a Mayor");
                mostrar(&pilaOrdenadaMenorAMayor);
                int dato;
                printf("Ingrese un dato a insertar en la pila: ");
                scanf("%d", &dato);
                insertarElemento(&pilaOrdenadaMenorAMayor, dato);
                printf("Pila con el nuevo elemento insertado:\n");
                mostrar(&pilaOrdenadaMenorAMayor);
                system("PAUSE");
                break;
            case 7:
                inicpila(&pila0);
                cargarPILA(&pila0);
                ordenamientoInsercion(&pila0);
                printf("Pila ordenada por insercion:");
                mostrar(&pila0);
                system("PAUSE");
                break;
            case 8:
                inicpila(&pila0);
                cargarPILA(&pila0);
                int suma=sumaTopeAnterior(pila0);
                printf("La suma del tope y la base de la pila es: %d \n",suma);
                system("PAUSE");
                break;
            case 9:
                inicpila(&pila0);
                cargarPILA(&pila0);
                float promedio=promedioPila(pila0);
                printf("El promedio de los elementos de la pila es: %.2f\n", promedio);
                system("PAUSE");
                break;
            case 10:
                inicpila(&pila0);
                cargarPILA(&pila0);
                int numeroDecimal=0;
                numeroDecimal = convertirPilaADecimal(pila0);
                printf("Pila a decimal: %d \n", numeroDecimal);
                system("PAUSE");
                break;
            case 0:
                printf("\n\nTERMINATE THE PROGRAM\n");
                break;
            default:
                printf("\nOpción no válida. Intente nuevamente.\n");
                system("PAUSE");
                break;
        }
    } while (selected != 0);

    return 0;
}


int menu() {
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1- Ingresar varios elementos en una pila (cantidad indefinida por usuario).");
    printf("\n2- Hacer una función que pase todos los elementos de una pila a otra.");
    printf("\n3- Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.");
    printf("\n4- Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.");
    printf("\n5- Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección).");
    printf("\n6- Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.");
    printf("\n7- Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción).");
    printf("\n8- Hacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.");
    printf("\n9- Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.");
    printf("\n10- Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal.");
    printf("\n0- SALIR");
    printf("\n\nIngrese su elección: ");
    scanf("%d", &input);
    return input;
}

void cargarPILA(Pila *pila){
    char respuesta;
    int dato;
    do {
        printf("\n Ingrese un numero  para la pila: \n");
        fflush(stdin);
        scanf("%d", &dato);
        apilar(pila,dato);
        printf("\n Desea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c",&respuesta);
    } while (respuesta == 's' || respuesta == 'S');

    printf("\n Elementos en la pila después de la carga:\n");
    mostrar(pila);  // Mostrar la pila después de la carga
}


void pasarPILA(Pila *origen){
    Pila destino;
    inicpila(&destino);

    printf("Pila origen antes:\n");
    mostrar(origen);

    while (!pilavacia(origen)) {
        apilar(&destino, desapilar(origen));
    }
    printf("Pila destino:\n");
    mostrar(&destino);

    printf("Pila origen despues:\n");
    mostrar(origen);
}

void pasarPilaOrdenada(Pila *origen){
    Pila destino, aux;

    inicpila(&destino);
    inicpila(&aux);

    printf("Pila origen antes:\n");
    mostrar(origen);

    while (!pilavacia(origen)){
        apilar(&aux, desapilar(origen));
    }
    while(!pilavacia(&aux)){
        apilar(&destino, desapilar(&aux));
    }
    printf("Pila destino:\n");
    mostrar(&destino);

    printf("Pila origen despues:\n");
    mostrar(origen);
}

int encontrarMenor (Pila *pila){
    Pila aux;
    inicpila(&aux);
    int menor=tope(pila);

    //encontrar el menor
    while(!pilavacia(pila)) {
        if (tope(pila)<menor){
            menor=tope(pila);
        }
        apilar(&aux, desapilar(pila));
    }


   // Reconstruir la pila SIN el menor
    while (!pilavacia(&aux)) {
        if (tope(&aux) != menor) {  // Solo apilar si NO es el menor
            apilar(pila, desapilar(&aux));
        } else {
            desapilar(&aux);  // Eliminar el menor
        }
    }


    return menor; // Devuelve el menor eliminado
}

// ORDENA DE MAYOR A MENOR
void ordenamientoSeleccion (Pila *origen){
    Pila destino;
    inicpila (&destino);

    while(!pilavacia(origen)){
        int elemento=encontrarMenor(origen);
        apilar(&destino, elemento);
    }
    printf("Pila destino ordenada:");
    mostrar(&destino);

    //paso elementos a la pila original
    printf("PASO DE DESTINO A ORIGEN: ");
    while (!pilavacia(&destino)) {
        apilar(origen, desapilar(&destino));
    }
    printf("Pila destino:\n");
    mostrar(&destino);
    printf("Pila origen:");
    mostrar(origen);
}

void insertarElemento(Pila *pila, int dato) {
    Pila aux;
    inicpila(&aux);

    //tope(pila) > dato FUNCIONA SOLO CON PILAS ORDENADAS DE MENOR A MAYOR.
    //tope(pila) < dato FUNCIONA SOLO CON PILAS ORDENADAS DE MAYOR A MENOR.
    // SI LE  PASO A ESTA FUNCION  UN A PILA DESORDENADA, APILA EN PILA EL MENOR ELEMTO.
    while (!pilavacia(pila) && tope(pila) > dato) {
        apilar(&aux, desapilar(pila));
    }

    apilar(pila, dato);

    while (!pilavacia(&aux)) {
        apilar(pila, desapilar(&aux));
    }
}

//ordena de mayor a menor
void ordenamientoInsercion(Pila *pila){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila)){
        int dato=desapilar(pila);
        insertarElemento(&aux,dato);
    }
    while(!pilavacia(&aux)){
        apilar(pila, desapilar(&aux));
    }
}

int sumaTopeAnterior (Pila pila){
    int a,b;
    a = desapilar(&pila);

    while(!pilavacia(&pila)){
        b = desapilar(&pila);
    }

    return a+b;
}

float promedioPila(Pila pila) {
    int suma = sumaElementosPila(pila);
    int n = cantidadElementos(pila);
    //convierto suma y n en float , no entiendo muy bien porqe
    float promedio = division((float)suma,(float)n);

    return promedio;
}

int sumaElementosPila(Pila pila){
     int suma=0;
     while(!pilavacia(&pila)) {
        suma+=desapilar(&pila);
     }

    return suma;
}

int cantidadElementos(Pila pila){
    int n=0;

    while(!pilavacia(&pila)){
        desapilar(&pila);
    n++;
    }

    return n;

}

float division (float a, float b){
    float cociente = a/b;

    return cociente;
}


int convertirPilaADecimal (Pila pila){
    int n=cantidadElementos(pila);
    int decimal=0;

    //aca hay un problema
    while(!pilavacia(&pila)){
     for (int i=n-1;i>=0;i--){
        decimal+=tope(&pila) * (int)pow(10, i);
        desapilar(&pila);
    }
}

    return decimal;
}


