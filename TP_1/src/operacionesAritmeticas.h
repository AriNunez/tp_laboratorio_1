/*
 * operacionesAritmeticas.h
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#ifndef OPERACIONESARITMETICAS_H_
#define OPERACIONESARITMETICAS_H_

/**FLOTANTES**/
int oper_DividirFloat(float numeroA, float numeroB,float *pResultado);
int oper_SumarFloat(float numeroA, float numeroB, float *pResultado);
int oper_RestarFloat(float numeroA, float numeroB, float *pResultado);
int oper_MultiplicacionFloat(float numeroA, float numeroB, double *pResultado);
double oper_FactorialFloat(float numeroIngresado);

/**VERIFICACIONES**/
int VerificarNumeroEntero(float numeroIngresado);

#endif /* OPERACIONESARITMETICAS_H_ */
