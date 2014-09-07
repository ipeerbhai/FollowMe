/*******************************************************************************
* File Name: usbUART115200bps_SPI_UART.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
*******************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "usbUART115200bps_PVT.h"
#include "usbUART115200bps_SPI_UART_PVT.h"

/***************************************
*        SPI/UART Private Vars
***************************************/

#if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
    volatile uint32 usbUART115200bps_rxBufferHead;
    volatile uint32 usbUART115200bps_rxBufferTail;
    volatile uint8  usbUART115200bps_rxBufferOverflow;
#endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

#if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
    volatile uint32 usbUART115200bps_txBufferHead;
    volatile uint32 usbUART115200bps_txBufferTail;
#endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */

#if(usbUART115200bps_INTERNAL_RX_SW_BUFFER)
    /* Add one element to the buffer to receive full packet. One byte in receive buffer is always empty */
    volatile uint8 usbUART115200bps_rxBufferInternal[usbUART115200bps_RX_BUFFER_SIZE];
#endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER) */

#if(usbUART115200bps_INTERNAL_TX_SW_BUFFER)
    volatile uint8 usbUART115200bps_txBufferInternal[usbUART115200bps_TX_BUFFER_SIZE];
#endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER) */


#if(usbUART115200bps_RX_DIRECTION)

    /*******************************************************************************
    * Function Name: usbUART115200bps_SpiUartReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Retrieves the next data element from the receive buffer. Undefined data will
    *  be returned if the RX buffer is empty.
    *  Call usbUART115200bps_SpiUartGetRxBufferSize() to return buffer size.
    *   - RX software buffer disabled: Returns data element retrieved from RX FIFO.
    *   - RX software buffer enabled: Returns data element from the software
    *     receive buffer.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Next data element from the receive buffer.
    *
    * Global Variables:
    *  Look into usbUART115200bps_SpiInit for description.
    *
    *******************************************************************************/
    uint32 usbUART115200bps_SpiUartReadRxData(void)
    {
        uint32 rxData = 0u;

        #if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 locTail;
        #endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(usbUART115200bps_CHECK_RX_SW_BUFFER)
        {
            if(usbUART115200bps_rxBufferHead != usbUART115200bps_rxBufferTail)
            {
                /* There is data in RX software buffer */

                /* Calculate index to read from */
                locTail = (usbUART115200bps_rxBufferTail + 1u);

                if(usbUART115200bps_RX_BUFFER_SIZE == locTail)
                {
                    locTail = 0u;
                }

                /* Get data fron RX software buffer */
                rxData = usbUART115200bps_GetWordFromRxBuffer(locTail);

                /* Change index in the buffer */
                usbUART115200bps_rxBufferTail = locTail;
            }
        }
        #else
        {
            rxData = usbUART115200bps_RX_FIFO_RD_REG; /* Read data from RX FIFO */
        }
        #endif

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_SpiUartGetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of received data elements in the receive buffer.
    *   - RX software buffer disabled: returns the number of used entries in
    *     RX FIFO.
    *   - RX software buffer enabled: returns the number of elements which were
    *     placed in receive buffer.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of received data elements
    *
    *******************************************************************************/
    uint32 usbUART115200bps_SpiUartGetRxBufferSize(void)
    {
        uint32 size;
        #if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 locHead;
        #endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(usbUART115200bps_CHECK_RX_SW_BUFFER)
        {
            locHead = usbUART115200bps_rxBufferHead;

            if(locHead >= usbUART115200bps_rxBufferTail)
            {
                size = (locHead - usbUART115200bps_rxBufferTail);
            }
            else
            {
                size = (locHead + (usbUART115200bps_RX_BUFFER_SIZE - usbUART115200bps_rxBufferTail));
            }
        }
        #else
        {
            size = usbUART115200bps_GET_RX_FIFO_ENTRIES;
        }
        #endif

        return(size);
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_SpiUartClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clear the receive buffer and RX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_SpiUartClearRxBuffer(void)
    {
        #if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
            uint32 intSourceMask;
        #endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(usbUART115200bps_CHECK_RX_SW_BUFFER)
        {
            intSourceMask = usbUART115200bps_SpiUartDisableIntRx();

            usbUART115200bps_CLEAR_RX_FIFO;

            /* Flush RX software buffer */
            usbUART115200bps_rxBufferHead     = usbUART115200bps_rxBufferTail;
            usbUART115200bps_rxBufferOverflow = 0u;

            /* End RX transfer */
            usbUART115200bps_ClearRxInterruptSource(usbUART115200bps_INTR_RX_ALL);

            usbUART115200bps_SpiUartEnableIntRx(intSourceMask);
        }
        #else
        {
            usbUART115200bps_CLEAR_RX_FIFO;
        }
        #endif
    }

#endif /* (usbUART115200bps_RX_DIRECTION) */


#if(usbUART115200bps_TX_DIRECTION)

    /*******************************************************************************
    * Function Name: usbUART115200bps_SpiUartWriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Places a data entry into the transmit buffer to be sent at the next available
    *  bus time.
    *  This function is blocking and waits until there is space available to put the
    *  requested data in the transmit buffer.
    *
    * Parameters:
    *  txDataByte: the data to be transmitted.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_SpiUartWriteTxData(uint32 txDataByte)
    {
        #if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 locHead;
            uint32 intSourceMask;
        #endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(usbUART115200bps_CHECK_TX_SW_BUFFER)
        {
            /* Head index to put data */
            locHead = (usbUART115200bps_txBufferHead + 1u);

            /* Adjust TX software buffer index */
            if(usbUART115200bps_TX_BUFFER_SIZE == locHead)
            {
                locHead = 0u;
            }

            while(locHead == usbUART115200bps_txBufferTail)
            {
                /* Wait for space in the TX software buffer */
            }

            /* The TX software buffer has at least one room */

            if((usbUART115200bps_txBufferHead == usbUART115200bps_txBufferTail) &&
               (usbUART115200bps_FIFO_SIZE != usbUART115200bps_GET_TX_FIFO_ENTRIES))
            {
                /* TX software buffer is empty: put data directly in TX FIFO */
                usbUART115200bps_TX_FIFO_WR_REG = txDataByte;
            }
            /* Put data in the TX software buffer */
            else
            {
                /* Clear old status of INTR_TX_EMPTY. It sets at the end of transfer: TX FIFO empty. */
                usbUART115200bps_ClearTxInterruptSource(usbUART115200bps_INTR_TX_NOT_FULL);

                usbUART115200bps_PutWordInTxBuffer(locHead, txDataByte);

                usbUART115200bps_txBufferHead = locHead;

                /* Enable interrupt to transmit */
                intSourceMask  = usbUART115200bps_INTR_TX_NOT_FULL;
                intSourceMask |= usbUART115200bps_GetTxInterruptMode();
                usbUART115200bps_SpiUartEnableIntTx(intSourceMask);
            }
        }
        #else
        {
            while(usbUART115200bps_FIFO_SIZE == usbUART115200bps_GET_TX_FIFO_ENTRIES)
            {
                /* Block while TX FIFO is FULL */
            }

            usbUART115200bps_TX_FIFO_WR_REG = txDataByte;
        }
        #endif
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_SpiUartPutArray
    ********************************************************************************
    *
    * Summary:
    *  Places an array of data into the transmit buffer to be sent.
    *  This function is blocking and waits until there is a space available to put
    *  all the requested data in the transmit buffer. The array size can be greater
    *  than transmit buffer size.
    *
    * Parameters:
    *  wrBuf:  pointer to an array with data to be placed in transmit buffer.
    *  count:  number of data elements to be placed in the transmit buffer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_SpiUartPutArray(const uint8 wrBuf[], uint32 count)
    {
        uint32 i;

        for(i=0u; i < count; i++)
        {
            usbUART115200bps_SpiUartWriteTxData((uint32) wrBuf[i]);
        }
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_SpiUartGetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Returns the number of elements currently in the transmit buffer.
    *  TX software buffer disabled: returns the number of used entries in TX FIFO.
    *  TX software buffer enabled: returns the number of elements currently used
    *  in the transmit buffer. This number does not include used entries in the
    *  TX FIFO. The transmit buffer size is zero until the TX FIFO is full.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Number of data elements ready to transmit.
    *
    *******************************************************************************/
    uint32 usbUART115200bps_SpiUartGetTxBufferSize(void)
    {
        uint32 size;
        #if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 locTail;
        #endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(usbUART115200bps_CHECK_TX_SW_BUFFER)
        {
            /* Get current Tail index */
            locTail = usbUART115200bps_txBufferTail;

            if(usbUART115200bps_txBufferHead >= locTail)
            {
                size = (usbUART115200bps_txBufferHead - locTail);
            }
            else
            {
                size = (usbUART115200bps_txBufferHead + (usbUART115200bps_TX_BUFFER_SIZE - locTail));
            }
        }
        #else
        {
            size = usbUART115200bps_GET_TX_FIFO_ENTRIES;
        }
        #endif

        return(size);
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_SpiUartClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the transmit buffer and TX FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_SpiUartClearTxBuffer(void)
    {
        #if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
            uint32 intSourceMask;
        #endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */

        #if(usbUART115200bps_CHECK_TX_SW_BUFFER)
        {
            intSourceMask = usbUART115200bps_SpiUartDisableIntTx();

            usbUART115200bps_CLEAR_TX_FIFO;

            /* Flush TX software buffer */
            usbUART115200bps_txBufferHead = usbUART115200bps_txBufferTail;

            /* End TX transfer if it is in progress */
            intSourceMask &= (uint32) ~usbUART115200bps_INTR_TX_NOT_FULL;

            usbUART115200bps_SpiUartEnableIntTx(intSourceMask);
        }
        #else
        {
            usbUART115200bps_CLEAR_TX_FIFO;
        }
        #endif
    }

#endif /* (usbUART115200bps_TX_DIRECTION) */


/*******************************************************************************
* Function Name: usbUART115200bps_SpiUartDisableIntRx
********************************************************************************
*
* Summary:
*  Disables RX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns RX interrupt soureces enabled before function call.
*
*******************************************************************************/
uint32 usbUART115200bps_SpiUartDisableIntRx(void)
{
    uint32 intSource;

    intSource = usbUART115200bps_GetRxInterruptMode();

    usbUART115200bps_SetRxInterruptMode(usbUART115200bps_NO_INTR_SOURCES);

    return(intSource);
}


/*******************************************************************************
* Function Name: usbUART115200bps_SpiUartDisableIntTx
********************************************************************************
*
* Summary:
*  Disables TX interrupt sources.
*
* Parameters:
*  None
*
* Return:
*  Returns TX interrupt soureces enabled before function call.
*
*******************************************************************************/
uint32 usbUART115200bps_SpiUartDisableIntTx(void)
{
    uint32 intSourceMask;

    intSourceMask = usbUART115200bps_GetTxInterruptMode();

    usbUART115200bps_SetTxInterruptMode(usbUART115200bps_NO_INTR_SOURCES);

    return(intSourceMask);
}


#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)

    /*******************************************************************************
    * Function Name: usbUART115200bps_PutWordInRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores byte/word into the RX buffer.
    *  Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  index:      index to store data byte/word in the RX buffer.
    *  rxDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_PutWordInRxBuffer(uint32 idx, uint32 rxDataByte)
    {
        /* Put data in the buffer */
        if(usbUART115200bps_ONE_BYTE_WIDTH == usbUART115200bps_rxDataBits)
        {
            usbUART115200bps_rxBuffer[idx] = ((uint8) rxDataByte);
        }
        else
        {
            usbUART115200bps_rxBuffer[(uint32)(idx << 1u)]      = LO8(LO16(rxDataByte));
            usbUART115200bps_rxBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(rxDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_GetWordFromRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from RX buffer.
    *  Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Returns byte/word read from RX buffer.
    *
    *******************************************************************************/
    uint32 usbUART115200bps_GetWordFromRxBuffer(uint32 idx)
    {
        uint32 value;

        if(usbUART115200bps_ONE_BYTE_WIDTH == usbUART115200bps_rxDataBits)
        {
            value = usbUART115200bps_rxBuffer[idx];
        }
        else
        {
            value  = (uint32) usbUART115200bps_rxBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32)usbUART115200bps_rxBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return(value);
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_PutWordInTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Stores byte/word into the TX buffer.
    * Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  idx:        index to store data byte/word in the TX buffer.
    *  txDataByte: byte/word to store.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_PutWordInTxBuffer(uint32 idx, uint32 txDataByte)
    {
        /* Put data in the buffer */
        if(usbUART115200bps_ONE_BYTE_WIDTH == usbUART115200bps_txDataBits)
        {
            usbUART115200bps_txBuffer[idx] = ((uint8) txDataByte);
        }
        else
        {
            usbUART115200bps_txBuffer[(uint32)(idx << 1u)]      = LO8(LO16(txDataByte));
            usbUART115200bps_txBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(txDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_GetWordFromTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Reads byte/word from TX buffer.
    *  Only available in Unconfigured operation mode.
    *
    * Parameters:
    *  idx: index to get data byte/word from the TX buffer.
    *
    * Return:
    *  Returns byte/word read from TX buffer.
    *
    *******************************************************************************/
    uint32 usbUART115200bps_GetWordFromTxBuffer(uint32 idx)
    {
        uint32 value;

        if(usbUART115200bps_ONE_BYTE_WIDTH == usbUART115200bps_txDataBits)
        {
            value = (uint32) usbUART115200bps_txBuffer[idx];
        }
        else
        {
            value  = (uint32) usbUART115200bps_txBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32) usbUART115200bps_txBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return(value);
    }

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
