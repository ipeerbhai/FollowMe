/*******************************************************************************
* File Name: pinLeftStep.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "pinLeftStep.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        pinLeftStep_PC =   (pinLeftStep_PC & \
                                (uint32)(~(uint32)(pinLeftStep_DRIVE_MODE_IND_MASK << (pinLeftStep_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (pinLeftStep_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: pinLeftStep_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void pinLeftStep_Write(uint8 value) 
{
    uint8 drVal = (uint8)(pinLeftStep_DR & (uint8)(~pinLeftStep_MASK));
    drVal = (drVal | ((uint8)(value << pinLeftStep_SHIFT) & pinLeftStep_MASK));
    pinLeftStep_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: pinLeftStep_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void pinLeftStep_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(pinLeftStep__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: pinLeftStep_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro pinLeftStep_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 pinLeftStep_Read(void) 
{
    return (uint8)((pinLeftStep_PS & pinLeftStep_MASK) >> pinLeftStep_SHIFT);
}


/*******************************************************************************
* Function Name: pinLeftStep_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 pinLeftStep_ReadDataReg(void) 
{
    return (uint8)((pinLeftStep_DR & pinLeftStep_MASK) >> pinLeftStep_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(pinLeftStep_INTSTAT) 

    /*******************************************************************************
    * Function Name: pinLeftStep_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 pinLeftStep_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(pinLeftStep_INTSTAT & pinLeftStep_MASK);
		pinLeftStep_INTSTAT = maskedStatus;
        return maskedStatus >> pinLeftStep_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
