/*******************************************************************************
* File Name: timerThreadTimers.h
* Version 2.50
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_30_timerThreadTimers_H)
#define CY_Timer_v2_30_timerThreadTimers_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 timerThreadTimers_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define timerThreadTimers_Resolution                 8u
#define timerThreadTimers_UsingFixedFunction         0u
#define timerThreadTimers_UsingHWCaptureCounter      0u
#define timerThreadTimers_SoftwareCaptureMode        0u
#define timerThreadTimers_SoftwareTriggerMode        0u
#define timerThreadTimers_UsingHWEnable              0u
#define timerThreadTimers_EnableTriggerMode          0u
#define timerThreadTimers_InterruptOnCaptureCount    0u
#define timerThreadTimers_RunModeUsed                0u
#define timerThreadTimers_ControlRegRemoved          0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!timerThreadTimers_UsingFixedFunction)
        #if (CY_UDB_V0)
            uint8 TimerUdb;                 /* Timer internal counter value */
            uint8 TimerPeriod;              /* Timer Period value       */
            uint8 InterruptMaskValue;       /* Timer Compare Value */
            #if (timerThreadTimers_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;  /* Timer Capture Counter Value */
            #endif /* variable declaration for backing up Capture Counter value*/
        #endif /* variables for non retention registers in CY_UDB_V0 */

        #if (CY_UDB_V1)
            uint8 TimerUdb;
            uint8 InterruptMaskValue;
            #if (timerThreadTimers_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;
            #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */
        #endif /* (CY_UDB_V1) */

        #if (!timerThreadTimers_ControlRegRemoved)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */
}timerThreadTimers_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    timerThreadTimers_Start(void) ;
void    timerThreadTimers_Stop(void) ;

void    timerThreadTimers_SetInterruptMode(uint8 interruptMode) ;
uint8   timerThreadTimers_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define timerThreadTimers_GetInterruptSource() timerThreadTimers_ReadStatusRegister()

#if(!timerThreadTimers_ControlRegRemoved)
    uint8   timerThreadTimers_ReadControlRegister(void) ;
    void    timerThreadTimers_WriteControlRegister(uint8 control) \
        ;
#endif /* (!timerThreadTimers_ControlRegRemoved) */

uint8  timerThreadTimers_ReadPeriod(void) ;
void    timerThreadTimers_WritePeriod(uint8 period) \
    ;
uint8  timerThreadTimers_ReadCounter(void) ;
void    timerThreadTimers_WriteCounter(uint8 counter) \
    ;
uint8  timerThreadTimers_ReadCapture(void) ;
void    timerThreadTimers_SoftwareCapture(void) ;


#if(!timerThreadTimers_UsingFixedFunction) /* UDB Prototypes */
    #if (timerThreadTimers_SoftwareCaptureMode)
        void    timerThreadTimers_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!timerThreadTimers_UsingFixedFunction) */

    #if (timerThreadTimers_SoftwareTriggerMode)
        void    timerThreadTimers_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (timerThreadTimers_SoftwareTriggerMode) */
    #if (timerThreadTimers_EnableTriggerMode)
        void    timerThreadTimers_EnableTrigger(void) ;
        void    timerThreadTimers_DisableTrigger(void) ;
    #endif /* (timerThreadTimers_EnableTriggerMode) */

    #if(timerThreadTimers_InterruptOnCaptureCount)
        #if(!timerThreadTimers_ControlRegRemoved)
            void    timerThreadTimers_SetInterruptCount(uint8 interruptCount) \
                ;
        #endif /* (!timerThreadTimers_ControlRegRemoved) */
    #endif /* (timerThreadTimers_InterruptOnCaptureCount) */

    #if (timerThreadTimers_UsingHWCaptureCounter)
        void    timerThreadTimers_SetCaptureCount(uint8 captureCount) \
            ;
        uint8   timerThreadTimers_ReadCaptureCount(void) ;
    #endif /* (timerThreadTimers_UsingHWCaptureCounter) */

    void timerThreadTimers_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void timerThreadTimers_Init(void)          ;
