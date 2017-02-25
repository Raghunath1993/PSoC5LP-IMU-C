/*******************************************************************************
* File Name: DACpin.h  
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

#if !defined(CY_PINS_DACpin_H) /* Pins DACpin_H */
#define CY_PINS_DACpin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DACpin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DACpin__PORT == 15 && ((DACpin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DACpin_Write(uint8 value);
void    DACpin_SetDriveMode(uint8 mode);
uint8   DACpin_ReadDataReg(void);
uint8   DACpin_Read(void);
void    DACpin_SetInterruptMode(uint16 position, uint16 mode);
uint8   DACpin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DACpin_SetDriveMode() function.
     *  @{
     */
        #define DACpin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DACpin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DACpin_DM_RES_UP          PIN_DM_RES_UP
        #define DACpin_DM_RES_DWN         PIN_DM_RES_DWN
        #define DACpin_DM_OD_LO           PIN_DM_OD_LO
        #define DACpin_DM_OD_HI           PIN_DM_OD_HI
        #define DACpin_DM_STRONG          PIN_DM_STRONG
        #define DACpin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DACpin_MASK               DACpin__MASK
#define DACpin_SHIFT              DACpin__SHIFT
#define DACpin_WIDTH              1u

/* Interrupt constants */
#if defined(DACpin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DACpin_SetInterruptMode() function.
     *  @{
     */
        #define DACpin_INTR_NONE      (uint16)(0x0000u)
        #define DACpin_INTR_RISING    (uint16)(0x0001u)
        #define DACpin_INTR_FALLING   (uint16)(0x0002u)
        #define DACpin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DACpin_INTR_MASK      (0x01u) 
#endif /* (DACpin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DACpin_PS                     (* (reg8 *) DACpin__PS)
/* Data Register */
#define DACpin_DR                     (* (reg8 *) DACpin__DR)
/* Port Number */
#define DACpin_PRT_NUM                (* (reg8 *) DACpin__PRT) 
/* Connect to Analog Globals */                                                  
#define DACpin_AG                     (* (reg8 *) DACpin__AG)                       
/* Analog MUX bux enable */
#define DACpin_AMUX                   (* (reg8 *) DACpin__AMUX) 
/* Bidirectional Enable */                                                        
#define DACpin_BIE                    (* (reg8 *) DACpin__BIE)
/* Bit-mask for Aliased Register Access */
#define DACpin_BIT_MASK               (* (reg8 *) DACpin__BIT_MASK)
/* Bypass Enable */
#define DACpin_BYP                    (* (reg8 *) DACpin__BYP)
/* Port wide control signals */                                                   
#define DACpin_CTL                    (* (reg8 *) DACpin__CTL)
/* Drive Modes */
#define DACpin_DM0                    (* (reg8 *) DACpin__DM0) 
#define DACpin_DM1                    (* (reg8 *) DACpin__DM1)
#define DACpin_DM2                    (* (reg8 *) DACpin__DM2) 
/* Input Buffer Disable Override */
#define DACpin_INP_DIS                (* (reg8 *) DACpin__INP_DIS)
/* LCD Common or Segment Drive */
#define DACpin_LCD_COM_SEG            (* (reg8 *) DACpin__LCD_COM_SEG)
/* Enable Segment LCD */
#define DACpin_LCD_EN                 (* (reg8 *) DACpin__LCD_EN)
/* Slew Rate Control */
#define DACpin_SLW                    (* (reg8 *) DACpin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DACpin_PRTDSI__CAPS_SEL       (* (reg8 *) DACpin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DACpin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DACpin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DACpin_PRTDSI__OE_SEL0        (* (reg8 *) DACpin__PRTDSI__OE_SEL0) 
#define DACpin_PRTDSI__OE_SEL1        (* (reg8 *) DACpin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DACpin_PRTDSI__OUT_SEL0       (* (reg8 *) DACpin__PRTDSI__OUT_SEL0) 
#define DACpin_PRTDSI__OUT_SEL1       (* (reg8 *) DACpin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DACpin_PRTDSI__SYNC_OUT       (* (reg8 *) DACpin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DACpin__SIO_CFG)
    #define DACpin_SIO_HYST_EN        (* (reg8 *) DACpin__SIO_HYST_EN)
    #define DACpin_SIO_REG_HIFREQ     (* (reg8 *) DACpin__SIO_REG_HIFREQ)
    #define DACpin_SIO_CFG            (* (reg8 *) DACpin__SIO_CFG)
    #define DACpin_SIO_DIFF           (* (reg8 *) DACpin__SIO_DIFF)
#endif /* (DACpin__SIO_CFG) */

/* Interrupt Registers */
#if defined(DACpin__INTSTAT)
    #define DACpin_INTSTAT            (* (reg8 *) DACpin__INTSTAT)
    #define DACpin_SNAP               (* (reg8 *) DACpin__SNAP)
    
	#define DACpin_0_INTTYPE_REG 		(* (reg8 *) DACpin__0__INTTYPE)
#endif /* (DACpin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DACpin_H */


/* [] END OF FILE */
