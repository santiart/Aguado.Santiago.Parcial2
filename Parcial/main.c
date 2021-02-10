#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corredor.h"
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "controller.h"

int main()
{
     int opcion;
    char path[22];
    LinkedList* listaCorredor = ll_newLinkedList();
    LinkedList* listaMapeada=ll_newLinkedList();
     do
    {
        menu();
        opcion=getInt("\nPor favor ingrese una opcion <1-4> :");

        switch(opcion)
        {
        case 1:

            getString("\nIngrese el nombre del archivo a cargar, sin olvidarse de poner al final '.csv'\n:",path);

            if(controller_loadFromText(path,listaCorredor))
            {
                printf("deberia listar");
                controller_ListCorredor(listaCorredor);
                printf("\n archivo cargado correctamente (modo texto)\n\n");
            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }

            break;

        case 2:
            if(controller_listExist(listaCorredor)==1)
            {

                if(controller_map(listaCorredor)==1)
                {
                    controller_ListCorredor(listaCorredor);
                    printf("\n elementos mapeados correctamente\n\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudieron mapear a los elementos\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de listar\n");
            }
            break;

        case 3:
            if(controller_listExist(listaCorredor)==1)
            {

                if(controller_saveAsText("AutosCarreraMapeado.txt",listaMapeada))
                {
                    printf("\nArchivo AutosCarreraMapeado.txt guardado\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudo guardar el archivo\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de guardar\n");
            }

            break;
        case 4:
            printf("\n\nSALIENDO DEL PROGRAMA\n\n");
            break;

        default:
            printf("\n\nERROR...Ingrese una opcion correcta <1-5>\n\n");
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion != 4);

    ll_deleteLinkedList(listaCorredor);

    return 0;
}
