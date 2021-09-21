/*
 * operacionesAritmeticas.h
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#ifndef OPERACIONESARITMETICAS_H_
#define OPERACIONESARITMETICAS_H_

int oper_DividirInt(int numeroA, int numeroB,float *pResultado);
int oper_SumarInt(int numeroA, int numeroB, long *pResultado);
int oper_RestarInt(int numeroA, int numeroB, long *pResultado);
int oper_MultiplicacionInt(int numeroA, int numeroB, long *pResultado);
int oper_FactorialInt(int numero,unsigned long* pResultado);
unsigned long long CalcularFactorial(int numeroIngresado);

#endif /* OPERACIONESARITMETICAS_H_ */
