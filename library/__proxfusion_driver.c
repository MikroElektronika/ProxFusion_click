/*
    __proxfusion_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__proxfusion_driver.h"
#include "__proxfusion_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __PROXFUSION_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* Device information data (R) */
const uint8_t _PROXFUSION_REG_PR_NUMBER               = 0x00;
const uint8_t _PROXFUSION_REG_SW_NUMBER         = 0x01;
const uint8_t _PROXFUSION_REG_HW_NUMBER         = 0x02;

// Read variants Product number

const uint8_t _PROXFUSION_PR_OK                                = 0x41;
const uint8_t _PROXFUSION_SW_IQS620_OK                = 0x04;
const uint8_t _PROXFUSION_SW_IQS620A_OK                = 0x08;
const uint8_t _PROXFUSION_HW_OK                                = 0x82;

/*Flag register (R)*/
const uint8_t _PROXFUSION_FREG_SYSTEM                                = 0x10;
const uint8_t _PROXFUSION_FREG_GLOBAL_EVENTS                = 0x11;
const uint8_t _PROXFUSION_FREG_UI                                        = 0x12;
const uint8_t _PROXFUSION_FREG_SAR_HYSTERESIS_UI        = 0x13;
const uint8_t _PROXFUSION_FREG_HALL_EFFECT_UI                = 0x16;
const uint8_t _PROXFUSION_FREG_TEMP_UI                                = 0x19;

/* Register outputs */
const uint16_t _PROXFUSION_REG_OUT_HYSTERESIS        = 0x1514;
const uint16_t _PROXFUSION_REG_OUT_HALL_EFFECT  = 0x1817;
const uint16_t _PROXFUSION_REG_OUT_TEMP         = 0x1A;

/* Chanel counts ( raw data ) (R)*/
const uint8_t _PROXFUSION_REG_CH_0_LSB = 0x20;
const uint8_t _PROXFUSION_REG_CH_0_MSB = 0x21;
const uint8_t _PROXFUSION_REG_CH_1_LSB = 0x22;
const uint8_t _PROXFUSION_REG_CH_1_MSB = 0x23;
const uint8_t _PROXFUSION_REG_CH_2_LSB = 0x24;
const uint8_t _PROXFUSION_REG_CH_2_MSB = 0x25;
const uint8_t _PROXFUSION_REG_CH_3_LSB = 0x26;
const uint8_t _PROXFUSION_REG_CH_3_MSB = 0x27;
const uint8_t _PROXFUSION_REG_CH_4_LSB = 0x28;
const uint8_t _PROXFUSION_REG_CH_4_MSB = 0x29;
const uint8_t _PROXFUSION_REG_CH_5_LSB = 0x2A;
const uint8_t _PROXFUSION_REG_CH_5_MSB = 0x2B;

/* LTA values (Filtered data) (RW) */
const uint8_t _PROXFUSION_REG_LTA_CH_0_LSB = 0x30;
const uint8_t _PROXFUSION_REG_LTA_CH_0_MSB = 0x31;
const uint8_t _PROXFUSION_REG_LTA_CH_1_LSB = 0x32;
const uint8_t _PROXFUSION_REG_LTA_CH_1_MSB = 0x33;
const uint8_t _PROXFUSION_REG_LTA_CH_2_LSB = 0x34;
const uint8_t _PROXFUSION_REG_LTA_CH_2_MSB = 0x35;

/* ProxFusion sensor settings block 0 (RW) */
const uint8_t _PROXFUSION_REG_SETTINGS_0_0 = 0x40;
const uint8_t _PROXFUSION_REG_SETTINGS_0_1 = 0x41;
const uint8_t _PROXFUSION_REG_SETTINGS_0_2 = 0x42;
const uint8_t _PROXFUSION_REG_SETTINGS_1_0 = 0x43;
const uint8_t _PROXFUSION_REG_SETTINGS_1_1 = 0x44;
const uint8_t _PROXFUSION_REG_SETTINGS_1_2 = 0x45;
const uint8_t _PROXFUSION_REG_SETTINGS_2_0 = 0x46;
const uint8_t _PROXFUSION_REG_SETTINGS_2_1 = 0x47;
const uint8_t _PROXFUSION_REG_SETTINGS_2_2 = 0x48;
const uint8_t _PROXFUSION_REG_SETTINGS_3_0 = 0x49;
const uint8_t _PROXFUSION_REG_SETTINGS_3_1 = 0x4A;
const uint8_t _PROXFUSION_REG_SETTINGS_3_2 = 0x4B;

