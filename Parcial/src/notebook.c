#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marcas.h"
#include "servicios.h"
#include "tipo.h"

int menu()
{
    int opcion;

    printf(" \n\n *** Menu de Opciones ***\n");
    printf("1)Alta Notebook\n");
    printf("2)Modificar Notebook\n");
    printf("3)Baja Notebook\n");
    printf("4)Listar Notebook\n");
    printf("5)Listar marcas\n");
    printf("6)Listar tipos\n");
    printf("7)Listar servicios\n");
    printf("8)Alta trabajo\n");
    printf("9)Listar trabajos\n");
    printf("10)Salir\n");

    requestDataNumInt("\nIngrese una opcion: ", "Error. Ingrese una opcion valida: ",
                      &opcion, 1, 10);
    return opcion;
}

int initNotebook(eNotebook *listN, int tamN)
{
    int todoOk = 0;

    if (listN != NULL && tamN >= 0)
    {
        for (int i = 0; i < tamN; i++)
        {
            listN[i].isEmpty = 0;
        }
        todoOk = 1;
    }
    return todoOk;
}

int findNotebook(eNotebook *listN, int tamN)
{
    int position = -1;

    if (listN != NULL && tamN >= 0)
    {
        for (int i = 0; i < tamN; i++)
        {
            if (listN[i].isEmpty == 0)
            {
                position = i;
                break;
            }
        }
    }
    return position;
}

