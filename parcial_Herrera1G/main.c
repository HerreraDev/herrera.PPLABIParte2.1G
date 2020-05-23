#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "moto.h"
#include "trabajo.h"
#include "cliente.h"
#include "informes.h"


#define TAMMOTOS 10
#define TAMTIPOS 4
#define TAMCOLOR 5
#define TAMSERVICIO 4
#define TAMCILINDRADA 5
#define TAMCLIENTES 8
#define TAMTRABAJOS 10

#define TAMHARDCODEO 8



int main()
{
    eTipo tipos[TAMTIPOS] =
    {
        {1000,"Enduro"},
        {1001,"Chopera"},
        {1002,"Scooter"},
        {1003,"Ciclomotor"}
    };

    eColor colores[TAMCOLOR] =
    {
        {10000,"Gris"},
        {10001,"Negro"},
        {10002,"Blanco"},
        {10003,"Azul"},
        {10004,"Rojo"}
    };
    eServicio servicios[TAMSERVICIO] =
    {
        {20000,"Limpieza",250},
        {20001,"Ajuste",300},
        {20002,"Balanceo",17},
        {20003,"Cadena",190},
    };

    int cilindrada[TAMCILINDRADA] = {50,125,500,600,750};

    eCliente clientes[TAMCLIENTES] = {
        {50,"Ana",'f'},
        {51,"Pedro",'m'},
        {52,"Jose",'m'},
        {53,"Maria",'f'},
        {54,"Marisol",'f'},
        {55,"Juan",'m'},
        {56,"Alberto",'m'},
        {57,"Isabel",'f'},
    };


    int seguir = 's';
    int proxIdMoto = 10;
    int proxIdTrab = 20;
    int listaVacia = 0;
    eMoto motos[TAMMOTOS];
    eTrabajo trabajos[TAMTRABAJOS];

    inicializarMotos(motos,TAMMOTOS);
    inicializarTrabajos(trabajos,TAMTRABAJOS);

    hardcodearMotos(motos,TAMHARDCODEO);
    proxIdMoto += TAMHARDCODEO;
    hardcodearTrabajos(trabajos,TAMHARDCODEO);
    proxIdTrab += TAMHARDCODEO;

    do
    {
        if(verificarArrayVacio(motos,TAMMOTOS)==0)
        {
            listaVacia = 1;
        }
        switch(menu())
        {
        case 'a':
            if(altaMotos(&proxIdMoto,motos,TAMMOTOS,colores,TAMCOLOR,tipos,TAMTIPOS,cilindrada,TAMCILINDRADA,clientes,TAMCLIENTES)==1)
            {
                listaVacia = 0;
            }
            break;
        case 'b':
            if(listaVacia == 1)
            {
                printf("Sistema vacio, realice al menos una carga.\n");
            }
            else
            {
                modificarMoto(motos, TAMMOTOS,colores,TAMCOLOR,cilindrada,TAMCILINDRADA,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            }
            break;
        case 'c':
            if(listaVacia == 1)
            {
                printf("Sistema vacio, realice al menos una carga.\n");
            }
            else
            {
                bajaMoto(motos,TAMMOTOS,colores,TAMCOLOR,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            }
            break;
        case 'd':
            if(listaVacia == 1)
            {
                printf("Sistema vacio, realice al menos una carga.\n");
            }
            else
            {
                motosOrdenadas(motos,TAMMOTOS);
                mostrarMotos(motos,TAMMOTOS,colores,TAMCOLOR,tipos,TAMTIPOS,clientes,TAMCLIENTES);
            }
            break;
        case 'e':
            listarTipos(tipos,TAMTIPOS);
            break;
        case 'f':
            listarColores(colores,TAMCOLOR);
            break;
        case 'g':
            listarServicios(servicios,TAMSERVICIO);
            break;
        case 'h':
            altaTrabajo(&proxIdTrab,motos,TAMMOTOS,servicios,TAMSERVICIO,colores,TAMCOLOR,tipos,TAMTIPOS,trabajos,TAMTRABAJOS,clientes,TAMCLIENTES);
            break;
        case 'i':
            mostrarTrabajos(trabajos,TAMTRABAJOS,servicios,TAMSERVICIO,motos,TAMMOTOS);
            break;
        case 'j':
            informes(motos,TAMMOTOS,tipos,TAMTIPOS,colores,TAMCOLOR,cilindrada,TAMCILINDRADA,servicios,TAMSERVICIO,clientes,TAMCLIENTES,trabajos,TAMTRABAJOS);
            break;
        case 'x':
            seguir = 'n';
            break;

        }

        system("pause");
    }
    while ( seguir == 's');
    return 0;
}




