// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <config_common.h>

// 18-digit serial number. Must be programmed at factory
// TODO: Figure out how to do that. Probably a script to compile qmk
#define SERIAL_NUMBER "FRALDLvvccxxxxxxxx"

#ifdef KEYBOARD_lotus_ansi
    #define LED_CAPS_LOCK_PIN GP24
#elif KEYBOARD_lotus_iso
    #define LED_CAPS_LOCK_PIN GP24
#elif KEYBOARD_lotus_jis
    #define LED_CAPS_LOCK_PIN GP24
#elif KEYBOARD_lotus_numpad
    #define LED_NUM_LOCK_PIN GP24
#elif KEYBOARD_lotus_gridpad
#endif

// PWM single one backlight configuration
// The RP2040 datasheet says GPIO25 maps to PWM channel 4B
// On the Raspberry Pi Pico this is the green LED on the board, good for prototyping
#define BACKLIGHT_PWM_DRIVER    PWMD4
#define BACKLIGHT_PWM_CHANNEL   RP2040_PWM_CHANNEL_B

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
