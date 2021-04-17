/*
 * operacionesAritmeticas.c
 *
 *  Created on: 11 abr. 2021
 *      Author: ariel
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

/*
 * \brief Recibe dos numeros, los divide (siempre que el divisor sea distinto a 0) y devuelve el resultado
 * \param numeroA Recibe el dividendo de la operacion
 * \param numeroB Recibe el divisor de la operacion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) en caso haber realizado la operacion y -1 (ERROR) si no
 */
int oper_dividir(int numeroA, int numeroB,float *pResultado)
{
	int retorno;

	if(pResultado != NULL)
	{
		if(numeroB == 0)
		{
			retorno = -1;
		}
		else
		{
			*pResultado =(float) numeroA / numeroB;
			retorno = 0;
		}
	}
	return retorno;
}

/*
 * \brief Recibe dos numeros, los suma y devulve el resultado
 * \param numeroA Recibe el primer numero de la operacion
 * \param numeroB Recibe el segundo numero de la operacion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) en caso haber realizado la operacion y -1 (ERROR) si no
 */
int oper_sumarInt(int numeroA, int numeroB, int *pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numeroA + numeroB;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief Recibe dos numeros, los resta y devulve el resultado
 * \param numeroA Recibe el primer numero de la operacion
 * \param numeroB Recibe el segundo numero de la operacion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) en caso haber realizado la operacion y -1 (ERROR) si no
 */
int oper_restarInt(int numeroA, int numeroB, int *pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numeroA - numeroB;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief Recibe dos numeros, los multiplica y devulve el resultado
 * \param numeroA Recibe el primer numero de la operacion
 * \param numeroB Recibe el segundo numero de la operacion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) en caso haber realizado la operacion y -1 (ERROR) si no
 */
int oper_multiplicacionInt(int numeroA, int numeroB, int *pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		*pResultado = numeroA * numeroB;
		retorno = 0;
	}
	return retorno;
}

/*
 * \brief Recibe un numero, calcula su factorial y devuelve el resultado
 * \param numero Recibe el numero para realizar la operacion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) en caso haber realizado la operacion y -1 (ERROR) si no
 */
int oper_factorialInt(int numero,long long int* pResultado)
{
	int retorno = 0;
	int bufferInt = numero;
	long long int bufferResultado = 1;

	if(pResultado != NULL)
	{
		if(bufferInt == 0)
			{
				*pResultado = 1;
			}
			else
			{
				if(bufferInt > 0)
				{

					while(bufferInt > 0)
						{
							bufferResultado = bufferResultado * bufferInt;
							bufferInt--;
						}
				}
				else
				{
					retorno = -1;
				}
			}
		*pResultado = bufferResultado;
	}
	return retorno;
}
