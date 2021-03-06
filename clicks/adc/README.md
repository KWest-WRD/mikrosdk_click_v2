\mainpage Main Page

 

---
# ADC click

ADC Click carries the MCP3204 12-bit Analog-to-Digital converter. The click is designed to run on 3.3V by default.
Place PWR SEL SMD jumper to 5V position if used with 5V systems.

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/ADC.png">
</p>

[click Product page](<https://www.mikroe.com/adc-click>)

---


#### Click library

- **Author**        : Nemanja Medakovic
- **Date**          : Nov 2019.
- **Type**          : SPI type


# Software Support

We provide a library for the Adc Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers).
The demo can run on all the main MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account.

## Library Description

> This library contains API for Adc Click driver.

#### Standard key functions :

- Configuration Object Setup function.
> void adc_cfg_setup( adc_cfg_t *cfg );
 
- Click Initialization function.
> adc_err_t adc_init( adc_t *ctx, adc_cfg_t *cfg );

#### Example key functions :

- Get Single-Ended Channel function.
> uint16_t adc_get_single_ended_ch( adc_t *ctx, adc_ch_t channel );
 
- Get Pseudo-Differential Pair function.
> uint16_t adc_get_differential_ch( adc_t *ctx, adc_ch_t channel );

## Examples Description

>
> This example demonstrates the use of ADC Click board.
> The all channels can be configured as single-ended or pseudo-differential pair.
>

**The demo application is composed of two sections :**

### Application Init

>
> Initializes SPI driver, performs the reference voltage selection and
> initializes UART console for results logging.
>

```c

void application_init( void )
{
    adc_cfg_t adc_cfg;
    log_cfg_t console_cfg;

    //  Click initialization.
    adc_cfg_setup( &adc_cfg );
    ADC_MAP_MIKROBUS( adc_cfg, MIKROBUS_1 );
    adc_init( &adc, &adc_cfg );

    //  UART console initialization.
    LOG_MAP_USB_UART( console_cfg );
    console_cfg.baud = 57600;
    log_init( &console, &console_cfg );
    log_write( &console, "* * *  ADC initialization done  * * *",
               LOG_FORMAT_LINE );
    log_write( &console, "*************************************",
               LOG_FORMAT_LINE );
}

```

### Application Task

>
> Reads voltage level of channels 0 and 1 in the both configurations,
> single-ended and pseudo-differential pair, every 1 second.
> All channels results will be calculated to millivolts [mV].
>

```c

void application_task( void )
{
    adc_get_single_ended_ch( &adc, ADC_CH0_OR_CH01 );
    adc_get_single_ended_ch( &adc, ADC_CH1_OR_CH10 );
    adc_get_differential_ch( &adc, ADC_CH0_OR_CH01 );
    adc_get_differential_ch( &adc, ADC_CH1_OR_CH10 );

    log_printf( &console, "* CH0 = %d mV\r\n", adc.ch0 );
    log_printf( &console, "* CH1 = %d mV\r\n", adc.ch1 );
    log_printf( &console, "* CH0 - CH1 = %d mV\r\n", adc.ch01 );
    log_printf( &console, "* CH1 - CH0 = %d mV\r\n\n", adc.ch10 );

    Delay_ms( 1000 );
}

```

## Note

>
> In single-ended mode the all channels must be in the range from Vss (GND)
> to Vref (3V3 by default).
> In pseudo-differential mode the IN- channel must be in the range from
> (Vss - 100mV) to (Vss + 100mV). The IN+ channel must be in the range from
> IN- to (Vref + IN-).
> If any of conditions are not satisfied, the device will return 0 or Vref
> voltage level, and measurements are not valid.
>

The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.Adc

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
