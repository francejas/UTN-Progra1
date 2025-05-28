#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "pila.h"

#define AR_INT "datosInt.dat"

#define AR_ALUMNOS "alumnos.dat"

#define MAX 100

int menu();

int main(int argc, char *argv[])
{
    int selected;
    int v=0;

    Pila legajoMayores;
    inicpila(&legajoMayores);
    int edad=18;
    int cant=0;
    int minimaEdad;
    int maximaEdad;
    int anio;

    stAlumno alumnos[MAX];
    int vAlumnos=0;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            agregarEnteroArchivo(AR_INT);
            system("PAUSE");
            break;
        case 2:
            mostrarContenidoArchivo(AR_INT);
            system("PAUSE");
            break;
        case 3:
        {
            int cantidad = contarRegistrosArchivoINT(AR_INT);
            if (cantidad >= 0)
                printf("Cantidad de registros: %d\n", cantidad);
            else
                printf("No se pudo abrir el archivo.\n");
            system("PAUSE");
            break;
        }
        case 4:
            v=cargarArchivoAlumnos(AR_ALUMNOS,v);
            system("PAUSE");
            break;
        case 5:
            mostrarArchivoAlumnos(AR_ALUMNOS);
            system("PAUSE");
            break;
        case 6:
            cargaAlumno();
            system("PAUSE");
            break;
        case 7:
            pasarLegajosMayoresEdadAPila(AR_ALUMNOS,&legajoMayores,edad);
            printf("Legajo de los alumnos mayores de edad:\n");
            mostrar(&legajoMayores);
            system("PAUSE");
            break;
        case 8:
            printf("Ingrese la edad mínima: ");
            scanf("%d", &edad);
            cant=contarMayoresDeEdad(AR_ALUMNOS,edad);
            printf("Cantidad de alumnos con edad mayor o igual a %d: %d\n", edad, cant);
            system("PAUSE");
            break;
        case 9:
            printf("Ingrese rango de edad:\n");
            printf("Minimo:");
            scanf("%d",&minimaEdad);
            printf("Maxima:");
            scanf("%d",&maximaEdad);
            mostrarAlumnosEnRangoEdad(AR_ALUMNOS,minimaEdad,maximaEdad);
            system("PAUSE");
            break;
        case 10:
            mostrarAlumnoMayorEdad(AR_ALUMNOS);
            system("PAUSE");
            break;
        case 11:
            printf("Ingrese anio:");
            scanf("%d",&anio);
            cant=contarAlumnosPorAnio(AR_ALUMNOS,anio);
            printf("Cantidad de alumnos que estan en %d anio: %d.\n", anio, cant);
            system("PAUSE");
            break;
        case 12:
        {
            printf("Carga de alumnos en arreglo.\n");
            vAlumnos=cargaArregloAlumnos(alumnos,v,MAX);
            printf("Se cargaron en el arreglo: %d alumnos",vAlumnos);
            printf("Pasando %d alumnos al archivo \"%s\"",vAlumnos,AR_ALUMNOS);
            int cantDatos=copiarArregloArchivo(AR_ALUMNOS,alumnos,v);
            printf("Se pasaron con exito: %d alumnos\n",cantDatos);
            printf("Ingrese un anio:");
            scanf("%d",&anio);
            printf("Pasando los alumnos del anio %d del archivo \"%s\" al arreglo\n",anio,AR_ALUMNOS);
            vAlumnos=copiarArchivoArregloFiltrado(AR_ALUMNOS,alumnos,anio,MAX);
            printf("Se pasaron con exito: %d alumnos\n",cantDatos);
            system("PAUSE");
            break;
        }
        case 13:
            cant=contarRegistrosGenerico(AR_ALUMNOS,sizeof(stAlumno));
            printf("El archivo \"%s\" contiene %d archivos.\n",AR_ALUMNOS,cant);
            system("PAUSE");
            break;
        case 14:
            //mostrarRegistroPorNumero();
            system("PAUSE");
            break;
        case 15:
            modificarRegistro(AR_ALUMNOS);
            system("PAUSE");
            break;
        case 16:
            //invertirArchivoAlumnos();
            system("PAUSE");
            break;
        case 0:
            printf("\n\nTERMINATE THE PROGRAM\n");
            break;
        default:
            printf("Opción inválida.\n");
            system("PAUSE");
        }

    }
    while(selected != 0);

    return 0;
}
int menu()
{
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n-----------------------------");
    printf("\nLIST MENU");
    printf("\n-----------------------------");
    printf("\n 1 - Agregar entero al archivo.");
    printf("\n 2 - Mostrar contenido del archivo de enteros.");
    printf("\n 3 - Contar registros del archivo de enteros.");
    printf("\n 4 - Cargar archivo de alumnos (máximo 5).");
    printf("\n 5 - Mostrar archivo de alumnos.");
    printf("\n 6 - Agregar un alumno al archivo.");
    printf("\n 7 - Pasar a una pila los legajos de los alumnos mayores de edad.");
    printf("\n 8 - Contar alumnos mayores a una edad específica.");
    printf("\n 9 - Mostrar nombres de alumnos en un rango de edad.");
    printf("\n10 - Mostrar alumno de mayor edad.");
    printf("\n11 - Contar alumnos que cursan un año determinado.");
    printf("\n12 - Copiar arreglo de alumnos al archivo y viceversa (filtrado por año).");
    printf("\n13 - Contar registros de un archivo con fseek y ftell.");
    printf("\n14 - Mostrar registro por número (0 a 9).");
    printf("\n15 - Modificar un registro existente.");
    printf("\n16 - Invertir el contenido del archivo de alumnos.");
    printf("\n 0 - SALIR");
    printf("\n-----------------------------");
    printf("\nIngrese su opción: ");
    scanf("%d", &input);
    return input;
}


