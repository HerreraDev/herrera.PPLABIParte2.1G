#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief recorre el array de servicios y muestra los datos
 *
 * \param servicios, vector de servicios
 * \param tamserv, tamaño del vector de servicios
 * \return void
 *
 */
void listarServicios(eServicio servicios[],int tamserv);

/** \brief
 *
 * \param descripcion, variable donde se copiara la descripcion del servicio
 * \param idServicio, id que se va a comparar con el id de la estructura eservicio
 * \param servicios, vector de servicios
 * \param tamserv, tamaño del vector de servicios
 * \return
 *
 */
int cargarDescripcionServicios(char descripcion[], int idServicio, eServicio servicios[], int tamservicios);

/** \brief
 *
 * \param id, id que se servira para compararse con el id de la estructura eservicio
 * \param servicios, vector de servicios
 * \param tamserv, tamaño del vector de servicios
 * \return
 *
 */
int buscarServicio(int id, eServicio lista[], int tamservicio);
