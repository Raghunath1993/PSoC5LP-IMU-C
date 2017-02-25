/*******************************************************************************
* File Name: pink.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pink_H) /* Pins pink_H */
#define CY_PINS_pink_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pink_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pink__PORT == 15 && ((pink__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pink_Write(uint8 value);
void    pink_SetDriveMode(uint8 mode);
uint8   pink_ReadDataReg(void);
uint8   pink_Read(void);
void    pink_SetInterruptMode(uint16 position, uint16 mode);
uint8   pink_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pink_SetDriveMode() function.
     *  @{
     */
        #define pink_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pink_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pink_DM_RES_UP          PIN_DM_RES_UP
        #define pink_DM_RES_DWN         PIN_DM_RES_DWN
        #define pink_DM_OD_LO           PIN_DM_OD_LO
        #define pink_DM_OD_HI           PIN_DM_OD_HI
        #define pink_DM_STRONG          PIN_DM_STRONG
        #define pink_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pink_MASK               pink__MASK
#define pink_SHIFT              pink__SHIFT
#define pink_WIDTH              1u

/* Interrupt constants */
#if defined(pink__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pink_SetInterruptMode() function.
     *  @{
     */
        #define pink_INTR_NONE      (uint16)(0x0000u)
        #define pink_INTR_RISING    (uint16)(0x0001u)
        #define pink_INTR_FALLING   (uint16)(0x0002u)
        #define pink_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pink_INTR_MASK      (0x01u) 
#endif /* (pink__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pink_PS                     (* (reg8 *) pink__PS)
/* Data Register */
#define pink_DR                     (* (reg8 *) pink__DR)
/* Port Number */
#define pink_PRT_NUM                (* (reg8 *) pink__PRT) 
/* Connect to Analog Globals */                                                  
#define pink_AG                     (* (reg8 *) pink__AG)                       
/* Analog MUX bux enable */
#define pink_AMUX                   (* (reg8 *) pink__AMUX) 
/* Bidirectional Enable */                                                        
#define pink_BIE                    (* (reg8 *) pink__BIE)
/* Bit-mask for Aliased Register Access */
#define pink_BIT_MASK               (* (reg8 *) pink__BIT_MASK)
/* Bypass Enable */
#define pink_BYP                    (* (reg8 *) pink__BYP)
/* Port wide control signals */                                                   
#define pink_CTL                    (* (reg8 *) pink__CTL)
/* Drive Modes */
#define pink_DM0                    (* (reg8 *) pink__DM0) 
#define pink_DM1                    (* (reg8 *) pink__DM1)
#define pink_DM2                    (* (reg8 *) pink__DM2) 
/* Input Buffer Disable Override */
#define pink_INP_DIS                (* (reg8 *) pink__INP_DIS)
/* LCD Common or Segment Drive */
#define pink_LCD_COM_SEG            (* (reg8 *) pink__LCD_COM_SEG)
/* Enable Segment LCD */
#define pink_LCD_EN                 (* (reg8 *) pink__LCD_EN)
/* Slew Rate Control */
#define pink_SLW                    (* (reg8 *) pink__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pink_PRTDSI__CAPS_SEL       (* (reg8 *) pink__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pink_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pink__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pink_PRTDSI__OE_SEL0        (* (reg8 *) pink__PRTDSI__OE_SEL0) 
#define pink_PRTDSI__OE_SEL1        (* (reg8 *) pink__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pink_PRTDSI__OUT_SEL0       (* (reg8 *) pink__PRTDSI__OUT_SEL0) 
#define pink_PRTDSI__OUT_SEL1       (* (reg8 *) pink__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pink_PRTDSI__SYNC_OUT       (* (reg8 *) pink__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pink__SIO_CFG)
    #define pink_SIO_HYST_EN        (* (reg8 *) pink__SIO_HYST_EN)
    #define pink_SIO_REG_HIFREQ     (* (reg8 *) pink__SIO_REG_HIFREQ)
    #define pink_SIO_CFG            (* (reg8 *) pink__SIO_CFG)
    #define pink_SIO_DIFF           (* (reg8 *) pink__SIO_DIFF)
#endif /* (pink__SIO_CFG) */

/* Interrupt Registers */
#if defined(pink__INTSTAT)
    #define pink_INTSTAT            (* (reg8 *) pink__INTSTAT)
    #define pink_SNAP               (* (reg8 *) pink__SNAP)
    
	#define pink_0_INTTYPE_REG 		(* (reg8 *) pink__0__INTTYPE)
#endif /* (pink__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pink_H */


/* [] END OF FILE */
