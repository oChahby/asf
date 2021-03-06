/**
* \file
*
* \brief Next DST Change Service Application declarations
*
* Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
*
* \asf_license_start
*
* \page License
*
* Subject to your compliance with these terms, you may use Microchip
* software and any derivatives exclusively with Microchip products.
* It is your responsibility to comply with third party license terms applicable
* to your use of third party software (including open source software) that
* may accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
* INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
* AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
* LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
* LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
* SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
* POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
* ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
* RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*
* \asf_license_stop
*
*/
/*
* Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
*/
// <<< Use Configuration Wizard in Context Menu >>>
// <h> Next DST Change Service Configuration
// =======================
#ifndef __NEXT_DST_H__
#define __NEXT_DST_H__

/***********************************************************************************
 *									Includes		                               *
 **********************************************************************************/
#include "ble_manager.h"

/***********************************************************************************
 *									Macros			                               *
 **********************************************************************************/
/* Link Loss Alert length of data to read */
//  <o> Characteristics read Lenght <0-100>
//  <i> Defines number of bytes to characteristics read length .
//  <i> Default: 8
//  <id> dst_read_length
#define DST_READ_LENGTH                         (8)

/* Link Loss read offset length*/
//  <o> Characteristics read Offset <0-100>
//  <i> Defines offset value to read characteristics.
//  <i> Default: 0
//  <id> dst_read_offset
#define DST_READ_OFFSET                         (0)

/* Link Loss invalid character handler*/
#define DST_INVALID_CHAR_HANDLE					(0)


/***********************************************************************************
 *									Types		                               *
 **********************************************************************************/
typedef struct gatt_dst_handler
{
	at_ble_handle_t start_handle;
	at_ble_handle_t end_handle;
	at_ble_handle_t dst_char_handle;
	at_ble_status_t char_discovery;
	uint8_t *dst_char_data;
}gatt_dst_handler_t;


/***********************************************************************************
 *									Functions		                               *
 **********************************************************************************/
/**@brief Send the Read request to the current time characteristic
 * Read value will be reported via @ref AT_BLE_CHARACTERISTIC_READ_RESPONSE
 *event
 *
 * @param[in] conn_handle handle of the connection
 * @param[in] char_handle handle of the characteristic
 * @return @ref AT_BLE_SUCCESS operation completed successfully
 * @return @ref AT_BLE_INVALID_PARAM Invalid arguments.
 * @return @ref AT_BLE_FAILURE Generic error.
 */
at_ble_status_t tis_dst_change_read(at_ble_handle_t conn_handle,
		at_ble_handle_t char_handle);

/**@brief Read response handler for read response
 *
 * @param[in] read_value read response data available form
 *at_ble_characteristic_read_response_t
 * @return Current time value.
 * @return LLS_READ_RESP_INVALID if value are other than alert levels
 */
int8_t tis_dst_change_read_response(at_ble_characteristic_read_response_t *read_resp,
		gatt_dst_handler_t *dst_handler);
		
#endif /*__NEXT_DST_H__*/
// </h>

// <<< end of configuration section >>>
