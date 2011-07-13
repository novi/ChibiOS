/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @defgroup STM32F10X_CL_HAL STM32F105/F107 HAL Support
 * @details HAL support for STM32 Connectivity Line sub-family.
 *
 * @ingroup HAL
 */

/**
 * @file    STM32/hal_lld_f105_f107.h
 * @brief   STM32F10x Connectivity Line HAL subsystem low level driver header.
 *
 * @addtogroup STM32F10X_CL_HAL
 * @{
 */

#ifndef _HAL_LLD_F105_F107_H_
#define _HAL_LLD_F105_F107_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define STM32_HSICLK            8000000     /**< High speed internal clock. */
#define STM32_LSICLK            40000       /**< Low speed internal clock.  */

/* RCC_CFGR register bits definitions.*/
#define STM32_SW_HSI            (0 << 0)    /**< SYSCLK source is HSI.      */
#define STM32_SW_HSE            (1 << 0)    /**< SYSCLK source is HSE.      */
#define STM32_SW_PLL            (2 << 0)    /**< SYSCLK source is PLL.      */

#define STM32_HPRE_DIV1         (0 << 4)    /**< SYSCLK divided by 1.       */
#define STM32_HPRE_DIV2         (8 << 4)    /**< SYSCLK divided by 2.       */
#define STM32_HPRE_DIV4         (9 << 4)    /**< SYSCLK divided by 4.       */
#define STM32_HPRE_DIV8         (10 << 4)   /**< SYSCLK divided by 8.       */
#define STM32_HPRE_DIV16        (11 << 4)   /**< SYSCLK divided by 16.      */
#define STM32_HPRE_DIV64        (12 << 4)   /**< SYSCLK divided by 64.      */
#define STM32_HPRE_DIV128       (13 << 4)   /**< SYSCLK divided by 128.     */
#define STM32_HPRE_DIV256       (14 << 4)   /**< SYSCLK divided by 256.     */
#define STM32_HPRE_DIV512       (15 << 4)   /**< SYSCLK divided by 512.     */

#define STM32_PPRE1_DIV1        (0 << 8)    /**< HCLK divided by 1.         */
#define STM32_PPRE1_DIV2        (4 << 8)    /**< HCLK divided by 2.         */
#define STM32_PPRE1_DIV4        (5 << 8)    /**< HCLK divided by 4.         */
#define STM32_PPRE1_DIV8        (6 << 8)    /**< HCLK divided by 8.         */
#define STM32_PPRE1_DIV16       (7 << 8)    /**< HCLK divided by 16.        */

#define STM32_PPRE2_DIV1        (0 << 11)   /**< HCLK divided by 1.         */
#define STM32_PPRE2_DIV2        (4 << 11)   /**< HCLK divided by 2.         */
#define STM32_PPRE2_DIV4        (5 << 11)   /**< HCLK divided by 4.         */
#define STM32_PPRE2_DIV8        (6 << 11)   /**< HCLK divided by 8.         */
#define STM32_PPRE2_DIV16       (7 << 11)   /**< HCLK divided by 16.        */

#define STM32_ADCPRE_DIV2       (0 << 14)   /**< HCLK divided by 2.         */
#define STM32_ADCPRE_DIV4       (1 << 14)   /**< HCLK divided by 4.         */
#define STM32_ADCPRE_DIV6       (2 << 14)   /**< HCLK divided by 6.         */
#define STM32_ADCPRE_DIV8       (3 << 14)   /**< HCLK divided by 8.         */

#define STM32_PLLSRC_HSI        (0 << 16)   /**< PLL clock source is HSI.   */
#define STM32_PLLSRC_PREDIV1    (1 << 16)   /**< PLL clock source is
                                                 PREDIV1.                   */

#define STM32_OTGFSPRE_DIV2     (1 << 22)   /**< HCLK*2 divided by 2.       */
#define STM32_OTGFSPRE_DIV3     (0 << 22)   /**< HCLK*2 divided by 3.       */

