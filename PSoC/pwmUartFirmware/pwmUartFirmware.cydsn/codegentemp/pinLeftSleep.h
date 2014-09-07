/*******************************************************************************
* File Name: pinLeftSleep.h  
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

#if !defined(CY_PINS_pinLeftSleep_H) /* Pins pinLeftSleep_H */
#define CY_PINS_pinLeftSleep_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pinLeftSleep_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pinLeftSleep_Write(uint8 value) ;
void    pinLeftSleep_SetDriveMode(uint8 mode) ;
uint8   pinLeftSleep_ReadDataReg(void) ;
uint8   pinLeftSleep_Read(void) ;
uint8   pinLeftSleep_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinLeftSleep_DRIVE_MODE_BITS        (3)
#define pinLeftSleep_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pinLeftSleep_DRIVE_MODE_BITS))
#define pinLeftSleep_DRIVE_MODE_SHIFT       (0x00u)
#define pinLeftSleep_DRIVE_MODE_MASK        (0x07u << pinLeftSleep_DRIVE_MODE_SHIFT)

#define pinLeftSleep_DM_ALG_HIZ         (0x00u << pinLeftSleep_DRIVE_MODE_SHIFT)
#define pinLeftSleep_DM_DIG_HIZ         (0x01u << pinLeftSleep_DRIVE_MODE_SHIFT)
#define pinLeftSleep_DM_RES_UP          (0x02u << pinLeftSleep_DRIVE_MODE_SHIFT)
#define pinLeftSleep_DM_RES_DWN         (0x03u << pinLeftSleep_DRIVE_MODE_SHIFT)
#define pinLeftSleep_DM_OD_LO           (0x04u << pinLeftSleep_DRIVE_MODE_SHIFT)
#define pinLeftSleep_DM_OD_HI           (0x05u << pinLeftSleep_DRIVE_MODE_SHIFT)
#define pinLeftSleep_DM_STRONG          (0x06u << pinLeftSleep_DRIVE_MODE_SHIFT)
#define pinLeftSleep_DM_RES_UPDWN       (0x07u << pinLeftSleep_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define pinLeftSleep_MASK               pinLeftSleep__MASK
#define pinLeftSleep_SHIFT              pinLeftSleep__SHIFT
#define pinLeftSleep_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinLeftSleep_PS                     (* (reg32 *) pinLeftSleep__PS)
/* Port Configuration */
#define pinLeftSleep_PC                     (* (reg32 *) pinLeftSleep__PC)
/* Data Register */
#define pinLeftSleep_DR                     (* (reg32 *) pinLeftSleep__DR)
/* Input Buffer Disable Override */
#define pinLeftSleep_INP_DIS                (* (reg32 *) pinLeftSleep__PC2)


#if defined(pinLeftSleep__INTSTAT)  /* Interrupt Registers */

    #define pinLeftSleep_INTSTAT                (* (reg32 *) pinLeftSleep__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins pinLeftSleep_H */


/* [] END OF FILE */
