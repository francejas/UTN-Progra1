#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 60
#define COLUMNS 60



// Prototipos de funciones
void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas);
void mostrarMatrizEnteros(int matriz[ROWS][COLUMNS], int filas, int columnas);
float promedioMatrizEnteros (int matriz[ROWS][COLUMNS], int filas, int columnas);
int buscarElementoEnMatriz(int matriz[ROWS][COLUMNS], int filas, int columnas, int dato);
int buscarElementoArrayString (char array[ROWS][COLUMNS], int cantidadPalabras, char dato[]);
int menu();

int main(int argc, char *argv[])
{
    int selected;

    int matrizEnterosVacia[ROWS][COLUMNS];
    int filas = 0;
    int columnas = 0;

    int matrizEnterosCargada[ROWS][COLUMNS]=
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int filasEnterosCargada=3;
    int columnasEnterosCargada=4;

    char arrayPalabrasVacio[ROWS][COLUMNS];
    int cantPalabras=0;

    char arrayPalabrasCargado[ROWS][COLUMNS]= {"hola","chau","gato","perro"};
    int cantPalabrasCargado=4;

    int matriz2x2[ROWS][COLUMNS]=
    {
        {2,4},
        {1,2}
    };
    int filasMatriz2x2=2;
    int columMatriz2x2=2;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            cargaMatrizEnteros(matrizEnterosVacia, &filas, &columnas);
            system("PAUSE");
            break;
        case 2:
            cargaMatrizEnteros(matrizEnterosVacia, &filas, &columnas);
            mostrarMatrizEnteros(matrizEnterosVacia, filas, columnas);
            system("PAUSE");
            break;
        case 3:
            cargaMatrizEnterosRandom(matrizEnterosVacia,&filas, &columnas);
            mostrarMatrizEnteros(matrizEnterosVacia, filas, columnas);
            system("PAUSE");
            break;
        case 4:
        {
            mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            int suma = sumarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            printf("La suma de todos los elementos de la matriz es: %d\n", suma);  // A�adir %d para mostrar el valor
            system("PAUSE");
        }
        break;
        case 5:
        {
            mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            float promedio = promedioMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            printf("Promedio de los elementos de la matriz: %.2f \n",promedio);
            system("PAUSE");
        }
        break;
        case 6:
        {
            int dato=0;
            printf("Ingrese un dato a buscar en la matriz: ");
            scanf("%d",&dato);
            if(buscarElementoEnMatriz(matrizEnterosCargada,filasEnterosCargada,columnasEnterosCargada,dato))
            {
                printf("El elemento: %d se encuentra en la matriz. \n",dato);
                mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            }
            else
            {
                printf("El elemento: %d NO se encuentra en la matriz. \n",dato);
                mostrarMatrizEnteros(matrizEnterosCargada, filasEnterosCargada, columnasEnterosCargada);
            }
            system("PAUSE");
        }
        break;
        case 7:
        {
            cargarArrayStings(arrayPalabrasVacio,&cantPalabras);
            system("PAUSE");
        }
        break;
        case 8:
            cargarArrayStings(arrayPalabrasVacio,&cantPalabras);
            mostrarArrayPalabras(arrayPalabrasVacio,cantPalabras);
            system("PAUSE");
            break;
        case 9:
        {
            char dato[COLUMNS];
            printf("Ingrese una palabra a buscar: ");
            scanf("%s", dato);

            int respuesta = buscarElementoArrayString(arrayPalabrasCargado, cantPalabrasCargado, dato);
            if(respuesta == -1)
            {
                printf("La palabra %s NO se encuentra en el arreglo: \n", dato);
                mostrarArrayPalabras(arrayPalabrasCargado, cantPalabrasCargado);
            }
            else
            {
                printf("La palabra '%s' se encuentra en el arreglo en la posicion %d: \n", dato, respuesta);
                mostrarArrayPalabras(arrayPalabrasCargado, cantPalabrasCargado);
            }
            system("PAUSE");
        }
        break;
        case 10:
        {

            system("PAUSE");
        }
        break;
        case 11:
        {
            printf("Arreglo desordenado: \n");
            mostrarArrayPalabras(arrayPalabrasCargado, cantPalabrasCargado);
            printf("Arreglo ordenado por Insercion: \n");
            ordenarPalabrasInsercion(arrayPalabrasCargado,cantPalabrasCargado);
            mostrarArrayPalabras(arrayPalabrasCargado, cantPalabrasCargado);
            system("PAUSE");
        }
        break;
        case 12:
            printf("Determinante de la matriz 2x2 \n");
            mostrarMatrizEnteros(matriz2x2,filasMatriz2x2,columMatriz2x2);
            int determinante=determinanteMatriz2x2(matriz2x2,filasMatriz2x2,columMatriz2x2);
            printf("Determinante: %d \n",determinante);
            system("PAUSE");
            break;
        case 13:
            printf("La matriz: \n");
            mostrarMatrizEnteros(matriz2x2,filasMatriz2x2,columMatriz2x2);
            int inversa=tieneInversa(matriz2x2,filasMatriz2x2,columMatriz2x2);

            if (inversa==-1){
                printf("La matriz NO tiene inversa \n");
            }else
            printf("La matriz tiene inversa \n");

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
    printf("\n1-Hacer una funci�n que reciba como par�metro una matriz de n�meros enteros y permita que el usuario ingrese valores al mismo por teclado. La funci�n debe cargar la matriz por completo.");
    printf("\n2- Hacer una funci�n que reciba como par�metro una matriz de n�meros enteros y la muestre por pantalla (en formato matricial).");
    printf("\n3- Hacer una funci�n que reciba como par�metro una matriz de n�meros enteros y que cargue la misma con n�meros aleatorios (sin intervenci�n del usuario). La funci�n debe cargar la matriz por completo.");
    printf("\n4- Hacer una funci�n tipo int que sume el contenido total de una matriz de n�meros enteros.");
    printf("\n5- Hacer una funci�n tipo float que calcule el promedio de una matriz de n�meros enteros.");
    printf("\n6- Hacer una funci�n que determine si un elemento se encuentra dentro de una matriz de n�meros enteros. La funci�n recibe la matriz y el dato a buscar.");
    printf("\n7- Hacer una funci�n que cargue un arreglo de palabras (strings). La funci�n debe retornar cuantas palabras se cargaron.  (puede ser a trav�s del par�metro como puntero).");
    printf("\n8- Hacer una funci�n que muestre un arreglo de palabras.");
    printf("\n9- Hacer una funci�n que determine si un string se encuentra dentro de un arreglo de strings. La funci�n recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar. ///devuelve el �ndice de la fila en que se encuentra, de lo contrario retorna -1.");
    printf("\n10- Hacer una función que determine si un string se encuentra dentro de un arreglo de strings ordenado alfabéticamente. La función recibe el arreglo, la cantidad de palabras que contiene y el string a buscar.  ///devuelve el índice de la fila en que se encuentra, de lo contrario retorna -1");
    printf("\n11- Hacer una función (o varias) que ordene un arreglo de palabras por orden alfabético. (Por selección o inserción, el que más te guste).");
    printf("\n12- Hacer una función que retorne el determinante de una matriz de 2x2.");
    printf("\n13- Función que verifique si una matriz de 2x2 tiene inversa.");
    printf("\n0- SALIR");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);

    return input;
}



