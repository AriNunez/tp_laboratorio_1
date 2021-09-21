/*
 * menu.c
 *
 *  Created on: 18 sep. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "operacionesAritmeticas.h"

void MenuOpciones ()
{
	int primerNumero;
	int segundoNumero;
	int opciones;

	long resultadoSuma;
	long resultadoResta;
	float resultadoDivision;
	long resultadoMultiplicacion;
	unsigned long long resultadoFactorialA;
	unsigned long long resultadoFactorialB;

	int devolucionDividir;
	//int devolucionFactorialA;
	//int devolucionFactorialB;

	primerNumero = 0;
	segundoNumero = 0;

	do
	{
		printf("\n==========CALCULADORA==========\n");
		printf("1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n"
				"3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir",primerNumero,segundoNumero);
		if(utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 1, 5, 1)==0)
		{
			switch(opciones)
			{
				case 1:
					if(utn_getIntSinLimite(&primerNumero, "\nIngrese un numero entero: ", "\n¡ERROR!", 1)==0)
					{
						printf("\n¡INGRESO EXITOSO!\n");
					}
					else
					{
						printf("\n¡ERROR EN EL INGRESO!\n");
					}
					break;

				case 2:
					if(utn_getIntSinLimite(&segundoNumero, "\nIngrese un numero entero: ", "\n¡ERROR! ", 1)==0)
					{
						printf("\n¡INGRESO EXITOSO!\n");
					}
					else
					{
						printf("\n¡ERROR EN EL INGRESO!\n");
					}
					break;

				case 3:
					oper_SumarInt(primerNumero, segundoNumero, &resultadoSuma);

					oper_RestarInt(primerNumero, segundoNumero, &resultadoResta);

					devolucionDividir = oper_DividirInt(primerNumero, segundoNumero, &resultadoDivision);

					oper_MultiplicacionInt(primerNumero, segundoNumero, &resultadoMultiplicacion);

					//devolucionFactorialA = oper_FactorialInt(primerNumero, &resultadoFactorialA);

					//devolucionFactorialB = oper_FactorialInt(segundoNumero, &resultadoFactorialB);

					resultadoFactorialA = CalcularFactorial(primerNumero);
					resultadoFactorialB = CalcularFactorial(segundoNumero);
					break;

				case 4:
					printf("\n==========RESULTADOS==========\n");
					printf("\na) El resultado de %d+%d es: %li",primerNumero,segundoNumero,resultadoSuma);

					printf("\nb) El resultado de %d-%d es: %li",primerNumero,segundoNumero,resultadoResta);

					if(devolucionDividir == 1)
					{
						printf("\nc) El resultado de %d/%d es: %f",primerNumero,segundoNumero,resultadoDivision);
					}
					else
					{
						printf("\nc) No es posible dividir por cero");
					}
					printf("\nd) El resultado de %d*%d es: %li",primerNumero,segundoNumero,resultadoMultiplicacion);

					/*if(devolucionFactorialA > 0)
					{
						printf("\ne) El factorial de %d es: %lu",primerNumero,resultadoFactorialA);
					}
					else
					{
						printf("\ne) No fue posible calcular el factorial de %d",primerNumero);
					}

					if(devolucionFactorialB > 0)
					{
						printf(" || El factorial de %d es: %lu\n",segundoNumero,resultadoFactorialB);
					}
					else
					{
						printf(" || No fue posible calcular el factorial de %d\n",segundoNumero);
					}*/

					if(resultadoFactorialA > 0)
					{
						printf("\ne) El factorial de %d es: %lu",primerNumero,resultadoFactorialA);
					}
					else
					{
						printf("\ne) No fue posible calcular el factorial de %d",primerNumero);
					}

					if(resultadoFactorialB > 0)
					{
						printf(" || El factorial de %d es: %lu\n",segundoNumero,resultadoFactorialB);
					}
					else
					{
						printf(" || No fue posible calcular el factorial de %d\n",segundoNumero);
					}

					break;

				case 5:
					printf("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
					break;
			}
		}

	}while(opciones != 5);


}