void agregarEnteroArchivo(char nombreArchivo[])
{
    int dato;
    char control;
    do
    {
        FILE *fp = fopen(nombreArchivo, "ab");
        if (fp != NULL)
        {
            printf("\nIngrese el número entero a agregar: ");
            scanf("%d", &dato);
            fwrite(&dato, sizeof(dato), 1, fp);
            fclose(fp);
        }
        else
        {
            printf("Error al abrir el archivo para agregar.\n");
        }

        printf("¿Desea seguir? (s/n): ");
        scanf(" %c", &control);  // espacio para limpiar buffer

    }
    while(control != 'n' && control != 'N');
}

void mostrarContenidoArchivo(const char nombreArchivo[])
{
    int dato;
    int contador = 0;

    FILE *fp = fopen(nombreArchivo, "rb");
    if (fp != NULL)
    {
        printf("\nContenido del archivo \"%s\":\n", nombreArchivo);
        while (fread(&dato, sizeof(int), 1, fp) > 0)
        {
            printf(" [%d] %d\n", contador, dato);
            contador++;
        }

        if (contador == 0)
        {
            printf("El archivo está vacío.\n");
        }

        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

int contarRegistrosArchivoINT(const char nombreArchivo[])
{
    int cant = -1;

    FILE *fp = fopen(nombreArchivo, "rb");
    if (fp != NULL)
    {
        /// muevo el indicador de posición al final
        fseek(fp, 0, SEEK_END);
        /// la totalidad de bytes lo divido por el tamaño de un registro.
        long bytesTotales = ftell(fp);
        cant = (int)(bytesTotales / sizeof(int));
        fclose(fp);
    }

    return cant;
}

int cargarArchivoAlumnos(const char nombreArchivo[],int v)
{
    char control;
    stAlumno a;

    FILE *fp = fopen(nombreArchivo, "rb");
    if(fp==NULL)
    {
        printf("El archivo \"%s\" no existe. Se creará uno nuevo.\n", nombreArchivo);
    }
    else
    {
        fclose(fp); // Cierro el archivo de solo lectura antes de abrir en modo escritura
    }
    // Abro en modo "ab" siempre para agregar sin borrar contenido
    fp = fopen(nombreArchivo, "ab");
    if (fp == NULL)
    {
        printf("Error al abrir o crear el archivo.\n");
    }

    do
    {
        a=cargaAlumno();
        fwrite(&a, sizeof(stAlumno), 1, fp);
        v++;

        if (v >= 5)
        {
            printf("\nSe alcanzó el límite de 5 alumnos.\n");
            break;
        }

        printf("¿Desea seguir ingresando alumnos? (s/n): ");
        fflush(stdin);
        scanf(" %c", &control);
    }
    while (control != 'n' && control != 'N');

    fclose(fp);

    return v;
}
void mostrarArchivoAlumnos(char nombreArchivo[])
{
    stAlumno aux;
    FILE* fp = fopen(nombreArchivo, "rb");

    if (fp == NULL)
    {
        printf("El archivo \"%s\" no existe.\n", nombreArchivo);
    }
    else
    {
        printf("\n--- Lista de Alumnos ---\n");
        while (fread(&aux, sizeof(stAlumno), 1, fp) > 0)
        {
            muestraUnAlumno(aux);
        }
        fclose(fp);
    }
}

void muestraUnAlumno(stAlumno alumno)
{
    printf("\n-------------------------\n");
    printf("Legajo: %d\n", alumno.legajo);
    printf("Nombre y Apellido: %s", alumno.nombreYapellido);  // fgets incluye el '\n'
    printf("Edad: %d\n", alumno.edad);
    printf("Año: %d\n", alumno.anio);
}

stAlumno cargaAlumno()
{
    stAlumno aux;

    printf("\n--- Ingreso de Alumno ---\n");

    printf("Ingrese legajo: ");
    scanf("%d", &aux.legajo);

    printf("Ingrese nombre y apellido: ");
    fflush(stdin);
    fgets(aux.nombreYapellido, sizeof(aux.nombreYapellido), stdin);

    printf("Ingrese edad: ");
    scanf("%d", &aux.edad);

    printf("Ingrese anio: ");
    scanf("%d", &aux.anio);

    return aux;

}

void pasarLegajosMayoresEdadAPila(char nombreArchivo[],Pila*legajoMayores, int edad)
{
    stAlumno a;
    FILE*fp;
    fp=fopen(nombreArchivo,"rb");
    if(fp!=NULL)
    {
        while(fread(&a,sizeof(stAlumno),1,fp)>0)
        {
            if(a.edad>=edad)
            {
                apilar(legajoMayores,a.legajo);
            }
        }
        //aca tendria qe ir el fclose ?
    }
    else
    {
        printf("El archivo no existe.\n");
    }
    fclose(fp);

}

int contarMayoresDeEdad(char nombreArchivo[], int edad)
{
    int contador=0;
    stAlumno a;
    FILE*fp;
    fp=fopen(nombreArchivo,"rb");
    if(fp!=NULL)
    {
        while(fread(&a,sizeof(stAlumno),1,fp)>0)
        {
            if(a.edad>=edad)
            {
                contador++;
            }

        }
        fclose(fp);
    }
    else
    {
        printf("El archivo no existe.\n");
    }
    return contador;
}
void mostrarAlumnosEnRangoEdad(char nombreArchivo[], int min, int max)
{
    FILE *fp;
    stAlumno aux;
    fp = fopen(nombreArchivo, "rb");
    if(fp != NULL)
    {
        printf("\n--- Alumnos entre %d y %d años ---\n", min, max);
        while(fread(&aux, sizeof(stAlumno), 1, fp) > 0)
        {
            if(aux.edad >= min && aux.edad <= max)
            {
                mostrarNombreAlumno(aux);
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}


void mostrarNombreAlumno(stAlumno alumno)
{
    printf("\n-------------------------\n");
    printf("Nombre y Apellido: %s", alumno.nombreYapellido);  // fgets incluye el '\n'
}


///NO ENTIENDO
/*
void mostrarAlumnoMayorEdad(char nombreArchivo[])
{
    FILE*fp;
    stAlumno alumnoActual;
    stAlumno alumnoMayor;
    fp=fopen(nombreArchivo,"rb");
    if(fp!=NULL)
    {
        while(fread(&alumnoActual,sizeof(stAlumno),1,fp)>0)
        {
            if(alumnoActual.edad>alumnoMayor.edad)
            {
                alumnoMayor=alumnoActual;
            }
        }
        fclose(fp);
        printf("\n--- Alumno de Mayor Edad ---\n");
        muestraUnAlumno(alumnoMayor);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }

}
*/

// Esta función busca y muestra el alumno de mayor edad en el archivo binario de alumnos.
void mostrarAlumnoMayorEdad(char nombreArchivo[])
{
    FILE *fp;
    stAlumno alumnoActual;  // Variable para almacenar el alumno que se va leyendo del archivo
    stAlumno alumnoMayor;   // Variable que va a contener el alumno con la mayor edad encontrada

    fp = fopen(nombreArchivo, "rb");  // Abrimos el archivo en modo lectura binaria

    if (fp != NULL)
    {
        // Leemos el primer alumno del archivo y lo guardamos como "alumnoMayor" inicial.
        // Esto es muy importante: usamos este primer alumno como punto de comparación,
        // porque sabemos que es un alumno real del archivo.
        if (fread(&alumnoMayor, sizeof(stAlumno), 1, fp) > 0)
        {
            // Empezamos a leer el resto de los alumnos uno por uno
            while (fread(&alumnoActual, sizeof(stAlumno), 1, fp) > 0)
            {
                // Comparamos la edad del alumno actual con la del mayor hasta ahora
                if (alumnoActual.edad > alumnoMayor.edad)
                {
                    // Si el alumno actual tiene más edad, lo guardamos como nuevo "mayor"
                    alumnoMayor = alumnoActual;
                }
            }

            fclose(fp);  // Cerramos el archivo una vez terminado el recorrido

            // Mostramos los datos del alumno de mayor edad
            printf("\n--- Alumno de Mayor Edad ---\n");
            muestraUnAlumno(alumnoMayor);
        }
        else
        {
            // Si no se pudo leer ni un solo alumno, es porque el archivo está vacío
            printf("El archivo está vacío.\n");
            fclose(fp);
        }
    }
    else
    {
        // Si no se pudo abrir el archivo, mostramos mensaje de error
        printf("Error al abrir el archivo.\n");
    }
}

int contarAlumnosPorAnio(char nombreArchivo[],int anio)
{
    FILE*fp;
    fp=fopen(nombreArchivo,"rb");
    stAlumno aux;
    int contador=0;
    if(fp!=NULL)
    {
        while (fread(&aux, sizeof(stAlumno), 1, fp) > 0)
        {
            if(aux.anio==anio)
            {
                contador++;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return contador;
}


int cargaArregloAlumnos(stAlumno alumnos[], int v, int max_dim)
{
    int i = v;
    char control;

    do
    {
        alumnos[i]=cargaAlumno();
        printf("¿Desea seguir ingresando alumnos? (s/n): ");
        fflush(stdin);
        scanf(" %c", &control);
        i++;

    }
    while ((control == 's' || control == 'S') && i < max_dim);

    return i;
}

int copiarArregloArchivo(char nombreArchivo[], stAlumno alumnos[],int v)
{
    FILE*fp;
    int cantDatos=0;
    fp=fopen(nombreArchivo,"rb");
    if(fp==NULL)
    {
        printf("El archivo \"%s\" no existe. Se creará uno nuevo.\n", nombreArchivo);
    }
    else
    {
        fclose(fp);
    }
    fp=fopen(nombreArchivo,"ab");
    if(fp!=NULL)
    {
        cantDatos=fwrite(alumnos,sizeof(stAlumno),v,fp);
        fclose(fp);
    }
    else
    {
        printf("El archivo \"%s\" no existe.\n", nombreArchivo);
    }
    return cantDatos;
}

int copiarArchivoArregloFiltrado(char nombreArchivo[],stAlumno alumnos[],int anio, int max_dim)
{
    int i=0;
    FILE*fp;
    fp=fopen(nombreArchivo,"rb");
    stAlumno aux;
    if(fp!=NULL)
    {
        while(fread(&aux,sizeof(stAlumno),1,fp)>0)
        {
            if(aux.anio==anio)
            {
                alumnos[i]=aux;
                i++;
            }
            if(i>=max_dim)
            {
                printf("Se alcanzo el limite del arreglo.\n");
                printf("Se completaron la carga de %d alumnos.\n",i);
                break;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("El archivo \"%s\" no existe.\n", nombreArchivo);
    }

    return i;
}

int contarRegistrosGenerico (char nombreArchivo[],int tamRegistro)
{
    FILE*fp;
    fp=fopen(nombreArchivo,"rb");
    int cant=0;
    if(fp!=NULL)
    {
        fseek(fp,0,SEEK_END);
        long bytesTotales=ftell(fp);
        cant=(int)(bytesTotales/tamRegistro);
        fclose(fp);
    }
    else
    {
        printf("El archivo \"%s\" no existe.\n", nombreArchivo);
    }
    return cant;
}

void modificarRegistro(char nombreArchivo[])
{
    mostrarArchivoAlumnos(nombreArchivo);
    printf("Ingrese el numero del legajo del alumno que quiera modificar")
    ingresa legajo
    se localiza el alumno del legajo
    se pregunta que se desea modificar
    una banda de ifs y se modifica

}
