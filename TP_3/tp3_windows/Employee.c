#include "Employee.h"

//****FUNCIONES ESTATICAS****
static void employee_GenerarID(int* idAumentado);
static void employee_BuscarUltimoID(char* id);
static void employee_GuardarUltimoID(int id);

//****FUNCIONES****

/// \brief Crea un nuevo Employee en memoria de manera dinamica y lo inicializa con valores iniciales
/// \return Employee* Retorna (NULL) en caso de no conseguir espacio en memoria o el puntero al espacio reservado
Employee* employee_new()
{
	Employee* pNewEmployee = NULL;

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

/// \brief Asigna valores a un Employee que se encuentra en memoria dinamica
/// \param idStr char* Puntero a string
/// \param nombreStr char* Puntero a string
/// \param horasTrabajadasStr char* Puntero a string
/// \param sueldoStr char* Puntero a string
/// \return Employee* Retorna (NULL) en caso de error - en caso de exito retorna el puntero al espacio reservado con valores asignados
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pNewEmployee = NULL;
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

/// \brief Elimina un Employee que se encuentra en memoria dinamica
/// \param this Employee* Puntero a empleado
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/// \brief Muestra los valores de un Employee
/// \param this Employee* Puntero a empleado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el Employee recibido por paramentro
/// \param this Employee* Puntero a empleado
/// \param id int
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del Employee recibido por parametro y lo devuelve
/// \param this Employee* Puntero a empleado
/// \param id int* Puntero a int donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el Employee recibido por paramentro
/// \param this Employee* Puntero a empleado
/// \param nombre char* Puntero a string
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del Employee recibido por parametro y lo devuelve
/// \param this Employee* Puntero a empleado
/// \param nombre char* Puntero a string donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el Employee recibido por paramentro
/// \param this Employee* Puntero a empleado
/// \param id int
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del Employee recibido por parametro y lo devuelve
/// \param this Employee* Puntero a empleado
/// \param id int* Puntero a int donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Asigna un valor en el Employee recibido por paramentro
/// \param this Employee* Puntero a empleado
/// \param id int
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Toma un valor del Employee recibido por parametro y lo devuelve
/// \param this Employee* Puntero a empleado
/// \param id int* Puntero a int donde se guardara el valor buscado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstEmployee void* Puntero al primer elemento a comparar
/// \param pSecondEmployee void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (1) en caso de que el primero sea mayor - (-1) en caso de que el segundo sea mayor
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstEmployee void* Puntero al primer elemento a comparar
/// \param pSecondEmployee void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (>=1) en caso de que el primero sea mayor - (<=-1) en caso de que el segundo sea mayor
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstEmployee void* Puntero al primer elemento a comparar
/// \param pSecondEmployee void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (1) en caso de que el primero sea mayor - (-1) en caso de que el segundo sea mayor
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

/// \brief Compara dos elementos recibidos por parametro
/// \param pFirstEmployee void* Puntero al primer elemento a comparar
/// \param pSecondEmployee void* Puntero al segundo elemento a comparar
/// \return int Retorna (0) en caso de que sean iguales - (1) en caso de que el primero sea mayor - (-1) en caso de que el segundo sea mayor
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

/// \brief Realiza el alta de un Employee con espacio reservado en memoria dinamica
/// \param pNewEmployee Employee* Puntero a empleado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Realiza la carga de datos para un Employee con espacio reservado en memoria dinamica
/// \param pNewEmployee Employee* Puntero a empleado
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Pide al usuario un nombre
/// \param nombre char* Puntero a string donde se guardara el nombre pedido
/// \param tam int Representa el largo de la cadena
/// \return int Retorna (0) en caso de error - (1) en caso de exito
int employee_PedirNombre(char* nombre,int tam)
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

/// \brief Pide al usuario la cantidad de horas trabajadas
/// \param horasTrabajadas int* Puntero a int donde se guardara el dato pedido
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Pide al usuario que ingrese el sueldo
/// \param sueldo int* Puntero a int donde se guardara el dato pedido
/// \return int Retorna (0) en caso de error - (1) en caso de exito
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

/// \brief Clona en un Employee auxiliar los datos del Employee que recibe por paramentro
/// \param pEmployee Employee* Puntero a empleado
/// \return Employee* Retorna (NULL) en caso de error - en caso de exito retorna el puntero al empleado clon
Employee* employee_ClonarEmployee(Employee* pEmployee)
{
	Employee* pAuxEmployee = NULL;
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

/// \brief Genera un ID autoincremental
/// \param idAumentado int* Puntero a int donde se guardara el ID autoincrementado
static void employee_GenerarID(int* idAumentado)
{
	char id[128];
	int idAux;

	employee_BuscarUltimoID(id);
	idAux=atoi(id);
	idAux++;
	*idAumentado = idAux;
}

/// \brief Lee un archivo y busca cual es el ultimo ID cargado
/// \param id int* Puntero a char donde se guardara el ID leido desde el archivo
static void employee_BuscarUltimoID(char* id)
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

/// \brief Escribe en un archivo el ultimo ID cargado
/// \param id int Entero que representa el ultimo ID cargado
static void employee_GuardarUltimoID(int id)
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
