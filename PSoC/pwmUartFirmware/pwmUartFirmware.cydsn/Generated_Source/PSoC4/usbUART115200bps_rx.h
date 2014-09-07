/*******************************************************************************
* File Name: usbUART115200bps_rx.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_usbUART115200bps_rx_H) /* Pins usbUART115200bps_rx_H */
#define CY_PINS_usbUART115200bps_rx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "usbUART115200bps_rx_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    usbUART115200bps_rx_Write(uint8 value) ;
void    usbUART115200bps_rx_SetDriveMode(uint8 mode) ;
uint8   usbUART115200bps_rx_ReadDataReg(void) ;
uint8   usbUART115200bps_rx_Read(void) ;
uint8   usbUART115200bps_rx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define usbUART115200bps_rx_DRIVE_MODE_BITS        (3)
#define usbUART115200bps_rx_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - usbUART115200bps_rx_DRIVE_MODE_BITS))
#define usbUART115200bps_rx_DRIVE_MODE_SHIFT       (0x00u)
#define usbUART115200bps_rx_DRIVE_MODE_MASK        (0x07u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)

#define usbUART115200bps_rx_DM_ALG_HIZ         (0x00u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)
#define usbUART115200bps_rx_DM_DIG_HIZ         (0x01u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)
#define usbUART115200bps_rx_DM_RES_UP          (0x02u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)
#define usbUART115200bps_rx_DM_RES_DWN         (0x03u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)
#define usbUART115200bps_rx_DM_OD_LO           (0x04u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)
#define usbUART115200bps_rx_DM_OD_HI           (0x05u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)
#define usbUART115200bps_rx_DM_STRONG          (0x06u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)
#define usbUART115200bps_rx_DM_RES_UPDWN       (0x07u << usbUART115200bps_rx_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define usbUART115200bps_rx_MASK               usbUART115200bps_rx__MASK
#define usbUART115200bps_rx_SHIFT              usbUART115200bps_rx__SHIFT
#define usbUART115200bps_rx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define usbUART115200bps_rx_PS                     (* (reg32 *) usbUART115200bps_rx__PS)
/* Port Configuration */
#define usbUART115200bps_rx_PC                     (* (reg32 *) usbUART115200bps_rx__PC)
/* Data Register */
#define usbUART115200bps_rx_DR                     (* (reg32 *) usbUART115200bps_rx__DR)
/* Input Buffer Disable Override */
#define usbUART115200bps_rx_INP_DIS                (* (reg32 *) usbUART115200bps_rx__PC2)


#if defined(usbUART115200bps_rx__INTSTAT)  /* Interrupt Registers */

    #define usbUART115200bps_rx_INTSTAT                (* (reg32 *) usbUART115200bps_rx__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins usbUART115200bps_rx_H */


/* [] END OF FILE */
