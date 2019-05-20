/*=====[UART MENU Finite State Machine]===========================================================
 * Copyright 2019 Gambarotta Martin Abel <magambarotta@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 1.0.0
 * Creation Date: 2019/04/22
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _UART_MENU_MEF_H_
#define _UART_MENU_MEF_H_

/*=====[Inclusions of public function dependencies]==========================*/
#include "../../../cese_pdm/ejercicio6/inc/motorMEF.h"
/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/


//Estructura que define los 3 posibles menus de visualizacion

typedef enum {
	MENU_PRINCIPAL, MENU_CONF_VELOCIDAD, MENU_CONF_FECHA
} uartMenu_t;

/*=====[Prototypes (declarations) of public functions]=======================*/

//Inicializacion del Menu, deja seteada la pantalla principal
void uartMenuInit(void);
//Actualizacion del Menu, se va moviendo por las diferentes pantallas y actualizando los valores en las mismas
void uartMenuUpdate(motor_t*,rtc_t*);


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _UART_MENU_MEF_H_ */
