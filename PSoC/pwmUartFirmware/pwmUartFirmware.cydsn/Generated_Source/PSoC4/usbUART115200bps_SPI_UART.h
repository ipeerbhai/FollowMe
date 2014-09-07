/*******************************************************************************
* File Name: usbUART115200bps_SPI_UART.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_usbUART115200bps_H)
#define CY_SCB_SPI_UART_usbUART115200bps_H

#include "usbUART115200bps.h"


/***************************************
*   SPI Initial Parameter Constants
****************************************/

#define usbUART115200bps_SPI_MODE                   (0u)
#define usbUART115200bps_SPI_SUB_MODE               (0u)
#define usbUART115200bps_SPI_CLOCK_MODE             (0u)
#define usbUART115200bps_SPI_OVS_FACTOR             (16u)
#define usbUART115200bps_SPI_MEDIAN_FILTER_ENABLE   (0u)
#define usbUART115200bps_SPI_LATE_MISO_SAMPLE_ENABLE (0u)
#define usbUART115200bps_SPI_RX_DATA_BITS_NUM       (8u)
#define usbUART115200bps_SPI_TX_DATA_BITS_NUM       (8u)
#define usbUART115200bps_SPI_WAKE_ENABLE            (0u)
#define usbUART115200bps_SPI_BITS_ORDER             (1u)
#define usbUART115200bps_SPI_TRANSFER_SEPARATION    (1u)
#define usbUART115200bps_SPI_NUMBER_OF_SS_LINES     (1u)
#define usbUART115200bps_SPI_RX_BUFFER_SIZE         (8u)
#define usbUART115200bps_SPI_TX_BUFFER_SIZE         (8u)

#define usbUART115200bps_SPI_INTERRUPT_MODE         (0u)

#define usbUART115200bps_SPI_INTR_RX_MASK           (0u)
#define usbUART115200bps_SPI_INTR_TX_MASK           (0u)

#define usbUART115200bps_SPI_RX_TRIGGER_LEVEL       (7u)
#define usbUART115200bps_SPI_TX_TRIGGER_LEVEL       (0u)


/***************************************
*   UART Initial Parameter Constants
****************************************/

#define usbUART115200bps_UART_SUB_MODE              (0u)
#define usbUART115200bps_UART_DIRECTION             (3u)
#define usbUART115200bps_UART_DATA_BITS_NUM         (8u)
#define usbUART115200bps_UART_PARITY_TYPE           (2u)
#define usbUART115200bps_UART_STOP_BITS_NUM         (2u)
#define usbUART115200bps_UART_OVS_FACTOR            (12u)
#define usbUART115200bps_UART_IRDA_LOW_POWER        (0u)
#define usbUART115200bps_UART_MEDIAN_FILTER_ENABLE  (0u)
#define usbUART115200bps_UART_RETRY_ON_NACK         (0u)
#define usbUART115200bps_UART_IRDA_POLARITY         (0u)
#define usbUART115200bps_UART_DROP_ON_FRAME_ERR     (0u)
#define usbUART115200bps_UART_DROP_ON_PARITY_ERR    (0u)
#define usbUART115200bps_UART_WAKE_ENABLE           (0u)
#define usbUART115200bps_UART_RX_BUFFER_SIZE        (8u)
#define usbUART115200bps_UART_TX_BUFFER_SIZE        (8u)
#define usbUART115200bps_UART_MP_MODE_ENABLE        (0u)
#define usbUART115200bps_UART_MP_ACCEPT_ADDRESS     (0u)
#define usbUART115200bps_UART_MP_RX_ADDRESS         (2u)
#define usbUART115200bps_UART_MP_RX_ADDRESS_MASK    (255u)

#define usbUART115200bps_UART_INTERRUPT_MODE        (0u)

#define usbUART115200bps_UART_INTR_RX_MASK          (0u)
#define usbUART115200bps_UART_INTR_TX_MASK          (0u)

#define usbUART115200bps_UART_RX_TRIGGER_LEVEL      (7u)
#define usbUART115200bps_UART_TX_TRIGGER_LEVEL      (0u)

/* Sources of RX errors */
#define usbUART115200bps_INTR_RX_ERR        (usbUART115200bps_INTR_RX_OVERFLOW    | \
                                             usbUART115200bps_INTR_RX_UNDERFLOW   | \
                                             usbUART115200bps_INTR_RX_FRAME_ERROR | \
                                             usbUART115200bps_INTR_RX_PARITY_ERROR)

/* UART direction enum */
#define usbUART115200bps_UART_RX    (1u)
#define usbUART115200bps_UART_TX    (2u)
#define usbUART115200bps_UART_TX_RX (3u)


