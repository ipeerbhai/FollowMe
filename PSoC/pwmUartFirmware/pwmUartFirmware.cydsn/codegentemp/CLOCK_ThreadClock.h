/*******************************************************************************
* File Name: CLOCK_ThreadClock.h
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

#if !defined(CY_CLOCK_CLOCK_ThreadClock_H)
#define CY_CLOCK_CLOCK_ThreadClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void CLOCK_ThreadClock_Start(void);
void CLOCK_ThreadClock_Stop(void);

void CLOCK_ThreadClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CLOCK_ThreadClock_GetDividerRegister(void);
uint8  CLOCK_ThreadClock_GetFractionalDividerRegister(void);

#define CLOCK_ThreadClock_Enable()                         CLOCK_ThreadClock_Start()
#define CLOCK_ThreadClock_Disable()                        CLOCK_ThreadClock_Stop()
#define CLOCK_ThreadClock_SetDividerRegister(clkDivider, reset)  \
                        CLOCK_ThreadClock_SetFractionalDividerRegister((clkDivider), 0u)
#define CLOCK_ThreadClock_SetDivider(clkDivider)           CLOCK_ThreadClock_SetDividerRegister((clkDivider), 1u)
#define CLOCK_ThreadClock_SetDividerValue(clkDivider)      CLOCK_ThreadClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/

#define CLOCK_ThreadClock_DIV_REG    (*(reg32 *)CLOCK_ThreadClock__REGISTER)
#define CLOCK_ThreadClock_ENABLE_REG CLOCK_ThreadClock_DIV_REG

#endif /* !defined(CY_CLOCK_CLOCK_ThreadClock_H) */

/* [] END OF FILE */
