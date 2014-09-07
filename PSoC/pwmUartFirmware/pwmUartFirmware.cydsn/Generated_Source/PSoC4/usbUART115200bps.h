/*******************************************************************************
* File Name: usbUART115200bps.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_usbUART115200bps_H)
#define CY_SCB_usbUART115200bps_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*  Conditional Compilation Parameters
****************************************/

#define usbUART115200bps_SCB_MODE                     (4u)

/* SCB modes enum */
#define usbUART115200bps_SCB_MODE_I2C                 (0x01u)
#define usbUART115200bps_SCB_MODE_SPI                 (0x02u)
#define usbUART115200bps_SCB_MODE_UART                (0x04u)
#define usbUART115200bps_SCB_MODE_EZI2C               (0x08u)
#define usbUART115200bps_SCB_MODE_UNCONFIG            (0xFFu)

/* Define run time operation mode */
#define usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG       (usbUART115200bps_SCB_MODE_I2C       == usbUART115200bps_scbMode)
#define usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG       (usbUART115200bps_SCB_MODE_SPI       == usbUART115200bps_scbMode)
#define usbUART115200bps_SCB_MODE_UART_RUNTM_CFG      (usbUART115200bps_SCB_MODE_UART      == usbUART115200bps_scbMode)
#define usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG     (usbUART115200bps_SCB_MODE_EZI2C     == usbUART115200bps_scbMode)
#define usbUART115200bps_SCB_MODE_UNCONFIG_RUNTM_CFG  (usbUART115200bps_SCB_MODE_UNCONFIG  == usbUART115200bps_scbMode)

/* Condition compilation depends on operation mode: unconfigured implies apply to all modes */
#define usbUART115200bps_SCB_MODE_I2C_CONST_CFG       (usbUART115200bps_SCB_MODE_I2C       == usbUART115200bps_SCB_MODE)
#define usbUART115200bps_SCB_MODE_SPI_CONST_CFG       (usbUART115200bps_SCB_MODE_SPI       == usbUART115200bps_SCB_MODE)
#define usbUART115200bps_SCB_MODE_UART_CONST_CFG      (usbUART115200bps_SCB_MODE_UART      == usbUART115200bps_SCB_MODE)
#define usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG     (usbUART115200bps_SCB_MODE_EZI2C     == usbUART115200bps_SCB_MODE)
#define usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG  (usbUART115200bps_SCB_MODE_UNCONFIG  == usbUART115200bps_SCB_MODE)

/* Condition compilation for includes */
#define usbUART115200bps_SCB_MODE_I2C_INC       (0u !=(usbUART115200bps_SCB_MODE_I2C       & usbUART115200bps_SCB_MODE))
#define usbUART115200bps_SCB_MODE_SPI_INC       (0u !=(usbUART115200bps_SCB_MODE_SPI       & usbUART115200bps_SCB_MODE))
#define usbUART115200bps_SCB_MODE_UART_INC      (0u !=(usbUART115200bps_SCB_MODE_UART      & usbUART115200bps_SCB_MODE))
#define usbUART115200bps_SCB_MODE_EZI2C_INC     (0u !=(usbUART115200bps_SCB_MODE_EZI2C     & usbUART115200bps_SCB_MODE))

/* Interrupts remove options */
#define usbUART115200bps_REMOVE_SCB_IRQ             (1u)
#define usbUART115200bps_SCB_IRQ_INTERNAL           (0u == usbUART115200bps_REMOVE_SCB_IRQ)

#define usbUART115200bps_REMOVE_UART_RX_WAKEUP_IRQ  (1u)
#define usbUART115200bps_UART_RX_WAKEUP_IRQ         (0u == usbUART115200bps_REMOVE_UART_RX_WAKEUP_IRQ)

/* SCB interrupt enum */
#define usbUART115200bps_SCB_INTR_MODE_NONE     (0u)
#define usbUART115200bps_SCB_INTR_MODE_INTERNAL (1u)
#define usbUART115200bps_SCB_INTR_MODE_EXTERNAL (2u)

/* Bootloader communication interface enable */
#define usbUART115200bps_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))


/***************************************
*       Includes
****************************************/

#include "usbUART115200bps_PINS.h"

#if(usbUART115200bps_SCB_IRQ_INTERNAL)
    #include "usbUART115200bps_SCB_IRQ.h"
#endif /* (usbUART115200bps_SCB_IRQ_INTERNAL) */

#if(usbUART115200bps_UART_RX_WAKEUP_IRQ)
    #include "usbUART115200bps_RX_WAKEUP_IRQ.h"
#endif /* (usbUART115200bps_UART_RX_WAKEUP_IRQ) */


/***************************************
*       Type Definitions
***************************************/

typedef struct
{
    uint8 enableState;
} usbUART115200bps_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* Start and Stop APIs */
void usbUART115200bps_Init(void);
void usbUART115200bps_Enable(void);
void usbUART115200bps_Start(void);
void usbUART115200bps_Stop(void);

/* Sleep and Wakeup APis */
void usbUART115200bps_Sleep(void);
void usbUART115200bps_Wakeup(void);

/* Customer interrupt handler */
void usbUART115200bps_SetCustomInterruptHandler(cyisraddress func);

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (usbUART115200bps_BTLDR_COMM_ENABLED)

    /* Bootloader Physical layer functions */
    void usbUART115200bps_CyBtldrCommStart(void);
    void usbUART115200bps_CyBtldrCommStop (void);
    void usbUART115200bps_CyBtldrCommReset(void);
    cystatus usbUART115200bps_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus usbUART115200bps_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    #if(CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps)
        #define CyBtldrCommStart    usbUART115200bps_CyBtldrCommStart
        #define CyBtldrCommStop     usbUART115200bps_CyBtldrCommStop
        #define CyBtldrCommReset    usbUART115200bps_CyBtldrCommReset
        #define CyBtldrCommWrite    usbUART115200bps_CyBtldrCommWrite
        #define CyBtldrCommRead     usbUART115200bps_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps) */

