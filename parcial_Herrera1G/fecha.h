#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief pide las fechas y verifica que sean correctas
 *
 * \param diaAux, puntero de la variable diaAux
 * \param mesAux, puntero de la variable mesAux
 * \param anioAux, puntero de la variable anioAux
 * \return devuelve un entero, 1 si esta todo ok y la fecha es valida, 0 si la fecha es invalida
 *
 */
int ingresarFecha(int* diaAux, int* mesAux, int*anioAux);
