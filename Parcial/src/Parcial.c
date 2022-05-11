#include "notebook.h"
#include "marcas.h"
#include "servicios.h"
#include "trabajos.h"

#define TAMN 200
#define TAMM 4
#define TAMS 4
#define TAMT 4
#define TAMTR 200

int main()
{
    int id = 1;
    int idTr = 1;
    eNotebook listaN[TAMN];
    eMarca listaM[TAMM] = {{1000, "Compaq"}, {1001, "Asus"}, {1002, "Acer"}, {1003, "HP"}};
    eServicio listaS[TAMT] = {{2000, "Bateria", 2250}, {2001, "Display", 10300}, {2002, "Mantenimiento", 4400}, {2003, "Fuente", 5600}};
    eTipo listaT[TAMT] = {{5000, "Gamer"}, {5001, "Disenio"}, {5002, "Ultrabook"}, {5003, "Normalita"}};
    eTrabajo listaTr[TAMTR];
    int baja;
    int addN = 0;
    int addTr = 0;

    int salir = 0;

    if (initNotebook(listaN, TAMN))
    {
        do
        {
            system("cls");
            switch (menu())
            {

            case 1:
                if (addNotebook(listaN, TAMN, &id, listaM, TAMM, listaT, TAMT))
                {
                    printf("Baja exitosa\n");
                    id++;
                    addN++;
                }
                else
                {
                    printf("Error al ingresar una notebook");
                }
                break;
            case 2:
                if (addN != 0)
                {
                    if (modificarNotebook(listaN, TAMN, listaM, TAMM, listaT, TAMT))
                    {
                        printf("Modificacion exitosa\n");
                        system("pause");
                    }
                    else
                    {
                        printf("hubo un error\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Ingrese notebooks antes de modificarlos\n");
                }

                break;
            case 3:
                if (addN != 0)
                {
                    baja = bajaNotebook(listaN, TAMN, listaM, TAMM, listaT, TAMT);
                    if (baja == 1)
                    {
                        printf("Baja exitosa\n");
                        system("pause");
                    }
                    else if (baja == 2)
                    {
                        printf("Baja Canselada\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Error al dar de baja\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Ingrese notebooks antes de dar de baja\n");
                }
                break;
            case 4:
                if (addN != 0)
                {
                    ordenarNotebooks(listaN, TAMN);
                    listarNotebook(listaN, TAMN, listaM, TAMM, listaT, TAMT);
                }
                else
                {
                    printf("Ingrese notebooks antes de listarlos\n");
                }
                break;
            case 5:
                if (!listarMarcas(listaM, TAMM))
                {
                    printf("error al mostrar las marcas\n");
                }
                break;

            case 6:
                if (!listartipo(listaT, TAMT))
                {
                    printf("error al mostrar los Tipos\n");
                }
                break;
            case 7:
                if (!listarServicios(listaS, TAMS))
                {
                    printf("error al mostrar los servicios\n");
                }
                break;
            case 8:
                if (addN != 0)
                {
                    addTrabajo(listaN, TAMN, &idTr, listaM, TAMM, listaT, TAMT, listaS, TAMS, listaTr, TAMT);
                }
                else
                {
                    printf("Ingrese una notebook antes de agregar trabajos\n");
                }
                break;
            case 9:
                if (addTr != 0)
                {
                    listarTrabajos(listaTr, TAMTR, listaS, TAMS);
                }
                else
                {
                    printf("ingrese un trabajo antes de listarlos\n");
                }
                break;
            case 10:
                salir = 1;
                break;
            }
            system("pause");

        } while (salir == 0);
    }
    else
    {
        printf("No se puedo inicializar la lista\n");
        system("pause");
    }
    return 0;
}
