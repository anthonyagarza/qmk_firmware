/* Copyright 2020 Anthony Garza
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _QWERTY,
    _FN
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};


#define LOCK LGUI(LCTL(KC_Q))
#define __ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11, KC_F12,              KC_PSCR, KC_SLCK, KC_PAUS, LOCK,
        KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,      KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL, KC_BSLS, KC_DEL,     KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,  KC_W,  KC_F,  KC_P,  KC_G,             KC_J,  KC_L,  KC_U,  KC_Y,  KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,    KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_CAPS, KC_A,  KC_R,  KC_S,  KC_T,  KC_D,             KC_H,  KC_N,  KC_E,  KC_I,  KC_O,    KC_QUOT, KC_ENT,             KC_P4, KC_P5, KC_P6,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,       MO(_FN), KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),        KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,  KC_LGUI,  KC_BSPC,          KC_SPC,           KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,             KC_P0, KC_P0, KC_PDOT
    ),
    /* Qwerty */
    [_QWERTY] = LAYOUT(
        KC_ESC,         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11, KC_F12,              KC_PSCR, KC_SLCK, KC_PAUS, LOCK,
        KC_GRV,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,      KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL, KC_BSLS, KC_DEL,     KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,             KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,    KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_CAPS, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,             KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT, KC_ENT,             KC_P4, KC_P5, KC_P6,
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,       MO(_FN), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_FN),        KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,  KC_LGUI,  KC_BSPC,          KC_SPC,           KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,             KC_P0, KC_P0, KC_PDOT
    ),
    [_FN] = LAYOUT(
        RESET,  QWERTY, COLEMAK, __, __, __,     __, __, __, __, __,  __, __,            __, __, __, LOCK,
        __,  __,  __,  __,  __,  __,  __,      __,  __,  __,  __,  __, __, __, __,     __, __, __, __,
        __,  __,  __,  __,  __,  __,             __,  __,  __,  __,  __, __, __, __,   __, __, __, __,
        __, __,  __,  __,  __,  __,             __,  __,  __,  __,  __,    __, __,     __, __, __,
        __, __,  __,  __,  __,  __,       __, __, __, __, __, __, __, __,              __, __, __, __,
        __, __, __,  __,  __,          __,           __, __, __, __,                   __, __, __
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
        break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
