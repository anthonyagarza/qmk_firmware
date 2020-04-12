/* Copyright 2017 MechMerlin
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

#define _QWERTY 0
#define _COLEMAK 1
#define _GAMER 2
#define _FN 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAMER
};

#define GUITAB LGUI_T(KC_TAB)
#define FNCAPS LT(_FN, KC_CAPS)
#define LOCK LGUI(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_all(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_PSCR, KC_SLCK, LOCK, \
      KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_INS,  KC_HOME, KC_PGUP, \
      GUITAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL,  KC_END,  KC_PGDN, \
      KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
      KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FN),                   KC_UP, \
      KC_LCTL, KC_LGUI, KC_LALT,                 KC_SPC,                           KC_RALT, KC_RGUI, MO(_FN),   KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RGHT),

    [_COLEMAK] = LAYOUT_all(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_PSCR, KC_SLCK, LOCK, \
      KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_INS,  KC_HOME, KC_PGUP, \
      GUITAB,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_G,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL,  KC_END,  KC_PGDN, \
      KC_CAPS, KC_A,    KC_R,    KC_S,   KC_T,   KC_D,   KC_H,   KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, KC_ENT, \
      KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  MO(_FN),                   KC_UP, \
      KC_LCTL, KC_LGUI, KC_LALT,                 KC_SPC,                           KC_RALT, KC_RGUI, MO(_FN),   KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RGHT),

    [_GAMER] = LAYOUT_all(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_PSCR, KC_SLCK, LOCK, \
      KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_INS,  KC_HOME, KC_PGUP, \
      KC_TAB,  KC_Q,    KC_W,    KC_F,   KC_P,   KC_G,   KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,          KC_DEL,  KC_END,  KC_PGDN, \
      KC_CAPS, KC_A,    KC_R,    KC_S,   KC_T,   KC_D,   KC_H,   KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, KC_ENT, \
      KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  MO(_FN),                   KC_UP, \
      KC_LCTL, KC_LGUI, KC_LALT,                 KC_SPC,                           KC_RALT, KC_LGUI, KC_LGUI,   KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RGHT),

     [_FN] = LAYOUT_all(
      RESET,    QWERTY, COLEMAK, GAMER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG,                    KC_TRNS, KC_TRNS, QWERTY, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, RESET,      KC_TRNS, KC_TRNS, COLEMAK, \
      KC_TRNS, BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS),
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
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case GAMER:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMER);
      }
      return false;
      break;
  }
  return true;
}
