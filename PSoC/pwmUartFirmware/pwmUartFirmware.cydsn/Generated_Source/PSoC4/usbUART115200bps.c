/*******************************************************************************
* File Name: usbUART115200bps.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SCB Component.
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

#if(usbUART115200bps_SCB_MODE_I2C_INC)
    #include "usbUART115200bps_I2C_PVT.h"
#endif /* (usbUART115200bps_SCB_MODE_I2C_INC) */

#if(usbUART115200bps_SCB_MODE_EZI2C_INC)
    #include "usbUART115200bps_EZI2C_PVT.h"
#endif /* (usbUART115200bps_SCB_MODE_EZI2C_INC) */

#if(usbUART115200bps_SCB_MODE_SPI_INC || usbUART115200bps_SCB_MODE_UART_INC)
    #include "usbUART115200bps_SPI_UART_PVT.h"
#endif /* (usbUART115200bps_SCB_MODE_SPI_INC || usbUART115200bps_SCB_MODE_UART_INC) */


/**********************************
*    Run Time Configuration Vars
**********************************/

/* Stores internal component configuration for unconfigured mode */
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    uint8 usbUART115200bps_scbMode = usbUART115200bps_SCB_MODE_UNCONFIG;
    uint8 usbUART115200bps_scbEnableWake;
    uint8 usbUART115200bps_scbEnableIntr;

    /* I2C config vars */
    uint8 usbUART115200bps_mode;
    uint8 usbUART115200bps_acceptAddr;

    /* SPI/UART config vars */
    volatile uint8 * usbUART115200bps_rxBuffer;
    uint8  usbUART115200bps_rxDataBits;
    uint32 usbUART115200bps_rxBufferSize;

    volatile uint8 * usbUART115200bps_txBuffer;
    uint8  usbUART115200bps_txDataBits;
    uint32 usbUART115200bps_txBufferSize;

    /* EZI2C config vars */
    uint8 usbUART115200bps_numberOfAddr;
    uint8 usbUART115200bps_subAddrSize;
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */


/**********************************
*     Common SCB Vars
**********************************/

uint8 usbUART115200bps_initVar = 0u;
cyisraddress usbUART115200bps_customIntrHandler = NULL;


/***************************************
*    Private Function Prototypes
***************************************/

static void usbUART115200bps_ScbEnableIntr(void);
static void usbUART115200bps_ScbModeStop(void);


/*******************************************************************************
* Function Name: usbUART115200bps_Init
********************************************************************************
*
* Summary:
*  Initializes SCB component to operate in one of selected configurations:
*  I2C, SPI, UART, EZI2C or EZSPI.
*  This function does not do any initialization when configuration is set to
*  Unconfigured SCB.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_Init(void)
{
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    if(usbUART115200bps_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        usbUART115200bps_initVar = 0u; /* Clear init var */
    }
    else
    {
        /* Initialization was done before call */
    }

#elif(usbUART115200bps_SCB_MODE_I2C_CONST_CFG)
    usbUART115200bps_I2CInit();

#elif(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)
    usbUART115200bps_SpiInit();

#elif(usbUART115200bps_SCB_MODE_UART_CONST_CFG)
    usbUART115200bps_UartInit();

