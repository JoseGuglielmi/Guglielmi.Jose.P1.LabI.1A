#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajos.h"
#include "servicios.h"
#include "fecha.h"
#include "funciones.h"
#include "notebook.h"

int initTrabajos(eTrabajo *listTr, int tamTr)
{
    int todoOk = 0;

    if (listTr != NULL && tamTr >= 0)
    {
        for (int i = 0; i < tamTr; i++)
        {
            listTr[i].isEmpty = 0;
        }
        todoOk = 1;
    }
    return todoOk;
}

int findTrabajo(eTrabajo *listTr, int tamTr)
{
    int position = -1;

    if (listTr != NULL && tamTr >= 0)
    {
        for (int i = 0; i < tamTr; i++)
        {
            if (listTr[i].isEmpty == 0)
            {
                position = i;
                break;
            }
        }
    }
    return position;
}

int addTrabajo(eNotebook *listN, int tamN, int *idTrabajo, eMarca *listaM, int tamM, eTipo *listaT, int tamT, eServicio *listaS, int tamS, eTrabajo *listTr, int tamTr)
{
    int todoOk = 0;
    eTrabajo auxLista;
    int index;

    if (listN != NULL && idTrabajo != NULL)
    {

        index = findTrabajo(listTr, tamTr);
        if (index == -1)
        {
            printf("No hay espacio en la lista\n");
            system("pause");
        }
        else
        {
            system("cls");
            listarNotebook(listN,tamN,listaM,tamM,listaT,tamT);
            requestDataNumInt("Ingrese id de la notebook: ", "Error. ReIngrese id de la notebook: ", &auxLista.idNotebook, 0,200);
            while (!buscarNotebookId(listN,tamN,auxLista.idNotebook))
            {
                requestDataNumInt("Ingrese id de la notebook: ", "Error. ReIngrese id de la notebook: ", &auxLista.idNotebook, 0,200);
            }
            listarServicios(listaS, tamS);
            requestDataNumInt("Ingrese id del servicio: ", "Error. ReIngrese id del servicio: ", &auxLista.idServicio, 2000, 2003);
            while (!buscarServicio(listaS, tamS,auxLista.idServicio,&index))
            {
                requestDataNumInt("Ingrese id del servicio: ", "Error. ReIngrese id del servicio: ", &auxLista.idServicio, 2000, 2003);
            }
            validarFecha(&auxLista.fecha.dia,&auxLista.fecha.mes, &auxLista.fecha.anio);
            printf("%d", auxLista.fecha.dia);


            auxLista.id = *idTrabajo;
            auxLista.isEmpty = 1;
            listTr[index] = auxLista;
            todoOk = 1;
            system("cls");
            printf("                |nuevo trabajo|\n");
            printf("\n ID  ID Notebook  Servicio  \n");
            mostrarTrabajo(listTr+index,listaS, tamS);
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarTrabajo(eTrabajo *listaTr, eServicio *listaS, int tamS)
{
    int todoOk = 0;
    char descripS[25];


    cargarDescripcionServicio(listaS, tamS, listaTr->idServicio, descripS);



    printf(" %-4d    %-4d   %-10s\n", listaTr->id, listaTr->idNotebook,descripS);
    todoOk = 1;

    return todoOk;
}

int listarTrabajos(eTrabajo *listaTr, int tamTr, eServicio *listaS, int tamS)
{
    int todoOk = 0;
    if (listaTr != NULL && tamTr > 0)
    {
        system("cls");
        printf(" \n\n         ***   Listado de Notebooks   ***\n\n");
        printf(" ID      Modelo       Marca       Tipo   precio\n");

        for (int i = 0; i < tamTr; i++)
        {
            if (listaTr[i].isEmpty)
            {
                mostrarTrabajo(listaTr+i,listaS, tamS);

            }
        }
        todoOk = 1;
    }
    return todoOk;
}
