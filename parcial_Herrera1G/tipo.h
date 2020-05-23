#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief
 *
 * \param tipos, vector de tipos
 * \param tamtipos, tamaño del vector de tipos
 * \return void
 *
 */
void listarTipos(eTipo tipos[],int tamtipos);


/** \brief
 *
 * \param descripcion, array donde se guardara la descripcion del tipo
 * \param idTipos, id a comparar con los ids de los tipos
 * \param tipos, array de tipos
 * \param tamtipos, tamaño del array de tipos
 * \return
 * \return
 *
 */
int cargarDescripcionTipos(char descripcion[], int idTipos, eTipo tipos[], int tamtipos);
