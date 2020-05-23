#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "dataWareHousue.h"
#include "validacionesHerrera.h"





void inicializarMotos(eMoto motos[], int tammoto)
{
    for(int i = 0; i < tammoto; i++)
    {
        motos[i].isEmpty = 1;
    }
}

void hardcodearMotos(eMoto motos[], int tammoto)
{
    for(int i = 0; i < tammoto; i++)
    {
        motos[i].id = idsMotos[i]; //uso los datos pregarcados de la libreria dataWarehouse
        strcpy(motos[i].marca, marcas[i]);
        motos[i].idColor = idsColores[i];
        motos[i].idTipo = idsTipos[i];
        motos[i].cilindradas = Cilindradas[i];
        motos[i].idCliente = idClientes[i];
        motos[i].isEmpty= 0;
    }
}

void mostrarMoto(eMoto moto, eColor colores[],int tamcolor, eTipo tipos[], int tamtipos, eCliente clientes[], int tamclientes)
{
    char descripcionColor[20];
    char descripcionTipo[20];
    char nombreCliente[25];
    cargarDescripcionColor(descripcionColor, moto.idColor, colores,  tamcolor);
    cargarDescripcionTipos(descripcionTipo,moto.idTipo,tipos,tamtipos);
    cargarNombreCliente(nombreCliente,moto.idCliente,clientes,tamclientes);

    printf("\n%d    %10s          %10s          %10s      %d            %10s\n",moto.id,moto.marca,descripcionColor,descripcionTipo,moto.cilindradas,nombreCliente);
}

void mostrarMotos(eMoto motos[],int tammoto, eColor colores[],int tamcolor, eTipo tipos[], int tamtipos, eCliente clientes[], int tamclientes)
{
    int hayMotos = 0;
    printf("\n***** Listado Motos *****\n\n");
    printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");

    for (int i=0; i< tammoto; i++)
    {
        if (motos[i].isEmpty == 0)
        {
            mostrarMoto(motos[i], colores, tamcolor,tipos,tamtipos,clientes,tamclientes);
            hayMotos = 1;
        }
    }

    if (hayMotos == 0)
    {
        printf("\nNo hay Motos que listar \n");
        system("pause");
    }

}





