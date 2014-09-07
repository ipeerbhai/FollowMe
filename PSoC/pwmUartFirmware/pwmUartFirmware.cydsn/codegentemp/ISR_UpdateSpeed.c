/*******************************************************************************
* File Name: ISR_UpdateSpeed.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <ISR_UpdateSpeed.h>

#if !defined(ISR_UpdateSpeed__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_UpdateSpeed_intc` */
#include "TIMER_ThreadTimer.h"
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_UpdateSpeed_Disable();

    /* Set the ISR to point to the ISR_UpdateSpeed Interrupt. */
    ISR_UpdateSpeed_SetVector(&ISR_UpdateSpeed_Interrupt);

    /* Set the priority. */
    ISR_UpdateSpeed_SetPriority((uint8)ISR_UpdateSpeed_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_UpdateSpeed_Enable();
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_UpdateSpeed_Disable();

    /* Set the ISR to point to the ISR_UpdateSpeed Interrupt. */
    ISR_UpdateSpeed_SetVector(address);

    /* Set the priority. */
    ISR_UpdateSpeed_SetPriority((uint8)ISR_UpdateSpeed_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_UpdateSpeed_Enable();
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_Stop(void)
{
    /* Disable this interrupt. */
    ISR_UpdateSpeed_Disable();

    /* Set the ISR to point to the passive one. */
    ISR_UpdateSpeed_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISR_UpdateSpeed.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(ISR_UpdateSpeed_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISR_UpdateSpeed_Interrupt` */
    TIMER_ThreadTimer_ReadStatusRegister();  //Required to clear the interrupt.


    /* `#END` */
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_UpdateSpeed_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISR_UpdateSpeed_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ISR_UpdateSpeed__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress ISR_UpdateSpeed_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ISR_UpdateSpeed__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISR_UpdateSpeed_Start
*   or ISR_UpdateSpeed_StartEx will override any effect this method would 
*   have had. This method should only be called after ISR_UpdateSpeed_Start or 
*   ISR_UpdateSpeed_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ISR_UpdateSpeed__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ISR_UpdateSpeed_INTC_PRIOR = (*ISR_UpdateSpeed_INTC_PRIOR & (uint32)(~ISR_UpdateSpeed__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 ISR_UpdateSpeed_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ISR_UpdateSpeed__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ISR_UpdateSpeed_INTC_PRIOR & ISR_UpdateSpeed__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_Enable(void)
{
    /* Enable the general interrupt. */
    *ISR_UpdateSpeed_INTC_SET_EN = ISR_UpdateSpeed__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 ISR_UpdateSpeed_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISR_UpdateSpeed_INTC_SET_EN & (uint32)ISR_UpdateSpeed__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_Disable(void)
{
    /* Disable the general interrupt. */
    *ISR_UpdateSpeed_INTC_CLR_EN = ISR_UpdateSpeed__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_SetPending(void)
{
    *ISR_UpdateSpeed_INTC_SET_PD = ISR_UpdateSpeed__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_UpdateSpeed_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ISR_UpdateSpeed_ClearPending(void)
{
    *ISR_UpdateSpeed_INTC_CLR_PD = ISR_UpdateSpeed__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
