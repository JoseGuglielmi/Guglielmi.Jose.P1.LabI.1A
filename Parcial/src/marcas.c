#include "marcas.h"

int cargarDescripcionMarca(eMarca *listaM, int tamM, int id, char *descripcion)
{
    int todoOk = 0;
    int indice;

    buscarMarca(listaM, tamM, id, &indice);

    if (descripcion != NULL && indice != -1)
    {
        strcpy(descripcion, listaM[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int buscarMarca(eMarca *listaM,int tamM,int id,int *indice)
{
    int todoOk = 0;
    if (listaM != NULL && tamM > 0 && indice != NULL)
    {
        *indice = -1;
        for (int i = 0; i < tamM; i++)
        {
            if (listaM[i].id == id)
            {
                *indice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMarca(eMarca *lista)
{
    int todoOk = 0;
    printf("%04d  %s \n", lista->id, lista->descripcion);
    return todoOk;
}

int listarMarcas(eMarca *lista, int tamM)
{
    int todoOk = 0;
    if (lista != NULL && tamM > 0)
    {

        printf("  ***Listado de Marcas***\n\n");
        printf(" ID      Marca  \n");
        printf("------------------\n");
        for (int i = 0; i < tamM; i++)
        {
            mostrarMarca(lista + i);
        }
        todoOk = 1;
    }
    return todoOk;

    return todoOk;
}

