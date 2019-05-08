/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2018, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * Date: 2018/10/04
 *===========================================================================*/

/*==================[inclusions]=============================================*/

#include "../../ejercicio5/inc/task2.h"  // <= own header
#include "../../ejercicio5/inc/task1.h"  // <= own header
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/


/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

uartModoMenu_t menu;
uint8_t byteingresado;
extern antireboteTecla_t tecla1, tecla2, tecla3, tecla4;
/*==================[external functions definition]==========================*/




// Funcion que inicializa la tarea
void task2_Init( void ){
	//Inicializacion UART_USB -> UART2
	uartConfig(UART_USB, 115200);
	//Inicializacion ADC
	adcConfig(ADC_ENABLE);

}

// Funcion que se ejecuta periodicamente
void task2_Update( void* taskParam ){
	uartMenuMEFProcesar();
}

void uartMenuMEFIniciar(void) {
	uartWriteString(UART_USB, "Bienvenido al Menu  MEF UART\r\n");
	menu = MODO_MENU_PRINCIPAL;
}
void uartMenuMEFProcesar(void) {
	uint16_t lectura_adc = 0;
	static char uartBuff[10];

	clearScreen();
	switch (menu) {
	case MODO_MENU_PRINCIPAL:
		uartWriteString(UART_USB, "Configuración:\r\n");
		uartWriteString(UART_USB,
				"Ingrese [1] si desea acceder al modo GPIO's\r\n");
		uartWriteString(UART_USB,
				"Ingrese [2] si desea acceder al modo ADC\r\n");

		if (uartReadByte(UART_USB, &byteingresado)) {
			switch (byteingresado) {
			case '1':
				menu = MODO_GPIO;
				break;
			case '2':
				menu = MODO_ADC;
				break;
			default:
				uartWriteString(UART_USB,
						"Ingreso una configuración de menu incorrecta.\r\n");
				break;
			}
		}

		break;
	case MODO_GPIO:
		uartWriteString(UART_USB, "MODO GPIO:\r\n");
		uartWriteString(UART_USB, "Estado Tec1: ");
		if (tecla1.estado == TECLA_SUELTA)
			uartWriteString(UART_USB, "SUELTA\r\n");
		else if (tecla1.estado == TECLA_APRETADA)
			uartWriteString(UART_USB, "APRETADA\r\n");
		uartWriteString(UART_USB, "Estado Tec2: ");
		if (tecla2.estado == TECLA_SUELTA)
			uartWriteString(UART_USB, "SUELTA\r\n");
		else if (tecla2.estado == TECLA_APRETADA)
			uartWriteString(UART_USB, "APRETADA\r\n");
		uartWriteString(UART_USB, "Estado Tec3: ");
		if (tecla3.estado == TECLA_SUELTA)
			uartWriteString(UART_USB, "SUELTA\r\n");
		else if (tecla3.estado == TECLA_APRETADA)
			uartWriteString(UART_USB, "APRETADA\r\n");
		uartWriteString(UART_USB, "Estado Tec4: ");
		if (tecla4.estado == TECLA_SUELTA)
			uartWriteString(UART_USB, "SUELTA\r\n");
		else if (tecla4.estado == TECLA_APRETADA)
			uartWriteString(UART_USB, "APRETADA\r\n");

		uartWriteString(UART_USB, "[ESC] para volver al menu principal\r\n");

		if (uartReadByte(UART_USB, &byteingresado)) {
			if (byteingresado == 27) {
				menu = MODO_MENU_PRINCIPAL;
			}
		}
		break;
	case MODO_ADC:
		uartWriteString(UART_USB, "MODO ADC\r\n");
		lectura_adc = adcRead(CH1);
		itoa(lectura_adc, uartBuff, 10);
		uartWriteString(UART_USB, "Lectura Sensor: ");
		uartWriteString(UART_USB, uartBuff);
		uartWriteString(UART_USB, "\r\n");
		uartWriteString(UART_USB, "[ESC] para volver al menu principal\r\n");
		if (uartReadByte(UART_USB, &byteingresado)) {
			if (byteingresado == 27) {
				menu = MODO_MENU_PRINCIPAL;
			}
		}

		break;
	default:
		break;
	}
}

static void clearScreen(void) {
	uartWriteByte(UART_USB, 27);
	uartWriteString(UART_USB, "[2J");
	uartWriteByte(UART_USB, 27);
	uartWriteString(UART_USB, "[H");
	delay(1);
}

static char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) {
		*result = '\0';
		return result;
	}

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ =
				"zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35
						+ (tmp_value - value * base)];
	} while (value);

	// Apply negative sign
	if (tmp_value < 0)
		*ptr++ = '-';
	*ptr-- = '\0';
	while (ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}


/*==================[end of file]============================================*/
