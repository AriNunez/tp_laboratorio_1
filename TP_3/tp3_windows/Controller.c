#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;

	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_EmployeeFromText(pArchivo, pArrayListEmployee);
			fclose(pArchivo);
			retorno = 1;
		}
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;

	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path,"rb");

		if(pArchivo != NULL)
		{
			parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
			fclose(pArchivo);
			retorno = 1;
		}
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    Employee* pNewEmployee;

    retorno = 0;

    if(pArrayListEmployee != NULL)
    {
    	pNewEmployee = employee_new();
    	if(pNewEmployee != NULL)
    	{
    		if(employee_Alta(pNewEmployee)==1)
    		{
    			ll_add(pArrayListEmployee, pNewEmployee);
    			retorno = 1;
    		}
    		else
    		{
    			employee_delete(pNewEmployee);
    		}
    	}
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int index;
	char seguir;
	char confirmacion;
	int opciones;
	Employee* pEmployee;
	Employee* pAuxEmployee;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		if(controller_ElegirEmpleadoEnLista(pArrayListEmployee, &index)==1)
		{
			pEmployee = ll_get(pArrayListEmployee, index);
			pAuxEmployee = employee_ClonarEmployee(pEmployee);
			do
			{
				puts("\n\t>>¿QUE DESEA MODIFICAR?");
				puts("1. NOMBRE\n2. HORAS TRABAJADAS\n3. SUELDO\n");
				if(utn_getInt(&opciones, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 3, 3)==0)
				{
					switch(opciones)
					{
						case 1:
							if(employee_PedirNombre(nombre, 128)==1)
							{
								employee_setNombre(pAuxEmployee, nombre);
							}
							break;

						case 2:
							if(employee_PedirHorasTrabajadas(&horasTrabajadas)==1)
							{
								employee_setHorasTrabajadas(pAuxEmployee, horasTrabajadas);
							}
							break;

						case 3:
							if(employee_PedirSueldo(&sueldo)==1)
							{
								employee_setSueldo(pAuxEmployee, sueldo);
							}
							break;
					}
				}

				if(utn_getCharParaContinuar(&seguir, "\n¿DESEA SEGUIR MODIFICANDO? S/N\n", "¡ERROR!\n", 'S', 'N', 5)==-1)
				{
					break;
				}

				}while(seguir=='S');

			if(seguir == 'N' && utn_getCharParaContinuar(&confirmacion, "\n¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 5)==0 && confirmacion == 'S')
			{
				ll_set(pArrayListEmployee, index, pAuxEmployee);
				employee_delete(pEmployee);
				retorno = 1;
			}
			else
			{
				employee_delete(pAuxEmployee);
			}
		}

	}

	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int index;
	char confirmacion;

	retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		if(controller_ElegirEmpleadoEnLista(pArrayListEmployee, &index)==1)
		{
			if(utn_getCharParaContinuar(&confirmacion, "\n¿DESEA CONTINUAR? S/N\n", "¡ERROR!\n", 'S', 'N', 5)==0 && confirmacion == 'S' && index != -1)
			{
				ll_remove(pArrayListEmployee, index);
				retorno = 1;
			}

		}
	}

	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int len;
	int i;
	Employee* pEmployee;

	retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		puts("\n\t>>Listado Empleados");
		printf("\n|%-10s|%-25s|%-25s|%-25s|\n\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");

		for(i=0;i<len;i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if(employee_MostrarUno(pEmployee)==1)
			{
				retorno = 1;
			}
		}

	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int criterio;
	int orden;

	retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		puts("\n\t>>Listado Criterios");
		puts("1. ID\n2. NOMBRE\n3. HORAS TRABAJADAS\n4. SUELDO\n");
		if(utn_getInt(&criterio, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 4, 3)==0)
		{
			puts("\n\t>>Listado Orden");
			puts("1. ASCENDENTE\n2. DESCENDENTE\n");
			if(utn_getInt(&orden, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 2, 3)==0)
			{
				if(orden==2)
				{
					orden=0;
				}

				switch(criterio)
				{
					case 1:
						ll_sort(pArrayListEmployee, employee_CompareById, orden);
						break;

					case 2:
						ll_sort(pArrayListEmployee, employee_CompareByName, orden);
						break;

					case 3:
						ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, orden);
						break;

					case 4:
						ll_sort(pArrayListEmployee, employee_CompareBySueldo, orden);
						break;
				}
				retorno = 1;
			}
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;
	Employee* pEmpleado;
	int len;
	int i;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
	{
		pArchivo = fopen(path,"w");

		if(pArchivo != NULL)
		{
			len = ll_len(pArrayListEmployee);

			fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

			for(i=0;i<len;i++)
			{
				pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				if(pEmpleado == NULL)
				{
					break;
				}

				employee_getId(pEmpleado, &id);
				employee_getNombre(pEmpleado, nombre);
				employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);
				employee_getSueldo(pEmpleado, &sueldo);

				fprintf(pArchivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
			}

			fclose(pArchivo);

			if(len==i)
			{
				retorno = 1;
			}
		}

	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno;
    FILE* pArchivo;
    Employee* pEmpleado;
    int i;
    int len;

    retorno = 0;

    if(path != NULL && pArrayListEmployee && ll_isEmpty(pArrayListEmployee)==0)
    {
    	pArchivo = fopen(path,"wb");
    	if(pArchivo != NULL)
    	{
    		len = ll_len(pArrayListEmployee);
    		for(i=0;i<len;i++)
    		{
    			pEmpleado = ll_get(pArrayListEmployee, i);
    			if(pEmpleado == NULL)
    			{
    				break;
    			}

    			fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
    		}
    		fclose(pArchivo);

    		if(len == i)
    		{
    			retorno = 1;
    		}
    	}
    }

    return retorno;
}

/// \fn int controller_ElegirEmpleadoEnLista(LinkedList*, int*)
/// \brief
/// \param pArrayListEmployee
/// \param index
/// \return
int controller_ElegirEmpleadoEnLista(LinkedList* pArrayListEmployee,int* index)
{
	int retorno;
	int i;
	int id;
	int len;
	Employee* pAuxEmployee;
	Employee* pEmployee;

	retorno = 0;

	if(pArrayListEmployee != NULL && index != NULL)
	{
		*index = -1;
		if(controller_ListEmployee(pArrayListEmployee)==1)
		{
			if(utn_getInt(&id, "\nSeleccione un ID de empleado: \n", "\n¡ERROR!\n", 1, 1000000, 3)==0)
			{
				pAuxEmployee = employee_new();

				if(pAuxEmployee != NULL)
				{
					employee_setId(pAuxEmployee, id);

					len = ll_len(pArrayListEmployee);

					for(i=0;i<len;i++)
					{
						pEmployee = ll_get(pArrayListEmployee, i);

						if(pEmployee != NULL && employee_CompareById(pEmployee, pAuxEmployee)==0)
						{
							retorno = 1;
							*index = i;
							employee_delete(pAuxEmployee);
							break;
						}
					}
				}
			}

		}
	}

	return retorno;
}
