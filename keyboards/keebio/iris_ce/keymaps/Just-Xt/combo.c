#include QMK_KEYBOARD_H

const uint16_t PROGMEM dfjk_caps[] = {HRM_D, HRM_F, HRM_J, HRM_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(dfjk_caps, KC_CAPS),
};