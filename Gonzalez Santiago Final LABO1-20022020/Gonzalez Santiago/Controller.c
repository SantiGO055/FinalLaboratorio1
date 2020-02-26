#include <stdio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cadenas.h"
#define RETURN_OK 1
#define RETURN_ERROR 0



int controller_loadFromTextCadenas(char* path , LinkedList* pArrayListCadenas)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_eCadenaFromText(pFile, pArrayListCadenas);
    }
    else
    {
        printf("El Archivo no existe\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Listar usrleados
 *
 * \param path char*
 * \param pArrayListComputer LinkedList*
 * \return int
 *
 */
int controller_ListComputers(LinkedList* pArrayListCadenas)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    int i;
    len = ll_len(pArrayListCadenas);

    if(pArrayListCadenas != NULL)
    {
        if(len != 0)
        {
            printf("ID - Descripcion - Precio - idTipo - Oferta \n\n");
            for(i = 0; i < len; i++)
            {
                eCadenas_showCadenas(pArrayListCadenas);
                ret = RETURN_OK;
                break;
            }
            system("pause");
        }
        else
        {
            printf("No hay datos\n\n");
            system("pause");
        }
    }
    return ret;
}


/** \brief Ordenar usrleados
 *
 * \param path char*
 * \param pArrayListCadenas LinkedList*
 * \return int
 *
 */

int controller_sortCadenas(LinkedList* pArrayListCadenas, int orden)
{
    int ret;
    ret = RETURN_ERROR;
    if(pArrayListCadenas != NULL)
    {
        ll_sort(pArrayListCadenas, eCadenas_sort,orden);
    }
    else
    {
        printf("No hay datos\n");
    }

    return ret;
}

int controller_filter(void* cadenas)
{
    int ret;
    int i;
    char* prueba;
    eCadenas* filter;
    ret = RETURN_ERROR;
    void* filterComputer;
    if(((eCadenas*)cadenas)->cadenas == 1 )
    {
        prueba=((eCadenas*)cadenas)->cadenas;
        filterComputer = ((eCadenas*)cadenas);
        ret = RETURN_OK;
    }

    return ret;
}

/** \brief Guarda los datos de los usrleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListComputer LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListCadenas)
{
    int ret;
    ret = RETURN_ERROR;
    int  i;
    FILE* pFile;
    pFile = fopen(path, "w");
    eCadenas* cdn;


    if(pArrayListCadenas != NULL)
    {
        for(i = 0; i<ll_len(pArrayListCadenas);i++)
        {
            cdn = (eCadenas*)ll_get(pArrayListCadenas, i);
            fprintf(pFile, "%s\n",cdn->cadenas);
        }
        fclose(pFile);
        ret = RETURN_OK;
    }

    else
    {
        printf("No hay Datos\n");
        system("pause");
    }

    return ret;
}

