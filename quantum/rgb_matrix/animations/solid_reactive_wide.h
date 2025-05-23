#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE) || defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE)

#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define RGB_MATRIX_EFFECT_SOLID_REACTIVE_WIDE
RGB_MATRIX_EFFECT(SOLID_REACTIVE_WIDE)
#        endif

#        ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define RGB_MATRIX_EFFECT_SOLID_REACTIVE_MULTIWIDE
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTIWIDE)
#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_WIDE_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;
#            ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
#            endif
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

#            ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
bool SOLID_REACTIVE_WIDE(effect_params_t* params) {
    return effect_runner_reactive_splash(qsub8(g_last_hit_tracker.count, 1), params, &SOLID_REACTIVE_WIDE_math);
}
#            endif

#            ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
bool SOLID_REACTIVE_MULTIWIDE(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &SOLID_REACTIVE_WIDE_math);
}
#            endif

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // !defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE) || !defined(ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE)
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
