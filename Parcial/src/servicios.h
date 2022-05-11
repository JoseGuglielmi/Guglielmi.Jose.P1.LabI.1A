/*
 * servicios.h
 *
 *  Created on: 11 may 2022
 *      Author: lufor
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef SERVICIOS_H_
#define SERVICIOS_H_




typedef struct{
int id;
char descripcion[25];
float precio;
}eServicio;



int mostrarServicio(eServicio* listaS);
int listarServicios(eServicio* listaS, int tamS);
int cargarDescripcionServicio(eServicio* listaS, int tamS, int id, char* descripcion);
int buscarServicio(eServicio* listaS, int tamS, int id, int* pIndice);

#endif /* SERVICIOS_H_ */
