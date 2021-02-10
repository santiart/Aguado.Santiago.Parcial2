#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "corredor.h"
#include "LinkedList.h"
#include "parser.h"
#include "input.h"

eCorredor* corredor_new()
{
    eCorredor* corredor = (eCorredor*) malloc(sizeof(eCorredor));
    if(corredor != NULL)
        {
        corredor->id_corredor = 0;
        strcpy(corredor->apellido,"");
        strcpy(corredor->tipo, "");
        corredor->promedio = 0;
        corredor->tiempo = 0;
        }
    return corredor;
}
int corredor_setId(eCorredor* this, int id)
{
    int setted = 0;

    if(this != NULL){
        this->id_corredor = id;
        setted = 1;
    }

    return setted;
}

int corredor_getId(eCorredor* this,int* id)
{
    int getted = 0;

    if(this != NULL && id != NULL){
        *id = this->id_corredor;
        getted = 1;
    }

    return getted;
}

int corredor_setapellido(eCorredor* this,char* apellido)
{
    int setted = 0;

    if(this != NULL&&apellido!=NULL){
        strcpy(this->apellido, apellido);
        setted = 1;
    }

    return setted;
}
int corredor_getApellido(eCorredor* this,char* apellido)
{
    int getted = 0;

    if(this != NULL && apellido != NULL){
        strcpy(apellido,this->apellido);
        getted = 1;
    }

    return getted;
}
int corredor_setTipo(eCorredor* this,char tipo)
{
    int setted = 0;

    if(this != NULL&&tipo!=NULL){
        strcpy(this->tipo, tipo);
        setted = 1;
    }

    return setted;
}
int corredor_getTipo(eCorredor* this,char* tipo)
{
     int getted = 0;

    if(this != NULL && tipo != NULL){
        strcpy(tipo,this->tipo);
        getted = 1;
    }

    return getted;
}
int corredor_setPromedio(eCorredor* this,int promedio)
{
     int setted = 0;

    if(this != NULL){
        this->promedio = promedio;
        setted = 1;
    }

    return setted;
}
int corredor_getPromedio(eCorredor* this,int* promedio)
{
    int getted = 0;

    if(this != NULL && promedio != NULL){
        *promedio = this->promedio;
        getted = 1;
    }

    return getted;
}
int corredor_setTiempo(eCorredor* this, float tiempo)
{
     int setted = 0;

    if(this != NULL){
        this->tiempo = tiempo;
        setted = 1;
    }

    return setted;
}
int corredor_getTiempo(eCorredor* this, float* tiempo)
{
    int getted = 0;

    if(this != NULL && tiempo != NULL){
        *tiempo = this->tiempo;
        getted = 1;
    }

    return getted;
}
eCorredor* corredor_newParametros(char* idStr, char* apellido, char* tipo, char* promedioStr, char* tiempoStr)
{
    eCorredor* corredor = corredor_new();
    int flag = 0;
    if(corredor != NULL)
    {
        if(corredor_setId(corredor,atoi(idStr)) == 1){
            if(corredor_setapellido(corredor, apellido) == 1){
                if(corredor_setTipo(corredor, tipo) == 1){
                    if(corredor_setPromedio(corredor, atoi(promedioStr)) ==  1){
                        if(corredor_setTiempo(corredor, atof(tiempoStr)) == 1){
                            flag = 1;
                        }
                    }
                }
            }
        }
    }

    if(flag == 0)
    {
        free(corredor);
        corredor = NULL;
    }

    return corredor;
}
int corredor_mapearTiempos(void* pElement)
{
     int retorno = -1;
     eCorredor* corredor;
     int auxTiempo = 1.2;
     if(pElement != NULL)
     {
         corredor =(eCorredor*)pElement;

         corredor_getTiempo(corredor, &auxTiempo);
         retorno = 1;
    }
    return retorno;
}

