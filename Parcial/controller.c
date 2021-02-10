#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "corredor.h"
#include "input.h"
#include "controller.h"

int controller_listExist(LinkedList* lista)
{
    int existe = -1;
    if(ll_len(lista) > 0)
    {
        existe = 1;
    }
    return existe;
}
int controller_loadFromText(char* path,LinkedList* lista)
{
    int retorno = -1;
    FILE* pFile = fopen(path,"r");
    if(pFile != NULL && lista != NULL)
    {
        if(parser_fromText(pFile, lista))
        {
            printf("entra bien al load");
            retorno = 1;
        }
        else
        {
            retorno = -1;
        }
    }
    else
    {
        retorno = -1;
    }
    fclose(pFile);
    free(pFile);

    return retorno;
}
int controller_ListCorredor(LinkedList* lista)
{
    eCorredor* corredor = corredor_new();
    int idAux;
    char apellidoAux[50];
    char tipoAux[50];
    int promedioAux;
    float tiempoAux;
    int retorno=-1;
    int i;

     if(corredor!=NULL && lista!=NULL)
    {
        system("cls");
        puts(" [ID]\t[APELLIDO]\t[TIPO]\t[PROMEDIO]\t[TIEMPO]\n\n");

        for(i=0; i < ll_len(lista); i++)
        {
            corredor =(eCorredor*)ll_get(lista, i);

            corredor_getId(corredor, &idAux);
            corredor_getApellido(corredor,apellidoAux);
            corredor_getTipo(corredor, tipoAux);
            corredor_getPromedio(corredor,&promedioAux);
            corredor_getTiempo(corredor,&tiempoAux);

            printf("%5d  %10s %10s  %10d %5f\n",idAux, apellidoAux, tipoAux, promedioAux ,tiempoAux);

        }

        retorno=1;
    }

    else
    {
        retorno=-1;
    }

    printf("\n\n");

    return retorno;
}
int controller_saveAsText(char* path, LinkedList* lista)
{
    eCorredor* corredor = corredor_new();
    int idAux;
    char apellidoAux[50];
    char tipoAux[50];
    int promedioAux;
    float tiempoAux;
    int retorno=-1;
    int i;
    int len;
    FILE* pFile = fopen(path,"w+");

    if(pFile != NULL && lista != NULL && corredor!=NULL )
    {
        len=ll_len(lista);
        fprintf(pFile, "id, apellido, tipo, promedio, tiempo\n");

        for(i=0; i<len; i++)
        {
            corredor= ll_get(lista,i);

            corredor_getId(corredor, &idAux);
            corredor_getApellido(corredor,apellidoAux);
            corredor_getTipo(corredor, tipoAux);
            corredor_getPromedio(corredor,&promedioAux);
            corredor_getTiempo(corredor,&tiempoAux);

            fprintf(pFile,"%d,%s,%s,%d,%f\n",idAux, apellidoAux, tipoAux, promedioAux ,tiempoAux);

        }

        retorno = 1;

    }
    else
    {
        retorno=-1;
    }

    fclose(pFile);

    return retorno;
}
int controller_map(LinkedList* pArrayListeCorredors)
{
    int retorno = -1;

    if(pArrayListeCorredors != NULL)
    {
        if(ll_map(pArrayListeCorredors, corredor_mapearTiempos))
        {
            retorno = 1;
        }
    }

    return retorno;
}
