/*******************************************************************************
* File Name: TIMER_ThreadTimer_PM.c
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

#include "TIMER_ThreadTimer.h"
static TIMER_ThreadTimer_backupStruct TIMER_ThreadTimer_backup;


/*******************************************************************************
* Function Name: TIMER_ThreadTimer_SaveConfig
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
*  TIMER_ThreadTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TIMER_ThreadTimer_SaveConfig(void) 
{
    #if (!TIMER_ThreadTimer_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            TIMER_ThreadTimer_backup.TimerUdb = TIMER_ThreadTimer_ReadCounter();
            TIMER_ThreadTimer_backup.TimerPeriod = TIMER_ThreadTimer_ReadPeriod();
            TIMER_ThreadTimer_backup.InterruptMaskValue = TIMER_ThreadTimer_STATUS_MASK;
            #if (TIMER_ThreadTimer_UsingHWCaptureCounter)
                TIMER_ThreadTimer_backup.TimerCaptureCounter = TIMER_ThreadTimer_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            TIMER_ThreadTimer_backup.TimerUdb = TIMER_ThreadTimer_ReadCounter();
            TIMER_ThreadTimer_backup.InterruptMaskValue = TIMER_ThreadTimer_STATUS_MASK;
            #if (TIMER_ThreadTimer_UsingHWCaptureCounter)
                TIMER_ThreadTimer_backup.TimerCaptureCounter = TIMER_ThreadTimer_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!TIMER_ThreadTimer_ControlRegRemoved)
            TIMER_ThreadTimer_backup.TimerControlRegister = TIMER_ThreadTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: TIMER_ThreadTimer_RestoreConfig
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
*  TIMER_ThreadTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_ThreadTimer_RestoreConfig(void) 
{   
    #if (!TIMER_ThreadTimer_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 TIMER_ThreadTimer_interruptState;

            TIMER_ThreadTimer_WriteCounter(TIMER_ThreadTimer_backup.TimerUdb);
            TIMER_ThreadTimer_WritePeriod(TIMER_ThreadTimer_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            TIMER_ThreadTimer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            TIMER_ThreadTimer_STATUS_AUX_CTRL |= TIMER_ThreadTimer_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(TIMER_ThreadTimer_interruptState);
            TIMER_ThreadTimer_STATUS_MASK =TIMER_ThreadTimer_backup.InterruptMaskValue;
            #if (TIMER_ThreadTimer_UsingHWCaptureCounter)
                TIMER_ThreadTimer_SetCaptureCount(TIMER_ThreadTimer_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            TIMER_ThreadTimer_WriteCounter(TIMER_ThreadTimer_backup.TimerUdb);
            TIMER_ThreadTimer_STATUS_MASK =TIMER_ThreadTimer_backup.InterruptMaskValue;
            #if (TIMER_ThreadTimer_UsingHWCaptureCounter)
                TIMER_ThreadTimer_SetCaptureCount(TIMER_ThreadTimer_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!TIMER_ThreadTimer_ControlRegRemoved)
            TIMER_ThreadTimer_WriteControlRegister(TIMER_ThreadTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: TIMER_ThreadTimer_Sleep
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
*  TIMER_ThreadTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void TIMER_ThreadTimer_Sleep(void) 
{
    #if(!TIMER_ThreadTimer_ControlRegRemoved)
        /* Save Counter's enable state */
        if(TIMER_ThreadTimer_CTRL_ENABLE == (TIMER_ThreadTimer_CONTROL & TIMER_ThreadTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            TIMER_ThreadTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            TIMER_ThreadTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    TIMER_ThreadTimer_Stop();
    TIMER_ThreadTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: TIMER_ThreadTimer_Wakeup
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
*  TIMER_ThreadTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TIMER_ThreadTimer_Wakeup(void) 
{
    TIMER_ThreadTimer_RestoreConfig();
    #if(!TIMER_ThreadTimer_ControlRegRemoved)
        if(TIMER_ThreadTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                TIMER_ThreadTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
