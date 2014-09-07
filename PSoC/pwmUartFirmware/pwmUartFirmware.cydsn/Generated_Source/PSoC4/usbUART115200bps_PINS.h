/*******************************************************************************
* File Name: usbUART115200bps_PINS.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PINS_usbUART115200bps_H)
#define CY_SCB_PINS_usbUART115200bps_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define usbUART115200bps_REMOVE_MOSI_SCL_RX_WAKE_PIN    (1u)
#define usbUART115200bps_REMOVE_MOSI_SCL_RX_PIN         (1u)
#define usbUART115200bps_REMOVE_MISO_SDA_TX_PIN         (1u)
#define usbUART115200bps_REMOVE_SCLK_PIN                (1u)
#define usbUART115200bps_REMOVE_SS0_PIN                 (1u)
#define usbUART115200bps_REMOVE_SS1_PIN                 (1u)
#define usbUART115200bps_REMOVE_SS2_PIN                 (1u)
#define usbUART115200bps_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define usbUART115200bps_REMOVE_I2C_PINS                (1u)
#define usbUART115200bps_REMOVE_SPI_MASTER_PINS         (1u)
#define usbUART115200bps_REMOVE_SPI_SLAVE_PINS          (1u)
#define usbUART115200bps_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define usbUART115200bps_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define usbUART115200bps_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define usbUART115200bps_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define usbUART115200bps_REMOVE_UART_TX_PIN             (0u)
#define usbUART115200bps_REMOVE_UART_RX_TX_PIN          (1u)
#define usbUART115200bps_REMOVE_UART_RX_PIN             (0u)
#define usbUART115200bps_REMOVE_UART_RX_WAKE_PIN        (1u)

/* Unconfigured pins */
#define usbUART115200bps_MOSI_SCL_RX_WAKE_PIN   (0u == usbUART115200bps_REMOVE_MOSI_SCL_RX_WAKE_PIN)
#define usbUART115200bps_MOSI_SCL_RX_PIN        (0u == usbUART115200bps_REMOVE_MOSI_SCL_RX_PIN)
#define usbUART115200bps_MISO_SDA_TX_PIN        (0u == usbUART115200bps_REMOVE_MISO_SDA_TX_PIN)
#define usbUART115200bps_SCLK_PIN               (0u == usbUART115200bps_REMOVE_SCLK_PIN)
#define usbUART115200bps_SS0_PIN                (0u == usbUART115200bps_REMOVE_SS0_PIN)
#define usbUART115200bps_SS1_PIN                (0u == usbUART115200bps_REMOVE_SS1_PIN)
#define usbUART115200bps_SS2_PIN                (0u == usbUART115200bps_REMOVE_SS2_PIN)
#define usbUART115200bps_SS3_PIN                (0u == usbUART115200bps_REMOVE_SS3_PIN)

/* Mode defined pins */
#define usbUART115200bps_I2C_PINS               (0u == usbUART115200bps_REMOVE_I2C_PINS)
#define usbUART115200bps_SPI_MASTER_PINS        (0u == usbUART115200bps_REMOVE_SPI_MASTER_PINS) 
#define usbUART115200bps_SPI_SLAVE_PINS         (0u == usbUART115200bps_REMOVE_SPI_SLAVE_PINS)
#define usbUART115200bps_SPI_MASTER_SS0_PIN     (0u == usbUART115200bps_REMOVE_SPI_MASTER_SS0_PIN)
#define usbUART115200bps_SPI_MASTER_SS1_PIN     (0u == usbUART115200bps_REMOVE_SPI_MASTER_SS1_PIN)
#define usbUART115200bps_SPI_MASTER_SS2_PIN     (0u == usbUART115200bps_REMOVE_SPI_MASTER_SS2_PIN)
#define usbUART115200bps_SPI_MASTER_SS3_PIN     (0u == usbUART115200bps_REMOVE_SPI_MASTER_SS3_PIN)
#define usbUART115200bps_UART_TX_PIN            (0u == usbUART115200bps_REMOVE_UART_TX_PIN)
#define usbUART115200bps_UART_RX_TX_PIN         (0u == usbUART115200bps_REMOVE_UART_RX_TX_PIN)
#define usbUART115200bps_UART_RX_PIN            (0u == usbUART115200bps_REMOVE_UART_RX_PIN)
#define usbUART115200bps_UART_RX_WAKE_PIN       (0u == usbUART115200bps_REMOVE_UART_RX_WAKE_PIN)


