// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_logo(void) {
    // QMK Logo
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    render_logo();
    return false;
}
#endif

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { 
    {
        // Key Matrix → LED Index
        // 10x5 matrix per hand (electrical rows/cols)
        // NO_LED voor lege plekken
        // Left hand
        {  5,  4,  3,  2,  1,  0 },
        {  6,  7,  8,  9, 10, 11 },
        { 17, 16, 15, 14, 13, 12 },
        { 18, 19, 20, 21, 22, 23 },
        { NO_LED, 28, 27, 26, 25, 24 },

        // Right hand
        { 40, 39, 38, 37, 36, 35 },
        { 41, 42, 43, 44, 45, 46 },
        { 52, 51, 50, 49, 48, 47 },
        { 53, 54, 55, 56, 57, 58 },
        { NO_LED, 63, 62, 61, 60, 59 }
    }, 
    {
        // LED Index → Physical Position { x, y }
        // Left hand LEDs (0..34)
        {  0,  0}, { 22,  0}, { 44,  0}, { 66,  0}, { 88,  0}, {110,  0},
        {  0, 16}, { 22, 16}, { 44, 16}, { 66, 16}, { 88, 16}, {110, 16},
        {110, 32}, { 88, 32}, { 66, 32}, { 44, 32}, { 22, 32}, {  0, 32},
        {  0, 48}, { 22, 48}, { 44, 48}, { 66, 48}, { 88, 48}, {110, 48},
        {132, 40}, {154, 40}, {176, 40}, {198, 40}, {220, 40},

        // Left underglow
        { 44, 64}, { 88, 64}, {132, 64}, 
        {  0, 64}, {110, 64}, {220, 64}, 

        // Right hand LEDs (35..69)
        {110,  0}, {132,  0}, {154,  0}, {176,  0}, {198,  0}, {220,  0},
        {220, 16}, {198, 16}, {176, 16}, {154, 16}, {132, 16}, {110, 16},
        {110, 32}, {132, 32}, {154, 32}, {176, 32}, {198, 32}, {220, 32},
        {220, 48}, {198, 48}, {176, 48}, {154, 48}, {132, 48}, {110, 48},
        { 88, 40}, { 66, 40}, { 44, 40}, { 22, 40}, {  0, 40},

        // Right underglow
        { 66, 64}, {110, 64}, {154, 64}, 
        {198, 64}, {132, 64}, {176, 64} 
    }, 
    {
        // LED Index → Flags
        // Key LEDs = LED_FLAG_KEYLIGHT, Underglow = LED_FLAG_UNDERGLOW
        // Left hand keys (0..34)
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,

        // Left underglow
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,

        // Right hand keys (35..69)
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,

        // Right underglow
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW
    }
};

#endif