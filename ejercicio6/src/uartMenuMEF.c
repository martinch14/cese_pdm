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
#include <motorMEF.h>
/*=====[Inclusions of private function dependencies]=========================*/
/*=====[Definition macros of private constants]==============================*/
/*=====[Private function-like macros]========================================*/
/*=====[Definitions of private data types]===================================*/
/*=====[Definitions of external public global variables]=====================*/
/*=====[Definitions of public global variables]==============================*/
/*=====[Definitions of private global variables]=============================*/
uartMenu_t menu;
uint8_t byteIngresadoMenu;
uint8_t byteIngresoVelocidad;
volatile uint16_t lectura_adc = 0;
/*=====[Prototypes (declarations) of private functions]======================*/
static void clearScreen(void);
static char* itoa(int, char*, int);
void showDateAndTime(rtc_t * rtc);

/*=====[Implementations of public functions]=================================*/

void uartMenuInit(void) {
	menu = MENU_PRINCIPAL;
}

void uartMenuUpdate(motor_t * motor, rtc_t* rtc) {
	static char uartBuff[5];
	int num;

	clearScreen();
	switch (menu) {
	case MENU_PRINCIPAL:
		//Muestra Velocidad
		uartWriteString(UART_USB, "Velocidad(rpm):		");
		itoa(motor->velocidad, uartBuff, 10); /* 10 => BASE 10 Decimal */
		uartWriteString(UART_USB, uartBuff);
		uartWriteString(UART_USB, "/");
		lectura_adc = adcRead(CH1);
		itoa(lectura_adc, uartBuff, 10);
		uartWriteString(UART_USB, uartBuff);
		uartWriteString(UART_USB, "\r\n");
		//Muestra Estado del Motor (ENCENDIDO-APAGADO)
		uartWriteString(UART_USB, "Estado Motor:		");
		if (motor->estado)
			uartWriteString(UART_USB, "APAGADO\r\n");
		else
			uartWriteString(UART_USB, "ENCENDIDO\r\n");
		//Muestra Fecha
		uartWriteString(UART_USB, "Fecha:			");
		rtcRead(rtc);
		showDateAndTime(rtc);
		uartWriteString(UART_USB, "\r\n");
		uartWriteString(UART_USB, "Ingrese [1] para setear Velocidad\r\n");
		uartWriteString(UART_USB, "Ingrese [2] para setear Fecha\r\n");
		uartWriteString(UART_USB,
				"Presione [TEC1] para  Encender|Apagar Motor\r\n");
		if (uartReadByte(UART_USB, &byteIngresadoMenu)) {
			switch (byteIngresadoMenu) {
			case '1':
				menu = MENU_CONF_VELOCIDAD;
				break;
			case '2':
				menu = MENU_CONF_FECHA;
				break;
			default:
				uartWriteString(UART_USB,
						"Ingreso una configuración de menu incorrecta.\r\n");
				break;
			}
		}

		break;
	case MENU_CONF_VELOCIDAD:
		uartWriteString(UART_USB, "[ESC] para volver al menu principal\r\n");
		uartWriteString(UART_USB, "Velocidad(0-3000 rpm): ");
		itoa(motor->velocidad, uartBuff, 10); /* 10 => BASE 10 Decimal */
		uartWriteString(UART_USB, uartBuff);
		if (uartReadByte(UART_USB, &byteIngresadoMenu)) {
			if (byteIngresadoMenu != 27 & byteIngresadoMenu != '\n') {
				motor->velocidad = byteIngresadoMenu - 48;
			}
			if (byteIngresadoMenu == 27) {
				menu = MENU_PRINCIPAL;
			}
		}
		break;

	case MENU_CONF_FECHA:
		uartWriteString(UART_USB, "[ESC] para volver al menu principal\r\n");
		uartWriteString(UART_USB, "Fecha: ");
		rtcRead(rtc);
		showDateAndTime(rtc);
		if (uartReadByte(UART_USB, &byteIngresadoMenu)) {
			if (byteIngresadoMenu == 27) {
				menu = MENU_PRINCIPAL;
			}
		}
		break;
	default:
		menu = MENU_PRINCIPAL;
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

/* Enviar fecha y hora en formato "DD/MM/YYYY, HH:MM:SS" */
void showDateAndTime(rtc_t * rtc) {
	static char uartBuff[10];
	/* Conversion de entero a ascii con base decimal */
	itoa((int) (rtc->mday), (char*) uartBuff, 10); /* 10 significa decimal */
	/* Envio el dia */
	if ((rtc->mday) < 10)
		uartWriteByte(UART_USB, '0');
	uartWriteString(UART_USB, uartBuff);
	uartWriteByte(UART_USB, '/');

	/* Conversion de entero a ascii con base decimal */
	itoa((int) (rtc->month), (char*) uartBuff, 10); /* 10 significa decimal */
	/* Envio el mes */
	if ((rtc->month) < 10)
		uartWriteByte(UART_USB, '0');
	uartWriteString(UART_USB, uartBuff);
	uartWriteByte(UART_USB, '/');

	/* Conversion de entero a ascii con base decimal */
	itoa((int) (rtc->year), (char*) uartBuff, 10); /* 10 significa decimal */
	/* Envio el año */
	if ((rtc->year) < 10)
		uartWriteByte(UART_USB, '0');
	uartWriteString(UART_USB, uartBuff);

	uartWriteString(UART_USB, ", ");

	/* Conversion de entero a ascii con base decimal */
	itoa((int) (rtc->hour), (char*) uartBuff, 10); /* 10 significa decimal */
	/* Envio la hora */
	if ((rtc->hour) < 10)
		uartWriteByte(UART_USB, '0');
	uartWriteString(UART_USB, uartBuff);
	uartWriteByte(UART_USB, ':');

	/* Conversion de entero a ascii con base decimal */
	itoa((int) (rtc->min), (char*) uartBuff, 10); /* 10 significa decimal */
	/* Envio los minutos */
	// uartBuff[2] = 0;    /* NULL */
	if ((rtc->min) < 10)
		uartWriteByte(UART_USB, '0');
	uartWriteString(UART_USB, uartBuff);
	uartWriteByte(UART_USB, ':');

	/* Conversion de entero a ascii con base decimal */
	itoa((int) (rtc->sec), (char*) uartBuff, 10); /* 10 significa decimal */
	/* Envio los segundos */
	if ((rtc->sec) < 10)
		uartWriteByte(UART_USB, '0');
	uartWriteString(UART_USB, uartBuff);

	/* Envio un 'enter' */
	uartWriteString(UART_USB, "\r\n");
}
