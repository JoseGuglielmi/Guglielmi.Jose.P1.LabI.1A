/*
 * tipo.h
 *
 *  Created on: 11 may 2022
 *      Author: lufor
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef TIPO_H_
#define TIPO_H_




typedef struct{
int id;
char descripcion[51];
}eTipo;



int buscarTipo(eTipo* listaT, int tamT, int id, int* pIndice);
int cargarDescripcionTipo(eTipo* listaT, int tamT, int id, char* descripcion);
int mostrarTipo(eTipo* listaT);
int listartipo(eTipo* listaT,int tamT);

#endif /* TIPO_H_ */
