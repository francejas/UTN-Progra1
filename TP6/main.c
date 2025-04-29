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

int main(int argc, char *argv[])
{
    stAlumno alumnos[MAX_ALUMNOS];
    int vAlumnos = 0;
    int matricula;
    char genero;

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
            scanf("%d",&genero);
            mostrarAlumnosPorGenero(alumnos,vAlumnos,genero);
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
    printf("\n1-Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.");
    printf("\n2-Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.");
    printf("\n3-Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.");
    printf("\n4-Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.");
    printf("\n5-Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d", &input);
    getchar(); // Consumir ENTER después del scanf
    return input;
}

int cargarAlumnos(stAlumno alumnos[], int v, int max)
{
    int i = v;
    char seguir;

    do
    {
        printf("\n--- Alumno %d ---\n", i + 1);

        printf("Ingrese matrícula: ");
        scanf("%d", &alumnos[i].matricula);
        getchar(); // Consumir ENTER después de scanf

        printf("Ingrese nombre: ");
        gets(alumnos[i].nombre);
        //fgets(alumnos[i].nombre, sizeof(alumnos[i].nombre), stdin);

        printf("Ingrese género (m/f/o): ");
        scanf("%c", &alumnos[i].genero);
        getchar(); // Consumir ENTER después de scanf

        i++;

        if (i < max)
        {
            printf("¿Desea cargar otro alumno? (s/n): ");
            scanf("%c", &seguir);
            getchar(); // Consumir ENTER después de scanf
        }
        else
        {
            printf("Se alcanzó el máximo de alumnos permitido.\n");
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
    printf("Matrícula: %d\n", alumno.matricula);
    printf("Nombre: %s\n", alumno.nombre);
    printf("Género: %c\n", alumno.genero);
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
        printf("Alumno con matrícula %d no encontrado.\n", matricula);
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

void mostrarAlumnosPorGenero(stAlumno alumnos[],int v,char genero){

}
