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

#include "../../../cese_pdm/ejercicio6/inc/antireboteMEF.h"
#include "../../../cese_pdm/ejercicio6/inc/motorMEF.h"
#include "../../../cese_pdm/ejercicio6/inc/uartMenuMEF.h"

/*=====[Definition macros of private constants]==============================*/
/*=====[Definitions of extern global variables]==============================*/
/*=====[Definitions of public global variables]==============================*/
/*=====[Definitions of private global variables]=============================*/
/*=====[Main function, program entry point after power on or reset]==========*/

int main (void)
 {
	// ----- Configurations --------------------------
	boardConfig();

	//Inicializacion de Delay's, 1) Para la actualizacion de los datos en el menu 2) Para el envio y recepcion de datos SPI
	delay_t delayAntirebote,delayMenu, delayDatosMotor;
	delayConfig(&delayAntirebote,10);
	delayConfig(&delayMenu, 150);
	delayConfig(&delayDatosMotor,600 );

	//Inicializacion UART_USB -> UART2
	uartConfig(UART_USB, 115200);

	//Inicializacion MEF Menu UART, configura el Menu Inicial como primer estado
	uartMenuInit();

	//Inicializacion ADC
	adcConfig(ADC_ENABLE);

	//Inicialiazacion Motor con valores Nulos de Velocidad y Aceleracion
	motor_t motor;
	motorInit(&motor);

	//Inicializacion MEF Botonera
	antireboteTecla_t tecla1;
	antireboteMEFIniciar(&tecla1, TEC1);

	//Inicializacion RTC
	rtc_t rtc;
	rtc.year = 2019;
	rtc.month = 4;
	rtc.mday = 24;
	rtc.wday = 3;
	rtc.hour = 17;
	rtc.min = 23;
	rtc.sec = 0;
	rtcInit(&rtc);

	// ----- Repeat for ever -------------------------
	while (TRUE) {

		if (delayRead(&delayMenu))uartMenuUpdate(&motor,&rtc);
		if (delayRead(&delayDatosMotor))motorUpdate(&motor);
		if (delayRead(&delayAntirebote))antireboteMEFProcesar(&tecla1,&motor);

	}

	return 0;
}

