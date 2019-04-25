/*=====[Module Name]===========================================================
 * Copyright 2019 Gambarotta Martin Abel <magambarotta@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 1.0.0
 * Creation Date: 2019/04/22
 */
 
/*=====[Inclusion of own header]=============================================*/
#include <motorMEF.h>
/*=====[Inclusions of private function dependencies]=========================*/
/*=====[Definition macros of private constants]==============================*/
/*=====[Private function-like macros]========================================*/
/*=====[Definitions of private data types]===================================*/
/*=====[Definitions of external public global variables]=====================*/
/*=====[Definitions of public global variables]==============================*/
/*=====[Definitions of private global variables]=============================*/
/*=====[Prototypes (declarations) of private functions]======================*/
/*=====[Implementations of public functions]=================================*/
void motorInit(motor_t * motor) {
	motor->id = 0;
	motor->velocidad = 0;
	motor->velocidad_registrada = 0;
	motor->aceleracion = 0;
	motor->aceleracion_registrada = 0;
	motor->tiempo_ejecucion = 0;
	motor->estado = MOTOR_OFF;

//	spiInit(SPI0);
//	TODO Envío de parametros por defector a través de SPI
//	spiWrite(SPI0, 0x80, 1);
//	spiWrite(SPI0, 0x00000004, 4);
//	spiWrite(SPI0, 0xEC, 1);
//	spiWrite(SPI0, 0x000101D5, 4);
//	spiWrite(SPI0, 0x90, 1);
//	spiWrite(SPI0, 0x00070603, 4);
//	spiWrite(SPI0, 0x91, 1);
//	spiWrite(SPI0, 0x0000000A, 4);
//	spiWrite(SPI0, 0xF0, 1);
//	spiWrite(SPI0, 0x000401C8, 4);
//	spiWrite(SPI0, 0xA4, 1);
//	spiWrite(SPI0, 0x000003E8, 4);
//	spiWrite(SPI0, 0xA5, 1);
//	spiWrite(SPI0, 0x000186A0, 4);
//	spiWrite(SPI0, 0xA6, 1);
//	spiWrite(SPI0, 0x0000C350, 4);
//	spiWrite(SPI0, 0xA7, 1);
//	spiWrite(SPI0, 0x000186A0, 4);
//	spiWrite(SPI0, 0xAA, 1);
//	spiWrite(SPI0, 0x00000578, 4);
//	spiWrite(SPI0, 0xAB, 1);
//	spiWrite(SPI0, 0x0000000A, 4);
//	spiWrite(SPI0, 0xA0, 1);
//	spiWrite(SPI0, 0x00000000, 4);
//	spiWrite(SPI0, 0xA1, 1);
//	spiWrite(SPI0, 0x00000000, 4);
//	spiWrite(SPI0, 0xAD, 1);
//	spiWrite(SPI0, 0x00000000, 4);
}

void motorUpdate(motor_t * motor) {
//	spiWrite(SPI0, 0xAD, 1);
//	spiWrite(SPI0, 0x0007D000, 4);
}

/*=====[Implementations of interrupt functions]==============================*/
/*=====[Implementations of private functions]================================*/

