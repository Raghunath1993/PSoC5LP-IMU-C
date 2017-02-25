/*******************************************************************************
* File Name: switch3.h  
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

#if !defined(CY_PINS_switch3_H) /* Pins switch3_H */
#define CY_PINS_switch3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "switch3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 switch3__PORT == 15 && ((switch3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    switch3_Write(uint8 value);
void    switch3_SetDriveMode(uint8 mode);
uint8   switch3_ReadDataReg(void);
uint8   switch3_Read(void);
void    switch3_SetInterruptMode(uint16 position, uint16 mode);
uint8   switch3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the switch3_SetDriveMode() function.
     *  @{
     */
        #define switch3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define switch3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define switch3_DM_RES_UP          PIN_DM_RES_UP
        #define switch3_DM_RES_DWN         PIN_DM_RES_DWN
        #define switch3_DM_OD_LO           PIN_DM_OD_LO
        #define switch3_DM_OD_HI           PIN_DM_OD_HI
        #define switch3_DM_STRONG          PIN_DM_STRONG
        #define switch3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define switch3_MASK               switch3__MASK
#define switch3_SHIFT              switch3__SHIFT
#define switch3_WIDTH              1u

/* Interrupt constants */
#if defined(switch3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in switch3_SetInterruptMode() function.
     *  @{
     */
        #define switch3_INTR_NONE      (uint16)(0x0000u)
        #define switch3_INTR_RISING    (uint16)(0x0001u)
        #define switch3_INTR_FALLING   (uint16)(0x0002u)
        #define switch3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define switch3_INTR_MASK      (0x01u) 
#endif /* (switch3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define switch3_PS                     (* (reg8 *) switch3__PS)
/* Data Register */
#define switch3_DR                     (* (reg8 *) switch3__DR)
/* Port Number */
#define switch3_PRT_NUM                (* (reg8 *) switch3__PRT) 
/* Connect to Analog Globals */                                                  
#define switch3_AG                     (* (reg8 *) switch3__AG)                       
/* Analog MUX bux enable */
#define switch3_AMUX                   (* (reg8 *) switch3__AMUX) 
/* Bidirectional Enable */                                                        
#define switch3_BIE                    (* (reg8 *) switch3__BIE)
/* Bit-mask for Aliased Register Access */
#define switch3_BIT_MASK               (* (reg8 *) switch3__BIT_MASK)
/* Bypass Enable */
#define switch3_BYP                    (* (reg8 *) switch3__BYP)
/* Port wide control signals */                                                   
#define switch3_CTL                    (* (reg8 *) switch3__CTL)
/* Drive Modes */
#define switch3_DM0                    (* (reg8 *) switch3__DM0) 
#define switch3_DM1                    (* (reg8 *) switch3__DM1)
#define switch3_DM2                    (* (reg8 *) switch3__DM2) 
/* Input Buffer Disable Override */
#define switch3_INP_DIS                (* (reg8 *) switch3__INP_DIS)
/* LCD Common or Segment Drive */
#define switch3_LCD_COM_SEG            (* (reg8 *) switch3__LCD_COM_SEG)
/* Enable Segment LCD */
#define switch3_LCD_EN                 (* (reg8 *) switch3__LCD_EN)
/* Slew Rate Control */
#define switch3_SLW                    (* (reg8 *) switch3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define switch3_PRTDSI__CAPS_SEL       (* (reg8 *) switch3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define switch3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) switch3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define switch3_PRTDSI__OE_SEL0        (* (reg8 *) switch3__PRTDSI__OE_SEL0) 
#define switch3_PRTDSI__OE_SEL1        (* (reg8 *) switch3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define switch3_PRTDSI__OUT_SEL0       (* (reg8 *) switch3__PRTDSI__OUT_SEL0) 
#define switch3_PRTDSI__OUT_SEL1       (* (reg8 *) switch3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define switch3_PRTDSI__SYNC_OUT       (* (reg8 *) switch3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(switch3__SIO_CFG)
    #define switch3_SIO_HYST_EN        (* (reg8 *) switch3__SIO_HYST_EN)
    #define switch3_SIO_REG_HIFREQ     (* (reg8 *) switch3__SIO_REG_HIFREQ)
    #define switch3_SIO_CFG            (* (reg8 *) switch3__SIO_CFG)
    #define switch3_SIO_DIFF           (* (reg8 *) switch3__SIO_DIFF)
#endif /* (switch3__SIO_CFG) */

/* Interrupt Registers */
#if defined(switch3__INTSTAT)
    #define switch3_INTSTAT            (* (reg8 *) switch3__INTSTAT)
    #define switch3_SNAP               (* (reg8 *) switch3__SNAP)
    
	#define switch3_0_INTTYPE_REG 		(* (reg8 *) switch3__0__INTTYPE)
#endif /* (switch3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_switch3_H */


/* [] END OF FILE */
