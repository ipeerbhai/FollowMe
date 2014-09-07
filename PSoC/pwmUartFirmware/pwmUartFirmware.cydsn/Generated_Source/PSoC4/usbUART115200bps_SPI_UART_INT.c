/*******************************************************************************
* File Name: usbUART115200bps_SPI_UART_INT.c
* Version 1.10
*
* Description:
*  This file provides the source code to the Interrupt Servive Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "usbUART115200bps_PVT.h"
#include "usbUART115200bps_SPI_UART_PVT.h"


/*******************************************************************************
* Function Name: usbUART115200bps_SPI_UART_ISR
********************************************************************************
*
* Summary:
*  Handles Interrupt Service Routine for SCB SPI or UART modes.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
CY_ISR(usbUART115200bps_SPI_UART_ISR)
{
    #if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locHead;
        uint32 dataRx;
    #endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */

    if(NULL != usbUART115200bps_customIntrHandler)
    {
        usbUART115200bps_customIntrHandler(); /* Call customer routine if needed */
    }

    #if(usbUART115200bps_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        usbUART115200bps_ClearSpiExtClkInterruptSource(usbUART115200bps_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if(usbUART115200bps_CHECK_RX_SW_BUFFER)
    {
        /* Get data from RX FIFO */
        if(usbUART115200bps_CHECK_INTR_RX_MASKED(usbUART115200bps_INTR_RX_NOT_EMPTY))
        {
            while(0u != usbUART115200bps_GET_RX_FIFO_ENTRIES)
            {
                /* Get data from RX FIFO */
                dataRx = usbUART115200bps_RX_FIFO_RD_REG;

                /* Move local head index */
                locHead = (usbUART115200bps_rxBufferHead + 1u);

                /* Adjust local head index */
                if(usbUART115200bps_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if(locHead == usbUART115200bps_rxBufferTail)
                {
                    /* Overflow: through away new data */
                    usbUART115200bps_rxBufferOverflow = (uint8) usbUART115200bps_INTR_RX_OVERFLOW;
                }
                else
                {
                    /* Store received data */
                    usbUART115200bps_PutWordInRxBuffer(locHead, dataRx);

                    /* Move head index */
                    usbUART115200bps_rxBufferHead = locHead;
                }
            }

            usbUART115200bps_ClearRxInterruptSource(usbUART115200bps_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if(usbUART115200bps_CHECK_TX_SW_BUFFER)
    {
        if(usbUART115200bps_CHECK_INTR_TX_MASKED(usbUART115200bps_INTR_TX_NOT_FULL))
        {
            /* Put data into TX FIFO */
            while(usbUART115200bps_FIFO_SIZE != usbUART115200bps_GET_TX_FIFO_ENTRIES)
            {
                /* There is a data in TX software buffer */
                if(usbUART115200bps_txBufferHead != usbUART115200bps_txBufferTail)
                {
                    /* Mode local tail index */
                    locTail = (usbUART115200bps_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if(usbUART115200bps_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    usbUART115200bps_TX_FIFO_WR_REG = usbUART115200bps_GetWordFromTxBuffer(locTail);

                    /* Mode tail index */
                    usbUART115200bps_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is EMPTY: end of transmitting */
                    usbUART115200bps_DISABLE_INTR_TX(usbUART115200bps_INTR_TX_NOT_FULL);
                    break;
                }
            }

            usbUART115200bps_ClearTxInterruptSource(usbUART115200bps_INTR_TX_NOT_FULL);
        }
    }
    #endif
}


/* [] END OF FILE */