/* ProxFusion sensor settings block 1 (RW) */
const uint8_t _PROXFUSION_REG_SETTINGS_4        = 0x50;
const uint8_t _PROXFUSION_REG_SETTINGS_5        = 0x51;
const uint8_t _PROXFUSION_REG_COMPENSATION_CH_0 = 0x52;
const uint8_t _PROXFUSION_REG_COMPENSATION_CH_1 = 0x53;
const uint8_t _PROXFUSION_REG_COMPENSATION_CH_2 = 0x54;
const uint8_t _PROXFUSION_REG_MULTIPLIERS_CH_0  = 0x55;
const uint8_t _PROXFUSION_REG_MULTIPLIERS_CH_1  = 0x56;
const uint8_t _PROXFUSION_REG_MULTIPLIERS_CH_2  = 0x57;

/* RroxFusion UI settings (RW) */
const uint8_t _PROXFUSION_REG_PROX_CH_0    = 0x60;
const uint8_t _PROXFUSION_REG_TOUCH_CH_0   = 0x61;
const uint8_t _PROXFUSION_REG_PROX_CH_1    = 0x62;
const uint8_t _PROXFUSION_REG_TOUCH_CH_1   = 0x63;
const uint8_t _PROXFUSION_REG_PROX_CH_2    = 0x64;
const uint8_t _PROXFUSION_REG_TOUCH_CH_2   = 0x65;
const uint8_t _PROXFUSION_REG_UI_HALY_TIME = 0x66;

/* SAR UI settings (RW) */
const uint8_t _PROXFUSION_REG_SAR_SETTINGS_CH0       = 0x70;
const uint8_t _PROXFUSION_REG_SAR_SETTINGS_CH1       = 0x71;
const uint8_t _PROXFUSION_REG_QRD_THRESHOLD          = 0x72;
const uint8_t _PROXFUSION_REG_FILTER_HALT_THRESHOLD  = 0x73;
const uint8_t _PROXFUSION_REG_PROX_THRESHOLD         = 0x74;

/* Hysteresis UI settings (RW) */
const uint8_t _PROXFUSION_REG_HYS_UI_SETTINGS       = 0x80;
const uint8_t _PROXFUSION_REG_HYS_FILTER_THRESHOLD  = 0x81;
const uint8_t _PROXFUSION_REG_HYS_PROX_THRESHOLD    = 0x82;
const uint8_t _PROXFUSION_REG_HYS_TOUCH_THRESHOLD   = 0x83;

/* Hall-effect sensor settings (RW) */
const uint8_t _PROXFUSION_REG_HALL_SETTINGS_0       = 0x90;
const uint8_t _PROXFUSION_REG_HALL_SETTINGS_1       = 0x91;
const uint8_t _PROXFUSION_REG_HALL_COMPENSATION_4_5 = 0x92;
const uint8_t _PROXFUSION_REG_HALL_MULTIPLIERS_4_5  = 0x93;

/* Hall-effect switch UI settings (RW)*/
const uint8_t _PROXFUSION_REG_HALL_SWITCH_UI    = 0xA0;
const uint8_t _PROXFUSION_REG_HALL_SWITCH_PROX  = 0xA1;
const uint8_t _PROXFUSION_REG_HALL_SWITCH_TOUCH = 0xA2;

/* Temperature UI settings (RW) */
const uint8_t _PROXFUSION_REG_TEMP_UI_SETTINGS    = 0xC0;
const uint8_t _PROXFUSION_REG_TEMP_MULTIPLIERS_3  = 0xC1;
const uint8_t _PROXFUSION_REG_TEMP_DATA_0         = 0xC2;
const uint8_t _PROXFUSION_REG_TEMP_DATA_1         = 0xC3;
const uint8_t _PROXFUSION_REG_TEMP_OFFSET         = 0xC4;

const uint8_t _PROXFUSION_REG_I2C_SETTINGS        = 0xDA;