#define STM32_MCO_NOCLOCK       (0 << 24)   /**< No clock on MCO pin.       */
#define STM32_MCO_SYSCLK        (4 << 24)   /**< SYSCLK on MCO pin.         */
#define STM32_MCO_HSI           (5 << 24)   /**< HSI clock on MCO pin.      */
#define STM32_MCO_HSE           (6 << 24)   /**< HSE clock on MCO pin.      */
#define STM32_MCO_PLLDIV2       (7 << 24)   /**< PLL/2 clock on MCO pin.    */
#define STM32_MCO_PLL2          (8 << 24)   /**< PLL2 clock on MCO pin.     */
#define STM32_MCO_PLL3DIV2      (9 << 24)   /**< PLL3/2 clock on MCO pin.   */
#define STM32_MCO_XT1           (10 << 24)  /**< XT1 clock on MCO pin.      */
#define STM32_MCO_PLL3          (11 << 24)  /**< PLL3 clock on MCO pin.     */

/* RCC_CFGR2 register bits definitions.*/
#define STM32_PREDIV1SRC_HSE    (0 << 16)   /**< PREDIV1 source is HSE.     */
#define STM32_PREDIV1SRC_PLL2   (1 << 16)   /**< PREDIV1 source is PLL2.    */

/*===========================================================================*/
/* Platform specific friendly IRQ names.                                     */
/*===========================================================================*/

#define WWDG_IRQHandler         Vector40    /**< Window Watchdog.           */
#define PVD_IRQHandler          Vector44    /**< PVD through EXTI Line
                                                 detect.                    */
#define TAMPER_IRQHandler       Vector48    /**< Tamper.                    */
#define RTC_IRQHandler          Vector4C    /**< RTC.                       */
#define FLASH_IRQHandler        Vector50    /**< Flash.                     */
#define RCC_IRQHandler          Vector54    /**< RCC.                       */
#define EXTI0_IRQHandler        Vector58    /**< EXTI Line 0.               */
#define EXTI1_IRQHandler        Vector5C    /**< EXTI Line 1.               */
#define EXTI2_IRQHandler        Vector60    /**< EXTI Line 2.               */
#define EXTI3_IRQHandler        Vector64    /**< EXTI Line 3.               */
#define EXTI4_IRQHandler        Vector68    /**< EXTI Line 4.               */
#define DMA1_Ch1_IRQHandler     Vector6C    /**< DMA1 Channel 1.            */
#define DMA1_Ch2_IRQHandler     Vector70    /**< DMA1 Channel 2.            */
#define DMA1_Ch3_IRQHandler     Vector74    /**< DMA1 Channel 3.            */
#define DMA1_Ch4_IRQHandler     Vector78    /**< DMA1 Channel 4.            */
#define DMA1_Ch5_IRQHandler     Vector7C    /**< DMA1 Channel 5.            */
#define DMA1_Ch6_IRQHandler     Vector80    /**< DMA1 Channel 6.            */
#define DMA1_Ch7_IRQHandler     Vector84    /**< DMA1 Channel 7.            */
#define ADC1_2_IRQHandler       Vector88    /**< ADC1 and ADC2.             */
#define CAN1_TX_IRQHandler      Vector8C    /**< CAN1 TX.                   */
#define CAN1_RX0_IRQHandler     Vector90    /**< CAN1 RX0.                  */
#define CAN1_RX1_IRQHandler     Vector94    /**< CAN1 RX1.                  */
#define CAN1_SCE_IRQHandler     Vector98    /**< CAN1 SCE.                  */
#define EXTI9_5_IRQHandler      Vector9C    /**< EXTI Line 9..5.            */
#define TIM1_BRK_IRQHandler     VectorA0    /**< TIM1 Break.                */
#define TIM1_UP_IRQHandler      VectorA4    /**< TIM1 Update.               */
#define TIM1_TRG_COM_IRQHandler VectorA8    /**< TIM1 Trigger and
                                                 Commutation.               */
