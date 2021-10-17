/*
 * ArrayEmployees.h
 *
 *  Created on: 3 oct. 2021
 *      Author: user
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//---DEFINES---//
#define TRUE 1
#define FALSE 0
#define LEN_NAME 51
#define ELEMENTS 1000

//---STRUCT---//
typedef struct{
	int id;
	char name[LEN_NAME];
	char lastName[LEN_NAME];
	float salary;
	int sector;
	int isEmpty;
}Employee;

//---FUNCTIONS---//
int InitEmployees(Employee* list, int len);
int AddEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int FindEmployeeById(Employee* list, int len, int id);
int RemoveEmployee(Employee* list, int len, int id);
int SortEmployees(Employee* list, int len, int order);
int PrintEmployees(Employee* list, int len);

int BajaEmpleado(Employee* list,int len);
int BuscarIndexLibre(Employee* list,int len);
int AltaEmpleado(Employee* list,int len,int* id);
int ModificarEmpleado(Employee* list,int len);
int PedirDatosParaModificar(Employee elementoParaModificar,Employee* elementoModificado);
int InformarTotalSalarios(Employee* list,int len);
void InformarPromedioSalarios(float promedioSalarios);
void InformarCuantosSuperanElSalarioPromedio(int cantidadSuperanPromedio);
int CalcularTotalSalarios(Employee* list,int len,float* totalSalarios);
int CalcularPromedioSalarios(float totalSalarios,int cantidadEmpleados,float* promedioSalarios);
int CalcularCuantosSuperanElSalarioPromedio(Employee* list,int len,float promedioSalarios,int* cantidadSuperanPromedio);

#endif /* ARRAYEMPLOYEES_H_ */
