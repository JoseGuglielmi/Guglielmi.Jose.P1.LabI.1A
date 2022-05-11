#include "tipo.h"

int mostrarTipo(eTipo* listaT){
int todoOk = 0;

printf("%04d   %10s\n", listaT->id, listaT->descripcion);
return todoOk;
}

int listartipo(eTipo* listaT,int tamT){
	int todoOk = 0;
		if (listaT != NULL && tamT > 0)
		{

			printf(" \n\n         ***   Listado de servicios   ***\n\n");
			printf(" ID      Tipo\n");
			printf("--------------------------------\n");
			for (int i = 0; i < tamT; i++)
			{
				mostrarTipo(listaT + i);
			}
			todoOk = 1;
		}
	return todoOk;
	}

int cargarDescripcionTipo(eTipo* listaT, int tamT, int id, char* descripcion){
int todoOk = 0;
int indice;

    buscarTipo(listaT,tamT, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, listaT[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarTipo(eTipo* listaT, int tamT, int id, int* pIndice){
    int todoOk = 0;
    if(listaT != NULL && tamT > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamT; i++){
                if(listaT[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
