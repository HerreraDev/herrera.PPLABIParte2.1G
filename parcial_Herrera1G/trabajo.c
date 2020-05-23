#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "validacionesHerrera.h"



void inicializarTrabajos(eTrabajo trabajos[], int tamtrab)
{
    for(int i = 0; i < tamtrab; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int buscarIndiceLibreTrabajo(eTrabajo lista[], int tamtrabajo)
{
    int indiceLibre = -1;
    for (int i =0 ; i< tamtrabajo; i++)
    {
        if (lista[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}

void altaTrabajo(int* id, eMoto motos[],int tammotos, eServicio servicios[], int tamserv,eColor colores[], int tamcolores, eTipo tipos[], int tamtipos, eTrabajo trabajos[], int tamtrabajo, eCliente clientes[], int tamclientes)
{
    int idMoto;
    int existe;
    int indice;
    eTrabajo auxTrabajo;
    int verificarFecha = 0;

    int idx;
    idx = *id;

    auxTrabajo.id = idx;

    indice = buscarIndiceLibreTrabajo(trabajos,tamtrabajo);

    if(indice == -1)
    {
        printf("No hay lugar para dar de alta mas trabajos.\n");
        system("pause");
    }
    else
    {
        mostrarMotos(motos,tammotos,colores,tamcolores,tipos,tamtipos,clientes,tamclientes);
        printf("Ingrese id de la moto: \n");
        scanf("%d",&idMoto);

        existe = buscarMoto(idMoto,motos,tammotos);

        if(existe == -1)
        {
            printf("No hay moto con esa id\n");
            system("pause");
        }
        else
        {
            system("pause");
            system("cls");
            printf("La moto a la que se le realizara el serivio es la siguiente: \n\n");
            printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");
            auxTrabajo.idMoto = idMoto;
            mostrarMoto(motos[existe],colores,tamcolores,tipos,tamtipos,clientes,tamclientes);

            listarServicios(servicios,tamserv);
            if(utn_getNumero(&auxTrabajo.idServicio,"Ingrese id del servicio\n","Error, numero  invalido.\n",20000,20004,3) == -1)
            {
                printf("No existe dicho servicio.\n");
            }
            else
            {
                do
                {
                    verificarFecha = ingresarFecha(&auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
                }while(verificarFecha != 1);
                trabajos[indice] = auxTrabajo;
                trabajos[indice].isEmpty = 0;
                (*id)++;
            }
        }
    }
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[],int tamserv, eMoto motos[], int tammotos)
{
    char descripcion[25];
    char marca[20];
    cargarMarcaDeMoto(marca,trabajo.idMoto,motos,tammotos);
    cargarDescripcionServicios(descripcion,trabajo.idServicio,servicios,tamserv);
    printf("%d          %d     %10s      %10s          %d/%d/%d \n",trabajo.id,trabajo.idMoto,marca,descripcion,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
}

void mostrarTrabajos(eTrabajo trabajos[],int tamtrabajos, eServicio servicios[], int tamserv, eMoto motos[], int tammotos)
{
    int hayTrabajo = 0;
    printf("\n***** Listado Trabajos *****\n\n");
    printf("IdTrabajo    idMoto      Marca      Servicio           Fecha\n");

    for (int i=0; i< tamtrabajos; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamserv,motos,tammotos);
            hayTrabajo = 1;
        }
    }
    if (hayTrabajo == 0)
    {
        printf("\nNo hay trabajos que listar \n");
    }
}

void hardcodearTrabajos(eTrabajo trabajos[], int tamtrabajos)
{
    int idsTrabajos[] = {20,21,22,23,24,25,26,27,28,29};
    int idsMotosTrabajos[]={11,12,13,12,15,17,19,18,17,10};
    int idsServicios[] = {20000,20002,20003,20001,20003,20001,20002,20001,20003,20000};
    int dias[] = {5,8,12,10,5,18,22,26,27,30};
    int meses[] = {1,4,5,6,1,7,12,11,10,9};
    int anios[] =  {2010,2012,2008,2003,2010,2019,2020,2017,2016,2015};

    for(int i = 0; i < tamtrabajos; i++)
    {
        trabajos[i].id =  idsTrabajos[i];
        trabajos[i].idMoto = idsMotosTrabajos[i];
        trabajos[i].idServicio = idsServicios[i];
        trabajos[i].fecha.dia = dias[i];
        trabajos[i].fecha.mes = meses[i];
        trabajos[i].fecha.anio = anios[i];
        trabajos[i].isEmpty= 0;
    }
}