#define TIM1_CC_IRQHandler      VectorAC    /**< TIM1 Capture Compare.      */
#define TIM2_IRQHandler         VectorB0    /**< TIM2.                      */
#define TIM3_IRQHandler         VectorB4    /**< TIM3.                      */
#define TIM4_IRQHandler         VectorB8    /**< TIM4.                      */
#define I2C1_EV_IRQHandler      VectorBC    /**< I2C1 Event.                */
#define I2C1_ER_IRQHandler      VectorC0    /**< I2C1 Error.                */
#define I2C2_EV_IRQHandler      VectorC4    /**< I2C2 Event.                */
#define I2C2_ER_IRQHandler      VectorC8    /**< I2C1 Error.                */
#define SPI1_IRQHandler         VectorCC    /**< SPI1.                      */
#define SPI2_IRQHandler         VectorD0    /**< SPI2.                      */
#define USART1_IRQHandler       VectorD4    /**< USART1.                    */
#define USART2_IRQHandler       VectorD8    /**< USART2.                    */
#define USART3_IRQHandler       VectorDC    /**< USART3.                    */
#define EXTI15_10_IRQHandler    VectorE0    /**< EXTI Line 15..10.          */
#define RTCAlarm_IRQHandler     VectorE4    /**< RTC alarm through EXTI
                                                 line.                      */
#define OTG_FS_WKUP_IRQHandler  VectorE8    /**< USB OTG FS Wakeup through
                                                 EXTI line.                 */
#define TIM5_IRQHandler         Vector108   /**< TIM5.                      */
#define SPI3_IRQHandler         Vector10C   /**< SPI3.                      */
#define UART4_IRQHandler        Vector110   /**< UART4.                     */
#define UART5_IRQHandler        Vector114   /**< UART5.                     */
#define TIM6_IRQHandler         Vector118   /**< TIM6.                      */
#define TIM7_IRQHandler         Vector11C   /**< TIM7.                      */
#define DMA2_Ch1_IRQHandler     Vector120   /**< DMA2 Channel1.             */
#define DMA2_Ch2_IRQHandler     Vector124   /**< DMA2 Channel2.             */
#define DMA2_Ch3_IRQHandler     Vector128   /**< DMA2 Channel3.             */
#define DMA2_Ch4_IRQHandler     Vector12C   /**< DMA2 Channel4.             */
#define DMA2_Ch5_IRQHandler     Vector130   /**< DMA2 Channel5.             */
#define ETH_IRQHandler          Vector134   /**< Ethernet.                  */
#define ETH_WKUP_IRQHandler     Vector138   /**< Ethernet Wakeup through
                                                 EXTI line.                 */
#define CAN2_TX_IRQHandler      Vector13C   /**< CAN2 TX.                   */
#define CAN2_RX0_IRQHandler     Vector140   /**< CAN2 RX0.                  */
#define CAN2_RX1_IRQHandler     Vector144   /**< CAN2 RX1.                  */
#define CAN2_SCE_IRQHandler     Vector148   /**< CAN2 SCE.                  */
#define OTG_FS_IRQHandler       Vector14C   /**< USB OTG FS.                */
                                   
/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   PLL1 main switch.
 * @note    If this constant is set to @p TRUE then the PLL1 is initialized
 *          and started.
 */
#if !defined(STM32_ACTIVATE_PLL1) || defined(__DOXYGEN__)
#define STM32_ACTIVATE_PLL1         TRUE
#endif

/**
 * @brief   PLL2 main switch.
 * @note    If this constant is set to @p TRUE then the PLL2 is initialized
 *          and started.
 */
#if !defined(STM32_ACTIVATE_PLL2) || defined(__DOXYGEN__)
#define STM32_ACTIVATE_PLL2         TRUE
#endif

/**
 * @brief   PLL3 main switch.
 * @note    If this constant is set to @p TRUE then the PLL3 is initialized
 *          and started.
 */
#if !defined(STM32_ACTIVATE_PLL3) || defined(__DOXYGEN__)
#define STM32_ACTIVATE_PLL3         TRUE
#endif

