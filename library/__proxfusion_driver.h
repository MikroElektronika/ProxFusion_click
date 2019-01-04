/*
    __proxfusion_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __proxfusion_driver.h
@brief    ProxFusion Driver
@mainpage ProxFusion Click
@{

@image html sch.jpg

@}

@defgroup   PROXFUSION
@brief      ProxFusion Click Driver
@{

| Global Library Prefix | **PROXFUSION** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2017.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _PROXFUSION_H_
#define _PROXFUSION_H_

/** 
 * @macro T_PROXFUSION_P
 * @brief Driver Abstract type 
 */
#define T_PROXFUSION_P    const uint8_t*

/** @defgroup PROXFUSION_COMPILE Compilation Config */              /** @{ */

//  #define   __PROXFUSION_DRV_SPI__                            /**<     @macro __PROXFUSION_DRV_SPI__  @brief SPI driver selector */
   #define   __PROXFUSION_DRV_I2C__                            /**<     @macro __PROXFUSION_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __PROXFUSION_DRV_UART__                           /**<     @macro __PROXFUSION_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup PROXFUSION_VAR Variables */                           /** @{ */
/* Device information data (R) */
extern const uint8_t _PROXFUSION_REG_PR_NUMBER;
extern const uint8_t _PROXFUSION_REG_SW_NUMBER;
extern const uint8_t _PROXFUSION_REG_HW_NUMBER;

/*Flag register (R)*/
extern const uint8_t _PROXFUSION_FREG_SYSTEM;
extern const uint8_t _PROXFUSION_FREG_GLOBAL_EVENTS;
extern const uint8_t _PROXFUSION_FREG_UI;
extern const uint8_t _PROXFUSION_FREG_SAR_HYSTERESIS_UI;
extern const uint8_t _PROXFUSION_FREG_HALL_EFFECT_UI;
extern const uint8_t _PROXFUSION_FREG_TEMP_UI;

/* Register outputs */
extern const uint16_t _PROXFUSION_REG_OUT_HYSTERESIS ;
extern const uint16_t _PROXFUSION_REG_OUT_HALL_EFFECT;
extern const uint16_t _PROXFUSION_REG_OUT_TEMP;

/* Chanel counts ( raw data ) (R)*/
extern const uint8_t _PROXFUSION_REG_CH_0_LSB;
extern const uint8_t _PROXFUSION_REG_CH_0_MSB;
extern const uint8_t _PROXFUSION_REG_CH_1_LSB;
extern const uint8_t _PROXFUSION_REG_CH_1_MSB;
extern const uint8_t _PROXFUSION_REG_CH_2_LSB;
extern const uint8_t _PROXFUSION_REG_CH_2_MSB;
extern const uint8_t _PROXFUSION_REG_CH_3_LSB;
extern const uint8_t _PROXFUSION_REG_CH_3_MSB;
extern const uint8_t _PROXFUSION_REG_CH_4_LSB;
extern const uint8_t _PROXFUSION_REG_CH_4_MSB;
extern const uint8_t _PROXFUSION_REG_CH_5_LSB;
extern const uint8_t _PROXFUSION_REG_CH_5_MSB;

/* LTA values (Filtered data) (RW) */
extern const uint8_t _PROXFUSION_REG_LTA_CH_0_LSB;
extern const uint8_t _PROXFUSION_REG_LTA_CH_0_MSB;
extern const uint8_t _PROXFUSION_REG_LTA_CH_1_LSB;
extern const uint8_t _PROXFUSION_REG_LTA_CH_1_MSB;
extern const uint8_t _PROXFUSION_REG_LTA_CH_2_LSB;
extern const uint8_t _PROXFUSION_REG_LTA_CH_2_MSB;

/* ProxFusion sensor settings block 0 (RW) */
extern const uint8_t _PROXFUSION_REG_SETTINGS_0_0;
extern const uint8_t _PROXFUSION_REG_SETTINGS_0_1;
extern const uint8_t _PROXFUSION_REG_SETTINGS_0_2;
extern const uint8_t _PROXFUSION_REG_SETTINGS_1_0;
extern const uint8_t _PROXFUSION_REG_SETTINGS_1_1;
extern const uint8_t _PROXFUSION_REG_SETTINGS_1_2;
extern const uint8_t _PROXFUSION_REG_SETTINGS_2_1;
extern const uint8_t _PROXFUSION_REG_SETTINGS_2_2;
extern const uint8_t _PROXFUSION_REG_SETTINGS_3_0;
extern const uint8_t _PROXFUSION_REG_SETTINGS_3_1;
extern const uint8_t _PROXFUSION_REG_SETTINGS_3_2;

