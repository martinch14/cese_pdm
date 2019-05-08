/*=====[Nombre del modulo]=====================================================
 * Copyright 2019 Martin Abel Gambarotta <magambarotta@mail.com>
 * All rights reserved.
 * Licencia:
 * Version: 0.0.0
 * Fecha de creacion: 2019/04/03
 */

/*=====[Inclusion de su propia cabecera]=====================================*/
#include <sapi.h>
#include <antireboteMEF.h>
#include <motorMEF.h>

/*=====[Macros de definicion de constantes privadas]=========================*/
/*=====[Macros estilo funcion privadas]======================================*/
#define TIEMPO_ANTIREBOTE 40
/*=====[Definiciones de tipos de datos privados]=============================*/
/*=====[Definiciones de Variables globales publicas externas]================*/
/*=====[Definiciones de Variables globales publicas]=========================*/
/*=====[Definiciones de Variables globales privadas]=========================*/
/*=====[Prototipos de funciones privadas]====================================*/
void EncenderLedTec(gpioMap_t tecla);
void ApagarLedTec(gpioMap_t tecla);

/*=====[Implementaciones de funciones publicas]==============================*/
void antireboteMEFIniciar(antireboteTecla_t* p_antirebote_estructura,
		gpioMap_t tecla) {
	p_antirebote_estructura->tecla = tecla;
	antireboteEstadoTecla_t TECLA_SUELTA;
	p_antirebote_estructura->estado = TECLA_SUELTA;
	return;
}

void antireboteMEFProcesar(antireboteTecla_t* p_antirebote_estructura,motor_t * motor) {
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
				EncenderLedTec(p_antirebote_estructura->tecla);
				if (motor->estado)motor->estado=0;
				else if (motor->estado == 0)motor->estado=1;
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
				ApagarLedTec(p_antirebote_estructura->tecla);
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

/*=====[Implementaciones de funciones de interrupcion publicas]==============*/
/*=====[Implementaciones de funciones privadas]==============================*/
void EncenderLedTec(gpioMap_t tecla) {
	if (tecla == TEC1)gpioWrite(LEDG, ON);
	return;
}
void ApagarLedTec(gpioMap_t tecla) {
	if (tecla == TEC1)gpioWrite(LEDG, OFF);
	return;
}

