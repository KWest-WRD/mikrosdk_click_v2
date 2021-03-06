
---
# Bluetooth click

With the range up to a 100m and low power consumption, Bluetooth click is a great solution if you are looking for a simple way to integrate Bluetooth 2.1 communication to your device. It features the RN-41 low power, class 1 Bluetooth radio module. Bluetooth click communicates with the target board MCU through UART interface and is designed to run on 3.3V power supply only.

<p align="center">
  <img src="http://download.mikroe.com/images/click_for_ide/bluetooth_click.png" height=300px>
</p>

[click Product page](<https://www.mikroe.com/bluetooth-click>)

---


#### Click library 

- **Author**        : MikroE Team
- **Date**          : Jun 2020.
- **Type**          : UART GPS/GNSS type


# Software Support

We provide a library for the Bluetooth Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). 
The demo can run on all the main MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account. 

## Library Description

> This library contains API for Bluetooth Click driver.

#### Standard key functions :

- Config Object Initialization function.
> void bluetooth_cfg_setup ( bluetooth_cfg_t *cfg ); 
 
- Initialization function.
> BLUETOOTH_RETVAL bluetooth_init ( bluetooth_t *ctx, bluetooth_cfg_t *cfg );


#### Example key functions :

- The function enter the command mode of the RN-41 Bluetooth module on Bluetooth Click board.
> BLUETOOTH_RETVAL bluetooth_enter_command_mode ( bluetooth_t *ctx );
 
- The function set the authentication value to the RN-41 Bluetooth module on Bluetooth Click board.
> BLUETOOTH_RETVAL bluetooth_set_authentication ( bluetooth_t *ctx, uint8_t auth_value );

- The function set security pin code string to the RN-41 Bluetooth module on Bluetooth Click board.
> BLUETOOTH_RETVAL bluetooth_set_security_pin_code ( bluetooth_t *ctx, uint8_t *sp_code );

## Examples Description

> This example reads and processes data from Bluetooth clicks.

**The demo application is composed of two sections :**

### Application Init 

> Initialization driver enables - UART,
> enable interrupts routine, enter command mode, set device name,
> set extended status string, set operating mode, set auth,
> and set security pin code also write log. 

```c

void application_init ( void )
{
    log_cfg_t log_cfg;
    bluetooth_cfg_t cfg;

    //  Logger initialization.

    LOG_MAP_USB_UART( log_cfg );
    log_cfg.level = LOG_LEVEL_DEBUG;
    log_cfg.baud = 115200;
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );

    //  Click initialization.

    bluetooth_cfg_setup( &cfg );
    BLUETOOTH_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    bluetooth_init( &bluetooth, &cfg );

    cmd_mode = 1;
    data_ready = 0;

    Delay_ms( 500 );

    do
    {    
        bluetooth_enter_command_mode( &bluetooth );
        Delay_ms( 500 );
        log_printf( &logger, " --- Command mode --- \r\n" );
        bluetooth_process(  );
    }
    while ( bluetooth_get_response( &bluetooth ) != BLUETOOTH_CMD );

    do
    {
        bluetooth_set_device_name( &bluetooth, &DEVICE_NAME_DATA[ 0 ] );
        Delay_ms( 500 );
        log_printf( &logger, " --- Device name --- \r\n" );
        bluetooth_process(  );
    }
    while ( bluetooth_get_response( &bluetooth ) != BLUETOOTH_AOK );

    do
    {
        bluetooth_set_extended_status_string( &bluetooth, &EXTENDED_STRING_DATA[ 0 ] );
        Delay_ms( 500 );
        log_printf( &logger, " --- Status string --- \r\n" );
        bluetooth_process(  );
    }
    while ( bluetooth_get_response( &bluetooth ) != BLUETOOTH_AOK );

    do
    {
        bluetooth_set_operating_mode( &bluetooth, 0 );
        Delay_ms( 500 );
        log_printf( &logger, " --- Operating mode --- \r\n" );
        bluetooth_process(  );
    }
    while ( bluetooth_get_response( &bluetooth ) != BLUETOOTH_AOK );

    do
    {
        bluetooth_set_authentication( &bluetooth, 1 );
        Delay_ms( 500 );
        log_printf( &logger, " --- Authentication --- \r\n" );
        bluetooth_process(  );
    }
    while ( bluetooth_get_response( &bluetooth ) != BLUETOOTH_AOK );

    do
    {
        bluetooth_set_security_pin_code( &bluetooth, &PIN_CODE_DATA[ 0 ] );
        Delay_ms( 500 );
        log_printf( &logger, " --- Pin code --- \r\n" );
        bluetooth_process(  );
    }
    while ( bluetooth_get_response( &bluetooth ) != BLUETOOTH_AOK );

    cmd_mode = 0;
    data_ready = 0;
}
  
```

### Application Task

> This is an example which demonstrates the use of Bluetooth click board.
> Reads the received data and parses it. 

```c

void application_task ( void )
{
    bluetooth.buffer_cnt = 0;

    memset( bluetooth.driver_buffer, 0, 255 );
    
    log_printf( &logger, " * Waiting for message. * \r\n" );
    Delay_ms ( 1000 );

    while ( !data_ready )
    {
        bluetooth_process(  );
        Delay_ms ( 1000 );
    }

    data_ready = 0;

    bluetooth.buffer_cnt = 0;
} 

```

## Note

> Before starting to use this click, it must be paired with other device.

The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.Bluetooth

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