/***************************************
*   Conditional Compilation Parameters
****************************************/

#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)

    /* Direction */
    #define usbUART115200bps_RX_DIRECTION           (1u)
    #define usbUART115200bps_TX_DIRECTION           (1u)
    #define usbUART115200bps_UART_RX_DIRECTION      (1u)
    #define usbUART115200bps_UART_TX_DIRECTION      (1u)

    /* Only external RX and TX buffer for uncofigured mode */
    #define usbUART115200bps_INTERNAL_RX_SW_BUFFER   (0u)
    #define usbUART115200bps_INTERNAL_TX_SW_BUFFER   (0u)

    /* Get RX and TX buffer size */
    #define usbUART115200bps_RX_BUFFER_SIZE (usbUART115200bps_rxBufferSize)
    #define usbUART115200bps_TX_BUFFER_SIZE (usbUART115200bps_txBufferSize)

    /* Return true if buffer is provided */
    #define usbUART115200bps_CHECK_RX_SW_BUFFER (NULL != usbUART115200bps_rxBuffer)
    #define usbUART115200bps_CHECK_TX_SW_BUFFER (NULL != usbUART115200bps_txBuffer)

    /* Alwasy provde global variables to support RX and TX buffers */
    #define usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST    (1u)
    #define usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST    (1u)

    /* Get wakeup enable option */
    #define usbUART115200bps_SPI_WAKE_ENABLE_CONST  (1u)
    #define usbUART115200bps_CHECK_SPI_WAKE_ENABLE  (0u != usbUART115200bps_scbEnableWake)
    #define usbUART115200bps_UART_WAKE_ENABLE_CONST (1u)

#else

    /* SPI internal RX and TX buffers */
    #define usbUART115200bps_INTERNAL_SPI_RX_SW_BUFFER  (usbUART115200bps_SPI_RX_BUFFER_SIZE > \
                                                                                            usbUART115200bps_FIFO_SIZE)
    #define usbUART115200bps_INTERNAL_SPI_TX_SW_BUFFER  (usbUART115200bps_SPI_TX_BUFFER_SIZE > \
                                                                                            usbUART115200bps_FIFO_SIZE)

    /* UART internal RX and TX buffers */
    #define usbUART115200bps_INTERNAL_UART_RX_SW_BUFFER  (usbUART115200bps_UART_RX_BUFFER_SIZE > \
                                                                                            usbUART115200bps_FIFO_SIZE)
    #define usbUART115200bps_INTERNAL_UART_TX_SW_BUFFER  (usbUART115200bps_UART_TX_BUFFER_SIZE > \
                                                                                            usbUART115200bps_FIFO_SIZE)

    /* SPI Direction */
    #define usbUART115200bps_SPI_RX_DIRECTION (1u)
    #define usbUART115200bps_SPI_TX_DIRECTION (1u)

    /* UART Direction */
    #define usbUART115200bps_UART_RX_DIRECTION (0u != (usbUART115200bps_UART_DIRECTION & usbUART115200bps_UART_RX))
    #define usbUART115200bps_UART_TX_DIRECTION (0u != (usbUART115200bps_UART_DIRECTION & usbUART115200bps_UART_TX))

    /* Direction */
    #define usbUART115200bps_RX_DIRECTION ((usbUART115200bps_SCB_MODE_SPI_CONST_CFG) ? \
                                            (usbUART115200bps_SPI_RX_DIRECTION) : (usbUART115200bps_UART_RX_DIRECTION))

    #define usbUART115200bps_TX_DIRECTION ((usbUART115200bps_SCB_MODE_SPI_CONST_CFG) ? \
                                            (usbUART115200bps_SPI_TX_DIRECTION) : (usbUART115200bps_UART_TX_DIRECTION))

    /* Internal RX and TX buffer: for SPI or UART */
    #if(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)

        /* Internal SPI RX and TX buffer */
        #define usbUART115200bps_INTERNAL_RX_SW_BUFFER  (usbUART115200bps_INTERNAL_SPI_RX_SW_BUFFER)
        #define usbUART115200bps_INTERNAL_TX_SW_BUFFER  (usbUART115200bps_INTERNAL_SPI_TX_SW_BUFFER)

        /* Internal SPI RX and TX buffer size */
        #define usbUART115200bps_RX_BUFFER_SIZE         (usbUART115200bps_SPI_RX_BUFFER_SIZE + 1u)
        #define usbUART115200bps_TX_BUFFER_SIZE         (usbUART115200bps_SPI_TX_BUFFER_SIZE)
        
        /* Get wakeup enable option */
        #define usbUART115200bps_SPI_WAKE_ENABLE_CONST  (0u != usbUART115200bps_SPI_WAKE_ENABLE)
        #define usbUART115200bps_UART_WAKE_ENABLE_CONST (0u)

    #else

        /* Internal UART RX and TX buffer */
        #define usbUART115200bps_INTERNAL_RX_SW_BUFFER  (usbUART115200bps_INTERNAL_UART_RX_SW_BUFFER)
        #define usbUART115200bps_INTERNAL_TX_SW_BUFFER  (usbUART115200bps_INTERNAL_UART_TX_SW_BUFFER)

        /* Internal UART RX and TX buffer size */
        #define usbUART115200bps_RX_BUFFER_SIZE         (usbUART115200bps_UART_RX_BUFFER_SIZE + 1u)
        #define usbUART115200bps_TX_BUFFER_SIZE         (usbUART115200bps_UART_TX_BUFFER_SIZE)
        
        /* Get wakeup enable option */
        #define usbUART115200bps_SPI_WAKE_ENABLE_CONST  (0u)
        #define usbUART115200bps_UART_WAKE_ENABLE_CONST (0u != usbUART115200bps_UART_WAKE_ENABLE)
    #endif /* (usbUART115200bps_SCB_MODE_SPI_CONST_CFG) */

    /* Internal RX and TX buffer: for SPI or UART. Used in conditional compilation check */
    #define usbUART115200bps_CHECK_RX_SW_BUFFER (usbUART115200bps_INTERNAL_RX_SW_BUFFER)
    #define usbUART115200bps_CHECK_TX_SW_BUFFER (usbUART115200bps_INTERNAL_TX_SW_BUFFER)

    /* Provide global variables to support RX and TX buffers */
    #define usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST    (usbUART115200bps_INTERNAL_RX_SW_BUFFER)
    #define usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST    (usbUART115200bps_INTERNAL_TX_SW_BUFFER)
    
    /* Wakeup for SPI */
    #define usbUART115200bps_CHECK_SPI_WAKE_ENABLE  (usbUART115200bps_SPI_WAKE_ENABLE_CONST)

