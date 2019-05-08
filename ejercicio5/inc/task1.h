/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2018, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * Date: 2018/10/04
 *===========================================================================*/

#ifndef _TASK1_H_
#define _TASK1_H_

/*==================[inclusions]=============================================*/

#include "sapi.h"   // <= sAPI header

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
/*=====[Macros de definicion de constantes publicas]=========================*/

typedef enum {
	TECLA_PRESIONANDO, TECLA_SUELTA, TECLA_APRETADA, TECLA_SOLTANDO
} antireboteEstadoTecla_t;
typedef struct {
	gpioMap_t tecla;
	antireboteEstadoTecla_t estado;
	delay_t delay;
} antireboteTecla_t;

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

// Funcion que inicializa la tarea
void task1_Init( void );

// Funcion que se ejecuta periodicamente
void task1_Update( void* taskParam );
void antireboteMEFIniciar(antireboteTecla_t* p_antirebote_estructura,
		gpioMap_t tecla);
void antireboteMEFProcesar(antireboteTecla_t* p_antirebote_estructura);

void botonPresionado(gpioMap_t tecla);
void botonSoltado(gpioMap_t tecla) ;


/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _TASK1_H_ */
