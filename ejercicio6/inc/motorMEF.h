/*=====[Module Name]===========================================================
 * Copyright 2019 Gambarotta Martin Abel <mgambarotta@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Creation Date: 2019/04/22
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _MOTOR_MEF_H_
#define _MOTOR_MEF_H_

#include<sapi.h>     /////SI NO LO PONGO NO CONOCE LOS TIPOS unit16_t Y NO COMPILA Preguntar??????

/*=====[Inclusions of public function dependencies]==========================*/
/*=====[C++ - begin]=========================================================*/
#ifdef __cplusplus
extern "C" {
#endif
/*=====[Definition macros of public constants]===============================*/
/*=====[Public function-like macros]=========================================*/
/*=====[Definitions of public data types]====================================*/

typedef enum {
	MOTOR_ON, MOTOR_OFF
} estadoMotor_t;

typedef struct {
	uint8_t id;
	uint16_t velocidad;
	uint16_t velocidad_registrada;
	uint16_t aceleracion;
	uint16_t aceleracion_registrada;
	uint16_t tiempo_ejecucion;
	estadoMotor_t estado;
} motor_t;

/*=====[Prototypes (declarations) of public functions]=======================*/

void motorInit(motor_t *);		//Inicializacion del motor con valores de velocidad y aceleracion 0
void motorUpdate(motor_t *);   	//Envía y Recibe un datagrama con la configuracion actual del motor y lectura de sensores

/*=====[Prototypes (declarations) of public interrupt functions]=============*/
/*=====[C++ - end]===========================================================*/
#ifdef __cplusplus
}
#endif
/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _MOTOR_MEF_H_ */
