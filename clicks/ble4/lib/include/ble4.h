/*
 * MikroSDK - MikroE Software Development Kit
 * Copyright© 2020 MikroElektronika d.o.o.
 * 
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE 
 * OR OTHER DEALINGS IN THE SOFTWARE. 
 */

/*!
 * \file
 *
 * \brief This file contains API for BLE 4  Click driver.
 *
 * \addtogroup ble4 BLE 4  Click Driver
 * @{
 */
// ----------------------------------------------------------------------------

#ifndef BLE4_H
#define BLE4_H

#include "drv_digital_out.h"
#include "drv_digital_in.h"
#include "drv_uart.h"

// -------------------------------------------------------------- PUBLIC MACROS 
/**
 * \defgroup macros Macros
 * \{
 */

/**
 * \defgroup map_mikrobus MikroBUS
 * \{
 */
#define BLE4_MAP_MIKROBUS( cfg, mikrobus ) \
  cfg.tx_pin  = MIKROBUS( mikrobus, MIKROBUS_TX ); \
  cfg.rx_pin  = MIKROBUS( mikrobus, MIKROBUS_RX ); \
  cfg.dtr = MIKROBUS( mikrobus, MIKROBUS_AN ); \
  cfg.rst = MIKROBUS( mikrobus, MIKROBUS_RST ); \
  cfg.cts = MIKROBUS( mikrobus, MIKROBUS_CS ); \
  cfg.dsr = MIKROBUS( mikrobus, MIKROBUS_PWM ); \
  cfg.rts = MIKROBUS( mikrobus, MIKROBUS_INT )
/** \} */

/**
 * \defgroup error_code Error Code
 * \{
 */
#define BLE4_RETVAL  uint8_t

#define BLE4_OK           0x00
#define BLE4_INIT_ERROR   0xFF
/** \} */

/**
 * \defgroup cfg_ctrl Configuration & Control
 * \{
 */
#define BLE4_END_BUFF                         0

#define BLE4_READ_MODE                        1
#define BLE4_WRITE_MODE                       2

#define BLE4_RSP_READY                        1
#define BLE4_RSP_NOT_READY                    0

#define BLE4_OK                               0x00
#define BLE4_ERROR                            0xFF

#define BLE4_ECHO_ON                          1
#define BLE4_ECHO_OFF                         0

#define BLE4_COMMAND_MODE                     0
#define BLE4_DATA_MODE                        1
#define BLE4_EXT_DATA_MODE                    2
#define BLE4_PPP_MODE                         3

#define BLE4_DISABLED_ROLE                    0
#define BLE4_CENTRAL_ROLE                     1
#define BLE4_PERIPHERAL_ROLE                  2
#define BLE4_SIMULTANEOUS_ROLE                3

#define BLE4_SEC_DISABLED                     1
#define BLE4_SEC_JUST_WORKS                   2
#define BLE4_SEC_DISPLAY_ONLY                 3
#define BLE4_SEC_DISPLAY_YES_NO               4
#define BLE4_SEC_KEYBOARD_ONLY                5
#define BLE4_SEC_OUT_OF_BAND                  6

#define BLE4_GAP_NON_PAIRING_MODE             1
#define BLE4_GAP_PAIRING_MODE                 2

#define BLE4_GAP_NON_CONNECTABLE_MODE         1
#define BLE4_GAP_CONNECTABLE_MODE             2

#define BLE4_GAP_NON_DISCOVERABLE_MODE        1
#define BLE4_GAP_LIMITED_DISCOVERABLE_MODE    2
#define BLE4_GAP_GENERAL_DISCOVERABLE_MODE    3
/** \} */

/**
 * \defgroup driver Driver define
 * \{
 */
#define DRV_RX_BUFFER_SIZE 500
/** \} */

/** \} */ // End group macro 
// --------------------------------------------------------------- PUBLIC TYPES
/**
 * \defgroup type Types
 * \{
 */
/**
 * @brief Click ctx object definition.
 */
