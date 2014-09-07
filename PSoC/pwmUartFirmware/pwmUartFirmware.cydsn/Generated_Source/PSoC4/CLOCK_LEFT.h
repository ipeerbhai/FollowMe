/*******************************************************************************
* File Name: CLOCK_LEFT.h
* Version 2.10
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

#if !defined(CY_CLOCK_CLOCK_LEFT_H)
#define CY_CLOCK_CLOCK_LEFT_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void CLOCK_LEFT_Start(void);
void CLOCK_LEFT_Stop(void);

void CLOCK_LEFT_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CLOCK_LEFT_GetDividerRegister(void);
uint8  CLOCK_LEFT_GetFractionalDividerRegister(void);

#define CLOCK_LEFT_Enable()                         CLOCK_LEFT_Start()
#define CLOCK_LEFT_Disable()                        CLOCK_LEFT_Stop()
#define CLOCK_LEFT_SetDividerRegister(clkDivider, reset)  \
                        CLOCK_LEFT_SetFractionalDividerRegister((clkDivider), 0u)
#define CLOCK_LEFT_SetDivider(clkDivider)           CLOCK_LEFT_SetDividerRegister((clkDivider), 1u)
#define CLOCK_LEFT_SetDividerValue(clkDivider)      CLOCK_LEFT_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/

#define CLOCK_LEFT_DIV_REG    (*(reg32 *)CLOCK_LEFT__REGISTER)
#define CLOCK_LEFT_ENABLE_REG CLOCK_LEFT_DIV_REG

#endif /* !defined(CY_CLOCK_CLOCK_LEFT_H) */

/* [] END OF FILE */
