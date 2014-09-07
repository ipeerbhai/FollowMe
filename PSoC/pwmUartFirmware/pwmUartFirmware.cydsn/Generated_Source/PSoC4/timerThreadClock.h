/*******************************************************************************
* File Name: timerThreadClock.h
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

#if !defined(CY_CLOCK_timerThreadClock_H)
#define CY_CLOCK_timerThreadClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void timerThreadClock_Start(void);
void timerThreadClock_Stop(void);

void timerThreadClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 timerThreadClock_GetDividerRegister(void);
uint8  timerThreadClock_GetFractionalDividerRegister(void);

#define timerThreadClock_Enable()                         timerThreadClock_Start()
#define timerThreadClock_Disable()                        timerThreadClock_Stop()
#define timerThreadClock_SetDividerRegister(clkDivider, reset)  \
                        timerThreadClock_SetFractionalDividerRegister((clkDivider), 0u)
#define timerThreadClock_SetDivider(clkDivider)           timerThreadClock_SetDividerRegister((clkDivider), 1u)
#define timerThreadClock_SetDividerValue(clkDivider)      timerThreadClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/

#define timerThreadClock_DIV_REG    (*(reg32 *)timerThreadClock__REGISTER)
#define timerThreadClock_ENABLE_REG timerThreadClock_DIV_REG

#endif /* !defined(CY_CLOCK_timerThreadClock_H) */

/* [] END OF FILE */
