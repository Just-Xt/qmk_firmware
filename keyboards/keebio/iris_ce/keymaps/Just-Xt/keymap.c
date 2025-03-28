// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap.h"

#include "customrgb.c"
#include "chordal.c"

#ifdef COMBO_ENABLE
   #include "combo.c"
#endif

enum custom_layers {
     _MAIN,
     _LOWER,
     _RAISE,
     _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     KC_ESCAPE, KC_1,  LT(0, KC_2),KC_3,     KC_4,     KC_5,                                  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
  //├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     LT(0, KC_LBRC),
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_LCTL,  HRM_A,    HRM_S,    HRM_D,    HRM_F,    KC_G,                                  KC_H,     HRM_J,    HRM_K,    HRM_L,    HRM_SCLN,  KC_QUOT,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     KC_LSFT,  KC_Z,  LT(0, KC_X),LT(0, KC_C),LT(0, KC_V),KC_B,  KC_BSPC,           RGB_TOG,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_F13,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                       KC_LGUI,  TL_LOWR,  KC_SPC,                       KC_BSPC,  TL_UPPR,  KC_ENT
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_NO,    KC_NO,    KC_HOME,  KC_UP,    KC_END,   AMPER,                                 PIPE,    KC_KP_SLASH, BSLASH, KC_GRAVE, HSHTG,    KC_NO,
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     _______,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_MINUS,                              UNDRSC,   KC_LPRN,  KC_RPRN,  LCRLBRC,  RCRLBRC,  KC_NO,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_KP_PLUS, _______,         _______,  KC_EQUAL, LSQRBRC,  RSQRBRC,  LTHAN,    GTHAN,    _______,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                       _______, _______, _______,                        _______,  _______, _______
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                 KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  
  //├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     RGB_TOG,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PSCR,
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     RGB_RMOD, RGB_VAD,  KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     RGB_MOD,  RGB_VAI,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    _______,           _______,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                        _______, _______, _______,                        _______,  _______, _______
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_SLEP,
  //├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_NO,    KC_NO,    KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_NO,                                 KC_NO,    KC_BTN4,  KC_BTN5,  KC_NO,    KC_NO,    KC_NO,
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_NO,    KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,                                 KC_NO,    KC_BTN1,  KC_BTN2,  KC_NO,    KC_NO,    KC_NO,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     CM_TOGG,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    _______,            _______, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                        _______, _______, _______,                        _______,  _______, _______
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case LT(0, KC_LBRC):
            if (record->tap.count && record->event.pressed) { // Tap
               return true;
               break;
            } 
            else if (record->event.pressed) { // Hold
               tap_code16(KC_RBRC);
               return false;
            }
            return true;
            
         case LT(0, KC_2):
            if (record->tap.count && record->event.pressed) { // Tap
               return true;
               break;
            } 
            else if (record->event.pressed) { // Hold
               tap_code16(RALT(KC_2));
               return false;
            }
            return true;
            
         case LT(0, KC_Z):
            if (record->tap.count && record->event.pressed) { // Tap
               return true;
               break;
            } 
            else if (record->event.pressed) { // Hold
               tap_code16(RCTL(KC_Z));
               return false;
            }
            return true;
            
         case LT(0, KC_X):
            if (record->tap.count && record->event.pressed) { // Tap
               return true;
               break;
            } 
            else if (record->event.pressed) { // Hold
               tap_code16(RCTL(KC_X));
               return false;
            }
            return true;
            
         case LT(0, KC_C):
            if (record->tap.count && record->event.pressed) { // Tap
               return true;
               break;
            } 
            else if (record->event.pressed) { // Hold
               tap_code16(RCTL(KC_C));
               return false;
            }
            return true;
            
         case LT(0, KC_V):
            if (record->tap.count && record->event.pressed) { // Tap
               return true;
               break;
            } 
            else if (record->event.pressed) { // Hold
               tap_code16(RCTL(KC_V));
               return false;
            }
            return true;
    }
    return true;
}