#include QMK_KEYBOARD_H

uint8_t get_horizontal_gradient_index(uint8_t row, uint8_t col) {
   if (row == 0) {
      return col;  // Left: 0–5
  } else if (row == 5) {
      return 11 - col;  // Right: 11–6
  }
  return 0;
}

uint8_t get_hue_for_index(uint8_t grad_index, uint8_t total_keys) {
   if (total_keys < 2) return 0;  // Prevent divide-by-zero or flat color
   return (uint8_t)(((uint16_t)(255 * grad_index) / total_keys) % 256);
}

void rgb_matrix_set_color_hsv(uint8_t index, HSV hsv) {
   RGB rgb = hsv_to_rgb(hsv);
   rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   const bool caps_lock = host_keyboard_led_state().caps_lock;
   const bool caps_word = is_caps_word_on();
   HSV matrix_hsv = rgb_matrix_get_hsv();
    
   for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
         const uint8_t index = g_led_config.matrix_co[row][col];
         
         if (index < led_min || index >= led_max)
            continue;

         HSV hsv = {
            .s = 222,
            .v = matrix_hsv.v
         };
         
         // Whole top row, Rainbow gradient animation
         if (row == 0 || row == 5)
         {
            bool reverse = false; // or toggle based on layer/state
            
            uint8_t grad_index = reverse 
               ? (11 - get_horizontal_gradient_index(row, col)) 
               : get_horizontal_gradient_index(row, col);
               
            hsv.h = get_hue_for_index(grad_index, 12);
            
            rgb_matrix_set_color_hsv(index, hsv);
            continue;
         }
         
         // Weird thumb key left
         if ((row == 4 && col == 5))
         {
            if (caps_lock) {
               // sets hue to opposite color on hsv circle, and cuts saturation in half
               hsv.h = (matrix_hsv.h + 128) % 256, 
               hsv.s >>= 1,
               hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
               rgb_matrix_set_color_hsv(index, hsv);
               continue;
            }
            
            // Base color applied here
            continue;
         }
         
         // Weird thumb key right
         if ((row == 9 && col == 5))
         {
            if (caps_word) {
               // sets hue to opposite color on hsv circle, and cuts saturation in half
               hsv.h = (matrix_hsv.h + 128) % 256, 
               hsv.s >>= 1,
               hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
               rgb_matrix_set_color_hsv(index, hsv);
               continue;
            }
            
            // Base color applied here
            continue;
         }
         
         // Set everything else to off
         hsv.v = 0;
         rgb_matrix_set_color_hsv(index, hsv);
      }
   }

   return false;
}