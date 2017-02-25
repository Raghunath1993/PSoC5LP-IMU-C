/*******************************************************************************
* File Name: Ain.h  
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

#if !defined(CY_PINS_Ain_H) /* Pins Ain_H */
#define CY_PINS_Ain_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Ain_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Ain__PORT == 15 && ((Ain__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Ain_Write(uint8 value);
void    Ain_SetDriveMode(uint8 mode);
uint8   Ain_ReadDataReg(void);
uint8   Ain_Read(void);
void    Ain_SetInterruptMode(uint16 position, uint16 mode);
uint8   Ain_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Ain_SetDriveMode() function.
     *  @{
     */
        #define Ain_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Ain_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Ain_DM_RES_UP          PIN_DM_RES_UP
        #define Ain_DM_RES_DWN         PIN_DM_RES_DWN
        #define Ain_DM_OD_LO           PIN_DM_OD_LO
        #define Ain_DM_OD_HI           PIN_DM_OD_HI
        #define Ain_DM_STRONG          PIN_DM_STRONG
        #define Ain_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Ain_MASK               Ain__MASK
#define Ain_SHIFT              Ain__SHIFT
#define Ain_WIDTH              1u

/* Interrupt constants */
#if defined(Ain__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Ain_SetInterruptMode() function.
     *  @{
     */
        #define Ain_INTR_NONE      (uint16)(0x0000u)
        #define Ain_INTR_RISING    (uint16)(0x0001u)
        #define Ain_INTR_FALLING   (uint16)(0x0002u)
        #define Ain_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Ain_INTR_MASK      (0x01u) 
#endif /* (Ain__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Ain_PS                     (* (reg8 *) Ain__PS)
/* Data Register */
#define Ain_DR                     (* (reg8 *) Ain__DR)
/* Port Number */
#define Ain_PRT_NUM                (* (reg8 *) Ain__PRT) 
/* Connect to Analog Globals */                                                  
#define Ain_AG                     (* (reg8 *) Ain__AG)                       
/* Analog MUX bux enable */
#define Ain_AMUX                   (* (reg8 *) Ain__AMUX) 
/* Bidirectional Enable */                                                        
#define Ain_BIE                    (* (reg8 *) Ain__BIE)
/* Bit-mask for Aliased Register Access */
#define Ain_BIT_MASK               (* (reg8 *) Ain__BIT_MASK)
/* Bypass Enable */
#define Ain_BYP                    (* (reg8 *) Ain__BYP)
/* Port wide control signals */                                                   
#define Ain_CTL                    (* (reg8 *) Ain__CTL)
/* Drive Modes */
#define Ain_DM0                    (* (reg8 *) Ain__DM0) 
#define Ain_DM1                    (* (reg8 *) Ain__DM1)
#define Ain_DM2                    (* (reg8 *) Ain__DM2) 
/* Input Buffer Disable Override */
#define Ain_INP_DIS                (* (reg8 *) Ain__INP_DIS)
/* LCD Common or Segment Drive */
#define Ain_LCD_COM_SEG            (* (reg8 *) Ain__LCD_COM_SEG)
/* Enable Segment LCD */
#define Ain_LCD_EN                 (* (reg8 *) Ain__LCD_EN)
/* Slew Rate Control */
#define Ain_SLW                    (* (reg8 *) Ain__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Ain_PRTDSI__CAPS_SEL       (* (reg8 *) Ain__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Ain_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Ain__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Ain_PRTDSI__OE_SEL0        (* (reg8 *) Ain__PRTDSI__OE_SEL0) 
#define Ain_PRTDSI__OE_SEL1        (* (reg8 *) Ain__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Ain_PRTDSI__OUT_SEL0       (* (reg8 *) Ain__PRTDSI__OUT_SEL0) 
#define Ain_PRTDSI__OUT_SEL1       (* (reg8 *) Ain__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Ain_PRTDSI__SYNC_OUT       (* (reg8 *) Ain__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Ain__SIO_CFG)
    #define Ain_SIO_HYST_EN        (* (reg8 *) Ain__SIO_HYST_EN)
    #define Ain_SIO_REG_HIFREQ     (* (reg8 *) Ain__SIO_REG_HIFREQ)
    #define Ain_SIO_CFG            (* (reg8 *) Ain__SIO_CFG)
    #define Ain_SIO_DIFF           (* (reg8 *) Ain__SIO_DIFF)
#endif /* (Ain__SIO_CFG) */

/* Interrupt Registers */
#if defined(Ain__INTSTAT)
    #define Ain_INTSTAT            (* (reg8 *) Ain__INTSTAT)
    #define Ain_SNAP               (* (reg8 *) Ain__SNAP)
    
	#define Ain_0_INTTYPE_REG 		(* (reg8 *) Ain__0__INTTYPE)
#endif /* (Ain__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Ain_H */


/* [] END OF FILE */
