#ifndef eCadenas_H_INCLUDED
#define eCadenas_H_INCLUDED
typedef struct
{
    char cadenas[128];
}eCadenas;


eCadenas* eCadenas_new();
eCadenas* eCadenas_newParametros(char* cadenasStr);
/*
int eCadenas_setId(eCadenas* this,int id);
int eCadenas_getId(eCadenas* this,int* id);

int eCadenas_setNombre(eCadenas* this,char* nombre);
int eCadenas_getNombre(eCadenas* this,char* nombre);

int eCadenas_setEmail(eCadenas* this,char* email);
int eCadenas_getEmail(eCadenas* this,char* email);

int eCadenas_setSexo(eCadenas* this,char* sexo);
int eCadenas_getSexo(eCadenas* this,char* sexo);

int eCadenas_setPais(eCadenas* this,char* pais);
int eCadenas_getPais(eCadenas* this,char* pais);

int eCadenas_setPassword(eCadenas* this,char* password);
int eCadenas_getPassword(eCadenas* this,char* password);

int eCadenas_setIpAddress(eCadenas* this,char* ip_address);
int eCadenas_getIpAddress(eCadenas* this,char* ip_address);
*/
void  eCadenas_showCadenas(eCadenas* this);
void  eCadenas_showeCadenas(eCadenas* this);

int eCadenas_sort(void* CadenaA, void* CadenaB);
int eCadenas_len(void* CadenaA, void* CadenaB);
#endif // eCadenas_H_INCLUDED
