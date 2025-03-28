#include QMK_KEYBOARD_H

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const bool caps_lock = host_keyboard_led_state().caps_lock;
    const uint8_t layer = get_highest_layer(layer_state);
    HSV matrix_hsv = rgb_matrix_get_hsv();
    
   if (!caps_lock && !layer)
      return false;

   for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
         const uint8_t index = g_led_config.matrix_co[row][col];

         if (index < led_min || index >= led_max)
               continue;

         HSV hsv;
         hsv.s = 255;
         hsv.v = matrix_hsv.v;

         uint16_t kc = layer 
            ? keymap_key_to_keycode(layer, (keypos_t){col,row}) 
            : -1; // Leave at -1 because 0 is KC_NO!
            
         switch (kc) {
            case QK_BOOT:
               hsv.h = 0;
               break;
               
            case KC_RIGHT ... KC_UP:
               hsv.h = 135;
               break;
               
            case KC_HOME ... KC_END:
               hsv.h = 160;
               break;
               
            case KC_MS_U ... KC_WH_R:
               hsv.h = 222;
               break;
               
            case KC_F1 ... KC_F12:
               hsv.h = 148;
               break;
               
            case KC_F13 ... KC_F24:
               hsv.h = 85;
               break;
               
            case KC_NO:
               hsv.v = 0;
               break;
            
            default:
               if (caps_lock 
                  && ((row == 0 && col == 5) || (row == 5 && col == 5)))
                  // sets hue to opposite color on hsv circle, and cuts saturation in half
                  hsv.h = matrix_hsv.h+128, hsv.s >>= 1,
                  hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
               else
                  continue;
         }

         RGB rgb = hsv_to_rgb(hsv);
         rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
      }
   }

   return false;
}