/*******************************************************************************
* File Name: usbUART115200bps_PM.c
* Version 1.10
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "usbUART115200bps.h"
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


/***************************************
*   Backup Structure declaration
***************************************/

usbUART115200bps_BACKUP_STRUCT usbUART115200bps_backup =
{
    0u, /* enableState */
};


/*******************************************************************************
* Function Name: usbUART115200bps_Sleep
********************************************************************************
*
* Summary:
*  Calls SaveConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_Sleep(void)
{
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)

    if(0u != usbUART115200bps_scbEnableWake)
    {
        if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
        {
            usbUART115200bps_I2CSaveConfig();
        }
        else if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
        {
            usbUART115200bps_SpiSaveConfig();
        }
        else if(usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
        {
            usbUART115200bps_UartSaveConfig();
        }
        else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            usbUART115200bps_EzI2CSaveConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        usbUART115200bps_backup.enableState = (uint8) usbUART115200bps_GET_CTRL_ENABLED;
        
        if(0u != usbUART115200bps_backup.enableState)
        {
            usbUART115200bps_Stop();
        }
    }
    
    usbUART115200bps_DisableTxPinsInputBuffer();
    
#else
    
    #if defined (usbUART115200bps_I2C_WAKE_ENABLE_CONST) && (usbUART115200bps_I2C_WAKE_ENABLE_CONST)
        usbUART115200bps_I2CSaveConfig();
        
    #elif defined (usbUART115200bps_SPI_WAKE_ENABLE_CONST) && (usbUART115200bps_SPI_WAKE_ENABLE_CONST)
        usbUART115200bps_SpiSaveConfig();
        
    #elif defined (usbUART115200bps_UART_WAKE_ENABLE_CONST) && (usbUART115200bps_UART_WAKE_ENABLE_CONST)
        usbUART115200bps_UartSaveConfig();
        
    #elif defined (usbUART115200bps_EZI2C_WAKE_ENABLE_CONST) && (usbUART115200bps_EZI2C_WAKE_ENABLE_CONST)
        usbUART115200bps_EzI2CSaveConfig();
    
    #else
        
        usbUART115200bps_backup.enableState = (uint8) usbUART115200bps_GET_CTRL_ENABLED;
        
        /* Check enable state */
        if(0u != usbUART115200bps_backup.enableState)
        {
            usbUART115200bps_Stop();
        }
        
    #endif /* defined (usbUART115200bps_SCB_MODE_I2C_CONST_CFG) && (usbUART115200bps_I2C_WAKE_ENABLE_CONST) */
    
    usbUART115200bps_DisableTxPinsInputBuffer();
    