/**
 * @brief   Main clock source selection.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_SW) || defined(__DOXYGEN__)
#define STM32_SW                    STM32_SW_PLL
#endif

/**
 * @brief   Clock source for the PLL.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_PLLSRC) || defined(__DOXYGEN__)
#define STM32_PLLSRC                STM32_PLLSRC_PREDIV1
#endif

/**
 * @brief   PREDIV1 clock source.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_PREDIV1SRC) || defined(__DOXYGEN__)
#define STM32_PREDIV1SRC            STM32_PREDIV1SRC_PLL2
#endif

/**
 * @brief   PREDIV1 division factor.
 * @note    The allowed range is 1...16.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_PREDIV1_VALUE) || defined(__DOXYGEN__)
#define STM32_PREDIV1_VALUE         5
#endif

/**
 * @brief   PLL multiplier value.
 * @note    The allowed range is 4...9.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_PLLMUL_VALUE) || defined(__DOXYGEN__)
#define STM32_PLLMUL_VALUE          9
#endif

/**
 * @brief   PREDIV2 division factor.
 * @note    The allowed range is 1...16.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_PREDIV2_VALUE) || defined(__DOXYGEN__)
#define STM32_PREDIV2_VALUE         5
#endif

/**
 * @brief   PLL2 multiplier value.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_PLL2MUL_VALUE) || defined(__DOXYGEN__)
#define STM32_PLL2MUL_VALUE         8
#endif

/**
 * @brief   PLL3 multiplier value.
 * @note    The default value is calculated for a 50MHz clock from
 *          a 25MHz crystal.
 */
#if !defined(STM32_PLL3MUL_VALUE) || defined(__DOXYGEN__)
#define STM32_PLL3MUL_VALUE         10
#endif

/**
 * @brief   AHB prescaler value.
 * @note    The default value is calculated for a 72MHz system clock from
 *          a 25MHz crystal using both PLL and PLL2.
 */
#if !defined(STM32_HPRE) || defined(__DOXYGEN__)
#define STM32_HPRE                  STM32_HPRE_DIV1
#endif

/**
 * @brief   APB1 prescaler value.
 */
#if !defined(STM32_PPRE1) || defined(__DOXYGEN__)
#define STM32_PPRE1                 STM32_PPRE1_DIV2
#endif

/**
 * @brief   APB2 prescaler value.
 */
#if !defined(STM32_PPRE2) || defined(__DOXYGEN__)
#define STM32_PPRE2                 STM32_PPRE2_DIV2
#endif

/**
 * @brief   ADC prescaler value.
 */
#if !defined(STM32_ADCPRE) || defined(__DOXYGEN__)
#define STM32_ADCPRE                STM32_ADCPRE_DIV4
#endif

/**
 * @brief   OTG prescaler initialization.
 */
#if !defined(STM32_OTGFSPRE) || defined(__DOXYGEN__)
#define STM32_OTGFSPRE              STM32_OTGFSPRE_DIV3
#endif

/**
 * @brief   MCO pin setting.
 */
#if !defined(STM32_MCO) || defined(__DOXYGEN__)
#define STM32_MCO                   STM32_MCO_NOCLOCK
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* PLL2 usage check.*/
#if STM32_ACTIVATE_PLL2 &&                                                  \
    (STM32_PREDIV1SRC != STM32_PREDIV1SRC_PLL2) &&                          \
    (STM32_MCO != STM32_MCO_PLL2)
#error "PLL2 activated but not used"
#endif

/**
 * @brief   PREDIV1 field.
 */
#if (STM32_PREDIV1_VALUE >= 1) && (STM32_PREDIV1_VALUE <= 16) ||            \
    defined(__DOXYGEN__)
#define STM32_PREDIV1               ((STM32_PREDIV1_VALUE - 1) << 0)
#else
#error "invalid STM32_PREDIV1_VALUE value specified"
#endif

/**
 * @brief   PREDIV2 field.
 */
#if (STM32_PREDIV2_VALUE >= 1) && (STM32_PREDIV2_VALUE <= 16) ||            \
    defined(__DOXYGEN__)
#define STM32_PREDIV2               ((STM32_PREDIV2_VALUE - 1) << 4)
#else
#error "invalid STM32_PREDIV2_VALUE value specified"
#endif

/**
 * @brief   PLLMUL field.
 */
#if ((STM32_PLLMUL_VALUE >= 4) && (STM32_PLLMUL_VALUE <= 9)) ||             \
    defined(__DOXYGEN__)
#define STM32_PLLMUL                ((STM32_PLLMUL_VALUE - 2) << 18)
#else
#error "invalid STM32_PLLMUL_VALUE value specified"
#endif

/**
 * @brief   PLL2MUL field.
 */
