#include <stdio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Computer.h"
#define RETURN_OK 1
#define RETURN_ERROR 0



int controller_loadFromTextComputers(char* path , LinkedList* pArrayListComputer)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        ret = parser_eComputerFromText(pFile, pArrayListComputer);
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
int controller_ListComputers(LinkedList* pArrayListComputer)
{
    int ret;
    ret = RETURN_ERROR;
    int len;
    int i;
    len = ll_len(pArrayListComputer);

    if(pArrayListComputer != NULL)
    {
        if(len != 0)
        {
            printf("ID - Descripcion - Precio - idTipo - Oferta \n\n");
            for(i = 0; i < len; i++)
            {
                eComputer_showComputer(pArrayListComputer);
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
 * \param pArrayListComputer LinkedList*
 * \return int
 *
 */

int controller_sortComputers(LinkedList* pArrayListComputer)
{
    int ret;
    ret = RETURN_ERROR;
    if(pArrayListComputer != NULL)
    {
        ll_sort(pArrayListComputer, eComputer_sortByIdTipo,1);
    }
    else
    {
        printf("No hay datos\n");
    }

    return ret;
}

int controller_filter(void* computers)
{
    int ret;
    int i;
    char* prueba;
    eComputer* filter;
    ret = RETURN_ERROR;
    void* filterComputer;
    if(((eComputer*)computers)->idTipo == 1 )
    {
        prueba=((eComputer*)computers)->precio;
        filterComputer = ((eComputer*)computers);
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

int controller_saveAsText(char* path , LinkedList* pArrayListComputer)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    eComputer* cmp;


    if(pArrayListComputer != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListComputer);i++)
        {
            cmp = (eComputer*)ll_get(pArrayListComputer, i);
            fprintf(pFile, "%d,%s,%d,%d,%s\n",cmp->id ,cmp->descripcion ,cmp->precio, cmp->idTipo, cmp->oferta);
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