void timerThreadTimers_Enable(void)        ;
void timerThreadTimers_SaveConfig(void)    ;
void timerThreadTimers_RestoreConfig(void) ;
void timerThreadTimers_Sleep(void)         ;
void timerThreadTimers_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define timerThreadTimers__B_TIMER__CM_NONE 0
#define timerThreadTimers__B_TIMER__CM_RISINGEDGE 1
#define timerThreadTimers__B_TIMER__CM_FALLINGEDGE 2
#define timerThreadTimers__B_TIMER__CM_EITHEREDGE 3
#define timerThreadTimers__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define timerThreadTimers__B_TIMER__TM_NONE 0x00u
#define timerThreadTimers__B_TIMER__TM_RISINGEDGE 0x04u
#define timerThreadTimers__B_TIMER__TM_FALLINGEDGE 0x08u
#define timerThreadTimers__B_TIMER__TM_EITHEREDGE 0x0Cu
#define timerThreadTimers__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define timerThreadTimers_INIT_PERIOD             24u
#define timerThreadTimers_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << timerThreadTimers_CTRL_CAP_MODE_SHIFT))
#define timerThreadTimers_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << timerThreadTimers_CTRL_TRIG_MODE_SHIFT))
#if (timerThreadTimers_UsingFixedFunction)
    #define timerThreadTimers_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << timerThreadTimers_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << timerThreadTimers_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define timerThreadTimers_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << timerThreadTimers_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << timerThreadTimers_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << timerThreadTimers_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (timerThreadTimers_UsingFixedFunction) */
