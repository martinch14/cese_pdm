#include"sapi.h"

void LED_parpadear (gpioMap_t led, uint16_t periodo );
void LED_parpadear_n_veces(gpioMap_t led ,uint16_t periodo, uint8_t n_veces);
void LED_secuencia_fija( uint16_t periodo );
void LED_secuencia_arbitraria( uint16_t periodo, gpioMap_t * psecuencia);
void LED_secuencia_arbitraria_B( uint16_t periodo, gpioMap_t* psecuencia,
                                                    uint8_t n_leds);



