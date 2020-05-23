#include "tipo.h"
#include "color.h"
#include "cliente.h"

#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindradas;
    int idCliente;
    int isEmpty;

}eMoto;


#endif // MOTO_H_INCLUDED

/** \brief realiza la carga de los datos de la biblioteca datawarehouse en el array de motos
 *
 * \param motos, array de las motos
 * \param tammoto, tamaño del array de motos
 * \return  void
 *
 */
void hardcodearMotos(eMoto motos[], int tammoto);

/** \brief pone en 1 todos los isEmpty  del array de motos
 *
 * \param motos, array de las motos
 * \param tammoto, tamaño del array de motos
 * \return
 *
 */
void inicializarMotos(eMoto motos[], int tammoto);

/** \brief muestra la moto que le llega en la llamada
 *
 * \param moto, una sola entidad de motos
 * \param colores, array de colores
 * \param tamcolor, tamaño del array de colores
 * \param tipos, array de colores
 * \param tamtipos, tamaño del array de tipos
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \return void
 *
 */
void mostrarMoto(eMoto moto, eColor colores[],int tamcolor, eTipo tipos[], int tamtipos, eCliente clientes[], int tamclientes);

/** \brief realiza un listado de las motos
 *
 * \param motos, array de las motos
 * \param tammoto, tamaño del array de motos
 * \param colores, array de colores
 * \param tamcolor, tamaño del array de colores
 * \param tipos, array de colores
 * \param tamtipos, tamaño del array de tipos
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \return void
 *
 */
void mostrarMotos(eMoto motos[],int tammoto, eColor colores[],int tamcolor, eTipo tipos[], int tamtipos, eCliente clientes[], int tamclientes);

/** \brief devuelve el caracetr ingresado
 *
 * \return void
 *
 */
char menu();

/** \brief realiza el proceso de carga de una moto nueva
 *
 * \param proxId, puntero a la direccion de memoria de la variable, que sera incrementada cuando se realice una nueva carga
 * \param lista, array de las motos
 * \param tammoto, tamaño del array de motos
 * \param colores, array de las colores
 * \param tamcolor, tamaño del array de colores
 * \param tipos, array de tipo
 * \param tamtipos, tamaño del array de tipos
 * \param cilindrada, array de las cilindradas
 * \param tamcilindrada, tamaño del array de cilindradas
 * \param clientes, array de clientes
 * \param tamclientes, tamaño del array de clientes
 * \return 1 si esta todo ok, 0 si hubo algun error
 *
 */
int altaMotos(int* proxId, eMoto lista[], int tammoto, eColor colores[], int tamcolor, eTipo tipos[], int tamtipos, int cilindrada[], int tamcilindrada, eCliente clientes[], int tamclientes);

/** \brief devuelve el primer indice libre del array de motos
 *
 * \param motos, array de las motos
 * \param tammoto, tamaño del array de motos
 * \return retora -1 si hubo error o el entero del indice libre
 *
 */
int buscarIndiceLibre(eMoto lista[], int tammoto);

/** \brief lista las cilindradas y que opcion hay que elegir para seleccionar cada cilindrada
 *
 * \param cilindrada, array de las cilindradas
 * \param tamcilindrada, tamaño del array de cilindradas
 * \return void
 *
 */
void elegirCilindrada(int cilindradas[], int tamcilindrada);

/** \brief pide una id y realiza una baja logica
 *
 * \param motos, array de las motos
 * \param tammotos, tamaño del array de motos
 * \param colores, array de las colores
 * \param tamcolor, tamaño del array de colores
 * \param tipos, array de tipo
 * \param tamtipos, tamaño del array de tipos
 * \param clientes, array de clientes
 * \param tamcliente, tamaño del array de clientes
 * \return void
 *
 */
void bajaMoto(eMoto motos[],int tammotos, eColor colores[],int tamcolor, eTipo tipos[], int tamtipos, eCliente clientes[], int tamcliente);

/** \brief verifica que la moto exista, comparando el id ingresado con los id que hay en la lista de motos
 *
 * \param id, es el id que le llegara para verificar si existe
 * \param motos, array de las motos
 * \param tammoto, tamaño del array de motos
 * \return
 *
 */
int buscarMoto(int id, eMoto lista[], int tammoto);

/** \brief da la posibilidad de realizar una modificacion en las motos
 *
 * \param motos, array de las motos
 * \param tammotos, tamaño del array de motos
 * \param colores, array de las colores
 * \param tamcolor, tamaño del array de colores
 * \param tipos, array de tipo
 * \param tamtipos, tamaño del array de tipos
 * \param cilindrada, array de las cilindradas
 * \param tamcilindrada, tamaño del array de cilindradas
 * \param clientes, array de clientes
 * \param tammclientes, tamaño del array de clientes
 * \return void
 *
 */
void modificarMoto(eMoto motos[], int tammotos,eColor colores[],int tamcolor, int cilindrada[], int tamcilindrada,eTipo tipos[],int tamtipos, eCliente clientes[], int tammclientes);

/** \brief ordena el array de motos a traves del burbujeo
 *
 * \param motos, array de las motos
 * \param tammoto, tamaño del array de motos
 * \return void
 *
 */
void motosOrdenadas(eMoto motos[],int tammoto);

/** \brief verifica que el array este vacio
 *
 * \param lista, array de motos
 * \param len, tamaño del array de motos
 * \return devuelve un entero, 0 si el array esta vacio o 1 si no lo esta
 *
 */
int verificarArrayVacio(eMoto lista[], int len);

/** \brief copia la marca de la moto en el array descripcion
 *
 * \param descripcion, array donde se guardara la marca de la moto
 * \param idMoto, id a comparar
 * \param motos, array de motos
 * \param tammotos, tamaño del array de motos
 * \return
 *
 */
int cargarMarcaDeMoto(char descripcion[], int idMoto, eMoto motos[], int tammotos);