#endif /*defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps) || \
                                                     (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */

/* Interface to internal interrupt component */
#if(usbUART115200bps_SCB_IRQ_INTERNAL)
    #define usbUART115200bps_EnableInt()    usbUART115200bps_SCB_IRQ_Enable()
    #define usbUART115200bps_DisableInt()   usbUART115200bps_SCB_IRQ_Disable()
#endif /* (usbUART115200bps_SCB_IRQ_INTERNAL) */

/* Get interrupt cause */
#define usbUART115200bps_GetInterruptCause()    (usbUART115200bps_INTR_CAUSE_REG)

/* APIs to service INTR_RX register */
#define usbUART115200bps_SetRxInterruptMode(interruptMask)     usbUART115200bps_WRITE_INTR_RX_MASK(interruptMask)
#define usbUART115200bps_ClearRxInterruptSource(interruptMask) usbUART115200bps_CLEAR_INTR_RX(interruptMask)
#define usbUART115200bps_SetRxInterrupt(interruptMask)         usbUART115200bps_SET_INTR_RX(interruptMask)
#define usbUART115200bps_GetRxInterruptSource()                (usbUART115200bps_INTR_RX_REG)
#define usbUART115200bps_GetRxInterruptMode()                  (usbUART115200bps_INTR_RX_MASK_REG)
#define usbUART115200bps_GetRxInterruptSourceMasked()          (usbUART115200bps_INTR_RX_MASKED_REG)

/* APIs to service INTR_TX register */
#define usbUART115200bps_SetTxInterruptMode(interruptMask)     usbUART115200bps_WRITE_INTR_TX_MASK(interruptMask)
#define usbUART115200bps_ClearTxInterruptSource(interruptMask) usbUART115200bps_CLEAR_INTR_TX(interruptMask)
#define usbUART115200bps_SetTxInterrupt(interruptMask)         usbUART115200bps_SET_INTR_TX(interruptMask)
#define usbUART115200bps_GetTxInterruptSource()                (usbUART115200bps_INTR_TX_REG)
#define usbUART115200bps_GetTxInterruptMode()                  (usbUART115200bps_INTR_TX_MASK_REG)
#define usbUART115200bps_GetTxInterruptSourceMasked()          (usbUART115200bps_INTR_TX_MASKED_REG)

/* APIs to service INTR_MASTER register */
#define usbUART115200bps_SetMasterInterruptMode(interruptMask)    usbUART115200bps_WRITE_INTR_MASTER_MASK(interruptMask)
#define usbUART115200bps_ClearMasterInterruptSource(interruptMask) usbUART115200bps_CLEAR_INTR_MASTER(interruptMask)
#define usbUART115200bps_SetMasterInterrupt(interruptMask)         usbUART115200bps_SET_INTR_MASTER(interruptMask)
#define usbUART115200bps_GetMasterInterruptSource()                (usbUART115200bps_INTR_MASTER_REG)
#define usbUART115200bps_GetMasterInterruptMode()                  (usbUART115200bps_INTR_MASTER_MASK_REG)
#define usbUART115200bps_GetMasterInterruptSourceMasked()          (usbUART115200bps_INTR_MASTER_MASKED_REG)

/* APIs to service INTR_SLAVE register */
#define usbUART115200bps_SetSlaveInterruptMode(interruptMask)     usbUART115200bps_WRITE_INTR_SLAVE_MASK(interruptMask)
#define usbUART115200bps_ClearSlaveInterruptSource(interruptMask) usbUART115200bps_CLEAR_INTR_SLAVE(interruptMask)
#define usbUART115200bps_SetSlaveInterrupt(interruptMask)         usbUART115200bps_SET_INTR_SLAVE(interruptMask)
#define usbUART115200bps_GetSlaveInterruptSource()                (usbUART115200bps_INTR_SLAVE_REG)
#define usbUART115200bps_GetSlaveInterruptMode()                  (usbUART115200bps_INTR_SLAVE_MASK_REG)
#define usbUART115200bps_GetSlaveInterruptSourceMasked()          (usbUART115200bps_INTR_SLAVE_MASKED_REG)


/**********************************
*     Vars with External Linkage
**********************************/

extern uint8 usbUART115200bps_initVar;


/***************************************
*              Registers
***************************************/

#define usbUART115200bps_CTRL_REG               (*(reg32 *) usbUART115200bps_SCB__CTRL)
#define usbUART115200bps_CTRL_PTR               ( (reg32 *) usbUART115200bps_SCB__CTRL)

#define usbUART115200bps_STATUS_REG             (*(reg32 *) usbUART115200bps_SCB__STATUS)
#define usbUART115200bps_STATUS_PTR             ( (reg32 *) usbUART115200bps_SCB__STATUS)

#define usbUART115200bps_SPI_CTRL_REG           (*(reg32 *) usbUART115200bps_SCB__SPI_CTRL)
#define usbUART115200bps_SPI_CTRL_PTR           ( (reg32 *) usbUART115200bps_SCB__SPI_CTRL)

#define usbUART115200bps_SPI_STATUS_REG         (*(reg32 *) usbUART115200bps_SCB__SPI_STATUS)
#define usbUART115200bps_SPI_STATUS_PTR         ( (reg32 *) usbUART115200bps_SCB__SPI_STATUS)

#define usbUART115200bps_UART_CTRL_REG          (*(reg32 *) usbUART115200bps_SCB__UART_CTRL)
#define usbUART115200bps_UART_CTRL_PTR          ( (reg32 *) usbUART115200bps_SCB__UART_CTRL)

#define usbUART115200bps_UART_TX_CTRL_REG       (*(reg32 *) usbUART115200bps_SCB__UART_TX_CTRL)
#define usbUART115200bps_UART_TX_CTRL_PTR       ( (reg32 *) usbUART115200bps_SCB__UART_RX_CTRL)

#define usbUART115200bps_UART_RX_CTRL_REG       (*(reg32 *) usbUART115200bps_SCB__UART_RX_CTRL)
#define usbUART115200bps_UART_RX_CTRL_PTR       ( (reg32 *) usbUART115200bps_SCB__UART_RX_CTRL)

#define usbUART115200bps_UART_RX_STATUS_REG     (*(reg32 *) usbUART115200bps_SCB__UART_RX_STATUS)
#define usbUART115200bps_UART_RX_STATUS_PTR     ( (reg32 *) usbUART115200bps_SCB__UART_RX_STATUS)

#define usbUART115200bps_I2C_CTRL_REG           (*(reg32 *) usbUART115200bps_SCB__I2C_CTRL)
#define usbUART115200bps_I2C_CTRL_PTR           ( (reg32 *) usbUART115200bps_SCB__I2C_CTRL)

#define usbUART115200bps_I2C_STATUS_REG         (*(reg32 *) usbUART115200bps_SCB__I2C_STATUS)
#define usbUART115200bps_I2C_STATUS_PTR         ( (reg32 *) usbUART115200bps_SCB__I2C_STATUS)

#define usbUART115200bps_I2C_MASTER_CMD_REG     (*(reg32 *) usbUART115200bps_SCB__I2C_M_CMD)
#define usbUART115200bps_I2C_MASTER_CMD_PTR     ( (reg32 *) usbUART115200bps_SCB__I2C_M_CMD)

#define usbUART115200bps_I2C_SLAVE_CMD_REG      (*(reg32 *) usbUART115200bps_SCB__I2C_S_CMD)
#define usbUART115200bps_I2C_SLAVE_CMD_PTR      ( (reg32 *) usbUART115200bps_SCB__I2C_S_CMD)

#define usbUART115200bps_I2C_CFG_REG            (*(reg32 *) usbUART115200bps_SCB__I2C_CFG)
#define usbUART115200bps_I2C_CFG_PTR            ( (reg32 *) usbUART115200bps_SCB__I2C_CFG)

#define usbUART115200bps_TX_CTRL_REG            (*(reg32 *) usbUART115200bps_SCB__TX_CTRL)
#define usbUART115200bps_TX_CTRL_PTR            ( (reg32 *) usbUART115200bps_SCB__TX_CTRL)

#define usbUART115200bps_TX_FIFO_CTRL_REG       (*(reg32 *) usbUART115200bps_SCB__TX_FIFO_CTRL)
#define usbUART115200bps_TX_FIFO_CTRL_PTR       ( (reg32 *) usbUART115200bps_SCB__TX_FIFO_CTRL)

#define usbUART115200bps_TX_FIFO_STATUS_REG     (*(reg32 *) usbUART115200bps_SCB__TX_FIFO_STATUS)
#define usbUART115200bps_TX_FIFO_STATUS_PTR     ( (reg32 *) usbUART115200bps_SCB__TX_FIFO_STATUS)

#define usbUART115200bps_TX_FIFO_WR_REG         (*(reg32 *) usbUART115200bps_SCB__TX_FIFO_WR)
#define usbUART115200bps_TX_FIFO_WR_PTR         ( (reg32 *) usbUART115200bps_SCB__TX_FIFO_WR)

#define usbUART115200bps_RX_CTRL_REG            (*(reg32 *) usbUART115200bps_SCB__RX_CTRL)
#define usbUART115200bps_RX_CTRL_PTR            ( (reg32 *) usbUART115200bps_SCB__RX_CTRL)

#define usbUART115200bps_RX_FIFO_CTRL_REG       (*(reg32 *) usbUART115200bps_SCB__RX_FIFO_CTRL)
#define usbUART115200bps_RX_FIFO_CTRL_PTR       ( (reg32 *) usbUART115200bps_SCB__RX_FIFO_CTRL)

#define usbUART115200bps_RX_FIFO_STATUS_REG     (*(reg32 *) usbUART115200bps_SCB__RX_FIFO_STATUS)
#define usbUART115200bps_RX_FIFO_STATUS_PTR     ( (reg32 *) usbUART115200bps_SCB__RX_FIFO_STATUS)

#define usbUART115200bps_RX_MATCH_REG           (*(reg32 *) usbUART115200bps_SCB__RX_MATCH)
#define usbUART115200bps_RX_MATCH_PTR           ( (reg32 *) usbUART115200bps_SCB__RX_MATCH)

#define usbUART115200bps_RX_FIFO_RD_REG         (*(reg32 *) usbUART115200bps_SCB__RX_FIFO_RD)
#define usbUART115200bps_RX_FIFO_RD_PTR         ( (reg32 *) usbUART115200bps_SCB__RX_FIFO_RD)

#define usbUART115200bps_RX_FIFO_RD_SILENT_REG  (*(reg32 *) usbUART115200bps_SCB__RX_FIFO_RD_SILENT)
#define usbUART115200bps_RX_FIFO_RD_SILENT_PTR  ( (reg32 *) usbUART115200bps_SCB__RX_FIFO_RD_SILENT)

#define usbUART115200bps_EZBUF_DATA00_REG       (*(reg32 *) usbUART115200bps_SCB__EZ_DATA00)
#define usbUART115200bps_EZBUF_DATA00_PTR       ( (reg32 *) usbUART115200bps_SCB__EZ_DATA00)

#define usbUART115200bps_INTR_CAUSE_REG         (*(reg32 *) usbUART115200bps_SCB__INTR_CAUSE)
#define usbUART115200bps_INTR_CAUSE_PTR         ( (reg32 *) usbUART115200bps_SCB__INTR_CAUSE)

#define usbUART115200bps_INTR_I2C_EC_REG        (*(reg32 *) usbUART115200bps_SCB__INTR_I2C_EC)
#define usbUART115200bps_INTR_I2C_EC_PTR        ( (reg32 *) usbUART115200bps_SCB__INTR_I2C_EC)

#define usbUART115200bps_INTR_I2C_EC_MASK_REG   (*(reg32 *) usbUART115200bps_SCB__INTR_I2C_EC_MASK)
#define usbUART115200bps_INTR_I2C_EC_MASK_PTR   ( (reg32 *) usbUART115200bps_SCB__INTR_I2C_EC_MASK)

#define usbUART115200bps_INTR_I2C_EC_MASKED_REG (*(reg32 *) usbUART115200bps_SCB__INTR_I2C_EC_MASKED)
#define usbUART115200bps_INTR_I2C_EC_MASKED_PTR ( (reg32 *) usbUART115200bps_SCB__INTR_I2C_EC_MASKED)

#define usbUART115200bps_INTR_SPI_EC_REG        (*(reg32 *) usbUART115200bps_SCB__INTR_SPI_EC)
#define usbUART115200bps_INTR_SPI_EC_PTR        ( (reg32 *) usbUART115200bps_SCB__INTR_SPI_EC)

#define usbUART115200bps_INTR_SPI_EC_MASK_REG   (*(reg32 *) usbUART115200bps_SCB__INTR_SPI_EC_MASK)
#define usbUART115200bps_INTR_SPI_EC_MASK_PTR   ( (reg32 *) usbUART115200bps_SCB__INTR_SPI_EC_MASK)

#define usbUART115200bps_INTR_SPI_EC_MASKED_REG (*(reg32 *) usbUART115200bps_SCB__INTR_SPI_EC_MASKED)
#define usbUART115200bps_INTR_SPI_EC_MASKED_PTR ( (reg32 *) usbUART115200bps_SCB__INTR_SPI_EC_MASKED)

#define usbUART115200bps_INTR_MASTER_REG        (*(reg32 *) usbUART115200bps_SCB__INTR_M)
#define usbUART115200bps_INTR_MASTER_PTR        ( (reg32 *) usbUART115200bps_SCB__INTR_M)

#define usbUART115200bps_INTR_MASTER_SET_REG    (*(reg32 *) usbUART115200bps_SCB__INTR_M_SET)
#define usbUART115200bps_INTR_MASTER_SET_PTR    ( (reg32 *) usbUART115200bps_SCB__INTR_M_SET)

#define usbUART115200bps_INTR_MASTER_MASK_REG   (*(reg32 *) usbUART115200bps_SCB__INTR_M_MASK)
#define usbUART115200bps_INTR_MASTER_MASK_PTR   ( (reg32 *) usbUART115200bps_SCB__INTR_M_MASK)

#define usbUART115200bps_INTR_MASTER_MASKED_REG (*(reg32 *) usbUART115200bps_SCB__INTR_M_MASKED)
#define usbUART115200bps_INTR_MASTER_MASKED_PTR ( (reg32 *) usbUART115200bps_SCB__INTR_M_MASKED)

#define usbUART115200bps_INTR_SLAVE_REG         (*(reg32 *) usbUART115200bps_SCB__INTR_S)
#define usbUART115200bps_INTR_SLAVE_PTR         ( (reg32 *) usbUART115200bps_SCB__INTR_S)

#define usbUART115200bps_INTR_SLAVE_SET_REG     (*(reg32 *) usbUART115200bps_SCB__INTR_S_SET)
#define usbUART115200bps_INTR_SLAVE_SET_PTR     ( (reg32 *) usbUART115200bps_SCB__INTR_S_SET)

#define usbUART115200bps_INTR_SLAVE_MASK_REG    (*(reg32 *) usbUART115200bps_SCB__INTR_S_MASK)
#define usbUART115200bps_INTR_SLAVE_MASK_PTR    ( (reg32 *) usbUART115200bps_SCB__INTR_S_MASK)

#define usbUART115200bps_INTR_SLAVE_MASKED_REG  (*(reg32 *) usbUART115200bps_SCB__INTR_S_MASKED)
#define usbUART115200bps_INTR_SLAVE_MASKED_PTR  ( (reg32 *) usbUART115200bps_SCB__INTR_S_MASKED)

#define usbUART115200bps_INTR_TX_REG            (*(reg32 *) usbUART115200bps_SCB__INTR_TX)
#define usbUART115200bps_INTR_TX_PTR            ( (reg32 *) usbUART115200bps_SCB__INTR_TX)

#define usbUART115200bps_INTR_TX_SET_REG        (*(reg32 *) usbUART115200bps_SCB__INTR_TX_SET)
#define usbUART115200bps_INTR_TX_SET_PTR        ( (reg32 *) usbUART115200bps_SCB__INTR_TX_SET)

#define usbUART115200bps_INTR_TX_MASK_REG       (*(reg32 *) usbUART115200bps_SCB__INTR_TX_MASK)
#define usbUART115200bps_INTR_TX_MASK_PTR       ( (reg32 *) usbUART115200bps_SCB__INTR_TX_MASK)

#define usbUART115200bps_INTR_TX_MASKED_REG     (*(reg32 *) usbUART115200bps_SCB__INTR_TX_MASKED)
#define usbUART115200bps_INTR_TX_MASKED_PTR     ( (reg32 *) usbUART115200bps_SCB__INTR_TX_MASKED)

#define usbUART115200bps_INTR_RX_REG            (*(reg32 *) usbUART115200bps_SCB__INTR_RX)
#define usbUART115200bps_INTR_RX_PTR            ( (reg32 *) usbUART115200bps_SCB__INTR_RX)

#define usbUART115200bps_INTR_RX_SET_REG        (*(reg32 *) usbUART115200bps_SCB__INTR_RX_SET)
#define usbUART115200bps_INTR_RX_SET_PTR        ( (reg32 *) usbUART115200bps_SCB__INTR_RX_SET)

#define usbUART115200bps_INTR_RX_MASK_REG       (*(reg32 *) usbUART115200bps_SCB__INTR_RX_MASK)
#define usbUART115200bps_INTR_RX_MASK_PTR       ( (reg32 *) usbUART115200bps_SCB__INTR_RX_MASK)

#define usbUART115200bps_INTR_RX_MASKED_REG     (*(reg32 *) usbUART115200bps_SCB__INTR_RX_MASKED)
#define usbUART115200bps_INTR_RX_MASKED_PTR     ( (reg32 *) usbUART115200bps_SCB__INTR_RX_MASKED)


/***************************************
*        Registers Constants
***************************************/

/* usbUART115200bps_CTRL */
#define usbUART115200bps_CTRL_OVS_POS           (0u)  /* [3:0]   Oversampling factor                 */
#define usbUART115200bps_CTRL_EC_AM_MODE_POS    (8u)  /* [8]     Externally clocked address match    */
#define usbUART115200bps_CTRL_EC_OP_MODE_POS    (9u)  /* [9]     Externally clocked operation mode   */
#define usbUART115200bps_CTRL_EZBUF_MODE_POS    (10u) /* [10]    EZ buffer is enabled                */
#define usbUART115200bps_CTRL_ADDR_ACCEPT_POS   (16u) /* [16]    Put matched address in RX FIFO      */
#define usbUART115200bps_CTRL_BLOCK_POS         (17u) /* [17]    Ext and Int logic to resolve colide */
#define usbUART115200bps_CTRL_MODE_POS          (24u) /* [25:24] Operation mode                      */
#define usbUART115200bps_CTRL_ENABLED_POS       (31u) /* [31]    Enable SCB block                    */
#define usbUART115200bps_CTRL_OVS_MASK          ((uint32) 0x0Fu)
#define usbUART115200bps_CTRL_EC_AM_MODE        ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_EC_AM_MODE_POS))
#define usbUART115200bps_CTRL_EC_OP_MODE        ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_EC_OP_MODE_POS))
#define usbUART115200bps_CTRL_EZBUF_MODE        ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_EZBUF_MODE_POS))
#define usbUART115200bps_CTRL_ADDR_ACCEPT       ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_ADDR_ACCEPT_POS))
#define usbUART115200bps_CTRL_BLOCK             ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_BLOCK_POS))
#define usbUART115200bps_CTRL_MODE_MASK         ((uint32) ((uint32) 0x03u << usbUART115200bps_CTRL_MODE_POS))
#define usbUART115200bps_CTRL_MODE_I2C          ((uint32)  0x00u)
#define usbUART115200bps_CTRL_MODE_SPI          ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_MODE_POS))
#define usbUART115200bps_CTRL_MODE_UART         ((uint32) ((uint32) 0x02u << usbUART115200bps_CTRL_MODE_POS))
#define usbUART115200bps_CTRL_ENABLED           ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_ENABLED_POS))


/* usbUART115200bps_STATUS_REG */
#define usbUART115200bps_STATUS_EC_BUSY_POS     (0u)  /* [0] Bus busy. Externaly clocked loigc access to EZ memory */
#define usbUART115200bps_STATUS_EC_BUSY         ((uint32) 0x0Fu)


/* usbUART115200bps_SPI_CTRL_REG  */
#define usbUART115200bps_SPI_CTRL_CONTINUOUS_POS        (0u)  /* [0]     Continuous or Separated SPI data transfers */
#define usbUART115200bps_SPI_CTRL_SELECT_PRECEDE_POS    (1u)  /* [1]     Precedes or coincides start of data frame  */
#define usbUART115200bps_SPI_CTRL_CPHA_POS              (2u)  /* [2]     SCLK phase                                 */
#define usbUART115200bps_SPI_CTRL_CPOL_POS              (3u)  /* [3]     SCLK polarity                              */
#define usbUART115200bps_SPI_CTRL_LATE_MISO_SAMPLE_POS  (4u)  /* [4]     Late MISO sample enabled                   */
#define usbUART115200bps_SPI_CTRL_LOOPBACK_POS          (16u) /* [16]    Local loopback control enabled             */
#define usbUART115200bps_SPI_CTRL_MODE_POS              (24u) /* [25:24] Submode of SPI operation                   */
#define usbUART115200bps_SPI_CTRL_SLAVE_SELECT_POS      (26u) /* [27:26] Selects SPI SS signal                      */
#define usbUART115200bps_SPI_CTRL_MASTER_MODE_POS       (31u) /* [31]    Master mode enabled                        */
#define usbUART115200bps_SPI_CTRL_CONTINUOUS            ((uint32) 0x01u)
#define usbUART115200bps_SPI_CTRL_SELECT_PRECEDE        ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_SPI_CTRL_SELECT_PRECEDE_POS))
#define usbUART115200bps_SPI_CTRL_SCLK_MODE_MASK        ((uint32) ((uint32) 0x03u << \
                                                                    usbUART115200bps_SPI_CTRL_CPHA_POS))
