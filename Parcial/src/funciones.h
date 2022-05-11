/*
 * funciones.h
 *
 *  Created on: 11 may 2022
 *      Author: lufor
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



int requestDataTex(char *menInicio, char *menError, char *text, int len);
int requestDataNumFloat(char *menInicio, char *menError, float *number, int min, int max);
int requestDataNumInt(char *menInicio, char *menError, int *number, int min, int max);
char* addSpaces(char *text, int len);
int removeBarN(char *text);
int ordenarStrings(char *array);

#endif /* FUNCIONES_H_ */
