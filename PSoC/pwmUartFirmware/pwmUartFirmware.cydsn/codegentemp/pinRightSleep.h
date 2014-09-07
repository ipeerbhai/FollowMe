/*******************************************************************************
* File Name: pinRightSleep.h  
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

#if !defined(CY_PINS_pinRightSleep_H) /* Pins pinRightSleep_H */
#define CY_PINS_pinRightSleep_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pinRightSleep_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pinRightSleep_Write(uint8 value) ;
void    pinRightSleep_SetDriveMode(uint8 mode) ;
uint8   pinRightSleep_ReadDataReg(void) ;
uint8   pinRightSleep_Read(void) ;
uint8   pinRightSleep_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pinRightSleep_DRIVE_MODE_BITS        (3)
#define pinRightSleep_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pinRightSleep_DRIVE_MODE_BITS))
#define pinRightSleep_DRIVE_MODE_SHIFT       (0x00u)
#define pinRightSleep_DRIVE_MODE_MASK        (0x07u << pinRightSleep_DRIVE_MODE_SHIFT)

#define pinRightSleep_DM_ALG_HIZ         (0x00u << pinRightSleep_DRIVE_MODE_SHIFT)
#define pinRightSleep_DM_DIG_HIZ         (0x01u << pinRightSleep_DRIVE_MODE_SHIFT)
#define pinRightSleep_DM_RES_UP          (0x02u << pinRightSleep_DRIVE_MODE_SHIFT)
#define pinRightSleep_DM_RES_DWN         (0x03u << pinRightSleep_DRIVE_MODE_SHIFT)
#define pinRightSleep_DM_OD_LO           (0x04u << pinRightSleep_DRIVE_MODE_SHIFT)
#define pinRightSleep_DM_OD_HI           (0x05u << pinRightSleep_DRIVE_MODE_SHIFT)
#define pinRightSleep_DM_STRONG          (0x06u << pinRightSleep_DRIVE_MODE_SHIFT)
#define pinRightSleep_DM_RES_UPDWN       (0x07u << pinRightSleep_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define pinRightSleep_MASK               pinRightSleep__MASK
#define pinRightSleep_SHIFT              pinRightSleep__SHIFT
#define pinRightSleep_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pinRightSleep_PS                     (* (reg32 *) pinRightSleep__PS)
/* Port Configuration */
#define pinRightSleep_PC                     (* (reg32 *) pinRightSleep__PC)
/* Data Register */
#define pinRightSleep_DR                     (* (reg32 *) pinRightSleep__DR)
/* Input Buffer Disable Override */
#define pinRightSleep_INP_DIS                (* (reg32 *) pinRightSleep__PC2)


#if defined(pinRightSleep__INTSTAT)  /* Interrupt Registers */

    #define pinRightSleep_INTSTAT                (* (reg32 *) pinRightSleep__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins pinRightSleep_H */


/* [] END OF FILE */
