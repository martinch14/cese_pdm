/*=====[Nombre del programa]===================================================
 * Copyright 2019 Martin Abel Gambarotta <magambarotta@gmail.com>
 * All rights reserved.
 * Licencia:
 * Version: 0.0.0
 * Fecha de creacion: 2019/04/03
 */

/*=====[Inclusiones de dependencias de funciones]============================*/
#include "sapi.h"

#include "../../../cese_pdm/ejercicio6/inc/antireboteMEF.h"
#include "../../../cese_pdm/ejercicio6/inc/uartMenuMEF.h"

/*=====[Macros de definición de constantes privadas]=========================*/
/*=====[Definiciones de variables globales externas]=========================*/
/*=====[Definiciones de variables globales publicas]=========================*/
/*=====[Definiciones de variables globales privadas]=========================*/
/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

antireboteTecla_t tecla1, tecla2, tecla3, tecla4;

int main(void) {
	//Inicializacion Board EDU-CIAA
	boardConfig();
	//Inicializacion UART_USB -> UART2
	uartConfig(UART_USB, 115200);
	//Inicializacion ADC
	adcConfig(ADC_ENABLE);

	//Inicializacion MEF Menu
	uartMenuMEFIniciar();
	delay(2000);
	//Inicializacion MEF Botonera
	antireboteMEFIniciar(&tecla1, TEC1);
	antireboteMEFIniciar(&tecla2, TEC2);
	antireboteMEFIniciar(&tecla3, TEC3);
	antireboteMEFIniciar(&tecla4, TEC4);

	tick_t tick_menu = 0;

	while (TRUE) {

		//Imprime el menu y procesa que dato es ingresado.
		tick_menu = tickRead();
		if (tick_menu >= 200) {
			uartMenuMEFProcesar();
			tickWrite(0);
		}

		//Pasa por todas las teclas para ver si alguna es apretada.
		antireboteMEFProcesar(&tecla1);
		antireboteMEFProcesar(&tecla2);
		antireboteMEFProcesar(&tecla3);
		antireboteMEFProcesar(&tecla4);

	}

	return 0;
}
