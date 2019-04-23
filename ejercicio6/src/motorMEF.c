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

// Data type that renames an elementary data type
// Function pointer data type
// Enumerated data type
// Structured, union or bit field data type

/*=====[Definitions of external public global variables]=====================*/
/*=====[Definitions of public global variables]==============================*/
/*=====[Definitions of private global variables]=============================*/
/*=====[Prototypes (declarations) of private functions]======================*/
void motorInit(motor_t *);
void motorUpdate(motor_t *);
/*=====[Implementations of public functions]=================================*/
void motorInit(motor_t * motor){
motor->id=0;
motor->velocidad=0;
motor->aceleracion=0;
motor->estado=MOTOR_OFF;

spiInit(SPI0);

}
void motorUpdate(motor_t * motor){
	uint8_t buffer=10;
	uint32_t buffer_size=8;
	spiWrite(SPI0,&buffer,buffer_size);

}

/*=====[Implementations of interrupt functions]==============================*/
/*=====[Implementations of private functions]================================*/

