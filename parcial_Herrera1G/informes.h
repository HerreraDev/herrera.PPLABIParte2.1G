#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "moto.h"
#include "trabajo.h"
#include "cliente.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief funcion que englobara el funcionamiento del menu de los informes
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param cilindradas, array de cilindradas
 * \param tamcilindrada, tamaño del array de cilindradas
 * \param servicios, array de servicios
 * \param tamservicios, tamaño del array de servicios
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \param trabajos, array de trabajos
 * \param tamtrabajos, tamaño del array de trabajos
 * \return void
 *
 */
void informes(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, int cilindradas[], int tamcilindrada, eServicio servicios[], int tamservicios, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos);

/** \brief muestra un menu de informes
 *
 * \return devuelve un entero con la opcion elegida
 *
 */
int menuInformes();

/** \brief lista las motos por el tipo seleccionado
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \return void
 *
 */
void listarMotosPorTipoSeleccionado(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes);

/** \brief lista las motos por el color seleccionado
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \return void
 *
 */
void mostrarMotosPorColorSeleccionada(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes);

/** \brief lista todas las motos con la mayor cilindrada
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \param cilindradas, array de cilindradas
 * \return void
 *
 */
void mostrarMotosDeMayorCilindrada(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, int cilindradas[]);

/** \brief muestra todas las motos de cada tipo
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \param cilindradas, array de cilindradas
 * \return
 *
 */
void informarMotosPorTipo(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes);

/** \brief muestra la cantidad de motos que hay del tipo y color elegido
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \return void
 *
 */
void informarCantidadDeMotosDeTipoYColorElegido(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores);

/** \brief obtiene la cantidad de veces que se eligio el color del id que se le pasa
 *
 * \param idColor, id que se comparara con el idColor del array de motos
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \return
 *
 */
int obtenerTotalColoMotos(int idColor, eMoto motos[], int tammotos);

/** \brief informa cuantas veces fue elegido el color mas elegido y cuales son
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param colores, array de colores
 * \param colores, tamaño del array de colores
 * \return
 *
 */
void informarLosColoresMasElegidos(eMoto motos[], int tammmotos, eColor colores[], int tamcolores);

/** \brief lista los trabajos realizados a la moto que se elige
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param servicios, array de servicios
 * \param tamservicios, tamaño del array de servicios
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \param trabajos, array de trabajos
 * \param tamtrabajos, tamaño del array de trabajos
 * \return void
 *
 */
void informarTrabajosMotos(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios);

/** \brief informa el total de dinero gastado en servicios hechos a una moto elegida
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param servicios, array de servicios
 * \param tamservicios, tamaño del array de servicios
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \param trabajos, array de trabajos
 * \param tamtrabajos, tamaño del array de trabajos
 * \return void
 *
 */
void informarTotalImporteServices(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios);

/** \brief lista a que motos se le hizo el servicio elegido y en que fecha
 *
 * \param motos, array de motos
 * \param tammmotos, tamaño del array de motos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \param colores, array de colores
 * \param tamcolores, tamaño del array de colores
 * \param servicios, array de servicios
 * \param tamservicios, tamaño del array de servicios
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \param trabajos, array de trabajos
 * \param tamtrabajos, tamaño del array de trabajos
 * \return void
 *
 */
void serviciosHechosAMotos(eMoto motos[], int tammmotos, eTipo tipos[],int tamtipos, eColor colores[], int tamcolores, eCliente clientes[], int tamclientes, eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios);

/** \brief lista los servicios y a que moto se le hicieron segun la fecha ingresada
 *
 * \param trabajos, array de trabajos
 * \param tamtrabajos, tamaño del array de trabajos
 * \param servicios, array de servicios
 * \param tamservicios, tamaño del array de servicios
 * \param motos, array de trabajos
 * \param tammotos, tamaño del array de motos
 * \return void
 */
void serviciosPorFecha(eTrabajo trabajos[], int tamtrabajos, eServicio servicios[], int tamservicios, eMoto motos[], int tammotos);
