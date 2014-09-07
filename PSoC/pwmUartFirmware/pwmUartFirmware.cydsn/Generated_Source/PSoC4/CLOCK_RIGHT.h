/*******************************************************************************
* File Name: CLOCK_RIGHT.h
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

#if !defined(CY_CLOCK_CLOCK_RIGHT_H)
#define CY_CLOCK_CLOCK_RIGHT_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void CLOCK_RIGHT_Start(void);
void CLOCK_RIGHT_Stop(void);

void CLOCK_RIGHT_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CLOCK_RIGHT_GetDividerRegister(void);
uint8  CLOCK_RIGHT_GetFractionalDividerRegister(void);

#define CLOCK_RIGHT_Enable()                         CLOCK_RIGHT_Start()
#define CLOCK_RIGHT_Disable()                        CLOCK_RIGHT_Stop()
#define CLOCK_RIGHT_SetDividerRegister(clkDivider, reset)  \
                        CLOCK_RIGHT_SetFractionalDividerRegister((clkDivider), 0u)
#define CLOCK_RIGHT_SetDivider(clkDivider)           CLOCK_RIGHT_SetDividerRegister((clkDivider), 1u)
#define CLOCK_RIGHT_SetDividerValue(clkDivider)      CLOCK_RIGHT_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/

#define CLOCK_RIGHT_DIV_REG    (*(reg32 *)CLOCK_RIGHT__REGISTER)
#define CLOCK_RIGHT_ENABLE_REG CLOCK_RIGHT_DIV_REG

#endif /* !defined(CY_CLOCK_CLOCK_RIGHT_H) */

/* [] END OF FILE */
