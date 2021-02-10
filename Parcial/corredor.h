#ifndef CORREDOR_H_INCLUDED
#define CORREDOR_H_INCLUDED

typedef struct
{
    int id_corredor;
    char apellido[50];
    char tipo[50];
    int promedio;
    float tiempo;
}eCorredor;

eCorredor* corredor_new();
int corredor_setId(eCorredor* this, int id);
int corredor_getId(eCorredor* this,int* id);
int corredor_setapellido(eCorredor* this,char* apellido);
int corredor_getApellido(eCorredor* this,char* apellido);
int corredor_setTipo(eCorredor* this,char tipo);
int corredor_getTipo(eCorredor* this,char* tipo);
int corredor_setPromedio(eCorredor* this,int promedio);
int corredor_getPromedio(eCorredor* this,int* promedio);
int corredor_setTiempo(eCorredor* this, float tiempo);
int corredor_getTiempo(eCorredor* this, float* tiempo);
eCorredor* corredor_newParametros(char* idStr, char* apellido, char* tipo, char* promedioStr, char* tiempoStr);
int corredor_mapearTiempos(void* pElement);

#endif // CORREDOR_H_INCLUDED
