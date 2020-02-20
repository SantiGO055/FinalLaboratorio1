#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Computer.h"
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

    LinkedList* eComputer = ll_newLinkedList();
    LinkedList* eComputerFilter = ll_newLinkedList();
    FILE* path;
    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                //printf("Ingrese nombre del archivo a cargar: ");
                //scanf("%s",path);
                controller_loadFromTextComputers("datosLaptops.csv",eComputer);
                break;
            case 2:
                system("cls");
                controller_sortComputers(eComputer);
                break;
            case 3:
                system("cls");
                eComputer_showeComputer(eComputer);
                system("pause");
                //ll_filter(eComputer,controller_filter());
                break;
            case 4:
                system("cls");
                ll_map(eComputer,eComputer_map);
                eComputer_showeComputer(eComputer);
                system("pause");
                //eDominioFilter=ll_filter(eComputer,)
                break;
            case 5:
                system("cls");
                eComputerFilter=ll_filter(eComputer,controller_filter);
                eComputer_showeComputer(eComputerFilter);
                returnSave=controller_saveAsText("filtrado.dat", eComputerFilter);
                if(returnSave==1){
                    printf("El archivo se guardo correctamente a la carpeta raiz con nombre filtrado.dat\n");
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
        printf("  2. Ordenar lista por idTipo.                                                   \n");
        printf("  3. Imprimir lista ordenada                                                     \n");
        printf("  4. Imprimir oferta de descuentos                                               \n");
       // printf("  9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   \n");
        printf(" 5. Filtrar la lista por PC Desktop                                              \n");
        printf(" 6. Salir                                                                        \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 6);

    return r;
}
