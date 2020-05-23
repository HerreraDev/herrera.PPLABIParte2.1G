#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[25];
    char sexo;

}eCliente;


#endif // CLIENTE_H_INCLUDED

/** \brief recorre el listado de clientes y muestra los datos
 *
 * \param clientes, vector de clientes
 * \param tamclientes, es el tamaño del vector de clientes
 * \return void
 *
 */
void listarClientes(eCliente clientes[],int tamclientes);

/** \brief
 *
 * \param descripcion, vector de caracteres donde se guardara el nombre del cliente
 * \param idCliente, entero que se refiere al idCliente a comparar con el id del de la estructura cliente
 * \param clientes, vector de clientes
 * \param tammclientes, es el tamaño del vector de clientes
 * \return devuelve un entero, 1 si todo esta OK y 0 si hubo error
 *
 */
int cargarNombreCliente(char descripcion[], int idCliente, eCliente clientes[], int tammclientes);
