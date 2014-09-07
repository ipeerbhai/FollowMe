/*******************************************************************************
* File Name: pinRightStep.c  
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
#include "pinRightStep.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        pinRightStep_PC =   (pinRightStep_PC & \
                                (uint32)(~(uint32)(pinRightStep_DRIVE_MODE_IND_MASK << (pinRightStep_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (pinRightStep_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: pinRightStep_Write
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
void pinRightStep_Write(uint8 value) 
{
    uint8 drVal = (uint8)(pinRightStep_DR & (uint8)(~pinRightStep_MASK));
    drVal = (drVal | ((uint8)(value << pinRightStep_SHIFT) & pinRightStep_MASK));
    pinRightStep_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: pinRightStep_SetDriveMode
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
void pinRightStep_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(pinRightStep__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: pinRightStep_Read
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
*  Macro pinRightStep_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 pinRightStep_Read(void) 
{
    return (uint8)((pinRightStep_PS & pinRightStep_MASK) >> pinRightStep_SHIFT);
}


/*******************************************************************************
* Function Name: pinRightStep_ReadDataReg
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
uint8 pinRightStep_ReadDataReg(void) 
{
    return (uint8)((pinRightStep_DR & pinRightStep_MASK) >> pinRightStep_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(pinRightStep_INTSTAT) 

    /*******************************************************************************
    * Function Name: pinRightStep_ClearInterrupt
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
    uint8 pinRightStep_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(pinRightStep_INTSTAT & pinRightStep_MASK);
		pinRightStep_INTSTAT = maskedStatus;
        return maskedStatus >> pinRightStep_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
