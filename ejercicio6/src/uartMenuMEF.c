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

#include <sapi.h>
#include <uartMenuMEF.h>

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

uartMenu_t menu;
uint8_t byteingresado;

/*=====[Prototypes (declarations) of private functions]======================*/

static void clearScreen(void);
static char* itoa(int, char*, int);

/*=====[Implementations of public functions]=================================*/

void uartMenuInit(void) {
	menu = MENU_PRINCIPAL;
}

void uartMenuUpdate(void) {
	clearScreen();
	switch (menu) {
	case MENU_PRINCIPAL:
		uartWriteString(UART_USB, "				Seteado		|		Medido	\r\n");
		uartWriteString(UART_USB, "Velocidad(rpm):");

		uartWriteString(UART_USB,"					|		\r\n");
		uartWriteString(UART_USB, "Aceleracion(rpm/s):				|		\r\n");
		uartWriteString(UART_USB, "Ingrese [1] para setear Velocidad\r\n");
		uartWriteString(UART_USB, "Ingrese [2] para setear Aceleracion\r\n");
		if (uartReadByte(UART_USB, &byteingresado)) {
			switch (byteingresado) {
			case '1':
				menu = MENU_CONF_VELOCIDAD;
				break;
			case '2':
				menu = MENU_CONF_ACELERACION;
				break;
			default:
				uartWriteString(UART_USB,"Ingreso una configuración de menu incorrecta.\r\n");
				break;
			}
		}

		break;
	case MENU_CONF_VELOCIDAD:
		uartWriteString(UART_USB, "Velocidad(0-3000 rpm):\r\n");
		uartWriteString(UART_USB, "[ESC] para volver al menu principal\r\n");
		if (uartReadByte(UART_USB, &byteingresado)) {
			if (byteingresado == 27) {
				menu = MENU_PRINCIPAL;
			}
		}
		break;
	case MENU_CONF_ACELERACION:
		uartWriteString(UART_USB, "Aceleracion(0-3000 rpm):\r\n");
		uartWriteString(UART_USB, "[ESC] para volver al menu principal\r\n");
		if (uartReadByte(UART_USB, &byteingresado)) {
			if (byteingresado == 27) {
				menu = MENU_PRINCIPAL;
			}
		}
		break;
	}
}

/*=====[Implementations of interrupt functions]==============================*/
/*=====[Implementations of private functions]================================*/

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