#define usbUART115200bps_SPI_CTRL_CPHA                  ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_SPI_CTRL_CPHA_POS))
#define usbUART115200bps_SPI_CTRL_CPOL                  ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_SPI_CTRL_CPOL_POS))
#define usbUART115200bps_SPI_CTRL_LATE_MISO_SAMPLE      ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_SPI_CTRL_LATE_MISO_SAMPLE_POS))
#define usbUART115200bps_SPI_CTRL_LOOPBACK              ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_SPI_CTRL_LOOPBACK_POS))
#define usbUART115200bps_SPI_CTRL_MODE_MASK             ((uint32) ((uint32) 0x03u << \
                                                                    usbUART115200bps_SPI_CTRL_MODE_POS))
#define usbUART115200bps_SPI_CTRL_MODE_MOTOROLA         ((uint32) 0x00u)
#define usbUART115200bps_SPI_CTRL_MODE_TI               ((uint32) ((uint32) 0x01u << usbUART115200bps_CTRL_MODE_POS))
#define usbUART115200bps_SPI_CTRL_MODE_NS               ((uint32) ((uint32) 0x02u << usbUART115200bps_CTRL_MODE_POS))
#define usbUART115200bps_SPI_CTRL_SLAVE_SELECT_MASK     ((uint32) ((uint32) 0x03u << \
                                                                    usbUART115200bps_SPI_CTRL_SLAVE_SELECT_POS))
#define usbUART115200bps_SPI_CTRL_SLAVE_SELECT0         ((uint32) 0x00u)
#define usbUART115200bps_SPI_CTRL_SLAVE_SELECT1         ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_SPI_CTRL_SLAVE_SELECT_POS))
#define usbUART115200bps_SPI_CTRL_SLAVE_SELECT2         ((uint32) ((uint32) 0x02u << \
                                                                    usbUART115200bps_SPI_CTRL_SLAVE_SELECT_POS))
#define usbUART115200bps_SPI_CTRL_SLAVE_SELECT3         ((uint32) ((uint32) 0x03u << \
                                                                    usbUART115200bps_SPI_CTRL_SLAVE_SELECT_POS))
#define usbUART115200bps_SPI_CTRL_MASTER                ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_SPI_CTRL_MASTER_MODE_POS))
#define usbUART115200bps_SPI_CTRL_SLAVE                 ((uint32) 0x00u)


/* usbUART115200bps_SPI_STATUS_REG  */
#define usbUART115200bps_SPI_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy - slave selected */
#define usbUART115200bps_SPI_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EzAddress                 */
#define usbUART115200bps_SPI_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define usbUART115200bps_SPI_STATUS_EZBUF_ADDR_MASK    ((uint32) ((uint32) 0xFFu << \
                                                                    usbUART115200bps_I2C_STATUS_EZBUF_ADDR_POS))


/* usbUART115200bps_UART_CTRL */
#define usbUART115200bps_UART_CTRL_LOOPBACK_POS         (16u) /* [16] Loopback     */
#define usbUART115200bps_UART_CTRL_MODE_POS             (24u) /* [24] UART subMode */
#define usbUART115200bps_UART_CTRL_LOOPBACK             ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_UART_CTRL_LOOPBACK_POS))
#define usbUART115200bps_UART_CTRL_MODE_UART_STD        ((uint32) 0x00u)
#define usbUART115200bps_UART_CTRL_MODE_UART_SMARTCARD  ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_UART_CTRL_MODE_POS))
#define usbUART115200bps_UART_CTRL_MODE_UART_IRDA       ((uint32) ((uint32) 0x02u << \
                                                                        usbUART115200bps_UART_CTRL_MODE_POS))
#define usbUART115200bps_UART_CTRL_MODE_MASK            ((uint32) ((uint32) 0x03u << \
                                                                        usbUART115200bps_UART_CTRL_MODE_POS))


/* usbUART115200bps_UART_TX_CTRL */
#define usbUART115200bps_UART_TX_CTRL_STOP_BITS_POS         (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 period */
#define usbUART115200bps_UART_TX_CTRL_PARITY_POS            (4u)  /* [4]   Parity bit                              */
#define usbUART115200bps_UART_TX_CTRL_PARITY_ENABLED_POS    (5u)  /* [5]   Parity enable                           */
#define usbUART115200bps_UART_TX_CTRL_RETRY_ON_NACK_POS     (8u)  /* [8]   Smart Card: re-send frame on NACK       */
#define usbUART115200bps_UART_TX_CTRL_ONE_STOP_BIT          ((uint32) 0x01u)
#define usbUART115200bps_UART_TX_CTRL_ONE_HALF_STOP_BITS    ((uint32) 0x02u)
#define usbUART115200bps_UART_TX_CTRL_TWO_STOP_BITS         ((uint32) 0x03u)
#define usbUART115200bps_UART_TX_CTRL_STOP_BITS_MASK        ((uint32) 0x07u)
#define usbUART115200bps_UART_TX_CTRL_PARITY                ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_TX_CTRL_PARITY_POS))
#define usbUART115200bps_UART_TX_CTRL_PARITY_ENABLED        ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_TX_CTRL_PARITY_ENABLED_POS))
#define usbUART115200bps_UART_TX_CTRL_RETRY_ON_NACK         ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_TX_CTRL_RETRY_ON_NACK_POS))


/* usbUART115200bps_UART_RX_CTRL */
#define usbUART115200bps_UART_RX_CTRL_STOP_BITS_POS             (0u)  /* [2:0] Stop bits: (Stop bits + 1) * 0.5 prd   */
#define usbUART115200bps_UART_RX_CTRL_PARITY_POS                (4u)  /* [4]   Parity bit                             */
#define usbUART115200bps_UART_RX_CTRL_PARITY_ENABLED_POS        (5u)  /* [5]   Parity enable                          */
#define usbUART115200bps_UART_RX_CTRL_POLARITY_POS              (6u)  /* [6]   IrDA: inverts polarity of RX signal    */
#define usbUART115200bps_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS    (8u)  /* [8]   Drop and lost RX FIFO on parity error  */
#define usbUART115200bps_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS     (9u)  /* [9]   Drop and lost RX FIFO on frame error   */
#define usbUART115200bps_UART_RX_CTRL_MP_MODE_POS               (10u) /* [10]  Multi-processor mode                   */
#define usbUART115200bps_UART_RX_CTRL_LIN_MODE_POS              (12u) /* [12]  Lin mode: applicable for UART Standart */
#define usbUART115200bps_UART_RX_CTRL_SKIP_START_POS            (13u) /* [13]  Skip start not: only for UART Standart */
#define usbUART115200bps_UART_RX_CTRL_BREAK_WIDTH_POS           (16u) /* [19:16]  Break width: (Break width + 1)      */
#define usbUART115200bps_UART_TX_CTRL_ONE_STOP_BIT              ((uint32) 0x01u)
#define usbUART115200bps_UART_TX_CTRL_ONE_HALF_STOP_BITS        ((uint32) 0x02u)
#define usbUART115200bps_UART_TX_CTRL_TWO_STOP_BITS             ((uint32) 0x03u)
#define usbUART115200bps_UART_RX_CTRL_STOP_BITS_MASK            ((uint32) 0x07u)
#define usbUART115200bps_UART_RX_CTRL_PARITY                    ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_RX_CTRL_PARITY_POS))
#define usbUART115200bps_UART_RX_CTRL_PARITY_ENABLED            ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_RX_CTRL_PARITY_ENABLED_POS))
#define usbUART115200bps_UART_RX_CTRL_POLARITY                  ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_RX_CTRL_POLARITY_POS))
#define usbUART115200bps_UART_RX_CTRL_DROP_ON_PARITY_ERR        ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_UART_RX_CTRL_DROP_ON_PARITY_ERR_POS))
#define usbUART115200bps_UART_RX_CTRL_DROP_ON_FRAME_ERR         ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_UART_RX_CTRL_DROP_ON_FRAME_ERR_POS))
#define usbUART115200bps_UART_RX_CTRL_MP_MODE                   ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_RX_CTRL_MP_MODE_POS))
#define usbUART115200bps_UART_RX_CTRL_LIN_MODE                  ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_UART_RX_CTRL_LIN_MODE_POS))
#define usbUART115200bps_UART_RX_CTRL_SKIP_START                ((uint32) ((uint32) 0x01u << \
                                                                  usbUART115200bps_UART_RX_CTRL_SKIP_START_POS))
#define usbUART115200bps_UART_RX_CTRL_BREAK_WIDTH_MASK          ((uint32) ((uint32) 0x0Fu << \
                                                                  usbUART115200bps_UART_RX_CTRL_BREAK_WIDTH_POS))

/* usbUART115200bps_UART_RX_STATUS_REG */
#define usbUART115200bps_UART_RX_STATUS_BR_COUNTER_POS     (0u)  /* [11:0] Baute Rate counter */
#define usbUART115200bps_UART_RX_STATUS_BR_COUNTER_MASK    ((uint32) 0xFFFu)


/* usbUART115200bps_I2C_CTRL */
#define usbUART115200bps_I2C_CTRL_HIGH_PHASE_OVS_POS           (0u)   /* [3:0] Oversampling factor high: masrer only */
#define usbUART115200bps_I2C_CTRL_LOW_PHASE_OVS_POS            (4u)   /* [7:4] Oversampling factor low:  masrer only */
#define usbUART115200bps_I2C_CTRL_M_READY_DATA_ACK_POS         (8u)   /* [8]   Master ACKs data wgile RX FIFO != FULL*/
#define usbUART115200bps_I2C_CTRL_M_NOT_READY_DATA_NACK_POS    (9u)   /* [9]   Master NACKs data if RX FIFO ==  FULL */
#define usbUART115200bps_I2C_CTRL_S_GENERAL_IGNORE_POS         (11u)  /* [11]  Slave ignores General call            */
#define usbUART115200bps_I2C_CTRL_S_READY_ADDR_ACK_POS         (12u)  /* [12]  Slave ACKs Address if RX FIFO != FULL */
#define usbUART115200bps_I2C_CTRL_S_READY_DATA_ACK_POS         (13u)  /* [13]  Slave ACKs data while RX FIFO == FULL */
#define usbUART115200bps_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS    (14u)  /* [14]  Slave NACKs address if RX FIFO == FULL*/
#define usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK_POS    (15u)  /* [15]  Slave NACKs data if RX FIFO is  FULL  */
#define usbUART115200bps_I2C_CTRL_LOOPBACK_POS                 (16u)  /* [16]  Loopback                              */
#define usbUART115200bps_I2C_CTRL_SLAVE_MODE_POS               (30u)  /* [30]  Slave mode enabled                    */
#define usbUART115200bps_I2C_CTRL_MASTER_MODE_POS              (31u)  /* [31]  Master mode enabled                   */
#define usbUART115200bps_I2C_CTRL_HIGH_PHASE_OVS_MASK  ((uint32) 0x0Fu)
#define usbUART115200bps_I2C_CTRL_LOW_PHASE_OVS_MASK   ((uint32) ((uint32) 0x0Fu << \
                                                                usbUART115200bps_I2C_CTRL_LOW_PHASE_OVS_POS))
