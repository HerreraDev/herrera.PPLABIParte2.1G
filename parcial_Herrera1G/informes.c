#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "validacionesHerrera.h"



void informes(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, int cilindradas[], int tamcilindrada, eServicio servicios[], int tamservicios, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos)
{
    char seguir = 's';

    do
    {
        switch(menuInformes())
        {
        case 1:
            mostrarMotosPorColorSeleccionada(motos,tammmotos,tipos,tamtipos,colores,tamcolores,clientes,tamclientes);
            break;
        case 2:
            listarMotosPorTipoSeleccionado(motos,tammmotos,tipos,tamtipos,colores,tamcolores,clientes,tamclientes);
            break;
        case 3:
            mostrarMotosDeMayorCilindrada(motos,tammmotos,tipos,tamtipos,colores,tamcolores,clientes,tamclientes,cilindradas);
            break;
        case 4:
            informarMotosPorTipo(motos,tammmotos,tipos,tamtipos,colores,tamcolores,clientes,tamclientes);
            break;
        case 5:
            informarCantidadDeMotosDeTipoYColorElegido(motos,tammmotos,tipos,tamtipos,colores,tamcolores);
            break;
        case 6:
            informarLosColoresMasElegidos(motos,tammmotos,colores,tamcolores);
            break;
        case 7:
            informarTrabajosMotos(motos,tammmotos,tipos,tamtipos,colores,tamcolores,clientes,tamclientes,trabajos,tamtrabajos,servicios,tamservicios);
            break;
        case 8:
            informarTotalImporteServices(motos,tammmotos,tipos,tamtipos,colores,tamcolores,clientes,tamclientes,trabajos,tamtrabajos,servicios,tamservicios);
            break;
        case 9:
            serviciosHechosAMotos(motos,tammmotos,tipos,tamtipos,colores,tamcolores,clientes,tamclientes,trabajos,tamtrabajos,servicios,tamservicios);
            break;
        case 10:
            serviciosPorFecha(trabajos,tamtrabajos,servicios,tamservicios,motos,tammmotos);
            break;
        case 11:
            seguir = 'n';
            break;
        }
        system("pause");

    }
    while ( seguir == 's');

}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("**** Informes de motos **** \n\n");
    printf("1.  Mostrar las motos del color seleccionada.\n");
    printf("2.  Mostrar las motos del tipo seleccionada. \n");
    printf("3.  Mostrar la o las motos de mayor cilindrada. \n");
    printf("4.  Mostrar listado de motos separados por tipo. \n");
    printf("5.  Elegir color y tipo y contar cuantas hay de ese color y de ese tipo.\n");
    printf("6.  Mostrar el o los colores mas elegidos por los clientes. \n");
    printf("7.  Informe de los trabajos realizados a una moto. \n");
    printf("8.  Importe total de los servicios realizados a una moto. \n");
    printf("9.  Elegir servicio y mostrar a que moto se le realizo y en que fecha. \n");
    printf("10. Elegir una fecha y mostrar los servicios realizados en la misma. \n");
    printf("11. Salir. \n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}


void listarMotosPorTipoSeleccionado(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes)
{
    int tipo;
    int hayMotos = 0;

    system("cls");
    listarTipos(tipos,tamtipos);
    if(utn_getNumero(&tipo,"Ingrese el id de un tipo: \n","Error, tipo incorrecto\n",1000,1003,3)==-1)
    {
        printf("Se acabaron los intentos.\n");
    }
    else
    {
        system("pause");
        system("cls");
        printf("**** Listado de motos por tipo ingresado ****\n\n");
        printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");

        for (int i=0; i< tammmotos; i++)
        {
            if (motos[i].isEmpty == 0 && motos[i].idTipo == tipo)
            {
                mostrarMoto(motos[i], colores, tamcolores,tipos,tamtipos,clientes,tamclientes);
                hayMotos = 1;
            }
        }


        if ( hayMotos == 0)
        {
            printf("\nNo hay motos de ese tipo. \n");
        }
    }
}

void mostrarMotosPorColorSeleccionada(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes)
{
    int color;
    int hayMotos = 0;

    system("cls");

    listarColores(colores,tamcolores);
    if(utn_getNumero(&color,"Ingrese el id del color: \n","Error, color incorrecto \n",10000,10004,3)==-1)
    {
        printf("Error, se acabaron los intentos.\n");
    }
    else
    {
        system("pause");
        system("cls");
        printf("**** Listado de motos por color ingresado ****\n\n");
        printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");

        for (int i=0; i< tammmotos; i++)
        {
            if (motos[i].isEmpty == 0 && motos[i].idColor == color)
            {
                mostrarMoto(motos[i], colores, tamcolores,tipos,tamtipos,clientes,tamclientes);
                hayMotos = 1;
            }
        }

        if ( hayMotos == 0)
        {
            printf("\nNo hay motos de ese color. \n");
        }
    }


}

void mostrarMotosDeMayorCilindrada(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, int cilindradas[])
{

    int flagMoto = 0;
    system("cls");
    printf("\n** Listado de moto/s de mayor cilindrada**\n\n");
    printf("La mayor cilindrada es 750 y la/s moto/s con dicha cilindrada es/son: \n\n");
    printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");

    for (int i = 0; i <  tammmotos;  i++)
    {
        if ( motos[i].isEmpty == 0 && motos[i].cilindradas == 750)
        {
            mostrarMoto(motos[i],colores,tamcolores,tipos,tamtipos,clientes,tamclientes);
            flagMoto = 1;
        }
    }
    if(flagMoto == 0)
    {
        printf("No hay motos con esa cilindrada.\n");
    }

    system("pause");
}

void informarMotosPorTipo(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes)
{
    int flag;
    system("cls");
    printf("** Listado de motos de todos los tipos **\n\n");
    printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");

    for(int s = 0; s < tamtipos; s++)
    {
        flag = 0;
        printf("Tipos: %s\n",tipos[s].descripcion);
        for(int e = 0; e < tammmotos; e++)
        {
            if(motos[e].isEmpty == 0 && motos[e].idTipo == tipos[s].id)
            {
                mostrarMoto(motos[e], colores, tamcolores,tipos,tamtipos,clientes,tamclientes);
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf("No hay motos de ese tipo.\n");
    }

}

void informarCantidadDeMotosDeTipoYColorElegido(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores)
{
    int flag;
    int tipo;
    int color;
    int contador = 0;

    listarColores(colores,tamcolores);
    if(utn_getNumero(&color,"Ingrese el id del color: \n","Error, color incorrecto \n",10000,10004,3)==-1)
    {
        printf("Error, se acabaron los intentos.\n");
    }
    else
    {
        listarTipos(tipos,tamtipos);
        if(utn_getNumero(&tipo,"Ingrese el id de un tipo: \n","Error, tipo incorrecto\n",1000,1003,3)==-1)
        {
            printf("Se acabaron los intentos.\n");
        }
        else
        {
            system("pause");
            system("cls");
            for (int i=0; i< tammmotos; i++)
            {
                if (motos[i].isEmpty == 0 && motos[i].idColor == color && motos[i].idTipo == tipo)
                {
                    contador++;
                    flag = 1;
                }
            }

            if(flag==0)
            {
                printf("No hay de ese tipo o color.\n");
                system("pause");
            }
            else
            {
                printf("Hay %d motos de ese color y tipo \n",contador);
            }

        }

    }
}


void informarLosColoresMasElegidos(eMoto motos[], int tammmotos, eColor colores[], int tamcolores)
{
    system("cls");
    printf("**** Color mas elegido ****\n\n");

    int totalColoers[tamcolores];
    int mayor;
    int flag = 0;

    for(int i = 0; i < tamcolores; i++)
    {
        totalColoers[i] = obtenerTotalColoMotos(colores[i].id,motos,tammmotos);
    }

    for(int i = 0; i < tamcolores; i++)
    {
        if(totalColoers[i] > mayor || flag == 0)
        {
            mayor = totalColoers[i];
            flag=1;
        }
    }

    printf("El color mas elegido fue elegido %d de veces y es o son los siguientes:\n",mayor);

    for(int i = 0; i < tamcolores; i++)
    {
        if(totalColoers[i] == mayor)
        {
            printf("%s\n",colores[i].nombreColor);
        }
    }


    system("pause");
}



int obtenerTotalColoMotos(int icColor, eMoto motos[], int tammotos)
{
    int totalColor = 0;
    for(int i = 0; i < tammotos; i++)
    {
        if(motos[i].isEmpty == 0 && motos[i].idColor == icColor)
        {
            totalColor++;
        }
    }
    return totalColor;
}

void informarTrabajosMotos(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios)
{
    int idMoto;
    int existe;
    int flag = 0;
    system("cls");

    mostrarMotos(motos,tammmotos,colores,tamcolores,tipos,tamtipos,clientes,tamclientes);

    printf("Ingresar id de moto: ");
    scanf("%d", &idMoto);



    existe = buscarMoto(idMoto,motos,tammmotos);
    if(existe==-1)
    {
        printf("No hay motos con el id: %d",idMoto);
        system("pause");
    }
    else
    {
        system("pause");
        system("cls");
        printf("***** Listado de trabajos de la moto elegida***** \n\n");
        printf("IdTrabajo    idMoto      Marca      Servicio           Fecha\n");
        for(int i = 0; i < tamtrabajos; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == idMoto)
            {
                mostrarTrabajo(trabajos[i], servicios, tamservicios,motos,tammmotos);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay trabajos para esa moto.\n");
            system("pause");
        }

    }
}

void informarTotalImporteServices(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios)
{
    float sumaTotal = 0;
    int idMoto;
    int indiceServicio;
    int indiceMoto;
    system("cls");
    mostrarMotos(motos,tammmotos,colores,tamcolores,tipos,tamtipos,clientes,tamclientes);

    printf("Ingresar id de moto: ");
    scanf("%d", &idMoto);


    indiceMoto = buscarMoto(idMoto,motos,tammmotos);

    if(indiceMoto == -1)
    {
        printf("No existe moto con el id %d \n",idMoto);
        system("pause");
    }
    else
    {
        for(int i = 0; i < tamtrabajos; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == idMoto)
            {
                indiceServicio = buscarServicio(trabajos[i].idServicio,servicios,tamservicios);
                sumaTotal += servicios[indiceServicio].precio;
            }
        }
        if(sumaTotal == 0)
        {
            printf("No hay trabajos realizados a dicha moto\n");
        }
        else
        {
            system("pause");
            system("cls");
            printf("La suma total de los servicios hechos en esa moto son de: %.2f \n",sumaTotal);
        }

    }

}

void serviciosHechosAMotos(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios)
{
    int idServicio;
    char descripcionServicio[25];
    system("cls");
    printf("****** Lista de servicios hechos a las motos ****** \n");

    listarServicios(servicios,tamservicios);
    if(utn_getNumero(&idServicio,"Ingrese id del servicio\n","Error, numero  invalido.\n",20000,20004,3) == -1)
    {
        printf("No existe dicho servicio.\n");
    }
    else
    {
        system("pause");
        system("cls");
        cargarDescripcionServicios(descripcionServicio,idServicio,servicios,tamservicios);
        printf("Listado de cuando y a que moto se le realizo el servicio %s:\n\n",descripcionServicio);
        printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n\n");
        for(int i = 0; i < tamtrabajos; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
            {
                for(int m = 0; m < tammmotos; m++)
                {
                    if(motos[m].isEmpty == 0 && motos[m].id == trabajos[i].idMoto)
                    {
                        printf("En la fecha %d/%d/%d se realizo el servicio a las siguientes motos: \n",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);
                        mostrarMoto(motos[m],colores,tamcolores,tipos,tamtipos,clientes,tamclientes);
                    }
                }
            }
        }
    }

}


void serviciosPorFecha(eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios, eMoto motos[], int tammotos)
{
    int auxDia;
    int auxMes;
    int auxAnio;
    int verificarFecha;
    char descripcion[25];
    int flag = 0;

    do
    {
        verificarFecha = ingresarFecha(&auxDia, &auxMes, &auxAnio);
    }
    while(verificarFecha != 1);
    system("cls");
    printf("**** Listado de servicios realizados en dicha feca ****\n\n");
    printf("IdTrabajo    idMoto      Marca      Servicio           Fecha\n");

    for(int i = 0; i < tamtrabajos; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].fecha.dia == auxDia && trabajos[i].fecha.mes == auxMes && trabajos[i].fecha.anio == auxAnio)
        {
            cargarDescripcionServicios(descripcion,trabajos[i].idServicio,servicios,tamservicios);
            mostrarTrabajo(trabajos[i],servicios,tamservicios,motos,tammotos);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No se realizaron servicios esa fecha.\n\n");
    }

}