#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_Wakeup
********************************************************************************
*
* Summary:
*  Calls RestoreConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_Wakeup(void)
{
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)

    usbUART115200bps_EnableTxPinsInputBuffer();
        
    if(0u != usbUART115200bps_scbEnableWake)
    {
        if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
        {
            usbUART115200bps_I2CRestoreConfig();
        }
        else if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
        {
            usbUART115200bps_SpiRestoreConfig();
        }
        else if(usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
        {
            usbUART115200bps_UartRestoreConfig();
        }
        else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            usbUART115200bps_EzI2CRestoreConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {    
        /* Restore enable state */
        if(0u != usbUART115200bps_backup.enableState)
        {
            usbUART115200bps_Enable();
        }
    }

#else
    
    usbUART115200bps_EnableTxPinsInputBuffer();
        
    #if defined (usbUART115200bps_I2C_WAKE_ENABLE_CONST) && (usbUART115200bps_I2C_WAKE_ENABLE_CONST)
        usbUART115200bps_I2CRestoreConfig();
        
    #elif defined (usbUART115200bps_SPI_WAKE_ENABLE_CONST) && (usbUART115200bps_SPI_WAKE_ENABLE_CONST)
        usbUART115200bps_SpiRestoreConfig();
        
    #elif defined (usbUART115200bps_UART_WAKE_ENABLE_CONST) && (usbUART115200bps_UART_WAKE_ENABLE_CONST)
        usbUART115200bps_UartRestoreConfig();
        
    #elif defined (usbUART115200bps_EZI2C_WAKE_ENABLE_CONST) && (usbUART115200bps_EZI2C_WAKE_ENABLE_CONST)
        usbUART115200bps_EzI2CRestoreConfig();
    
    #else
        /* Check enable state */
        if(0u != usbUART115200bps_backup.enableState)
        {
            usbUART115200bps_Enable();
        }
        
    #endif /* (usbUART115200bps_I2C_WAKE_ENABLE_CONST) */

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_DisableTxPinsInputBuffer
********************************************************************************
*
* Summary:
*  Disables input buffers for TX pins. This action removes leakage current while
*  low power mode (Cypress ID 149635).
*   SCB mode is I2C and EZI2C: bus is pulled-up. Leave pins as it is.
*   SCB mode SPI:
*     Slave  - disable input buffer for MISO pin.
*     Master - disable input buffer for all pins.
*   SCB mode SmartCard: 
*     Standard and IrDA - disable input buffer for TX pin.
*     SmartCard - RX_TX pin is pulled-up. Leave pin as it is.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_DisableTxPinsInputBuffer(void)
{
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    
    /* SCB mode is I2C and EZI2C: bus is pulled-up. Does nothing */
       
    if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
    {
        if(0u != (usbUART115200bps_SPI_CTRL_REG & usbUART115200bps_SPI_CTRL_MASTER))
        /* SPI Master */
        {
        #if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
            usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS |= \
                                                                usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_MASK;
        #endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */

        #if(usbUART115200bps_MOSI_SCL_RX_PIN)
            usbUART115200bps_spi_mosi_i2c_scl_uart_rx_INP_DIS |= usbUART115200bps_spi_mosi_i2c_scl_uart_rx_MASK;
        #endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

        #if(usbUART115200bps_MISO_SDA_TX_PIN)
            usbUART115200bps_spi_miso_i2c_sda_uart_tx_INP_DIS |= usbUART115200bps_spi_miso_i2c_sda_uart_tx_MASK;
        #endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */

        #if(usbUART115200bps_SCLK_PIN)
            usbUART115200bps_spi_sclk_INP_DIS |= usbUART115200bps_spi_sclk_MASK;
        #endif /* (usbUART115200bps_SCLK_PIN) */

        #if(usbUART115200bps_SS0_PIN)
            usbUART115200bps_spi_ss0_INP_DIS |= usbUART115200bps_spi_ss0_MASK;
        #endif /* (usbUART115200bps_SS1_PIN) */

        #if(usbUART115200bps_SS1_PIN)
            usbUART115200bps_spi_ss1_INP_DIS |= usbUART115200bps_spi_ss1_MASK;
        #endif /* (usbUART115200bps_SS1_PIN) */

        #if(usbUART115200bps_SS2_PIN)
            usbUART115200bps_spi_ss2_INP_DIS |= usbUART115200bps_spi_ss2_MASK;
        #endif /* (usbUART115200bps_SS2_PIN) */

        #if(usbUART115200bps_SS3_PIN)
            usbUART115200bps_spi_ss3_INP_DIS |= usbUART115200bps_spi_ss3_MASK;
        #endif /* (usbUART115200bps_SS3_PIN) */
        }
        else
        /* SPI Slave */
        {
        #if(usbUART115200bps_MISO_SDA_TX_PIN)
            usbUART115200bps_spi_miso_i2c_sda_uart_tx_INP_DIS |= usbUART115200bps_spi_miso_i2c_sda_uart_tx_MASK;
        #endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else if (usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
    {
        if(usbUART115200bps_UART_CTRL_MODE_UART_SMARTCARD != 
            (usbUART115200bps_UART_CTRL_REG & usbUART115200bps_UART_CTRL_MODE_MASK))
        /* UART Standard or IrDA */
        {
        #if(usbUART115200bps_MISO_SDA_TX_PIN)
            usbUART115200bps_spi_miso_i2c_sda_uart_tx_INP_DIS |= usbUART115200bps_spi_miso_i2c_sda_uart_tx_MASK;
        #endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else
    {
        /* Does nothing */
    }
    
#else
    
    /* SCB mode is I2C and EZI2C: bus is pulled-up. Does nothing */
        
    /* SCB mode is SPI Master */
    #if(usbUART115200bps_SPI_MASTER_PINS)
        usbUART115200bps_sclk_m_INP_DIS |= usbUART115200bps_sclk_m_MASK;
        usbUART115200bps_mosi_m_INP_DIS |= usbUART115200bps_mosi_m_MASK;
        usbUART115200bps_miso_m_INP_DIS |= usbUART115200bps_miso_m_MASK;
    #endif /* (usbUART115200bps_SPI_MASTER_PINS) */

    #if(usbUART115200bps_SPI_MASTER_SS0_PIN)
        usbUART115200bps_ss0_m_INP_DIS |= usbUART115200bps_ss0_m_MASK;
    #endif /* (usbUART115200bps_SPI_MASTER_SS0_PIN) */

    #if(usbUART115200bps_SPI_MASTER_SS1_PIN)
        usbUART115200bps_ss1_m_INP_DIS |= usbUART115200bps_ss1_m_MASK;
    #endif /* (usbUART115200bps_SPI_MASTER_SS1_PIN) */

    #if(usbUART115200bps_SPI_MASTER_SS2_PIN)
        usbUART115200bps_ss2_m_INP_DIS |= usbUART115200bps_ss2_m_MASK;
    #endif /* (usbUART115200bps_SPI_MASTER_SS2_PIN) */

    #if(usbUART115200bps_SPI_MASTER_SS3_PIN)
        usbUART115200bps_ss3_m_INP_DIS |= usbUART115200bps_ss3_m_MASK;
    #endif /* (usbUART115200bps_SPI_MASTER_SS3_PIN) */
    
    /* SCB mode is SPI Slave */
    #if(usbUART115200bps_SPI_SLAVE_PINS)
        usbUART115200bps_miso_s_INP_DIS |= usbUART115200bps_miso_s_MASK;
    #endif /* (usbUART115200bps_SPI_SLAVE_PINS) */

    /* SCB mode is UART */
    #if(usbUART115200bps_UART_TX_PIN)
        usbUART115200bps_tx_INP_DIS |= usbUART115200bps_tx_MASK;
    #endif /* (usbUART115200bps_UART_TX_PIN) */

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_EnableTxPinsInputBuffer
********************************************************************************
*
* Summary:
*  Enables input buffers for TX pins. Restore changes done byte
*usbUART115200bps_DisableTxPinsInputBuffer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_EnableTxPinsInputBuffer(void)
{
#if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
    if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
    {
        if(0u != (usbUART115200bps_SPI_CTRL_REG & usbUART115200bps_SPI_CTRL_MASTER))
        /* SPI Master */
        {
        #if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
            usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS &= \
                                            (uint32) ~((uint32) usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_MASK);
        #endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */

        #if(usbUART115200bps_MOSI_SCL_RX_PIN)
            usbUART115200bps_spi_mosi_i2c_scl_uart_rx_INP_DIS &= \
                                            (uint32) ~((uint32) usbUART115200bps_spi_mosi_i2c_scl_uart_rx_MASK);
        #endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

        #if(usbUART115200bps_MISO_SDA_TX_PIN)
            usbUART115200bps_spi_miso_i2c_sda_uart_tx_INP_DIS &= \
                                            (uint32) ~((uint32) usbUART115200bps_spi_miso_i2c_sda_uart_tx_MASK);
        #endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */

        #if(usbUART115200bps_SCLK_PIN)
            usbUART115200bps_spi_sclk_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_spi_sclk_MASK);
        #endif /* (usbUART115200bps_SCLK_PIN) */

        #if(usbUART115200bps_SS0_PIN)
            usbUART115200bps_spi_ss0_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_spi_ss0_MASK);
        #endif /* (usbUART115200bps_SS1_PIN) */

        #if(usbUART115200bps_SS1_PIN)
            usbUART115200bps_spi_ss1_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_spi_ss1_MASK);
        #endif /* (usbUART115200bps_SS1_PIN) */

        #if(usbUART115200bps_SS2_PIN)
            usbUART115200bps_spi_ss2_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_spi_ss2_MASK);
        #endif /* (usbUART115200bps_SS2_PIN) */

        #if(usbUART115200bps_SS3_PIN)
            usbUART115200bps_spi_ss3_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_spi_ss3_MASK);
        #endif /* (usbUART115200bps_SS3_PIN) */
        }
        else
        /* SPI Slave */
        {
        #if(usbUART115200bps_MISO_SDA_TX_PIN)
            usbUART115200bps_spi_miso_i2c_sda_uart_tx_INP_DIS &= \
                                                (uint32) ~((uint32) usbUART115200bps_spi_miso_i2c_sda_uart_tx_MASK);
        #endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else if (usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
    {
        if(usbUART115200bps_UART_CTRL_MODE_UART_SMARTCARD != 
                (usbUART115200bps_UART_CTRL_REG & usbUART115200bps_UART_CTRL_MODE_MASK))
        /* UART Standard or IrDA */
        {
        #if(usbUART115200bps_MISO_SDA_TX_PIN)
            usbUART115200bps_spi_miso_i2c_sda_uart_tx_INP_DIS &= \
                                                (uint32) ~((uint32) usbUART115200bps_spi_miso_i2c_sda_uart_tx_MASK);
        #endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else
    {
        /* Does nothing */
    }
    
#else
        
    /* SCB mode is SPI Master */
    #if(usbUART115200bps_SPI_MASTER_PINS)
        usbUART115200bps_sclk_m_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_sclk_m_MASK);
        usbUART115200bps_mosi_m_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_mosi_m_MASK);
        usbUART115200bps_miso_m_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_miso_m_MASK);
    #endif /* (usbUART115200bps_SPI_MASTER_PINS) */

    #if(usbUART115200bps_SPI_MASTER_SS0_PIN)
        usbUART115200bps_ss0_m_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_ss0_m_MASK);
    #endif /* (usbUART115200bps_SPI_MASTER_SS0_PIN) */

    #if(usbUART115200bps_SPI_MASTER_SS1_PIN)
        usbUART115200bps_ss1_m_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_ss1_m_MASK);
    #endif /* (usbUART115200bps_SPI_MASTER_SS1_PIN) */

    #if(usbUART115200bps_SPI_MASTER_SS2_PIN)
        usbUART115200bps_ss2_m_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_ss2_m_MASK);
    #endif /* (usbUART115200bps_SPI_MASTER_SS2_PIN) */

    #if(usbUART115200bps_SPI_MASTER_SS3_PIN)
        usbUART115200bps_ss3_m_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_ss3_m_MASK);
    #endif /* (usbUART115200bps_SPI_MASTER_SS3_PIN) */
    
    /* SCB mode is SPI Slave */
    #if(usbUART115200bps_SPI_SLAVE_PINS)
        usbUART115200bps_miso_s_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_miso_s_MASK);
    #endif /* (usbUART115200bps_SPI_SLAVE_PINS) */

    /* SCB mode is UART */
    #if(usbUART115200bps_UART_TX_PIN)
        usbUART115200bps_tx_INP_DIS &= (uint32) ~((uint32) usbUART115200bps_tx_MASK);
    #endif /* (usbUART115200bps_UART_TX_PIN) */

#endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
