/*
 * marcas.h
 *
 *  Created on: 11 may 2022
 *      Author: lufor
 */

#ifndef MARCAS_H_
#define MARCAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

typedef struct{
int id;
char descripcion[20];
}eMarca;

int buscarMarca(eMarca *listaM,int tamM,int id, int *indice);
int cargarDescripcionMarca(eMarca *listaM, int tamM, int id, char *descripcion);
int listarMarcas(eMarca *lista, int tamM);
int mostrarMarca(eMarca *lista);

#endif /* MARCAS_H_ */
