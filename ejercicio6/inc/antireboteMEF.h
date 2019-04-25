/*=====[Nombre del modulo]=====================================================
 * Copyright 2019 Martin Abel Gambarotta <magambarotta@mail.com>
 * All rights reserved.
 * Licencia:
 * Version: 0.0.0
 * Fecha de creacion: 2019/04/04
 */
/*=====[Evitar inclusion multiple comienzo]==================================*/
#ifndef _ANTIREBOTE_MEF_H_
#define _ANTIREBOTE_MEF_H_

/*=====[Inclusiones de dependencias de funciones publicas]===================*/
#include <motorMEF.h>
/*=====[C++ comienzo]========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Macros de definicion de constantes publicas]=========================*/
/*=====[Macros estilo funcion publicas]======================================*/
/*=====[Definiciones de tipos de datos publicos]=============================*/
typedef enum {
	TECLA_PRESIONANDO, TECLA_SUELTA, TECLA_APRETADA, TECLA_SOLTANDO
} antireboteEstadoTecla_t;
typedef struct {
	gpioMap_t tecla;
	antireboteEstadoTecla_t estado;
	delay_t delay;
} antireboteTecla_t;

/*=====[Prototipos de funciones publicas]====================================*/

//
void antireboteMEFIniciar(antireboteTecla_t* p_antirebote_estructura,
		gpioMap_t tecla);

//
void antireboteMEFProcesar(antireboteTecla_t* p_antirebote_estructura, motor_t* motor);

/*=====[Prototipos de funciones publicas de interrupcion]====================*/
/*=====[C++ fin]=============================================================*/
#ifdef __cplusplus
}
#endif
/*=====[Evitar inclusion multiple fin]=======================================*/
#endif /* _ANTIREBOTE_MEF_H_ */
