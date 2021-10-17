/*
 ============================================================================
 Name        : TP_2.c
 Author      : Ariel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"


int main(void)
{
	setbuf(stdout,NULL);

	int options;
	Employee listEmployees[ELEMENTS];
	int id;
	int flagAlta;

	id = 0;
	flagAlta = 0;

	if(InitEmployees(listEmployees, ELEMENTS)==0)
	{
		do
		{
			puts("\n==========ABM EMPLEADOS==========\n");
			puts("1. ALTA\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n5. SALIR\n");
			if(utn_getInt(&options, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 6, 3)==0)
			{
				switch(options)
				{
					case 1:
						if(AltaEmpleado(listEmployees, ELEMENTS, &id)==0)
						{
							printf("\nALTA DE EMPLEADO EXITOSA\n");
							flagAlta = 1;
						}
						else
						{
							printf("\nALTA DE EMPLEADO CANCELADA\n");
						}
						break;

					case 2:
						if(flagAlta == 1)
						{
							if(ModificarEmpleado(listEmployees, ELEMENTS)==0)
							{
								printf("\nMODIFICACION DE EMPLEADO EXITOSA\n");
								PrintEmployees(listEmployees, ELEMENTS);
							}
							else
							{
								printf("\nMODIFICACION DE EMPLEADO CANCELADA\n");
							}
						}
						else
						{
							printf("\n¡ATENCION! NO HAY EMPLEADOS EN ALTA\n");
						}
						break;

					case 3:
						if(flagAlta == 1)
						{
							if(BajaEmpleado(listEmployees, ELEMENTS)==0)
							{
								printf("\nBAJA DE EMPLEADO EXITOSA\n");
								if(PrintEmployees(listEmployees, ELEMENTS)==-1)
								{
									flagAlta = 0;
								}

							}
							else
							{
								printf("\nBAJA DE EMPLEADO CANCELADA\n");
							}
						}
						else
						{
							printf("\n¡ATENCION! NO HAY EMPLEADOS EN ALTA\n");
						}
						break;

					case 4:
						if(flagAlta == 1)
						{
							puts("\n==========INFORMES==========\n");
							puts("1. LISTADO DE LOS EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR DE FORMA ASCENDENTE\n2. LISTADO DE LOS EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR DE FORMA DESCENDENTE"
									"\n3. TOTAL Y PROMEDIO DE LOS SALARIOS, Y CUANTOS EMPLEADOS SUPERAN EL SALARIO PROMEDIO\n");
							if(utn_getInt(&options, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 3, 3)==0)
							{
								switch(options)
								{
									case 1:
										if(SortEmployees(listEmployees, ELEMENTS, 1)==0)
										{
											PrintEmployees(listEmployees, ELEMENTS);
										}
										break;
									case 2:
										if(SortEmployees(listEmployees, ELEMENTS, 0)==0)
										{
											PrintEmployees(listEmployees, ELEMENTS);
										}
										break;
									case 3:
										InformarTotalSalarios(listEmployees, ELEMENTS);
										break;
								}
							}
						}
						else
						{
							printf("\n¡ATENCION! NO HAY EMPLEADOS EN ALTA\n");
						}
						break;

					case 5:
						puts("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
						break;
				}
			}

		}while(options != 5);
	}



	return EXIT_SUCCESS;
}
