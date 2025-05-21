#include QMK_KEYBOARD_H

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',             'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',             'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',             'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', 'R', 'R', 
                          'L', 'L', 'L',       'R', 'R', 'R'
    );
    
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
   
   // Handle one-handed chords
    switch (tap_hold_keycode) {
        case HRM_K:
            if (other_keycode == KC_BSPC) {
                return true;
            }
            break;
    }
    
    // Defer to the opposite hands rule
    return get_chordal_hold_default(tap_hold_record, other_record);
}