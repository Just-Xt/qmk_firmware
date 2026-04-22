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

// Sets hue to opposite color on HSV circle, and cuts saturation in half
static void apply_inverted_indicator_color(uint8_t index, HSV matrix_hsv) {
   HSV hsv = {
      .h = (matrix_hsv.h + 128) % 256,
      .s = matrix_hsv.s >> 1,
      .v = RGB_MATRIX_MAXIMUM_BRIGHTNESS
   };
   rgb_matrix_set_color_hsv(index, hsv);
}

static void apply_flashing_indicator_color(uint8_t index, HSV matrix_hsv) {
   // LED on for half of this ms value
   uint16_t elapsed = timer_read() % 1000; 
   
   if (elapsed < 500) {
      // LED is "on" - show inverted color
      apply_inverted_indicator_color(index, matrix_hsv);
   } else {
      // LED is "off" - dim or hide
      rgb_matrix_set_color(index, 0, 0, 0);
   }
}


//┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐                       ┌────────-┬────────-┬───────-─┬─────-───┬────-────┬──────-──┐
//  [0, 0]    [0, 1]    [0, 2]    [0, 3]    [0, 4]    [0, 5]                             [5, 5]    [5, 4]    [5, 3]    [5, 2]    [5, 1]    [5, 0]
//├────-────┼──────-──┼────-────┼────-────┼──-──────┼────-────┤                       ├─────-───┼────-────┼──-──────┼───-─────┼──-──────┼────-────┤
//  [1, 0]    [1, 1]    [1, 2]    [1, 3]    [1, 4]    [1, 5]                             [6, 5]    [6, 4]    [6, 3]    [6, 2]    [6, 1]    [6, 0]
//├──────-──┼─────-───┼────-────┼─────-───┼───-─────┼───-─────┼───-─────┐   ┌───-─────┼────-────┼───-─────┼─────-───┼─────-───┼─────-───┼───-─────┤
//  [2, 0]    [2, 1]    [2, 2]    [2, 3]    [2, 4]    [2, 5]    [4, 5]         [9, 5]    [7, 5]    [7, 4]    [7, 3]    [7, 2]    [7, 1]    [7, 0]
//└───-─────┴─────-───┴──────-──┴───┬──-──┴───┬──-──┴───┬──-──┴───┬─-───┘   └─-──┬────┴─-──┬────┴──-─┬────┴──-─┬────┴─-~~~~~~~┴~~~~~----┴~~~-~~~~~~┘
//                                    [4, 2]    [4, 3]    [4, 4]                    [9, 4]    [9, 3]    [9, 2]
//                                  └─────-───┴───-─────┴─────-───┘              └──────-──┴───-─────┴─────-───┘
                                 
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   const bool caps_lock = host_keyboard_led_state().caps_lock;
   const bool caps_word = is_caps_word_on();
   const bool oneshot_shift = get_oneshot_mods() & MOD_MASK_SHIFT;
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
        
         // Whole top row
         if (row == 0 || row == 5)
         {
            // Indicators for lock states
            if (col == 5 && caps_lock)
            {
               apply_inverted_indicator_color(index, matrix_hsv);
               continue;
            }
            if (col == 4 && caps_word)
            { 
               apply_flashing_indicator_color(index, matrix_hsv);
               continue;
            }
            if (col == 3 && oneshot_shift)
            {
               apply_flashing_indicator_color(index, matrix_hsv);
               continue;
            }
            
            
            // Rainbow gradient
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
            continue;
         }
         
         // Weird thumb key right
         if ((row == 9 && col == 5))
         {
            continue;
         }
         
         // Set everything else to off
         hsv.v = 0;
         rgb_matrix_set_color_hsv(index, hsv);
      }
   }

   return false;
}