/***************************************
*             Includes
****************************************/

#if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
    #include "usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake.h"
#endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */

#if(usbUART115200bps_MOSI_SCL_RX_PIN)
    #include "usbUART115200bps_spi_mosi_i2c_scl_uart_rx.h"
#endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

#if(usbUART115200bps_MISO_SDA_TX_PIN)
    #include "usbUART115200bps_spi_miso_i2c_sda_uart_tx.h"
#endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */

#if(usbUART115200bps_SCLK_PIN)
    #include "usbUART115200bps_spi_sclk.h"
#endif /* (usbUART115200bps_SCLK_PIN) */

#if(usbUART115200bps_SS0_PIN)
    #include "usbUART115200bps_spi_ss0.h"
#endif /* (usbUART115200bps_SS1_PIN) */

#if(usbUART115200bps_SS1_PIN)
    #include "usbUART115200bps_spi_ss1.h"
#endif /* (usbUART115200bps_SS1_PIN) */

#if(usbUART115200bps_SS2_PIN)
    #include "usbUART115200bps_spi_ss2.h"
#endif /* (usbUART115200bps_SS2_PIN) */

#if(usbUART115200bps_SS3_PIN)
    #include "usbUART115200bps_spi_ss3.h"
#endif /* (usbUART115200bps_SS3_PIN) */

#if(usbUART115200bps_I2C_PINS)
    #include "usbUART115200bps_scl.h"
    #include "usbUART115200bps_sda.h"
#endif /* (usbUART115200bps_I2C_PINS) */
    
#if(usbUART115200bps_SPI_MASTER_PINS)
    #include "usbUART115200bps_sclk_m.h"
    #include "usbUART115200bps_mosi_m.h"
    #include "usbUART115200bps_miso_m.h"
#endif /* (usbUART115200bps_SPI_MASTER_PINS) */

#if(usbUART115200bps_SPI_SLAVE_PINS)
    #include "usbUART115200bps_sclk_s.h"
    #include "usbUART115200bps_mosi_s.h"
    #include "usbUART115200bps_miso_s.h"
    #include "usbUART115200bps_ss_s.h"
#endif /* (usbUART115200bps_SPI_SLAVE_PINS) */

#if(usbUART115200bps_SPI_MASTER_SS0_PIN)
    #include "usbUART115200bps_ss0_m.h"
#endif /* (usbUART115200bps_SPI_MASTER_SS0_PIN) */

#if(usbUART115200bps_SPI_MASTER_SS1_PIN)
    #include "usbUART115200bps_ss1_m.h"
#endif /* (usbUART115200bps_SPI_MASTER_SS1_PIN) */

#if(usbUART115200bps_SPI_MASTER_SS2_PIN)
    #include "usbUART115200bps_ss2_m.h"
#endif /* (usbUART115200bps_SPI_MASTER_SS2_PIN) */

#if(usbUART115200bps_SPI_MASTER_SS3_PIN)
    #include "usbUART115200bps_ss3_m.h"
#endif /* (usbUART115200bps_SPI_MASTER_SS3_PIN) */

#if(usbUART115200bps_UART_TX_PIN)
    #include "usbUART115200bps_tx.h"
#endif /* (usbUART115200bps_UART_TX_PIN) */

#if(usbUART115200bps_UART_RX_TX_PIN)
    #include "usbUART115200bps_rx_tx.h"