#if ((STM32_PLL2MUL_VALUE >= 8) && (STM32_PLL2MUL_VALUE <= 14)) ||          \
    defined(__DOXYGEN__)
#define STM32_PLL2MUL               ((STM32_PLL2MUL_VALUE - 2) << 8)
#elif (STM32_PLL2MUL_VALUE == 16)
#define STM32_PLL2MUL               (14 << 8)
#elif (STM32_PLL2MUL_VALUE == 20)
#define STM32_PLL2MUL               (15 << 8)
#else
#error "invalid STM32_PLL2MUL_VALUE value specified"
#endif

/**
 * @brief   PLL3MUL field.
 */
#if ((STM32_PLL3MUL_VALUE >= 8) && (STM32_PLL3MUL_VALUE <= 14)) ||          \
    defined(__DOXYGEN__)
#define STM32_PLL3MUL               ((STM32_PLL3MUL_VALUE - 2) << 12)
#elif (STM32_PLL3MUL_VALUE == 16)
#define STM32_PLL3MUL               (14 << 12)
#elif (STM32_PLL3MUL_VALUE == 20)
#define STM32_PLL3MUL               (15 << 12)
#else
#error "invalid STM32_PLL3MUL_VALUE value specified"
#endif

/* The following values are only used if PLL2 is activated */
#if STM32_ACTIVATE_PLL2
/**
 * @brief   PLL2 input frequency.
 */
#define STM32_PLL2CLKIN             (STM32_HSECLK / STM32_PREDIV2_VALUE)

/* PLL2 input frequency range check.*/
#if (STM32_PLL2CLKIN < 3000000) || (STM32_PLL2CLKIN > 5000000)
#error "STM32_PLL2CLKIN outside acceptable range (3...5MHz)"
#endif

/**
 * @brief   PLL2 output clock frequency.
 */
#define STM32_PLL2CLKOUT            (STM32_PLL2CLKIN * STM32_PLL2MUL_VALUE)

/**
 * @brief   PLL2 VCO clock frequency.
 */
#define STM32_PLL2VCO               (STM32_PLL2CLKOUT * 2)

/* PLL2 output frequency range check.*/
#if (STM32_PLL2VCO < 80000000) || (STM32_PLL2VCO > 148000000)
#error "STM32_PLL2VCO outside acceptable range (80...148MHz)"
#endif
#endif /* STM32_ACTIVATE_PLL2 */

/* The following values are only used if PLL3 is activated */
#if STM32_ACTIVATE_PLL3
/**
 * @brief   PLL3 input frequency.
 */
#define STM32_PLL3CLKIN             (STM32_HSECLK / STM32_PREDIV2_VALUE)

/* PLL3 input frequency range check.*/
#if (STM32_PLL3CLKIN < 3000000) || (STM32_PLL3CLKIN > 5000000)
#error "STM32_PLL3CLKIN outside acceptable range (3...5MHz)"
#endif

/**
 * @brief   PLL3 output clock frequency.
 */
#define STM32_PLL3CLKOUT            (STM32_PLL3CLKIN * STM32_PLL3MUL_VALUE)

/**
 * @brief   PLL3 VCO clock frequency.
 */
#define STM32_PLL3VCO               (STM32_PLL3CLKOUT * 2)

/* PLL3 output frequency range check.*/
#if (STM32_PLL3VCO < 80000000) || (STM32_PLL3VCO > 148000000)
#error "STM32_PLL3CLKOUT outside acceptable range (80...148MHz)"
#endif
#endif /* STM32_ACTIVATE_PLL3 */

/* The following values are only used if PLL1 is activated */
#if STM32_ACTIVATE_PLL1
/**
 * @brief   PREDIV1 input frequency.
 */
#if (STM32_PREDIV1SRC == STM32_PREDIV1SRC_PLL2) || defined(__DOXYGEN__)
#if !STM32_ACTIVATE_PLL2
#error "PLL2 selected as clock source for STM32_PREDIV1SRC but not activated"
#endif
#define STM32_PREDIV1CLK            STM32_PLL2CLKOUT
#elif STM32_PREDIV1SRC == STM32_PREDIV1SRC_HSE
#define STM32_PREDIV1CLK            STM32_HSECLK
#else
#error "invalid STM32_PREDIV1SRC value specified"
#endif

