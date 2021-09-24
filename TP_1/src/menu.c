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

/// \brief Incluye y muestra un menu interactivo con opciones para elegir.
void MenuOpciones ()
{
	float primerNumero;
	float segundoNumero;
	int opciones;

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	double resultadoMultiplicacion;
	double resultadoFactorialA;
	double resultadoFactorialB;

	int devolucionDividir;
	int flagCalcularResultados;

	primerNumero = 0;
	segundoNumero = 0;
	flagCalcularResultados = 0;

	do
	{
		printf("\n==========CALCULADORA==========\n");
		printf("1. Ingresar 1er operando (A=%.2f)\n2. Ingresar 2do operando (B=%.2f)\n"
				"3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir",primerNumero,segundoNumero);
		if(utn_getInt(&opciones, "\nIngrese una opcion: ", "\n¡ERROR! ", 1, 5, 1)==0)
		{
			switch(opciones)
			{
				case 1:
					if(utn_getFloatSinLimite(&primerNumero, "\nIngrese un numero: ", "\n¡ERROR!", 1)==0)
					{
						printf("\n¡INGRESO EXITOSO!\n");
					}
					else
					{
						printf("\n¡ERROR EN EL INGRESO!\n");
					}

					break;

				case 2:
					if(utn_getFloatSinLimite(&segundoNumero, "\nIngrese un numero: ", "\n¡ERROR! ", 1)==0)
					{
						printf("\n¡INGRESO EXITOSO!\n");
					}
					else
					{
						printf("\n¡ERROR EN EL INGRESO!\n");
					}

					break;

				case 3:
					oper_SumarFloat(primerNumero, segundoNumero, &resultadoSuma);

					oper_RestarFloat(primerNumero, segundoNumero, &resultadoResta);

					devolucionDividir = oper_DividirFloat(primerNumero, segundoNumero, &resultadoDivision);

					oper_MultiplicacionFloat(primerNumero, segundoNumero, &resultadoMultiplicacion);

					resultadoFactorialA = oper_FactorialFloat(primerNumero);

					resultadoFactorialB = oper_FactorialFloat(segundoNumero);

					flagCalcularResultados = 1;

					printf("\n¡SE CALCULARON TODAS LAS OPERACIONES!\n");

					break;

				case 4:
					if(flagCalcularResultados == 1)
					{
						printf("\n==========RESULTADOS==========\n");
						printf("a) El resultado de %.2f+%.2f es: %.2f",primerNumero,segundoNumero,resultadoSuma);

						printf("\nb) El resultado de %.2f-%.2f es: %.2f",primerNumero,segundoNumero,resultadoResta);

						if(devolucionDividir == 1)
						{
							printf("\nc) El resultado de %.2f/%.2f es: %.2f",primerNumero,segundoNumero,resultadoDivision);
						}
						else
						{
							printf("\nc) No es posible dividir por cero");
						}
						printf("\nd) El resultado de %.2f*%.2f es: %.2f",primerNumero,segundoNumero,resultadoMultiplicacion);

						if(resultadoFactorialA > 0)
						{
							printf("\ne) El factorial de %.2f es: %.2f",primerNumero,resultadoFactorialA);
						}
						else
						{
							printf("\ne) No fue posible calcular el factorial de %.2f",primerNumero);
						}

						if(resultadoFactorialB > 0)
						{
							printf(" || El factorial de %.2f es: %.2f\n",segundoNumero,resultadoFactorialB);
						}
						else
						{
							printf(" || No fue posible calcular el factorial de %.2f\n",segundoNumero);
						}
					}
					else
					{
						printf("¡ERROR! PRIMERO SE DEBEN CALCULAR LOS RESULTADOS PARA PODER MOSTRAR\n");
					}

					break;

				case 5:
					printf("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
					break;
			}
		}

	}while(opciones != 5);
}
