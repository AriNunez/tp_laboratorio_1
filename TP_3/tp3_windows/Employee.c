#include "Employee.h"

Employee* employee_new()
{
	Employee* pNewEmployee;

	pNewEmployee = (Employee*) malloc(sizeof(Employee));

	if(pNewEmployee != NULL)
	{
		pNewEmployee->id = 0;
		strcpy(pNewEmployee->nombre,"0");
		pNewEmployee->horasTrabajadas = 0;
		pNewEmployee->sueldo = 0;
	}

	return pNewEmployee;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pNewEmployee;
	int id;
	int horasTrabajadas;
	int sueldo;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		pNewEmployee = employee_new();

		if(pNewEmployee != NULL)
		{
			id = atoi(idStr);
			horasTrabajadas = atoi(horasTrabajadasStr);
			sueldo = atoi(sueldoStr);
			employee_setId(pNewEmployee, id);
			employee_setNombre(pNewEmployee, nombreStr);
			employee_setHorasTrabajadas(pNewEmployee, horasTrabajadas);
			employee_setSueldo(pNewEmployee, sueldo);

		}
	}

	return pNewEmployee;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int employee_MostrarUno(Employee* this)
{
	int retorno;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horasTrabajadas);
		employee_getSueldo(this, &sueldo);

		printf("|%-10d|%-25s|%-25d|%-25d|\n",id,nombre,horasTrabajadas,sueldo);
	}

	return retorno;
}


int employee_setId(Employee* this,int id)
{
	int retorno;

	retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno;

	retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}



int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;

	retorno = 0;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;

	retorno = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;

	retorno = 0;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;

	retorno = 0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}