#define usbUART115200bps_I2C_CTRL_M_READY_DATA_ACK      ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_M_READY_DATA_ACK_POS))
#define usbUART115200bps_I2C_CTRL_M_NOT_READY_DATA_NACK ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_M_NOT_READY_DATA_NACK_POS))
#define usbUART115200bps_I2C_CTRL_S_GENERAL_IGNORE      ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_S_GENERAL_IGNORE_POS))
#define usbUART115200bps_I2C_CTRL_S_READY_ADDR_ACK      ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_S_READY_ADDR_ACK_POS))
#define usbUART115200bps_I2C_CTRL_S_READY_DATA_ACK      ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_S_READY_DATA_ACK_POS))
#define usbUART115200bps_I2C_CTRL_S_NOT_READY_ADDR_NACK ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_S_NOT_READY_ADDR_NACK_POS))
#define usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK_POS))
#define usbUART115200bps_I2C_CTRL_LOOPBACK              ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_LOOPBACK_POS))
#define usbUART115200bps_I2C_CTRL_SLAVE_MODE            ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_SLAVE_MODE_POS))
#define usbUART115200bps_I2C_CTRL_MASTER_MODE           ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CTRL_MASTER_MODE_POS))
#define usbUART115200bps_I2C_CTRL_SLAVE_MASTER_MODE_MASK    ((uint32) ((uint32) 0x03u << \
                                                                usbUART115200bps_I2C_CTRL_SLAVE_MODE_POS))


/* usbUART115200bps_I2C_STATUS_REG  */
#define usbUART115200bps_I2C_STATUS_BUS_BUSY_POS    (0u)  /* [0]    Bus busy: internally clocked */
#define usbUART115200bps_I2C_STATUS_S_READ_POS      (4u)  /* [4]    Slave is read by master      */
#define usbUART115200bps_I2C_STATUS_M_READ_POS      (5u)  /* [5]    Master reads Slave           */
#define usbUART115200bps_I2C_STATUS_EZBUF_ADDR_POS  (8u)  /* [15:8] EZAddress                    */
#define usbUART115200bps_I2C_STATUS_BUS_BUSY        ((uint32) 0x01u)
#define usbUART115200bps_I2C_STATUS_S_READ          ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_I2C_STATUS_S_READ_POS))
#define usbUART115200bps_I2C_STATUS_M_READ          ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_I2C_STATUS_M_READ_POS))
#define usbUART115200bps_I2C_STATUS_EZBUF_ADDR_MASK ((uint32) ((uint32) 0xFFu << \
                                                                    usbUART115200bps_I2C_STATUS_EZBUF_ADDR_POS))


/* usbUART115200bps_I2C_MASTER_CMD_REG */
#define usbUART115200bps_I2C_MASTER_CMD_M_START_POS             (0u)  /* [0] Master generate Start                */
#define usbUART115200bps_I2C_MASTER_CMD_M_START_ON_IDLE_POS     (1u)  /* [1] Master generate Start if bus is free */
#define usbUART115200bps_I2C_MASTER_CMD_M_ACK_POS               (2u)  /* [2] Master generate ACK                  */
#define usbUART115200bps_I2C_MASTER_CMD_M_NACK_POS              (3u)  /* [3] Master generate NACK                 */
#define usbUART115200bps_I2C_MASTER_CMD_M_STOP_POS              (4u)  /* [4] Master generate Stop                 */
#define usbUART115200bps_I2C_MASTER_CMD_M_START         ((uint32) 0x01u)
#define usbUART115200bps_I2C_MASTER_CMD_M_START_ON_IDLE ((uint32) ((uint32) 0x01u << \
                                                                   usbUART115200bps_I2C_MASTER_CMD_M_START_ON_IDLE_POS))
#define usbUART115200bps_I2C_MASTER_CMD_M_ACK           ((uint32) ((uint32) 0x01u << \
                                                                   usbUART115200bps_I2C_MASTER_CMD_M_ACK_POS))
#define usbUART115200bps_I2C_MASTER_CMD_M_NACK          ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_I2C_MASTER_CMD_M_NACK_POS))
#define usbUART115200bps_I2C_MASTER_CMD_M_STOP          ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_I2C_MASTER_CMD_M_STOP_POS))


/* usbUART115200bps_I2C_SLAVE_CMD_REG  */
#define usbUART115200bps_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define usbUART115200bps_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define usbUART115200bps_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define usbUART115200bps_I2C_SLAVE_CMD_S_NACK       ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_SLAVE_CMD_S_NACK_POS))

#define usbUART115200bps_I2C_SLAVE_CMD_S_ACK_POS    (0u)  /* [0] Slave generate ACK  */
#define usbUART115200bps_I2C_SLAVE_CMD_S_NACK_POS   (1u)  /* [1] Slave generate NACK */
#define usbUART115200bps_I2C_SLAVE_CMD_S_ACK        ((uint32) 0x01u)
#define usbUART115200bps_I2C_SLAVE_CMD_S_NACK       ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_SLAVE_CMD_S_NACK_POS))
/* usbUART115200bps_I2C_CFG  */
#define usbUART115200bps_I2C_CFG_SDA_FILT_HYS_POS           (0u)  /* [1:0]   Trim bits for the I2C SDA filter         */
#define usbUART115200bps_I2C_CFG_SDA_FILT_TRIM_POS          (2u)  /* [3:2]   Trim bits for the I2C SDA filter         */
#define usbUART115200bps_I2C_CFG_SCL_FILT_HYS_POS           (4u)  /* [5:4]   Trim bits for the I2C SCL filter         */
#define usbUART115200bps_I2C_CFG_SCL_FILT_TRIM_POS          (6u)  /* [7:6]   Trim bits for the I2C SCL filter         */
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_HYS_POS       (8u)  /* [9:8]   Trim bits for I2C SDA filter output path */
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_TRIM_POS      (10u) /* [11:10] Trim bits for I2C SDA filter output path */
#define usbUART115200bps_I2C_CFG_SDA_FILT_HS_POS            (16u) /* [16]    '0': 50 ns filter, '1': 10 ns filter     */
#define usbUART115200bps_I2C_CFG_SDA_FILT_ENABLED_POS       (17u) /* [17]    I2C SDA filter enabled                   */
#define usbUART115200bps_I2C_CFG_SCL_FILT_HS_POS            (24u) /* [24]    '0': 50 ns filter, '1': 10 ns filter     */
#define usbUART115200bps_I2C_CFG_SCL_FILT_ENABLED_POS       (25u) /* [25]    I2C SCL filter enabled                   */
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_HS_POS        (26u) /* [26]    '0': 50ns filter, '1': 10 ns filter      */
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_ENABLED_POS   (27u) /* [27]    I2C SDA output delay filter enabled      */
#define usbUART115200bps_I2C_CFG_SDA_FILT_HYS_MASK          ((uint32) 0x00u)
#define usbUART115200bps_I2C_CFG_SDA_FILT_TRIM_MASK         ((uint32) ((uint32) 0x03u << \
                                                                usbUART115200bps_I2C_CFG_SDA_FILT_TRIM_POS))
#define usbUART115200bps_I2C_CFG_SCL_FILT_HYS_MASK          ((uint32) ((uint32) 0x03u << \
                                                                usbUART115200bps_I2C_CFG_SCL_FILT_HYS_POS))
#define usbUART115200bps_I2C_CFG_SCL_FILT_TRIM_MASK         ((uint32) ((uint32) 0x03u << \
                                                                usbUART115200bps_I2C_CFG_SCL_FILT_TRIM_POS))
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_HYS_MASK      ((uint32) ((uint32) 0x03u << \
                                                                usbUART115200bps_I2C_CFG_SDA_FILT_OUT_HYS_POS))
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_TRIM_MASK     ((uint32) ((uint32) 0x03u << \
                                                                usbUART115200bps_I2C_CFG_SDA_FILT_OUT_TRIM_POS))
#define usbUART115200bps_I2C_CFG_SDA_FILT_HS                ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CFG_SDA_FILT_HS_POS))
#define usbUART115200bps_I2C_CFG_SDA_FILT_ENABLED           ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CFG_SDA_FILT_ENABLED_POS))
#define usbUART115200bps_I2C_CFG_SCL_FILT_HS                ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CFG_SCL_FILT_HS_POS))
#define usbUART115200bps_I2C_CFG_SCL_FILT_ENABLED           ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CFG_SCL_FILT_ENABLED_POS))
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_HS            ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CFG_SDA_FILT_OUT_HS_POS))
#define usbUART115200bps_I2C_CFG_SDA_FILT_OUT_ENABLED       ((uint32) ((uint32) 0x01u << \
                                                                usbUART115200bps_I2C_CFG_SDA_FILT_OUT_ENABLED_POS))


/* usbUART115200bps_TX_CTRL_REG */
#define usbUART115200bps_TX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Dataframe width: (Data width - 1) */
#define usbUART115200bps_TX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define usbUART115200bps_TX_CTRL_ENABLED_POS        (31u) /* [31]  Transmitter enabled               */
#define usbUART115200bps_TX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define usbUART115200bps_TX_CTRL_MSB_FIRST          ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_TX_CTRL_MSB_FIRST_POS))
#define usbUART115200bps_TX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define usbUART115200bps_TX_CTRL_ENABLED            ((uint32) ((uint32) 0x01u << usbUART115200bps_TX_CTRL_ENABLED_POS))


/* usbUART115200bps_TX_CTRL_FIFO_REG */
#define usbUART115200bps_TX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)  /* [2:0] Trigger level                              */
#define usbUART115200bps_TX_FIFO_CTRL_CLEAR_POS             (16u) /* [16]  Clear TX FIFO: claared after set           */
#define usbUART115200bps_TX_FIFO_CTRL_FREEZE_POS            (17u) /* [17]  Freeze TX FIFO: HW do not inc read pointer */
#define usbUART115200bps_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) 0x07u)
#define usbUART115200bps_TX_FIFO_CTRL_CLEAR                 ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_TX_FIFO_CTRL_CLEAR_POS))
#define usbUART115200bps_TX_FIFO_CTRL_FREEZE                ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_TX_FIFO_CTRL_FREEZE_POS))


/* usbUART115200bps_TX_FIFO_STATUS_REG */
#define usbUART115200bps_TX_FIFO_STATUS_USED_POS    (0u)  /* [3:0]   Amount of entries in TX FIFO */
#define usbUART115200bps_TX_FIFO_SR_VALID_POS       (15u) /* [15]    Shifter status of TX FIFO    */
#define usbUART115200bps_TX_FIFO_STATUS_RD_PTR_POS  (16u) /* [18:16] TX FIFO read pointer         */
#define usbUART115200bps_TX_FIFO_STATUS_WR_PTR_POS  (24u) /* [26:24] TX FIFO write pointer        */
#define usbUART115200bps_TX_FIFO_STATUS_USED_MASK   ((uint32) 0x0Fu)
#define usbUART115200bps_TX_FIFO_SR_VALID           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_TX_FIFO_SR_VALID_POS))
#define usbUART115200bps_TX_FIFO_STATUS_RD_PTR_MASK ((uint32) ((uint32) 0x07u << \
                                                                    usbUART115200bps_TX_FIFO_STATUS_RD_PTR_POS))
#define usbUART115200bps_TX_FIFO_STATUS_WR_PTR_MASK ((uint32) ((uint32) 0x07u << \
                                                                    usbUART115200bps_TX_FIFO_STATUS_WR_PTR_POS))


/* usbUART115200bps_TX_FIFO_WR_REG */
#define usbUART115200bps_TX_FIFO_WR_POS    (0u)  /* [15:0] Data written into TX FIFO */
#define usbUART115200bps_TX_FIFO_WR_MASK   ((uint32) 0xFFu)


