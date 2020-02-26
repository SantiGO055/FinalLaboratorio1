#include <stdio.h>
#include "Cadenas.h"
#define RETURN_OK 1
#define RETURN_ERROR 0
eCadenas* eCadenas_new()
{

    eCadenas* cdn;
    cdn = (eCadenas*)malloc(sizeof(eCadenas));
    strcpy(cdn->cadenas, "");

    return cdn;
}


eCadenas* eCadenas_newParametros(char* cadenasStr)
{
    eCadenas* cdn;
    cdn = (eCadenas*)malloc(sizeof(eCadenas));
    strcpy(cdn->cadenas, cadenasStr);
    return cdn;
}




/*void eCadenas_delete()
{

}*/
/*
int eCadenas_setId(eCadenas* this,int id)
{
    int ret;
    ret = RETURN_ERROR;

    if(id > 0 && this != NULL)
    {
        this->id = id;
        ret = RETURN_OK;
    }
    return ret;
}
int eCadenas_getId(eCadenas* this,int* id)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *id = this->id;
        ret = RETURN_OK;
    }

    return ret;
}

int eCadenas_setDescripcion(eCadenas* this,char* descripcion)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->descripcion,descripcion);
        ret = RETURN_OK;
    }

    return ret;
}

int eCadenas_getDescripcion(eCadenas* this,char* descripcion)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(descripcion,this->descripcion);
        ret = RETURN_OK;
    }

    return ret;
}

int eCadenas_setPrecio(eCadenas* this,char* precio)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->precio,precio);
        ret = RETURN_OK;
    }

    return ret;
}

int eCadenas_getPrecio(eCadenas* this,char* precio)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *precio = this->precio;
        ret = RETURN_OK;
    }

    return ret;
}

int eCadenas_setIdTipo(eCadenas* this,int idTipo)
{
    int ret;
    ret = RETURN_ERROR;

    if(idTipo > 0 && this != NULL)
    {
        this->idTipo = idTipo;
        ret = RETURN_OK;
    }
    return ret;
}
int eCadenas_getIdTipo(eCadenas* this,int* idTipo)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *idTipo = this->idTipo;
        ret = RETURN_OK;
    }

    return ret;
}

int eCadenas_setOferta(eCadenas* this,char* oferta)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->oferta,oferta);
        ret = RETURN_OK;
    }

    return ret;
}
int eCadenas_getOferta(eCadenas* this,char* oferta)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *oferta = this->oferta;
        ret = RETURN_OK;
    }

    return ret;
}

*/
void  eCadenas_showCadenas(eCadenas* this)
{
    if(this != NULL )
    {
            printf ( "%s\n" ,this->cadenas);
        }

    }


void  eCadenas_showeCadenas(eCadenas* this)
{
    eCadenas* str;
    int i=0;
    printf("[Palabras]\n");
    if(this != NULL )
    {
        for(i=0; i<ll_len(this);i++)
        {
            str = (eCadenas*)ll_get(this, i);
            eCadenas_showCadenas(str);

        }
    }
    else
    {
        printf("No hay palabras cargadas\n\n");
        system("pause");
    }

}

int eCadenas_sort(void* CadenaA, void* CadenaB)
{
    int ret;
    ret = strcmp(((eCadenas*)CadenaA)->cadenas, ((eCadenas*)CadenaB)->cadenas);
    return ret;
}
//0 si son iguales, 1 si la primera es mayor a la segunda, 2 si la primera es menor a la segunda
int eCadenas_len(void* CadenaA, void* CadenaB)
{
    int cantA;
    int cantB;
    int ret=-1;
    int strcmpaux;
    eCadenas* cadAux;
    cantA = strlen(CadenaA);
    cantB = strlen(CadenaB);
    if (cantA==cantB){
        ret=0;
    }
    else if(cantA>cantB){
        ret=1;
    }
    else if(cantA<cantB){
        ret=2;
    }

    return ret;
}
/*
int eCadenas_map(void* CadenasA)
{
    int ret=RETURN_ERROR;

    if(((eCadenas*)CadenasA)->idTipo == 1 ){
        strcpy(((eCadenas*)CadenasA)->oferta,("SIN DATOS"));
        ret=RETURN_OK;
    }
    else if( ((eCadenas*)CadenasA)->precio>20000){
        strcpy(((eCadenas*)CadenasA)->oferta,"50% DESCUENTO");
        ret=RETURN_OK;
    }
    else{
        strcpy(((eCadenas*)CadenasA)->oferta,("SIN DATOS"));
        ret=RETURN_OK;
    }


    return ret;
}*/
