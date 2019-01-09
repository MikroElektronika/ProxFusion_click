![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# ProxFusion Click

- **CIC Prefix**  : PROXFUSION
- **Author**      : Katarina Perendic

---

### Software Support

We provide a library for the ProxFusion Click on our [LibStock](https://libstock.mikroe.com/projects/view/2275/proxfusion-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Key functions :

- ``` void proxfusion_systemSetting(uint8_t value) ``` - System settings setup
- ``` uint8_t proxfusion_Touch() ``` - Read info about touch
- ``` uint16_t proxfusion_getTemperature() ``` - Read current temperature

**Examples Description**

Description :

The application is composed of three sections :

- System Initialization -  Intializes I2C module and UART for info logging.
- Application Initialization -  Driver intialization and ProxFusion mode setup.
- Application Task - (code snippet) - Writes information about last detected touch.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2275/proxfusion-click) page.

mikroE Libraries used in the example:

- I2C
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
