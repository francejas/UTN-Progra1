#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define AR_DEUDORES "Deudores.dat"
#define AR_ACREDORES "Acredores.dat"


typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    int edad;
    float saldo;
} stCliente;

typedef struct
{
    int deudores;
    int acredores;
    float balance;
} stBanco;

int cargarArrayClientes(stCliente arrayClientes[],int v,int max_dim, int edadMax, int edadMin);
stCliente cargaUnCliente(stCliente arrayClientes[],int i,int edadMax,int edadMin);
int existeCliente(stCliente arrayClientes[],int v,int idBuscar);
void mostrarArrayClientesRecursivo(stCliente arrayClientes[],int v,int i);
void mostrarArrayClientesIterativo(stCliente arrayClientes[],int v);
void mostrarUnCliente(stCliente cliente);
float sumatoriaArregloRecursivo(stCliente arrayClientes[], int v, int i);
void cargarArchivoDeudoresAcredores(stCliente arrayClientes[],int v,char deudores[],char acredores[], int *cantAcredores,int *cantDeudores);
void cargarAcredor(char acredores,stCliente cliente);
void cargarDeudor(char deudores,stCliente cliente);
int contadorRegistro(char nombreArchivo[]);
void mostrarBalanceBanco(stBanco banco);


int main()
{
    stCliente arrayClientes[MAX];
    stBanco banco;
    int vClientes=0;
    int edadMax=120;
    int edadMin=18;
    float suma=0;
    int cantRegistro=0;
    int cantAcredores=0;
    int cantDeudores=0;



    //1
    vClientes=cargarArrayClientes(arrayClientes,vClientes,MAX,edadMax,edadMin);
    printf("Se cargaron en el arreglo: %d clientes.\n",vClientes);
    //2
    //mostrarArrayClientesRecursivo(arrayClientes,vClientes,0):
    mostrarArrayClientesIterativo(arrayClientes,vClientes);
    //3
    suma=sumatoriaArregloRecursivo(arrayClientes,vClientes,0);
    printf("Suma total de saldo: %.2f",suma);
    //4
    cargarArchivoDeudoresAcredores(arrayClientes,vClientes,AR_DEUDORES,AR_ACREDORES,&cantAcredores,&cantDeudores);
    printf("En el archivo \"%s\" hay : %d clientes.\n",AR_DEUDORES,cantAcredores);
    printf("En el archivo \"%s\" hay : %d clientes.\n",AR_ACREDORES,cantDeudores);

    //5
    cantRegistro=contadorRegistro(AR_DEUDORES)+contadorRegistro(AR_ACREDORES);
    printf("Cantidad de resgitros de \"%s\" y \"%s\": %d",AR_DEUDORES,AR_ACREDORES,cantRegistro);
    //7
    banco.balance=suma+sumaArchivoTotal(AR_DEUDORES,AR_ACREDORES);
    banco.acredores=(cantRegistro/cantAcredores)*100;
    banco.deudores=(cantRegistro/cantDeudores)*100;
    mostrarBalance(stBanco);


    system("PAUSE");
    return 0;
}

int cargarArrayClientes(stCliente arrayClientes[],int v,int max_dim, int edadMax, int edadMin)
{
    stCliente cliente;
    char control;
    int i=v;
    do
    {
        cliente=cargaUnCliente(arrayClientes,i,edadMax,edadMin);
        arrayClientes[i]=cliente;
        i++;
        if(i==max_dim)
        {
            printf("Limite alcanzado.\n");
            break;
        }
        printf("Desea seguir? (s/n).");
        fflush(stdin);
        scanf(" %c",&control);
    }
    while((control=='s'||control=='S') && i<max_dim);

    return i;

}

stCliente cargaUnCliente(stCliente arrayClientes[],int v, int edadMax, int edadMin)
{
    stCliente cliente;
    int idBuscar;
    int edad;
    printf("Ingrese id cliente:");
    scanf("%d",&idBuscar);

    while(existeCliente(arrayClientes,v,idBuscar))
    {
        printf("Cliente ya existe.\n");
        printf("Ingrese id cliente:");
        scanf("%d",&idBuscar);
    }

    cliente.idCliente=idBuscar;
    printf("\nIngrese nombre:");
    scanf("%s",&cliente.nombre);
    printf("\nIngrese apellido:");
    scanf("%s",&cliente.apellido);
    printf("\nIngrese edad:");
    scanf("%d",&edad);
    while(edad>edadMax || edad<edadMin)
    {
        printf("Edad incorrecta.\n");
        printf("\nIngrese edad:");
        scanf("%d",&edad);
    }
    cliente.edad=edad;
    printf("\nIngrese saldo:");
    scanf("%f",&cliente.saldo);

    return cliente;

}