/* ProxFusion sensor settings block 1 (RW) */
extern const uint8_t _PROXFUSION_REG_SETTINGS_4;
extern const uint8_t _PROXFUSION_REG_SETTINGS_5;
extern const uint8_t _PROXFUSION_REG_COMPENSATION_CH_0;
extern const uint8_t _PROXFUSION_REG_COMPENSATION_CH_1;
extern const uint8_t _PROXFUSION_REG_COMPENSATION_CH_2;
extern const uint8_t _PROXFUSION_REG_MULTIPLIERS_CH_0;
extern const uint8_t _PROXFUSION_REG_MULTIPLIERS_CH_1;
extern const uint8_t _PROXFUSION_REG_MULTIPLIERS_CH_2;

/* RroxFusion UI settings (RW) */
extern const uint8_t _PROXFUSION_REG_PROX_CH_0;
extern const uint8_t _PROXFUSION_REG_TOUCH_CH_0;
extern const uint8_t _PROXFUSION_REG_PROX_CH_1;
extern const uint8_t _PROXFUSION_REG_TOUCH_CH_1;
extern const uint8_t _PROXFUSION_REG_PROX_CH_2;
extern const uint8_t _PROXFUSION_REG_TOUCH_CH_2;
extern const uint8_t _PROXFUSION_REG_UI_HALY_TIME;

/* SAR UI settings (RW) */
extern const uint8_t _PROXFUSION_REG_SAR_SETTINGS_CH0;
extern const uint8_t _PROXFUSION_REG_SAR_SETTINGS_CH1;
extern const uint8_t _PROXFUSION_REG_QRD_THRESHOLD;
extern const uint8_t _PROXFUSION_REG_FILTER_HALT_THRESHOLD;
extern const uint8_t _PROXFUSION_REG_PROX_THRESHOLD;

/* Hysteresis UI settings (RW) */
extern const uint8_t _PROXFUSION_REG_HYS_UI_SETTINGS;
extern const uint8_t _PROXFUSION_REG_HYS_FILTER_THRESHOLD;
extern const uint8_t _PROXFUSION_REG_HYS_PROX_THRESHOLD;
extern const uint8_t _PROXFUSION_REG_HYS_TOUCH_THRESHOLD;

/* Hall-effect sensor settings (RW) */
extern const uint8_t _PROXFUSION_REG_HALL_SETTINGS_0;
extern const uint8_t _PROXFUSION_REG_HALL_SETTINGS_1;
extern const uint8_t _PROXFUSION_REG_HALL_COMPENSATION_4_5;
extern const uint8_t _PROXFUSION_REG_HALL_MULTIPLIERS_4_5;

/* Hall-effect switch UI settings (RW)*/
extern const uint8_t _PROXFUSION_REG_HALL_SWITCH_UI;
extern const uint8_t _PROXFUSION_REG_HALL_SWITCH_PROX;
extern const uint8_t _PROXFUSION_REG_HALL_SWITCH_TOUCH;

/* Temperature UI settings (RW) */
extern const uint8_t _PROXFUSION_REG_TEMP_UI_SETTINGS;
extern const uint8_t _PROXFUSION_REG_TEMP_MULTIPLIERS_3;
extern const uint8_t _PROXFUSION_REG_TEMP_DATA_0;
extern const uint8_t _PROXFUSION_REG_TEMP_DATA_1;
extern const uint8_t _PROXFUSION_REG_TEMP_OFFSET;

extern const uint8_t _PROXFUSION_REG_I2C_SETTINGS;

/* System settings */
extern const uint8_t _PROXFUSION_SYSTEM_RESET;
extern const uint8_t _PROXFUSION_SYSTEM_ATI_RESET;
extern const uint8_t _PROXFUSION_EVENT_MODE_0;
extern const uint8_t _PROXFUSION_EVENT_MODE_1;
extern const uint8_t _PROXFUSION_CLOCK_16MHz;
extern const uint8_t _PROXFUSION_CLOCK_4MHz;
extern const uint8_t _PROXFUSION_ATI_DESABLED;
extern const uint8_t _PROXFUSION_ATI_ENABLED;
extern const uint8_t _PROXFUSION_ATI_BAND_1_8;
extern const uint8_t _PROXFUSION_ATI_BAND_1_16;