#define timerThreadTimers_INIT_CAPTURE_COUNT      (2u)
#define timerThreadTimers_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << timerThreadTimers_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (timerThreadTimers_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define timerThreadTimers_STATUS         (*(reg8 *) timerThreadTimers_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define timerThreadTimers_STATUS_MASK    (*(reg8 *) timerThreadTimers_TimerHW__SR0 )
    #define timerThreadTimers_CONTROL        (*(reg8 *) timerThreadTimers_TimerHW__CFG0)
    #define timerThreadTimers_CONTROL2       (*(reg8 *) timerThreadTimers_TimerHW__CFG1)
    #define timerThreadTimers_CONTROL2_PTR   ( (reg8 *) timerThreadTimers_TimerHW__CFG1)
    #define timerThreadTimers_RT1            (*(reg8 *) timerThreadTimers_TimerHW__RT1)
    #define timerThreadTimers_RT1_PTR        ( (reg8 *) timerThreadTimers_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define timerThreadTimers_CONTROL3       (*(reg8 *) timerThreadTimers_TimerHW__CFG2)
        #define timerThreadTimers_CONTROL3_PTR   ( (reg8 *) timerThreadTimers_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define timerThreadTimers_GLOBAL_ENABLE  (*(reg8 *) timerThreadTimers_TimerHW__PM_ACT_CFG)
    #define timerThreadTimers_GLOBAL_STBY_ENABLE  (*(reg8 *) timerThreadTimers_TimerHW__PM_STBY_CFG)

    #define timerThreadTimers_CAPTURE_LSB         (* (reg16 *) timerThreadTimers_TimerHW__CAP0 )
    #define timerThreadTimers_CAPTURE_LSB_PTR       ((reg16 *) timerThreadTimers_TimerHW__CAP0 )
    #define timerThreadTimers_PERIOD_LSB          (* (reg16 *) timerThreadTimers_TimerHW__PER0 )
    #define timerThreadTimers_PERIOD_LSB_PTR        ((reg16 *) timerThreadTimers_TimerHW__PER0 )
    #define timerThreadTimers_COUNTER_LSB         (* (reg16 *) timerThreadTimers_TimerHW__CNT_CMP0 )
    #define timerThreadTimers_COUNTER_LSB_PTR       ((reg16 *) timerThreadTimers_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define timerThreadTimers_BLOCK_EN_MASK                     timerThreadTimers_TimerHW__PM_ACT_MSK
    #define timerThreadTimers_BLOCK_STBY_EN_MASK                timerThreadTimers_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define timerThreadTimers_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define timerThreadTimers_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define timerThreadTimers_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define timerThreadTimers_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define timerThreadTimers_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define timerThreadTimers_CTRL_ENABLE                        ((uint8)((uint8)0x01u << timerThreadTimers_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define timerThreadTimers_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define timerThreadTimers_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << timerThreadTimers_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define timerThreadTimers_CTRL_MODE_SHIFT                     0x01u
        #define timerThreadTimers_CTRL_MODE_MASK                     ((uint8)((uint8)0x07u << timerThreadTimers_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define timerThreadTimers_CTRL_RCOD_SHIFT        0x02u
        #define timerThreadTimers_CTRL_ENBL_SHIFT        0x00u
        #define timerThreadTimers_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define timerThreadTimers_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << timerThreadTimers_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define timerThreadTimers_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << timerThreadTimers_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define timerThreadTimers_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << timerThreadTimers_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define timerThreadTimers_CTRL_RCOD       ((uint8)((uint8)0x03u << timerThreadTimers_CTRL_RCOD_SHIFT))
        #define timerThreadTimers_CTRL_ENBL       ((uint8)((uint8)0x80u << timerThreadTimers_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define timerThreadTimers_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define timerThreadTimers_RT1_MASK                        ((uint8)((uint8)0x03u << timerThreadTimers_RT1_SHIFT))
    #define timerThreadTimers_SYNC                            ((uint8)((uint8)0x03u << timerThreadTimers_RT1_SHIFT))
    #define timerThreadTimers_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define timerThreadTimers_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << timerThreadTimers_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define timerThreadTimers_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << timerThreadTimers_SYNCDSI_SHIFT))

    #define timerThreadTimers_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << timerThreadTimers_CTRL_MODE_SHIFT))
    #define timerThreadTimers_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << timerThreadTimers_CTRL_MODE_SHIFT))
    #define timerThreadTimers_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << timerThreadTimers_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define timerThreadTimers_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define timerThreadTimers_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define timerThreadTimers_STATUS_TC_INT_MASK_SHIFT        (timerThreadTimers_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define timerThreadTimers_STATUS_CAPTURE_INT_MASK_SHIFT   (timerThreadTimers_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define timerThreadTimers_STATUS_TC                       ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_TC_SHIFT))
    #define timerThreadTimers_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define timerThreadTimers_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define timerThreadTimers_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define timerThreadTimers_STATUS              (* (reg8 *) timerThreadTimers_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define timerThreadTimers_STATUS_MASK         (* (reg8 *) timerThreadTimers_TimerUDB_rstSts_stsreg__MASK_REG)
    #define timerThreadTimers_STATUS_AUX_CTRL     (* (reg8 *) timerThreadTimers_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define timerThreadTimers_CONTROL             (* (reg8 *) timerThreadTimers_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(timerThreadTimers_Resolution <= 8u) /* 8-bit Timer */
        #define timerThreadTimers_CAPTURE_LSB         (* (reg8 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define timerThreadTimers_CAPTURE_LSB_PTR       ((reg8 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define timerThreadTimers_PERIOD_LSB          (* (reg8 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define timerThreadTimers_PERIOD_LSB_PTR        ((reg8 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define timerThreadTimers_COUNTER_LSB         (* (reg8 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define timerThreadTimers_COUNTER_LSB_PTR       ((reg8 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(timerThreadTimers_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define timerThreadTimers_CAPTURE_LSB         (* (reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define timerThreadTimers_CAPTURE_LSB_PTR       ((reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define timerThreadTimers_PERIOD_LSB          (* (reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define timerThreadTimers_PERIOD_LSB_PTR        ((reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define timerThreadTimers_COUNTER_LSB         (* (reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define timerThreadTimers_COUNTER_LSB_PTR       ((reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define timerThreadTimers_CAPTURE_LSB         (* (reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define timerThreadTimers_CAPTURE_LSB_PTR       ((reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define timerThreadTimers_PERIOD_LSB          (* (reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define timerThreadTimers_PERIOD_LSB_PTR        ((reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define timerThreadTimers_COUNTER_LSB         (* (reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define timerThreadTimers_COUNTER_LSB_PTR       ((reg16 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(timerThreadTimers_Resolution <= 24u)/* 24-bit Timer */
        #define timerThreadTimers_CAPTURE_LSB         (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define timerThreadTimers_CAPTURE_LSB_PTR       ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define timerThreadTimers_PERIOD_LSB          (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define timerThreadTimers_PERIOD_LSB_PTR        ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define timerThreadTimers_COUNTER_LSB         (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define timerThreadTimers_COUNTER_LSB_PTR       ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define timerThreadTimers_CAPTURE_LSB         (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define timerThreadTimers_CAPTURE_LSB_PTR       ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define timerThreadTimers_PERIOD_LSB          (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define timerThreadTimers_PERIOD_LSB_PTR        ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define timerThreadTimers_COUNTER_LSB         (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define timerThreadTimers_COUNTER_LSB_PTR       ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define timerThreadTimers_CAPTURE_LSB         (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define timerThreadTimers_CAPTURE_LSB_PTR       ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define timerThreadTimers_PERIOD_LSB          (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define timerThreadTimers_PERIOD_LSB_PTR        ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define timerThreadTimers_COUNTER_LSB         (* (reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define timerThreadTimers_COUNTER_LSB_PTR       ((reg32 *) timerThreadTimers_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #if (timerThreadTimers_UsingHWCaptureCounter)
        #define timerThreadTimers_CAP_COUNT              (*(reg8 *) timerThreadTimers_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define timerThreadTimers_CAP_COUNT_PTR          ( (reg8 *) timerThreadTimers_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define timerThreadTimers_CAPTURE_COUNT_CTRL     (*(reg8 *) timerThreadTimers_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define timerThreadTimers_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) timerThreadTimers_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (timerThreadTimers_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define timerThreadTimers_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define timerThreadTimers_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define timerThreadTimers_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define timerThreadTimers_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define timerThreadTimers_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define timerThreadTimers_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << timerThreadTimers_CTRL_INTCNT_SHIFT))
    #define timerThreadTimers_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << timerThreadTimers_CTRL_TRIG_MODE_SHIFT))
    #define timerThreadTimers_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << timerThreadTimers_CTRL_TRIG_EN_SHIFT))
    #define timerThreadTimers_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << timerThreadTimers_CTRL_CAP_MODE_SHIFT))
    #define timerThreadTimers_CTRL_ENABLE                    ((uint8)((uint8)0x01u << timerThreadTimers_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define timerThreadTimers_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define timerThreadTimers_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define timerThreadTimers_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define timerThreadTimers_STATUS_TC_INT_MASK_SHIFT       timerThreadTimers_STATUS_TC_SHIFT
    #define timerThreadTimers_STATUS_CAPTURE_INT_MASK_SHIFT  timerThreadTimers_STATUS_CAPTURE_SHIFT
    #define timerThreadTimers_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define timerThreadTimers_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define timerThreadTimers_STATUS_FIFOFULL_INT_MASK_SHIFT timerThreadTimers_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define timerThreadTimers_STATUS_TC                      ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define timerThreadTimers_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define timerThreadTimers_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define timerThreadTimers_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define timerThreadTimers_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define timerThreadTimers_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define timerThreadTimers_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << timerThreadTimers_STATUS_FIFOFULL_SHIFT))

    #define timerThreadTimers_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define timerThreadTimers_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define timerThreadTimers_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define timerThreadTimers_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define timerThreadTimers_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define timerThreadTimers_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_timerThreadTimers_H */


/* [] END OF FILE */
