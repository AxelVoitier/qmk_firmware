// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"

enum _layers {
  _BASE,
  _SYM,
  _FRA,
  _NAV,
  _NUM,
//   _FN,
//   _FN_LOCK,
//   _FM
};

#define KC_WRLF LCTL(KC_LEFT)
#define KC_WRRH LCTL(KC_RGHT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
     * 14 keys │ESC  │Mut│vDn│vUp│Prv│Ply│Nxt│bDn│bUp│Scn│Air│Prt│App│Del │
     *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
     * 14 keys │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backsp│
     *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * 14 keys │ Tab │ Q │ W │ F │ P │ B │ [ │ J │ L │ U │ Y │ - │ ' │ \  │
     *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
     * 13 keys │Backsp│ A │ R │ S │ T │ G │ ] │ M │ N │ E │ I │ O │ Enter │
     *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
     * 12 keys │  Ctrl  │ X │ C │ D │ V │ Z │ / │ K │ H │ , │ . │  Shift  │
     *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
     *         │    │   │   │   │                   │   │   │    │↑  │    │
     * 11 keys │Alt │GUI│Nav│Shi│                   │Shi│Sym│ ←  ├───┤  → │
     *         │    │   │   │   │                   │   │   │    │  ↓│    │
     *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
     * 78 total
     */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, KC_MSEL, KC_DEL,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SCLN, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_MINS, KC_BSLS,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    XXXXXXX, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,             KC_ENT,
        KC_LCTL,          KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,           KC_RSFT,
        KC_LALT, KC_LGUI, MO(_NUM),MO(_NAV),         SFT_T(KC_SPC),             KC_RSFT, LT(_SYM, KC_ENT),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, KC_GRV,  KC_TILD, KC_CIRC, KC_PIPE, XXXXXXX, XXXXXXX, KC_ASTR, KC_QUES, KC_EXLM, KC_PERC, KC_PLUS, _______, XXXXXXX,
        _______, KC_LT,   KC_LCBR, KC_LBRC, KC_LPRN, KC_AT,   XXXXXXX, KC_EQL,  KC_RPRN, KC_RBRC, KC_RCBR, KC_GT,            _______,
        _______,          XXXXXXX, KC_AMPR, KC_DLR,  KC_BSLS, XXXXXXX, XXXXXXX, KC_SLSH, KC_HASH, KC_SCLN, KC_COLN,          _______,
        _______, _______, XXXXXXX, _______,          _______,                   MO(_FRA),_______, _______, _______, _______, _______
    ),
    [_FRA] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC(0xB5),XXXXXXX, UC(0xB1),UC(0xB1),XXXXXXX,
        _______, UC(0x308),UC(0x302),UC(0x300),UC(0x301),UC(0x327),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,UC(0x2126),       _______,
        _______,          XXXXXXX, XXXXXXX, UC(0xB0),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,
        _______, _______, XXXXXXX, _______,          _______,                   _______, _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX, XXXXXXX,
        _______, RGB_RMOD,QK_RBT,  XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, KC_WRLF, KC_LEFT, KC_DOWN, KC_RGHT, KC_WRRH,          _______,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_WRLF, XXXXXXX, KC_WRRH,          _______,
        _______, _______, XXXXXXX, _______,          _______,                   _______, KC_ENT,  _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_PMNS, KC_NUM,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PDOT, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_0,          KC_PENT,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_KP_1, KC_KP_2, KC_KP_3,          _______,
        _______, _______, _______, XXXXXXX,          _______,                   _______, KC_PENT, _______, _______, _______, _______
    ),
     /*
     * Function layer
     *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
     * 14 keys │FN lk│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Ins │
     *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
     * 14 keys │   │   │   │   │   │   │   │   │   │   │   │   │   │      │
     *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * 14 keys │     │   │RGB│Nxt│Hue│Sat│Spd│Brt│   │   │Pau│   │   │    │
     *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
     * 13 keys │      │   │SRq│Prv│Hue│Sat│Spd│Brt│ScL│   │   │   │       │
     *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
     * 12 keys │        │   │   │   │   │   │Brk│   │   │   │   │         │
     *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
     *         │    │   │   │   │                   │   │   │    │PgU│    │
     * 11 keys │    │   │   │   │ Toggle Backlight  │   │   │Home├───┤End │
     *         │    │   │   │   │                   │   │   │    │PgD│    │
     *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
     * 78 total
     */
    // [_FN] = LAYOUT(
    //     FN_LOCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, _______, _______, KC_PAUS, _______, _______, _______,
    //     _______, _______, KC_SYRQ, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, KC_SCRL, _______, _______, _______,          _______,
    //     _______,          _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______,          BL_STEP,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    // ),
    // Function lock layer
    // Everything on F-row locked to function layer, except ESC and DEL
    // [_FN_LOCK] = LAYOUT(
    //     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, MO(_FM), _______, _______,          _______,                   _______, _______, _______, _______, _______, _______
    // ),
    // Locked+temporary FN (back to base plus extra keys)
    // [_FM] = LAYOUT(
    //     FN_LOCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, KC_MSEL,  KC_INS,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, _______, _______, KC_PAUS, _______, _______, _______,
    //     _______, _______, KC_SYRQ, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, KC_SCRL, _______, _______, _______,          _______,
    //     _______,          _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______,          BL_STEP,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    // ),
};

// // Make sure to keep FN Lock even after reset
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case FN_LOCK:
//             if (record->event.pressed) {
//                 if (layer_state_is(_FN)) {
//                     set_single_persistent_default_layer(_FN_LOCK);
//                 }
//                 if (layer_state_is(_FM)) {
//                     set_single_persistent_default_layer(_BASE);
//                 }
//             }
//             return false;
//             break;
//         default:
//             break;
//     }
//     return true;
// }

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t base_comma_shift_to_semicolon_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON, 1 << _BASE);
const key_override_t base_dot_shift_to_colon_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLON, 1 << _BASE);
const key_override_t num_dot_shift_to_comma_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PDOT, KC_COMMA, 1 << _NUM);
const key_override_t num_ent_shift_to_equal_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PENT, KC_EQL, 1 << _NUM);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &base_comma_shift_to_semicolon_key_override,
    &base_dot_shift_to_colon_key_override,
    &num_dot_shift_to_comma_key_override,
    &num_ent_shift_to_equal_key_override,
    NULL // Null terminate the array of overrides!
};
#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        // Layer debug
        // uint8_t n1 = 15;
        // uint8_t n2 = 13;
        // uint8_t n3 = 12;
        // uint8_t n4 = 11;
        // switch(layer) {
        //     case 1:
        //         rgb_matrix_set_color(n1, RGB_AZURE);
        //         break;
        //     case 2:
        //         rgb_matrix_set_color(n2, RGB_AZURE);
        //         break;
        //     case 3:
        //         rgb_matrix_set_color(n3, RGB_AZURE);
        //         break;
        //     case 4:
        //         rgb_matrix_set_color(n4, RGB_AZURE);
        //         break;
        // }

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_TURQUOISE);
                }
            }
        }
    }
    return false;
}
#endif
