/*
 * utn.c
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------PROTOTIPOS DE FUNCIONES STATIC--------------------
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets (char* cadena, int longitud);
static int getFloat(float* pResultado);
static int esNumericaConDecimal(char* cadena);

//--------------------INTEGER--------------------

int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}

int utn_getIntSinLimite(int* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}
/*
 * \brief Verifica si la cadena ingresada es numerica.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			retorno = 0;
			*pResultado = atoi(buffer);//convierte un string en caso de ser posible en un numero int
		}
	}
	return retorno;
}
/*
 * \brief Verifica si la cadena ingresada es numerica.
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esNumerica(char* cadena)//trata de verificar si cada caracter es un numero falso 0 y verdadero 1
{
	int retorno = 1;
	int i;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		else
		{
			i = 0;
		}

		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

//--------------------FLOAT--------------------
/*
 * \brief Solicita un numero con decimales al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \param reintentos Es el numero de reintentos para poder ingresar un dato valido
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}

			printf("%s",mensajeError);
			reintentos--;

		}while(reintentos >=0);
	}

	return retorno;
}
/*
 * \brief Verifica si la cadena ingresada es numerica con decimal.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumericaConDecimal(buffer))
		{
			retorno = 0;
			*pResultado = atof(buffer);//convierte un string en caso de ser posible en un numero int
		}
	}
	return retorno;
}

/*
 * \brief Verifica si la cadena ingresada es numerica con decimal.
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esNumericaConDecimal(char* cadena)//trata de verificar si cada caracter es un numero falso 0 y verdadero 1
{
	int retorno = 1;
	int i;
	int contadorPuntos = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}
		else
		{
			i = 0;
		}

		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.')
			{
				retorno = 0;
			}
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			i++;
		}
		if(contadorPuntos > 1)
		{
			retorno = 0;
		}
	}
	return retorno;
}

//-----------------FUNCION PRINCIPAL-----------------------
/*
 * \brief Lee un stdin (lo que lee por consola) hasta que encuentra un '\n' o hasta que haya copiado
 * 		  en cadena un maximo de 'longitud - 1' caracteres.
 *	\param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 *	\param longitud Define el tamaño de cadena
 *	\return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 */
static int myGets (char* cadena, int longitud)//verifica que no se desborde y remplaza el scanf
{
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin) == cadena)//file gets, lee un archivo, longitud me da el limte y cadena el espacio donde lo voy a guardar
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}

	return -1;
}
