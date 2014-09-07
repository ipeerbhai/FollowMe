/*******************************************************************************
* File Name: usbUART115200bps_BOOT.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the bootloader
*  communication support in SCB Component.
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

#if(usbUART115200bps_SCB_MODE_I2C_INC)
    #include "usbUART115200bps_I2C.h"
#endif /* (usbUART115200bps_SCB_MODE_I2C_INC) */

#if(usbUART115200bps_SCB_MODE_EZI2C_INC)
    #include "usbUART115200bps_EZI2C.h"
#endif /* (usbUART115200bps_SCB_MODE_EZI2C_INC) */

#if(usbUART115200bps_SCB_MODE_SPI_INC || usbUART115200bps_SCB_MODE_UART_INC)
    #include "usbUART115200bps_SPI_UART.h"
#endif /* (usbUART115200bps_SCB_MODE_SPI_INC || usbUART115200bps_SCB_MODE_UART_INC) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/*******************************************************************************
* Function Name: usbUART115200bps_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls Start function fucntion of the bootloader communication component for
*  selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_CyBtldrCommStart(void)
{
    #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
        if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
        {
            usbUART115200bps_I2CCyBtldrCommStart();
        }
        else if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
        {
            usbUART115200bps_SpiCyBtldrCommStart();
        }
        else if(usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
        {
            usbUART115200bps_UartCyBtldrCommStart();
        }
        else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             usbUART115200bps_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(usbUART115200bps_SCB_MODE_I2C_CONST_CFG)
        usbUART115200bps_I2CCyBtldrCommStart();

    #elif(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)
        usbUART115200bps_SpiCyBtldrCommStart();

    #elif(usbUART115200bps_SCB_MODE_UART_CONST_CFG)
        usbUART115200bps_UartCyBtldrCommStart();

    #elif(usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG)
        usbUART115200bps_EzI2CCyBtldrCommStart();

    #else
        /* Do nothing */

    #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls Stop function fucntion of the bootloader communication component for
*  selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_CyBtldrCommStop(void)
{
    #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
        if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
        {
            usbUART115200bps_I2CCyBtldrCommStop();
        }
        else if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
        {
            usbUART115200bps_SpiCyBtldrCommStop();
        }
        else if(usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
        {
            usbUART115200bps_UartCyBtldrCommStop();
        }
        else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            usbUART115200bps_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(usbUART115200bps_SCB_MODE_I2C_CONST_CFG)
        usbUART115200bps_I2CCyBtldrCommStop();

    #elif(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)
        usbUART115200bps_SpiCyBtldrCommStop();

    #elif(usbUART115200bps_SCB_MODE_UART_CONST_CFG)
        usbUART115200bps_UartCyBtldrCommStop();

    #elif(usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG)
        usbUART115200bps_EzI2CCyBtldrCommStop();

    #else
        /* Do nothing */

    #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls reset function fucntion of the bootloader communication component for
*  selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void usbUART115200bps_CyBtldrCommReset(void)
{
    #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
        if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
        {
            usbUART115200bps_I2CCyBtldrCommReset();
        }
        else if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
        {
            usbUART115200bps_SpiCyBtldrCommReset();
        }
        else if(usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
        {
            usbUART115200bps_UartCyBtldrCommReset();
        }
        else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            usbUART115200bps_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(usbUART115200bps_SCB_MODE_I2C_CONST_CFG)
        usbUART115200bps_I2CCyBtldrCommReset();

    #elif(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)
        usbUART115200bps_SpiCyBtldrCommReset();

    #elif(usbUART115200bps_SCB_MODE_UART_CONST_CFG)
        usbUART115200bps_UartCyBtldrCommReset();

    #elif(usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG)
        usbUART115200bps_EzI2CCyBtldrCommReset();

    #else
        /* Do nothing */

    #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: usbUART115200bps_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls read fucntion of the bootloader communication component for selected
*  mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus usbUART115200bps_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
        if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = usbUART115200bps_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = usbUART115200bps_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
        {
            status = usbUART115200bps_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = usbUART115200bps_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(usbUART115200bps_SCB_MODE_I2C_CONST_CFG)
        status = usbUART115200bps_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)
        status = usbUART115200bps_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(usbUART115200bps_SCB_MODE_UART_CONST_CFG)
        status = usbUART115200bps_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG)
        status = usbUART115200bps_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: usbUART115200bps_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls write fucntion of the bootloader communication component for selected
*  mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus usbUART115200bps_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG)
        if(usbUART115200bps_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = usbUART115200bps_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(usbUART115200bps_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = usbUART115200bps_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(usbUART115200bps_SCB_MODE_UART_RUNTM_CFG)
        {
            status = usbUART115200bps_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(usbUART115200bps_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = usbUART115200bps_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }
    #elif(usbUART115200bps_SCB_MODE_I2C_CONST_CFG)
        status = usbUART115200bps_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(usbUART115200bps_SCB_MODE_SPI_CONST_CFG)
        status = usbUART115200bps_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(usbUART115200bps_SCB_MODE_UART_CONST_CFG)
        status = usbUART115200bps_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(usbUART115200bps_SCB_MODE_EZI2C_CONST_CFG)
        status = usbUART115200bps_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (usbUART115200bps_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_usbUART115200bps) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */


/* [] END OF FILE */
