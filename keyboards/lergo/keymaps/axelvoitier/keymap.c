// Copyright 2021 Axel Voitier (@Axel Voitier)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    COLEMAK_DH,
    COLEMAK,
    QWERTY,
    MEDIA,
    SYM1,
    NAV,
    NUM,
    SYM2,
    SHORT,
    FUN,
};

enum {
    TD_CTL_MEDIA,
    TD_NUM_PRN
};

bool is_gui_tab_active = false;
uint16_t gui_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [COLEMAK_DH] = LAYOUT_3x5_1x2u_2x1u(
        LGUI_T(KC_Q),        KC_W ,        KC_F ,        KC_P ,        KC_B ,                                                                                  KC_J ,        KC_L ,        KC_U ,        KC_Y ,     KC_COLN ,
               KC_A , LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),        KC_G ,                                                                                  KC_M , RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I),        KC_O ,
               KC_Z ,        KC_X ,        KC_C ,        KC_D ,        KC_V ,                                                                                  KC_K ,        KC_H ,     KC_COMM ,      KC_DOT ,     KC_QUOT ,
                      TD(TD_CTL_MEDIA), KC_BTN3 ,     KC_BTN3 ,               LT(SYM1, KC_SPC), LT(NAV, KC_ESC), LT(SHORT,  KC_DEL), LT(SYM1, KC_ENT),                      KC_NO ,     MO(NAV) ,      MO(FUN),
                                                                                                LT(NUM, KC_TAB), LT( SYM2, KC_BSPC)
    ),
    [COLEMAK] = LAYOUT_3x5_1x2u_2x1u(
        LGUI_T(KC_Q),        KC_W ,        KC_F ,        KC_P ,        KC_G ,                                                                                  KC_J ,        KC_L ,        KC_U ,        KC_Y ,     KC_COLN ,
               KC_A , LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),        KC_D ,                                                                                  KC_H , RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I),        KC_O ,
               KC_Z ,        KC_X ,        KC_C ,        KC_V ,        KC_B ,                                                                                  KC_K ,        KC_M ,     KC_COMM ,      KC_DOT ,     KC_QUOT ,
                      TD(TD_CTL_MEDIA), KC_BTN3 ,     KC_BTN3 ,               LT(SYM1, KC_SPC), LT(NAV, KC_ESC), LT(SHORT,  KC_DEL), LT(SYM1, KC_ENT),                      KC_NO ,     MO(NAV) ,      MO(FUN),
                                                                                                LT(NUM, KC_TAB), LT( SYM2, KC_BSPC)
    ),
    [QWERTY] = LAYOUT_3x5_1x2u_2x1u(
        LGUI_T(KC_Q),        KC_W ,        KC_E ,        KC_R ,        KC_T ,                                                                                  KC_Y ,        KC_U ,        KC_I ,        KC_O ,    RGUI_T(KC_P),
               KC_A , LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),        KC_G ,                                                                                  KC_H , RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L),        KC_SCLN ,
               KC_Z,         KC_X ,        KC_C ,        KC_V ,        KC_B ,                                                                                  KC_N ,        KC_M ,     KC_COMM ,      KC_DOT ,        KC_SLSH ,
                     TD(TD_CTL_MEDIA),  KC_BTN3 ,     KC_BTN3 ,               LT(SYM1, KC_SPC), LT(NAV, KC_ESC), LT(SHORT,  KC_DEL), LT(SYM1, KC_ENT),                      KC_NO ,     MO(NAV) ,      MO(FUN),
                                                                                                LT(NUM, KC_TAB), LT( SYM2, KC_BSPC)
    ),
    [MEDIA] = LAYOUT_3x5_1x2u_2x1u(
        KC_LGUI,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                     RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
          KC_NO, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                                       KC_NO, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                   KC_NO, KC_BTN3, KC_BTN3,            KC_NO,   KC_NO, KC_MUTE, KC_MPLY,            KC_NO,   KC_NO,   KC_NO,
                                                                KC_NO, KC_MSTP

    ),
    [SYM1] = LAYOUT_3x5_1x2u_2x1u(
          KC_GRV, KC_TILD, KC_CIRC, KC_HASH,  KC_DLR,                                     KC_MINS, KC_ASTR, KC_EXLM,    KC_PERC, KC_SCLN,
           KC_LT, KC_LCBR, KC_LBRC, KC_LPRN, KC_PIPE,                                      KC_EQL, KC_RPRN, KC_RBRC,    KC_RCBR,   KC_GT,
        UC(0xB0),   KC_AT, KC_AMPR, KC_UNDS, KC_BSLS,                                     KC_PLUS, KC_SLSH, KC_QUES, UC(0x20AC),  KC_DQT,  // ° .... € ...
                    KC_NO, KC_BTN3, KC_BTN3,            KC_NO,   KC_NO,  KC_DEL,  KC_ENT,            KC_NO,   KC_NO,      KC_NO,
                                                                 KC_NO, KC_BSPC

    ),
    [NAV] = LAYOUT_3x5_1x2u_2x1u(
        KC_LGUI,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                                       KC_NO, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                      KC_INS, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,
                   KC_NO, KC_BTN3, KC_BTN3,            KC_NO,   KC_NO,  KC_DEL,  KC_ENT,            KC_NO,   KC_NO,   KC_NO,
                                                                KC_NO, KC_BSPC

    ),
    [NUM] = LAYOUT_3x5_1x2u_2x1u(
        KC_LGUI, EEP_RST,   KC_NO,   RESET,   KC_NO,                                     KC_PMNS,    KC_7,    KC_8,    KC_9, KC_PSLS,
          KC_NO, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                                      KC_DOT,    KC_4,    KC_5,    KC_6, KC_PEQL,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                     KC_PPLS,    KC_1,    KC_2,    KC_3, KC_PAST,
                   KC_NO, KC_BTN3, KC_BTN3,           KC_SPC,   KC_NO,  KC_DEL,  KC_ENT,            KC_NO,    KC_0, TD(TD_NUM_PRN),
                                                                KC_NO, KC_BSPC

    ),
    [SYM2] = LAYOUT_3x5_1x2u_2x1u(
          UC(0xBA),   UC(0xB9),   UC(0xB2),   UC(0xB3),   UC(0xBD), /* º ¹ ² ³ ½ */        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_RGUI,
        UC(0x0308), UC(0x0302), UC(0x0300), UC(0x0301), UC(0x0327), /* ̈ ̂ ̀ ́ ̧*/        KC_NO, KC_RSFT, KC_RCTL, KC_RALT,   KC_NO,
          UC(0xBE),   UC(0xB1), UC(0x2126),   UC(0xB5),   UC(0xBC), /* ¾ ± Ω µ ¼ */        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                   KC_NO, KC_BTN3, KC_BTN3,           KC_SPC,  KC_ESC,   KC_NO,  KC_ENT,            KC_NO,   KC_NO,   KC_NO,
                                                               KC_TAB, KC_BSPC

    ),
    [SHORT] = LAYOUT_3x5_1x2u_2x1u(
        C(KC_D), C(KC_F), C(KC_W), C(KC_T),    KC_F2 ,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_RGUI,
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), RCS(KC_Z),                                     KC_NO, KC_RSFT, KC_RCTL, KC_RALT,   KC_NO,
          KC_NO,   KC_NO, C(KC_A), C(KC_S), C(KC_N),                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                   KC_NO, KC_BTN3, KC_BTN3,           KC_SPC,  KC_ESC,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,
                                                               KC_TAB,   KC_NO

    ),
    [FUN] = LAYOUT_3x5_1x2u_2x1u(
         KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_SLCK,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
         KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_PSCR,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
         KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                                       KC_NO, DF(COLEMAK_DH), DF(COLEMAK), DF(QWERTY),   KC_NO,
                   KC_NO, KC_BTN3, KC_BTN3,            KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,
                                                                KC_NO,   KC_NO

    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if(layer_state_is(MEDIA)) {
        if(index == 0) {  // Volume
            if(clockwise)
                tap_code(KC_VOLU);
            else
                tap_code(KC_VOLD);
        }else if(index == 1) {  // Track
            if(clockwise)
                tap_code(KC_MNXT);
            else
                tap_code(KC_MPRV);
        }
    }else if(layer_state_is(NAV)) {
        if(index == 0) {  // Words
            if(clockwise)
                tap_code16(C(KC_LEFT));
            else
                tap_code16(C(KC_RGHT));
        }else if(index == 1) {  // Tabs
            if(clockwise)
                tap_code16(C(KC_TAB));
            else
                tap_code16(S(C(KC_TAB)));
        }
    }else if(layer_state_is(SHORT)) {
        if(index == 0) {  // Search results
            if(clockwise)
                tap_code16(S(KC_F3));
            else
                tap_code(KC_F3);
        }else if(index == 1) {  // Windows
            if(clockwise) {
                if(!is_gui_tab_active) {
                    is_gui_tab_active = true;
                    register_code(KC_LGUI);
                }
                gui_tab_timer = timer_read();
                tap_code16(KC_TAB);
            }else{
                if(!is_gui_tab_active) {
                    is_gui_tab_active = true;
                    register_code(KC_LGUI);
                }
                gui_tab_timer = timer_read();
                tap_code16(S(KC_TAB));
            }
        }
    }else{
        if(index == 0) {  // Vertical scrolling
            if(clockwise)
                tap_code(KC_MS_WH_UP);
            else
                tap_code(KC_MS_WH_DOWN);
        }else if(index == 1) {  // Horizontal scrolling
            if(clockwise)
                tap_code(KC_MS_WH_RIGHT);
            else
                tap_code(KC_MS_WH_LEFT);
        }
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        #ifdef ENCODER_ENABLE
        case KC_LEFT:
        case KC_UP:
        case KC_DOWN:
        case KC_RGHT:
            if(is_gui_tab_active)
                gui_tab_timer = timer_read();

            return true;
        #endif

        default:
            return true;
    }
}

