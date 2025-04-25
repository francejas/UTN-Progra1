#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int selected;

    do
    {
        selected = menu();
        switch(selected)
        {
        case 1:
            funcion_x();
            break;
        case 2:
            funcion_x();
            break;
        case 3:
            funcion_x();
            break;
        case 4:
            funcion_x();
            break;
        case 5:
            funcion_x();
            break;
        case 6:
            funcion_x();
            break;
        case 7:
            funcion_x();
            break;
        case 8:
            funcion_x();
            break;
        case 9:
            funcion_x();
            break;
        case 10:
            funcion_x();
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
    printf("\n1-Agrega elementos a Pila");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d",&input);
    return input;
}
funcion_x()
{
    system("cls");
    system("color 1E");
    printf("\n\naca deberia estar la funcion pedida en cada ejercicio de la practica\n");
    system("PAUSE");
}
