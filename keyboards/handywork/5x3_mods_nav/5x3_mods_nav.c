// TODO: License header

#include "quantum.h"

#if defined(LED_MATRIX_ENABLE)

const is31fl3733_led_t PROGMEM g_is31fl3733_leds[IS31FL3733_LED_COUNT] = {
/* Driver
 *   |  V */
    {0, SW3_CS11},
    {0, SW5_CS9},
    {0, SW5_CS12},
    {0, SW5_CS13},
    {0, SW5_CS2},
    {0, SW5_CS5},
    {0, SW5_CS7},
    {0, SW5_CS6},
    {0, SW5_CS8},
    {0, SW3_CS10},
    {0, SW4_CS11},
    {0, SW3_CS9},
    {0, SW3_CS12},
    {0, SW3_CS13},
    {0, SW3_CS2},
    {0, SW3_CS1},
    {0, SW3_CS5},
    {0, SW3_CS7},
    {0, SW3_CS6},
    {0, SW3_CS8},
    {0, SW4_CS10},
    {0, SW2_CS11},
    {0, SW4_CS9},
    {0, SW4_CS12},
    {0, SW4_CS13},
    {0, SW4_CS2},
    {0, SW4_CS3},
    {0, SW4_CS1},
    {0, SW4_CS4},
    {0, SW4_CS5},
    {0, SW4_CS7},
    {0, SW4_CS6},
    {0, SW4_CS8},
    {0, SW2_CS10},
    {0, SW1_CS11},
    {0, SW2_CS9},
    {0, SW2_CS12},
    {0, SW2_CS6},
    {0, SW2_CS8},
    {0, SW1_CS10},
    {0, SW1_CS13},
    {0, SW1_CS2},
    {0, SW1_CS3},
    {0, SW1_CS4},
    {0, SW1_CS5},
    {0, SW1_CS7},
};

#endif // LED_MATRIX_ENABLE
