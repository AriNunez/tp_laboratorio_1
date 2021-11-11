#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	int i;
	Employee* pEmpleado;
	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
	int idAux;

	retorno = 0;
	i = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
			{
				pEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(ll_add(pArrayListEmployee, pEmpleado)==-1)
				{
					employee_delete(pEmpleado);
				}
				else
				{
					idAux = atoi(id);
					employee_GuardarUltimoID(idAux);
				}

				i++;
			}
		}

		retorno = 1;
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* pEmpleado;
	int i;
	int id;


	i = 0;
	retorno = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			pEmpleado = employee_new();
			if(pEmpleado != NULL)
			{
				fread(pEmpleado,sizeof(Employee),1,pFile);
				if(feof(pFile))
				{
					break;
				}

				if(ll_add(pArrayListEmployee, pEmpleado)==-1)
				{
					employee_delete(pEmpleado);
					break;
				}
				else
				{
					employee_getId(pEmpleado, &id);
					employee_GuardarUltimoID(id);
				}

				i++;
			}
		}
		retorno = 1;
	}

    return retorno;
}
