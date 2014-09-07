/*******************************************************************************
* File Name: isrUpdateSpeed.c  
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
#include <isrUpdateSpeed.h>

#if !defined(isrUpdateSpeed__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isrUpdateSpeed_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: isrUpdateSpeed_Start
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
void isrUpdateSpeed_Start(void)
{
    /* For all we know the interrupt is active. */
    isrUpdateSpeed_Disable();

    /* Set the ISR to point to the isrUpdateSpeed Interrupt. */
    isrUpdateSpeed_SetVector(&isrUpdateSpeed_Interrupt);

    /* Set the priority. */
    isrUpdateSpeed_SetPriority((uint8)isrUpdateSpeed_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isrUpdateSpeed_Enable();
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_StartEx
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
void isrUpdateSpeed_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isrUpdateSpeed_Disable();

    /* Set the ISR to point to the isrUpdateSpeed Interrupt. */
    isrUpdateSpeed_SetVector(address);

    /* Set the priority. */
    isrUpdateSpeed_SetPriority((uint8)isrUpdateSpeed_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isrUpdateSpeed_Enable();
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_Stop
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
void isrUpdateSpeed_Stop(void)
{
    /* Disable this interrupt. */
    isrUpdateSpeed_Disable();

    /* Set the ISR to point to the passive one. */
    isrUpdateSpeed_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isrUpdateSpeed.
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
CY_ISR(isrUpdateSpeed_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isrUpdateSpeed_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isrUpdateSpeed_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isrUpdateSpeed_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isrUpdateSpeed_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + isrUpdateSpeed__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_GetVector
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
cyisraddress isrUpdateSpeed_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + isrUpdateSpeed__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isrUpdateSpeed_Start
*   or isrUpdateSpeed_StartEx will override any effect this method would 
*   have had. This method should only be called after isrUpdateSpeed_Start or 
*   isrUpdateSpeed_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isrUpdateSpeed_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((isrUpdateSpeed__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *isrUpdateSpeed_INTC_PRIOR = (*isrUpdateSpeed_INTC_PRIOR & (uint32)(~isrUpdateSpeed__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_GetPriority
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
uint8 isrUpdateSpeed_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((isrUpdateSpeed__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*isrUpdateSpeed_INTC_PRIOR & isrUpdateSpeed__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_Enable
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
void isrUpdateSpeed_Enable(void)
{
    /* Enable the general interrupt. */
    *isrUpdateSpeed_INTC_SET_EN = isrUpdateSpeed__INTC_MASK;
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_GetState
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
uint8 isrUpdateSpeed_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isrUpdateSpeed_INTC_SET_EN & (uint32)isrUpdateSpeed__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_Disable
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
void isrUpdateSpeed_Disable(void)
{
    /* Disable the general interrupt. */
    *isrUpdateSpeed_INTC_CLR_EN = isrUpdateSpeed__INTC_MASK;
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_SetPending
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
void isrUpdateSpeed_SetPending(void)
{
    *isrUpdateSpeed_INTC_SET_PD = isrUpdateSpeed__INTC_MASK;
}


/*******************************************************************************
* Function Name: isrUpdateSpeed_ClearPending
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
void isrUpdateSpeed_ClearPending(void)
{
    *isrUpdateSpeed_INTC_CLR_PD = isrUpdateSpeed__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
