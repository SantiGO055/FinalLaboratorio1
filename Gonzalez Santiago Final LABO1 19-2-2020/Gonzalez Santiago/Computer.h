#ifndef eComputer_H_INCLUDED
#define eComputer_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[128];
    int precio;
    int idTipo;
    char oferta[128];
}eComputer;


eComputer* eComputer_new();
eComputer* eComputer_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr);
void eComputer_delete();

int eComputer_setId(eComputer* this,int id);
int eComputer_getId(eComputer* this,int* id);

int eComputer_setNombre(eComputer* this,char* nombre);
int eComputer_getNombre(eComputer* this,char* nombre);

int eComputer_setEmail(eComputer* this,char* email);
int eComputer_getEmail(eComputer* this,char* email);

int eComputer_setSexo(eComputer* this,char* sexo);
int eComputer_getSexo(eComputer* this,char* sexo);

int eComputer_setPais(eComputer* this,char* pais);
int eComputer_getPais(eComputer* this,char* pais);

int eComputer_setPassword(eComputer* this,char* password);
int eComputer_getPassword(eComputer* this,char* password);

int eComputer_setIpAddress(eComputer* this,char* ip_address);
int eComputer_getIpAddress(eComputer* this,char* ip_address);

void  eComputer_showUsuario(eComputer* this);
void  eComputer_showeComputer(eComputer* this);

int eComputer_sortByIdTipo(void* ComputerA, void* ComputerB);
int eComputer_map(void* ComputerA);
#endif // eComputer_H_INCLUDED
