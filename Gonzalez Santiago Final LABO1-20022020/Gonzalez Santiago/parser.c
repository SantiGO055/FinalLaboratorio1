#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Cadenas.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los cadleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListcadloyee LinkedList*
 * \return int
 *
 */
int parser_eCadenaFromText(FILE* pFile , LinkedList* pArrayListCadenas)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char cadenasStr[128];
    //char sueldoStr[6];

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,\n]\n",cadenasStr);

            if(cant != 1)
            {
                printf("Error al cargar Archivo\n\n");
                system("pause");
            }
            else
            {
                eCadenas* cad = eCadenas_new();
                strcpy(cad->cadenas, cadenasStr);

                ll_add(pArrayListCadenas, cad);
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
