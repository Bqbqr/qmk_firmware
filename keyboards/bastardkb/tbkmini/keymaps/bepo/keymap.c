/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
#include "keymap_bepo.h"


enum layers {
  _BEPO,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMBER,
  _SIGNS,
  _GAMING
};

// Custom keycodes for layer keys
#define KC_LGESC LGUI_T(KC_ESC)
#define KC_SFTAB LSFT_T(KC_TAB)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST,
  KC_RACL, // right alt / colon
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BEPO] = LAYOUT_split_3x6_3(

// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    BP_W,    BP_B,    BP_ECUT, BP_P,    BP_O,    BP_EGRV,                      BP_DCIR, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_SFTAB,BP_A,    BP_U,    BP_I, LT(4,BP_E), BP_COMM,                      BP_C,  LT(5,BP_T),    BP_S,    BP_R,    BP_N,    BP_M,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                         BP_QUOT, BP_Q,    BP_G,    BP_H,    BP_F,    RSFT_T(BP_CCED),
// |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            KC_LGUI,LT(1, KC_SPC), LALT_T(KC_ENT),    KC_ENT, LT(2, KC_BSPC),KC_RACL 
                                     //`--------+--------+--------'  `--------+--------+--------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,---------------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1, KC_2,   KC_3,   KC_4,   KC_5,                    KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_DEL,
  //|------+------+-------+-------+-------+-------|                |------+------+------+------+------+------|
    KC_LSFT, KC_NO, KC_NO, LCTL(BP_Y),LCTL(BP_Z),KC_NO,             KC_NO, KC_MS_WH_UP,  KC_UP, KC_MS_WH_DOWN,KC_PGUP,KC_NO,
  //|------+------+-------+-------+-------+-------|                |------+------+------+------+------+------|
    KC_LCTL, KC_NO, KC_NO, LCTL(BP_X),LCTL(BP_C),LCTL(BP_V),        KC_HOME,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,KC_NO,
  //|------+------+-------+-------+-------+-------+------|  |------+------+------+------+------+------+------|
                                    KC_LGUI, LOWER,KC_SPC,   KC_ENT, RAISE,KC_LALT
                                  //`--------------------'  `--------------------'
 ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_MINS,KC_EQL,KC_LCBR,KC_RCBR,KC_PIPE,KC_GRV,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL, KC_F6, KC_F7, KC_F8, KC_F9,KC_F12,                KC_UNDS,KC_PLUS,KC_LBRC,KC_RBRC,KC_BSLS,KC_TILD,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_SPC,   KC_ENT, RAISE,KC_LALT
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET,RGBRST, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_MPRV,KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_NO,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_NO,KC_NO,KC_NO,KC_NO,KC_PSCREEN,KC_NO,               KC_AUDIO_MUTE,KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    TG(6),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,               KC_SCROLLLOCK,KC_VOLD, KC_NO, KC_NO, KC_NO, RGB_RMOD,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_SPC,   KC_ENT, RAISE,KC_RALT
                              //`--------------------'  `--------------------'
  ),

  [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------.                ,-----------------------------------------.
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  BP_EURO, BP_7, BP_8, BP_9, BP_SLSH, KC_BSPC,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_NO,  KC_NO, BP_DOT, BP_DLR, KC_NO, KC_NO,                 BP_HASH, BP_4, BP_5, BP_6, BP_ASTR, BP_EQL,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  BP_PERC, BP_1, BP_2, BP_3, BP_MINS, KC_ENT,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER, KC_SPC,   KC_ENT, BP_PLUS, BP_0
                              //`--------------------'  `--------------------'
  ),

  [_SIGNS] = LAYOUT_split_3x6_3(
    // ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN,                      BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, BP_AMPR, BP_LESS, BP_GRTR, BP_LBRC, BP_RBRC,                      KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BP_PERC,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, BP_PIPE, BP_BSLS, BP_SLSH, BP_LCBR, BP_RCBR,                      KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
// |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                              KC_NO, BP_UNDS,KC_NO,   KC_NO, KC_NO, KC_NO
                                             //`--------------------'  `--------------------'
  ),
  [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------.                ,---------------------------------------------.
    BP_W,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                  KC_Y, BP_V ,KC_I,  KC_O,  KC_P, BP_Z,
  //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
    KC_TAB,  KC_A,  KC_S,  KC_D, KC_F,  KC_G,                 BP_C,  BP_T,  KC_K,  KC_L, KC_SCLN, KC_QUOT,
  //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
    KC_LSFT,  KC_Z,  BP_Y,  KC_C,  KC_V,  KC_B,                KC_N,  KC_M,KC_COMM,BP_H,BP_F, RSFT_T(BP_CCED),
  //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
                        KC_LCTL,KC_SPC, LALT_T(KC_ENT),            TG(6), KC_BSPC, KC_ESC
                             //`--------------------'  `--------------------'
  )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t my_colon_timer;

  switch (keycode) {
    case KC_RACL:
        if (record->event.pressed) {
          my_colon_timer = timer_read();
          register_code(KC_RALT);
        } else {
          unregister_code(KC_RALT);
          if (timer_elapsed(my_colon_timer) < TAPPING_TERM) {
            register_code(KC_ESC); // Change the character(s) to be sent on tap here
            unregister_code(KC_ESC); // Change the character(s) to be sent on tap here
          }
        }
        return false;
      break;
  }
  return true;
}