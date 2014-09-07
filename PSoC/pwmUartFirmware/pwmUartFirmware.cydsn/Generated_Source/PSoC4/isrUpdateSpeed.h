/*******************************************************************************
* File Name: isrUpdateSpeed.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isrUpdateSpeed_H)
#define CY_ISR_isrUpdateSpeed_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrUpdateSpeed_Start(void);
void isrUpdateSpeed_StartEx(cyisraddress address);
void isrUpdateSpeed_Stop(void);

CY_ISR_PROTO(isrUpdateSpeed_Interrupt);

void isrUpdateSpeed_SetVector(cyisraddress address);
cyisraddress isrUpdateSpeed_GetVector(void);

void isrUpdateSpeed_SetPriority(uint8 priority);
uint8 isrUpdateSpeed_GetPriority(void);

void isrUpdateSpeed_Enable(void);
uint8 isrUpdateSpeed_GetState(void);
void isrUpdateSpeed_Disable(void);

void isrUpdateSpeed_SetPending(void);
void isrUpdateSpeed_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrUpdateSpeed ISR. */
#define isrUpdateSpeed_INTC_VECTOR            ((reg32 *) isrUpdateSpeed__INTC_VECT)

/* Address of the isrUpdateSpeed ISR priority. */
#define isrUpdateSpeed_INTC_PRIOR             ((reg32 *) isrUpdateSpeed__INTC_PRIOR_REG)

/* Priority of the isrUpdateSpeed interrupt. */
#define isrUpdateSpeed_INTC_PRIOR_NUMBER      isrUpdateSpeed__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrUpdateSpeed interrupt. */
#define isrUpdateSpeed_INTC_SET_EN            ((reg32 *) isrUpdateSpeed__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrUpdateSpeed interrupt. */
#define isrUpdateSpeed_INTC_CLR_EN            ((reg32 *) isrUpdateSpeed__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrUpdateSpeed interrupt state to pending. */
#define isrUpdateSpeed_INTC_SET_PD            ((reg32 *) isrUpdateSpeed__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrUpdateSpeed interrupt. */
#define isrUpdateSpeed_INTC_CLR_PD            ((reg32 *) isrUpdateSpeed__INTC_CLR_PD_REG)



#endif /* CY_ISR_isrUpdateSpeed_H */


/* [] END OF FILE */