#endif /* End (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Bootloader communication interface enable: NOT supported yet */
#define usbUART115200bps_SPI_BTLDR_COMM_ENABLED   ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

#define usbUART115200bps_UART_BTLDR_COMM_ENABLED   ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))


/***************************************
*       Type Definitions
***************************************/

/* usbUART115200bps_SPI_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 submode;
    uint32 sclkMode;
    uint32 oversample;
    uint32 enableMedianFilter;
    uint32 enableLateSampling;
    uint32 enableWake;
    uint32 rxDataBits;
    uint32 txDataBits;
    uint32 bitOrder;
    uint32 transferSeperation;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
} usbUART115200bps_SPI_INIT_STRUCT;

/* usbUART115200bps_UART_INIT_STRUCT */
typedef struct
{
    uint32 mode;
    uint32 direction;
    uint32 dataBits;
    uint32 parity;
    uint32 stopBits;
    uint32 oversample;
    uint32 enableIrdaLowPower;
    uint32 enableMedianFilter;
    uint32 enableRetryNack;
    uint32 enableInvertedRx;
    uint32 dropOnParityErr;
    uint32 dropOnFrameErr;
    uint32 enableWake;
    uint32 rxBufferSize;
    uint8* rxBuffer;
    uint32 txBufferSize;
    uint8* txBuffer;
    uint32 enableMultiproc;
    uint32 multiprocAcceptAddr;
    uint32 multiprocAddr;
    uint32 multiprocAddrMask;
    uint32 enableInterrupt;
    uint32 rxInterruptMask;
    uint32 rxTriggerLevel;
    uint32 txInterruptMask;
    uint32 txTriggerLevel;
} usbUART115200bps_UART_INIT_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

/* SPI specific functions */
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    void usbUART115200bps_SpiInit(const usbUART115200bps_SPI_INIT_STRUCT *config);
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(usbUART115200bps_SCB_MODE_SPI_INC)
    void usbUART115200bps_SpiSetActiveSlaveSelect(uint32 activeSelect);
#endif /* (usbUART115200bps_SCB_MODE_SPI_INC) */

/* UART specific functions */
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    void usbUART115200bps_UartInit(const usbUART115200bps_UART_INIT_STRUCT *config);
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

#if(usbUART115200bps_SCB_MODE_UART_INC)
    void usbUART115200bps_UartSetRxAddress(uint32 address);
    void usbUART115200bps_UartSetRxAddressMask(uint32 addressMask);
