RGB_MATRIX_EFFECT(numpad_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool numpad_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    if (!is_keyboard_master()) {
        //numpad lights
        rgb_matrix_set_color(6, 0xff, 0xff, 0x00);//m3
        rgb_matrix_set_color(7, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(8, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(9, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(10, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(11, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(12, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(15, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(16, 0xff, 0xff, 0x00);
        rgb_matrix_set_color(17, 0xff, 0xff, 0x00);

        //parenthesis lights
        rgb_matrix_set_color(18, 0xff, 0x00, 0x00);
        rgb_matrix_set_color(23, 0xff, 0x00, 0x00);
        rgb_matrix_set_color(19, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(22, 0xff, 0x00, 0xff);
        rgb_matrix_set_color(20, 0x00, 0x00, 0xff);
        rgb_matrix_set_color(21, 0x00, 0x00, 0xff);

        //disable backlight
        rgb_matrix_set_color(0, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(1, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(2, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(3, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(4, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(5, 0x00, 0x00, 0x00);

        //disable m1 and m2 lights
        rgb_matrix_set_color(13, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(14, 0x00, 0x00, 0x00);

        //disable left row lights
        rgb_matrix_set_color(24, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(25, 0x00, 0x00, 0x00);
        rgb_matrix_set_color(26, 0x00, 0x00, 0x00);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
            break;
        case 1:
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_numpad_effect);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    return state;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
