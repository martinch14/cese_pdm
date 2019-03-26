/*==================[inclusions]=============================================*/

#include "sapi.h"       // <= sAPI header

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void) {

	/* ------------- INICIALIZACIONES ------------- */

	/* Inicializar la placa */
	boardConfig();

	uint32_t tiempo_boton_presionado_4 = 0, tiempo_boton_presionado_3 = 0,
			tiempo_boton_presionado_2 = 0, tiempo_boton_presionado_1 = 0;

	/* ------------- REPETIR POR SIEMPRE ------------- */
	while (TRUE) {
		/*Configuración para TEC4*/
		while (!gpioRead(TEC4)) {
			delay(1);
			tiempo_boton_presionado_4++;
		}
		gpioWrite(LED3, OFF);
		if (tiempo_boton_presionado_4 > 0) {
			gpioWrite(LED3, ON);
			delay(tiempo_boton_presionado_4);
			tiempo_boton_presionado_4 = 0;
		}

		/*Configuración para TEC3*/
		while (!gpioRead(TEC3)) {
			delay(1);
			tiempo_boton_presionado_3++;
		}
		gpioWrite(LED2, OFF);
		if (tiempo_boton_presionado_3 > 0) {
			gpioWrite(LED2, ON);
			delay(tiempo_boton_presionado_3);
			tiempo_boton_presionado_3 = 0;
		}

		/*Configuración para TEC2*/
		while (!gpioRead(TEC2)) {
			delay(1);
			tiempo_boton_presionado_2++;
		}
		gpioWrite(LED1, OFF);
		if (tiempo_boton_presionado_2 > 0) {
			gpioWrite(LED1, ON);
			delay(tiempo_boton_presionado_2);
			tiempo_boton_presionado_2 = 0;
		}

		/*Configuración para TEC1*/
		while (!gpioRead(TEC1)) {
			delay(1);
			tiempo_boton_presionado_1++;
		}
		gpioWrite(LEDB, OFF);
		if (tiempo_boton_presionado_1 > 0) {
			gpioWrite(LEDB, ON);
			delay(tiempo_boton_presionado_1);
			tiempo_boton_presionado_1 = 0;
		}

	}
	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	 por ningun S.O. */
	return 0;
}

/*==================[end of file]============================================*/
