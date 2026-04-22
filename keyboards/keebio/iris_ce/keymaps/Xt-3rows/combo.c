#include QMK_KEYBOARD_H

#undef COMBO_TERM
#define COMBO_TERM 20

// G H
const uint16_t PROGMEM caps_lock[] = {KC_G, KC_H, COMBO_END};

// F J
const uint16_t PROGMEM caps_word[] = {HRM_F, HRM_J, COMBO_END};

// D K
const uint16_t PROGMEM osm_shift[] = {HRM_D, HRM_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(caps_lock, KC_CAPS),
    COMBO(caps_word, QK_CAPS_WORD_TOGGLE),
    COMBO(osm_shift, OSM(MOD_LSFT)),
};