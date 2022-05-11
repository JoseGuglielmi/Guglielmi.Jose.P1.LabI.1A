#include "fecha.h"

void validarFecha(int *dia, int *mes, int *anio)
{
    requestDataNumInt("Ingresar mes : \n", "Error ingresar mes valido. \n", mes, 0, 12);

    switch (*mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        requestDataNumInt("Ingresar dia : \n", "Error ingresar dia valido. \n", dia, 0, 31);
        break;

    case 4:
    case 6:
    case 9:
    case 11:

        requestDataNumInt("Ingresar dia : \n", "Error ingresar dia valido. \n", dia, 0, 30);
        break;

    case 2:

        requestDataNumInt("Ingresar dia : \n", "Error ingresar dia valido. \n", dia, 0, 28);
        break;
    }
    requestDataNumInt("Ingresar anio : \n", "Error ingresar anio valido, 1900/2022 \n", anio, 1900, 2022);
}
