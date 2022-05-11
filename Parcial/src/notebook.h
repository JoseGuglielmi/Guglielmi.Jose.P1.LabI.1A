/*
 * notebook.h
 *
 *  Created on: 11 may 2022
 *      Author: lufor
 */
#include "funciones.h"
#include "marcas.h"
#include "servicios.h"
#include "tipo.h"
#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_





typedef struct{
int id;
char modelo[20];
int idMarca;
int idTipo;
float precio;
int isEmpty;
}eNotebook;



int menu();
int initNotebook(eNotebook *listN, int tamN);
int findNotebook(eNotebook *listN, int tamN);
int addNotebook(eNotebook *listN, int tamN, int *id, eMarca *listaM,int tamM, eTipo *listaT,int tamT);
int mostrarNotebook(eNotebook *listaN,eMarca* listM, int tamM,eTipo* listaT,int tamT);
int listarNotebook(eNotebook *listaN, int tamN,eMarca* listaM, int tamM,eTipo *listaT,int tamT);
int modificarNotebook(eNotebook *listaN, int tamN,eMarca* listaM, int tamM, eTipo* listaT,int tamT);
int menuMod(eNotebook *listaN,eMarca* listaM, int tamM, eTipo* listaT,int tamT);
int buscarNotebookId(eNotebook *listaN, int tamN, int id);
int bajaNotebook(eNotebook *listaN, int tamN,eMarca* listaM, int tamM, eTipo* listaT,int tamT);
int ordenarNotebooks(eNotebook *listaN, int tamN);

#endif /* NOTEBOOK_H_ */
