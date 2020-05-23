#include "fecha.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "moto.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief pone en 1 todos los campos isEmpty del array de trabajos
 *
 * \param trabajos, array de trabajos
 * \param tamtrab, tamaño del array de trabajos
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo trabajos[], int tamtrab);

/** \brief devuelve el primer indice libre del array de trabajos
 *
 * \param lista, array de trabajos
 * \param tamtrabajo, tamaño del array de trabajos
 * \return
 *
 */
int buscarIndiceLibreTrabajo(eTrabajo lista[], int tamtrabajo);

/** \brief realiza la carga de un nuevo trabajo
 *
 * \param id, puntero a la direccion de memoria de la variable, que sera incrementada cuando se realice una nueva carga
 * \param motos, array de las motos
 * \param tammotos, tamaño del array de motos
 * \param colores, array de las colores
 * \param tamcolores, tamaño del array de colores
 * \param tipos, array de tipo
 * \param tamtipos, tamaño del array de tipos
 * \param trabajos, array de los trabajos
 * \param tamtrabajo, tamaño del array de trabajos
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \return void
 *
 */
void altaTrabajo(int* id, eMoto motos[],int tammotos, eServicio servicios[], int tamserv,eColor colores[], int tamcolores, eTipo tipos[], int tamtipos, eTrabajo trabajos[], int tamtrabajo, eCliente clientes[], int tamclientes);

/** \brief muestra los datos del trabajo que le llega en la llamada
 *
 * \param trabajo, una entidad de trabajo
 * \param servicios, vector de servicios
 * \param tamserv, tamaño del vector de servicios
 * \param motos, array de las motos
 * \param tammotos, tamaño del array de motos
 * \return
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[],int tamserv, eMoto motos[], int tammotos);

/** \brief muestra una lista de los trabajos
 *
 * \param trabajos, array de los trabajos
 * \param tamtrabajos, tamaño del array de trabajos
 * \param motos, array de las motos
 * \param tammotos, tamaño del array de motos
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trabajos[],int tamtrabajos, eServicio servicios[], int tamserv, eMoto motos[], int tammotos);

/** \brief hardcodea los datos del array de trabajos
 *
 * \param trabajos, array de los trabajos
 * \param tamtrabajos, tamaño del array de trabajos
 * \return
 *
 */
void hardcodearTrabajos(eTrabajo trabajos[], int tamtrabajos);
