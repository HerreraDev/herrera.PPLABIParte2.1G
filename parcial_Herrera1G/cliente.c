#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


void listarClientes(eCliente clientes[],int tamclientes)
{
    printf("\n***** Listado Clientes *****\n\n");
    printf("Id      Nombre      Sexo\n");

    for (int i=0; i< tamclientes; i++)
    {

        printf("%d    %10s    %c\n",clientes[i].id,clientes[i].nombre,clientes[i].sexo);
    }
    printf("\n\n");
}


int cargarNombreCliente(char descripcion[], int idCliente, eCliente clientes[], int tammclientes)
{
    int todoOk=0;
    for (int i =0; i< tammclientes; i++)
    {
        if (clientes[i].id == idCliente)
        {
            strcpy(descripcion, clientes[i].nombre);
            todoOk =1;
        }
    }
    return todoOk;
}