/* usbUART115200bps_RX_CTRL_REG */
#define usbUART115200bps_RX_CTRL_DATA_WIDTH_POS     (0u)  /* [3:0] Dataframe width: (Data width - 1) */
#define usbUART115200bps_RX_CTRL_MSB_FIRST_POS      (8u)  /* [8]   MSB first shifter-out             */
#define usbUART115200bps_RX_CTRL_MEDIAN_POS         (9u)  /* [9]   Median filter                     */
#define usbUART115200bps_RX_CTRL_ENABLED_POS        (31u) /* [31]  Receiver enabled                  */
#define usbUART115200bps_RX_CTRL_DATA_WIDTH_MASK    ((uint32) 0x0Fu)
#define usbUART115200bps_RX_CTRL_MSB_FIRST          ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_RX_CTRL_MSB_FIRST_POS))
#define usbUART115200bps_RX_CTRL_LSB_FIRST          ((uint32) 0x00u)
#define usbUART115200bps_RX_CTRL_MEDIAN             ((uint32) ((uint32) 0x01u << usbUART115200bps_RX_CTRL_MEDIAN_POS))
#define usbUART115200bps_RX_CTRL_ENABLED            ((uint32) ((uint32) 0x01u << usbUART115200bps_RX_CTRL_ENABLED_POS))


/* usbUART115200bps_RX_FIFO_CTRL_REG */
#define usbUART115200bps_RX_FIFO_CTRL_TRIGGER_LEVEL_POS     (0u)   /* [2:0] Trigger level                            */
#define usbUART115200bps_RX_FIFO_CTRL_CLEAR_POS             (16u)  /* [16]  Clear RX FIFO: claar after set           */
#define usbUART115200bps_RX_FIFO_CTRL_FREEZE_POS            (17u)  /* [17]  Freeze RX FIFO: HW writes has not effect */
#define usbUART115200bps_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK    ((uint32) 0x07u)
#define usbUART115200bps_RX_FIFO_CTRL_CLEAR                 ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_RX_FIFO_CTRL_CLEAR_POS))
#define usbUART115200bps_RX_FIFO_CTRL_FREEZE                ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_RX_FIFO_CTRL_FREEZE_POS))


/* usbUART115200bps_RX_FIFO_STATUS_REG */
#define usbUART115200bps_RX_FIFO_STATUS_USED_POS    (0u)   /* [3:0]   Amount of entries in RX FIFO */
#define usbUART115200bps_RX_FIFO_SR_VALID_POS       (15u)  /* [15]    Shifter status of RX FIFO    */
#define usbUART115200bps_RX_FIFO_STATUS_RD_PTR_POS  (16u)  /* [18:16] RX FIFO read pointer         */
#define usbUART115200bps_RX_FIFO_STATUS_WR_PTR_POS  (24u)  /* [26:24] RX FIFO write pointer        */
#define usbUART115200bps_RX_FIFO_STATUS_USED_MASK   ((uint32) 0x0Fu)
#define usbUART115200bps_RX_FIFO_SR_VALID           ((uint32) ((uint32) 0x01u << \
                                                                  usbUART115200bps_RX_FIFO_SR_VALID_POS))
#define usbUART115200bps_RX_FIFO_STATUS_RD_PTR_MASK ((uint32) ((uint32) 0x07u << \
                                                                  usbUART115200bps_RX_FIFO_STATUS_RD_PTR_POS))
#define usbUART115200bps_RX_FIFO_STATUS_WR_PTR_MASK ((uint32) ((uint32) 0x07u << \
                                                                  usbUART115200bps_RX_FIFO_STATUS_WR_PTR_POS))


/* usbUART115200bps_RX_MATCH_REG */
#define usbUART115200bps_RX_MATCH_ADDR_POS     (0u)  /* [7:0]   Slave address                        */
#define usbUART115200bps_RX_MATCH_MASK_POS     (16u) /* [23:16] Slave address mask: 0 - doesn't care */
#define usbUART115200bps_RX_MATCH_ADDR_MASK    ((uint32) 0xFFu)
#define usbUART115200bps_RX_MATCH_MASK_MASK    ((uint32) ((uint32) 0xFFu << usbUART115200bps_RX_MATCH_MASK_POS))


/* usbUART115200bps_RX_FIFO_WR_REG */
#define usbUART115200bps_RX_FIFO_RD_POS    (0u)  /* [15:0] Data read from RX FIFO */
#define usbUART115200bps_RX_FIFO_RD_MASK   ((uint32) 0xFFu)


/* usbUART115200bps_RX_FIFO_RD_SILENT_REG */
#define usbUART115200bps_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define usbUART115200bps_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* usbUART115200bps_RX_FIFO_RD_SILENT_REG */
#define usbUART115200bps_RX_FIFO_RD_SILENT_POS     (0u)  /* [15:0] Data read from RX FIFO: not remove data from FIFO */
#define usbUART115200bps_RX_FIFO_RD_SILENT_MASK    ((uint32) 0xFFu)

/* usbUART115200bps_EZBUF_DATA_REG */
#define usbUART115200bps_EZBUF_DATA_POS   (0u)  /* [7:0] Data from Ez Memory */
#define usbUART115200bps_EZBUF_DATA_MASK  ((uint32) 0xFFu)

/*  usbUART115200bps_INTR_CAUSE_REG */
#define usbUART115200bps_INTR_CAUSE_MASTER_POS  (0u)  /* [0] Master interrupt active                 */
#define usbUART115200bps_INTR_CAUSE_SLAVE_POS   (1u)  /* [1] Slave interrupt active                  */
#define usbUART115200bps_INTR_CAUSE_TX_POS      (2u)  /* [2] Transmitter interrupt active            */
#define usbUART115200bps_INTR_CAUSE_RX_POS      (3u)  /* [3] Receiver interrupt active               */
#define usbUART115200bps_INTR_CAUSE_I2C_EC_POS  (4u)  /* [4] Externally clock I2C interrupt active   */
#define usbUART115200bps_INTR_CAUSE_SPI_EC_POS  (5u)  /* [5] Externally clocked SPI interrupt active */
#define usbUART115200bps_INTR_CAUSE_MASTER      ((uint32) 0x01u)
#define usbUART115200bps_INTR_CAUSE_SLAVE       ((uint32) ((uint32) 0x01u << usbUART115200bps_INTR_CAUSE_SLAVE_POS))
#define usbUART115200bps_INTR_CAUSE_TX          ((uint32) ((uint32) 0x01u << usbUART115200bps_INTR_CAUSE_TX_POS))
#define usbUART115200bps_INTR_CAUSE_RX          ((uint32) ((uint32) 0x01u << usbUART115200bps_INTR_CAUSE_RX_POS))
#define usbUART115200bps_INTR_CAUSE_I2C_EC      ((uint32) ((uint32) 0x01u << usbUART115200bps_INTR_CAUSE_I2C_EC_POS))
#define usbUART115200bps_INTR_CAUSE_SPI_EC      ((uint32) ((uint32) 0x01u << usbUART115200bps_INTR_CAUSE_SPI_EC_POS))


/* usbUART115200bps_INTR_SPI_EC_REG, usbUART115200bps_INTR_SPI_EC_MASK_REG, usbUART115200bps_INTR_SPI_EC_MASKED_REG */
#define usbUART115200bps_INTR_SPI_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define usbUART115200bps_INTR_SPI_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define usbUART115200bps_INTR_SPI_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define usbUART115200bps_INTR_SPI_EC_WAKE_UP              ((uint32) 0x01u)
#define usbUART115200bps_INTR_SPI_EC_EZBUF_STOP           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SPI_EC_EZBUF_STOP_POS))
#define usbUART115200bps_INTR_SPI_EC_EZBUF_WRITE_STOP     ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SPI_EC_EZBUF_WRITE_STOP_POS))


/* usbUART115200bps_INTR_I2C_EC, usbUART115200bps_INTR_I2C_EC_MASK, usbUART115200bps_INTR_I2C_EC_MASKED */
#define usbUART115200bps_INTR_I2C_EC_WAKE_UP_POS          (0u)  /* [0] Address match: triggers wakeup of chip */
#define usbUART115200bps_INTR_I2C_EC_EZBUF_STOP_POS       (1u)  /* [1] Externally clocked Stop detected       */
#define usbUART115200bps_INTR_I2C_EC_EZBUF_WRITE_STOP_POS (2u)  /* [2] Externally clocked Write Stop detected */
#define usbUART115200bps_INTR_I2C_EC_WAKE_UP              ((uint32) 0x01u)
#define usbUART115200bps_INTR_I2C_EC_EZBUF_STOP           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_I2C_EC_EZBUF_STOP_POS))
#define usbUART115200bps_INTR_I2C_EC_EZBUF_WRITE_STOP     ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_I2C_EC_EZBUF_WRITE_STOP_POS))


/* usbUART115200bps_INTR_MASTER, usbUART115200bps_INTR_MASTER_SET,
   usbUART115200bps_INTR_MASTER_MASK, usbUART115200bps_INTR_MASTER_MASKED */
#define usbUART115200bps_INTR_MASTER_I2C_ARB_LOST_POS   (0u)  /* [0] Master lost arbitration                          */
#define usbUART115200bps_INTR_MASTER_I2C_NACK_POS       (1u)  /* [1] Master receives NACK: address or write to slave  */
#define usbUART115200bps_INTR_MASTER_I2C_ACK_POS        (2u)  /* [2] Master receives NACK: address or write to slave  */
#define usbUART115200bps_INTR_MASTER_I2C_STOP_POS       (4u)  /* [4] Master detects the Stop: only self generated Stop*/
#define usbUART115200bps_INTR_MASTER_I2C_BUS_ERROR_POS  (8u)  /* [8] Master detects bus error: misplaced Start or Stop*/
#define usbUART115200bps_INTR_MASTER_SPI_DONE_POS       (9u)  /* [9] Master complete trasfer: Only for SPI            */
#define usbUART115200bps_INTR_MASTER_I2C_ARB_LOST       ((uint32) 0x01u)
#define usbUART115200bps_INTR_MASTER_I2C_NACK           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_MASTER_I2C_NACK_POS))
#define usbUART115200bps_INTR_MASTER_I2C_ACK            ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_MASTER_I2C_ACK_POS))
#define usbUART115200bps_INTR_MASTER_I2C_STOP           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_MASTER_I2C_STOP_POS))
#define usbUART115200bps_INTR_MASTER_I2C_BUS_ERROR      ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_MASTER_I2C_BUS_ERROR_POS))
#define usbUART115200bps_INTR_MASTER_SPI_DONE           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_MASTER_SPI_DONE_POS))

/*
* usbUART115200bps_INTR_SLAVE, usbUART115200bps_INTR_SLAVE_SET,
* usbUART115200bps_INTR_SLAVE_MASK, usbUART115200bps_INTR_SLAVE_MASKED
*/
#define usbUART115200bps_INTR_SLAVE_I2C_ARB_LOST_POS         (0u)  /* [0]  Slave lost arbitration                   */
#define usbUART115200bps_INTR_SLAVE_I2C_NACK_POS             (1u)  /* [1]  Slave receives NACK: master reads data   */
#define usbUART115200bps_INTR_SLAVE_I2C_ACK_POS              (2u)  /* [2]  Slave receives ACK: master reads data    */
#define usbUART115200bps_INTR_SLAVE_I2C_WRITE_STOP_POS       (3u)  /* [3]  Slave detects end of write transaction   */
#define usbUART115200bps_INTR_SLAVE_I2C_STOP_POS             (4u)  /* [4]  Slave detects end of transaction intened */
#define usbUART115200bps_INTR_SLAVE_I2C_START_POS            (5u)  /* [5]  Slave detects Start                      */
#define usbUART115200bps_INTR_SLAVE_I2C_ADDR_MATCH_POS       (6u)  /* [6]  Slave address matches                    */
#define usbUART115200bps_INTR_SLAVE_I2C_GENERAL_POS          (7u)  /* [7]  General call received                    */
#define usbUART115200bps_INTR_SLAVE_I2C_BUS_ERROR_POS        (8u)  /* [8]  Slave detects bus error                  */
#define usbUART115200bps_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS (9u)  /* [9]  Slave write complete: Only for SPI       */
#define usbUART115200bps_INTR_SLAVE_SPI_EZBUF_STOP_POS       (10u) /* [10] Slave end of transaciton: Only for SPI   */
#define usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR_POS        (11u) /* [11] Slave detects bus error: Only for SPI    */
#define usbUART115200bps_INTR_SLAVE_I2C_ARB_LOST             ((uint32) 0x01u)
#define usbUART115200bps_INTR_SLAVE_I2C_NACK                 ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_NACK_POS))
#define usbUART115200bps_INTR_SLAVE_I2C_ACK                  ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_ACK_POS))
#define usbUART115200bps_INTR_SLAVE_I2C_WRITE_STOP           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_WRITE_STOP_POS))
#define usbUART115200bps_INTR_SLAVE_I2C_STOP                 ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_STOP_POS))
#define usbUART115200bps_INTR_SLAVE_I2C_START                ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_START_POS))
#define usbUART115200bps_INTR_SLAVE_I2C_ADDR_MATCH           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_ADDR_MATCH_POS))
#define usbUART115200bps_INTR_SLAVE_I2C_GENERAL              ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_GENERAL_POS))
#define usbUART115200bps_INTR_SLAVE_I2C_BUS_ERROR            ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_I2C_BUS_ERROR_POS))
#define usbUART115200bps_INTR_SLAVE_SPI_EZBUF_WRITE_STOP     ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_SPI_EZBUF_WRITE_STOP_POS))
#define usbUART115200bps_INTR_SLAVE_SPI_EZBUF_STOP           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_SPI_EZBUF_STOP_POS))
#define usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR           ((uint32) ((uint32) 0x01u << \
                                                                    usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR_POS))


