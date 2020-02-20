#include <stdio.h>
#include "Computer.h"
#define RETURN_OK 1
#define RETURN_ERROR 0
eComputer* eComputer_new()
{

    eComputer* cmp;
    cmp = (eComputer*)malloc(sizeof(eComputer));
    cmp->id = 0;
    strcpy(cmp->descripcion, "");
    cmp->precio = 0;
    cmp->idTipo=0;
    strcpy(cmp->oferta, "");

    return cmp;
}


eComputer* eComputer_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr)
{
    eComputer* cmp;
    cmp = (eComputer*)malloc(sizeof(eComputer));
    cmp->id = idStr;
    strcpy(cmp->descripcion, descripcionStr);
    strcpy(cmp->precio, precioStr);
    cmp->idTipo = idTipoStr;
    return cmp;
}




/*void eComputer_delete()
{

}*/

int eComputer_setId(eComputer* this,int id)
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
int eComputer_getId(eComputer* this,int* id)
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

int eComputer_setDescripcion(eComputer* this,char* descripcion)
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

int eComputer_getDescripcion(eComputer* this,char* descripcion)
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

int eComputer_setPrecio(eComputer* this,char* precio)
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

int eComputer_getPrecio(eComputer* this,char* precio)
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

int eComputer_setIdTipo(eComputer* this,int idTipo)
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
int eComputer_getIdTipo(eComputer* this,int* idTipo)
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

int eComputer_setOferta(eComputer* this,char* oferta)
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
int eComputer_getOferta(eComputer* this,char* oferta)
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


void  eComputer_showComputer(eComputer* this)
{
    char tipo[7];
    if(this != NULL )
    {
        if(this->idTipo==1){
            strcpy(tipo,"DESKTOP");
            printf ( "%4d - %s - %d - %s - %s\n\n " , this->id, this->descripcion, this->precio, tipo, this->oferta);
        }
        else{
            strcpy(tipo,"LAPTOP");
            printf ( "%4d - %s - %d - %s - %s\n\n " , this->id, this->descripcion, this->precio, tipo, this->oferta);
        }

    }
}

void  eComputer_showeComputer(eComputer* this)
{
    eComputer* str;
    int i=0;
    printf("[ID] - [DESCRIPCION] - [PRECIO] - [TIPO] - [OFERTA]\n");
    if(this != NULL )
    {
        for(i=0; i<ll_len(this);i++)
        {
            str = (eComputer*)ll_get(this, i);
            eComputer_showComputer(str);

        }
    }
    else
    {
        printf("No hay computadoras cargados\n\n");
        system("pause");
    }

}

int eComputer_sortByIdTipo(void* ComputerA, void* ComputerB)
{
    int ret;
    if(((eComputer*)ComputerA)->idTipo > ((eComputer*)ComputerB)->idTipo){
        ret=RETURN_OK;
    }


    return ret;
}

int eComputer_map(void* ComputerA)
{
    int ret=RETURN_ERROR;

    if(((eComputer*)ComputerA)->idTipo == 1 ){
        strcpy(((eComputer*)ComputerA)->oferta,("SIN DATOS"));
        ret=RETURN_OK;
    }
    else if( ((eComputer*)ComputerA)->precio>20000){
        strcpy(((eComputer*)ComputerA)->oferta,"50% DESCUENTO");
        ret=RETURN_OK;
    }
    else{
        strcpy(((eComputer*)ComputerA)->oferta,("SIN DATOS"));
        ret=RETURN_OK;
    }


    return ret;
}
