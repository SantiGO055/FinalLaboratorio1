#include <stdio.h>
#include "Usuarios.h"
#define RETURN_OK 1
#define RETURN_ERROR 0
Usuarios* eUsuarios_new()
{

    Usuarios* usr;
    usr = (Usuarios*)malloc(sizeof(Usuarios));
    usr->id = 0;
    strcpy(usr->nombre, "");
    strcpy(usr->email, "");
    strcpy(usr->sexo, "");
    strcpy(usr->pais, "");
    strcpy(usr->password, "");
    strcpy(usr->ip_address, "");

    return usr;
}

Temas* eTemas_new()
{
    Temas* tema;
    tema = (Temas*)malloc(sizeof(Temas));
    tema->id = 0;
    strcpy(tema->nombre_tema, "");
    strcpy(tema->artista, "");
    tema->contadorEscuchados=0;

    return tema;
}


Usuarios* eUsuarios_newParametros(char* idStr,char* nombreStr,char* emailStr,
                                  char* sexoStr,char* paisStr,char* passwordStr,char* ipAddressStr)
{
    Usuarios* usr;
    usr = (Usuarios*)malloc(sizeof(Usuarios));
    usr->id = idStr;
    strcpy(usr->nombre, nombreStr);
    strcpy(usr->email, emailStr);
    strcpy(usr->sexo, sexoStr);
    strcpy(usr->pais, paisStr);
    strcpy(usr->password, passwordStr);
    strcpy(usr->ip_address, ipAddressStr);
    return usr;
}
Temas* eTemas_newParametros(char* idStr, char* nombre_temaStr, char* artistaStr)
{
    Temas* tema;
    tema = (Temas*)malloc(sizeof(Temas));
    tema->id = idStr;
    strcpy(tema->nombre_tema, nombre_temaStr);
    strcpy(tema->artista, artistaStr);
    return tema;
}




/*void Usuarios_delete()
{

}*/

int Usuarios_setId(Usuarios* this,int id)
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
int Usuarios_getId(Usuarios* this,int* id)
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

int Usuarios_setNombre(Usuarios* this,char* nombre)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        ret = RETURN_OK;
    }

    return ret;
}

int Usuarios_getNombre(Usuarios* this,char* nombre)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        ret = RETURN_OK;
    }

    return ret;
}

int Usuarios_setEmail(Usuarios* this,char* email)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->email,email);
        ret = RETURN_OK;
    }

    return ret;
}

int Usuarios_getEmail(Usuarios* this,char* email)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *email = this->email;
        ret = RETURN_OK;
    }

    return ret;
}

int Usuarios_setSexo(Usuarios* this,char* sexo)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->sexo,sexo);
        ret = RETURN_OK;
    }

    return ret;
}
int Usuarios_getSexo(Usuarios* this,char* sexo)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *sexo = this->sexo;
        ret = RETURN_OK;
    }

    return ret;
}

int Usuarios_setPais(Usuarios* this,char* pais)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->pais,pais);
        ret = RETURN_OK;
    }

    return ret;
}
int Usuarios_getPais(Usuarios* this,char* pais)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *pais = this->pais;
        ret = RETURN_OK;
    }

    return ret;
}

int Usuarios_setPassword(Usuarios* this,char* password)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->password,password);
        ret = RETURN_OK;
    }

    return ret;
}
int Usuarios_getPassword(Usuarios* this,char* password)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(password,this->password);
        ret = RETURN_OK;
    }

    return ret;
}

int Usuarios_setIpAddress(Usuarios* this,char* ip_Address)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       strcpy(this->ip_address,ip_Address);
        ret = RETURN_OK;
    }

    return ret;
}
int Usuarios_getIpAddress(Usuarios* this,char* ip_address)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *ip_address = this->ip_address;
        ret = RETURN_OK;
    }

    return ret;
}

int temas_getId(Temas* this,int* id)
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




void  Usuarios_showUsuario(Usuarios* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %s  %s  %s  %s  %s  \n\n " , this->id, this->nombre, this->email, this->sexo, this->pais,this->ip_address);
    }
}

void  Usuarios_showUsuarios(Usuarios* this)
{
    Usuarios* str;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            str = (Usuarios*)ll_get(this, i);
            Usuarios_showUsuario(str);
        }
    }
    else
    {
        printf("No hay usuarios cargados\n\n");
        system("pause");
    }

}


void  Temas_showTema(Temas* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %s  %s\n\n " , this->id, this->nombre_tema, this->artista);
    }
}

void  Temas_showTemas(Temas* this)
{
    Temas* tema;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            tema = (Temas*)ll_get(this, i);
            Temas_showTema(tema);
        }
    }
    else
    {
        printf("No hay temas cargados\n\n");
        system("pause");
    }

}



int Usuarios_sortByName(void* UsuarioA, void* UsuarioB)
{
    int ret;
    ret = strcmp(((Usuarios*)UsuarioA)->nombre, ((Usuarios*)UsuarioB)->nombre);

    return ret;
}


int Usuarios_sortByNac(void* UsuarioA, void* UsuarioB)
{
    int ret;
    ret = strcmp(((Usuarios*)UsuarioA)->pais, ((Usuarios*)UsuarioB)->pais);
    return ret;
}

/*
int Usuarios_sortByHsTrabajadas(void* UsuarioA, void* UsuarioB)
{
    int ret;
    if(((Usuarios*)UsuarioA)->horasTrabajadas > ((Usuarios*)UsuarioB)->horasTrabajadas)
    {
        ret = 1;
    }
    else if(((Usuarios*)UsuarioA)->horasTrabajadas < ((Usuarios*)UsuarioB)->horasTrabajadas)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int Usuarios_sortBySueldo(void* UsuarioA, void* UsuarioB)
{
    int ret;
    if(((Usuarios*)UsuarioA)->sueldo > ((Usuarios*)UsuarioB)->sueldo)
    {
        ret = 1;
    }
    else if(((Usuarios*)UsuarioA)->sueldo < ((Usuarios*)UsuarioB)->sueldo)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int Usuarios_loadSueldo(void* strleado)
{
    void* ret;
    int horasBajas;
    int horasMedias;
    int horasAltas;
    if(((Usuarios*)strleado)->horasTrabajadas <= 176)
    {
        horasBajas = ((Usuarios*)strleado)->horasTrabajadas * 180;
        ((Usuarios*)strleado)->sueldo = horasBajas;
    }
    else if(((Usuarios*)strleado)->horasTrabajadas >= 177)
    {
        horasBajas = 176 * 180;
        horasMedias = ((Usuarios*)strleado)->horasTrabajadas - 176;
        ((Usuarios*)strleado)->sueldo = (horasMedias * 270) + horasBajas;
    }
    else if(((Usuarios*)strleado)->horasTrabajadas >= 208)
    {
        horasBajas = 176 * 180;
        horasMedias = 32 * 270;
        horasMedias = ((Usuarios*)strleado)->horasTrabajadas - 208;
        ((Usuarios*)strleado)->sueldo = (horasMedias * 360) + horasBajas;
    }
    ret = ((Usuarios*)strleado)->sueldo;
    return ret;
}

*/

