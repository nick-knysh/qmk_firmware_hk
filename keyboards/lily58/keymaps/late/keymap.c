 /* Copyright 2020 Naoki Katahira
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
#include <stdio.h>
#include "users/holykeebs/holykeebs.h"

#define QK_C_EEPROM QK_CLEAR_EEPROM

//extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _NUM,
  _NAV,
  _LTF,
  _RTJ,
  _SETTINGS
};

#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define LTF MO(_LTF)
#define RTJ MO(_RTJ)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                                ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                                |   6  |   7  |   8  |   9  |   0  |  ~   |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.                ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |                |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|                |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /                 \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /                   \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /                     \      \ |      |      |      |
 *                   `-------------------''-------'                       '------''--------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,       KC_5,                       KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,       KC_T,                       KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    LT(3,KC_F), KC_G,                       KC_H,    LT(4,KC_J),KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,       KC_B, KC_MS_BTN1,   KC_DEL, KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, S(KC_SLSH),
                              KC_LALT, KC_LGUI,  KC_SPC, NUM,              NAV,   KC_BSPC, KC_ENT,  LTF
),
[_NUM] = LAYOUT(
  _______, _______,    _______,    _______, _______, _______,				                      _______, _______, _______, _______, _______, _______,
  _______, S(KC_1),    S(KC_2),    S(KC_3), S(KC_4), S(KC_5),				                      S(KC_6), S(KC_7), S(KC_8), KC_MINS, KC_EQL,  _______,
  _______, KC_1,       KC_2,       KC_3,    KC_4,    KC_5,				                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  _______, S(KC_MINS), S(KC_LBRC), KC_LBRC, S(KC_9), S(KC_BSLS), KC_MS_BTN2,	KC_MS_BTN3, KC_EQL, S(KC_0), KC_RBRC, S(KC_RBRC), KC_BSLS, S(KC_EQL),
		                          KC_LALT, _______, _______, _______,	                  _______, KC_ENT, _______, _______
),
[_NAV] = LAYOUT(
  _______, _______, _______,    _______,    _______,    _______,			                    _______,     _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,
  KC_F11,  KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,                            KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_LCAP, MS_WHLL, _______,    _______,    _______,    MS_WHLR,				                  KC_MS_WH_UP, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MS_WH_DOWN,
  _______, _______, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_Z), _______,	   _______, S(KC_BSLS),  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                    _______, _______, _______, _______,	              _______,    _______,    _______,    _______  
),
[_LTF] = LAYOUT(
  _______, _______, _______, _______, _______, _______,			                	_______,     _______,     _______,     _______,    _______, _______,
  _______, _______, _______, _______, _______, _______,			                	_______,     KC_QUOT,     KC_MINS,     KC_BSLS,    _______, _______,
  _______, _______, _______, _______, _______, _______,			                	S(KC_BSLS),  S(KC_QUOT),  S(KC_MINS),  KC_SLSH,    KC_GRV,  _______,
  _______, _______, _______, _______, _______, _______, _______,	   _______, LCTL(KC_Z),  LCTL(KC_V),  LCTL(KC_C),  LCTL(KC_X), _______,  _______,
                        _______, _______, _______, _______,	              _______,    _______,    _______,    _______
),
[_RTJ] = LAYOUT(
  _______, _______, _______, _______, _______, _______,			                	_______,    _______,    _______,    _______,    _______, _______,
  _______, _______, _______, _______, _______, _______,			                	_______,    _______,    _______,    _______,    _______, _______,
  _______, _______, _______, _______, _______, _______,			                	_______,    _______,    _______,    _______,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______,	   _______, _______,    _______,    _______,    _______,    _______, _______,
                        _______, _______, _______, _______,	              _______,    _______,    _______,    _______
),
[_SETTINGS] = LAYOUT(
  HK_RESET,  HK_DUMP,      HK_SAVE,     XXXXXXX,   XXXXXXX,    XXXXXXX,                         XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  XXXXXXX,   HK_P_SET_BUF, HK_C_SCROLL, XXXXXXX,   XXXXXXX,    QK_BOOT,                         QK_BOOT,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  DT_PRNT,    
  KC_LSFT,   HK_P_SET_S,   HK_S_MODE_T, XXXXXXX,   XXXXXXX,    XXXXXXX,                         XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  DT_UP,      
  XXXXXXX,   HK_P_SET_D,   HK_D_MODE_T, XXXXXXX,   XXXXXXX,    QK_C_EEPROM,  XXXXXXX,  XXXXXXX, QK_C_EEPROM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  DT_DOWN,    
                                             _______, _______, _______, _______,            _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _NUM, _NAV, _SETTINGS);
  return state;
}