/*
void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas)
{
    char opcion;
    int valor;
    int resultado;

    // Inicializar filas y columnas a 0
    *filas = 0;
    *columnas = 0;

    printf("Ingrese un valor para cargar la matriz \n");
    printf("Ingrese f para crear una nueva fila \n");
    printf("Ingrese n/N para terminar la carga \n");

    do
    {
        printf("Fila [%d] Columna [%d]: ", *filas, *columnas);

        // Intentar leer un n�mero entero
        resultado = scanf("%d", &valor);

        if (resultado == 1)
        {
            // Se ley� un n�mero correctamente
            matriz[*filas][*columnas] = valor;
            (*columnas)++;

            // Verificar si se alcanz� el l�mite de columnas
            if (*columnas >= COLUMNS)
            {
                printf("Se alcanz� el l�mite de columnas. Pasando a la siguiente fila.\n");
                (*filas)++;
                *columnas = 0;
            }
        }
        else
        {
            // Limpiar el buffer de entrada
            while(getchar() != '\n');

            printf("Ingrese 'f' para nueva fila, 'n' para terminar: ");
            opcion = getchar();
            while(getchar() != '\n'); // Limpiar el buffer despu�s de leer el car�cter

            if (opcion == 'f' || opcion == 'F')
            {
                // Crear nueva fila solo si hay datos en la fila actual
                if (*columnas > 0)
                {
                    (*filas)++;
                    *columnas = 0;
                    printf("Nueva fila iniciada.\n");
                }
                else
                {
                    printf("La fila actual est� vac�a. Ingrese al menos un valor.\n");
                }
            }
            else if (opcion == 'n' || opcion == 'N')
            {
                printf("Carga de matriz finalizada.\n");
                // Si hay datos en la �ltima fila, incrementar filas para contar correctamente
                if (*columnas > 0) {
                    (*filas)++;
                    *columnas = 0;
                }
                break;
            }
            else
            {
                printf("Opci�n no reconocida. Ingrese un n�mero, 'f' o 'n'.\n");
            }
        }
    }
    while (*filas < ROWS);

    // Verificar si se alcanzaron los l�mites
    if (*filas >= ROWS)
    {
        printf("Se alcanz� el l�mite de la matriz. Carga finalizada.\n");
    }
}
*/