int addNotebook(eNotebook *listN, int tamN, int *id, eMarca *listaM,int tamM, eTipo *listaT,int tamT)
{
    int todoOk = 0;
    eNotebook auxLista;
    int index;

    if (listN != NULL && id != NULL)
    {

        index = findNotebook(listN, tamN);
        if (index == -1)
        {
            printf("No hay espacio en la lista\n");
            system("pause");
        }
        else
        {
            system("cls");

            requestDataTex("Ingrese Modelo: ", "Error. ReIngrese Modelo: ", auxLista.modelo, 20);
            listarMarcas(listaM,tamM);
            requestDataNumInt("Ingrese ID de la marca: ", "Error. ReIngrese ID de la marca: ", &auxLista.idMarca, 1000, 1003);
            listartipo(listaT, tamT);
            requestDataNumInt("Ingrese el tipo: ", "Error. ReIngrese el tipo: ", &auxLista.idTipo, 5000,5003);
            requestDataNumFloat("Ingrese el precio: ", "error. ReIngrese el precio: ", &auxLista.precio, 0, 100000000);
            auxLista.id = *id;
            auxLista.isEmpty = 1;
            listN[index] = auxLista;
            todoOk = 1;
            system("cls");
            printf("                |Nueva notebook|\n");
            printf("\n ID     Modelo        Marca      Tipo     Precio\n");
            mostrarNotebook(listN + index,listaM, tamM, listaT, tamT);
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarNotebook(eNotebook *listaN,eMarca* listaM, int tamM, eTipo* listaT,int tamT)
{
    int todoOk = 0;
    char descripT[25];
    char descripM[25];

    cargarDescripcionMarca(listaM,tamM,listaN->idMarca,descripM);
    cargarDescripcionTipo(listaT, tamT, listaN->idTipo,descripT);


    printf(" %-4d    %-20s   %-10s   %-10s     %-10.5f\n", listaN->id, listaN->modelo, descripM, descripT, listaN->precio);
    todoOk = 1;

    return todoOk;
}

int listarNotebook(eNotebook *listaN, int tamN,eMarca* listaM, int tamM,eTipo *listaT,int tamT)
{
    int todoOk = 0;

    if (listaN != NULL && tamN > 0)
    {
        system("cls");
        printf(" \n\n         ***   Listado de Notebooks   ***\n\n");
        printf(" ID      Modelo       Marca       Tipo   precio\n");

        for (int i = 0; i < tamN; i++)
        {
            if (listaN[i].isEmpty)
            {
                mostrarNotebook(listaN + i,listaM, tamM, listaT, tamT);

            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarNotebookId(eNotebook *listaN, int tamN, int id)
{
    int index = -1;

    for (int i = 0; i <= tamN; i++)
    {
        if (listaN[i].id == id && listaN[i].isEmpty == 1)
        {
            index = i;
            break;
        }
        else
            index = -1;
    }

    return index;
}

int menuMod(eNotebook *listaN,eMarca* listaM, int tamM, eTipo* listaT,int tamT)
{
    int opcion;
    system("cls");
    printf("         *** MENU de modificacion ***\n\n");

    printf(" ID      Modelo       Marca       Tipo   precio\n");
    mostrarNotebook(listaN,listaM, tamM, listaT, tamT);

    printf("1-Modificar Tipo\n");
    printf("2-Modificar Precio\n");
    printf("3-Volver al menu principal\n\n");

    requestDataNumInt("Ingrese una opcion: ", "Error. ReIngrese una opcion: ", &opcion, 1, 3);

    return opcion;
}

int modificarNotebook(eNotebook *listaN, int tamN,eMarca* listaM, int tamM, eTipo* listaT,int tamT)
{
    int todoOk = 0;
    int id = 0;
    int index;
    int exit = 0;

    system("cls");

    if (!listarNotebook(listaN, tamN,listaM, tamM, listaT, tamT))
    {
        system("cls");
        printf("Hubo un error al mostrar las notebooks\n");
    }
    else
    {
        if (!requestDataNumInt("Ingrese el id que desea modificar: ", "Error. ReIngrese un id correcto:", &id, 0, tamN))
        {
            printf("Error al pedir los datos.\n");
        }
        else
        {
            index = buscarNotebookId(listaN, tamN, id);
            while (index == -1)
            {
                requestDataNumInt("Error al encontrar el id, ReIngrese: ", "Error al encontrar el id, ReIngrese: ", &id, 0, 2000);
                index = buscarNotebookId(listaN, tamN, id);
                todoOk = 1;
            }
            do
            {
                switch (menuMod(listaN + index,listaM, tamM, listaT, tamT))
                {
                case 1:
                    requestDataNumInt("Ingrese el tipo: ", "Error. ReIngrese el tipo: ", &listaN[index].idTipo, 1, 4);

                    break;
                case 2:
                    requestDataNumFloat("Ingrese el precio: ", "error. ReIngrese el precio: ", &listaN[index].precio, 0, 100000000);
                    break;
                case 3:
                    exit = 1;
                    todoOk = 1;
                    break;
                default:
                    printf("Opcion invalida ReIngrese\n");
                    system("pause");
                    break;
                }
            } while (exit == 0);
        }
    }

    return todoOk;
}

int bajaNotebook(eNotebook *listaN, int tamN,eMarca* listaM, int tamM, eTipo* listaT,int tamT)
{
    int todoOk = 0;
    int id = 0;
    int index = -1;
    int a;

    if (!listarNotebook(listaN, tamN,listaM, tamM, listaT, tamT))
    {
        system("cls");
        printf("Hubo un error al mostrar los pasajeros\n");
    }
    else
    {
        if (!requestDataNumInt("Ingrese el id que desea dar de baja: ", "Error. ReIngrese un id correcto:", &id, 0, tamN))
        {
            printf("Error al pedir los datos.\n");
        }
        else
        {
            index = buscarNotebookId(listaN, tamN, id);
            while (index == -1)
            {
                requestDataNumInt("Error al encontrar el id, ReIngrese id: ", "Error al encontrar el id, ReIngrese id: ", &id, 0, 2000);
                index = buscarNotebookId(listaN, tamN, id);
                todoOk = 1;
            }
            system("cls");
            mostrarNotebook(listaN + index,listaM, tamM, listaT, tamT);
            requestDataNumInt("Desea eliminarlo? 1 para si 2 para no: ", "Error. Desea eliminarlo? 1 para si 2 para no: ", &a, 1, 2);
            if (a == 1)
            {
                listaN[index].isEmpty = 0;
                todoOk = 1;
            }
            else
            {
                todoOk = 2;
            }
        }
    }

    return todoOk;
}

int ordenarNotebooks(eNotebook *listaN, int tamN)
{
    int todoOk = 0;
    eNotebook auxLista;

    for (int i = 0; i <= tamN; i++)
    {
        for (int j = i + 1; j <= tamN; j++)
        {
            if (listaN[i].idMarca > listaN[j].idMarca && listaN[i].isEmpty == 1 && listaN[j].isEmpty == 1)
            {
                auxLista = listaN[i];
                listaN[i] = listaN[j];
                listaN[j] = auxLista;
            }
        }

    }
    for (int i = 0; i <= tamN; i++)
    {
        for (int j = i + 1; j <= tamN; j++)
        {
            if (listaN[i].precio > listaN[j].precio && listaN[i].isEmpty == 1 && listaN[j].isEmpty == 1)
            {
                auxLista = listaN[i];
                listaN[i] = listaN[j];
                listaN[j] = auxLista;
            }
        }
    }
    todoOk = 1;
    return todoOk;
}
