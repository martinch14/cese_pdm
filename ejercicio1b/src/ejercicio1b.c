/*==================[inclusions]=============================================*/

#include "sapi.h"       // <= sAPI header

#define SENTIDO_DERECHO 	1
#define SENTIDO_IZQUIERDO 	-1

int main(void) {

	/* ------------- INICIALIZACIONES ------------- */

	/* Inicializar la placa */
	boardConfig();

	/* */
	/*Variable para ajuste de sentido, 0) -->>    1) <<-- */

	int8_t sentido = SENTIDO_DERECHO;
	uint32_t led=LEDB;
	delay_t delaySecuencia;


	delayConfig (&delaySecuencia,500);

	/* ------------- REPETIR POR SIEMPRE ------------- */
	while (TRUE) {

		/*Uso TEC2 para <<--    y TEC3 -->> */
		if (!gpioRead(TEC2)) {
				sentido = -1;
		}

		if (!gpioRead(TEC3)) {
				sentido = 1;
		}

		gpioWrite(led,ON);
		if(delayRead(&delaySecuencia)){
		gpioWrite(led,OFF);
		led+=sentido;
		//Chequeo de condiciones de borde
		if(led<LEDB){led=LED3;}
		if(led>LED3){led=LEDB;}
		}


	}
	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	 por ningun S.O. */
	return 0;
}

/*==================[end of file]============================================*/
