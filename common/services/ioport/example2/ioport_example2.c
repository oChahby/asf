/**
 * \file
 *
 * \brief Common IOPORT service example 2.
 *
 * Copyright (c) 2012-2018 Microchip Technology Inc. and its subsidiaries.
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
 * \mainpage
 * \section intro Introduction
 * This example demonstrates how to use the common IOPORT service for pin
 * control.
 *
 * \section files Main Files
 *  - ioport.h common gpio definitions
 *  - ioport_example2.c example application
 *  - conf_example.h example definitions
 *
 * \section ioport_service_section services/ioport/ioport.h
 * The common IOPORT service is described in
 * \ref ioport_group section.
 *
 * \section device_info Device Info
 * All Atmel SAM, MEGA, XMEGA and UC3 devices can be used. This example has been
 * tested with the following setup:
 *  - Xplain evaluation kit
 *  - EVK1100 evaluation kit
 *  - SAM3X evaluation kit
 *  - SAM4L evaluation kit
 *  - SAM4L Xplained Pro kit
 *  - SAM4L8 Xplained Pro kit
 *  - SAM4E evaluation kit
 *  - SAM4N Xplained Pro kit
 *  - STK600 evaluation Kit (Tested with STK600-ATMEGA128RFA1)
 *  - ATmega256RFR2 Xplained Pro kit 
 *  - SAM4C evaluation kit
 *  - SAMG53 Xplained Pro kit
 *  - SAMG55 Xplained Pro kit
 *  - SAMV71 Xplained Ultra kit
 *  - SAME70 Xplained Pro kit
 *
 * \section example_description Description of the example
 * This example flashes a single LEDs present with flash speed of 1Hz.
 *
 * Additionally a pin input can inspected from a debug session.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for SAM and AVR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit <a href="http://www.microchip.com/">Microchip</a>.\n
 * Support and FAQ: https://www.microchip.com/support/
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include "conf_example.h"

int main(void)
{
	/* Use static volatile to make it available in debug watch */
	static volatile bool pin_val;

	sysclk_init();
	board_init();
	ioport_init();

	delay_init(sysclk_get_cpu_hz());

	/* Set output direction on the given LED IOPORTs */
	ioport_set_pin_dir(EXAMPLE_LED, IOPORT_DIR_OUTPUT);

	/* Set direction and pullup on the given button IOPORT */
	ioport_set_pin_dir(EXAMPLE_BUTTON, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(EXAMPLE_BUTTON, IOPORT_MODE_PULLUP);

	/* Set LED IOPORTs high */
	ioport_set_pin_level(EXAMPLE_LED, IOPORT_PIN_LEVEL_HIGH);

	while (true) {
		/* Toggle LED IOPORTs with half a second interval */
		ioport_toggle_pin_level(EXAMPLE_LED);
		delay_ms(500);

		/* Get value from button port */
		/* Use watch with debugger to see it */
		pin_val = ioport_get_pin_level(EXAMPLE_BUTTON);
	}
}
