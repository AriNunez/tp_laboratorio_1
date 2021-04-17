/*
 ============================================================================
 Name        : TP1.c
 Author      : Ariel Nuñez I-H
 Version     :
 Copyright   : Your copyright notice
 Description : TP1
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "operacionesAritmeticas.h"
#include "utn.h"

int main(void)
{
	int opcionMenuPrincipal;
	int opcionMenu3;
	int numeroA=0;
	int numeroB=0;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	long long int resultadoFactorialA;
	long long int resultadoFactorialB;
	int respuestaDivision;
	int respuestaFactorialA;
	int respuestaFactorialB;
	int flagSuma=0;
	int flagResta=0;
	int flagDivision=0;
	int flagMultiplicacion=0;
	int flagFactorial=0;


	do
	{
		if(utn_getInt(&opcionMenuPrincipal, "\nSeleccione una opcion\n\n1-Ingresar 1er operando\n2-Ingresar 2do operando\n"
											"3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir\n", 1, 5, 2, "ERROR-No es una opcion valida\n")==0)
		{
			switch(opcionMenuPrincipal)
			{
			case 1:
				printf("A=%d",numeroA);
				utn_getInt(&numeroA, "\nINGRESE EL NUMERO A: \n", -1000000, 1000000, 2, "ERROR-DATO INVALIDO\n");
				break;

			case 2:
				printf("B=%d",numeroB);
				utn_getInt(&numeroB, "\nINGRESE EL NUMERO B: \n", -1000000, 1000000, 2, "ERROR-DATO INVALIDO\n");
				break;

			case 3:
				do
				{
					if(utn_getInt(&opcionMenu3, "\nSeleccione una opcion\n\n1-Calcular la suma (A+B)\n2-Calcular la resta (A-B)\n"
												"3-Calcular la division (A/B)\n4-Calcular la multiplicacion (A*B)\n5-Calcular el factorial(A! B!)\n6-Salir\n", 1, 6, 2, "ERROR-No es una opcion valida\n")==0)
					{
						switch(opcionMenu3)
						{
						case 1:
							oper_sumarInt(numeroA, numeroB, &resultadoSuma);
							flagSuma = 1;
							break;
						case 2:
							oper_restarInt(numeroA, numeroB, &resultadoResta);
							flagResta = 1;
							break;
						case 3:
							respuestaDivision=oper_dividir(numeroA, numeroB, &resultadoDivision);
							flagDivision = 1;
							break;
						case 4:
							oper_multiplicacionInt(numeroA, numeroB, &resultadoMultiplicacion);
							flagMultiplicacion = 1;
							break;
						case 5:
							respuestaFactorialA=oper_factorialInt(numeroA, &resultadoFactorialA);
							respuestaFactorialB=oper_factorialInt(numeroB, &resultadoFactorialB);
							flagFactorial = 1;
							break;
						}
					}
				}while(opcionMenu3 != 6);
				break;

			case 4:
				do
				{
					if(utn_getInt(&opcionMenu3, "\nSeleccione una opcion\n\n1-Mostrar Suma (A+B)\n2-Mostrar resta (A-B)\n"
												"3-Mostrar division (A/B)\n4-Mostrar multiplicacion (A*B)\n5-Mostrar factorial(A! B!)\n6-Salir\n", 1, 6, 2, "ERROR-No es una opcion valida\n")==0)
					{
						switch(opcionMenu3)
						{
						case 1:
							if(flagSuma == 1)
							{
								printf("\n\n================RESULTADO=============\n");
								printf("a)El resultado de %d + %d es: %d\n",numeroA,numeroB,resultadoSuma);
							}
							else
							{
								printf("a)No selecciono la opcion Calcular Suma\n");
							}
							break;

						case 2:
							if(flagResta == 1)
							{
								printf("\n\n================RESULTADO=============\n");
								printf("b)El resultado de %d - %d es: %d\n",numeroA,numeroB,resultadoResta);
							}
							else
							{
								printf("b)No selecciono la opcion Calcular Resta\n");
							}
							break;

						case 3:
							if(flagDivision == 1)
							{
								printf("\n\n================RESULTADO=============\n");
								if(respuestaDivision==0)
								{
									printf("c)El resultado de %d / %d es: %f\n",numeroA,numeroB,resultadoDivision);
								}
								else
								{
									printf("c)No es posible dividir por cero\n");
								}
							}
							else
							{
								printf("c)No selecciono la opcion Calcular Division\n");
							}
							break;

						case 4:
							if(flagMultiplicacion == 1)
							{
								printf("\n\n================RESULTADO=============\n");
								printf("d)El resultado de %d * %d es: %d\n",numeroA,numeroB,resultadoMultiplicacion);
							}
							else
							{
								printf("d)No selecciono la opcion Calcular Multiplicacion\n");
							}
							break;

						case 5:
							if(flagFactorial == 1)
							{
								printf("\n\n================RESULTADO=============\n");
								if(respuestaFactorialA==0)
								{
									printf("e)El factorial de %d es: %lld ",numeroA,resultadoFactorialA);
								}
								else
								{
									printf("e)No es posible calcular el factorial de %d ",numeroA);
								}

								if(respuestaFactorialB==0)
								{
									printf("y El factorial de %d es: %lld\n\n",numeroB,resultadoFactorialB);
								}
								else
								{
									printf("y no es posible calcular el factorial de %d\n\n",numeroB);
								}
							}
							else
							{
								printf("e)No selecciono la opcion Calcular Factorial\n");
							}
							break;
						}
					}
				}while(opcionMenu3 != 6);
				break;
			}
		}
	}while(opcionMenuPrincipal != 5);

	return EXIT_SUCCESS;
}
