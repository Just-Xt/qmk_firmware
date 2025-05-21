#pragma once
#include QMK_KEYBOARD_H

// CA-FR shortcuts
#define AMPER LSFT(KC_7)
#define PIPE LSFT(KC_GRAVE)
#define UNDRSC LSFT(KC_MINUS)
#define BSLASH RALT(KC_GRAVE)
#define HSHTG RALT(KC_SCLN)

#define LCRLBRC RALT(KC_QUOTE)
#define RCRLBRC RALT(KC_BSLS)
#define LSQRBRC RALT(KC_LBRC)
#define RSQRBRC RALT(KC_RBRC)
#define LTHAN KC_BSLS
#define GTHAN LSFT(KC_BSLS)

// Home row mods
#define HRM_A LGUI_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LSFT_T(KC_F)

#define HRM_J RSFT_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)

// Numbers + shifted symbols on hold
#define H_1 LT(0, KC_1)
#define H_2 LT(0, KC_2)
#define H_4 LT(0, KC_4)
#define H_5 LT(0, KC_5)
#define H_6 LT(0, KC_6)
#define H_8 LT(0, KC_8)

// Cut Copy Paste
#define H_X LT(0, KC_X)
#define H_C LT(0, KC_C)
#define H_V LT(0, KC_V)
