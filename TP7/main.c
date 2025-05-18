#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

#define AR_ARCHIVO_INT "int.dat"

int main(int argc, char *argv[])
{
    int selected;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:

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
    printf("\n1-Hacer una función que agregue un elemento al final de un archivo.");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}

//hola como estas
//hola
//holasaaaaa