int employee_CompareById(void* pFirstEmployee,void* pSecondEmployee)
{
	int retorno;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	int idPrimerEmpleado;
	int idSegundoEmpleado;

	if(pFirstEmployee != NULL && pSecondEmployee != NULL)
	{
		pPrimerEmpleado = (Employee*) pFirstEmployee;
		pSegundoEmpleado = (Employee*) pSecondEmployee;
		employee_getId(pPrimerEmpleado, &idPrimerEmpleado);
		employee_getId(pSegundoEmpleado, &idSegundoEmpleado);
		retorno = 0;

		if(idPrimerEmpleado > idSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(idPrimerEmpleado < idSegundoEmpleado)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_CompareByName(void* pFirstEmployee,void* pSecondEmployee)
{
	int retorno;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	char nombrePrimerEmpleado[128];
	char nombreSegundoEmpleado[128];

	if(pFirstEmployee != NULL && pSecondEmployee != NULL)
	{
		pPrimerEmpleado = (Employee*) pFirstEmployee;
		pSegundoEmpleado = (Employee*) pSecondEmployee;
		employee_getNombre(pPrimerEmpleado, nombrePrimerEmpleado);
		employee_getNombre(pSegundoEmpleado, nombreSegundoEmpleado);

		retorno = strcmp(nombrePrimerEmpleado,nombreSegundoEmpleado);
	}


	return retorno;
}

int employee_CompareByHorasTrabajadas(void* pFirstEmployee,void* pSecondEmployee)
{
	int retorno;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	int hsPrimerEmpleado;
	int hsSegundoEmpleado;

	if(pFirstEmployee != NULL && pSecondEmployee != NULL)
	{
		pPrimerEmpleado = (Employee*) pFirstEmployee;
		pSegundoEmpleado = (Employee*) pSecondEmployee;
		employee_getHorasTrabajadas(pPrimerEmpleado, &hsPrimerEmpleado);
		employee_getHorasTrabajadas(pSegundoEmpleado, &hsSegundoEmpleado);

		retorno = 0;

		if(hsPrimerEmpleado > hsSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(hsPrimerEmpleado < hsSegundoEmpleado)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_CompareBySueldo(void* pFirstEmployee,void* pSecondEmployee)
{
	int retorno;
	Employee* pPrimerEmpleado;
	Employee* pSegundoEmpleado;
	int sueldoPrimerEmpleado;
	int sueldoSegundoEmpleado;

	if(pFirstEmployee != NULL && pSecondEmployee != NULL)
	{
		retorno = 0;
		pPrimerEmpleado = (Employee*) pFirstEmployee;
		pSegundoEmpleado = (Employee*) pSecondEmployee;

		employee_getSueldo(pPrimerEmpleado, &sueldoPrimerEmpleado);
		employee_getSueldo(pSegundoEmpleado, &sueldoSegundoEmpleado);

		if(sueldoPrimerEmpleado > sueldoSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(sueldoPrimerEmpleado < sueldoSegundoEmpleado)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_Alta(Employee* pNewEmployee)
{
	 int retorno;
	 int id;

	 retorno = 0;

	if(pNewEmployee != NULL)
	{
		if(employee_CargarDatos(pNewEmployee)==1)
		{
			employee_GenerarID(&id);
			employee_setId(pNewEmployee, id);
			employee_GuardarUltimoID(id);
			retorno = 1;
		}
	}

	return retorno;
}


int employee_CargarDatos(Employee* pNewEmployee)
{
	int retorno;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	retorno = 0;

	if(pNewEmployee != NULL)
	{
		if(employee_PedirNombre(nombre, 128)==1)
		{
			if(employee_PedirHorasTrabajadas(&horasTrabajadas)==1)
			{
				if(employee_PedirSueldo(&sueldo)==1)
				{
					retorno = 1;
					employee_setNombre(pNewEmployee, nombre);
					employee_setHorasTrabajadas(pNewEmployee, horasTrabajadas);
					employee_setSueldo(pNewEmployee, sueldo);
				}
			}
		}
	}
	return retorno;
}

int employee_PedirNombre(char nombre[],int tam)
{
	int retorno;
	char auxNombre[tam];

	retorno = 0;

	if(nombre != NULL && tam > 0)
	{
		if(utn_getName(auxNombre, "\nIngrese un nombre: \n", "\n¡ERROR!\n", tam, 3)==0)
		{
			strcpy(nombre,auxNombre);
			retorno = 1;
		}
	}

	return retorno;
}

int employee_PedirHorasTrabajadas(int* horasTrabajadas)
{
	int retorno;
	int auxHorasTrabajadas;

	retorno = 0;

	if(horasTrabajadas != NULL)
	{
		if(utn_getInt(&auxHorasTrabajadas, "\nIngrese la cantidad de horas trabajadas: \n", "\n¡ERROR!\n", 0, 1000000, 3)==0)
		{
			*horasTrabajadas = auxHorasTrabajadas;
			retorno = 1;
		}
	}

	return retorno;
}

int employee_PedirSueldo(int* sueldo)
{
	int retorno;
	int auxSueldo;

	retorno = 0;

	if(sueldo != NULL)
	{
		if(utn_getInt(&auxSueldo, "\nIngrese el sueldo: \n", "\n¡ERROR!\n", 0, 9999999, 3)==0)
		{
			*sueldo = auxSueldo;
			retorno = 1;
		}
	}

	return retorno;
}

Employee* employee_ClonarEmployee(Employee* pEmployee)
{
	Employee* pAuxEmployee;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(pEmployee != NULL)
	{

		pAuxEmployee = employee_new();

		if(pAuxEmployee != NULL)
		{
			employee_getId(pEmployee, &id);
			employee_getNombre(pEmployee, nombre);
			employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
			employee_getSueldo(pEmployee, &sueldo);

			employee_setId(pAuxEmployee, id);
			employee_setNombre(pAuxEmployee, nombre);
			employee_setHorasTrabajadas(pAuxEmployee, horasTrabajadas);
			employee_setSueldo(pAuxEmployee, sueldo);
		}
	}

	return pAuxEmployee;
}


void employee_GenerarID(int* idAumentado)
{
	char id[128];
	int idAux;

	employee_BuscarUltimoID(id);
	idAux=atoi(id);
	idAux++;
	*idAumentado = idAux;
}

void employee_BuscarUltimoID(char* id)
{
	char idAux[128];
	FILE* pArchivo;

	pArchivo = fopen("id.csv","r");
	if(pArchivo != NULL && id != NULL)
	{
		fscanf(pArchivo,"%s",idAux);

		fclose(pArchivo);

		strcpy(id,idAux);
	}
}

void employee_GuardarUltimoID(int id)
{
	int idAux;
	FILE* pArchivo;

	pArchivo = fopen("id.csv","w");
	if(pArchivo != NULL && id > 0)
	{
		idAux = id;
		fprintf(pArchivo,"%d",idAux);
		fclose(pArchivo);
	}

}
