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
     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
     
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     KC_ESCAPE,KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     LT(0, KC_LBRC),
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_TAB,   HRM_A,    HRM_S,    HRM_D,    HRM_F,    KC_G,                                  KC_H,     HRM_J,    HRM_K,    HRM_L,    HRM_SCLN, KC_QUOT,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     KC_DEL,    KC_Z,     H_X,      H_C,      H_V,      KC_B,     KC_BSPC,           RGB_TOG,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                       KC_F20,   TL_LOWR,  KC_SPC,                       KC_BSPC,  TL_UPPR,  KC_ENT
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  ),

  [_LOWER] = LAYOUT(
     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
     
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
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
     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
     
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                 KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_NO,    KC_1,     H_2,      KC_3,     KC_4,     KC_5,                                  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_PSCR,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     KC_NO,   LSFT(KC_1),LSFT(KC_2), KC_NO,  LSFT(KC_4), LSFT(KC_5),  KC_NO,        KC_NO,   LSFT(KC_6), KC_NO,  LSFT(KC_8), KC_DOT,   KC_NO,    KC_F13,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                        _______, _______, _______,                        _______,  _______, _______
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  ),

  [_ADJUST] = LAYOUT(
     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
     
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     QK_BOOT,  KC_NO,    KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_NO,                                 KC_NO,    KC_BTN4,  KC_BTN5,  KC_NO,    KC_NO,    KC_SLEP,
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     KC_NO,    KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,                                 KC_NO,    KC_BTN1,  KC_BTN2,  KC_NO,    KC_NO,    KC_NO,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     CM_TOGG,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    _______,            _______, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                        _______, _______, _______,                        _______,  _______, _______
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  )
};

bool override_hold(uint16_t hold_keycode, keyrecord_t *record) {
   if (!record->tap.count && record->event.pressed) {
      tap_code16(hold_keycode);
      return false;
   }
   return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case LT(0, KC_LBRC):
         return override_hold(KC_RBRC, record);
      
      // Numbers + shifted symbols on hold
      // 1 and !
      case LT(0, KC_1):
         return override_hold(LSFT(KC_1), record); 
         
      // 2 and @
      case LT(0, KC_2):
         return override_hold(RALT(KC_2), record);
         
      // 4 and $
      case LT(0, KC_4):
         return override_hold(LSFT(KC_4), record);
         
      // 5 and %
      case LT(0, KC_5):
         return override_hold(LSFT(KC_5), record);
         
      // 6 and ?
      case LT(0, KC_6):
         return override_hold(LSFT(KC_6), record);
         
      // 8 and *
      case LT(0, KC_8):
         return override_hold(LSFT(KC_8), record);
         
         
      // Cut
      case LT(0, KC_X):
         return override_hold(RCTL(KC_X), record);
         
      // Copy   
      case LT(0, KC_C):
         return override_hold(RCTL(KC_C), record);
      
      // Paste   
      case LT(0, KC_V):
         return override_hold(RCTL(KC_V), record);
    }
    return true;
}