#include QMK_KEYBOARD_H

// DFJK to enable Caps Lock
const uint16_t PROGMEM dfjk_caps[] = {HRM_D, HRM_F, HRM_J, HRM_K, COMBO_END};

// GH to enable Caps Word
const uint16_t PROGMEM gh_caps_word[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    COMBO(dfjk_caps, KC_CAPS),
    COMBO(gh_caps_word, QK_CAPS_WORD_TOGGLE),
};