/*******************************************************************************
* File Name: usbUART115200bps_UART.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  UART mode.
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


#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Config Structure Initialization
    ***************************************/

    const usbUART115200bps_UART_INIT_STRUCT usbUART115200bps_configUart =
    {
        usbUART115200bps_UART_SUB_MODE,
        usbUART115200bps_UART_DIRECTION,
        usbUART115200bps_UART_DATA_BITS_NUM,
        usbUART115200bps_UART_PARITY_TYPE,
        usbUART115200bps_UART_STOP_BITS_NUM,
        usbUART115200bps_UART_OVS_FACTOR,
        usbUART115200bps_UART_IRDA_LOW_POWER,
        usbUART115200bps_UART_MEDIAN_FILTER_ENABLE,
        usbUART115200bps_UART_RETRY_ON_NACK,
        usbUART115200bps_UART_IRDA_POLARITY,
        usbUART115200bps_UART_DROP_ON_PARITY_ERR,
        usbUART115200bps_UART_DROP_ON_FRAME_ERR,
        usbUART115200bps_UART_WAKE_ENABLE,
        0u,
        NULL,
        0u,
        NULL,
        usbUART115200bps_UART_MP_MODE_ENABLE,
        usbUART115200bps_UART_MP_ACCEPT_ADDRESS,
        usbUART115200bps_UART_MP_RX_ADDRESS,
        usbUART115200bps_UART_MP_RX_ADDRESS_MASK,
        usbUART115200bps_SCB_IRQ_INTERNAL,
        usbUART115200bps_UART_INTR_RX_MASK,
        usbUART115200bps_UART_RX_TRIGGER_LEVEL,
        usbUART115200bps_UART_INTR_TX_MASK,
        usbUART115200bps_UART_TX_TRIGGER_LEVEL
    };


    /*******************************************************************************
    * Function Name: usbUART115200bps_UartInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for SPI operation.
    *
    * Parameters:
    *  config:  Pointer to a structure that contains the following ordered list of
    *           fields. These fields match the selections available in the
    *           customizer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_UartInit(const usbUART115200bps_UART_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due bad fucntion parameter */
        }
        else
        {
            /* Configure pins */
            usbUART115200bps_SetPins(usbUART115200bps_SCB_MODE_UART, config->mode, config->direction);

            /* Store internal configuration */
            usbUART115200bps_scbMode       = (uint8) usbUART115200bps_SCB_MODE_UART;
            usbUART115200bps_scbEnableWake = (uint8) config->enableWake;
            usbUART115200bps_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            usbUART115200bps_rxBuffer      =         config->rxBuffer;
            usbUART115200bps_rxDataBits    = (uint8) config->dataBits;
            usbUART115200bps_rxBufferSize  = (uint8) config->rxBufferSize;

            /* Set TX direction internal variables */
            usbUART115200bps_txBuffer      =         config->txBuffer;
            usbUART115200bps_txDataBits    = (uint8) config->dataBits;
            usbUART115200bps_txBufferSize  = (uint8) config->txBufferSize;


            /* Configure UART interface */
            if(usbUART115200bps_UART_MODE_IRDA == config->mode)
            {
                /* OVS settigns: IrDA */
                usbUART115200bps_CTRL_REG  = ((0u != config->enableIrdaLowPower) ?
                                                (usbUART115200bps_UART_GET_CTRL_OVS_IRDA_LP(config->oversample)) :
                                                (usbUART115200bps_CTRL_OVS_IRDA_OVS16));
            }
            else
            {
                /* OVS settigns: UART and SmartCard */
                usbUART115200bps_CTRL_REG  = usbUART115200bps_GET_CTRL_OVS(config->oversample);
            }

            usbUART115200bps_CTRL_REG     |= usbUART115200bps_GET_CTRL_ADDR_ACCEPT(config->multiprocAcceptAddr) |
                                             usbUART115200bps_CTRL_UART;

            /* Confiuure submode: UART, SmartCard or IrDA */
            usbUART115200bps_UART_CTRL_REG = usbUART115200bps_GET_UART_CTRL_MODE(config->mode);

            /* Configure RX direction */
            usbUART115200bps_UART_RX_CTRL_REG = usbUART115200bps_GET_UART_RX_CTRL_MODE(config->stopBits)              |
                                        usbUART115200bps_GET_UART_RX_CTRL_POLARITY(config->enableInvertedRx)          |
                                        usbUART115200bps_GET_UART_RX_CTRL_MP_MODE(config->enableMultiproc)            |
                                        usbUART115200bps_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(config->dropOnParityErr) |
                                        usbUART115200bps_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(config->dropOnFrameErr);

            if(usbUART115200bps_UART_PARITY_NONE != config->parity)
            {
               usbUART115200bps_UART_RX_CTRL_REG |= usbUART115200bps_GET_UART_RX_CTRL_PARITY(config->parity) |
                                                    usbUART115200bps_UART_RX_CTRL_PARITY_ENABLED;
            }

            usbUART115200bps_RX_CTRL_REG      = usbUART115200bps_GET_RX_CTRL_DATA_WIDTH(config->dataBits)       |
                                                usbUART115200bps_GET_RX_CTRL_MEDIAN(config->enableMedianFilter) |
                                                usbUART115200bps_GET_UART_RX_CTRL_ENABLED(config->direction);

            usbUART115200bps_RX_FIFO_CTRL_REG = usbUART115200bps_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure MP address */
            usbUART115200bps_RX_MATCH_REG     = usbUART115200bps_GET_RX_MATCH_ADDR(config->multiprocAddr) |
                                                usbUART115200bps_GET_RX_MATCH_MASK(config->multiprocAddrMask);

            /* Configure RX direction */
            usbUART115200bps_UART_TX_CTRL_REG = usbUART115200bps_GET_UART_TX_CTRL_MODE(config->stopBits) |
                                                usbUART115200bps_GET_UART_TX_CTRL_RETRY_NACK(config->enableRetryNack);

            if(usbUART115200bps_UART_PARITY_NONE != config->parity)
            {
               usbUART115200bps_UART_TX_CTRL_REG |= usbUART115200bps_GET_UART_TX_CTRL_PARITY(config->parity) |
                                                    usbUART115200bps_UART_TX_CTRL_PARITY_ENABLED;
            }

            usbUART115200bps_TX_CTRL_REG      = usbUART115200bps_GET_TX_CTRL_DATA_WIDTH(config->dataBits)    |
                                                usbUART115200bps_GET_UART_TX_CTRL_ENABLED(config->direction);

            usbUART115200bps_TX_FIFO_CTRL_REG = usbUART115200bps_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);


            /* Configure WAKE interrupt */
            #if(usbUART115200bps_UART_RX_WAKEUP_IRQ)
                usbUART115200bps_RX_WAKEUP_IRQ_StartEx(&usbUART115200bps_UART_WAKEUP_ISR);
                usbUART115200bps_RX_WAKEUP_IRQ_Disable();
            #endif /* (usbUART115200bps_UART_RX_WAKEUP_IRQ) */

            /* Configure interrupt with UART handler */
            usbUART115200bps_SCB_IRQ_Disable();
            usbUART115200bps_SCB_IRQ_SetVector(&usbUART115200bps_SPI_UART_ISR);
            usbUART115200bps_SCB_IRQ_SetPriority((uint8)usbUART115200bps_SCB_IRQ_INTC_PRIOR_NUMBER);

            /* Configure interrupt sources */
            usbUART115200bps_INTR_I2C_EC_MASK_REG = usbUART115200bps_NO_INTR_SOURCES;
            usbUART115200bps_INTR_SPI_EC_MASK_REG = usbUART115200bps_NO_INTR_SOURCES;
            usbUART115200bps_INTR_SLAVE_MASK_REG  = usbUART115200bps_NO_INTR_SOURCES;
            usbUART115200bps_INTR_MASTER_MASK_REG = usbUART115200bps_NO_INTR_SOURCES;
            usbUART115200bps_INTR_RX_MASK_REG     = config->rxInterruptMask;
            usbUART115200bps_INTR_TX_MASK_REG     = config->txInterruptMask;

            /* Clear RX buffer indexes */
            usbUART115200bps_rxBufferHead     = 0u;
            usbUART115200bps_rxBufferTail     = 0u;
            usbUART115200bps_rxBufferOverflow = 0u;

            /* Clrea TX buffer indexes */
            usbUART115200bps_txBufferHead = 0u;
            usbUART115200bps_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: usbUART115200bps_UartInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for SPI operation.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_UartInit(void)
    {
        /* Configure UART interface */
        usbUART115200bps_CTRL_REG = usbUART115200bps_UART_DEFAULT_CTRL;

        /* Confiuure submode: UART, SmartCard or IrDA */
        usbUART115200bps_UART_CTRL_REG = usbUART115200bps_UART_DEFAULT_UART_CTRL;

        /* Configure RX direction */
        usbUART115200bps_UART_RX_CTRL_REG = usbUART115200bps_UART_DEFAULT_UART_RX_CTRL;
        usbUART115200bps_RX_CTRL_REG      = usbUART115200bps_UART_DEFAULT_RX_CTRL;
        usbUART115200bps_RX_FIFO_CTRL_REG = usbUART115200bps_UART_DEFAULT_RX_FIFO_CTRL;
        usbUART115200bps_RX_MATCH_REG     = usbUART115200bps_UART_DEFAULT_RX_MATCH_REG;

        /* Configure TX direction */
        usbUART115200bps_UART_TX_CTRL_REG = usbUART115200bps_UART_DEFAULT_UART_TX_CTRL;
        usbUART115200bps_TX_CTRL_REG      = usbUART115200bps_UART_DEFAULT_TX_CTRL;
        usbUART115200bps_TX_FIFO_CTRL_REG = usbUART115200bps_UART_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with UART handler */
        #if(usbUART115200bps_SCB_IRQ_INTERNAL)
            usbUART115200bps_SCB_IRQ_Disable();
            usbUART115200bps_SCB_IRQ_SetVector(&usbUART115200bps_SPI_UART_ISR);
            usbUART115200bps_SCB_IRQ_SetPriority((uint8)usbUART115200bps_SCB_IRQ_INTC_PRIOR_NUMBER);
        #endif /* (usbUART115200bps_SCB_IRQ_INTERNAL) */

        /* Configure WAKE interrupt */
        #if(usbUART115200bps_UART_RX_WAKEUP_IRQ)
            usbUART115200bps_RX_WAKEUP_IRQ_StartEx(&usbUART115200bps_UART_WAKEUP_ISR);
            usbUART115200bps_RX_WAKEUP_IRQ_Disable();
        #endif /* (usbUART115200bps_UART_RX_WAKEUP_IRQ) */
        
        /* Configure interrupt sources */
        usbUART115200bps_INTR_I2C_EC_MASK_REG = usbUART115200bps_UART_DEFAULT_INTR_I2C_EC_MASK;
        usbUART115200bps_INTR_SPI_EC_MASK_REG = usbUART115200bps_UART_DEFAULT_INTR_SPI_EC_MASK;
        usbUART115200bps_INTR_SLAVE_MASK_REG  = usbUART115200bps_UART_DEFAULT_INTR_SLAVE_MASK;
        usbUART115200bps_INTR_MASTER_MASK_REG = usbUART115200bps_UART_DEFAULT_INTR_MASTER_MASK;
        usbUART115200bps_INTR_RX_MASK_REG     = usbUART115200bps_UART_DEFAULT_INTR_RX_MASK;
        usbUART115200bps_INTR_TX_MASK_REG     = usbUART115200bps_UART_DEFAULT_INTR_TX_MASK;

        #if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
            usbUART115200bps_rxBufferHead     = 0u;
            usbUART115200bps_rxBufferTail     = 0u;
            usbUART115200bps_rxBufferOverflow = 0u;
        #endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

        #if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
            usbUART115200bps_txBufferHead = 0u;
            usbUART115200bps_txBufferTail = 0u;
        #endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */
    }

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: usbUART115200bps_UartSetRxAddress
********************************************************************************
*
* Summary:
*  Sets the hardware detectable receiver address for the UART in Multiprocessor
*  mode.
*
* Parameters:
*  address: Address for hardware address detection.
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_UartSetRxAddress(uint32 address)
{
     uint32 matchReg;

    matchReg = usbUART115200bps_RX_MATCH_REG;

    matchReg &= ((uint32) ~usbUART115200bps_RX_MATCH_ADDR_MASK); /* Clear address bits */
    matchReg |= ((uint32)  (address & usbUART115200bps_RX_MATCH_ADDR_MASK)); /* Set address  */

    usbUART115200bps_RX_MATCH_REG = matchReg;
}


