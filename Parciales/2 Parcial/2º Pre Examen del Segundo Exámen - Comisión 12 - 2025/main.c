#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AR_ANIMALES "animales.dat"
#define AR_ESPECIES "especies.dat"
#define MAX 30

// --- ESTRUCTURAS ---
typedef struct
{
    int nro_identificacion;
    int idEspecie;
    char nombreAnimal[30];
    int poblacion;
} stAnimal;

typedef struct
{
    int idEspecie;
    int cantEjemplares;
    char nombreEspecie[30];
} stEspecie;

// --- PROTOTIPOS ---
int cargarArrayAnimales(stAnimal array[], int v, int dim, char nombreArchivo[]);
stAnimal cargarUnAnimal(char nombreArchivoEspecies[]);
int idEspecieExiste(char nombreArchivo[], int idBusqueda);

void mostrarUnAnimal(stAnimal animal);
void muestraArregloAnimalesRecursivo(stAnimal animales[], int v, int i);

void mostrarUnaEspecie(stEspecie e);
void muestraArchivoEspecies(char nombreArchivo[]);

int contarEjemplaresPorEspecie(stAnimal animales[], int vAnimales, int idEspecie);
int filtrarEspeciesPorCantidad(stAnimal animales[], int vAnimales, stEspecie especies[], int dim, char archivoEspecies[]);

// --- MAIN ---
int main()
{
    stAnimal arrayAnimales[MAX];
    int vAnimales = 0;

    stEspecie arrayEspecies[MAX];
    int vEspecies = 0;

    int cant=0;

    // Cargar animales
    vAnimales = cargarArrayAnimales(arrayAnimales, vAnimales, MAX, AR_ESPECIES);

    // Mostrar animales cargados
    printf("\nAnimales cargados: %d\n", vAnimales);
    muestraArregloAnimalesRecursivo(arrayAnimales, vAnimales, 0);

    // Filtrar especies cuya cantidad de animales sea > 2
    vEspecies = filtrarEspeciesPorCantidad(arrayAnimales, vAnimales, arrayEspecies, MAX, AR_ESPECIES);

    // Mostrar especies filtradas
    printf("\nEspecies con más de 2 animales:\n");
    for (int i = 0; i < vEspecies; i++)
    {
        mostrarUnaEspecie(arrayEspecies[i]);
    }

    cant=pasarAnimalesAltaPoblacionAArchivo(arrayAnimales,vAnimales,AR_ANIMALES);
    printf("\nAnimales cargados: %d\n", cant);
    return 0;
}

// --- FUNCIONES ---

int cargarArrayAnimales(stAnimal array[], int v, int dim, char nombreArchivo[])
{
    int i = v;
    char control;
    stAnimal animal;

    do
    {
        animal = cargarUnAnimal(nombreArchivo);
        array[i] = animal;
        i++;

        printf("Desea continuar ? (s/n)\n");
        fflush(stdin);
        scanf(" %c", &control);
    }
    while ((control == 's' || control == 'S') && i < dim);

    return i;
}

stAnimal cargarUnAnimal(char nombreArchivoEspecies[])
{
    stAnimal animal;
    printf("Ingrese nro de identificacion del animal: ");
    scanf("%d", &animal.nro_identificacion);

    int idValido = -1;

    do
    {
        printf("Ingrese idEspecie: ");
        scanf("%d", &idValido);

        if (idEspecieExiste(nombreArchivoEspecies, idValido) == 1)
        {
            animal.idEspecie = idValido;
        }
        else
        {
            printf("Número de especie inválido. Ingrese uno nuevamente\n\n");
            idValido = -1;
        }
    }
    while (idValido == -1);

    printf("Ingrese nombreAnimal: ");
    fflush(stdin);
    gets(animal.nombreAnimal);

    printf("Ingrese poblacion: ");
    scanf("%d", &animal.poblacion);

    return animal;
}

int idEspecieExiste(char nombreArchivo[], int idBusqueda)
{
    stEspecie aux;
    FILE *fp = fopen(nombreArchivo, "rb");
    int flag = 0;

    if (fp != NULL)
    {
        while (flag == 0 && fread(&aux, sizeof(stEspecie), 1, fp) > 0)
        {
            if (aux.idEspecie == idBusqueda)
            {
                flag = 1;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }

    return flag;
}

void mostrarUnAnimal(stAnimal animal)
{
    printf("\n-------------------------\n");
    printf("Nro de Identificacion: %d\n", animal.nro_identificacion);
    printf("Nombre Animal: %s\n", animal.nombreAnimal);
    printf("Poblacion: %d\n", animal.poblacion);
    printf("Id Especie: %d\n", animal.idEspecie);
    printf("-------------------------\n");
}

void muestraArregloAnimalesRecursivo(stAnimal animales[], int v, int i)
{
    if (i < v)
    {
        mostrarUnAnimal(animales[i]);
        muestraArregloAnimalesRecursivo(animales, v, i + 1);
    }
}

void mostrarUnaEspecie(stEspecie e)
{
    printf("\n-------------------------\n");
    printf("Id Especie: %d\n", e.idEspecie);
    printf("Nombre Especie: %s\n", e.nombreEspecie);
    printf("Cantidad Ejemplares: %d\n", e.cantEjemplares);
    printf("-------------------------\n");
}

void muestraArchivoEspecies(char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stEspecie aux;

    if (archi)
    {
        while (fread(&aux, sizeof(stEspecie), 1, archi) > 0)
        {
            mostrarUnaEspecie(aux);
        }
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

int contarEjemplaresPorEspecie(stAnimal animales[], int vAnimales, int idEspecie)
{
    int contador = 0;
    for (int i = 0; i < vAnimales; i++)
    {
        if (animales[i].idEspecie == idEspecie)
        {
            contador++;
        }
    }
    return contador;
}

int filtrarEspeciesPorCantidad(stAnimal animales[], int vAnimales, stEspecie especies[], int dim, char archivoEspecies[])
{
    FILE *fp = fopen(archivoEspecies, "rb");
    stEspecie especieAux;
    int vEspecies = 0;

    if (fp != NULL)
    {
        while (fread(&especieAux, sizeof(stEspecie), 1, fp) > 0 && vEspecies < dim)
        {
            int cantidad = contarEjemplaresPorEspecie(animales, vAnimales, especieAux.idEspecie);

            if (cantidad > 2)
            {
                especieAux.cantEjemplares = cantidad; // actualizar
                especies[vEspecies] = especieAux;
                vEspecies++;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo abrir el archivo de especies.\n");
    }

    return vEspecies;
}

int pasarAnimalesAltaPoblacionAArchivo(stAnimal arrayAnimales[],int v,char nombreArchivo)
{
    FILE*fp;
    fp=fopen(nombreArchivo,"ab");
    stAnimal aux;
    int i=0;
    int cant=0;
    if(fp!=NULL){
        for(int i=0;i<v;i++){
            if(arrayAnimales[i].poblacion>100){
                cant=fwrite(arrayAnimales[i],sizeof(stAnimal),1,fp);
            }
        }
    }else{

        printf("Error.\n");
    }

    return cant;

}
