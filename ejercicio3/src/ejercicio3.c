#include "sapi.h"       // <= sAPI header
#include "led.h"


int main(void) {

	/* ------------- INICIALIZACIONES ------------- */

	/* Inicializar la placa */
	boardConfig();

	//LED_parpadear_n_veces(LED3,500,5);
	/* ------------- REPETIR POR SIEMPRE ------------- */
	gpioMap_t secuencia[] = {LED1, LED3, LED1, LED2};
	gpioMap_t secuencia2[] = {LEDG, LED2,LEDB,LED1, LED3, LED1, LED2,LEDR};

	while (TRUE) {

	//	LED_parpadear(LED2,500);
	//	LED_secuencia_fija(700);
	//	LED_secuencia_arbitraria( 500, secuencia);
	LED_secuencia_arbitraria_B( 500, secuencia2, 8);



	}
	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
	 por ningun S.O. */
	return 0;
}

/*==================[end of file]============================================*/
