/*=====[APP]==========================================================
 * Copyright 2019 Gambarotta Martin Abel <magambarotta@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 1.0.0
 * Creation Date: 2019/04/22
 */

/*=====[Inclusions of function dependencies]=================================*/

#include <sapi.h>
#include <debounceMEF.h>
#include <motorMEF.h>
#include <uartMenuMEF.h>

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main (void)
 {
	// ----- Configurations --------------------------
	boardConfig();
	//Inicializacion UART_USB -> UART2
	uartConfig(UART_USB, 115200);
	//Inicializacion Maquina de Estado del Menu UART
	uartMenuInit();

	//Inicializacion de Delay's, 1) Para la actualizacion de los datos en el menu 2) Para el envio y recepcion de datos SPI
	delay_t delayMenu, delayDatosMotor;
	delayConfig(&delayMenu, 200);
	delayConfig(&delayDatosMotor, 1001);

	//Inicializo Motor con valores Nulos de Velocidad y Aceleracion  , se inicializa el periferico SPI  tambien
	motor_t motor;
	motorInit(&motor);

	// ----- Repeat for ever -------------------------
	while (TRUE) {
		if (delayRead(&delayMenu))uartMenuUpdate();
		if (delayRead(&delayDatosMotor))motorUpdate(&motor);
	}

	// YOU NEVER REACH HERE, because this program runs directly or on a
	// microcontroller and is not called by any Operating System, as in the
	// case of a PC program.
	return 0;
}

