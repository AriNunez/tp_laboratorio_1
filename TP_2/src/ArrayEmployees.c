/*
 * ArrayEmployees.c
 *
 *  Created on: 3 oct. 2021
 *      Author: user
 */

#include "ArrayEmployees.h"

/// \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
/// \param list Employee* Pointer to array of employees
/// \param len int Array lenght
/// \return int Return (-1) if Error [Invalid lenght or NULL pointer] - (0) if Ok.
int InitEmployees(Employee* list, int len)
{
	int rtn;
	int i;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
			rtn = 0;
		}
	}

	return rtn;
}

/// \brief add in an existing list of employees the values received as parameters in the first empty position.
/// \param list Employee* Pointer to array of employees
/// \param len int Array lenght
/// \param id int
/// \param name[] char
/// \param lastName[] char
/// \param salary float
/// \param sector int
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok.
int AddEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int rtn;
	int index;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		index = BuscarIndexLibre(list, len);

		if(index != -1)
		{
			list[index].id = id;
			strcpy(list[index].name,name);
			strcpy(list[index].lastName,lastName);
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty = FALSE;
			rtn = 0;
		}
	}

	return rtn;
}

/// \brief find an Employee by Id and returns the index position in array.
/// \param list Employee* Pointer to array of employees
/// \param len int Array lenght
/// \param id int
/// \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found].
int FindEmployeeById(Employee* list, int len, int id)
{
	int rtn;
	int i;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == FALSE)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/// \brief Remove a Employee by Id (put isEmpty Flag in 1).
/// \param list Employee* Pointer to array of employees
/// \param len int Array lenght
/// \param id int
/// \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok.
int RemoveEmployee(Employee* list, int len, int id)
{
	int rtn;
	int index;
	char confirm;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		index = FindEmployeeById(list, len, id);

		if(utn_getCharParaContinuar(&confirm, "\n¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 5)==0 && confirm == 'S')
		{
			rtn = 0;
			list[index].isEmpty = TRUE;
		}
	}

	return rtn;
}

/// \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order.
/// \param list Employee* Pointer to array of employees
/// \param len int Array lenght
/// \param order int [1] indicate UP - [0] indicate DOWN
/// \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
int SortEmployees(Employee* list, int len, int order)
{
	int rtn;
	int i;
	int j;
	Employee aux;

	rtn = -1;

	if(list != NULL && len > 0 && (order == 1 || order == 0))
	{
		switch(order)
		{
			case 0:
				for(i=0;i<len-1;i++)
				{
					for(j=i+1;j<len;j++)
					{
						if(list[i].isEmpty == FALSE)
						{
							if(strcmp(list[i].lastName,list[j].lastName)<0)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
							else
							{
								if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
							}
						}
					}
				}
				rtn = 0;
				break;

			case 1:

				for(i=0;i<len-1;i++)
				{
					for(j=i+1;j<len;j++)
					{
						if(list[i].isEmpty == FALSE)
						{
							if(strcmp(list[i].lastName,list[j].lastName)>0)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
							else
							{
								if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
							}
						}
					}
				}
				rtn = 0;
				break;
		}
	}

	return rtn;
}

/// \brief print the content of employees array
/// \param list Employee* Pointer to array of employees
/// \param len int Array lenght
/// \return int Return (-1) if Error [Invalid length, NULL pointer or nothing for show] - (0) if Ok.
int PrintEmployees(Employee* list, int len)
{
	int rtn;
	int i;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		puts("\n\t>>Listado Empleados");
		printf("|%-6s|%-15s|%-15s|%-20s|%-10s|\n\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("|%-6d|%-15s|%-15s|%-20.2f|%-10d|\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
				rtn = 0;
			}
		}
	}

	return rtn;
}

/// \brief Muestra los empleados en ALTA y solicita la eleccion de uno para darlo de BAJA.
/// \param list Employee* Puntero al array de empleados
/// \param len int Largo del array
/// \return Retorna (-1) en caso de error - (0) en caso de exito.
int BajaEmpleado(Employee* list,int len)
{
	int rtn;
	int idBaja;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		if(PrintEmployees(list, len)==0)
		{
			if(utn_getInt(&idBaja, "\nIngrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 5)==0)
			{
				while(FindEmployeeById(list, len, idBaja)==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idBaja, "\nIngrese un ID para dar de baja: \n", "¡ERROR!\n", 1, 3000000, 5);
				}
			}

			if(RemoveEmployee(list, len, idBaja)==0)
			{
				rtn = 0;
			}
		}
	}

	return rtn;
}

