/*=====[Nombre del modulo]=====================================================
 * Copyright 2019 Martin Abel Gambarotta <magambarotta@mail.com>
 * All rights reserved.
 * Licencia:
 * Version: 0.0.0
 * Fecha de creacion: 2019/04/04
 */
/*=====[Evitar inclusion multiple comienzo]==================================*/
#ifndef _UART_MENU_MEF_H_
#define _UART_MENU_MEF_H_

/*=====[Inclusiones de dependencias de funciones publicas]===================*/
/*=====[C++ comienzo]========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Macros de definicion de constantes publicas]=========================*/

typedef enum {
	MODO_MENU_PRINCIPAL, MODO_GPIO, MODO_ADC
} uartModoMenu_t;

/*=====[Macros estilo funcion publicas]======================================*/
/*=====[Definiciones de tipos de datos publicos]=============================*/
/*=====[Prototipos de funciones publicas]====================================*/
void uartMenuMEFIniciar(void);
void uartMenuMEFProcesar(void);
static void clearScreen(void);
static char* itoa(int value, char* result, int base);

/*=====[Prototipos de funciones publicas de interrupcion]====================*/
/*=====[C++ fin]=============================================================*/
#ifdef __cplusplus
}
#endif
/*=====[Evitar inclusion multiple fin]=======================================*/
#endif /* _UART_MENU_MEF_H_ */