void matrix_scan_user(void) {
    #ifdef ENCODER_ENABLE
    if(is_gui_tab_active) {
        if(timer_elapsed(gui_tab_timer) > 1250) {
            unregister_code(KC_LGUI);
            is_gui_tab_active = false;
        }
    }
    #endif
}

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
    // {  10,   0,  11,  19,  20, NO_LED },
    {  9,   1,  12,  18,  21}, // NO_LED },
    {   8,   2,  13,  17,  22}, // NO_LED },
    {   7,   3,  14,  16,  23}, // NO_LED },
    {   6,   4, NO_LED, NO_LED,  15}, // NO_LED },
    {   5, NO_LED, NO_LED, NO_LED, NO_LED}, // NO_LED },
    // {  33,  43,  44,  53,  58, NO_LED },
    {  34,  42,  45,  52,  57}, // NO_LED },
    {  35,  41,  46,  51,  56}, // NO_LED },
    {  36,  40,  47,  50,  55}, // NO_LED },
    {  38,  37, NO_LED,  48, 49}, // NO_LED },
    {  39, NO_LED, NO_LED, NO_LED, NO_LED}, // NO_LED }
}, {
    { 60, 0 }, { 60, 13 }, { 60, 26 }, { 60, 38 }, { 90, 51 }, { 105, 64 }, { 105, 51 },
    { 75, 38 }, { 75, 26 }, { 75, 13 }, { 75, 0 }, { 45, 0 }, { 45, 13 }, { 45, 26 }, { 45, 38 },
    { 30, 51 }, { 30, 38 }, { 30, 26 }, { 30, 13 }, { 30, 0 }, { 15, 0 }, { 15, 13 }, { 15, 26 }, { 15, 38 },
    { 112, 32 }, { 112, 32 }, { 112, 32 }, { 112, 32 }, { 112, 32 }, { 112, 32 }, { 112, 32 }, { 112, 32 }, { 112, 32 },

    { 150, 0 }, { 150, 13 }, { 150, 26 }, { 150, 39 }, { 135, 51 }, { 120, 51 }, { 120, 64 },
    { 165, 39 }, { 165, 26 }, { 165, 13 }, { 165, 0 }, { 180, 0 }, { 180, 13 }, { 180, 26 }, { 180, 39 },
    { 180, 51 }, { 195, 51 }, { 195, 39 }, { 195, 26 }, { 195, 13 }, { 195, 0 }, { 210, 0 },
    { 210, 13 }, { 210, 26 }, { 210, 39 }, { 210, 51 },
    { 225, 39 }, { 210, 13 }, { 180, 0 }, { 150, 7 }, { 128, 58 }, { 165, 39 }, { 195, 51 }
}, {
    0, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 0, 0, 4, 4, 4,
    4, 4, 4, 4, 0, 0, 4, 4, 4,
    0, 0, 0, 0, 0, 0, 0, 0, 0,

    0, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 0, 0, 4, 4, 4,
    4, 4, 4, 4, 4, 0, 8,
    4, 4, 4, 0,
    2, 2, 2, 2, 2, 2, 2
} };