/**
 * @brief   PLL input clock frequency.
 */
#if (STM32_PLLSRC == STM32_PLLSRC_PREDIV1) || defined(__DOXYGEN__)
#define STM32_PLLCLKIN              (STM32_PREDIV1CLK / STM32_PREDIV1_VALUE)
#elif STM32_PLLSRC == STM32_PLLSRC_HSI
#define STM32_PLLCLKIN              (STM32_HSICLK / 2)
#else
#error "invalid STM32_PLLSRC value specified"
#endif

/* PLL input frequency range check.*/
#if (STM32_PLLCLKIN < 3000000) || (STM32_PLLCLKIN > 12000000)
#error "STM32_PLLCLKIN outside acceptable range (3...12MHz)"
#endif

/**
 * @brief   PLL output clock frequency.
 */
#define STM32_PLLCLKOUT             (STM32_PLLCLKIN * STM32_PLLMUL_VALUE)

/**
 * @brief   PLL VCO clock frequency.
 */
#define STM32_PLLVCO                (STM32_PLLCLKOUT * 2)

/* PLL output frequency range check.*/
#if (STM32_PLLVCO < 36000000) || (STM32_PLLVCO > 144000000)
#error "STM32_PLLVCO outside acceptable range (36...144MHz)"
#endif
#endif /* STM32_ACTIVATE_PLL1 */

/**
 * @brief   System clock source.
 */
#if (STM32_SW == STM32_SW_PLL) || defined(__DOXYGEN__)
#if !STM32_ACTIVATE_PLL1
#error "PLL1 selected as clock source for STM32_SYSCLK but not activated"
#endif
#define STM32_SYSCLK                STM32_PLLCLKOUT
#elif (STM32_SW == STM32_SW_HSI)
#define STM32_SYSCLK                STM32_HSICLK
#elif (STM32_SW == STM32_SW_HSE)
#define STM32_SYSCLK                STM32_HSECLK
#else
#error "invalid STM32_SYSCLK_SW value specified"
#endif

/* Check on the system clock.*/
#if STM32_SYSCLK > 72000000
#error "STM32_SYSCLK above maximum rated frequency (72MHz)"
#endif

/**
 * @brief   AHB frequency.
 */
#if (STM32_HPRE == STM32_HPRE_DIV1) || defined(__DOXYGEN__)
#define STM32_HCLK                  (STM32_SYSCLK / 1)
#elif STM32_HPRE == STM32_HPRE_DIV2
#define STM32_HCLK                  (STM32_SYSCLK / 2)
#elif STM32_HPRE == STM32_HPRE_DIV4
#define STM32_HCLK                  (STM32_SYSCLK / 4)
#elif STM32_HPRE == STM32_HPRE_DIV8
#define STM32_HCLK                  (STM32_SYSCLK / 8)
#elif STM32_HPRE == STM32_HPRE_DIV16
#define STM32_HCLK                  (STM32_SYSCLK / 16)
#elif STM32_HPRE == STM32_HPRE_DIV64
#define STM32_HCLK                  (STM32_SYSCLK / 64)
#elif STM32_HPRE == STM32_HPRE_DIV128
#define STM32_HCLK                  (STM32_SYSCLK / 128)
#elif STM32_HPRE == STM32_HPRE_DIV256
#define STM32_HCLK                  (STM32_SYSCLK / 256)
#elif STM32_HPRE == STM32_HPRE_DIV512
#define STM32_HCLK                  (STM32_SYSCLK / 512)
#else
#error "invalid STM32_HPRE value specified"
#endif

/* AHB frequency check.*/
#if STM32_HCLK > 72000000
#error "STM32_HCLK exceeding maximum frequency (72MHz)"
#endif

/**
 * @brief   APB1 frequency.
 */
