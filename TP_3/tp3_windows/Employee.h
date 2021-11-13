#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_MostrarUno(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareById(void* pFirstEmployee,void* pSecondEmployee);
int employee_CompareByName(void* pFirstEmployee,void* pSecondEmployee);
int employee_CompareByHorasTrabajadas(void* pFirstEmployee,void* pSecondEmployee);
int employee_CompareBySueldo(void* pFirstEmployee,void* pSecondEmployee);

int employee_Alta(Employee* pNewEmployee);
int employee_CargarDatos(Employee* pNewEmployee);

int employee_PedirNombre(char* nombre,int tam);
int employee_PedirHorasTrabajadas(int* horasTrabajadas);
int employee_PedirSueldo(int* sueldo);

Employee* employee_ClonarEmployee(Employee* pEmployee);

#endif // employee_H_INCLUDED
