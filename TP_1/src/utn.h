/*
 * utn.h
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#ifndef UTN_H_
#define UTN_H_

//--------------------ENTEROS--------------------
int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

//--------------------FLOTANTES--------------------
int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getFloatSinLimite(float* pResultado,char* mensaje,char* mensajeError,int reintentos);

#endif /* UTN_H_ */