#elif(usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG)
    usbUART115200bps_EzI2CInit();

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_Enable
********************************************************************************
*
* Summary:
*  Enables SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_Enable(void)
{
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    if(!usbUART115200bps_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        /* Enable SCB block, only if already configured */
        usbUART115200bps_CTRL_REG |= usbUART115200bps_CTRL_ENABLED;
        
        /* Enable interrupt */
        usbUART115200bps_ScbEnableIntr();
    }
#else
    usbUART115200bps_CTRL_REG |= usbUART115200bps_CTRL_ENABLED; /* Enable SCB block */
    
    usbUART115200bps_ScbEnableIntr();
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call the component is enabled and ready for operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  usbUART115200bps_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void usbUART115200bps_Start(void)
{
    if(0u == usbUART115200bps_initVar)
    {
        usbUART115200bps_initVar = 1u; /* Component was initialized */
        usbUART115200bps_Init();       /* Initialize component      */
    }

    usbUART115200bps_Enable();
}


/*******************************************************************************
* Function Name: usbUART115200bps_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_Stop(void)
{
#if(usbUART115200bps_SCB_IRQ_INTERNAL)
    usbUART115200bps_SCB_IRQ_Disable();     /* Disable interrupt before block */
#endif /* (usbUART115200bps_SCB_IRQ_INTERNAL) */

    usbUART115200bps_CTRL_REG &= (uint32) ~usbUART115200bps_CTRL_ENABLED;  /* Disable SCB block */

#if(usbUART115200bps_SCB_IRQ_INTERNAL)
    usbUART115200bps_SCB_IRQ_ClearPending(); /* Clear pending interrupt */
#endif /* (usbUART115200bps_SCB_IRQ_INTERNAL) */
    
    usbUART115200bps_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: usbUART115200bps_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operations such as software buffer management functions
*  before the interrupt returns.  It is user's responsibility to not break the
*  software buffer operations. Only one custom handler is supported, which is
*  the function provided by the most recent call.
*  At initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_SetCustomInterruptHandler(cyisraddress func)
{
    usbUART115200bps_customIntrHandler = func; /* Register interrupt handler */
}


/*******************************************************************************
* Function Name: usbUART115200bps_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables interrupt for specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void usbUART115200bps_ScbEnableIntr(void)
{
#if(usbUART115200bps_SCB_IRQ_INTERNAL)
    #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Enable interrupt source */
        if(0u != usbUART115200bps_scbEnableIntr)
        {
            usbUART115200bps_SCB_IRQ_Enable();
        }
    #else
        usbUART115200bps_SCB_IRQ_Enable();
        
    #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (usbUART115200bps_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Calls Stop function for specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void usbUART115200bps_ScbModeStop(void)
{
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
    {
        usbUART115200bps_I2CStop();
    }
    else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        usbUART115200bps_EzI2CStop();
    }
    else
    {
        /* None of modes above */
    }
#elif(usbUART115200bps_SCB_MODE_I2C_CONST_CFG)
    usbUART115200bps_I2CStop();

#elif(usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG)
    usbUART115200bps_EzI2CStop();

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: usbUART115200bps_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets pins settings accordingly to selected operation mode.
    *  Only available in Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when specific mode of operation
    *  selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Submode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartTxRx:  Direction for UART.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void usbUART115200bps_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx)
    {
        uint32 hsiomSel[usbUART115200bps_SCB_PINS_NUMBER];
        uint32 pinsDm  [usbUART115200bps_SCB_PINS_NUMBER];
        uint32 i;

        /* Make all unused */
        for(i = 0u; i < usbUART115200bps_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i] = usbUART115200bps_HSIOM_DEF_SEL;
            pinsDm[i]   = usbUART115200bps_PIN_DM_ALG_HIZ;
        }

        /* Choice the Dm and HSIOM */
        if((usbUART115200bps_SCB_MODE_I2C   == mode) ||
           (usbUART115200bps_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX] = usbUART115200bps_HSIOM_I2C_SEL;
            hsiomSel[usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_HSIOM_I2C_SEL;

            pinsDm[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX] = usbUART115200bps_PIN_DM_OD_LO;
            pinsDm[usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_PIN_DM_OD_LO;
        }
        else if(usbUART115200bps_SCB_MODE_SPI == mode)
        {
            hsiomSel[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX] = usbUART115200bps_HSIOM_SPI_SEL;
            hsiomSel[usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_HSIOM_SPI_SEL;
            hsiomSel[usbUART115200bps_SCLK_PIN_INDEX]        = usbUART115200bps_HSIOM_SPI_SEL;

            if(usbUART115200bps_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX] = usbUART115200bps_PIN_DM_DIG_HIZ;
                pinsDm[usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_PIN_DM_STRONG;
                pinsDm[usbUART115200bps_SCLK_PIN_INDEX]        = usbUART115200bps_PIN_DM_DIG_HIZ;

            #if(usbUART115200bps_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[usbUART115200bps_SS0_PIN_INDEX] = usbUART115200bps_HSIOM_SPI_SEL;
                pinsDm  [usbUART115200bps_SS0_PIN_INDEX] = usbUART115200bps_PIN_DM_DIG_HIZ;
            #endif /* (usbUART115200bps_SS1_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX] = usbUART115200bps_PIN_DM_STRONG;
                pinsDm[usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_PIN_DM_DIG_HIZ;
                pinsDm[usbUART115200bps_SCLK_PIN_INDEX]        = usbUART115200bps_PIN_DM_STRONG;

            #if(usbUART115200bps_SS0_PIN)
                hsiomSel[usbUART115200bps_SS0_PIN_INDEX] = usbUART115200bps_HSIOM_SPI_SEL;
                pinsDm  [usbUART115200bps_SS0_PIN_INDEX] = usbUART115200bps_PIN_DM_STRONG;
            #endif /* (usbUART115200bps_SS0_PIN) */

            #if(usbUART115200bps_SS1_PIN)
                hsiomSel[usbUART115200bps_SS1_PIN_INDEX] = usbUART115200bps_HSIOM_SPI_SEL;
                pinsDm  [usbUART115200bps_SS1_PIN_INDEX] = usbUART115200bps_PIN_DM_STRONG;
            #endif /* (usbUART115200bps_SS1_PIN) */

            #if(usbUART115200bps_SS2_PIN)
                hsiomSel[usbUART115200bps_SS2_PIN_INDEX] = usbUART115200bps_HSIOM_SPI_SEL;
                pinsDm  [usbUART115200bps_SS2_PIN_INDEX] = usbUART115200bps_PIN_DM_STRONG;
            #endif /* (usbUART115200bps_SS2_PIN) */

            #if(usbUART115200bps_SS3_PIN)
                hsiomSel[usbUART115200bps_SS3_PIN_INDEX] = usbUART115200bps_HSIOM_SPI_SEL;
                pinsDm  [usbUART115200bps_SS3_PIN_INDEX] = usbUART115200bps_PIN_DM_STRONG;
            #endif /* (usbUART115200bps_SS2_PIN) */
            }
        }
        else /* UART */
        {
            if(usbUART115200bps_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_HSIOM_UART_SEL;
                pinsDm  [usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (usbUART115200bps_UART_RX & uartTxRx))
                {
                    hsiomSel[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX] = usbUART115200bps_HSIOM_UART_SEL;
                    pinsDm  [usbUART115200bps_MOSI_SCL_RX_PIN_INDEX] = usbUART115200bps_PIN_DM_DIG_HIZ;
                }

                if(0u != (usbUART115200bps_UART_TX & uartTxRx))
                {
                    hsiomSel[usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_HSIOM_UART_SEL;
                    pinsDm  [usbUART115200bps_MISO_SDA_TX_PIN_INDEX] = usbUART115200bps_PIN_DM_STRONG;
                }
            }
        }

        /* Condfigure pins: set HSIOM and DM */
        /* Condfigure pins: DR registers configuration remains unchanged for cyfitter_cfg() */

    #if(usbUART115200bps_MOSI_SCL_RX_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_MOSI_SCL_RX_HSIOM_REG,
                                       usbUART115200bps_MOSI_SCL_RX_HSIOM_MASK,
                                       usbUART115200bps_MOSI_SCL_RX_HSIOM_POS,
                                       hsiomSel[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX]);
    #endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

    #if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                       usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                       usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                       hsiomSel[usbUART115200bps_MOSI_SCL_RX_WAKE_PIN_INDEX]);
    #endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */

    #if(usbUART115200bps_MISO_SDA_TX_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_MISO_SDA_TX_HSIOM_REG,
                                       usbUART115200bps_MISO_SDA_TX_HSIOM_MASK,
                                       usbUART115200bps_MISO_SDA_TX_HSIOM_POS,
                                       hsiomSel[usbUART115200bps_MISO_SDA_TX_PIN_INDEX]);
    #endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

    #if(usbUART115200bps_SCLK_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_SCLK_HSIOM_REG, usbUART115200bps_SCLK_HSIOM_MASK,
                                       usbUART115200bps_SCLK_HSIOM_POS, hsiomSel[usbUART115200bps_SCLK_PIN_INDEX]);
    #endif /* (usbUART115200bps_SCLK_PIN) */

    #if(usbUART115200bps_SS0_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_SS0_HSIOM_REG, usbUART115200bps_SS0_HSIOM_MASK,
                                       usbUART115200bps_SS0_HSIOM_POS, hsiomSel[usbUART115200bps_SS0_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS1_PIN) */

    #if(usbUART115200bps_SS1_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_SS1_HSIOM_REG, usbUART115200bps_SS1_HSIOM_MASK,
                                       usbUART115200bps_SS1_HSIOM_POS, hsiomSel[usbUART115200bps_SS1_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS1_PIN) */

    #if(usbUART115200bps_SS2_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_SS2_HSIOM_REG, usbUART115200bps_SS2_HSIOM_MASK,
                                       usbUART115200bps_SS2_HSIOM_POS, hsiomSel[usbUART115200bps_SS2_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS2_PIN) */

    #if(usbUART115200bps_SS3_PIN)
        usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_SS3_HSIOM_REG,  usbUART115200bps_SS3_HSIOM_MASK,
                                       usbUART115200bps_SS3_HSIOM_POS, hsiomSel[usbUART115200bps_SS3_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS3_PIN) */



    #if(usbUART115200bps_MOSI_SCL_RX_PIN)
        usbUART115200bps_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8)
                                                               pinsDm[usbUART115200bps_MOSI_SCL_RX_PIN_INDEX]);
    #endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

    #if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
    usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                               pinsDm[usbUART115200bps_MOSI_SCL_RX_WAKE_PIN_INDEX]);

    /* Set interrupt on rising edge */
    usbUART115200bps_SET_INCFG_TYPE(usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                    usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                    usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                    usbUART115200bps_INTCFG_TYPE_FALLING_EDGE);

    #endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */

    #if(usbUART115200bps_MISO_SDA_TX_PIN)
        usbUART115200bps_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8)
                                                                    pinsDm[usbUART115200bps_MISO_SDA_TX_PIN_INDEX]);
    #endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

    #if(usbUART115200bps_SCLK_PIN)
        usbUART115200bps_spi_sclk_SetDriveMode((uint8) pinsDm[usbUART115200bps_SCLK_PIN_INDEX]);
    #endif /* (usbUART115200bps_SCLK_PIN) */

    #if(usbUART115200bps_SS0_PIN)
        usbUART115200bps_spi_ss0_SetDriveMode((uint8) pinsDm[usbUART115200bps_SS0_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS0_PIN) */

    #if(usbUART115200bps_SS1_PIN)
        usbUART115200bps_spi_ss1_SetDriveMode((uint8) pinsDm[usbUART115200bps_SS1_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS1_PIN) */

    #if(usbUART115200bps_SS2_PIN)
        usbUART115200bps_spi_ss2_SetDriveMode((uint8) pinsDm[usbUART115200bps_SS2_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS2_PIN) */

    #if(usbUART115200bps_SS3_PIN)
        usbUART115200bps_spi_ss3_SetDriveMode((uint8) pinsDm[usbUART115200bps_SS3_PIN_INDEX]);
    #endif /* (usbUART115200bps_SS3_PIN) */
    }

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
