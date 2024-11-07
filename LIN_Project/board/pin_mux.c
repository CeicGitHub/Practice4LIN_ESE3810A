/*This file contain the PINS and Clocks*/
#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"


#define PIN14_IDX                       14u   /*!< Pin number for pin 14 in a port */
#define PIN15_IDX                       15u   /*!< Pin number for pin 15 in a port */
#define PIN16_IDX                       16u   /*!< Pin number for pin 16 in a port */
#define PIN17_IDX                       17u   /*!< Pin number for pin 17 in a port */
#define SOPT5_UART0TXSRC_UART_TX      0x00u   /*!< UART 0 transmit data source select: UART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '62', peripheral: UART0, signal: RX, pin_signal: PTB16/SPI1_SOUT/UART0_RX/FTM_CLKIN0/FB_AD17/EWM_IN}
  - {pin_num: '63', peripheral: UART0, signal: TX, pin_signal: PTB17/SPI1_SIN/UART0_TX/FTM_CLKIN1/FB_AD16/EWM_OUT_b}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {

  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTB, PIN16_IDX, kPORT_MuxAlt3);           /* PORTB16 (pin 62) is configured as UART0_RX */
  PORT_SetPinMux(PORTB, PIN17_IDX, kPORT_MuxAlt3);           /* PORTB17 (pin 63) is configured as UART0_TX */

  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_UART0TXSRC_MASK)))                          /* Mask bits to zero which are setting */
      | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX)       /* UART 0 transmit data source select: UART0_TX pin */
    );

  /*UART 3 pins_config*/
  PORT_SetPinMux(PORTC, PIN16_IDX, kPORT_MuxAlt3);           /* PORTB14 (pin 90) is configured as UART3_RX */
  PORT_SetPinMux(PORTC, PIN17_IDX, kPORT_MuxAlt3);           /* PORTB15 (pin 91) is configured as UART3_TX */

  /*UART 4 pins_config*/
  PORT_SetPinMux(PORTC, PIN14_IDX, kPORT_MuxAlt3);           /* PORTB16 (pin 86) is configured as UART4_RX */
  PORT_SetPinMux(PORTC, PIN15_IDX, kPORT_MuxAlt3);           /* PORTB17 (pin 87) is configured as UART4_TX */

  //Led_Pins
  PORT_SetPinMux(PORTB, 22U, kPORT_MuxAsGpio);				 /* PORTB22 (pin 68) is configured as PTB22 */
  PORT_SetPinMux(PORTB, 21U, kPORT_MuxAsGpio);				 /* PORTB21 (pin 71) is configured as PTB21 */
  PORT_SetPinMux(PORTE, 26U, kPORT_MuxAsGpio);				 /* PORTE26 (pin 73) is configured as PTE26 */

}

/*******************************************************************************
 * EOF
 ******************************************************************************/
