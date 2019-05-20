#include "../../../cese_pdm/ejercicio3/inc/led.h"

#include "sapi.h"


void LED_parpadear(gpioMap_t led, uint16_t periodo) {
	if (periodo >= 100 && periodo <= 1000) {
		gpioToggle(led);
		delay(periodo);
	}
}

void LED_parpadear_n_veces(gpioMap_t led, uint16_t periodo, uint8_t n_veces) {
	uint8_t contador = 0;
	if (n_veces >= 1 && n_veces <= 10) {
		//contador < n_veces*2   es * 2 para que se cumpla la simetria del 50% encendido-apagado
		for (contador = 0; contador < n_veces*2; contador++) {
			if (periodo >= 100 && periodo <= 1000) {
				gpioToggle(led);
				delay(periodo);
				printf("variable contador:%d   variable periodo:%d \r\n",contador,periodo);
			}
		}
	}
}

void LED_secuencia_fija(uint16_t periodo) {
	uint8_t contador;
	if (periodo >= 100 && periodo <= 1000) {
		for (contador = 0; contador < 4; contador++) {
			switch (contador) {
			case 0:
				gpioWrite(LEDB, ON);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case 1:
				gpioWrite(LEDB, OFF);
				gpioWrite(LED1, ON);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case 2:
				gpioWrite(LEDB, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, ON);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case 3:
				gpioWrite(LEDB, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, ON);
				delay(periodo);
				break;
			default:
				break;
			}
		}
	}
}

void LED_secuencia_arbitraria(uint16_t periodo, gpioMap_t * psecuencia) {
	uint8_t contador;
	if (periodo >= 100 && periodo <= 1000) {
		for (contador = 0; contador < 4; contador++) {
			switch (psecuencia[contador]) {
			case LEDB:
				gpioWrite(LEDB, ON);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case LED1:
				gpioWrite(LEDB, OFF);
				gpioWrite(LED1, ON);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case LED2:
				gpioWrite(LEDB, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, ON);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case LED3:
				gpioWrite(LEDB, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, ON);
				delay(periodo);
				break;
			default:
				break;

			}
		}
	}
}

void LED_secuencia_arbitraria_B(uint16_t periodo, gpioMap_t* psecuencia,
		uint8_t n_leds) {
	uint8_t contador;
	if (periodo >= 100 && periodo <= 1000) {
		for (contador = 0; contador < n_leds; contador++) {
			switch (psecuencia[contador]) {
			case LEDB:
				gpioWrite(LEDB, ON);
				gpioWrite(LEDG, OFF);
				gpioWrite(LEDR, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case LED1:
				gpioWrite(LEDB, OFF);
				gpioWrite(LEDG, OFF);
				gpioWrite(LEDR, OFF);
				gpioWrite(LED1, ON);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case LED2:
				gpioWrite(LEDB, OFF);
				gpioWrite(LEDG, OFF);
				gpioWrite(LEDR, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, ON);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case LED3:
				gpioWrite(LEDB, OFF);
				gpioWrite(LEDG, OFF);
				gpioWrite(LEDR, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, ON);
				delay(periodo);
				break;
			case LEDG:
				gpioWrite(LEDB, OFF);
				gpioWrite(LEDG, ON);
				gpioWrite(LEDR, OFF);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;
			case LEDR:
				gpioWrite(LEDB, OFF);
				gpioWrite(LEDG, OFF);
				gpioWrite(LEDR, ON);
				gpioWrite(LED1, OFF);
				gpioWrite(LED2, OFF);
				gpioWrite(LED3, OFF);
				delay(periodo);
				break;

			default:
				break;

			}
		}
	}

}

