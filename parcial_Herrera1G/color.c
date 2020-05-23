#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"


void listarColores(eColor colores[],int tamcolor)
{
    printf("\n***** Listado Colores *****\n\n");
    printf("   Id   Descripcion del Color\n");

    for (int i=0; i< tamcolor; i++)
    {

        printf("%d         %10s\n",colores[i].id,colores[i].nombreColor);
    }
    printf("\n\n");
}

int cargarDescripcionColor(char descripcion[], int idColor, eColor colors[], int tamcolores)
{
    int todoOk=0;
    for (int i =0; i< tamcolores; i++)
    {
        if (colors[i].id == idColor)
        {
            strcpy(descripcion, colors[i].nombreColor);
            todoOk =1;
        }
    }
    return todoOk;
}