int existeCliente(stCliente arrayClientes[],int v,int idBuscar)
{
    int flag=0;
    for(int i =0; i<v; i++)
    {
        if(arrayClientes[i].idCliente==idBuscar)
        {
            flag=1;
            break;
        }
    }
    return flag;
}


void mostrarArrayClientesRecursivo(stCliente arrayClientes[],int v,int i)
{
    int i=0;
    if(i<v)
    {
        mostrarUnCliente(arrayClientes[i]);
        mostrarArrayClientesRecursivo(arrayClientes,v,i+1);
    }

}


void mostrarArrayClientesIterativo(stCliente arrayClientes[],int v)
{
    for(int i =0; i<v; i++)
    {
        mostrarUnCliente(arrayClientes[i]);
    }

}
void mostrarUnCliente(stCliente cliente)
{
    printf("ID Cliente: %d\n",cliente.idCliente);
    printf("Nombre: %s\n",cliente.nombre);
    printf("Apellido: %s\n",cliente.apellido);
    printf("Edad: %d\n",cliente.edad);
    printf("Saldo: %.2f\n",cliente.saldo);

}


float sumatoriaArregloRecursivo(stCliente arrayClientes[], int v, int i)
{

    float suma;
    if(i == v)
    {
        suma = 0;
    }
    else
    {
        suma = arrayClientes[i].saldo + sumatoriaArregloRecursivo(arrayClientes,v,i+1);
    }
    return suma;

}

void cargarArchivoDeudoresAcredores(stCliente arrayClientes[],int v,char deudores[],char acredores[], int *cantAcredores,int *cantDeudores)
{
    stCliente cliente;
    for(int i=0; i<v; i++)
    {
        cliente=arrayClientes[i];
        if(cliente.saldo>=0)
        {
            cargarAcredor(acredores,cliente);
            (*cantAcredores)++;
        }
        else
        {
            cargarDeudor(deudores,cliente);
            (*cantDeudores)++;
        }
    }

}

void cargarAcredor(char acredores,stCliente cliente)
{
    FILE*fp;
    fp=fopen(acredores,"ab");
    if(fp!=NULL)
    {
        fwrite(&cliente,sizeof(stCliente),1,fp);
    }
    else
    {
        printf("Error al abrir el archivo.");
    }

}

void cargarDeudor(char deudores,stCliente cliente)
{
    FILE*fp;
    fp=fopen(deudores,"ab");
    if(fp!=NULL)
    {
        fwrite(&cliente,sizeof(stCliente),1,fp);
    }
    else
    {
        printf("Error al abrir el archivo.");
    }

}

int contadorRegistro(char nombreArchivo[])
{
    int cant=0;
    FILE*fp;
    fp=fopen(nombreArchivo,"rb");
    if(fp!=NULL)
    {
        fseek(fp,0,SEEK_END);
        long bytesTotales=ftell(fp);
        cant = bytesTotales/sizeof(stCliente);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return cant;
}

float sumaArchivoTotal(char archivoDeudores,char archivoAcredores)
{
    float suma=sumaArchivo(stCliente,archivoAcredores)+sumaArchivo(stCliente,archivoDeudores);
    return suma;
}
float sumaArchivo(char nombreArchivo[])
{
    float suma;
    stCliente cliente;
    FILE*fp;
    fp=fopen(nombreArchivo,"rb");
    if(fp!=NULL)
    {
        while(fread(&cliente,sizeof(stCliente),1,fp)>0))
        {
            suma=suma+cliente.saldo;
        }
    }
    else
    {
        printf("Error.\n");
    }
    return suma;
}

void mostrarBalanceBanco(stBanco banco)
{
    printf("Porcentaje de deudores: %d\n",banco.deudores);
    printf("Porcentaje de acredores: %d\n",banco.acredores);
    printf("Balance total del banco: %.2f\n",banco.balance);

}
