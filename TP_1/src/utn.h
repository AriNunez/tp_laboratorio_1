/*
 * utn.h
 *
 *  Created on: 2 sep. 2021
 *      Author: user
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int utn_getIntSinLimite(int* pResultado,char* mensaje,char* mensajeError,int reintentos);

int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

#endif /* UTN_H_ */
