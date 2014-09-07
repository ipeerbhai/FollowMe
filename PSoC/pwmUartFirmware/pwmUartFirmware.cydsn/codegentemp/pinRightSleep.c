/*******************************************************************************
* File Name: pinRightSleep.c  
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
#include "pinRightSleep.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        pinRightSleep_PC =   (pinRightSleep_PC & \
                                (uint32)(~(uint32)(pinRightSleep_DRIVE_MODE_IND_MASK << (pinRightSleep_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (pinRightSleep_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: pinRightSleep_Write
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
void pinRightSleep_Write(uint8 value) 
{
    uint8 drVal = (uint8)(pinRightSleep_DR & (uint8)(~pinRightSleep_MASK));
    drVal = (drVal | ((uint8)(value << pinRightSleep_SHIFT) & pinRightSleep_MASK));
    pinRightSleep_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: pinRightSleep_SetDriveMode
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
void pinRightSleep_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(pinRightSleep__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: pinRightSleep_Read
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
*  Macro pinRightSleep_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 pinRightSleep_Read(void) 
{
    return (uint8)((pinRightSleep_PS & pinRightSleep_MASK) >> pinRightSleep_SHIFT);
}


/*******************************************************************************
* Function Name: pinRightSleep_ReadDataReg
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
uint8 pinRightSleep_ReadDataReg(void) 
{
    return (uint8)((pinRightSleep_DR & pinRightSleep_MASK) >> pinRightSleep_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(pinRightSleep_INTSTAT) 

    /*******************************************************************************
    * Function Name: pinRightSleep_ClearInterrupt
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
    uint8 pinRightSleep_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(pinRightSleep_INTSTAT & pinRightSleep_MASK);
		pinRightSleep_INTSTAT = maskedStatus;
        return maskedStatus >> pinRightSleep_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
