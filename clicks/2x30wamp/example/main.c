/*!
 * \file 
 * \brief c2x30W Amp Click example
 * 
 * # Description
 * This application is audio amplifier.
 *
 * The demo application is composed of two sections :
 * 
 * ## Application Init 
 * Initializes GPIO driver and allows the device to be enabled.
 * 
 * ## Application Task  
 * Allows the mute operation for a period of 4 seconds,
 * and after allows the unmute operation for a period of 10 seconds. After that time checks is
 * over current fault, over temperature fault or too high DC offset fault occurred.
 * Note: When under or over voltage condition occurres the output goes to high impedance state,
 * but the FAULT pin will not be asserted.
 * 
 * \author MikroE Team
 *
 */
// ------------------------------------------------------------------- INCLUDES

#include "board.h"
#include "log.h"
#include "c2x30wamp.h"

// ------------------------------------------------------------------ VARIABLES

static c2x30wamp_t c2x30wamp;
static log_t logger;

// ------------------------------------------------------ APPLICATION FUNCTIONS

void application_init ( void )
{
    log_cfg_t log_cfg;
    c2x30wamp_cfg_t cfg;

    //  Logger initialization.

    log_cfg.level = LOG_LEVEL_DEBUG;
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info(&logger, "---- Application Init ----");

    //  Click initialization.

    c2x30wamp_cfg_setup( &cfg );
    C2X30WAMP_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    c2x30wamp_init( &c2x30wamp, &cfg );

    c2x30wamp_enable( &c2x30wamp, C2X30WAMP_ENABLE );
    log_printf( &logger, "2x30W AMP is initialized \r\n" );
    Delay_ms( 200 );
}

void application_task ( void )
{
    uint8_t fault_check;

    c2x30wamp_mute( &c2x30wamp, C2X30WAMP_MUTE );
    Delay_ms( 4000 );
    c2x30wamp_mute( &c2x30wamp, C2X30WAMP_UNMUTE );
    Delay_ms( 10000 );
    
    fault_check = c2x30wamp_check_diagnostic( &c2x30wamp );
    if ( fault_check == 0 )
    {
        log_printf( &logger, "Fault condition! \r\n" );
    }
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
