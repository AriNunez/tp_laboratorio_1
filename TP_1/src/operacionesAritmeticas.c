/*
 * operacionesAritmeticas.c
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "operacionesAritmeticas.h"

/**FLOTANTES**/

/// \brief Recibe dos numeros reales, los divide y devuelve el resultado. Verifica que el divisor sea distinto de 0.
/// \param numeroA Representa al dividendo.
/// \param numeroB Representa al divisor.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido.
/// \return Retorna 1 (EXITO) en caso de poder realizar la division y 0 (ERROR) si detecta que el divisor es igual a 0.
int oper_DividirFloat(float numeroA, float numeroB,float *pResultado)
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
			*pResultado = numeroA / numeroB;
			retorno = 1;
		}
	}
	return retorno;
}

/// \brief Recibe dos numeros reales, los suma y devuelve el resultado.
/// \param numeroA Representa el primer numero de la suma.
/// \param numeroB Representa el segundo numero de la suma.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido.
/// \return Retorna 1 (EXITO) en caso de poder realizar la suma y 0 (ERROR) si no.
int oper_SumarFloat(float numeroA, float numeroB, float *pResultado)
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

/// \brief Recibe dos numeros reales, los resta y devuelve el resultado.
/// \param numeroA Representa el primer numero de la resta.
/// \param numeroB Representa el segundo numero de la resta.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido.
/// \return Retorna 1 (EXITO) en caso de poder realizar la resta y 0 (ERROR) si no.
int oper_RestarFloat(float numeroA, float numeroB, float *pResultado)
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

/// \brief Recibe dos numeros reales, los multiplica y devuelve el resultado.
/// \param numeroA Representa un factor de la multiplicacion.
/// \param numeroB Representa un factor de la multiplicacion.
/// \param pResultado Puntero al espacio de memoria donde se guardara el numero obtenido.
/// \return Retorna 1 (EXITO) en caso de poder realizar la multiplicacion y 0 (ERROR) si no.
int oper_MultiplicacionFloat(float numeroA, float numeroB, double *pResultado)
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

/// \brief Recibe un numero real, verifica si es un numero entero y mayor a 0, y en caso de serlo calcula su factorial.
/// \param numeroIngresado Representa el numero del cual se quiere saber su factorial.
/// \return Retorna el resultado del factorial. Devuelve un numero mayor a 0 (EXITO) en caso de calcular el factorial y 0 (ERROR) si no pudo.
double oper_FactorialFloat(float numeroIngresado)
{
	double resultado;
	int verificacion;

	resultado = 0;
	verificacion = VerificarNumeroEntero(numeroIngresado);

	if(verificacion==1)
	{
		if(numeroIngresado == 0)
		{
			resultado = 1;
		}
		else
		{
			if(numeroIngresado > 0)
			{
				resultado = (int)numeroIngresado * oper_FactorialFloat((int)numeroIngresado-1);
			}
		}
	}
	return resultado;
}

/**VERIFICACIONES**/

/// \brief Recibe un numero real y verifica si es un numero equivalente a un numero entero.
/// \param numeroIngresado Es el para verificar.
/// \return Retorna 1 (EXITO) en caso de verificar que el numero real ingresado equivale a un numero entero  y 0 (ERROR) si no.
int VerificarNumeroEntero(float numeroIngresado)
{
	int retorno;
	int numeroIngresadoEntero;
	float resultadoParaVerificar;

	numeroIngresadoEntero = numeroIngresado;
	retorno = 0;

	resultadoParaVerificar = numeroIngresado - numeroIngresadoEntero;

	if(resultadoParaVerificar == 0)
	{
		retorno = 1;
	}

	return retorno;
}
