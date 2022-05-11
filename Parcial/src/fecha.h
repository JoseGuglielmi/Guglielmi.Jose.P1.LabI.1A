#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

#ifndef FECHA_H_
#define FECHA_H_




typedef struct {
	int dia;
	int mes;
	int anio;
}
eFecha;

void validarFecha(int *dia, int *mes, int *anio);

#endif /* FECHA_H_ */
