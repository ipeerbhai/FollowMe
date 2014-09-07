/*******************************************************************************
* File Name: timerThreadTimers_PM.c
* Version 2.50
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "timerThreadTimers.h"
static timerThreadTimers_backupStruct timerThreadTimers_backup;


/*******************************************************************************
* Function Name: timerThreadTimers_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timerThreadTimers_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void timerThreadTimers_SaveConfig(void) 
{
    #if (!timerThreadTimers_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            timerThreadTimers_backup.TimerUdb = timerThreadTimers_ReadCounter();
            timerThreadTimers_backup.TimerPeriod = timerThreadTimers_ReadPeriod();
            timerThreadTimers_backup.InterruptMaskValue = timerThreadTimers_STATUS_MASK;
            #if (timerThreadTimers_UsingHWCaptureCounter)
                timerThreadTimers_backup.TimerCaptureCounter = timerThreadTimers_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            timerThreadTimers_backup.TimerUdb = timerThreadTimers_ReadCounter();
            timerThreadTimers_backup.InterruptMaskValue = timerThreadTimers_STATUS_MASK;
            #if (timerThreadTimers_UsingHWCaptureCounter)
                timerThreadTimers_backup.TimerCaptureCounter = timerThreadTimers_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!timerThreadTimers_ControlRegRemoved)
            timerThreadTimers_backup.TimerControlRegister = timerThreadTimers_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: timerThreadTimers_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timerThreadTimers_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void timerThreadTimers_RestoreConfig(void) 
{   
    #if (!timerThreadTimers_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 timerThreadTimers_interruptState;

            timerThreadTimers_WriteCounter(timerThreadTimers_backup.TimerUdb);
            timerThreadTimers_WritePeriod(timerThreadTimers_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            timerThreadTimers_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            timerThreadTimers_STATUS_AUX_CTRL |= timerThreadTimers_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(timerThreadTimers_interruptState);
            timerThreadTimers_STATUS_MASK =timerThreadTimers_backup.InterruptMaskValue;
            #if (timerThreadTimers_UsingHWCaptureCounter)
                timerThreadTimers_SetCaptureCount(timerThreadTimers_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            timerThreadTimers_WriteCounter(timerThreadTimers_backup.TimerUdb);
            timerThreadTimers_STATUS_MASK =timerThreadTimers_backup.InterruptMaskValue;
            #if (timerThreadTimers_UsingHWCaptureCounter)
                timerThreadTimers_SetCaptureCount(timerThreadTimers_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!timerThreadTimers_ControlRegRemoved)
            timerThreadTimers_WriteControlRegister(timerThreadTimers_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: timerThreadTimers_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timerThreadTimers_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void timerThreadTimers_Sleep(void) 
{
    #if(!timerThreadTimers_ControlRegRemoved)
        /* Save Counter's enable state */
        if(timerThreadTimers_CTRL_ENABLE == (timerThreadTimers_CONTROL & timerThreadTimers_CTRL_ENABLE))
        {
            /* Timer is enabled */
            timerThreadTimers_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            timerThreadTimers_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    timerThreadTimers_Stop();
    timerThreadTimers_SaveConfig();
}


/*******************************************************************************
* Function Name: timerThreadTimers_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  timerThreadTimers_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void timerThreadTimers_Wakeup(void) 
{
    timerThreadTimers_RestoreConfig();
    #if(!timerThreadTimers_ControlRegRemoved)
        if(timerThreadTimers_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                timerThreadTimers_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
