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

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
typedef enum {
	MENU_PRINCIPAL, MENU_CONF_VELOCIDAD, MENU_CONF_ACELERACION
} uartMenu_t;

/*=====[Prototypes (declarations) of public functions]=======================*/
void uartMenuInit(void);
void uartMenuUpdate(void);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _UART_MENU_MEF_H_ */