#endif /* (usbUART115200bps_UART_RX_TX_PIN) */

#if(usbUART115200bps_UART_RX_PIN)
    #include "usbUART115200bps_rx.h"
#endif /* (usbUART115200bps_UART_RX_PIN) */

#if(usbUART115200bps_UART_RX_WAKE_PIN)
    #include "usbUART115200bps_rx_wake.h"
#endif /* (usbUART115200bps_UART_RX_WAKE_PIN) */


/***************************************
*              Registers
***************************************/

#if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
    #define usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_REG  \
                                                (*(reg32 *) usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_PTR  \
                                                ( (reg32 *) usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM)
    #define usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_MASK \
                                                (usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_MASK)
    #define usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_POS  \
                                                (usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake__0__HSIOM_SHIFT)

    #define usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_REG    (*(reg32 *) \
                                                              usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)
    #define usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_PTR    ( (reg32 *) \
                                                              usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake__0__INTCFG)

    #define usbUART115200bps_INTCFG_TYPE_MASK                  (0x03u)
    #define usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS  (usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake__SHIFT)
    #define usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK ((uint32)                                           \
                                                                    ((uint32) usbUART115200bps_INTCFG_TYPE_MASK << \
                                                                    usbUART115200bps_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS))
#endif /* (usbUART115200bps_MOSI_SCL_RX_WAKE_PIN) */

#if(usbUART115200bps_MOSI_SCL_RX_PIN)
    #define usbUART115200bps_MOSI_SCL_RX_HSIOM_REG      (*(reg32 *) usbUART115200bps_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define usbUART115200bps_MOSI_SCL_RX_HSIOM_PTR      ( (reg32 *) usbUART115200bps_spi_mosi_i2c_scl_uart_rx__0__HSIOM)
    #define usbUART115200bps_MOSI_SCL_RX_HSIOM_MASK     (usbUART115200bps_spi_mosi_i2c_scl_uart_rx__0__HSIOM_MASK)
    #define usbUART115200bps_MOSI_SCL_RX_HSIOM_POS      (usbUART115200bps_spi_mosi_i2c_scl_uart_rx__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

#if(usbUART115200bps_MISO_SDA_TX_PIN)
    #define usbUART115200bps_MISO_SDA_TX_HSIOM_REG      (*(reg32 *) usbUART115200bps_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define usbUART115200bps_MISO_SDA_TX_HSIOM_PTR      ( (reg32 *) usbUART115200bps_spi_miso_i2c_sda_uart_tx__0__HSIOM)
    #define usbUART115200bps_MISO_SDA_TX_HSIOM_MASK     (usbUART115200bps_spi_miso_i2c_sda_uart_tx__0__HSIOM_MASK)
    #define usbUART115200bps_MISO_SDA_TX_HSIOM_POS      (usbUART115200bps_spi_miso_i2c_sda_uart_tx__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_MISO_SDA_TX_PIN_PIN) */

#if(usbUART115200bps_SCLK_PIN)
    #define usbUART115200bps_SCLK_HSIOM_REG     (*(reg32 *) usbUART115200bps_spi_sclk__0__HSIOM)
    #define usbUART115200bps_SCLK_HSIOM_PTR     ( (reg32 *) usbUART115200bps_spi_sclk__0__HSIOM)
    #define usbUART115200bps_SCLK_HSIOM_MASK    (usbUART115200bps_spi_sclk__0__HSIOM_MASK)
    #define usbUART115200bps_SCLK_HSIOM_POS     (usbUART115200bps_spi_sclk__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_SCLK_PIN) */

#if(usbUART115200bps_SS0_PIN)
    #define usbUART115200bps_SS0_HSIOM_REG      (*(reg32 *) usbUART115200bps_spi_ss0__0__HSIOM)
    #define usbUART115200bps_SS0_HSIOM_PTR      ( (reg32 *) usbUART115200bps_spi_ss0__0__HSIOM)
    #define usbUART115200bps_SS0_HSIOM_MASK     (usbUART115200bps_spi_ss0__0__HSIOM_MASK)
    #define usbUART115200bps_SS0_HSIOM_POS      (usbUART115200bps_spi_ss0__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_SS1_PIN) */

