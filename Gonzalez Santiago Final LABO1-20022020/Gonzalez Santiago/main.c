#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cadenas.h"
#include "parser.h"
#include <windows.h>
#define RETURN_OK 1
#define RETURN_ERROR 0


int menuPpal();
int menuSort();



int main()
{
    system("mode con: cols=100 lines=50");
    system ("color 0A" );
    int option = 0;
    int returnSave;

    LinkedList* eCadenas = ll_newLinkedList();
    LinkedList* eCadenasFilter = ll_newLinkedList();
    FILE* path;
    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                //printf("Ingrese nombre del archivo a cargar: ");
                //scanf("%s",path);
                controller_loadFromTextCadenas("examen.txt",eCadenas);
                break;
            case 2:
                system("cls");
                controller_sortCadenas(eCadenas,1);
                eCadenas_showeCadenas(eCadenas);
                system("pause");
                break;
            case 3:
                system("cls");
                controller_sortCadenas(eCadenas,0);
                eCadenas_showeCadenas(eCadenas);
                system("pause");
                //ll_filter(eCadenas,controller_filter());
                break;
            case 4:
                system("cls");
                //ll_map(eCadenas,eCadenas_map);
                ll_map(eCadenas,eCadenas_len);
                eCadenas_showeCadenas(eCadenas);
                system("pause");
                //eDominioFilter=ll_filter(eCadenas,)
                break;
            case 5:

                system("cls");
                /*
                eCadenasFilter=ll_filter(eCadenas,controller_filter);
                eCadenas_showeCadenas(eCadenasFilter);
                */
                returnSave=controller_saveAsText("listaOrdenada.dat", eCadenas);
                if(returnSave==1){
                    printf("El archivo se guardo correctamente a la carpeta raiz con nombre listaOrdenada.dat\n");
                    system("pause");
                }
                else{
                    printf("El archivo no se guardo correctamente\n");
                }

                break;

            case 6:
                system("exit");
                break;
        }
    }while(option != 6);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                                          \n");
        printf("  1. Cargar archivo de texto.                                                    \n");
        printf("  2. Ordenar palabras ascendente                                                 \n");
        printf("  2. Ordenar palabras descendente                                                \n");
        printf("  4. Ordenar por cantidad de palabras                                            \n");
       // printf("  9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   \n");
        printf(" 5. Guardar lista ordenada                                                       \n");
        printf(" 6. Salir                                                                        \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 6);

    return r;
}
