/*******************************************************************************
* File Name: pinLeftSleep.c  
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
#include "pinLeftSleep.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        pinLeftSleep_PC =   (pinLeftSleep_PC & \
                                (uint32)(~(uint32)(pinLeftSleep_DRIVE_MODE_IND_MASK << (pinLeftSleep_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (pinLeftSleep_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: pinLeftSleep_Write
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
void pinLeftSleep_Write(uint8 value) 
{
    uint8 drVal = (uint8)(pinLeftSleep_DR & (uint8)(~pinLeftSleep_MASK));
    drVal = (drVal | ((uint8)(value << pinLeftSleep_SHIFT) & pinLeftSleep_MASK));
    pinLeftSleep_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: pinLeftSleep_SetDriveMode
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
void pinLeftSleep_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(pinLeftSleep__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: pinLeftSleep_Read
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
*  Macro pinLeftSleep_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 pinLeftSleep_Read(void) 
{
    return (uint8)((pinLeftSleep_PS & pinLeftSleep_MASK) >> pinLeftSleep_SHIFT);
}


/*******************************************************************************
* Function Name: pinLeftSleep_ReadDataReg
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
uint8 pinLeftSleep_ReadDataReg(void) 
{
    return (uint8)((pinLeftSleep_DR & pinLeftSleep_MASK) >> pinLeftSleep_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(pinLeftSleep_INTSTAT) 

    /*******************************************************************************
    * Function Name: pinLeftSleep_ClearInterrupt
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
    uint8 pinLeftSleep_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(pinLeftSleep_INTSTAT & pinLeftSleep_MASK);
		pinLeftSleep_INTSTAT = maskedStatus;
        return maskedStatus >> pinLeftSleep_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
