/*
 * trabajos.h
 *
 *  Created on: 11 may 2022
 *      Author: lufor
 */
#include "fecha.h"
#include "notebook.h"

#ifndef TRABAJOS_H_
#define TRABAJOS_H_





typedef struct{
int id;
int idNotebook;
int idServicio;
eFecha fecha;
int isEmpty;
}eTrabajo;



int addTrabajo(eNotebook *listN, int tamN, int *id, eMarca *listaM, int tamM, eTipo *listaT, int tamT, eServicio *listaS, int tamS, eTrabajo *listTr, int tamTr);
int findTrabajo(eTrabajo *listTr, int tamTr);
int initTrabajos(eTrabajo *listTr, int tamTr);
int mostrarTrabajo(eTrabajo *listaTr, eServicio *listaS, int tamS);
int listarTrabajos(eTrabajo *listaTr, int tamTr, eServicio *listaS, int tamS);


#endif /* TRABAJOS_H_ */
