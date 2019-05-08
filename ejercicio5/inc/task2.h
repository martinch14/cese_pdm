/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2018, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * Date: 2018/10/04
 *===========================================================================*/

#ifndef _TASK2_H_
#define _TASK2_H_

/*==================[inclusions]=============================================*/

#include "sapi.h"   // <= sAPI header

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/
typedef enum {
	MODO_MENU_PRINCIPAL, MODO_GPIO, MODO_ADC
} uartModoMenu_t;
/*==================[external functions declaration]=========================*/

// Funcion que inicializa la tarea
void task2_Init( void );

// Funcion que se ejecuta periodicamente
void task2_Update( void* taskParam );


void uartMenuMEFIniciar(void);
void uartMenuMEFProcesar(void);
static void clearScreen(void);
static char* itoa(int value, char* result, int base);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _TASK2_H_ */