/* Event mask*/
extern const uint8_t _PROXFUSION_MASK_SAR_ACTIVE;
extern const uint8_t _PROXFUSION_MASK_PMU_EVENT;
extern const uint8_t _PROXFUSION_MASK_SYS_EVENT;
extern const uint8_t _PROXFUSION_MASK_TEMP_EVENT;
extern const uint8_t _PROXFUSION_MASK_HYSTERESIS_EVENT;
extern const uint8_t _PROXFUSION_MASK_HALL_EVENT;
extern const uint8_t _PROXFUSION_MASK_SAR_EVENT;
extern const uint8_t _PROXFUSION_MASK_PROX_SENSE_EVENT;
                                                                       /** @} */
/** @defgroup PROXFUSION_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup PROXFUSION_INIT Driver Initialization */              /** @{ */

#ifdef   __PROXFUSION_DRV_SPI__
void proxfusion_spiDriverInit(T_PROXFUSION_P gpioObj, T_PROXFUSION_P spiObj);
#endif
#ifdef   __PROXFUSION_DRV_I2C__
void proxfusion_i2cDriverInit(T_PROXFUSION_P gpioObj, T_PROXFUSION_P i2cObj, uint8_t slave);
#endif
#ifdef   __PROXFUSION_DRV_UART__
void proxfusion_uartDriverInit(T_PROXFUSION_P gpioObj, T_PROXFUSION_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void proxfusion_gpioDriverInit(T_PROXFUSION_P gpioObj);
                                                                       /** @} */
/** @defgroup PROXFUSION_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Returns status register and information
 */
uint8_t proxfusion_readStatus(uint8_t reg);
/**
 * @brief Reads data
 */
uint16_t proxfusion_readData(uint8_t reg);
/**
 * @brief Returns temperature in c
 *
 * @return temperature
 *
 */
uint16_t proxfusion_getTemperature();
/**
 * @brief Returns the information that the button is pressed or an antenna
 *
 * @return 1 - touch button 1 
 * @return 2 - touch button 2 
 * @return 3 - antenna
 *
 */
uint8_t proxfusion_Touch();
/**
 * @brief Writes configuration to system register
 *
 * Configuration data (value) consists of multiple settings:
     Software Reset and ACK Reset set on 1 (default), 
     Event mode enable, Main Clock frequency selection,
     Communications during ATI, Re-ATI Band selection,
     Redo ATI on all channels set on 1 (default)
     and Reseed all Long-term filters set on 1 (default).
 */

void proxfusion_systemSetting(uint8_t value);
/**
 * @brief This function selecting events
 *
 * selection options:
      SAR activation state,
      Power management unit event,
      System event,
      Temperature event,
      Hysteresis UI event,
      Hall-effect event,
      SAR event and
      ProxSense event.
 */
void proxfusion_EventMask(uint8_t value);
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_ProxFusion_STM.c
    @example Click_ProxFusion_TIVA.c
    @example Click_ProxFusion_CEC.c
    @example Click_ProxFusion_KINETIS.c
    @example Click_ProxFusion_MSP.c
    @example Click_ProxFusion_PIC.c
    @example Click_ProxFusion_PIC32.c
    @example Click_ProxFusion_DSPIC.c
    @example Click_ProxFusion_AVR.c
    @example Click_ProxFusion_FT90x.c
    @example Click_ProxFusion_STM.mbas
    @example Click_ProxFusion_TIVA.mbas
    @example Click_ProxFusion_CEC.mbas
    @example Click_ProxFusion_KINETIS.mbas
    @example Click_ProxFusion_MSP.mbas
    @example Click_ProxFusion_PIC.mbas
    @example Click_ProxFusion_PIC32.mbas
    @example Click_ProxFusion_DSPIC.mbas
    @example Click_ProxFusion_AVR.mbas
    @example Click_ProxFusion_FT90x.mbas
    @example Click_ProxFusion_STM.mpas
    @example Click_ProxFusion_TIVA.mpas
    @example Click_ProxFusion_CEC.mpas
    @example Click_ProxFusion_KINETIS.mpas
    @example Click_ProxFusion_MSP.mpas
    @example Click_ProxFusion_PIC.mpas
    @example Click_ProxFusion_PIC32.mpas
    @example Click_ProxFusion_DSPIC.mpas
    @example Click_ProxFusion_AVR.mpas
    @example Click_ProxFusion_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __proxfusion_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */