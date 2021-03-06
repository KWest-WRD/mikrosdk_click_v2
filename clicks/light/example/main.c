/*!
 * \file 
 * \brief Light Click example
 * 
 * # Description
 * This application return the ambient light intensity.
 *
 * The demo application is composed of two sections :
 * 
 * ## Application Init 
 * Initialization driver enable's - SPI and start write log.
 * 
 * ## Application Task  
 * This is a example which demonstrates the use of Light Click board.
 * Measured light intensity and calculate light intensity percent from sensor,
 * results are being sent to the Usart Terminal where you can track their changes.
 * All data logs on usb uart for aproximetly every 100 ms when the data value changes.
 * 
 *
 * 
 * \author MikroE Team
 *
 */
// ------------------------------------------------------------------- INCLUDES

#include "board.h"
#include "log.h"
#include "light.h"

// ------------------------------------------------------------------ VARIABLES

static light_t light;
static log_t logger;

void application_init ( void )
{
    log_cfg_t log_cfg;
    light_cfg_t cfg;

    //  Logger initialization.

    LOG_MAP_USB_UART( log_cfg );
    log_cfg.level = LOG_LEVEL_DEBUG;
    log_cfg.baud = 9600;
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );

    //  Click initialization.

    light_cfg_setup( &cfg );
    LIGHT_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    light_init( &light, &cfg );

}

void application_task ( void )
{
    uint16_t light_value;
    uint8_t light_percent;
    uint8_t percent_old = 1;

    light_value = light_read_data( &light );
    light_percent = light_calculate_percent( &light, light_value );
    

    if ( percent_old != light_percent )
    {
        log_printf( &logger, " Light Intensity : %d \r\n", light_percent );

        log_printf( &logger, " Light Value     : %d\r\n", light_value );

        percent_old = light_percent;
        Delay_100ms();
    }
    Delay_ms( 1000 );

}

void main ( void )
{
    application_init( );

    for ( ; ; )
    {
        application_task( );
    }
}


// ------------------------------------------------------------------------ END
