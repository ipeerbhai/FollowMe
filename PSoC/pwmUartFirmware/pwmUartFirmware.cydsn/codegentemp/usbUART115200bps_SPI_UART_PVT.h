/*******************************************************************************
* File Name: usbUART115200bps_SPI_UART_PVT.h
* Version 1.10
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_usbUART115200bps_H)
#define CY_SCB_SPI_UART_PVT_usbUART115200bps_H

#include "usbUART115200bps_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  usbUART115200bps_rxBufferHead;
    extern volatile uint32  usbUART115200bps_rxBufferTail;
    extern volatile uint8   usbUART115200bps_rxBufferOverflow;
#endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

#if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  usbUART115200bps_txBufferHead;
    extern volatile uint32  usbUART115200bps_txBufferTail;
#endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */

#if(usbUART115200bps_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 usbUART115200bps_rxBufferInternal[usbUART115200bps_RX_BUFFER_SIZE];
#endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER) */

#if(usbUART115200bps_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 usbUART115200bps_txBufferInternal[usbUART115200bps_TX_BUFFER_SIZE];
#endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)
    void usbUART115200bps_SpiInit(void);
#endif /* (usbUART115200bps_SCB_MODE_SPI_CONST_CFG) */

#if(usbUART115200bps_SPI_WAKE_ENABLE_CONST)
    void usbUART115200bps_SpiSaveConfig(void);
    void usbUART115200bps_SpiRestoreConfig(void);
#endif /* (usbUART115200bps_SPI_WAKE_ENABLE_CONST) */

#if(usbUART115200bps_SCB_MODE_UART_CONST_CFG)
    void usbUART115200bps_UartInit(void);
#endif /* (usbUART115200bps_SCB_MODE_UART_CONST_CFG) */

#if(usbUART115200bps_UART_WAKE_ENABLE_CONST)
    void usbUART115200bps_UartSaveConfig(void);
    void usbUART115200bps_UartRestoreConfig(void);
#endif /* (usbUART115200bps_UART_WAKE_ENABLE_CONST) */

/* Interrupt processing */
#define usbUART115200bps_SpiUartEnableIntRx(intSourceMask)  usbUART115200bps_SetRxInterruptMode(intSourceMask)
#define usbUART115200bps_SpiUartEnableIntTx(intSourceMask)  usbUART115200bps_SetTxInterruptMode(intSourceMask)
uint32 usbUART115200bps_SpiUartDisableIntRx(void);
uint32 usbUART115200bps_SpiUartDisableIntTx(void);

#endif /* (CY_SCB_SPI_UART_PVT_usbUART115200bps_H) */


/* [] END OF FILE */
