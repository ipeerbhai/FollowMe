/*******************************************************************************
* File Name: pinRightStep.h  
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

#if !defined(CY_PINS_pinRightStep_H) /* Pins pinRightStep_H */
#define CY_PINS_pinRightStep_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pinRightStep_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pinRightStep_Write(uint8 value) ;
void    pinRightStep_SetDriveMode(uint8 mode) ;
uint8   pinRightStep_ReadDataReg(void) ;
uint8   pinRightStep_Read(void) ;
uint8   pinRightStep_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinRightStep_DRIVE_MODE_BITS        (3)
#define pinRightStep_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pinRightStep_DRIVE_MODE_BITS))
#define pinRightStep_DRIVE_MODE_SHIFT       (0x00u)
#define pinRightStep_DRIVE_MODE_MASK        (0x07u << pinRightStep_DRIVE_MODE_SHIFT)

#define pinRightStep_DM_ALG_HIZ         (0x00u << pinRightStep_DRIVE_MODE_SHIFT)
#define pinRightStep_DM_DIG_HIZ         (0x01u << pinRightStep_DRIVE_MODE_SHIFT)
#define pinRightStep_DM_RES_UP          (0x02u << pinRightStep_DRIVE_MODE_SHIFT)
#define pinRightStep_DM_RES_DWN         (0x03u << pinRightStep_DRIVE_MODE_SHIFT)
#define pinRightStep_DM_OD_LO           (0x04u << pinRightStep_DRIVE_MODE_SHIFT)
#define pinRightStep_DM_OD_HI           (0x05u << pinRightStep_DRIVE_MODE_SHIFT)
#define pinRightStep_DM_STRONG          (0x06u << pinRightStep_DRIVE_MODE_SHIFT)
#define pinRightStep_DM_RES_UPDWN       (0x07u << pinRightStep_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define pinRightStep_MASK               pinRightStep__MASK
#define pinRightStep_SHIFT              pinRightStep__SHIFT
#define pinRightStep_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinRightStep_PS                     (* (reg32 *) pinRightStep__PS)
/* Port Configuration */
#define pinRightStep_PC                     (* (reg32 *) pinRightStep__PC)
/* Data Register */
#define pinRightStep_DR                     (* (reg32 *) pinRightStep__DR)
/* Input Buffer Disable Override */
#define pinRightStep_INP_DIS                (* (reg32 *) pinRightStep__PC2)


#if defined(pinRightStep__INTSTAT)  /* Interrupt Registers */

    #define pinRightStep_INTSTAT                (* (reg32 *) pinRightStep__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins pinRightStep_H */


/* [] END OF FILE */
