/*******************************************************************************
* File Name: ISR_UpdateSpeed.h
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
#if !defined(CY_ISR_ISR_UpdateSpeed_H)
#define CY_ISR_ISR_UpdateSpeed_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISR_UpdateSpeed_Start(void);
void ISR_UpdateSpeed_StartEx(cyisraddress address);
void ISR_UpdateSpeed_Stop(void);

CY_ISR_PROTO(ISR_UpdateSpeed_Interrupt);

void ISR_UpdateSpeed_SetVector(cyisraddress address);
cyisraddress ISR_UpdateSpeed_GetVector(void);

void ISR_UpdateSpeed_SetPriority(uint8 priority);
uint8 ISR_UpdateSpeed_GetPriority(void);

void ISR_UpdateSpeed_Enable(void);
uint8 ISR_UpdateSpeed_GetState(void);
void ISR_UpdateSpeed_Disable(void);

void ISR_UpdateSpeed_SetPending(void);
void ISR_UpdateSpeed_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_UpdateSpeed ISR. */
#define ISR_UpdateSpeed_INTC_VECTOR            ((reg32 *) ISR_UpdateSpeed__INTC_VECT)

/* Address of the ISR_UpdateSpeed ISR priority. */
#define ISR_UpdateSpeed_INTC_PRIOR             ((reg32 *) ISR_UpdateSpeed__INTC_PRIOR_REG)

/* Priority of the ISR_UpdateSpeed interrupt. */
#define ISR_UpdateSpeed_INTC_PRIOR_NUMBER      ISR_UpdateSpeed__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_UpdateSpeed interrupt. */
#define ISR_UpdateSpeed_INTC_SET_EN            ((reg32 *) ISR_UpdateSpeed__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_UpdateSpeed interrupt. */
#define ISR_UpdateSpeed_INTC_CLR_EN            ((reg32 *) ISR_UpdateSpeed__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_UpdateSpeed interrupt state to pending. */
#define ISR_UpdateSpeed_INTC_SET_PD            ((reg32 *) ISR_UpdateSpeed__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_UpdateSpeed interrupt. */
#define ISR_UpdateSpeed_INTC_CLR_PD            ((reg32 *) ISR_UpdateSpeed__INTC_CLR_PD_REG)



#endif /* CY_ISR_ISR_UpdateSpeed_H */


/* [] END OF FILE */