/*******************************************************************************
* Function Name: usbUART115200bps_UartSetRxAddressMask
********************************************************************************
*
* Summary:
*  Sets the hardware address mask for the UART in Multiprocessor mode.
*
* Parameters:
*  addressMask: Address mask.
*   0 - address bit does not care while comparison.
*   1 - address bit is significant while comparison.
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_UartSetRxAddressMask(uint32 addressMask)
{
    uint32 matchReg;

    matchReg = usbUART115200bps_RX_MATCH_REG;

    matchReg &= ((uint32) ~usbUART115200bps_RX_MATCH_MASK_MASK); /* Clear address mask bits */
    matchReg |= ((uint32) (addressMask << usbUART115200bps_RX_MATCH_MASK_POS));

    usbUART115200bps_RX_MATCH_REG = matchReg;
}


#if(usbUART115200bps_UART_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: usbUART115200bps_UartGetChar
    ********************************************************************************
    *
    * Summary:
    *  Retrieves next data element from receive buffer.
    *  This function is designed for ASCII characters and returns a char
    *  where 1 to 255 is valid characters and 0 indicates an error occurred or
    *  no data is present.
    *  RX software buffer disabled: returns data element retrieved from RX FIFO.
    *  Undefined data will be returned if the RX FIFO is empty.
    *  RX software buffer enabled: Returns data element from the software receive
    *  buffer.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Next data element from the receive buffer.
    *  ASCII character values from 1 to 255 are valid.
    *  A returned zero signifies an error condition or no data available.
    *
    *******************************************************************************/
    uint32 usbUART115200bps_UartGetChar(void)
    {
        uint32 rxData = 0u;

        /* Read data only if there is data to read */
        if(0u != usbUART115200bps_SpiUartGetRxBufferSize())
        {
            rxData = usbUART115200bps_SpiUartReadRxData();
        }

        if(usbUART115200bps_CHECK_INTR_RX(usbUART115200bps_INTR_RX_ERR))
        {
            rxData = 0u; /* Error occured: return zero */
            usbUART115200bps_ClearRxInterruptSource(usbUART115200bps_INTR_RX_ERR);
        }

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_UartGetByte
    ********************************************************************************
    *
    * Summary:
    *  Retrieves next data element from the receive buffer, returns received byte
    *  and error condition.
    *  RX software buffer disabled: Returns data element retrieved from RX FIFO.
    *  Undefined data will be returned if the RX FIFO is empty.
    *  RX software buffer enabled: Returns data element from the software receive
    *  buffer.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Bits 15-8 contains status and bits 7-0 contains the next data element from
    *  receive buffer. If the bits 15-8 are nonzero, an error has occurred.
    *
    *******************************************************************************/
    uint32 usbUART115200bps_UartGetByte(void)
    {
        uint32 rxData;
        uint32 tmpStatus;
        uint32 intSourceMask;

        intSourceMask = usbUART115200bps_SpiUartDisableIntRx();

        if(0u != usbUART115200bps_SpiUartGetRxBufferSize())
        {
             /*
             * Enable interrupt to receive more bytes: at least one byte is in
             * buffer.
             */
            usbUART115200bps_SpiUartEnableIntRx(intSourceMask);

            /* Get received byte */
            rxData = usbUART115200bps_SpiUartReadRxData();
        }
        else
        {
            /*
            * Read byte directly from RX FIFO: the underflow is raised in case
            * of empty. In other case the first received byte will be read.
            */
            rxData = usbUART115200bps_RX_FIFO_RD_REG;

            /*
            * Enable interrupt to receive more bytes.
            * The RX_NOT_EMPTY interrupt is cleared by interrupt routine in case
            * byte was received and read above.
            */
            usbUART115200bps_SpiUartEnableIntRx(intSourceMask);
        }

        /* Get and clear RX error mask */
        tmpStatus = (usbUART115200bps_GetRxInterruptSource() & usbUART115200bps_INTR_RX_ERR);
        usbUART115200bps_ClearRxInterruptSource(usbUART115200bps_INTR_RX_ERR);

        /*
        * Put together data and error status:
        * MP mode and accept address: the 9th bit is set to notify mark.
        */
        rxData |= ((uint32) (tmpStatus << 8u));

        return(rxData);
    }

#endif /* (usbUART115200bps_UART_RX_DIRECTION) */


#if(usbUART115200bps_UART_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: usbUART115200bps_UartPutString
    ********************************************************************************
    *
    * Summary:
    *  Places a NULL terminated string in the transmit buffer to be sent at the
    *  next available bus time.
    *  This function is blocking and waits until there is a space available to put
    *  all requested data in transmit buffer.
    *
    * Parameters:
    *  string: pointer to the null terminated string array to be placed in the
    *          transmit buffer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_UartPutString(const char8 string[])
    {
        uint32 bufIndex;

        bufIndex = 0u;

        /* Blocks the control flow until all data will be sent */
        while(string[bufIndex] != ((char8) 0))
        {
            usbUART115200bps_UartPutChar((uint32) string[bufIndex]);
            bufIndex++;
        }
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_UartPutCRLF
    ********************************************************************************
    *
    * Summary:
    *  Places byte of data followed by a carriage return (0x0D) and line feed (0x0A)
    *  to the transmit buffer.
    *  This function is blocking and waits until there is a space available to put
    *  all requested data in transmit buffer.
    *
    * Parameters:
    *  txDataByte : the data to be transmitted.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_UartPutCRLF(uint32 txDataByte)
    {
        usbUART115200bps_UartPutChar(txDataByte);  /* Blocks the control flow until all data will be sent */
        usbUART115200bps_UartPutChar(0x0Du);       /* Blocks the control flow until all data will be sent */
        usbUART115200bps_UartPutChar(0x0Au);       /* Blocks the control flow until all data will be sent */
    }
#endif /* (usbUART115200bps_UART_TX_DIRECTION) */


#if(usbUART115200bps_UART_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: usbUART115200bps_UartSaveConfig
    ********************************************************************************
    *
    * Summary:
    *  Wakeup disabled: does nothing.
    *  Wakeup enabled: clears SCB_backup.enableStateto keep component enabled while
    *  DeepSleep. Clears and enables interrupt on falling edge of rx input. The GPIO
    *  event wakes up the device and SKIP_START feature allows UART continue
    *  receiving data bytes properly. The GPIO interrupt does not track in active mode
    *  therefore requires to be cleared by this API. It makes uart wakeup single
    *  triggered event.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_UartSaveConfig(void)
    {
        /* Clear interrupt activy:
        *  - set skip start and disable RX. On GPIO wakeup the RX will be enabled.
        *  - clear rx_wake interrupt source as it triggers while normal operations.
        *  - clear wake interrupt pending state as it becomes pending in active mode.
        */

        usbUART115200bps_UART_RX_CTRL_REG |= usbUART115200bps_UART_RX_CTRL_SKIP_START;

        #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
            #if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
                (void) usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_ClearInterrupt();
            #endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */
        #else
            #if(usbUART115200bps_UART_RX_WAKE_PIN)
                (void) usbUART115200bps_rx_wake_ClearInterrupt();
            #endif /* (usbUART115200bps_UART_RX_WAKE_PIN) */
        #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

        #if(usbUART115200bps_UART_RX_WAKEUP_IRQ)
            usbUART115200bps_RX_WAKEUP_IRQ_ClearPending();
            usbUART115200bps_RX_WAKEUP_IRQ_Enable();
        #endif /* (usbUART115200bps_UART_RX_WAKEUP_IRQ) */
    }


    /*******************************************************************************
    * Function Name: usbUART115200bps_UartRestoreConfig
    ********************************************************************************
    *
    * Summary:
    *  Does nothing.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_UartRestoreConfig(void)
    {
        /* Disable RX GPIO interrupt: no more triggers in active mode */
        #if(usbUART115200bps_UART_RX_WAKEUP_IRQ)
            usbUART115200bps_RX_WAKEUP_IRQ_Disable();
        #endif /* (usbUART115200bps_UART_RX_WAKEUP_IRQ) */
    }
#endif /* (usbUART115200bps_UART_WAKE_ENABLE_CONST) */


#if(usbUART115200bps_UART_RX_WAKEUP_IRQ)
    /*******************************************************************************
    * Function Name: usbUART115200bps_UART_WAKEUP_ISR
    ********************************************************************************
    *
    * Summary:
    *  Handles Interrupt Service Routine for SCB UART mode GPIO wakeup event.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    CY_ISR(usbUART115200bps_UART_WAKEUP_ISR)
    {
        /* Clear interrupt source: the event becomes multi triggerred and only disabled
        * by usbUART115200bps_UartRestoreConfig() call.
        */
        #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
            #if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
                (void) usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_ClearInterrupt();
            #endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */
        #else
            #if(usbUART115200bps_UART_RX_WAKE_PIN)
                (void) usbUART115200bps_rx_wake_ClearInterrupt();
            #endif /* (usbUART115200bps_UART_RX_WAKE_PIN) */
        #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
    }
#endif /* (usbUART115200bps_UART_RX_WAKEUP_IRQ) */


/* [] END OF FILE */
