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
     KC_DEL,   KC_Z,     H_X,      H_C,      H_V,      KC_B,     KC_BSPC,           UG_TOGG,  KC_N,     KC_M,  LT(0, KC_COMM), KC_DOT,  KC_SLSH,    KC_NO,
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
     KC_NO,    KC_1,   LT(0, KC_2), KC_3,     KC_4,     KC_5,                                  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_PSCR,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     KC_NO,   LSFT(KC_1),LSFT(KC_2), KC_NO,  LSFT(KC_4), LSFT(KC_5),  KC_NO,        KC_NO,   LSFT(KC_6), KC_NO,  LSFT(KC_8), KC_DOT,   KC_NO,    KC_F13,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                        _______, _______, _______,                        _______,  _______, _______
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  ),

  [_ADJUST] = LAYOUT(
     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                 KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
     
  //┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                            ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
     QK_BOOT,  KC_NO,    MS_WHLU,  MS_UP,    MS_WHLD,  KC_NO,                                 KC_NO,    MS_BTN4,  MS_BTN5,  KC_NO,    KC_NO,    KC_SLEP,
  //├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                            ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
     EE_CLR,    KC_NO,    MS_LEFT,  MS_DOWN,  MS_RGHT,  KC_NO,                                 KC_NO,    MS_BTN1,  MS_BTN2,  KC_NO,    KC_NO,    KC_NO,
  //├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐        ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
     CM_TOGG,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    _______,            _______, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘        └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-───────┴────-────┴──-──────┘
                                        _______, _______, _______,                        _______,  _______, _______
                                   // └─────-───┴───-─────┴─────-───┘                   └──────-──┴───-─────┴─────-───┘
  )
};

void keyboard_post_init_user(void) {
    rgb_matrix_sethsv(212, 255, 80);
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
}

bool override_hold(uint16_t hold_keycode, keyrecord_t *record) {
   if (!record->tap.count && record->event.pressed) {
      tap_code16(hold_keycode);
      return false;
   }
   return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      // Cut on hold
      case H_X:
         return override_hold(RCTL(KC_X), record);
         
      // Copy on hold
      case H_C:
         return override_hold(RCTL(KC_C), record);
      
      // Paste on hold
      case H_V:
         return override_hold(RCTL(KC_V), record);
         
      // ^ on tap 
      // ¸ on hold
      case LT(0, KC_LBRC):
         return override_hold(KC_RBRC, record);
         
      // , on tap
      // ' on hold
      case LT(0, KC_COMM):
         return override_hold(LSFT(KC_COMM), record);
         
      // 2 on tap
      // @ on hold
      case LT(0, KC_2):
         return override_hold(RALT(KC_2), record);
         
    }
    return true;
}

bool is_flow_tap_key(uint16_t keycode) {
    // Disable Flow Tap on shift keys
    if (keycode == HRM_F || keycode == HRM_J) {
        return false;
    }
    
    // Keep default behavior for alpha keys
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

