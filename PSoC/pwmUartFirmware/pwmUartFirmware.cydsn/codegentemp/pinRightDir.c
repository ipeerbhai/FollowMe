/*******************************************************************************
* File Name: pinRightDir.c  
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
#include "pinRightDir.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        pinRightDir_PC =   (pinRightDir_PC & \
                                (uint32)(~(uint32)(pinRightDir_DRIVE_MODE_IND_MASK << (pinRightDir_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (pinRightDir_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: pinRightDir_Write
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
void pinRightDir_Write(uint8 value) 
{
    uint8 drVal = (uint8)(pinRightDir_DR & (uint8)(~pinRightDir_MASK));
    drVal = (drVal | ((uint8)(value << pinRightDir_SHIFT) & pinRightDir_MASK));
    pinRightDir_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: pinRightDir_SetDriveMode
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
void pinRightDir_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(pinRightDir__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: pinRightDir_Read
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
*  Macro pinRightDir_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 pinRightDir_Read(void) 
{
    return (uint8)((pinRightDir_PS & pinRightDir_MASK) >> pinRightDir_SHIFT);
}


/*******************************************************************************
* Function Name: pinRightDir_ReadDataReg
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
uint8 pinRightDir_ReadDataReg(void) 
{
    return (uint8)((pinRightDir_DR & pinRightDir_MASK) >> pinRightDir_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(pinRightDir_INTSTAT) 

    /*******************************************************************************
    * Function Name: pinRightDir_ClearInterrupt
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
    uint8 pinRightDir_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(pinRightDir_INTSTAT & pinRightDir_MASK);
		pinRightDir_INTSTAT = maskedStatus;
        return maskedStatus >> pinRightDir_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
