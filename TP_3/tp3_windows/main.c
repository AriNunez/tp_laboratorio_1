#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado.
     5. Baja de empleado.
     6. Listar empleados.
     7. Ordenar empleados.
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir.
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option;
    LinkedList* listaEmpleados;
    int flagCargaDesdeArchivo;
    int flagGuardarArchivoCSV;
    int flagGuardarArchivoBin;

    flagCargaDesdeArchivo = 0;
    flagGuardarArchivoCSV = 0;
    flagGuardarArchivoBin = 0;

    listaEmpleados = ll_newLinkedList();
    do
    {
		puts("\n==========TP3==========\n");
		puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)."
				"\n3. Alta de empleado.\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados.\n7. Ordenar empleados.\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				"\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n10. Salir.\n");
    	if(utn_getInt(&option, "\nIngrese una opcion: \n", "\n¡ERROR!\n", 1, 10, 3)==0)
    	    {
				switch(option)
				{
					case 1:
						if(flagCargaDesdeArchivo==0)
						{
							if(controller_loadFromText("data.csv",listaEmpleados)==0)
							{
								puts("\n¡ERROR EN LA CARGA DE DATOS DESDE ARCHIVO data.csv!\n");
							}
							else
							{
								puts("\n¡CARGA DE EMPLEADOS EXITOSA DESDE ARCHIVO data.csv!\n");
								flagCargaDesdeArchivo = 1;
							}
						}
						else
						{
							puts("\n¡ERROR! YA SE HAN CARGADO EMPLEADOS DESDE ARCHIVO\n");
						}
						break;

					case 2:
						if(flagCargaDesdeArchivo==0)
						{
							if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
							{
								puts("\n¡ERROR EN LA CARGA DE DATOS DESDE ARCHIVO data.bin!\n");
							}
							else
							{
								puts("\n¡CARGA DE EMPLEADOS EXITOSA DESDE ARCHIVO data.bin!\n");
								flagCargaDesdeArchivo = 1;
							}
						}
						else
						{
							puts("\n¡ERROR! YA SE HAN CARGADO EMPLEADOS DESDE ARCHIVO\n");
						}
						break;

					case 3:
						if(flagCargaDesdeArchivo==1)
						{
							if(controller_addEmployee(listaEmpleados)==0)
							{
								printf("\nALTA DE EMPLEADO CANCELADA\n");
							}
							else
							{
								printf("\nALTA DE EMPLEADO EXITOSA\n");
								if(flagGuardarArchivoBin==1||flagGuardarArchivoCSV==1)
								{
									flagGuardarArchivoCSV=0;
									flagGuardarArchivoBin=0;
								}
							}
						}
						else
						{
							puts("\n¡ERROR! ES NECESARIO EJECUTAR LA OPCION 1 o 2 PARA PODER REALIZAR ESTA ACCION\n");
						}
						break;

					case 4:
						if(flagCargaDesdeArchivo==1)
						{
							if(controller_editEmployee(listaEmpleados)==0)
							{
								puts("\nMODIFICACION DE EMPLEADO CANCELADA\n");
							}
							else
							{
								puts("\nMODIFICACION DE EMPLEADO EXITOSA\n");
								if(flagGuardarArchivoBin==1||flagGuardarArchivoCSV==1)
								{
									flagGuardarArchivoCSV=0;
									flagGuardarArchivoBin=0;
								}
							}
						}
						else
						{
							puts("\n¡ERROR! ES NECESARIO EJECUTAR LA OPCION 1 o 2 PARA PODER REALIZAR ESTA ACCION\n");
						}
						break;

					case 5:
						if(flagCargaDesdeArchivo==1)
						{
							if(controller_removeEmployee(listaEmpleados)==0)
							{
								puts("\nBAJA DE EMPLEADO CANCELADA\n");
							}
							else
							{
								puts("\nBAJA DE EMPLEADO EXITOSA\n");
								if(flagGuardarArchivoBin==1||flagGuardarArchivoCSV==1)
								{
									flagGuardarArchivoCSV=0;
									flagGuardarArchivoBin=0;
								}
							}
						}
						else
						{
							puts("\n¡ERROR! ES NECESARIO EJECUTAR LA OPCION 1 o 2 PARA PODER REALIZAR ESTA ACCION\n");
						}
						break;

					case 6:
						if(flagCargaDesdeArchivo==1)
						{
							controller_ListEmployee(listaEmpleados);
						}
						else
						{
							puts("\n¡ERROR! ES NECESARIO EJECUTAR LA OPCION 1 o 2 PARA PODER REALIZAR ESTA ACCION\n");
						}
						break;

					case 7:
						if(flagCargaDesdeArchivo==1)
						{
							if(controller_sortEmployee(listaEmpleados)==0)
							{
								puts("\n¡ORDENAMIENTO ERRONEO!\n");
							}
							else
							{
								puts("\n¡ORDENAMIENTO EXITOSO!\n");
							}
						}
						else
						{
							puts("\n¡ERROR! ES NECESARIO EJECUTAR LA OPCION 1 o 2 PARA PODER REALIZAR ESTA ACCION\n");
						}
						break;

					case 8:
						if(flagCargaDesdeArchivo==1)
						{
							ll_sort(listaEmpleados, employee_CompareById, 1);
							if(controller_saveAsText("data.csv", listaEmpleados)==0)
							{
								puts("\n¡ERROR AL GUARDAR EMPLEADOS EN ARCHIVO dataAux.csv!\n");
							}
							else
							{
								flagGuardarArchivoCSV = 1;
								puts("\n¡GUARDADO DE EMPLEADOS EXITOSA EN ARCHIVO dataAux.csv!\n");
							}
						}
						else
						{
							puts("\n¡ERROR! ES NECESARIO EJECUTAR LA OPCION 1 o 2 PARA PODER REALIZAR ESTA ACCION\n");
						}
						break;

					case 9:
						if(flagCargaDesdeArchivo==1)
						{
							ll_sort(listaEmpleados, employee_CompareById, 1);
							if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
							{
								puts("\n¡ERROR AL GUARDAR EMPLEADOS EN ARCHIVO dataAux.bin!\n");
							}
							else
							{
								flagGuardarArchivoBin = 1;
								puts("\n¡GUARDADO DE EMPLEADOS EXITOSA EN ARCHIVO dataAux.bin!\n");
							}
						}
						else
						{
							puts("\n¡ERROR! ES NECESARIO EJECUTAR LA OPCION 1 o 2 PARA PODER REALIZAR ESTA ACCION\n");
						}
						break;

					case 10:
						if(flagGuardarArchivoBin==1 && flagGuardarArchivoCSV==1)
						{
							ll_deleteLinkedList(listaEmpleados);
							puts("\n¡GRACIAS POR UTILIZAR NUESTROS SERVICIOS!\n");
						}
						else
						{
							puts("\n¡ERROR! ES NECASARIO GUARDAR EN MODO TEXTO Y BINARIO PARA SALIR DEL PROGRAMA\n");
							option = 0;
						}
						break;
				}
    	    }

    }while(option != 10);
    return EXIT_SUCCESS;
}