#endif /* (usbUART115200bps_SCB_MODE_UART_INC) */

/* UART RX direction APIs */
#if(usbUART115200bps_UART_RX_DIRECTION)
    uint32 usbUART115200bps_UartGetChar(void);
    uint32 usbUART115200bps_UartGetByte(void);
#endif /* (usbUART115200bps_UART_RX_DIRECTION) */

/* UART TX direction APIs */
#if(usbUART115200bps_UART_TX_DIRECTION)
    #define usbUART115200bps_UartPutChar(ch)    usbUART115200bps_SpiUartWriteTxData((uint32)(ch))
    void usbUART115200bps_UartPutString(const char8 string[]);
    void usbUART115200bps_UartPutCRLF(uint32 txDataByte);
#endif /* (usbUART115200bps_UART_TX_DIRECTION) */

/* Common APIs Rx direction */
#if(usbUART115200bps_RX_DIRECTION)
    uint32 usbUART115200bps_SpiUartReadRxData(void);
    uint32 usbUART115200bps_SpiUartGetRxBufferSize(void);
    void   usbUART115200bps_SpiUartClearRxBuffer(void);
#endif /* (usbUART115200bps_RX_DIRECTION) */

/* Common APIs Tx direction */
#if(usbUART115200bps_TX_DIRECTION)
    void   usbUART115200bps_SpiUartWriteTxData(uint32 txDataByte);
    void   usbUART115200bps_SpiUartPutArray(const uint8 wrBuf[], uint32 count);
    void   usbUART115200bps_SpiUartClearTxBuffer(void);
    uint32 usbUART115200bps_SpiUartGetTxBufferSize(void);
#endif /* (usbUART115200bps_TX_DIRECTION) */

CY_ISR_PROTO(usbUART115200bps_SPI_UART_ISR);

#if(usbUART115200bps_UART_RX_WAKEUP_IRQ)
    CY_ISR_PROTO(usbUART115200bps_UART_WAKEUP_ISR);
