#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listarTipos(eTipo tipos[],int tamtipos)
{
    printf("\n***** Listado Tipos *****\n\n");
    printf("   Id   Descripcion del Tipo\n");

    for (int i=0; i< tamtipos; i++)
    {

        printf("%d         %10s\n",tipos[i].id,tipos[i].descripcion);
    }
    printf("\n\n");
}

int cargarDescripcionTipos(char descripcion[], int idTipos, eTipo tipos[], int tamtipos)
{
    int todoOk=0;
    for (int i =0; i< tamtipos; i++)
    {
        if (tipos[i].id == idTipos)
        {
            strcpy(descripcion, tipos[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;
}
