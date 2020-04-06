#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _RAISE 2
#define _NAV 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

#define FNESC LT(_RAISE, KC_ESC)
#define FNQUOT LT(_RAISE, KC_QUOT)
#define LOCK LGUI(LCTL(KC_Q))
#define CMDENT LGUI_T(KC_ENT)
#define CMDBSP LGUI_T(KC_BSPC)
#define GUITAB LGUI_T(KC_TAB)
#define NAVTAB LT(_NAV, KC_TAB)
#define WKLEFT LCTL(KC_LEFT)
#define WKRIGHT LCTL(KC_RIGHT)
#define MISSION LCTL(KC_UP)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  -   |           |  =   |   6  |   7  |   8  |   9  |   0  |  Bsp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | PgUp |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| PgDn |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  |M2/Shift|
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | Ctrl |  Gui |  Alt |                                                                   | Left |  Down| Right |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |  Ins |       | Home |        |
 *                                        | Space|------|       |------|M1/Space|
 *                                        |      |  Del |       | End  |        |
 *                                        `-------------'       `---------------'
 */
    [_QWERTY] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_CAPS,      LOCK,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS,
  NAVTAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_EQL,      KC_LBRC, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
  FNESC,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, FNQUOT,
  KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_PGDN,      KC_PPLS, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI,KC_LALT,                                                                       KC_LEFT,MISSION, KC_RIGHT,
                                            GUITAB, KC_BSPC,      KC_SPC,  KC_ENT, 
                                           KC_NO , KC_DEL,       KC_END,  KC_NO
    ),

/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  -   |           |  =   |   6  |   7  |   8  |   9  |   0  |  Bsp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  | PgUp |           |  [   |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  | Enter  |
 * |--------+------+------+------+------+------| PgDn |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |  /   |M2/Shift|
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | Ctrl |  Gui |  Alt |                                                                   | Left |  Down| Right |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |  Ins |       | Home |        |
 *                                        | Space|------|       |------|M1/Space|
 *                                        |      |  Del |       | End  |        |
 *                                        `-------------'       `---------------'
 */
[_COLEMAK] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_CAPS,      LOCK,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS,
  NAVTAB,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_EQL,       KC_PPLS, KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN, KC_BSLS,
  FNESC,   KC_A,   KC_R,   KC_S,   KC_T,   KC_D,                          KC_H,   KC_N,   KC_E,   KC_I,   KC_O,    FNQUOT,
  KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_PGDN,      KC_RBRC, KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI,KC_LALT,                                                                       KC_LEFT,MISSION, KC_RIGHT,
                                           GUITAB, KC_BSPC,      KC_SPC,  KC_ENT,
                                           KC_NO , KC_DEL,       KC_END,  KC_NO
    ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |  F12 |  F6  |  F7  |  F8  |  F9  | F10  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |   '    |
 * |--------+------+------+------+------+------|      |           |  M3  |------+------+------+------+------+--------|
 * |        | Mute | Vol- | Vol+ |      |      |      |           |      |      |      |      |      |   /  |        |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |      |                                                                   |      |      |       |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                        |      |------|       |------|        |
 *                                        |      |      |       |      |        |
 *                                        `-------------'       `---------------'
 */
    [_RAISE] = LAYOUT(
  KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,     KC_F12,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,
  _______,  KC_EXLM,  KC_AT,  KC_LCBR,  KC_RCBR,    KC_PIPE,  KC_VOLU,      KC_BRMU, _______,  KC_KP_7 ,KC_KP_8 ,KC_KP_9,  _______,  _______,
  _______,  KC_HASH,  KC_DLR,  KC_LPRN,  KC_RPRN,   KC_TILD,                         _______,  KC_KP_4 ,KC_KP_5 ,KC_KP_6 , KC_PPLS,  _______,
  _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  _______,  KC_VOLD,    KC_BRMD,   _______,  KC_KP_1 ,KC_KP_2 ,KC_KP_3 , KC_KP_0,  _______,
  QWERTY,  COLEMAK,  _______,                                                                                   WKLEFT,   MISSION,  WKRIGHT,
                                                    _______,  _______,    _______,  KC_KP_0,
                                                    _______,  _______,    _______,  _______
    ),
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | Calc |NumLoc|   /  |   *  |    -   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |   7  |   8  |   9  |    +   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |   4  |   5  |   6  |    =   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |   1  |   2  |   3  |  Enter |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   |      |      |      |                                                                   |   0  |   .  | Enter|
 *   `--------------------'                                                                   `--------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                        |      |------|       |------|        |
 *                                        |      |      |       |      |        |
 *                                        `-------------'       `---------------'
 */
    [_NAV] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______, _______,  _______,  _______,  _______, _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,                        _______,  KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,                                                                                   _______,  _______,  _______,
                                                    _______,  _______,    _______,  _______,
                                                    _______,  _______,    _______,  _______
    ),
};

void matrix_scan_user(void) {

}

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
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

}