#endif /* (usbUART115200bps_UART_RX_WAKEUP_IRQ) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (usbUART115200bps_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void usbUART115200bps_SpiCyBtldrCommStart(void);
    void usbUART115200bps_SpiCyBtldrCommStop (void);
    void usbUART115200bps_SpiCyBtldrCommReset(void);
    cystatus usbUART115200bps_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus usbUART115200bps_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (usbUART115200bps_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (usbUART115200bps_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void usbUART115200bps_UartCyBtldrCommStart(void);
    void usbUART115200bps_UartCyBtldrCommStop (void);
    void usbUART115200bps_UartCyBtldrCommReset(void);
    cystatus usbUART115200bps_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus usbUART115200bps_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (usbUART115200bps_UART_BTLDR_COMM_ENABLED) */


/***************************************
*     Buffer Access Macro Definitions
***************************************/

#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    /* RX direction */
    void   usbUART115200bps_PutWordInRxBuffer  (uint32 idx, uint32 rxDataByte);
    uint32 usbUART115200bps_GetWordFromRxBuffer(uint32 idx);

    /* TX direction */
    void   usbUART115200bps_PutWordInTxBuffer  (uint32 idx, uint32 txDataByte);
    uint32 usbUART115200bps_GetWordFromTxBuffer(uint32 idx);

#else

    /* RX direction */
    #if(usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST)
        #define usbUART115200bps_PutWordInRxBuffer(idx, rxDataByte) \
                do{                                                 \
                    usbUART115200bps_rxBufferInternal[(idx)] = ((uint8) (rxDataByte)); \
                }while(0)

        #define usbUART115200bps_GetWordFromRxBuffer(idx) usbUART115200bps_rxBufferInternal[(idx)]

    #endif /* (usbUART115200bps_INTERNAL_RX_SW_BUFFER_CONST) */

    /* TX direction */
    #if(usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST)
        #define usbUART115200bps_PutWordInTxBuffer(idx, txDataByte) \
                    do{                                             \
                        usbUART115200bps_txBufferInternal[(idx)] = ((uint8) (txDataByte)); \
                    }while(0)

        #define usbUART115200bps_GetWordFromTxBuffer(idx) usbUART115200bps_txBufferInternal[(idx)]

    #endif /* (usbUART115200bps_INTERNAL_TX_SW_BUFFER_CONST) */

#endif /* (usbUART115200bps_TX_SW_BUFFER_ENABLE) */


/***************************************
*         SPI API Constants
***************************************/

/* SPI mode enum */
#define usbUART115200bps_SPI_SLAVE  (0u)
#define usbUART115200bps_SPI_MASTER (1u)

/* SPI sub mode enum */
#define usbUART115200bps_SPI_MODE_MOTOROLA      (0x00u)
#define usbUART115200bps_SPI_MODE_TI_COINCIDES  (0x01u)
#define usbUART115200bps_SPI_MODE_TI_PRECEDES   (0x11u)
#define usbUART115200bps_SPI_MODE_NATIONAL      (0x02u)
#define usbUART115200bps_SPI_MODE_MASK          (0x03u)
#define usbUART115200bps_SPI_MODE_TI_PRECEDES_MASK  (0x10u)

/* SPI phase and polarity mode enum */
#define usbUART115200bps_SPI_SCLK_CPHA0_CPOL0   (0x00u)
#define usbUART115200bps_SPI_SCLK_CPHA0_CPOL1   (0x02u)
#define usbUART115200bps_SPI_SCLK_CPHA1_CPOL0   (0x01u)
#define usbUART115200bps_SPI_SCLK_CPHA1_CPOL1   (0x03u)

/* SPI bits order enum */
#define usbUART115200bps_BITS_ORDER_LSB_FIRST   (0u)
#define usbUART115200bps_BITS_ORDER_MSB_FIRST   (1u)

/* SPI transfer separation enum */
#define usbUART115200bps_SPI_TRANSFER_SEPARATED     (0u)
#define usbUART115200bps_SPI_TRANSFER_CONTINUOUS    (1u)

/* "activeSS" constants for SpiSetActiveSlaveSelect() function */
#define usbUART115200bps_SPIM_ACTIVE_SS0    (0x00u)
#define usbUART115200bps_SPIM_ACTIVE_SS1    (0x01u)
#define usbUART115200bps_SPIM_ACTIVE_SS2    (0x02u)
#define usbUART115200bps_SPIM_ACTIVE_SS3    (0x03u)


/***************************************
*         UART API Constants
***************************************/

/* UART sub-modes enum */
#define usbUART115200bps_UART_MODE_STD          (0u)
#define usbUART115200bps_UART_MODE_SMARTCARD    (1u)
#define usbUART115200bps_UART_MODE_IRDA         (2u)

/* UART direction enum */
#define usbUART115200bps_UART_RX    (1u)
#define usbUART115200bps_UART_TX    (2u)
#define usbUART115200bps_UART_TX_RX (3u)

/* UART parity enum */
#define usbUART115200bps_UART_PARITY_EVEN   (0u)
#define usbUART115200bps_UART_PARITY_ODD    (1u)
#define usbUART115200bps_UART_PARITY_NONE   (2u)

/* UART stop bits enum */
#define usbUART115200bps_UART_STOP_BITS_1   (1u)
#define usbUART115200bps_UART_STOP_BITS_1_5 (2u)
#define usbUART115200bps_UART_STOP_BITS_2   (3u)

/* UART IrDA low power OVS enum */
#define usbUART115200bps_UART_IRDA_LP_OVS16     (16u)
#define usbUART115200bps_UART_IRDA_LP_OVS32     (32u)
#define usbUART115200bps_UART_IRDA_LP_OVS48     (48u)
#define usbUART115200bps_UART_IRDA_LP_OVS96     (96u)
#define usbUART115200bps_UART_IRDA_LP_OVS192    (192u)
#define usbUART115200bps_UART_IRDA_LP_OVS768    (768u)
#define usbUART115200bps_UART_IRDA_LP_OVS1536   (1536u)

/* Uart MP: mark (address) and space (data) bit definitions */
#define usbUART115200bps_UART_MP_MARK       (0x100u)
#define usbUART115200bps_UART_MP_SPACE      (0x000u)


/***************************************
*     Vars with External Linkage
***************************************/

#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    extern const usbUART115200bps_SPI_INIT_STRUCT  usbUART115200bps_configSpi;
    extern const usbUART115200bps_UART_INIT_STRUCT usbUART115200bps_configUart;
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*    Specific SPI Macro Definitions
***************************************/

#define usbUART115200bps_GET_SPI_INTR_SLAVE_MASK(sourceMask)  ((sourceMask) & usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR)
#define usbUART115200bps_GET_SPI_INTR_MASTER_MASK(sourceMask) ((sourceMask) & usbUART115200bps_INTR_MASTER_SPI_DONE)
#define usbUART115200bps_GET_SPI_INTR_RX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR)

#define usbUART115200bps_GET_SPI_INTR_TX_MASK(sourceMask) \
                                             ((sourceMask) & (uint32) ~usbUART115200bps_INTR_MASTER_SPI_DONE)


/***************************************
*    Specific UART Macro Definitions
***************************************/

#define usbUART115200bps_UART_GET_CTRL_OVS_IRDA_LP(oversample) \
        ((usbUART115200bps_UART_IRDA_LP_OVS16   == (oversample)) ? usbUART115200bps_CTRL_OVS_IRDA_LP_OVS16 : \
         ((usbUART115200bps_UART_IRDA_LP_OVS32   == (oversample)) ? usbUART115200bps_CTRL_OVS_IRDA_LP_OVS32 : \
          ((usbUART115200bps_UART_IRDA_LP_OVS48   == (oversample)) ? usbUART115200bps_CTRL_OVS_IRDA_LP_OVS48 : \
           ((usbUART115200bps_UART_IRDA_LP_OVS96   == (oversample)) ? usbUART115200bps_CTRL_OVS_IRDA_LP_OVS96 : \
            ((usbUART115200bps_UART_IRDA_LP_OVS192  == (oversample)) ? usbUART115200bps_CTRL_OVS_IRDA_LP_OVS192 : \
             ((usbUART115200bps_UART_IRDA_LP_OVS768  == (oversample)) ? usbUART115200bps_CTRL_OVS_IRDA_LP_OVS768 : \
              ((usbUART115200bps_UART_IRDA_LP_OVS1536 == (oversample)) ? usbUART115200bps_CTRL_OVS_IRDA_LP_OVS1536 : \
                                                                          usbUART115200bps_CTRL_OVS_IRDA_LP_OVS16)))))))

#define usbUART115200bps_GET_UART_RX_CTRL_ENABLED(direction) ((0u != (usbUART115200bps_UART_RX & (direction))) ? \
                                                                    (usbUART115200bps_RX_CTRL_ENABLED) : (0u))

#define usbUART115200bps_GET_UART_TX_CTRL_ENABLED(direction) ((0u != (usbUART115200bps_UART_TX & (direction))) ? \
                                                                    (usbUART115200bps_TX_CTRL_ENABLED) : (0u))


