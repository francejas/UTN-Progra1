#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct
{
    int nro_identificacion;
    int idEspecie;
    char nombreAnimal[30];
    int poblacion;    // cantidad de animales
} stAnimal;

typedef struct
{
    int idEspecie;
    int cantEjemplares; // cantidad de animales de esa especie
    char nombreEspecie[30];
} stEspecie;


int main()
{
    stAnimal arrayAnimales[MAX];
    int vAnimales=0;

    vAnimales=cargarArrayAnimales(arrayAnimales,vAnimales,MAX);



    return 0;
}

int cargarArrayAnimales(int arrayAnimales[],int v,int max_dim)
{


}
