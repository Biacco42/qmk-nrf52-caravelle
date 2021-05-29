/*
Copyright 2019 Sekigon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"
#include <stdio.h>

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
};


extern keymap_config_t keymap_config;

enum {
  _QWERTY,
  _META,
  _SYMB,
  _BIACCO,
  _BMETA,
  _BSYMB,
  _ADJUST
};

// Layer Key 
#define BIACCO  TG(_BIACCO)
#define ADJUST  MO(_ADJUST)
#define ESCSYM  LT(_SYMB, KC_ESC)
#define ENTMET  LT(_META, KC_ENT)
#define ESCBSYM LT(_BSYMB, KC_ESC)
#define ENTBMET LT(_BMETA, KC_ENT)

// Combination Key
#define SPCCTL  RCTL_T(KC_SPC)
#define TABSFT  SFT_T(KC_TAB)
#define ROSFT   SFT_T(KC_RO)

// Shorthand
#define S_MINS  S(KC_MINS)
#define S_EQL   S(KC_EQL)
#define S_JYEN  S(KC_JYEN)
#define S_RBRC  S(KC_RBRC)
#define S_BSLS  S(KC_BSLS)
#define S_COMM  S(KC_COMM)
#define S_DOT   S(KC_DOT)
#define S_SLSH  S(KC_SLSH)
#define S_RO    S(KC_RO)
#define S_SCLN  S(KC_SCLN)
#define S_QUOT  S(KC_QUOT)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCTL,        KC_LCTL, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,        KC_JYEN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ROSFT,   \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               ADJUST,  ESCSYM,  SPCCTL,  TABSFT,         KC_BSPC, ENTMET,  KC_DEL,  BIACCO \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_META] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F1,   XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, _______,        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_SYMB] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6),                          S(KC_7), S(KC_8), S(KC_9), S(KC_0), S_MINS,  S_EQL,   \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        _______, XXXXXXX, XXXXXXX, KC_RBRC, KC_BSLS, S_SCLN,  S_QUOT,  \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        S_JYEN,  S_RBRC,  S_BSLS,  S_COMM,  S_DOT,   S_SLSH,  S_RO,    \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_BIACCO] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Q,                             KC_Y,    KC_G,    KC_D,    KC_M,    KC_F,    KC_LBRC, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    KC_LALT, KC_A,    KC_O,    KC_E,    KC_I,    KC_U,    KC_LCTL,        KC_LCTL, KC_B,    KC_N,    KC_T,    KC_R,    KC_S,    KC_QUOT, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_W,    KC_LGUI,        KC_JYEN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SLSH, ROSFT,   \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               ADJUST,  ESCBSYM, SPCCTL,  TABSFT,         KC_BSPC, ENTBMET, KC_DEL,  _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_BMETA] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    _______,        _______, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, KC_1,    XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, _______,        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, ROSFT,   \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_BSYMB] = LAYOUT(
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, KC_RBRC, KC_BSLS, S_SCLN,  S_QUOT,  \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), _______,        _______, S(KC_7), S(KC_8), S(KC_9), S(KC_0), S_MINS,  S_EQL,   \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, S(KC_1), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        S_JYEN,  S_RBRC,  S_BSLS,  S_COMM,  S_DOT,   S_SLSH,  S_RO,    \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  ),

  [_ADJUST] = LAYOUT ( \
 //+--------+--------+--------+--------+--------+--------+                        +--------+--------+--------+--------+--------+--------+
    _______, AD_WO_L, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+--------|
    _______, DELBNDS, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
    _______, BATT_LV, ENT_SLP, ENT_DFU, RESET,   XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                               _______, _______, _______, _______,        _______, _______, _______, _______ \
 //                           +--------+--------+--------+--------+      +--------+--------+--------+--------+
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
}
;
