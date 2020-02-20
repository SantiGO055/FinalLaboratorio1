#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Computer.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los cmpleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListcmployee LinkedList*
 * \return int
 *
 */
int parser_eComputerFromText(FILE* pFile , LinkedList* pArrayListComputers)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[3];
    char descripcionStr[128];
    char precioStr[10];
    char idTipoStr[3];
    char ofertaStr[60];
    //char sueldoStr[6];

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",idStr, descripcionStr, precioStr, idTipoStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", idStr, descripcionStr, precioStr, idTipoStr);

            if(cant != 4)
            {
                printf("Error al cargar Archivo\n\n");
                system("pause");
            }
            else
            {
                eComputer* cmp = eComputer_new();
                cmp->id = atoi(idStr);
                strcpy(cmp->descripcion, descripcionStr);
                cmp->precio = atoi(precioStr);
                cmp->idTipo = atoi(idTipoStr);

                ll_add(pArrayListComputers, cmp);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Archivo sin datos\n\n");
        system("pause");
    }

    return ret;
}
