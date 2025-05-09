#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 50

typedef struct
{
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

// Prototipos
int menu();
int cargarAlumnos(stAlumno alumnos[], int v, int max);
void mostrarArrayAlumnos(stAlumno alumnos[], int v);
void mostrarAlumno(stAlumno alumno);
void mostrarAlumnoPorMatricula(stAlumno alumnos[], int v, int matricula);
void ordenarAlumnosPorMatriculaSeleccion(stAlumno alumnos[], int v);
int posicion_menor(stAlumno alumnos[], int v, int pos);
void mostrarAlumnosPorGenero(stAlumno alumnos[],int v,char genero);
int contadorPorGenero(stAlumno alumnos[], int v, char genero);

int main(int argc, char *argv[])
{
    stAlumno alumnos[MAX_ALUMNOS];
    int vAlumnos = 0;
    int matricula;
    char genero;

    int vGenero=0;

    int selected;
    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            vAlumnos = cargarAlumnos(alumnos, vAlumnos, MAX_ALUMNOS);
            system("PAUSE");
            break;
        case 2:
            mostrarArrayAlumnos(alumnos, vAlumnos);
            system("PAUSE");
            break;
        case 3:
            printf("Ingrese matricula del alumno: ");
            scanf("%d",&matricula);
            mostrarAlumnoPorMatricula(alumnos,vAlumnos,matricula);
            system("PAUSE");
            break;
        case 4:
            ordenarAlumnosPorMatriculaSeleccion(alumnos,vAlumnos);
            mostrarArrayAlumnos(alumnos, vAlumnos);
            system("PAUSE");
            break;
        case 5:
            printf("Ingrese genero del alumno: ");
            scanf(" %c",&genero);
            mostrarAlumnosPorGenero(alumnos,vAlumnos,genero);
            system("PAUSE");
            break;
        case 6:

            system("PAUSE");
            break;
        case 7:
            ordenarAlumnosPorNombreInsercion(alumnos,vAlumnos);
            mostrarArrayAlumnos(alumnos, vAlumnos);
            system("PAUSE");
            break;
        case 8:
            printf("Ingrese un genero: (m/f/o): ");
            scanf(" %c", &genero);
            vGenero = contadorPorGenero(alumnos, vAlumnos, genero);
            printf("Numero de alumnos de genero %c: %d\n", genero, vGenero);
            system("PAUSE");
            break;

        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        }
    }
    while(selected != 0);

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
    printf("\n1-Hacer una funci�n que cargue un arreglo de alumnos, hasta que el usuario lo decida.");
    printf("\n2-Hacer una funci�n que muestre un arreglo de alumnos por pantalla. Modularizar.");
    printf("\n3-Hacer una funci�n que muestre por pantalla los datos de un alumno, conociendo su matr�cula. Modularizar.");
    printf("\n4-Hacer una funci�n que ordene el arreglo de alumnos por medio del m�todo de selecci�n. El criterio de ordenaci�n es el n�mero de matr�cula.");
    printf("\n5-Hacer una funci�n que muestre por pantalla los datos de los estudiantes de un g�nero determinado (se env�a por par�metro). Modularizar.");
    printf("\n6-Hacer una funci�n que inserte en un arreglo ordenado por matr�cula un nuevo dato, conservando el orden.");
    printf("\n7-Hacer una funci�n que ordene el arreglo de alumnos por medio del m�todo de inserci�n. El criterio de ordenaci�n es el nombre.");
    printf("\n8-Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d", &input);
    getchar(); // Consumir ENTER despu�s del scanf
    return input;
}

int cargarAlumnos(stAlumno alumnos[], int v, int max)
{
    int i = v;
    char seguir;

    do
    {
        printf("\n--- Alumno %d ---\n", i + 1);

        printf("Ingrese matr�cula: ");
        scanf("%d", &alumnos[i].matricula);
        getchar(); // Consumir ENTER despu�s de scanf

        printf("Ingrese nombre: ");
        gets(alumnos[i].nombre);
        //fgets(alumnos[i].nombre, sizeof(alumnos[i].nombre), stdin);

        printf("Ingrese g�nero (m/f/o): ");
        scanf("%c", &alumnos[i].genero);
        getchar(); // Consumir ENTER despu�s de scanf

        i++;

        if (i < max)
        {
            printf("�Desea cargar otro alumno? (s/n): ");
            scanf("%c", &seguir);
            getchar(); // Consumir ENTER despu�s de scanf
        }
        else
        {
            printf("Se alcanz� el m�ximo de alumnos permitido.\n");
            seguir = 'n';
        }

    }
    while ((seguir == 's' || seguir == 'S') && i < max);

    return i;
}

void mostrarArrayAlumnos(stAlumno alumnos[], int v)
{
    for(int i = 0; i < v; i++)
    {
        mostrarAlumno(alumnos[i]);
    }
}

void mostrarAlumno(stAlumno alumno)
{
    printf("Matr�cula: %d\n", alumno.matricula);
    printf("Nombre: %s\n", alumno.nombre);
    printf("G�nero: %c\n", alumno.genero);
    printf("---------------------------\n");
}

void mostrarAlumnoPorMatricula(stAlumno alumnos[], int v, int matricula)
{
    int encontrado = 0;
    for (int i = 0; i < v; i++)
    {
        if (alumnos[i].matricula == matricula)
        {
            mostrarAlumno(alumnos[i]);
            encontrado = 1;
            break;  // Una vez encontrado, podemos salir del ciclo
        }
    }

    if (!encontrado)
    {
        printf("Alumno con matr�cula %d no encontrado.\n", matricula);
    }
}


void ordenarAlumnosPorMatriculaSeleccion(stAlumno alumnos[], int v)
{
    int posMenor;
    int i=0;
    stAlumno aux;

    while(i<v-1)
    {
        posMenor=posicion_menor(alumnos, v, i);
        aux=alumnos[posMenor];
        alumnos[posMenor]=alumnos[i];
        alumnos[i]=aux;
        i++;
    }
}

int posicion_menor(stAlumno alumnos[], int v, int pos)
{
    int menor=alumnos[pos].matricula;
    int posMenor=pos;
    int index=pos+1;

    while(index<v)
    {
        if (menor>alumnos[index].matricula)
        {
            menor=alumnos[index].matricula;
            posMenor=index;
        }
        index++;
    }
    return posMenor;
}

void mostrarAlumnosPorGenero(stAlumno alumnos[],int v,char genero)
{

    for(int i=0; i<v; i++)
    {
        if (alumnos[i].genero == genero)
        {
            mostrarAlumno(alumnos[i]);
        }
    }

}

void ordenarAlumnosPorNombreInsercion(stAlumno alumnos[], int v)
{
    int i=0;
    while(i<v-1)
    {
        insertar(alumnos, i);
        i++;
    }

}

void insertar(stAlumno alumnos[], int ultPos)
{
    stAlumno aux = alumnos[ultPos];
    int j = ultPos;

    while (j >= 0 && strcmp(aux.nombre, alumnos[j].nombre) < 0)
    {
        alumnos[j + 1] = alumnos[j];
        j--;
    }

    alumnos[j + 1] = aux;
}

int contadorPorGenero(stAlumno alumnos[], int v, char genero)
{
    int contador = 0;

    for(int i = 0; i < v; i++)
    {
        if (alumnos[i].genero == genero)
        {
            contador++;
        }
    }

    return contador;
}
