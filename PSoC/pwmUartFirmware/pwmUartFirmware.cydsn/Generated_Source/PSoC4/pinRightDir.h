/*******************************************************************************
* File Name: pinRightDir.h  
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

#if !defined(CY_PINS_pinRightDir_H) /* Pins pinRightDir_H */
#define CY_PINS_pinRightDir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pinRightDir_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pinRightDir_Write(uint8 value) ;
void    pinRightDir_SetDriveMode(uint8 mode) ;
uint8   pinRightDir_ReadDataReg(void) ;
uint8   pinRightDir_Read(void) ;
uint8   pinRightDir_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinRightDir_DRIVE_MODE_BITS        (3)
#define pinRightDir_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pinRightDir_DRIVE_MODE_BITS))
#define pinRightDir_DRIVE_MODE_SHIFT       (0x00u)
#define pinRightDir_DRIVE_MODE_MASK        (0x07u << pinRightDir_DRIVE_MODE_SHIFT)

#define pinRightDir_DM_ALG_HIZ         (0x00u << pinRightDir_DRIVE_MODE_SHIFT)
#define pinRightDir_DM_DIG_HIZ         (0x01u << pinRightDir_DRIVE_MODE_SHIFT)
#define pinRightDir_DM_RES_UP          (0x02u << pinRightDir_DRIVE_MODE_SHIFT)
#define pinRightDir_DM_RES_DWN         (0x03u << pinRightDir_DRIVE_MODE_SHIFT)
#define pinRightDir_DM_OD_LO           (0x04u << pinRightDir_DRIVE_MODE_SHIFT)
#define pinRightDir_DM_OD_HI           (0x05u << pinRightDir_DRIVE_MODE_SHIFT)
#define pinRightDir_DM_STRONG          (0x06u << pinRightDir_DRIVE_MODE_SHIFT)
#define pinRightDir_DM_RES_UPDWN       (0x07u << pinRightDir_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define pinRightDir_MASK               pinRightDir__MASK
#define pinRightDir_SHIFT              pinRightDir__SHIFT
#define pinRightDir_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinRightDir_PS                     (* (reg32 *) pinRightDir__PS)
/* Port Configuration */
#define pinRightDir_PC                     (* (reg32 *) pinRightDir__PC)
/* Data Register */
#define pinRightDir_DR                     (* (reg32 *) pinRightDir__DR)
/* Input Buffer Disable Override */
#define pinRightDir_INP_DIS                (* (reg32 *) pinRightDir__PC2)


#if defined(pinRightDir__INTSTAT)  /* Interrupt Registers */

    #define pinRightDir_INTSTAT                (* (reg32 *) pinRightDir__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins pinRightDir_H */


/* [] END OF FILE */
