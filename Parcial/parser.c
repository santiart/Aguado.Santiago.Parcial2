#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "corredor.h"
#include "LinkedList.h"
#include "input.h"
#include "parser.h"



int parser_fromText(FILE* pFile,LinkedList* lista)
{
    char buffer[5][50];
    int retorno=0;
    eCorredor* corredor = corredor_new();
    int cant;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3], buffer[4]);
    while(!feof(pFile))
        {
        cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3], buffer[4]);
        if(cant == 5)
            {
            corredor = corredor_newParametros(buffer[0],buffer[1],buffer[2],buffer[3], buffer[4]);// esta linea es el error
            ll_add(lista,corredor);
            retorno=1;
            }else
                {
                retorno=-1;
                }
        }
    return retorno;
}
