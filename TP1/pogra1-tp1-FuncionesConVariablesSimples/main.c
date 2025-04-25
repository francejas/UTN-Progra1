#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Necesario para la función time()



// PROTOTIPADO
int numRand();
void mostrarMayorYMenor(int a, int b, int c);
int sumaEnterosMenores(int N);
void tablaMultiplicar(int a);
float suma (float a ,float b);
float resta (float a ,float b);
float multiplicacion (float a ,float b);
float division (float a ,float b);
float convertirNegativo (float *a);
int menu();

int main(int argc, char *argv[]) {
    int selected;

    do {
        selected = menu();
        switch(selected) {
            case 1:
                {
                    int randomNumber = numRand();
                    printf("El numero random es: %d\n", randomNumber);
                    system("PAUSE");
                }
                break;
            case 2:
                {
                    int num1, num2, num3;
                    printf("Ingrese 3 numeros enteros: ");
                    scanf("%d %d %d", &num1, &num2, &num3);
                    mostrarMayorYMenor(num1, num2, num3);
                    system("PAUSE");
                }
                break;
            case 3:
                {
                    int N;
                    printf("Ingrese un numero entero: ");
                    scanf("%d", &N);
                    int suma = sumaEnterosMenores(N);
                    printf("La suma de los enteros menores que %d es: %d\n", N, suma);
                    system("PAUSE");
                }
                break;  // Añadido el break para evitar caer en el caso 4
            case 4:
                {
                    int num1;
                    printf("Ingrese un numero entero: ");
                    scanf("%d", &num1);
                    tablaMultiplicar(num1);
                    system("PAUSE");
                }
                break;
            case 5:
                {
                    float num1, num2;
                    char operador;

                  printf("Ingrese el operador (+, -, *, / ): \n");
                  scanf(" %c", &operador);

                  printf("Ingrese primer numero: \n");
                  scanf("%f",&num1);

                  printf("Ingrese segundo numero: \n");
                  scanf("%f",&num2);

                  float resultado;

                  switch (operador) {
        case '+':
            resultado = suma(num1, num2);
            break;
        case '-':
    resultado = resta(num1, num2);
            break;
        case '*':
    resultado = multiplicacion(num1, num2);
            break;
        case '/':
    resultado = division(num1, num2);
            break;
        default:
            printf("Operador invalido.\n");
            break;
    }

    printf("Resultado: %.2f\n", resultado);
    system("PAUSE");



                }
            break;
        case 6:
            {
             float num;
             printf("Ingrese un numero para convertirlo a negativo. \n");
             scanf("%f",&num);
             convertirNegativo(&num);
             printf("Numero: %.2f \n", num);
             system("PAUSE");
            }
            break;
        case 7:
            {
                int num1, num2;
                cargaValoresReferencia(&num1, &num2);
                printf("Sus numeros: %d y %d.", num1,num2);

             system("PAUSE");
            }
            break;
            case 0:
                printf("\n\nTERMINATE THE PROGRAM\n");
                break;
            default:
                printf("Opción no válida. Por favor, elige una opción del menú.\n");
                break;
        }
    } while(selected != 0);

    system("PAUSE");
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
    printf("\n1-Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100");
    printf("\n2-Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor");
    printf("\n3-Diseñe una función que reciba un número entero N y realice la suma de los números enteros positivos menores que N y lo retorne. N es un  dato ingresado por el usuario en el main");
    printf("\n4-Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por parámetro.");
    printf("\n5 Realice una pequeña calculadora, utilizando funciones una función de suma, una de multiplicación, una de resta, una de división…");
    printf("\n6 Realizar una función que reciba un número positivo entero por parámetro por referencia, y cambie su signo a negativo.");
    printf("\n7 Realizar una función que reciba dos números enteros por parámetro por referencia y cargue sus valores el usuario dentro de la función.");
    printf("\n0-QUIT");
    printf("\n\nENTER YOUR CHOICE: ");
    scanf("%d", &input);
    return input;
}

int numRand() {

    srand(time(NULL));  // Inicializa la semilla para la generación de números aleatorios
    int numeroRand = rand() % 101;  // Cambiado a 101 para incluir el 100 en el rango
    return numeroRand;
}

void mostrarMayorYMenor(int a, int b, int c) {
    int mayor, menor;

    // Determinar el mayor
    if (a >= b && a >= c) {
        mayor = a;
    } else if (b >= a && b >= c) {
        mayor = b;
    } else {
        mayor = c;
    }

    // Determinar el menor
    if (a <= b && a <= c) {
        menor = a;
    } else if (b <= a && b <= c) {
        menor = b;
    } else {
        menor = c;
    }

    printf("El mayor es: %d\n", mayor);
    printf("El menor es: %d\n", menor);
}

void tablaMultiplicar(int a) {
    for (int i = 0; i <= 10; i++) {
        int producto = a * i;
        printf("%d x %d = %d\n", a, i, producto);
    }
}

int sumaEnterosMenores(int N) {
    int sumaMenores = 0;
    for (int i = 1; i < N; i++) {  // Comienza desde 1 para sumar solo enteros positivos menores que N
        sumaMenores += i;
    }
    return sumaMenores;
}


float suma (float a ,float b) {
    return a+b;
}
float resta (float a ,float b) {
    return a-b;
}
float multiplicacion (float a ,float b) {
    return a*b;
}
float division (float a ,float b) {
    return a/b;
}

float convertirNegativo (float *a) {
    *a=*a *-1;
}

int cargaValoresReferencia(int *a, int *b){
    printf("Ingrese el primer numero: ");
    scanf("%d",a);
    printf("Ingrese el segundo numero: ");
    scanf("%d",b);

}
