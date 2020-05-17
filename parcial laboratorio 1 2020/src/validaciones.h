/*
 * validaciones.hh
 *
 *  Created on: 16 may. 2020
 *      Author: asato fumihito
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#define QTY_CARACTERES 51

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo);

int getFloat(	float *pResultado,
			char *pMensaje,
			char *pMensajeError,
			float minimo,
			float maximo);

int getName(    char *bName,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo);

int isSpace(char buffer[]);

char getChar(char *resultado,
			char *mensaje,
			char *mensajeError,
			char minimo,
			char maximo);


#endif /* VALIDACIONES_H_ */