typedef struct
{
    // Output pins 

    digital_out_t rst;
    digital_out_t cts;
    digital_out_t dsr;

    // Input pins 

    digital_in_t dtr;
    digital_in_t rts;
    
    // Modules 

    uart_t uart;

    char uart_rx_buffer[ DRV_RX_BUFFER_SIZE ];
    char uart_tx_buffer[ DRV_RX_BUFFER_SIZE ];

} ble4_t;

/**
 * @brief Click configuration structure definition.
 */
typedef struct
{
    // Communication gpio pins 

    pin_name_t rx_pin;
    pin_name_t tx_pin;
    
    // Additional gpio pins 

    pin_name_t dtr;
    pin_name_t rst;
    pin_name_t cts;
    pin_name_t dsr;
    pin_name_t rts;

    // static variable 

    uint32_t          baud_rate;     // Clock speed.
    bool              uart_blocking;
    uart_data_bits_t  data_bit;      // Data bits.
    uart_parity_t     parity_bit;    // Parity bit.  
    uart_stop_bits_t  stop_bit;      // Stop bits.    

} ble4_cfg_t;

/**
 * @brief Error type 
 */
typedef uint8_t ble4_error_t;

/** \} */ // End types group
// ----------------------------------------------- PUBLIC FUNCTION DECLARATIONS

/**
 * \defgroup public_function Public function
 * \{
 */
 
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Config Object Initialization function.
 *
 * @param cfg  Click configuration structure.
 *
 * @description This function initializes click configuration structure to init state.
 * @note All used pins will be set to unconnected state.
 */
void ble4_cfg_setup ( ble4_cfg_t *cfg );

/**
 * @brief Initialization function.
 * @param ble4 Click object.
 * @param cfg Click configuration structure.
 * 
 * @description This function initializes all necessary pins and peripherals used for this click.
 */
BLE4_RETVAL ble4_init ( ble4_t *ctx, ble4_cfg_t *cfg );

/**
 * @brief Generic write function.
 * @param ble4 Click object.
 * @param data_buf Data buffer for sends.
 * @param len Number of bytes for sends.
 */
void ble4_generic_write ( ble4_t *ctx, char *data_buf, uint16_t len );

/**
 * @brief Generic read function.
 * @param ble4 Click object.
 * @param data_buf Data buffer for read data.
 * @param max_len The maximum length of data that can be read.
 * @return Number of reads data.
 */
uint16_t ble4_generic_read ( ble4_t *ctx, char *data_buf, uint16_t max_len );

/**
 * @brief Uart write function.
 * 
 * @param ble4      Click object.
 * @param w_data    Write data.
 * 
 * @description This function writes the specified string byte by byte using UART.
 */
void ble4_uart_write ( ble4_t *ctx, uint8_t *w_data );

/**
 * @brief Hardware reset function.
 * 
 * @param ble4    Click object.
 * 
 * @description This function performs a hardware reset of the device.
 */
void ble4_hardware_reset ( ble4_t *ctx );

/**
 * @brief Factory reset function.
 * 
 * @param ble4    Click object.
 * 
 * @description This function performs a factory reset of the device.
 */
void ble4_factory_reset ( ble4_t *ctx );

/**
 * @brief Set device name function.
 * 
 * @param ble4        Click object.
 * @param dev_name    Device name.
 * 
 * @description This function sets the device name for the click module.
 */
void ble4_set_device_name ( ble4_t *ctx, uint8_t *dev_name );

/**
 * @brief Set data mode function.
 * 
 * @param ble4    Click object.
 * @param mode    Mode.
 * 
 * @description This function sets the device name for the click module.
 */
void ble4_set_data_mode ( ble4_t *ctx, uint8_t mode );

#ifdef __cplusplus
}
#endif
#endif  // _BLE4_H_

/** \} */ // End public_function group
/// \}    // End click Driver group  
/*! @} */
// ------------------------------------------------------------------------- END
