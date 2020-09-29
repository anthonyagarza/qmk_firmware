#include QMK_KEYBOARD_H

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi( /* Base */
        LOCK,   KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL, KC_PGUP,
        KC_F1,    KC_TAB,  KC_Q, KC_W, KC_F,  KC_P,  KC_G, KC_J,  KC_L,  KC_U,  KC_Y,  KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGDOWN,
        KC_F2,    KC_CAPS, KC_A, KC_R,  KC_S,  KC_T,  KC_D, KC_H,  KC_N,  KC_E,  KC_I,  KC_O, KC_QUOT, KC_ENT,
        KC_F3,    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        MO(_FN),    KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, KC_DEL, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_QWERTY] = LAYOUT_ansi( /* Base */
        LOCK,   KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL, KC_PGUP,
        KC_MFFD,    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGDOWN,
        KC_MRWD,    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_MPLY,    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        MO(_FN),    KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, KC_DEL, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT_ansi( /* Base */
        _______,    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, RESET,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,    QWERTY, COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
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
