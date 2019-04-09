/*==================[inclusions]=============================================*/

#include "sapi.h"       // <= sAPI header

int main(void) {

	/* ------------- INICIALIZACIONES ------------- */

	/* Inicializar la placa */
	boardConfig();

	/*Variable para retardo NO Bloqueante*/
	delay_t delay_led, delay_rebote_tecla;

	/*Agrego también un delay de 200 ms  antirebote para las teclas 2 y 3*/

	delayConfig(&delay_led, 500);
	delayConfig(&delay_rebote_tecla, 200);


	/*Variable para ajuste de sentido, 0) -->>    1) <<-- */
	uint8_t sentido = 0;
	int8_t i = 0;

	/* ------------- REPETIR POR SIEMPRE ------------- */
	while (TRUE) {

		/*Uso TEC2 para <<--    y TEC3 -->> */
		if (!gpioRead(TEC2)) {
			if (delayRead(&delay_rebote_tecla))
				sentido = 1;
		}

		if (!gpioRead(TEC3)) {
			if (delayRead(&delay_rebote_tecla))
				sentido = 0;
		}

		if (delayRead(&delay_led)) {
			if (!sentido) {
				i++;
			} else {
				i--;
			}
		}
		switch (i) {
		case 0:
			gpioWrite(LEDB, ON);
			gpioWrite(LED1, OFF);
			gpioWrite(LED2, OFF);
			gpioWrite(LED3, OFF);
			break;
		case 1:

			gpioWrite(LEDB, OFF);
			gpioWrite(LED1, ON);
			gpioWrite(LED2, OFF);
			gpioWrite(LED3, OFF);
			break;
		case 2:
			gpioWrite(LEDB, OFF);
			gpioWrite(LED1, OFF);
			gpioWrite(LED2, ON);
			gpioWrite(LED3, OFF);
			break;

		case 3:
			gpioWrite(LEDB, OFF);
			gpioWrite(LED1, OFF);
			gpioWrite(LED2, OFF);
			gpioWrite(LED3, ON);
			break;
		default:
			if (i < 0) {
				i = 3;
			}
			if (i > 3) {
				i = 0;
			}
			break;

		}

	}
	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	 por ningun S.O. */
	return 0;
}

/*==================[end of file]============================================*/