void cargaMatrizEnteros(int matriz[ROWS][COLUMNS], int *filas, int *columnas)
{
    printf("Ingrese dimension de la matriz a cargar \n");
    printf("Filas: ");
    scanf("%d", filas);
    printf("Columnas: ");
    scanf("%d", columnas);

    for(int i = 0; i < *filas; i++)
    {
        for(int j = 0; j < *columnas; j++)
        {
            printf("Fila[%d] Columna[%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


void mostrarMatrizEnteros(int matriz[ROWS][COLUMNS], int filas, int columnas)
{
    printf("Matriz [%d x %d]:\n", filas, columnas);

    for (int i = 0; i < filas; i++)
    {
        printf("| ");
        for (int j = 0; j < columnas; j++)
        {
            printf("%4d ", matriz[i][j]); // %4d para alinear los n�meros
        }
        printf("|\n");
    }
}
void cargaMatrizEnterosRandom(int matriz[ROWS][COLUMNS], int *filas, int *columnas)
{
    // Inicializar la semilla para n�meros aleatorios
    srand(time(NULL));

    printf("Ingrese la dimension de la matriz a cargar: \n");
    printf("Filas: ");
    scanf("%d", filas);
    printf("Columnas: ");
    scanf("%d", columnas);

    for(int i = 0; i < *filas; i++)
    {
        for(int j = 0; j < *columnas; j++)
        {
            matriz[i][j] = rand() % 11;  // Genera n�meros entre 0 y 10
        }
    }
}

int sumarMatrizEnteros (int matriz[ROWS][COLUMNS], int filas, int columnas)
{
    int suma=0;

    for (int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            suma+=matriz[i][j];
        }
    }

    return suma;
}

float promedioMatrizEnteros (int matriz[ROWS][COLUMNS], int filas, int columnas)
{

    float suma=sumarMatrizEnteros(matriz,filas,columnas);

    float promedio=suma/(filas*columnas) ;



    return promedio;
}

int buscarElementoEnMatriz(int matriz[ROWS][COLUMNS], int filas, int columnas, int dato)
{
    int flag=0;

    for(int i =0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            if (dato==matriz[i][j])
            {
                flag=1;
            }
        }
    }


    return flag;
}

// COLUMNS es la cantidad de caracteres
int cargarArrayStings(char array[ROWS][COLUMNS], int *cantPalabras)
{
    // Definir tama�o del arreglo, va a guardar una palabra y COLUMNS es el maximo de caracteres
    char palabra[COLUMNS];
    *cantPalabras = 0; // Inicializar contador

    do
    {
        printf("Ingrese palabras (escriba 'fin' para terminar):\n");
        printf("Palabra %d: ", *cantPalabras + 1);
        scanf("%s", palabra); // No necesita & para arreglos

        // Verificar si el usuario quiere terminar
        if (strcmp(palabra, "fin") == 0)
        {
            break;
        }

        if (strlen(palabra) >= COLUMNS)
        {
            printf("Exceso de caracteres, vuelva a ingresar\n");
        }
        else if (strlen(palabra) == 0)
        {
            printf("No ingreso ninguna palabra\n");
        }
        else
        {
            // Copiar la palabra al arreglo
            strcpy(array[*cantPalabras], palabra);
            (*cantPalabras)++;
        }
    }
    while (*cantPalabras < ROWS);

    return *cantPalabras; // Retornar cantidad de palabras cargadas
}

void mostrarArrayPalabras(char array[ROWS][COLUMNS], int cantPalabras)
{
    printf("\nArreglo de palabras (%d palabras):\n", cantPalabras);
    printf("---------------------------\n");

    for (int i = 0; i < cantPalabras; i++)
    {
        printf("%d: %s\n", i + 1, array[i]);
    }

    printf("---------------------------\n");
}

int buscarElementoArrayString (char array[ROWS][COLUMNS], int cantidadPalabras, char dato[])
{
    int posicion=-1;
    for(int i=0; i<cantidadPalabras; i++)
    {
        if (strcmp(array[i],dato)==0)
        {
            posicion=i+1;
        }
    }

    return posicion;
}

// NO ENTIENDOOOOOOO

/*
void ordenarPalabrasInsercion(char array[ROWS][COLUMNS], int cantidadPalabras)
{

    int u=0;
    while(u<cantidadPalabras-1)
    {
        insertar(array,u,array[u+1]);
        u++;
    }


}
*/
void ordenarPalabrasInsercion(char array[ROWS][COLUMNS], int cantidadPalabras)
{
    for (int u = 0; u < cantidadPalabras - 1; u++)
    {
        char dato[COLUMNS];
        strcpy(dato, array[u + 1]);  // Copiar antes de mover datos
        insertar(array, u, dato);
    }
}

void insertar(char array[ROWS][COLUMNS], int u, char dato[])
{
    int i=u;
    //strcoll();#include <string.h>
    //Comparar dos strings, devuelve un int, cero (0) si son iguales, menor que cero (0) si el primero es menor que el segundo y mayor que cero (0) si el primero es mayor que el segundo.
//Usar strcoll(...) == -1 es incorrecto. strcoll puede devolver cualquier número negativo, no necesariamente -1, cuando dato < array[i].
    while (i >= 0 && strcoll(dato, array[i]) < 0)
    {
        strcpy(array[i+1], array[i]);
        i--;

    }
    strcpy(array[i+1], dato);
}

int determinanteMatriz2x2(int matriz[ROWS][COLUMNS], int filas, int columnas)
{

    int determinante=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;

    for(int i=0; i<filas; i++)
    {

        for(int j=0; j<columnas; j++)
        {
            if (i==0 && j==0)
            {
                a=matriz[i][j];
            }
            if (i==0&&j==1)
            {
                b=matriz[i][j];
            }
            if (i==1&&j==0)
            {
                c=matriz[i][j];
            }
            if (i==1&&j==1)
            {
                d=matriz[i][j];
            }

        }
    }

    determinante=(a*d)-(b*c);


    return determinante;
}

int tieneInversa(int matriz[ROWS][COLUMNS], int filas, int columnas)
{
    int inversa=0;

    int determinante=determinanteMatriz2x2(matriz,filas,columnas);

    if(determinante==0)
    {
        inversa=-1;
    }

    return inversa;

}