#if(usbUART115200bps_SS1_PIN)
    #define usbUART115200bps_SS1_HSIOM_REG      (*(reg32 *) usbUART115200bps_spi_ss1__0__HSIOM)
    #define usbUART115200bps_SS1_HSIOM_PTR      ( (reg32 *) usbUART115200bps_spi_ss1__0__HSIOM)
    #define usbUART115200bps_SS1_HSIOM_MASK     (usbUART115200bps_spi_ss1__0__HSIOM_MASK)
    #define usbUART115200bps_SS1_HSIOM_POS      (usbUART115200bps_spi_ss1__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_SS1_PIN) */

#if(usbUART115200bps_SS2_PIN)
    #define usbUART115200bps_SS2_HSIOM_REG     (*(reg32 *) usbUART115200bps_spi_ss2__0__HSIOM)
    #define usbUART115200bps_SS2_HSIOM_PTR     ( (reg32 *) usbUART115200bps_spi_ss2__0__HSIOM)
    #define usbUART115200bps_SS2_HSIOM_MASK    (usbUART115200bps_spi_ss2__0__HSIOM_MASK)
    #define usbUART115200bps_SS2_HSIOM_POS     (usbUART115200bps_spi_ss2__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_SS2_PIN) */

#if(usbUART115200bps_SS3_PIN)
    #define usbUART115200bps_SS3_HSIOM_REG     (*(reg32 *) usbUART115200bps_spi_ss3__0__HSIOM)
    #define usbUART115200bps_SS3_HSIOM_PTR     ( (reg32 *) usbUART115200bps_spi_ss3__0__HSIOM)
    #define usbUART115200bps_SS3_HSIOM_MASK    (usbUART115200bps_spi_ss3__0__HSIOM_MASK)
    #define usbUART115200bps_SS3_HSIOM_POS     (usbUART115200bps_spi_ss3__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_SS3_PIN) */

#if(usbUART115200bps_I2C_PINS)
    #define usbUART115200bps_SCL_HSIOM_REG     (*(reg32 *) usbUART115200bps_scl__0__HSIOM)
    #define usbUART115200bps_SCL_HSIOM_PTR     ( (reg32 *) usbUART115200bps_scl__0__HSIOM)
    #define usbUART115200bps_SCL_HSIOM_MASK    (usbUART115200bps_scl__0__HSIOM_MASK)
    #define usbUART115200bps_SCL_HSIOM_POS     (usbUART115200bps_scl__0__HSIOM_SHIFT)

    #define usbUART115200bps_SDA_HSIOM_REG     (*(reg32 *) usbUART115200bps_sda__0__HSIOM)
    #define usbUART115200bps_SDA_HSIOM_PTR     ( (reg32 *) usbUART115200bps_sda__0__HSIOM)
    #define usbUART115200bps_SDA_HSIOM_MASK    (usbUART115200bps_sda__0__HSIOM_MASK)
    #define usbUART115200bps_SDA_HSIOM_POS     (usbUART115200bps_sda__0__HSIOM_SHIFT)
#endif /* (usbUART115200bps_I2C_PINS) */


/***************************************
*        Registers Constants
***************************************/

/* Pins constanst */
#define usbUART115200bps_HSIOM_DEF_SEL      (0x00u)
#define usbUART115200bps_HSIOM_GPIO_SEL     (0x00u)
#define usbUART115200bps_HSIOM_UART_SEL     (0x09u)
#define usbUART115200bps_HSIOM_I2C_SEL      (0x0Eu)
#define usbUART115200bps_HSIOM_SPI_SEL      (0x0Fu)