#if (STM32_PPRE1 == STM32_PPRE1_DIV1) || defined(__DOXYGEN__)
#define STM32_PCLK1                 (STM32_HCLK / 1)
#elif STM32_PPRE1 == STM32_PPRE1_DIV2
#define STM32_PCLK1                 (STM32_HCLK / 2)
#elif STM32_PPRE1 == STM32_PPRE1_DIV4
#define STM32_PCLK1                 (STM32_HCLK / 4)
#elif STM32_PPRE1 == STM32_PPRE1_DIV8
#define STM32_PCLK1                 (STM32_HCLK / 8)
#elif STM32_PPRE1 == STM32_PPRE1_DIV16
#define STM32_PCLK1                 (STM32_HCLK / 16)
#else
#error "invalid STM32_PPRE1 value specified"
#endif

/* APB1 frequency check.*/
#if STM32_PCLK1 > 36000000
#error "STM32_PCLK1 exceeding maximum frequency (36MHz)"
#endif

/**
 * @brief   APB2 frequency.
 */
#if (STM32_PPRE2 == STM32_PPRE2_DIV1) || defined(__DOXYGEN__)
#define STM32_PCLK2                 (STM32_HCLK / 1)
#elif STM32_PPRE2 == STM32_PPRE2_DIV2
#define STM32_PCLK2                 (STM32_HCLK / 2)
#elif STM32_PPRE2 == STM32_PPRE2_DIV4
#define STM32_PCLK2                 (STM32_HCLK / 4)
#elif STM32_PPRE2 == STM32_PPRE2_DIV8
#define STM32_PCLK2                 (STM32_HCLK / 8)
#elif STM32_PPRE2 == STM32_PPRE2_DIV16
#define STM32_PCLK2                 (STM32_HCLK / 16)
#else
#error "invalid STM32_PPRE2 value specified"
#endif

/* APB2 frequency check.*/
#if STM32_PCLK2 > 72000000
#error "STM32_PCLK2 exceeding maximum frequency (72MHz)"
#endif

/**
 * @brief   ADC frequency.
 */
#if (STM32_ADCPRE == STM32_ADCPRE_DIV2) || defined(__DOXYGEN__)
#define STM32_ADCCLK                (STM32_PCLK2 / 2)
#elif STM32_ADCPRE == STM32_ADCPRE_DIV4
#define STM32_ADCCLK                (STM32_PCLK2 / 4)
#elif STM32_ADCPRE == STM32_ADCPRE_DIV6
#define STM32_ADCCLK                (STM32_PCLK2 / 6)
#elif STM32_ADCPRE == STM32_ADCPRE_DIV8
#define STM32_ADCCLK                (STM32_PCLK2 / 8)
#else
#error "invalid STM32_ADCPRE value specified"
#endif

/* ADC frequency check.*/
#if STM32_ADCCLK > 14000000
#error "STM32_ADCCLK exceeding maximum frequency (14MHz)"
#endif

/**
 * @brief   OTG frequency.
 */
#if (STM32_OTGFSPRE == STM32_OTGFSPRE_DIV3) || defined(__DOXYGEN__)
#define STM32_OTGFSCLK              (STM32_PLLVCO / 3)
#elif (STM32_OTGFSPRE == STM32_OTGFSPRE_DIV2)
#define STM32_OTGFSCLK              (STM32_PLLVCO / 2)
#else
#error "invalid STM32_OTGFSPRE value specified"
#endif

/**
 * @brief   Timers 2, 3, 4, 5, 6, 7 clock.
 */
#if (STM32_PPRE1 == STM32_PPRE1_DIV1) || defined(__DOXYGEN__)
#define STM32_TIMCLK1               (STM32_PCLK1 * 1)
#else
#define STM32_TIMCLK1               (STM32_PCLK1 * 2)
#endif

/**
 * @brief   Timers 1, 8 clock.
 */
#if (STM32_PPRE2 == STM32_PPRE2_DIV1) || defined(__DOXYGEN__)
#define STM32_TIMCLK2               (STM32_PCLK2 * 1)
#else
#define STM32_TIMCLK2               (STM32_PCLK2 * 2)
#endif

/**
 * @brief   Flash settings.
 */
#if (STM32_HCLK <= 24000000) || defined(__DOXYGEN__)
#define STM32_FLASHBITS             0x00000010
#elif STM32_HCLK <= 48000000
#define STM32_FLASHBITS             0x00000011
#else
#define STM32_FLASHBITS             0x00000012
#endif

#endif /* _HAL_LLD_F105_F107_H_ */

/** @} */
