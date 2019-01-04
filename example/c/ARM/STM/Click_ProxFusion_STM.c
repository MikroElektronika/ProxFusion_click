/*
Example for ProxFusion Click

    Date          : Dec 2017.
    Author        : MikroE Team

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization -  Intializes I2C module
- Application Initialization -  Driver intialization and ProxFusion settings mode
- Application Task - (code snippet) -

*/

#include "Click_ProxFusion_types.h"
#include "Click_ProxFusion_config.h"

uint8_t touch;

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_PROXFUSION_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    proxfusion_i2cDriverInit( (T_PROXFUSION_P)&_MIKROBUS1_GPIO, (T_PROXFUSION_P)&_MIKROBUS1_I2C, 0x44 );
    proxfusion_systemSetting(_PROXFUSION_SYSTEM_RESET |
                             _PROXFUSION_EVENT_MODE_1 |
                             _PROXFUSION_CLOCK_16MHz |
                             _PROXFUSION_ATI_ENABLED |
                             _PROXFUSION_ATI_BAND_1_16 |
                             _PROXFUSION_SYSTEM_ATI_RESET);

    proxfusion_EventMask( _PROXFUSION_MASK_SYS_EVENT );
    Delay_1sec();
    mikrobus_logWrite("Initialize.....",_LOG_LINE);
    Delay_1sec();
}

void applicationTask()
{
    touch = proxfusion_Touch();
    if( touch == 1 )
        mikrobus_logWrite("Touch 1",_LOG_LINE);
    if( touch == 2 )
        mikrobus_logWrite("Touch 2",_LOG_LINE);
    if ( touch == 3 )
        mikrobus_logWrite("Touch antenna",_LOG_LINE);
    Delay_100ms();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
}