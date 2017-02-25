/*******************************************************************************
* File Name: orange.h  
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

#if !defined(CY_PINS_orange_H) /* Pins orange_H */
#define CY_PINS_orange_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "orange_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 orange__PORT == 15 && ((orange__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    orange_Write(uint8 value);
void    orange_SetDriveMode(uint8 mode);
uint8   orange_ReadDataReg(void);
uint8   orange_Read(void);
void    orange_SetInterruptMode(uint16 position, uint16 mode);
uint8   orange_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the orange_SetDriveMode() function.
     *  @{
     */
        #define orange_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define orange_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define orange_DM_RES_UP          PIN_DM_RES_UP
        #define orange_DM_RES_DWN         PIN_DM_RES_DWN
        #define orange_DM_OD_LO           PIN_DM_OD_LO
        #define orange_DM_OD_HI           PIN_DM_OD_HI
        #define orange_DM_STRONG          PIN_DM_STRONG
        #define orange_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define orange_MASK               orange__MASK
#define orange_SHIFT              orange__SHIFT
#define orange_WIDTH              1u

/* Interrupt constants */
#if defined(orange__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in orange_SetInterruptMode() function.
     *  @{
     */
        #define orange_INTR_NONE      (uint16)(0x0000u)
        #define orange_INTR_RISING    (uint16)(0x0001u)
        #define orange_INTR_FALLING   (uint16)(0x0002u)
        #define orange_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define orange_INTR_MASK      (0x01u) 
#endif /* (orange__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define orange_PS                     (* (reg8 *) orange__PS)
/* Data Register */
#define orange_DR                     (* (reg8 *) orange__DR)
/* Port Number */
#define orange_PRT_NUM                (* (reg8 *) orange__PRT) 
/* Connect to Analog Globals */                                                  
#define orange_AG                     (* (reg8 *) orange__AG)                       
/* Analog MUX bux enable */
#define orange_AMUX                   (* (reg8 *) orange__AMUX) 
/* Bidirectional Enable */                                                        
#define orange_BIE                    (* (reg8 *) orange__BIE)
/* Bit-mask for Aliased Register Access */
#define orange_BIT_MASK               (* (reg8 *) orange__BIT_MASK)
/* Bypass Enable */
#define orange_BYP                    (* (reg8 *) orange__BYP)
/* Port wide control signals */                                                   
#define orange_CTL                    (* (reg8 *) orange__CTL)
/* Drive Modes */
#define orange_DM0                    (* (reg8 *) orange__DM0) 
#define orange_DM1                    (* (reg8 *) orange__DM1)
#define orange_DM2                    (* (reg8 *) orange__DM2) 
/* Input Buffer Disable Override */
#define orange_INP_DIS                (* (reg8 *) orange__INP_DIS)
/* LCD Common or Segment Drive */
#define orange_LCD_COM_SEG            (* (reg8 *) orange__LCD_COM_SEG)
/* Enable Segment LCD */
#define orange_LCD_EN                 (* (reg8 *) orange__LCD_EN)
/* Slew Rate Control */
#define orange_SLW                    (* (reg8 *) orange__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define orange_PRTDSI__CAPS_SEL       (* (reg8 *) orange__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define orange_PRTDSI__DBL_SYNC_IN    (* (reg8 *) orange__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define orange_PRTDSI__OE_SEL0        (* (reg8 *) orange__PRTDSI__OE_SEL0) 
#define orange_PRTDSI__OE_SEL1        (* (reg8 *) orange__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define orange_PRTDSI__OUT_SEL0       (* (reg8 *) orange__PRTDSI__OUT_SEL0) 
#define orange_PRTDSI__OUT_SEL1       (* (reg8 *) orange__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define orange_PRTDSI__SYNC_OUT       (* (reg8 *) orange__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(orange__SIO_CFG)
    #define orange_SIO_HYST_EN        (* (reg8 *) orange__SIO_HYST_EN)
    #define orange_SIO_REG_HIFREQ     (* (reg8 *) orange__SIO_REG_HIFREQ)
    #define orange_SIO_CFG            (* (reg8 *) orange__SIO_CFG)
    #define orange_SIO_DIFF           (* (reg8 *) orange__SIO_DIFF)
#endif /* (orange__SIO_CFG) */

/* Interrupt Registers */
#if defined(orange__INTSTAT)
    #define orange_INTSTAT            (* (reg8 *) orange__INTSTAT)
    #define orange_SNAP               (* (reg8 *) orange__SNAP)
    
	#define orange_0_INTTYPE_REG 		(* (reg8 *) orange__0__INTTYPE)
#endif /* (orange__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_orange_H */


/* [] END OF FILE */
