#include "sapi.h"       // <= sAPI header

typedef struct {
	gpioMap_t pin;
	char pinString[5];
	uint64_t tiempoPresionado;
} boton_t;
typedef struct{
	gpioMap_t pin;
	char pinString[5];
	uint64_t tiempoEncendido;
	bool_t estado_led;
}led_t;


uint64_t tiempoPresionadoBoton(boton_t* boton) {
	uint64_t tiempoPresionado = 0;

	if (!gpioRead(boton->pin)) {
		boton->tiempoPresionado++;
	} else {
		tiempoPresionado = boton->tiempoPresionado;
		boton->tiempoPresionado = 0;
	}
	return tiempoPresionado;
}

void tiempoEncendidoLed(led_t * led, uint64_t tiempoMS) {
	if (tiempoMS > 0) {
		led->tiempoEncendido = tiempoMS;
		gpioWrite(led->pin, ON);
		led->estado_led = TRUE;
	}
	if (led->estado_led) {
		led->tiempoEncendido--;
		if (led->tiempoEncendido <= 0) {
			gpioWrite(led->pin, OFF);
			led->estado_led=FALSE;
		}
	}
}

boton_t tec1 = { .pin = TEC1, .pinString = "TIC1", .tiempoPresionado = 0 };
led_t ledB = { LEDB, "LEDB", 0, FALSE };

void funcionPeriodica(void * param ){
	uint64_t tiempoTec1=0;
	tiempoTec1=tiempoPresionadoBoton(&tec1);
	tiempoEncendidoLed(&ledB,tiempoTec1);
}

int main(void) {

	boardConfig();
	//Tick configurado en 1 MiliSeg .... en boardConfig  tickConfig(1);
	tickCallbackSet(funcionPeriodica,NULL);


	while (TRUE) {
		sleepUntilNextInterrupt();
	}
	return 0;
}