/*
* usbUART115200bps_INTR_TX, usbUART115200bps_INTR_TX_SET,
* usbUART115200bps_INTR_TX_MASK, usbUART115200bps_INTR_TX_MASKED
*/
#define usbUART115200bps_INTR_TX_TRIGGER_POS        (0u)  /* [0]  Trigger on TX FIFO entires                       */
#define usbUART115200bps_INTR_TX_NOT_FULL_POS       (1u)  /* [1]  TX FIFO is not full                              */
#define usbUART115200bps_INTR_TX_EMPTY_POS          (4u)  /* [4]  TX FIFO is empty                                 */
#define usbUART115200bps_INTR_TX_OVERFLOW_POS       (5u)  /* [5]  Attempt to write to a full TX FIFO               */
#define usbUART115200bps_INTR_TX_UNDERFLOW_POS      (6u)  /* [6]  Attempt to read from an empty TX FIFO            */
#define usbUART115200bps_INTR_TX_BLOCKED_POS        (7u)  /* [7]  No access to the EZ memory                       */
#define usbUART115200bps_INTR_TX_UART_NACK_POS      (8u)  /* [8]  UART transmitter received a NACK: SmartCard mode */
#define usbUART115200bps_INTR_TX_UART_DONE_POS      (9u)  /* [9]  UART transmitter done even                       */
#define usbUART115200bps_INTR_TX_UART_ARB_LOST_POS  (10u) /* [10] UART lost arbitration: LIN or SmartCard          */
#define usbUART115200bps_INTR_TX_TRIGGER            ((uint32) 0x01u)
#define usbUART115200bps_INTR_TX_NOT_FULL           ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_NOT_FULL_POS))
#define usbUART115200bps_INTR_TX_EMPTY              ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_EMPTY_POS))
#define usbUART115200bps_INTR_TX_OVERFLOW           ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_OVERFLOW_POS))
#define usbUART115200bps_INTR_TX_UNDERFLOW          ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_UNDERFLOW_POS))
#define usbUART115200bps_INTR_TX_BLOCKED            ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_BLOCKED_POS))
#define usbUART115200bps_INTR_TX_UART_NACK          ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_UART_NACK_POS))
#define usbUART115200bps_INTR_TX_UART_DONE          ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_UART_DONE_POS))
#define usbUART115200bps_INTR_TX_UART_ARB_LOST      ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_TX_UART_ARB_LOST_POS))


/*
* usbUART115200bps_INTR_RX, usbUART115200bps_INTR_RX_SET,
* usbUART115200bps_INTR_RX_MASK, usbUART115200bps_INTR_RX_MASKED
*/
#define usbUART115200bps_INTR_RX_TRIGGER_POS        (0u)   /* [0]  Trigger on RX FIFO entires            */
#define usbUART115200bps_INTR_RX_NOT_EMPTY_POS      (2u)   /* [2]  RX FIFO is not empty                  */
#define usbUART115200bps_INTR_RX_FULL_POS           (3u)   /* [3]  RX FIFO is full                       */
#define usbUART115200bps_INTR_RX_OVERFLOW_POS       (5u)   /* [5]  Attempt to write to a full RX FIFO    */
#define usbUART115200bps_INTR_RX_UNDERFLOW_POS      (6u)   /* [6]  Attempt to read from an empty RX FIFO */
#define usbUART115200bps_INTR_RX_BLOCKED_POS        (7u)   /* [7]  No access to the EZ memory            */
#define usbUART115200bps_INTR_RX_FRAME_ERROR_POS    (8u)   /* [8]  Frame error in received data frame    */
#define usbUART115200bps_INTR_RX_PARITY_ERROR_POS   (9u)   /* [9]  Parity error in received data frame   */
#define usbUART115200bps_INTR_RX_BAUD_DETECT_POS    (10u)  /* [10] LIN baudrate detection is completed   */
#define usbUART115200bps_INTR_RX_BREAK_DETECT_POS   (11u)  /* [11] Break detection is successful         */
#define usbUART115200bps_INTR_RX_TRIGGER            ((uint32) 0x01u)
#define usbUART115200bps_INTR_RX_NOT_EMPTY          ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_NOT_EMPTY_POS))
#define usbUART115200bps_INTR_RX_FULL               ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_FULL_POS))
#define usbUART115200bps_INTR_RX_OVERFLOW           ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_OVERFLOW_POS))
#define usbUART115200bps_INTR_RX_UNDERFLOW          ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_UNDERFLOW_POS))
#define usbUART115200bps_INTR_RX_BLOCKED            ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_BLOCKED_POS))
#define usbUART115200bps_INTR_RX_FRAME_ERROR        ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_FRAME_ERROR_POS))
#define usbUART115200bps_INTR_RX_PARITY_ERROR       ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_PARITY_ERROR_POS))
#define usbUART115200bps_INTR_RX_BAUD_DETECT        ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_BAUD_DETECT_POS))
#define usbUART115200bps_INTR_RX_BREAK_DETECT       ((uint32) ((uint32) 0x01u << \
                                                                        usbUART115200bps_INTR_RX_BREAK_DETECT_POS))


/* Define all interupt soureces */
#define usbUART115200bps_INTR_I2C_EC_ALL    (usbUART115200bps_INTR_I2C_EC_WAKE_UP    | \
                                             usbUART115200bps_INTR_I2C_EC_EZBUF_STOP | \
                                             usbUART115200bps_INTR_I2C_EC_EZBUF_WRITE_STOP)

#define usbUART115200bps_INTR_SPI_EC_ALL    (usbUART115200bps_INTR_SPI_EC_WAKE_UP    | \
                                             usbUART115200bps_INTR_SPI_EC_EZBUF_STOP | \
                                             usbUART115200bps_INTR_SPI_EC_EZBUF_WRITE_STOP)

#define usbUART115200bps_INTR_MASTER_ALL    (usbUART115200bps_INTR_MASTER_I2C_ARB_LOST  | \
                                             usbUART115200bps_INTR_MASTER_I2C_NACK      | \
                                             usbUART115200bps_INTR_MASTER_I2C_ACK       | \
                                             usbUART115200bps_INTR_MASTER_I2C_STOP      | \
                                             usbUART115200bps_INTR_MASTER_I2C_BUS_ERROR | \
                                             usbUART115200bps_INTR_MASTER_SPI_DONE )

#define usbUART115200bps_INTR_SLAVE_ALL     (usbUART115200bps_INTR_SLAVE_I2C_ARB_LOST      | \
                                             usbUART115200bps_INTR_SLAVE_I2C_NACK          | \
                                             usbUART115200bps_INTR_SLAVE_I2C_ACK           | \
                                             usbUART115200bps_INTR_SLAVE_I2C_WRITE_STOP    | \
                                             usbUART115200bps_INTR_SLAVE_I2C_STOP          | \
                                             usbUART115200bps_INTR_SLAVE_I2C_START         | \
                                             usbUART115200bps_INTR_SLAVE_I2C_ADDR_MATCH    | \
                                             usbUART115200bps_INTR_SLAVE_I2C_GENERAL       | \
                                             usbUART115200bps_INTR_SLAVE_I2C_BUS_ERROR     | \
                                             usbUART115200bps_INTR_SLAVE_SPI_EZBUF_WRITE_STOP | \
                                             usbUART115200bps_INTR_SLAVE_SPI_EZBUF_STOP       | \
                                             usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR)

#define usbUART115200bps_INTR_TX_ALL        (usbUART115200bps_INTR_TX_TRIGGER   | \
                                             usbUART115200bps_INTR_TX_NOT_FULL  | \
                                             usbUART115200bps_INTR_TX_EMPTY     | \
                                             usbUART115200bps_INTR_TX_OVERFLOW  | \
                                             usbUART115200bps_INTR_TX_UNDERFLOW | \
                                             usbUART115200bps_INTR_TX_BLOCKED   | \
                                             usbUART115200bps_INTR_TX_UART_NACK | \
                                             usbUART115200bps_INTR_TX_UART_DONE | \
                                             usbUART115200bps_INTR_TX_UART_ARB_LOST)

#define usbUART115200bps_INTR_RX_ALL        (usbUART115200bps_INTR_RX_TRIGGER      | \
                                             usbUART115200bps_INTR_RX_NOT_EMPTY    | \
                                             usbUART115200bps_INTR_RX_FULL         | \
                                             usbUART115200bps_INTR_RX_OVERFLOW     | \
                                             usbUART115200bps_INTR_RX_UNDERFLOW    | \
                                             usbUART115200bps_INTR_RX_BLOCKED      | \
                                             usbUART115200bps_INTR_RX_FRAME_ERROR  | \
                                             usbUART115200bps_INTR_RX_PARITY_ERROR | \
                                             usbUART115200bps_INTR_RX_BAUD_DETECT  | \
                                             usbUART115200bps_INTR_RX_BREAK_DETECT)

/* General usage HW definitions */
#define usbUART115200bps_ONE_BYTE_WIDTH (8u)   /* Number of bits in one byte           */
#define usbUART115200bps_FIFO_SIZE      (8u)   /* Size of TX or RX FIFO: defined by HW */
#define usbUART115200bps_EZBUFFER_SIZE  (32u)  /* EZ Buffer size: defined by HW        */

/* I2C and EZI2C slave address defines */
#define usbUART115200bps_I2C_SLAVE_ADDR_POS    (0x01u)    /* 7-bit address shift */
#define usbUART115200bps_I2C_SLAVE_ADDR_MASK   (0xFEu)    /* 8-bit address mask */

/* OVS constants for IrDA Low Power operation */
#define usbUART115200bps_CTRL_OVS_IRDA_LP_OVS16     (0x00u)
#define usbUART115200bps_CTRL_OVS_IRDA_LP_OVS32     (0x01u)
#define usbUART115200bps_CTRL_OVS_IRDA_LP_OVS48     (0x02u)
#define usbUART115200bps_CTRL_OVS_IRDA_LP_OVS96     (0x03u)
#define usbUART115200bps_CTRL_OVS_IRDA_LP_OVS192    (0x04u)
#define usbUART115200bps_CTRL_OVS_IRDA_LP_OVS768    (0x05u)
#define usbUART115200bps_CTRL_OVS_IRDA_LP_OVS1536   (0x06u)

/* OVS constant for IrDA */
#define usbUART115200bps_CTRL_OVS_IRDA_OVS16        (usbUART115200bps_UART_IRDA_LP_OVS16)


/***************************************
*    SCB Common Macro Definitions
***************************************/

/*
* Re-enables SCB IP: this cause partial reset of IP: state, status, TX and RX FIFOs.
* The triggered interrupts remains set.
*/
#define usbUART115200bps_SCB_SW_RESET \
                        do{ \
                            usbUART115200bps_CTRL_REG &= ((uint32) ~usbUART115200bps_CTRL_ENABLED ); \
                            usbUART115200bps_CTRL_REG |= ((uint32)  usbUART115200bps_CTRL_ENABLED ); \
                        }while(0)

/* TX FIFO macro */
#define usbUART115200bps_CLEAR_TX_FIFO \
                            do{        \
                                usbUART115200bps_TX_FIFO_CTRL_REG |= ((uint32)  usbUART115200bps_TX_FIFO_CTRL_CLEAR); \
                                usbUART115200bps_TX_FIFO_CTRL_REG &= ((uint32) ~usbUART115200bps_TX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define usbUART115200bps_GET_TX_FIFO_ENTRIES    (usbUART115200bps_TX_FIFO_STATUS_REG & \
                                                 usbUART115200bps_TX_FIFO_STATUS_USED_MASK)

#define usbUART115200bps_GET_TX_FIFO_SR_VALID   ((0u != (usbUART115200bps_TX_FIFO_STATUS_REG & \
                                                         usbUART115200bps_TX_FIFO_SR_VALID)) ? (1u) : (0u))

/* RX FIFO macro */
#define usbUART115200bps_CLEAR_RX_FIFO \
                            do{        \
                                usbUART115200bps_RX_FIFO_CTRL_REG |= ((uint32)  usbUART115200bps_RX_FIFO_CTRL_CLEAR); \
                                usbUART115200bps_RX_FIFO_CTRL_REG &= ((uint32) ~usbUART115200bps_RX_FIFO_CTRL_CLEAR); \
                            }while(0)

