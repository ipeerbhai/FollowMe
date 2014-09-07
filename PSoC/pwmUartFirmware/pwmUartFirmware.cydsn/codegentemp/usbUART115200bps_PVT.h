/*******************************************************************************
* File Name: .h
* Version 1.10
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_usbUART115200bps_H)
#define CY_SCB_PVT_usbUART115200bps_H

#include "usbUART115200bps.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define usbUART115200bps_SetI2CExtClkInterruptMode(interruptMask) usbUART115200bps_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define usbUART115200bps_ClearI2CExtClkInterruptSource(interruptMask) usbUART115200bps_CLEAR_INTR_I2C_EC(interruptMask)
#define usbUART115200bps_GetI2CExtClkInterruptSource()                (usbUART115200bps_INTR_I2C_EC_REG)
#define usbUART115200bps_GetI2CExtClkInterruptMode()                  (usbUART115200bps_INTR_I2C_EC_MASK_REG)
#define usbUART115200bps_GetI2CExtClkInterruptSourceMasked()          (usbUART115200bps_INTR_I2C_EC_MASKED_REG)

/* APIs to service INTR_SPI_EC register */
#define usbUART115200bps_SetSpiExtClkInterruptMode(interruptMask) usbUART115200bps_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define usbUART115200bps_ClearSpiExtClkInterruptSource(interruptMask) usbUART115200bps_CLEAR_INTR_SPI_EC(interruptMask)
#define usbUART115200bps_GetExtSpiClkInterruptSource()                 (usbUART115200bps_INTR_SPI_EC_REG)
#define usbUART115200bps_GetExtSpiClkInterruptMode()                   (usbUART115200bps_INTR_SPI_EC_MASK_REG)
#define usbUART115200bps_GetExtSpiClkInterruptSourceMasked()           (usbUART115200bps_INTR_SPI_EC_MASKED_REG)

#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void usbUART115200bps_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

void usbUART115200bps_DisableTxPinsInputBuffer(void);
void usbUART115200bps_EnableTxPinsInputBuffer(void);


/**********************************
*     Vars with External Linkage
**********************************/

extern cyisraddress usbUART115200bps_customIntrHandler;
extern usbUART115200bps_BACKUP_STRUCT usbUART115200bps_backup;

#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    extern uint8 usbUART115200bps_scbMode;
    extern uint8 usbUART115200bps_scbEnableWake;
    extern uint8 usbUART115200bps_scbEnableIntr;

    /* I2C config vars */
    extern uint8 usbUART115200bps_mode;
    extern uint8 usbUART115200bps_acceptAddr;

    /* SPI/UART config vars */
    extern volatile uint8 * usbUART115200bps_rxBuffer;
    extern uint8   usbUART115200bps_rxDataBits;
    extern uint32  usbUART115200bps_rxBufferSize;

    extern volatile uint8 * usbUART115200bps_txBuffer;
    extern uint8   usbUART115200bps_txDataBits;
    extern uint32  usbUART115200bps_txBufferSize;

    /* EZI2C config vars */
    extern uint8 usbUART115200bps_numberOfAddr;
    extern uint8 usbUART115200bps_subAddrSize;
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_usbUART115200bps_H) */


/* [] END OF FILE */