char menu()
{
    char opcion;

    system("cls");
    printf("**** Gestion de Motos **** \n\n");
    printf("a.  Alta motos \n");
    printf("b.  Modificar motos\n");
    printf("c.  Baja motos \n");
    printf("d.  Listar motos ordenadas por tipo e id \n");
    printf("e.  Listar tipos \n");
    printf("f.  Listar colores \n");
    printf("g.  Listar servicios \n");
    printf("h.  Alta trabajo. \n");
    printf("i.  Listar trabajos. \n");
    printf("j.  Informes. \n");
    printf("x.  Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}


int altaMotos(int* proxId, eMoto lista[], int tammoto, eColor colores[], int tamcolor, eTipo tipos[], int tamtipos, int cilindrada[], int tamcilindrada, eCliente clientes[], int tamclientes)
{
    int indice = buscarIndiceLibre(lista, tammoto);

    eMoto auxMoto;

    int todoOk =0;

    int id = *proxId;

    int idCilindrada;
    system("cls");

    printf("***** Alta Moto ***** \n \n");

    if( indice == -1 )    //hay lugar?
    {
        printf("Sistema completo. No hay lugar para nuevos ingresos. \n\n");
    }
    else
    {
        auxMoto.id = id;

        utn_getNombre(auxMoto.marca,20,"Ingrese marca: \n","Error, solo digite letras.\n",3);

        listarTipos(tipos,tamtipos);
        utn_getNumero(&auxMoto.idTipo,"Ingrese el id de un tipo: \n","Error, tipo incorrecto\n",1000,1003,3);

        listarColores(colores,tamcolor);
        utn_getNumero(&auxMoto.idColor,"Ingrese el id del color: \n","Error, color incorrecto \n",10000,10004,3);

        printf("Ingrese una cilindrada\n");
        elegirCilindrada(cilindrada,tamcilindrada);
        fflush(stdin);
        utn_getNumero(&idCilindrada,"Ingrese cilindrada: \n","Error, numero incorrecto.\n",1,5,3);
        switch(idCilindrada)
        {
        case 1:
            auxMoto.cilindradas = cilindrada[0];
            break;
        case 2:
            auxMoto.cilindradas = cilindrada[1];

            break;
        case 3:
            auxMoto.cilindradas = cilindrada[2];

            break;
        case 4:
            auxMoto.cilindradas = cilindrada[3];
            break;
        case 5:
            auxMoto.cilindradas = cilindrada[4];

            break;

        }

        listarClientes(clientes,tamclientes);
        utn_getNumero(&auxMoto.idCliente,"Ingrese el id del cliente: \n","Error, numero incorrecto. \n",50,57,3);


        auxMoto.isEmpty = 0;

        lista[indice] = auxMoto;  //copio al vector el nuevo empleado
        (*proxId)++;
        todoOk =1;
    }
    return todoOk;
}

int buscarIndiceLibre(eMoto lista[], int tammoto)
{
    int indiceLibre = -1;
    for (int i =0 ; i< tammoto; i++)
    {
        if (lista[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}

void elegirCilindrada(int cilindradas[], int tamcilindrada)
{
    for(int i = 0; i < tamcilindrada; i++)
    {
        printf("Opcion %d: %d \n",i+1,cilindradas[i]);
    }
}

void bajaMoto(eMoto motos[],int tammotos, eColor colores[],int tamcolor, eTipo tipos[], int tamtipos, eCliente clientes[], int tamcliente)
{
    int id;
    int indice;
    int confirma;
    system("cls");
    printf("***** Baja Moto ***** \n \n");

    mostrarMotos(motos,tammotos,colores,tamcolor,tipos,tamtipos,clientes,tamcliente);


    utn_getNumero(&id,"Ingrese id: \n","Error, solo numeros.\n",0,1000000,3);

    indice = buscarMoto(id,motos,tammotos);



    if (indice == -1)
    {
        printf("No hay registro Id: %d \n", id);
    }
    else
    {
        system("pause");
        system("cls");
        printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");
        mostrarMoto(motos[indice],colores,tamcolor,tipos,tamtipos,clientes,tamcliente);
        fflush(stdin);
        utn_getNumero(&confirma,"Confirma la baja? 1:SI 2:NO.\n","Error, opcion invalida.\n",1,2,3);
        if (confirma == 1)
        {
            motos[indice].isEmpty = 1;
            printf("Se realizo la baja. \n");
        }
        else
        {
            printf("Se ha cancelado la operacion. \n");
        }
    }
}


void modificarMoto(eMoto motos[], int tammotos,eColor colores[],int tamcolor, int cilindrada[], int tamcilindrada,eTipo tipos[],int tamtipos, eCliente clientes[], int tammclientes)
{

    int id;
    int indice;
    int cambio;
    int nuevoColor;
    int idCilindrada;
    int confirma;

    system("cls");
    printf("***** Modificar Moto ***** \n \n");

    mostrarMotos(motos,tammotos,colores,tamcolor,tipos,tamtipos,clientes,tammclientes);
    utn_getNumero(&id,"Ingrese id de la moto: \n","Error, numero invalido\n",0,10000,3);

    indice = buscarMoto(id,motos,tammotos);

    if (indice == -1)
    {
        printf("No hay registro de una moto con el Id: %d. \n", id);
        system("pause");
    }
    else
    {
        system("pause");
        system("cls");
        printf("Id       Marca                 Color            Tipo     Cilindrada           Cliente \n");
        mostrarMoto(motos[indice],colores,tamcolor,tipos,tamtipos,clientes,tammclientes);
        utn_getNumero(&cambio,"1-Modificar color: \n2-Modificar cilindrada \n","Error, numero erroneo\n.",1,2,3);
        if(cambio == 1)
        {
            listarColores(colores,tamcolor);
            utn_getNumero(&nuevoColor,"Ingrese el id del nuevo color: \n","Error, color incorrecto \n",10000,10004,3);
            utn_getNumero(&confirma,"Confirma la modificacion? 1:SI 2:NO.\n","Error, opcion invalida.\n",1,2,3);
            if (confirma == 1)
            {
                motos[indice].idColor = nuevoColor;
                printf("Se realizo la modificacion. \n");
            }
            else
            {
                printf("Se ha cancelado la operacion. \n");
            }

        }
        else if(cambio == 2)
        {
            elegirCilindrada(cilindrada,tamcilindrada);
            utn_getNumero(&idCilindrada,"Ingrese id de la nueva cilindrada: \n","Error, no es valido el numero\n",1,5,3);
            utn_getNumero(&confirma,"Confirma la modificacion? 1:SI 2:NO.\n","Error, opcion invalida.\n",1,2,3);
            if (confirma == 1)
            {
                switch(idCilindrada)
                {
                case 1:
                    motos[indice].cilindradas = cilindrada[0];
                    break;
                case 2:
                    motos[indice].cilindradas = cilindrada[1];
                    break;
                case 3:
                    motos[indice].cilindradas = cilindrada[2];
                    break;
                case 4:
                    motos[indice].cilindradas = cilindrada[3];
                    break;
                case 5:
                    motos[indice].cilindradas = cilindrada[4];
                    break;
                }
                printf("Se realizo la modificacion.\n");
                system("pause");
            }
            else
            {
                printf("Se ha cancelado la operacion. \n");
            }

        }
        else
        {
            printf("Error, opcion invalida\n");
            system("pause");
        }
    }

}



int buscarMoto(int id, eMoto lista[], int tammoto)
{
    int indiceBuscado = -1;
    for (int i =0; i<tammoto; i++)
    {
        if (lista[i].id == id && lista[i].isEmpty ==0)
        {
            indiceBuscado = i;
            break;
        }
    }
    return indiceBuscado;
}

void motosOrdenadas(eMoto motos[],int tammoto)
{
    eMoto auxMoto;
    for(int i = 0; i < tammoto - 1; i++)
    {
        for(int j = i + 1; j < tammoto; j++)
        {
            if(motos[i].idTipo > motos[j].idTipo)
            {
                auxMoto = motos[i];
                motos[i] = motos[j];
                motos[j] = auxMoto;
            }
            else if(motos[i].idTipo == motos[j].idTipo && motos[i].id < motos[j].id)
            {
                auxMoto = motos[i];
                motos[i] = motos[j];
                motos[j] = auxMoto;
            }
        }
    }
}

int verificarArrayVacio(eMoto lista[], int len)
{
    int succes = 0;
    for(int i = 0; i < len; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            succes = 1;
            break;
        }
    }
    return succes;
}


int cargarMarcaDeMoto(char descripcion[], int idMoto, eMoto motos[], int tammotos)
{
    int todoOk=0;
    for (int i =0; i< tammotos; i++)
    {
        if (motos[i].id == idMoto)
        {
            strcpy(descripcion, motos[i].marca);
            todoOk =1;
        }
    }
    return todoOk;
}
