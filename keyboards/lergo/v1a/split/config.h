// Copyright 2021 Axel Voitier (@Axel Voitier)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xA8E1
#define PRODUCT_ID   0x0001
#define DEVICE_VER   0x001A
#define MANUFACTURER Axel Voitier
#define PRODUCT      Lergo Split

/* key matrix size */
#ifndef MATRIX_ROWS
    #define MATRIX_ROWS 12
#endif
#ifndef MATRIX_COLS
    #define MATRIX_COLS 6
#endif

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#ifndef MATRIX_ROW_PINS
    #define MATRIX_ROW_PINS { F6, F7, B1, B3, B2, B6 }
#endif
#ifndef MATRIX_COL_PINS
    #define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#endif
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2  // or D0, D1, D3, E6

//#define BACKLIGHT_PIN B7
//#define BACKLIGHT_LEVELS 3
//#define BACKLIGHT_BREATHING

// #define RGB_DI_PIN D3
// #ifdef RGB_DI_PIN
//     #define DRIVER_LED_TOTAL 73
//
// #    define RGBLED_NUM 16
// #    define RGBLIGHT_HUE_STEP 8
// #    define RGBLIGHT_SAT_STEP 8
// #    define RGBLIGHT_VAL_STEP 8
// #    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
// #    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== customize breathing effect ==*/
// /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
// #    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
// /*==== use exp() and sin() ====*/
// #    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
// #    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
// #endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
