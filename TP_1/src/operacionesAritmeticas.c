/*
 * operacionesAritmeticas.c
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>


int oper_DividirInt(int numeroA, int numeroB,float *pResultado)
{
	int retorno;

	if(pResultado != NULL)
	{
		if(numeroB == 0)
		{
			retorno = 0;
		}
		else
		{
			*pResultado =(float) numeroA / numeroB;
			retorno = 1;
		}
	}
	return retorno;
}


int oper_SumarInt(int numeroA, int numeroB, long *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA + numeroB;
		retorno = 1;
	}
	return retorno;
}


int oper_RestarInt(int numeroA, int numeroB, long *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA - numeroB;
		retorno = 1;
	}
	return retorno;
}


int oper_MultiplicacionInt(int numeroA, int numeroB, long *pResultado)
{
	int retorno;

	retorno = 0;

	if(pResultado != NULL)
	{
		*pResultado = numeroA * numeroB;
		retorno = 1;
	}
	return retorno;
}


int oper_FactorialInt(int numero,unsigned long* pResultado)
{
	int retorno;
	int bufferInt;
	unsigned long bufferResultado;

	retorno = 0;
	bufferInt = numero;
	bufferResultado = 1;

	if(pResultado != NULL)
	{
		if(bufferInt > 0)
			{
				while(bufferInt > 0)
				{
					bufferResultado = bufferResultado * bufferInt;
					bufferInt--;
				}
				*pResultado = bufferResultado;
				retorno = 1;
			}
			else
			{
				if(bufferInt == 0)
				{
					*pResultado = 1;
					retorno = 2;
				}
			}
	}
	return retorno;
}

unsigned long long CalcularFactorial(int numeroIngresado)
{
	int resultado;

	resultado = -1;

	if(numeroIngresado == 0)
	{
		resultado = 1;
	}
	else
	{
		resultado = numeroIngresado * CalcularFactorial(numeroIngresado-1);
	}

	return resultado;
}
