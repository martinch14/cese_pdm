/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2018, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * Date: 2018/10/04
 *===========================================================================*/

/*==================[inclusions]=============================================*/

#include "../../../cese_pdm/ejercicio5/inc/task1.h"  // <= own header

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/


/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
#define TIEMPO_ANTIREBOTE 40

antireboteTecla_t tecla1, tecla2, tecla3, tecla4;

// Funcion que inicializa la tarea
void task1_Init( void ){
	antireboteMEFIniciar(&tecla1, TEC1);
	antireboteMEFIniciar(&tecla2, TEC2);
	antireboteMEFIniciar(&tecla3, TEC3);
	antireboteMEFIniciar(&tecla4, TEC4);


}

// Funcion que se ejecuta periodicamente
void task1_Update( void* taskParam ){
	antireboteMEFProcesar(&tecla1);
	antireboteMEFProcesar(&tecla2);
	antireboteMEFProcesar(&tecla3);
	antireboteMEFProcesar(&tecla4);

}
void antireboteMEFIniciar(antireboteTecla_t* p_antirebote_estructura,
		gpioMap_t tecla) {
	p_antirebote_estructura->tecla = tecla;
	p_antirebote_estructura->estado = TECLA_SUELTA;
	return;
}

void antireboteMEFProcesar(antireboteTecla_t* p_antirebote_estructura) {
	switch (p_antirebote_estructura->estado) {
	case TECLA_SUELTA:
		if (!gpioRead(p_antirebote_estructura->tecla)) {
			p_antirebote_estructura->estado = TECLA_PRESIONANDO;
		} else {
			p_antirebote_estructura->estado = TECLA_SUELTA;
		}
		break;
	case TECLA_PRESIONANDO:
		if (!p_antirebote_estructura->delay.running) {
			delayConfig(&p_antirebote_estructura->delay, TIEMPO_ANTIREBOTE);
			delayRead(&p_antirebote_estructura->delay);
		}
		if (delayRead(&p_antirebote_estructura->delay)) {
			if (!gpioRead(p_antirebote_estructura->tecla)) {
				botonPresionado(p_antirebote_estructura->tecla);
				p_antirebote_estructura->estado = TECLA_APRETADA;
			}
		} else {
			p_antirebote_estructura->estado = TECLA_SUELTA;
		}
		break;
	case TECLA_APRETADA:
		if (!gpioRead(p_antirebote_estructura->tecla)) {
			p_antirebote_estructura->estado = TECLA_APRETADA;
		} else {
			p_antirebote_estructura->estado = TECLA_SOLTANDO;
		}
		break;
	case TECLA_SOLTANDO:
		if (!p_antirebote_estructura->delay.running) {
			delayConfig(&p_antirebote_estructura->delay, TIEMPO_ANTIREBOTE);
			delayRead(&p_antirebote_estructura->delay);
		}
		if (delayRead(&p_antirebote_estructura->delay)) {
			if (gpioRead(p_antirebote_estructura->tecla)) {
				botonSoltado(p_antirebote_estructura->tecla);
				p_antirebote_estructura->estado = TECLA_SUELTA;
			}
		} else {
			p_antirebote_estructura->estado = TECLA_APRETADA;
		}
		break;
	default:
		p_antirebote_estructura->estado = TECLA_SUELTA;

	}
	return;
}

void botonPresionado(gpioMap_t tecla) {
	gpioWrite(LEDB, ON);
	return;
}
void botonSoltado(gpioMap_t tecla) {
	gpioWrite(LEDB, OFF);
	return;
}


/*==================[end of file]============================================*/
