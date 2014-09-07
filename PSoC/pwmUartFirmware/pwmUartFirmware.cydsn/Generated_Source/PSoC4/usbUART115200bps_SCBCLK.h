/*******************************************************************************
* File Name: usbUART115200bps_SCBCLK.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_usbUART115200bps_SCBCLK_H)
#define CY_CLOCK_usbUART115200bps_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void usbUART115200bps_SCBCLK_Start(void);
void usbUART115200bps_SCBCLK_Stop(void);

void usbUART115200bps_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 usbUART115200bps_SCBCLK_GetDividerRegister(void);
uint8  usbUART115200bps_SCBCLK_GetFractionalDividerRegister(void);

#define usbUART115200bps_SCBCLK_Enable()                         usbUART115200bps_SCBCLK_Start()
#define usbUART115200bps_SCBCLK_Disable()                        usbUART115200bps_SCBCLK_Stop()
#define usbUART115200bps_SCBCLK_SetDividerRegister(clkDivider, reset)  \
                        usbUART115200bps_SCBCLK_SetFractionalDividerRegister((clkDivider), 0)
#define usbUART115200bps_SCBCLK_SetDivider(clkDivider)           usbUART115200bps_SCBCLK_SetDividerRegister((clkDivider), 1)
#define usbUART115200bps_SCBCLK_SetDividerValue(clkDivider)      usbUART115200bps_SCBCLK_SetDividerRegister((clkDivider) - 1, 1)


/***************************************
*             Registers
***************************************/

#define usbUART115200bps_SCBCLK_DIV_REG    (*(reg32 *)usbUART115200bps_SCBCLK__REGISTER)
#define usbUART115200bps_SCBCLK_ENABLE_REG usbUART115200bps_SCBCLK_DIV_REG

#endif /* !defined(CY_CLOCK_usbUART115200bps_SCBCLK_H) */

/* [] END OF FILE */
