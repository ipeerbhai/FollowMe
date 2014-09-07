/*******************************************************************************
* File Name: pinLeftStep.h  
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

#if !defined(CY_PINS_pinLeftStep_H) /* Pins pinLeftStep_H */
#define CY_PINS_pinLeftStep_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pinLeftStep_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pinLeftStep_Write(uint8 value) ;
void    pinLeftStep_SetDriveMode(uint8 mode) ;
uint8   pinLeftStep_ReadDataReg(void) ;
uint8   pinLeftStep_Read(void) ;
uint8   pinLeftStep_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinLeftStep_DRIVE_MODE_BITS        (3)
#define pinLeftStep_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pinLeftStep_DRIVE_MODE_BITS))
#define pinLeftStep_DRIVE_MODE_SHIFT       (0x00u)
#define pinLeftStep_DRIVE_MODE_MASK        (0x07u << pinLeftStep_DRIVE_MODE_SHIFT)

#define pinLeftStep_DM_ALG_HIZ         (0x00u << pinLeftStep_DRIVE_MODE_SHIFT)
#define pinLeftStep_DM_DIG_HIZ         (0x01u << pinLeftStep_DRIVE_MODE_SHIFT)
#define pinLeftStep_DM_RES_UP          (0x02u << pinLeftStep_DRIVE_MODE_SHIFT)
#define pinLeftStep_DM_RES_DWN         (0x03u << pinLeftStep_DRIVE_MODE_SHIFT)
#define pinLeftStep_DM_OD_LO           (0x04u << pinLeftStep_DRIVE_MODE_SHIFT)
#define pinLeftStep_DM_OD_HI           (0x05u << pinLeftStep_DRIVE_MODE_SHIFT)
#define pinLeftStep_DM_STRONG          (0x06u << pinLeftStep_DRIVE_MODE_SHIFT)
#define pinLeftStep_DM_RES_UPDWN       (0x07u << pinLeftStep_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define pinLeftStep_MASK               pinLeftStep__MASK
#define pinLeftStep_SHIFT              pinLeftStep__SHIFT
#define pinLeftStep_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinLeftStep_PS                     (* (reg32 *) pinLeftStep__PS)
/* Port Configuration */
#define pinLeftStep_PC                     (* (reg32 *) pinLeftStep__PC)
/* Data Register */
#define pinLeftStep_DR                     (* (reg32 *) pinLeftStep__DR)
/* Input Buffer Disable Override */
#define pinLeftStep_INP_DIS                (* (reg32 *) pinLeftStep__PC2)


#if defined(pinLeftStep__INTSTAT)  /* Interrupt Registers */

    #define pinLeftStep_INTSTAT                (* (reg32 *) pinLeftStep__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins pinLeftStep_H */


/* [] END OF FILE */
