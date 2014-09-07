/*******************************************************************************
* File Name: pinLeftDir.h  
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

#if !defined(CY_PINS_pinLeftDir_H) /* Pins pinLeftDir_H */
#define CY_PINS_pinLeftDir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pinLeftDir_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pinLeftDir_Write(uint8 value) ;
void    pinLeftDir_SetDriveMode(uint8 mode) ;
uint8   pinLeftDir_ReadDataReg(void) ;
uint8   pinLeftDir_Read(void) ;
uint8   pinLeftDir_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinLeftDir_DRIVE_MODE_BITS        (3)
#define pinLeftDir_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pinLeftDir_DRIVE_MODE_BITS))
#define pinLeftDir_DRIVE_MODE_SHIFT       (0x00u)
#define pinLeftDir_DRIVE_MODE_MASK        (0x07u << pinLeftDir_DRIVE_MODE_SHIFT)

#define pinLeftDir_DM_ALG_HIZ         (0x00u << pinLeftDir_DRIVE_MODE_SHIFT)
#define pinLeftDir_DM_DIG_HIZ         (0x01u << pinLeftDir_DRIVE_MODE_SHIFT)
#define pinLeftDir_DM_RES_UP          (0x02u << pinLeftDir_DRIVE_MODE_SHIFT)
#define pinLeftDir_DM_RES_DWN         (0x03u << pinLeftDir_DRIVE_MODE_SHIFT)
#define pinLeftDir_DM_OD_LO           (0x04u << pinLeftDir_DRIVE_MODE_SHIFT)
#define pinLeftDir_DM_OD_HI           (0x05u << pinLeftDir_DRIVE_MODE_SHIFT)
#define pinLeftDir_DM_STRONG          (0x06u << pinLeftDir_DRIVE_MODE_SHIFT)
#define pinLeftDir_DM_RES_UPDWN       (0x07u << pinLeftDir_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define pinLeftDir_MASK               pinLeftDir__MASK
#define pinLeftDir_SHIFT              pinLeftDir__SHIFT
#define pinLeftDir_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinLeftDir_PS                     (* (reg32 *) pinLeftDir__PS)
/* Port Configuration */
#define pinLeftDir_PC                     (* (reg32 *) pinLeftDir__PC)
/* Data Register */
#define pinLeftDir_DR                     (* (reg32 *) pinLeftDir__DR)
/* Input Buffer Disable Override */
#define pinLeftDir_INP_DIS                (* (reg32 *) pinLeftDir__PC2)


#if defined(pinLeftDir__INTSTAT)  /* Interrupt Registers */

    #define pinLeftDir_INTSTAT                (* (reg32 *) pinLeftDir__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins pinLeftDir_H */


/* [] END OF FILE */