/* System settings */
const uint8_t _PROXFUSION_SYSTEM_RESET     = 0x02 << 6;
const uint8_t _PROXFUSION_SYSTEM_ATI_RESET = 0x02;
const uint8_t _PROXFUSION_EVENT_MODE_0     = 0x00 << 5;
const uint8_t _PROXFUSION_EVENT_MODE_1     = 0x01 << 5;
const uint8_t _PROXFUSION_CLOCK_16MHz      = 0x00 << 4;
const uint8_t _PROXFUSION_CLOCK_4MHz       = 0x01 << 4;
const uint8_t _PROXFUSION_ATI_DESABLED     = 0x00 << 3;
const uint8_t _PROXFUSION_ATI_ENABLED      = 0x01 << 3;
const uint8_t _PROXFUSION_ATI_BAND_1_8     = 0x00 << 3;
const uint8_t _PROXFUSION_ATI_BAND_1_16    = 0x01 << 3;

/* Event mask*/
const uint8_t _PROXFUSION_MASK_SAR_ACTIVE          = 0x80;
const uint8_t _PROXFUSION_MASK_PMU_EVENT           = 0x40;
const uint8_t _PROXFUSION_MASK_SYS_EVENT           = 0x20;
const uint8_t _PROXFUSION_MASK_TEMP_EVENT          = 0x10;
const uint8_t _PROXFUSION_MASK_HYSTERESIS_EVENT    = 0x08;
const uint8_t _PROXFUSION_MASK_HALL_EVENT          = 0x04;
const uint8_t _PROXFUSION_MASK_SAR_EVENT           = 0x02;
const uint8_t _PROXFUSION_MASK_PROX_SENSE_EVENT    = 0x01;




/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __PROXFUSION_DRV_SPI__

void proxfusion_spiDriverInit(T_PROXFUSION_P gpioObj, T_PROXFUSION_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __PROXFUSION_DRV_I2C__

void proxfusion_i2cDriverInit(T_PROXFUSION_P gpioObj, T_PROXFUSION_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __PROXFUSION_DRV_UART__

void proxfusion_uartDriverInit(T_PROXFUSION_P gpioObj, T_PROXFUSION_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void proxfusion_gpioDriverInit(T_PROXFUSION_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */
uint8_t proxfusion_readStatus(uint8_t reg)
{
    uint8_t wReg[1];
    uint8_t rReg[1];
    wReg[0] = reg;
        
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, rReg, 1, END_MODE_STOP);
    Delay_10ms();
        
    return rReg[0];
}

uint16_t proxfusion_readData(uint8_t reg)
{
    uint8_t wReg[1];
    uint8_t rReg[2];
    uint16_t Value;
    wReg[0] = reg;
        
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, rReg, 2, END_MODE_RESTART);
    
    Value = rReg[1];
    Value <<= 8;
    Value |= rReg[0];
        
    return Value;
}

uint16_t proxfusion_getTemperature()
{
    uint8_t wReg[1];
    uint8_t rReg[2];
    uint16_t Value;
    wReg[0] = _PROXFUSION_REG_OUT_TEMP;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, rReg, 2, END_MODE_RESTART);

    Value = rReg[1];
    Value <<= 8;
    Value |= rReg[0];

    Value = (Value / 8) - 273;

    return Value;
}

void proxfusion_systemSetting(uint8_t value)
{
    uint8_t wReg[2];
    wReg[0] = 0xD0;
    wReg[1] = value;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_STOP);
    Delay_10ms();
}

void proxfusion_EventMask(uint8_t value)
{
    uint8_t wReg[2];
    wReg[0] = 0xD7;
    wReg[1] = value;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 2, END_MODE_STOP);
    Delay_10ms();
}

uint8_t proxfusion_Touch()
{
    uint8_t wReg[1];
    uint8_t rReg[1];
    wReg[0] = 0x12;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, rReg, 1, END_MODE_STOP);
    Delay_10ms();

    if(rReg[0] == 0x33)
       return 2;
    if(rReg[0] == 0x44)
       return 1;
    if(rReg[0] == 0x77)
       return 3;
    
    return 0;
}




/* -------------------------------------------------------------------------- */
/*
  __proxfusion_driver.c

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