#define usbUART115200bps_GET_RX_FIFO_ENTRIES    (usbUART115200bps_RX_FIFO_STATUS_REG & \
                                                    usbUART115200bps_RX_FIFO_STATUS_USED_MASK)

#define usbUART115200bps_GET_RX_FIFO_SR_VALID   ((0u != (usbUART115200bps_RX_FIFO_STATUS_REG & \
                                                         usbUART115200bps_RX_FIFO_SR_VALID)) ? (1u) : (0u))

/* Writes interrupt source: set sourceMask bits in usbUART115200bps_INTR_X_MASK_REG */
#define usbUART115200bps_WRITE_INTR_I2C_EC_MASK(sourceMask) \
                                                do{         \
                                                    usbUART115200bps_INTR_I2C_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_WRITE_INTR_SPI_EC_MASK(sourceMask) \
                                                do{         \
                                                    usbUART115200bps_INTR_SPI_EC_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_WRITE_INTR_MASTER_MASK(sourceMask) \
                                                do{         \
                                                    usbUART115200bps_INTR_MASTER_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_WRITE_INTR_SLAVE_MASK(sourceMask)  \
                                                do{         \
                                                    usbUART115200bps_INTR_SLAVE_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_WRITE_INTR_TX_MASK(sourceMask)     \
                                                do{         \
                                                    usbUART115200bps_INTR_TX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_WRITE_INTR_RX_MASK(sourceMask)     \
                                                do{         \
                                                    usbUART115200bps_INTR_RX_MASK_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Enables interrupt source: set sourceMask bits in usbUART115200bps_INTR_X_MASK_REG */
#define usbUART115200bps_ENABLE_INTR_I2C_EC(sourceMask) \
                                                do{     \
                                                    usbUART115200bps_INTR_I2C_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_ENABLE_INTR_SPI_EC(sourceMask) \
                                                do{     \
                                                    usbUART115200bps_INTR_SPI_EC_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_ENABLE_INTR_MASTER(sourceMask) \
                                                do{     \
                                                    usbUART115200bps_INTR_MASTER_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_ENABLE_INTR_SLAVE(sourceMask)  \
                                                do{     \
                                                    usbUART115200bps_INTR_SLAVE_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_ENABLE_INTR_TX(sourceMask)     \
                                                do{     \
                                                    usbUART115200bps_INTR_TX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_ENABLE_INTR_RX(sourceMask)     \
                                                do{     \
                                                    usbUART115200bps_INTR_RX_MASK_REG |= (uint32) (sourceMask); \
                                                }while(0)

/* Disables interrupt source: clear sourceMask bits in usbUART115200bps_INTR_X_MASK_REG */
#define usbUART115200bps_DISABLE_INTR_I2C_EC(sourceMask) \
                                do{                      \
                                    usbUART115200bps_INTR_I2C_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define usbUART115200bps_DISABLE_INTR_SPI_EC(sourceMask) \
                                do{                      \
                                    usbUART115200bps_INTR_SPI_EC_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)

#define usbUART115200bps_DISABLE_INTR_MASTER(sourceMask) \
                                do{                      \
                                usbUART115200bps_INTR_MASTER_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define usbUART115200bps_DISABLE_INTR_SLAVE(sourceMask) \
                                do{                     \
                                    usbUART115200bps_INTR_SLAVE_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

#define usbUART115200bps_DISABLE_INTR_TX(sourceMask)    \
                                do{                     \
                                    usbUART115200bps_INTR_TX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                 }while(0)

#define usbUART115200bps_DISABLE_INTR_RX(sourceMask)    \
                                do{                     \
                                    usbUART115200bps_INTR_RX_MASK_REG &= ((uint32) ~((uint32) (sourceMask))); \
                                }while(0)

/* Sets interrupt sources: write sourceMask bits in usbUART115200bps_INTR_X_SET_REG */
#define usbUART115200bps_SET_INTR_MASTER(sourceMask)    \
                                                do{     \
                                                    usbUART115200bps_INTR_MASTER_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_SET_INTR_SLAVE(sourceMask) \
                                                do{ \
                                                    usbUART115200bps_INTR_SLAVE_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_SET_INTR_TX(sourceMask)    \
                                                do{ \
                                                    usbUART115200bps_INTR_TX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_SET_INTR_RX(sourceMask)    \
                                                do{ \
                                                    usbUART115200bps_INTR_RX_SET_REG = (uint32) (sourceMask); \
                                                }while(0)

/* Clears interrupt sources: write sourceMask bits in usbUART115200bps_INTR_X_REG */
#define usbUART115200bps_CLEAR_INTR_I2C_EC(sourceMask)  \
                                                do{     \
                                                    usbUART115200bps_INTR_I2C_EC_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_CLEAR_INTR_SPI_EC(sourceMask)  \
                                                do{     \
                                                    usbUART115200bps_INTR_SPI_EC_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_CLEAR_INTR_MASTER(sourceMask)  \
                                                do{     \
                                                    usbUART115200bps_INTR_MASTER_REG = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_CLEAR_INTR_SLAVE(sourceMask)   \
                                                do{     \
                                                    usbUART115200bps_INTR_SLAVE_REG  = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_CLEAR_INTR_TX(sourceMask)      \
                                                do{     \
                                                    usbUART115200bps_INTR_TX_REG     = (uint32) (sourceMask); \
                                                }while(0)

#define usbUART115200bps_CLEAR_INTR_RX(sourceMask)      \
                                                do{     \
                                                    usbUART115200bps_INTR_RX_REG     = (uint32) (sourceMask); \
                                                }while(0)

/* Return true if sourceMask is set in usbUART115200bps_INTR_CAUSE_REG */
#define usbUART115200bps_CHECK_CAUSE_INTR(sourceMask)    (0u != (usbUART115200bps_INTR_CAUSE_REG & (sourceMask)))

/* Return true if sourceMask is set in  INTR_X_MASKED_REG */
#define usbUART115200bps_CHECK_INTR_EC_I2C(sourceMask)  (0u != (usbUART115200bps_INTR_I2C_EC_REG & (sourceMask)))
#define usbUART115200bps_CHECK_INTR_EC_SPI(sourceMask)  (0u != (usbUART115200bps_INTR_SPI_EC_REG & (sourceMask)))
#define usbUART115200bps_CHECK_INTR_MASTER(sourceMask)  (0u != (usbUART115200bps_INTR_MASTER_REG & (sourceMask)))
#define usbUART115200bps_CHECK_INTR_SLAVE(sourceMask)   (0u != (usbUART115200bps_INTR_SLAVE_REG  & (sourceMask)))
#define usbUART115200bps_CHECK_INTR_TX(sourceMask)      (0u != (usbUART115200bps_INTR_TX_REG     & (sourceMask)))
#define usbUART115200bps_CHECK_INTR_RX(sourceMask)      (0u != (usbUART115200bps_INTR_RX_REG     & (sourceMask)))

/* Return true if sourceMask is set in usbUART115200bps_INTR_X_MASKED_REG */
#define usbUART115200bps_CHECK_INTR_I2C_EC_MASKED(sourceMask)   (0u != (usbUART115200bps_INTR_I2C_EC_MASKED_REG & \
                                                                       (sourceMask)))
#define usbUART115200bps_CHECK_INTR_SPI_EC_MASKED(sourceMask)   (0u != (usbUART115200bps_INTR_SPI_EC_MASKED_REG & \
                                                                       (sourceMask)))
#define usbUART115200bps_CHECK_INTR_MASTER_MASKED(sourceMask)   (0u != (usbUART115200bps_INTR_MASTER_MASKED_REG & \
                                                                       (sourceMask)))
#define usbUART115200bps_CHECK_INTR_SLAVE_MASKED(sourceMask)    (0u != (usbUART115200bps_INTR_SLAVE_MASKED_REG  & \
                                                                       (sourceMask)))
#define usbUART115200bps_CHECK_INTR_TX_MASKED(sourceMask)       (0u != (usbUART115200bps_INTR_TX_MASKED_REG     & \
                                                                       (sourceMask)))
#define usbUART115200bps_CHECK_INTR_RX_MASKED(sourceMask)       (0u != (usbUART115200bps_INTR_RX_MASKED_REG     & \
                                                                       (sourceMask)))

/* Return true if sourceMask is set in usbUART115200bps_CTRL_REG: generaly is used to check enable bit */
#define usbUART115200bps_GET_CTRL_ENABLED    (0u != (usbUART115200bps_CTRL_REG & usbUART115200bps_CTRL_ENABLED))

#define usbUART115200bps_CHECK_SLAVE_AUTO_ADDR_NACK     (0u != (usbUART115200bps_I2C_CTRL_REG & \
                                                                usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK))


/***************************************
*      I2C Macro Definitions
***************************************/

/* Enable auto ACK/NACK */
#define usbUART115200bps_ENABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                      \
                                usbUART115200bps_I2C_CTRL_REG |= usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define usbUART115200bps_ENABLE_SLAVE_AUTO_DATA_ACK \
                            do{                     \
                                usbUART115200bps_I2C_CTRL_REG |= usbUART115200bps_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define usbUART115200bps_ENABLE_SLAVE_AUTO_DATA_NACK \
                            do{                      \
                                usbUART115200bps_I2C_CTRL_REG |= usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define usbUART115200bps_ENABLE_MASTER_AUTO_DATA_ACK \
                            do{                      \
                                usbUART115200bps_I2C_CTRL_REG |= usbUART115200bps_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define usbUART115200bps_ENABLE_MASTER_AUTO_DATA_NACK \
                            do{                       \
                                usbUART115200bps_I2C_CTRL_REG |= usbUART115200bps_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Disable auto ACK/NACK */
#define usbUART115200bps_DISABLE_SLAVE_AUTO_ADDR_NACK \
                            do{                       \
                                usbUART115200bps_I2C_CTRL_REG &= ~usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define usbUART115200bps_DISABLE_SLAVE_AUTO_DATA_ACK \
                            do{                      \
                                usbUART115200bps_I2C_CTRL_REG &= ~usbUART115200bps_I2C_CTRL_S_READY_DATA_ACK; \
                            }while(0)

#define usbUART115200bps_DISABLE_SLAVE_AUTO_DATA_NACK \
                            do{                       \
                                usbUART115200bps_I2C_CTRL_REG &= ~usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK; \
                            }while(0)

#define usbUART115200bps_DISABLE_MASTER_AUTO_DATA_ACK \
                            do{                       \
                                usbUART115200bps_I2C_CTRL_REG &= ~usbUART115200bps_I2C_CTRL_M_READY_DATA_ACK; \
                            }while(0)

#define usbUART115200bps_DISABLE_MASTER_AUTO_DATA_NACK \
                            do{                        \
                                usbUART115200bps_I2C_CTRL_REG &= ~usbUART115200bps_I2C_CTRL_M_NOT_READY_DATA_NACK; \
                            }while(0)

/* Enable Slave autoACK/NACK Data */
#define usbUART115200bps_ENABLE_SLAVE_AUTO_DATA \
                            do{                 \
                                usbUART115200bps_I2C_CTRL_REG |= (usbUART115200bps_I2C_CTRL_S_READY_DATA_ACK |      \
                                                                  usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK); \
                            }while(0)

/* Disable Slave autoACK/NACK Data */
#define usbUART115200bps_DISABLE_SLAVE_AUTO_DATA \
                            do{                  \
                                usbUART115200bps_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(usbUART115200bps_I2C_CTRL_S_READY_DATA_ACK |       \
                                                                    usbUART115200bps_I2C_CTRL_S_NOT_READY_DATA_NACK)); \
                            }while(0)

/* Disable Master autoACK/NACK Data */
#define usbUART115200bps_DISABLE_MASTER_AUTO_DATA \
                            do{                   \
                                usbUART115200bps_I2C_CTRL_REG &= ((uint32) \
                                                                  ~(usbUART115200bps_I2C_CTRL_M_READY_DATA_ACK |       \
                                                                    usbUART115200bps_I2C_CTRL_M_NOT_READY_DATA_NACK)); \
                            }while(0)

/* Master commands */
#define usbUART115200bps_I2C_MASTER_GENERATE_START \
                            do{                    \
                                usbUART115200bps_I2C_MASTER_CMD_REG = usbUART115200bps_I2C_MASTER_CMD_M_START_ON_IDLE; \
                            }while(0)

#define usbUART115200bps_I2C_MASTER_CLEAR_START \
                            do{                 \
                                usbUART115200bps_I2C_MASTER_CMD_REG =  ((uint32) 0u); \
                            }while(0)

#define usbUART115200bps_I2C_MASTER_GENERATE_RESTART usbUART115200bps_I2CReStartGeneration()

#define usbUART115200bps_I2C_MASTER_GENERATE_STOP \
                            do{                   \
                                usbUART115200bps_I2C_MASTER_CMD_REG =                                            \
                                    (usbUART115200bps_I2C_MASTER_CMD_M_STOP |                                    \
                                        (usbUART115200bps_CHECK_I2C_STATUS(usbUART115200bps_I2C_STATUS_M_READ) ? \
                                            (usbUART115200bps_I2C_MASTER_CMD_M_NACK) : (0u)));                   \
                            }while(0)

#define usbUART115200bps_I2C_MASTER_GENERATE_ACK \
                            do{                  \
                                usbUART115200bps_I2C_MASTER_CMD_REG = usbUART115200bps_I2C_MASTER_CMD_M_ACK; \
                            }while(0)

#define usbUART115200bps_I2C_MASTER_GENERATE_NACK \
                            do{                   \
                                usbUART115200bps_I2C_MASTER_CMD_REG = usbUART115200bps_I2C_MASTER_CMD_M_NACK; \
                            }while(0)

/* Slave comamnds */
#define usbUART115200bps_I2C_SLAVE_GENERATE_ACK \
                            do{                 \
                                usbUART115200bps_I2C_SLAVE_CMD_REG = usbUART115200bps_I2C_SLAVE_CMD_S_ACK; \
                            }while(0)

#define usbUART115200bps_I2C_SLAVE_GENERATE_NACK \
                            do{                  \
                                usbUART115200bps_I2C_SLAVE_CMD_REG = usbUART115200bps_I2C_SLAVE_CMD_S_NACK; \
                            }while(0)


/* Return 8-bit address. The input address should be 7-bits */
#define usbUART115200bps_GET_I2C_8BIT_ADDRESS(addr) (((uint32) ((uint32) (addr) << \
                                                                    usbUART115200bps_I2C_SLAVE_ADDR_POS)) & \
                                                                        usbUART115200bps_I2C_SLAVE_ADDR_MASK)

#define usbUART115200bps_GET_I2C_7BIT_ADDRESS(addr) ((uint32) (addr) >> usbUART115200bps_I2C_SLAVE_ADDR_POS)


/* Adjust SDA filter Trim settings */
#define usbUART115200bps_DEFAULT_I2C_CFG_SDA_FILT_TRIM  (0x02u)
#define usbUART115200bps_EC_AM_I2C_CFG_SDA_FILT_TRIM    (0x03u)

#define usbUART115200bps_SET_I2C_CFG_SDA_FILT_TRIM(sdaTrim) \
        do{                                                 \
            usbUART115200bps_I2C_CFG_REG =                  \
                            ((usbUART115200bps_I2C_CFG_REG & (uint32) ~usbUART115200bps_I2C_CFG_SDA_FILT_TRIM_MASK) | \
                             ((uint32) ((uint32) (sdaTrim) <<usbUART115200bps_I2C_CFG_SDA_FILT_TRIM_POS)));           \
        }while(0)

/* Returns slave select number in SPI_CTRL */
#define usbUART115200bps_GET_SPI_CTRL_SS(activeSelect) (((uint32) ((uint32) (activeSelect) << \
                                                                    usbUART115200bps_SPI_CTRL_SLAVE_SELECT_POS)) & \
                                                                        usbUART115200bps_SPI_CTRL_SLAVE_SELECT_MASK)

/* Returns true if bit is set in usbUART115200bps_I2C_STATUS_REG */
#define usbUART115200bps_CHECK_I2C_STATUS(sourceMask)   (0u != (usbUART115200bps_I2C_STATUS_REG & (sourceMask)))

/* Returns true if bit is set in usbUART115200bps_SPI_STATUS_REG */
#define usbUART115200bps_CHECK_SPI_STATUS(sourceMask)   (0u != (usbUART115200bps_SPI_STATUS_REG & (sourceMask)))


/***************************************
*       SCB Init Macros Definitions
***************************************/

/* usbUART115200bps_CTRL */
#define usbUART115200bps_GET_CTRL_OVS(oversample)   ((((uint32) (oversample)) - 1u) & usbUART115200bps_CTRL_OVS_MASK)

#define usbUART115200bps_GET_CTRL_EC_OP_MODE(opMode)        ((0u != (opMode)) ? \
                                                                (usbUART115200bps_CTRL_EC_OP_MODE)  : (0u))

#define usbUART115200bps_GET_CTRL_EC_AM_MODE(amMode)        ((0u != (amMode)) ? \
                                                                (usbUART115200bps_CTRL_EC_AM_MODE)  : (0u))

#define usbUART115200bps_GET_CTRL_BLOCK(block)              ((0u != (block))  ? \
                                                                (usbUART115200bps_CTRL_BLOCK)       : (0u))

#define usbUART115200bps_GET_CTRL_ADDR_ACCEPT(acceptAddr)   ((0u != (acceptAddr)) ? \
                                                                (usbUART115200bps_CTRL_ADDR_ACCEPT) : (0u))

/* usbUART115200bps_I2C_CTRL */
#define usbUART115200bps_GET_I2C_CTRL_HIGH_PHASE_OVS(oversampleHigh) (((uint32) (oversampleHigh) - 1u) & \
                                                                        usbUART115200bps_I2C_CTRL_HIGH_PHASE_OVS_MASK)