#endif


#ifdef OLED_ENABLE

typedef struct {
    uint16_t layer_state;
    // led_t led_state;
    uint8_t mod_state;
    uint8_t os_mod_state;
} oled_states_t;

static oled_states_t oled_states = {
    .layer_state = 0xFFFF,
    .mod_state = 0,
    .os_mod_state = 0
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    bool diff = false;
    if(layer_state != oled_states.layer_state) {
        diff = true;
        oled_states.layer_state = layer_state;
    }
    if(get_mods() != oled_states.mod_state) {
        diff = true;
        oled_states.mod_state = get_mods();
    }
    if(get_oneshot_mods() != oled_states.os_mod_state) {
        diff = true;
        oled_states.os_mod_state = get_oneshot_mods();
    }
    if(!diff)
        return false;

    oled_clear();

    switch (get_highest_layer(layer_state)) {
        // case COLEMAK_DH:
        //     oled_write_P(PSTR("COLEMAK DH\n"), false);
        //     break;
        // case COLEMAK:
        //     oled_write_P(PSTR("COLEMAK\n"), false);
        //     break;
        // case QWERTY:
        //     oled_write_P(PSTR("QWERTY\n"), false);
        //     break;
        case MEDIA:
            oled_write_P(PSTR("MEDIA\n"), false);
            break;
        case SYM1:
            oled_write_P(PSTR("SYM1\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case NUM:
            oled_write_P(PSTR("NUM\n"), false);
            break;
        case SYM2:
            oled_write_P(PSTR("SYM2\n"), false);
            break;
        case SHORT:
            oled_write_P(PSTR("SHORT\n"), false);
            break;
        case FUN:
            oled_write_P(PSTR("FUN\n"), false);
            break;

        default:
            if(IS_LAYER_ON_STATE(default_layer_state, COLEMAK))
                oled_write_P(PSTR("COLEMAK\n"), false);
            else if(IS_LAYER_ON_STATE(default_layer_state, QWERTY))
                oled_write_P(PSTR("QWERTY\n"), false);
    }

    // // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // if(led_state.num_lock)
    //     oled_write_P(PSTR("NUM\n"), false);
    // if(led_state.caps_lock)
    //     oled_write_P(PSTR("CAP\n"), false);
    // if(led_state.scroll_lock)
    //     oled_write_P(PSTR("SCR\n"), false);

    uint8_t mod_state = get_mods();
    uint8_t os_mod_state = get_oneshot_mods();

    if(mod_state & MOD_MASK_SHIFT)
        oled_write_P(PSTR("SHIFT\n"), false);
    else if(os_mod_state & MOD_MASK_SHIFT)
        oled_write_P(PSTR("SHIFT*\n"), false);
    else
        oled_write_P(PSTR("\n"), false);

    if(mod_state & MOD_MASK_CTRL)
        oled_write_P(PSTR("CTRL\n"), false);
    else if(os_mod_state & MOD_MASK_CTRL)
        oled_write_P(PSTR("CTRL*\n"), false);
    else
        oled_write_P(PSTR("\n"), false);

    if(mod_state & MOD_MASK_ALT)
        oled_write_P(PSTR("ALT\n"), false);
    else if(os_mod_state & MOD_MASK_ALT)
        oled_write_P(PSTR("ALT*\n"), false);
    else
        oled_write_P(PSTR("\n"), false);

    if(mod_state & MOD_MASK_GUI)
        oled_write_P(PSTR("GUI\n"), false);
    else if(os_mod_state & MOD_MASK_GUI)
        oled_write_P(PSTR("GUI*\n"), false);
    else
        oled_write_P(PSTR("\n"), false);

    return false;
}
#endif

#ifdef TAP_DANCE_ENABLE

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

void dance_ctl_finished(qk_tap_dance_state_t *state, void *user_data) {xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LCTL)); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_HOLD: layer_on(MEDIA); break;
        default:
            break;
    }
    // if (state->count == 1) {
    //     set_oneshot_mods(MOD_LCTL);
    // } else {
    //     layer_on(MEDIA);
    // }
}

void dance_ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_HOLD: layer_off(MEDIA); break;
        default:
            break;
    }
    xtap_state.state = TD_NONE;
    // if (state->count == 1) {
    //     clear_oneshot_mods();
    // } else {
    //     layer_off(MEDIA);
    // }
}

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CTL_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ctl_finished, dance_ctl_reset),
    [TD_NUM_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN)
};
#endif
