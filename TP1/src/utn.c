/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: ariel
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets (char* cadena, int longitud);

/*
 * \brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado.
 * \param pNumero Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param pTexto Es el mensaje a ser mostrado
 * \param minimo Es el numero minimo a ser aceptado
 * \param maximo Es el numero maximo a ser aceptado
 * \param reintento Es el numero de reintentos para poder ingresar un dato valido
 * \param pError Es el mensaje de Error a ser mostrado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getInt(int* pNumero,char* pTexto,int minimo,int maximo,int reintento,char* pError)
{
	int retorno = -1;
	int bufferInt;

	if(pNumero != NULL && pTexto != NULL && pError != NULL && minimo <= maximo && reintento >= 0)
	{
		retorno = -2;

		do
		{
			printf("%s", pTexto);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pNumero = bufferInt;
				break;
			}

			printf("%s",pError);
			reintento--;

		}while(reintento >=0);
	}

	return retorno;
}

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
		__fpurge(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}

	return -1;
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
