/**
 * \file
 *
 * \brief Example configuration header file.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
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

/**
 * \defgroup twim_pdca_example_pin_defs
 *   - <b> Board  --  EEPROM </b>
 *   - TWIMS1 TWD(J4 PIN1)  --  SDA
 *   - TWIMS1 TWCK(J4 PIN2)  --  SCL
 *   - VCC  --  VCC
 *   - GND  --  GND
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef CONF_EXAMPLE_H_INCLUDED
#define CONF_EXAMPLE_H_INCLUDED

//! TWIM Interrupt Number
#define EXAMPLE_TWIM_IRQn    TWIM1_IRQn
//! TWIM Module Used
#define EXAMPLE_TWIM         TWIM1
//! Target's TWI address
#define TARGET_ADDRESS       0x50
//! Internal Address length
#define TARGET_ADDR_LGT      2
//! Internal Address
#define VIRTUALMEM_ADDR      0x50
//! Speed of TWI
#define TWIM_MASTER_SPEED    TWI_STD_MODE_SPEED
//! TWIM Interrupt Handler
#define EXAMPLE_TWIM_Handler TWIM1_Handler

#endif /* CONF_EXAMPLE_H_INCLUDED */