/***************************************
*        SPI Register Settings
***************************************/

#define usbUART115200bps_CTRL_SPI      (usbUART115200bps_CTRL_MODE_SPI)
#define usbUART115200bps_SPI_RX_CTRL   (usbUART115200bps_RX_CTRL_ENABLED)
#define usbUART115200bps_SPI_TX_CTRL   (usbUART115200bps_TX_CTRL_ENABLED)


/***************************************
*       SPI Init Register Settings
***************************************/

#if(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)

    /* SPI Configuration */
    #define usbUART115200bps_SPI_DEFAULT_CTRL \
                    (usbUART115200bps_GET_CTRL_OVS(usbUART115200bps_SPI_OVS_FACTOR)         | \
                     usbUART115200bps_GET_CTRL_EC_AM_MODE(usbUART115200bps_SPI_WAKE_ENABLE) | \
                     usbUART115200bps_CTRL_SPI)

    #define usbUART115200bps_SPI_DEFAULT_SPI_CTRL \
                    (usbUART115200bps_GET_SPI_CTRL_CONTINUOUS    (usbUART115200bps_SPI_TRANSFER_SEPARATION)       | \
                     usbUART115200bps_GET_SPI_CTRL_SELECT_PRECEDE(usbUART115200bps_SPI_SUB_MODE &                   \
                                                                  usbUART115200bps_SPI_MODE_TI_PRECEDES_MASK)     | \
                     usbUART115200bps_GET_SPI_CTRL_SCLK_MODE     (usbUART115200bps_SPI_CLOCK_MODE)                | \
                     usbUART115200bps_GET_SPI_CTRL_LATE_MISO_SAMPLE(usbUART115200bps_SPI_LATE_MISO_SAMPLE_ENABLE) | \
                     usbUART115200bps_GET_SPI_CTRL_SUB_MODE      (usbUART115200bps_SPI_SUB_MODE)                  | \
                     usbUART115200bps_GET_SPI_CTRL_MASTER_MODE   (usbUART115200bps_SPI_MODE))

    /* RX direction */
    #define usbUART115200bps_SPI_DEFAULT_RX_CTRL \
                    (usbUART115200bps_GET_RX_CTRL_DATA_WIDTH(usbUART115200bps_SPI_RX_DATA_BITS_NUM)     | \
                     usbUART115200bps_GET_RX_CTRL_BIT_ORDER (usbUART115200bps_SPI_BITS_ORDER)           | \
                     usbUART115200bps_GET_RX_CTRL_MEDIAN    (usbUART115200bps_SPI_MEDIAN_FILTER_ENABLE) | \
                     usbUART115200bps_SPI_RX_CTRL)

    #define usbUART115200bps_SPI_DEFAULT_RX_FIFO_CTRL \
                    usbUART115200bps_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(usbUART115200bps_SPI_RX_TRIGGER_LEVEL)

    /* TX direction */
    #define usbUART115200bps_SPI_DEFAULT_TX_CTRL \
                    (usbUART115200bps_GET_TX_CTRL_DATA_WIDTH(usbUART115200bps_SPI_TX_DATA_BITS_NUM) | \
                     usbUART115200bps_GET_TX_CTRL_BIT_ORDER (usbUART115200bps_SPI_BITS_ORDER)       | \
                     usbUART115200bps_SPI_TX_CTRL)

    #define usbUART115200bps_SPI_DEFAULT_TX_FIFO_CTRL \
                    usbUART115200bps_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(usbUART115200bps_SPI_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define usbUART115200bps_SPI_DEFAULT_INTR_SPI_EC_MASK   (usbUART115200bps_NO_INTR_SOURCES)

    #define usbUART115200bps_SPI_DEFAULT_INTR_I2C_EC_MASK   (usbUART115200bps_NO_INTR_SOURCES)
    #define usbUART115200bps_SPI_DEFAULT_INTR_SLAVE_MASK \
                    (usbUART115200bps_SPI_INTR_RX_MASK & usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR)

    #define usbUART115200bps_SPI_DEFAULT_INTR_MASTER_MASK \
                    (usbUART115200bps_SPI_INTR_TX_MASK & usbUART115200bps_INTR_MASTER_SPI_DONE)

    #define usbUART115200bps_SPI_DEFAULT_INTR_RX_MASK \
                    (usbUART115200bps_SPI_INTR_RX_MASK & (uint32) ~usbUART115200bps_INTR_SLAVE_SPI_BUS_ERROR)

    #define usbUART115200bps_SPI_DEFAULT_INTR_TX_MASK \
                    (usbUART115200bps_SPI_INTR_TX_MASK & (uint32) ~usbUART115200bps_INTR_MASTER_SPI_DONE)

#endif /* (usbUART115200bps_SCB_MODE_SPI_CONST_CFG) */


/***************************************
*        UART Register Settings
***************************************/

#define usbUART115200bps_CTRL_UART      (usbUART115200bps_CTRL_MODE_UART)
#define usbUART115200bps_UART_RX_CTRL   (usbUART115200bps_RX_CTRL_LSB_FIRST) /* LSB for UART goes first */
#define usbUART115200bps_UART_TX_CTRL   (usbUART115200bps_TX_CTRL_LSB_FIRST) /* LSB for UART goes first */


/***************************************
*      UART Init Register Settings
***************************************/

#if(usbUART115200bps_SCB_MODE_UART_CONST_CFG)

    /* UART configuration */
    #if(usbUART115200bps_UART_MODE_IRDA == usbUART115200bps_UART_SUB_MODE)

        #define usbUART115200bps_DEFAULT_CTRL_OVS   ((0u != usbUART115200bps_UART_IRDA_LOW_POWER) ?              \
                                (usbUART115200bps_UART_GET_CTRL_OVS_IRDA_LP(usbUART115200bps_UART_OVS_FACTOR)) : \
                                (usbUART115200bps_CTRL_OVS_IRDA_OVS16))

    #else

        #define usbUART115200bps_DEFAULT_CTRL_OVS   usbUART115200bps_GET_CTRL_OVS(usbUART115200bps_UART_OVS_FACTOR)

    #endif /* (usbUART115200bps_UART_MODE_IRDA == usbUART115200bps_UART_SUB_MODE) */

    #define usbUART115200bps_UART_DEFAULT_CTRL \
                                (usbUART115200bps_GET_CTRL_ADDR_ACCEPT(usbUART115200bps_UART_MP_ACCEPT_ADDRESS) | \
                                 usbUART115200bps_DEFAULT_CTRL_OVS                                              | \
                                 usbUART115200bps_CTRL_UART)

    #define usbUART115200bps_UART_DEFAULT_UART_CTRL \
                                    (usbUART115200bps_GET_UART_CTRL_MODE(usbUART115200bps_UART_SUB_MODE))

    /* RX direction */
    #define usbUART115200bps_UART_DEFAULT_RX_CTRL_PARITY \
                                ((usbUART115200bps_UART_PARITY_NONE != usbUART115200bps_UART_PARITY_TYPE) ?      \
                                  (usbUART115200bps_GET_UART_RX_CTRL_PARITY(usbUART115200bps_UART_PARITY_TYPE) | \
                                   usbUART115200bps_UART_RX_CTRL_PARITY_ENABLED) : (0u))

    #define usbUART115200bps_UART_DEFAULT_UART_RX_CTRL \
                    (usbUART115200bps_GET_UART_RX_CTRL_MODE(usbUART115200bps_UART_STOP_BITS_NUM)                    | \
                     usbUART115200bps_GET_UART_RX_CTRL_POLARITY(usbUART115200bps_UART_IRDA_POLARITY)                | \
                     usbUART115200bps_GET_UART_RX_CTRL_MP_MODE(usbUART115200bps_UART_MP_MODE_ENABLE)                | \
                     usbUART115200bps_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(usbUART115200bps_UART_DROP_ON_PARITY_ERR) | \
                     usbUART115200bps_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(usbUART115200bps_UART_DROP_ON_FRAME_ERR)   | \
                     usbUART115200bps_UART_DEFAULT_RX_CTRL_PARITY)

    #define usbUART115200bps_UART_DEFAULT_RX_CTRL \
                                (usbUART115200bps_GET_RX_CTRL_DATA_WIDTH(usbUART115200bps_UART_DATA_BITS_NUM)        | \
                                 usbUART115200bps_GET_RX_CTRL_MEDIAN    (usbUART115200bps_UART_MEDIAN_FILTER_ENABLE) | \
                                 usbUART115200bps_GET_UART_RX_CTRL_ENABLED(usbUART115200bps_UART_DIRECTION))

    #define usbUART115200bps_UART_DEFAULT_RX_FIFO_CTRL \
                                usbUART115200bps_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(usbUART115200bps_UART_RX_TRIGGER_LEVEL)

    #define usbUART115200bps_UART_DEFAULT_RX_MATCH_REG  ((0u != usbUART115200bps_UART_MP_MODE_ENABLE) ?          \
                                (usbUART115200bps_GET_RX_MATCH_ADDR(usbUART115200bps_UART_MP_RX_ADDRESS) | \
                                 usbUART115200bps_GET_RX_MATCH_MASK(usbUART115200bps_UART_MP_RX_ADDRESS_MASK)) : (0u))

    /* TX direction */
    #define usbUART115200bps_UART_DEFAULT_TX_CTRL_PARITY (usbUART115200bps_UART_DEFAULT_RX_CTRL_PARITY)

    #define usbUART115200bps_UART_DEFAULT_UART_TX_CTRL \
                                (usbUART115200bps_GET_UART_TX_CTRL_MODE(usbUART115200bps_UART_STOP_BITS_NUM)       | \
                                 usbUART115200bps_GET_UART_TX_CTRL_RETRY_NACK(usbUART115200bps_UART_RETRY_ON_NACK) | \
                                 usbUART115200bps_UART_DEFAULT_TX_CTRL_PARITY)

    #define usbUART115200bps_UART_DEFAULT_TX_CTRL \
                                (usbUART115200bps_GET_TX_CTRL_DATA_WIDTH(usbUART115200bps_UART_DATA_BITS_NUM) | \
                                 usbUART115200bps_GET_UART_TX_CTRL_ENABLED(usbUART115200bps_UART_DIRECTION))

    #define usbUART115200bps_UART_DEFAULT_TX_FIFO_CTRL \
                                usbUART115200bps_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(usbUART115200bps_UART_TX_TRIGGER_LEVEL)

    /* Interrupt sources */
    #define usbUART115200bps_UART_DEFAULT_INTR_I2C_EC_MASK  (usbUART115200bps_NO_INTR_SOURCES)
    #define usbUART115200bps_UART_DEFAULT_INTR_SPI_EC_MASK  (usbUART115200bps_NO_INTR_SOURCES)
    #define usbUART115200bps_UART_DEFAULT_INTR_SLAVE_MASK   (usbUART115200bps_NO_INTR_SOURCES)
    #define usbUART115200bps_UART_DEFAULT_INTR_MASTER_MASK  (usbUART115200bps_NO_INTR_SOURCES)
    #define usbUART115200bps_UART_DEFAULT_INTR_RX_MASK      (usbUART115200bps_UART_INTR_RX_MASK)
    #define usbUART115200bps_UART_DEFAULT_INTR_TX_MASK      (usbUART115200bps_UART_INTR_TX_MASK)

#endif /* (usbUART115200bps_SCB_MODE_UART_CONST_CFG) */

#endif /* CY_SCB_SPI_UART_usbUART115200bps_H */


/* [] END OF FILE */
