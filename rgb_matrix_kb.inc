RGB_MATRIX_EFFECT(gamepad_effect)
RGB_MATRIX_EFFECT(caps_word_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool gamepad_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color(27, RGB_CYAN);
  return rgb_matrix_check_finished_leds(led_max);
}

static bool caps_word_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color(23, RGB_CYAN);
  rgb_matrix_set_color(67, RGB_CYAN);
  rgb_matrix_set_color(66, RGB_CYAN);
  rgb_matrix_set_color(65, RGB_CYAN);
  rgb_matrix_set_color(31, RGB_CYAN);
  rgb_matrix_set_color(32, RGB_CYAN);
  rgb_matrix_set_color(33, RGB_CYAN);
  return rgb_matrix_check_finished_leds(led_max);
}

#endif