#define usbUART115200bps_SCB_PINS_NUMBER            (7u)
#define usbUART115200bps_MOSI_SCL_RX_PIN_INDEX      (0u) /* RX pins without interrupt */
#define usbUART115200bps_MOSI_SCL_RX_WAKE_PIN_INDEX (0u) /* RX pin with interrupt     */
#define usbUART115200bps_MISO_SDA_TX_PIN_INDEX      (1u)
#define usbUART115200bps_SCLK_PIN_INDEX             (2u)
#define usbUART115200bps_SS0_PIN_INDEX              (3u)
#define usbUART115200bps_SS1_PIN_INDEX              (4u)
#define usbUART115200bps_SS2_PIN_INDEX              (5u)
#define usbUART115200bps_SS3_PIN_INDEX              (6u)

#define usbUART115200bps_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin DM defines */
#define usbUART115200bps_PIN_DM_ALG_HIZ  (0u)
#define usbUART115200bps_PIN_DM_DIG_HIZ  (1u)
#define usbUART115200bps_PIN_DM_OD_LO    (4u)
#define usbUART115200bps_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

#define usbUART115200bps_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        /* Sets new bits-mask */                 \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

#define usbUART115200bps_SET_HSIOM_SEL(reg, mask, pos, sel) usbUART115200bps_SET_REGISTER_BITS(reg, mask, pos, sel)
#define usbUART115200bps_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        usbUART115200bps_SET_REGISTER_BITS(reg, mask, pos, intType)


/* usbUART115200bps_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  usbUART115200bps_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* Unconfigured SCB: scl singnal */
#if(usbUART115200bps_MOSI_SCL_RX_WAKE_PIN)
    #define usbUART115200bps_SET_I2C_SCL_DR(val) \
                            usbUART115200bps_spi_mosi_i2c_scl_uart_rx_wake_Write(val)

    #define usbUART115200bps_SET_I2C_SCL_HSIOM_SEL(sel) \
                    usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_REG,  \
                                                   usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_MASK, \
                                                   usbUART115200bps_MOSI_SCL_RX_WAKE_HSIOM_POS,  \
                                                   (sel))

#elif(usbUART115200bps_MOSI_SCL_RX_PIN)
    #define usbUART115200bps_SET_I2C_SCL_DR(val) \
                            usbUART115200bps_spi_mosi_i2c_scl_uart_rx_Write(val)


    #define usbUART115200bps_SET_I2C_SCL_HSIOM_SEL(sel) \
                            usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_MOSI_SCL_RX_HSIOM_REG,  \
                                                           usbUART115200bps_MOSI_SCL_RX_HSIOM_MASK, \
                                                           usbUART115200bps_MOSI_SCL_RX_HSIOM_POS,  \
                                                           (sel))
#else
    #if(!usbUART115200bps_I2C_PINS)
        #define usbUART115200bps_SET_I2C_SCL_DR(val) \
                                                 do{ ; }while(0)
        #define usbUART115200bps_SET_I2C_SCL_HSIOM_SEL(sel) \
                                                        do{ ; }while(0)

    #endif /* (!usbUART115200bps_I2C_PINS) */
#endif /* (usbUART115200bps_MOSI_SCL_RX_PIN) */

/* SCB I2C: scl singal */
#if(usbUART115200bps_I2C_PINS)
    #define usbUART115200bps_SET_I2C_SCL_DR(val) usbUART115200bps_scl_Write(val)

    #define usbUART115200bps_SET_I2C_SCL_HSIOM_SEL(sel) \
                          usbUART115200bps_SET_HSIOM_SEL(usbUART115200bps_SCL_HSIOM_REG,  \
                                                         usbUART115200bps_SCL_HSIOM_MASK, \
                                                         usbUART115200bps_SCL_HSIOM_POS,  \
                                                         (sel))

#endif /* (usbUART115200bps_I2C_PINS) */


#endif /* (CY_SCB_PINS_usbUART115200bps_H) */


/* [] END OF FILE */
