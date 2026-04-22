/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HSV 212, 255, 80


// Tap Hold settings (https://docs.qmk.fm/tap_hold)

// Disables hold during fast typing; triggers tap if pressed within this time of previous key
#define FLOW_TAP_TERM 150

// Settles as tap when keys pressed on same hand; uses hold rules for opposite hand chords
#define CHORDAL_HOLD

// Immediately settles as hold when another key is pressed (before tapping term expires)
// #define HOLD_ON_OTHER_KEY_PRESS

// Settles as hold when another key is tapped (pressed and released) within tapping term
// #define PERMISSIVE_HOLD