/// \brief Busca el primer lugar libre del array (isEmpty == TRUE) y retorna el indice de la posicion.
/// \param list Employee* Puntero al array de empleados
/// \param len int Largo del array
/// \return Retorna (-1) en caso de error - (>=0) en caso de exito.
int BuscarIndexLibre(Employee* list,int len)
{
	int rtn;
	int i;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/// \brief Solicita los datos relacionados con el empleado que se quiere dar de ALTA.
/// \param list Employee* Puntero al array de empleados
/// \param len int Largo del array
/// \param id int Puntero a un int que hace referencia al id Autoincremental.
/// \return Retorna (-1) en caso de error - (0) en caso de exito.
int AltaEmpleado(Employee* list,int len,int* id)
{
	int rtn;
	int idAux;
	Employee aux;

	rtn = -1;

	if(list != NULL && len > 0 && id != NULL)
	{
		idAux = *id;
		idAux++;

		if(utn_getName(aux.name, "\nIngrese el nombre del empleado: \n", "\n¡ERROR!\n", LEN_NAME, 3)==0)
		{
			if(utn_getName(aux.lastName, "\nIngrese el apellido del empleado: \n", "\n¡ERROR!\n", LEN_NAME, 3)==0)
			{
				if(utn_getFloat(&aux.salary, "\nIngrese el salario del empleado: \n", "\n¡ERROR!\n", 0, 9999999, 3)==0)
				{
					if(utn_getInt(&aux.sector, "\nIngrese el numero de sector en donde trabaja el empleado: \n", "\n¡ERROR!\n", 0, 9999999, 3)==0)
					{
						if(AddEmployee(list, len, idAux, aux.name, aux.lastName, aux.salary, aux.sector)==0)
						{
							rtn = 0;
							*id = idAux;
						}
					}
				}
			}
		}
	}

	return rtn;
}

/// \brief Muestra los empleados en ALTA y solicita la eleccion de uno para MODIFICARLO.
/// \param list Employee* Puntero al array de empleados
/// \param len int Largo del array
/// \return Retorna (-1) en caso de error - (0) en caso de exito.
int ModificarEmpleado(Employee* list,int len)
{
	int rtn;
	int idModificacion;
	int index;
	char confirm;
	Employee aux;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		if(PrintEmployees(list, len)==0)
		{
			if(utn_getInt(&idModificacion, "\nIngrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 5)==0)
			{
				index = FindEmployeeById(list, len, idModificacion);
				while(index==-1)
				{
					puts("NO EXISTE ID.");
					utn_getInt(&idModificacion, "\nIngrese un ID para modificar: \n", "¡ERROR!\n", 1, 3000000, 5);
					index = FindEmployeeById(list, len, idModificacion);
				}

				if(PedirDatosParaModificar(list[index], &aux)==0)
				{
					if(utn_getCharParaContinuar(&confirm, "¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 3)==0 && confirm == 'S')
					{
						list[index] = aux;
						rtn = 0;
					}
				}
			}


		}
	}

	return rtn;
}

/// \brief Solicita los datos relacionados con el empleado que se quiere MODIFICAR
/// \param elementoParaModificar Employee Elemento del array que se quiere modificar
/// \param elementoModificado Employee Puntero a Employee en donde devolveran los datos modificados
/// \return Retorna (-1) en caso de error - (0) en caso de exito.
int PedirDatosParaModificar(Employee elementoParaModificar,Employee* elementoModificado)
{
	int rtn;
	int opciones;
	Employee aux;

	rtn = -1;

	if(elementoModificado != NULL)
	{
		aux = elementoParaModificar;

		printf("\n¿QUE DESEA MODIFICAR?\n1. NOMBRE\n2. APELLIDO\n3. SALARIO\n4. SECTOR\n");
		if(utn_getInt(&opciones, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 4, 3)==0)
		{
			switch(opciones)
			{
				case 1:
					if(utn_getName(aux.name, "\nIngrese el nombre del empleado: \n", "\n¡ERROR!\n", LEN_NAME, 3)==0)
					{
						*elementoModificado = aux;
						rtn = 0;
					}
					break;

				case 2:
					if(utn_getName(aux.lastName, "\nIngrese el apellido del empleado: \n", "\n¡ERROR!\n", LEN_NAME, 3)==0)
					{
						*elementoModificado = aux;
						rtn = 0;
					}
					break;

				case 3:
					if(utn_getFloat(&aux.salary, "\nIngrese el salario del empleado: \n", "\n¡ERROR!\n", 0, 9999999, 3)==0)
					{
						*elementoModificado = aux;
						rtn = 0;
					}
					break;

				case 4:
					if(utn_getInt(&aux.sector, "\nIngrese el numero de sector en donde trabaja el empleado: \n", "\n¡ERROR!\n", 0, 9999999, 3)==0)
					{
						*elementoModificado = aux;
						rtn = 0;
					}
					break;
			}
		}
	}

	return rtn;
}

/// \brief Informa la suma total de salarios de los empleados en ALTA. Ademas, realiza las llamadas a funciones que informan el salario promedio y la cantidad de empleados que superan el salario promedio.
/// \param list Employee* Puntero al array de empleados
/// \param len int Largo del array
/// \return Retorna (-1) en caso de error - (0) en caso de exito.
int InformarTotalSalarios(Employee* list,int len)
{
	int rtn;
	float totalSalarios;
	int cantidadEmpleados;
	float promedioSalarios;
	int cantidadSuperanPromedio;

	rtn = -1;

	if(list != NULL && len > 0)
	{
		cantidadEmpleados = CalcularTotalSalarios(list, len, &totalSalarios);

		if(cantidadEmpleados != -1)
		{
			printf("\nLA SUMA TOTAL DE SALARIOS DE EMPLEADOS EN ALTA ES: %.2f\n",totalSalarios);

			if(CalcularPromedioSalarios(totalSalarios, cantidadEmpleados, &promedioSalarios)==0)
			{
				InformarPromedioSalarios(promedioSalarios);

				if(CalcularCuantosSuperanElSalarioPromedio(list, len, promedioSalarios, &cantidadSuperanPromedio)==0)
				{
					InformarCuantosSuperanElSalarioPromedio(cantidadSuperanPromedio);

				}
				else
				{
					printf("\nNO EXISTE NINGUN EMPLEADO QUE SUPERE EL SALARIO PROMEDIO\n");
				}
				rtn = 0;
			}
		}

	}

	return rtn;
}

/// \brief Informa el salario promedio entre los empleados en ALTA.
/// \param promedioSalarios float Hace referencia al salario promedio.
void InformarPromedioSalarios(float promedioSalarios)
{
	printf("\nEL PROMEDIO DEL TOTAL DE SALARIOS DE EMPLEADOS EN ALTA ES: %.2f\n",promedioSalarios);
}

/// \brief Informa la cantidad de empleados que superan el salario promedio.
/// \param cantidadSuperanPromedio int Hace referencia a la cantidad de empleados.
void InformarCuantosSuperanElSalarioPromedio(int cantidadSuperanPromedio)
{
	printf("\nLA CANTIDAD DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO ES: %d\n",cantidadSuperanPromedio);
}

/// \brief Calcula la suma total de los salarios de los empleados en ALTA.
/// \param list Employee* Puntero al array de empleados
/// \param len int Largo del array
/// \param totalSalarios float Puntero a float donde se devolvera la suma total de los salarios de los empleados en ALTA.
/// \return Retorna (-1) en caso de error - (>0) que hace referencia a la cantidad de empleados en ALTA contabilizados y exito.
int CalcularTotalSalarios(Employee* list,int len,float* totalSalarios)
{
	int rtn;
	int i;
	float acumuladorSalarios;
	int contadorEmpleados;

	rtn = -1;
	acumuladorSalarios = 0;
	contadorEmpleados = 0;

	if(list != NULL && len > 0 && totalSalarios != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acumuladorSalarios = acumuladorSalarios + list[i].salary;
				contadorEmpleados++;
			}
		}

		if(contadorEmpleados > 0)
		{
			rtn = contadorEmpleados;
			*totalSalarios = acumuladorSalarios;
		}
	}
	return rtn;
}

/// \brief Calcula el promedio entre la suma total de salarios de los empleados en ALTA y la cantidad de empleados en ALTA.
/// \param totalSalarios float Es la suma total de salarios de los empleados en ALTA.
/// \param cantidadEmpleados int Es la cantidad de empleados en Alta
/// \param promedioSalarios float Puntero a float donde se devolvera el promedio entre la suma total de salarios y la cantidad de empleados.
/// \return Retorna (-1) en caso de error - (0) en caso de exito.
int CalcularPromedioSalarios(float totalSalarios,int cantidadEmpleados,float* promedioSalarios)
{
	int rtn;
	float promedio;

	rtn = -1;

	if(totalSalarios > 0 && cantidadEmpleados > 0 && promedioSalarios != NULL)
	{
		promedio = totalSalarios / cantidadEmpleados;
		*promedioSalarios = promedio;
		rtn = 0;
	}

	return rtn;
}

/// \brief Calcula la cantidad de empleados en ALTA que superan el salario promedio.
/// \param list Employee* Puntero al array de empleados
/// \param len int Largo del array
/// \param promedioSalarios float Es el salario promedio.
/// \param cantidadSuperanPromedio int Puntero a int donde se devolvera la cantidad de empleados que superan el salario promedio.
/// \return Retorna (-1) en caso de error - (0) en caso de exito.
int CalcularCuantosSuperanElSalarioPromedio(Employee* list,int len,float promedioSalarios,int* cantidadSuperanPromedio)
{
	int rtn;
	int i;
	int contador;

	rtn = -1;
	contador = 0;

	if(list != NULL && len > 0 && cantidadSuperanPromedio != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > promedioSalarios)
			{
				contador++;
			}
		}

		if(contador > 0)
		{
			rtn = 0;
			*cantidadSuperanPromedio = contador;
		}
	}

	return rtn;
}
