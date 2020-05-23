#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED


/** \brief lista los colroes del array colores
 *
 * \param colores, array de colores
 * \param tamcolor, tamaño del array de colores
 * \return void
 *
 */
void listarColores(eColor colores[],int tamcolor);

/** \brief copia la descripcion del color en el array descripcion
 *
 * \param descripcion, array donde se guardara el nombre del color
 * \param idColor, id a comparar con los ids de los colores
 * \param colores, array de colores
 * \param tamcolor, tamaño del array de colores
 * \return
 *
 */
int cargarDescripcionColor(char descripcion[], int idColor, eColor colores[], int tamcolores);