#define usbUART115200bps_GET_I2C_CTRL_LOW_PHASE_OVS(oversampleLow)   (((uint32) (((uint32) (oversampleLow) - 1u) << \
                                                                    usbUART115200bps_I2C_CTRL_LOW_PHASE_OVS_POS)) &  \
                                                                    usbUART115200bps_I2C_CTRL_LOW_PHASE_OVS_MASK)

#define usbUART115200bps_GET_I2C_CTRL_S_NOT_READY_ADDR_NACK(wakeNack) ((0u != (wakeNack)) ? \
                                                            (usbUART115200bps_I2C_CTRL_S_NOT_READY_ADDR_NACK) : (0u))

#define usbUART115200bps_GET_I2C_CTRL_SL_MSTR_MODE(mode)    ((uint32) ((uint32)(mode) << \
                                                                    usbUART115200bps_I2C_CTRL_SLAVE_MODE_POS))

/* usbUART115200bps_SPI_CTRL */
#define usbUART115200bps_GET_SPI_CTRL_CONTINUOUS(separate)  ((0u != (separate)) ? \
                                                                (usbUART115200bps_SPI_CTRL_CONTINUOUS) : (0u))

#define usbUART115200bps_GET_SPI_CTRL_SELECT_PRECEDE(mode)  ((0u != (mode)) ? \
                                                                      (usbUART115200bps_SPI_CTRL_SELECT_PRECEDE) : (0u))

#define usbUART115200bps_GET_SPI_CTRL_SCLK_MODE(mode)       (((uint32) ((uint32) (mode) << \
                                                                        usbUART115200bps_SPI_CTRL_CPHA_POS)) & \
                                                                        usbUART115200bps_SPI_CTRL_SCLK_MODE_MASK)

#define usbUART115200bps_GET_SPI_CTRL_LATE_MISO_SAMPLE(lateMiso) ((0u != (lateMiso)) ? \
                                                                    (usbUART115200bps_SPI_CTRL_LATE_MISO_SAMPLE) : (0u))

#define usbUART115200bps_GET_SPI_CTRL_SUB_MODE(mode)        (((uint32) (((uint32) (mode)) << \
                                                                        usbUART115200bps_SPI_CTRL_MODE_POS)) & \
                                                                        usbUART115200bps_SPI_CTRL_MODE_MASK)

#define usbUART115200bps_GET_SPI_CTRL_SLAVE_SELECT(select)  (((uint32) ((uint32) (select) << \
                                                                      usbUART115200bps_SPI_CTRL_SLAVE_SELECT_POS)) & \
                                                                      usbUART115200bps_SPI_CTRL_SLAVE_SELECT_MASK)

#define usbUART115200bps_GET_SPI_CTRL_MASTER_MODE(mode)     ((0u != (mode)) ? \
                                                                (usbUART115200bps_SPI_CTRL_MASTER) : (0u))

/* usbUART115200bps_UART_CTRL */
#define usbUART115200bps_GET_UART_CTRL_MODE(mode)           (((uint32) ((uint32) (mode) << \
                                                                            usbUART115200bps_UART_CTRL_MODE_POS)) & \
                                                                                usbUART115200bps_UART_CTRL_MODE_MASK)

/* usbUART115200bps_UART_RX_CTRL */
#define usbUART115200bps_GET_UART_RX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                        usbUART115200bps_UART_RX_CTRL_STOP_BITS_MASK)

#define usbUART115200bps_GET_UART_RX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                                    (usbUART115200bps_UART_RX_CTRL_PARITY) : (0u))

#define usbUART115200bps_GET_UART_RX_CTRL_POLARITY(polarity)    ((0u != (polarity)) ? \
                                                                    (usbUART115200bps_UART_RX_CTRL_POLARITY) : (0u))

#define usbUART115200bps_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (usbUART115200bps_UART_RX_CTRL_DROP_ON_PARITY_ERR) : (0u))

#define usbUART115200bps_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(dropErr) ((0u != (dropErr)) ? \
                                                        (usbUART115200bps_UART_RX_CTRL_DROP_ON_FRAME_ERR) : (0u))

#define usbUART115200bps_GET_UART_RX_CTRL_MP_MODE(mpMode)   ((0u != (mpMode)) ? \
                                                        (usbUART115200bps_UART_RX_CTRL_MP_MODE) : (0u))

/* usbUART115200bps_UART_TX_CTRL */
#define usbUART115200bps_GET_UART_TX_CTRL_MODE(stopBits)    (((uint32) (stopBits) - 1u) & \
                                                                usbUART115200bps_UART_RX_CTRL_STOP_BITS_MASK)

#define usbUART115200bps_GET_UART_TX_CTRL_PARITY(parity)    ((0u != (parity)) ? \
                                                               (usbUART115200bps_UART_TX_CTRL_PARITY) : (0u))

#define usbUART115200bps_GET_UART_TX_CTRL_RETRY_NACK(nack)  ((0u != (nack)) ? \
                                                               (usbUART115200bps_UART_TX_CTRL_RETRY_ON_NACK) : (0u))

/* usbUART115200bps_RX_CTRL */
#define usbUART115200bps_GET_RX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                usbUART115200bps_RX_CTRL_DATA_WIDTH_MASK)

#define usbUART115200bps_GET_RX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (usbUART115200bps_RX_CTRL_MSB_FIRST) : (0u))

#define usbUART115200bps_GET_RX_CTRL_MEDIAN(filterEn)       ((0u != (filterEn)) ? \
                                                                (usbUART115200bps_RX_CTRL_MEDIAN) : (0u))

/* usbUART115200bps_RX_MATCH */
#define usbUART115200bps_GET_RX_MATCH_ADDR(addr)    ((uint32) (addr) & usbUART115200bps_RX_MATCH_ADDR_MASK)
#define usbUART115200bps_GET_RX_MATCH_MASK(mask)    (((uint32) ((uint32) (mask) << \
                                                            usbUART115200bps_RX_MATCH_MASK_POS)) & \
                                                            usbUART115200bps_RX_MATCH_MASK_MASK)

/* usbUART115200bps_RX_FIFO_CTRL */
#define usbUART115200bps_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    usbUART115200bps_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* usbUART115200bps_TX_CTRL */
#define usbUART115200bps_GET_TX_CTRL_DATA_WIDTH(dataWidth)  (((uint32) (dataWidth) - 1u) & \
                                                                usbUART115200bps_RX_CTRL_DATA_WIDTH_MASK)

#define usbUART115200bps_GET_TX_CTRL_BIT_ORDER(bitOrder)    ((0u != (bitOrder)) ? \
                                                                (usbUART115200bps_TX_CTRL_MSB_FIRST) : (0u))

/* usbUART115200bps_TX_FIFO_CTRL */
#define usbUART115200bps_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(level)  ((uint32) (level) & \
                                                                    usbUART115200bps_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK)

/* Clears register: config and interrupt mask */
#define usbUART115200bps_CLEAR_REG          ((uint32) (0u))
#define usbUART115200bps_NO_INTR_SOURCES    ((uint32) (0u))
#define usbUART115200bps_DUMMY_PARAM        ((uint32) (0u))
#define usbUART115200bps_SUBMODE_SPI_SLAVE  ((uint32) (0u))

/* Return in case I2C read error */
#define usbUART115200bps_I2C_INVALID_BYTE   ((uint32) 0xFFFFFFFFu)
#define usbUART115200bps_CHECK_VALID_BYTE   ((uint32) 0x80000000u)

#endif /* (CY_SCB_usbUART115200bps_H) */


/* [] END OF FILE */
