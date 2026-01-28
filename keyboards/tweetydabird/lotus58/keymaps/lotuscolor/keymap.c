// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

/*
 * KEYMAP DOCUMENTATIE - LOTUS 58 (HeerNMeester 2026-01-28)
 * --------------------------------------------------------
 * LED ROUTE: 
 * LINKS (Slave):  Underglow (0-5) -> Rij 5 naar Rij 1 (Index 6 t/m 34)
 * RECHTS (Master): Underglow (35-40) -> Rij 1 naar Rij 5 (Index 41 t/m 69)
 *
 * LAYERS & KLEUREN:
 * 0: _BASE   -> [GROEN] Volledige matrix
 * 1: _NUMPAD -> [BLAUW UG] Rechts: Groen Numpad | Links: Rode Pijlen
 * 2: _FUNC   -> [ROOD UG] Blauwe F-Toetsen (6-10 & 41-47) | Oranje Symbolen
 * 3: _SYS    -> [PAARS UG] Oranje RGB/Systeem controls
 */

/*
 * LINKER HELFT (Data: Onder -> Boven)
 * .-------------------------------------------.
 * |  11  |  10  |  09  |  08  |  07  |  06  | RIJ 1 (F1-F5 op 06-10)
 * |------+------+------+------+------+------|
 * |  12* |  13  |  14  |  15  |  16  |  17  | RIJ 2 (*12=Caps)
 * |------+------+------+------+------+------|
 * |  23* |  22  |  21  |  20  |  19  |  18  | RIJ 3 (*23=NumL, 20-22=Pijlen)
 * |------+------+------+------+------+------|
 * |  24  |  25  |  26  |  27  |  28  |  29  | RIJ 4
 * '------+------+------+------+------+------'
 * 		  |  34  |  33  |  32  |  31  |  30  | RIJ 5 (31-34=GROEN)
 *  	  '---------------------------'------'
 */

/*
 * RECHTER HELFT (Data: Boven -> Onder)
 * .-------------------------------------------.
 * |  41  |  42  |  43  |  44  |  45  |  46  | RIJ 1 (42-44=Num 7-9)
 * |------+------+------+------+------+------|
 * |  52  |  51  |  50  |  49  |  48  |  47  | RIJ 2 (49-51=Num 4-6)
 * |------+------+------+------+------+------|
 * |  53  |  54  |  55  |  56  |  57  |  58  | RIJ 3 (54-56=Num 1-3)
 * |------+------+------+------+------+------|
 * |  64  |  63  |  62  |  61  |  60  |  59  | RIJ 4 (61-62=Num 0/.)
 * '------+------+------+------+------+------'
 * |  65  |  66  |  67  |  68  |  69  | RIJ 5 (66-69=GROEN)
 * '---------------------------'------'
 */

enum layers {
    _BASE,
    _NUMPAD,
    _FUNC,
    _SYS
};

// ================= KEYMAPS =================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MPLY,        KC_MPLY, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    LSFT_T(KC_BSLS), KC_A, KC_S, KC_D, KC_F, KC_G,           KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_QUOT),
    LCTL_T(KC_LEFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DOWN, KC_UP, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RCTL_T(KC_RGHT),
                      KC_LALT, TT(_NUMPAD), KC_DEL, KC_SPC, RSFT_T(KC_ENT), KC_BSPC, TT(_FUNC), KC_RGUI
),

[_NUMPAD] = LAYOUT(
    XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,        _______, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
    KC_CAPS, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
    KC_NUM, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_HOME,       KC_END, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_PMNS, KC_PAST, KC_PPLS, KC_PSLS, KC_EQL, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, KC_KP_0, KC_PDOT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______, _______, _______
),

[_FUNC] = LAYOUT(
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,       _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    _______, KC_LBRC, KC_RBRC, _______, _______, _______,        _______, _______, XXXXXXX, XXXXXXX, KC_UP, KC_F12,
    _______, LSFT(KC_LBRC), LSFT(KC_RBRC), _______, _______, _______,        _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,
    _______, LSFT(KC_COMM), LSFT(KC_DOT), _______, _______, _______, TT(_SYS), TT(_SYS), _______, _______, KC_MPRV, KC_MNXT, XXXXXXX, KC_PSCR,
                      _______, _______, _______, _______, _______, _______, _______, _______
),

[_SYS] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, AC_TOGG, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, UG_PREV, UG_NEXT, UG_TOGG,
    QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, UG_SATD, UG_SATU, RGB_M_P,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,                     XXXXXXX, XXXXXXX, XXXXXXX, UG_HUED, UG_HUEU, RGB_M_B,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_VALD, UG_VALU, RGB_M_R,
                      _______, _______, _______, _______, _______, _______, _______, _______
)
};

// ================= ENCODERS =================
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_MPRV), ENCODER_CCW_CW(KC_TRNS, KC_MNXT) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

// ================= OLED =================
#ifdef OLED_ENABLE
static void print_status_narrow(void) {
    oled_write_P(PSTR("\nLotus -58-\n"), false);
    oled_write_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("-Base\n"), false); break;
        case 1: oled_write_P(PSTR("-Nump\n"), false); break;
        case 2: oled_write_P(PSTR("-Func\n"), false); break;
        case 3: oled_write_P(PSTR("-Sys\n"), false); break;
        default: oled_write_P(PSTR("Undef\n"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("Stats"), false);
    oled_write_P(led_state.num_lock ? PSTR("num:*") : PSTR("num:."), false);
    oled_write_P(led_state.caps_lock ? PSTR("cap:*") : PSTR("cap:."), false);
    oled_write_P(led_state.scroll_lock ? PSTR("scr:*") : PSTR("scr:."), false);
}
bool oled_task_user(void) {
    print_status_narrow();
    return false;
}
#endif

bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    bool blink_on = (timer_read() % 1000) < 500;
    led_t led_state = host_keyboard_led_state();

    // --- 1. UNDERGLOW (Layer Sync) ---
    uint8_t ug[] = {0, 1, 2, 3, 4, 5, 35, 36, 37, 38, 39, 40};
    uint8_t r = 0, g = 0, b = 0;
    switch (layer) {
        case _BASE:   g = 255; break;
        case _NUMPAD: b = 255; break; 
        case _FUNC:   r = 255; break; 
        case _SYS:    r = 255; b = 255; break; 
    }
    for (int j = 0; j < 12; j++) { rgb_matrix_set_color(ug[j], r, g, b); }

    // --- 2. KEY MATRIX ---
    for (int i = 0; i < 70; i++) {
        if ((i >= 0 && i <= 5) || (i >= 35 && i <= 40)) continue;

        // REGEL: Laatste 4 toetsen van elke helft (Rij 5 eind) altijd GROEN
        if (i == 31 || i == 32 || i == 33 || i == 34 || 
            i == 66 || i == 67 || i == 68 || i == 69) {
            rgb_matrix_set_color(i, 0, 255, 0);
            continue;
        }

        if (layer == _BASE) {
            rgb_matrix_set_color(i, 0, 255, 0); 
        } 
        else {
            // A. LOCKS (Wit knipperend)
            if ((i == 12 && led_state.caps_lock) || (i == 23 && led_state.num_lock)) {
                rgb_matrix_set_color(i, blink_on ? 255 : 0, blink_on ? 255 : 0, blink_on ? 255 : 0);
            }
            // B. NUMPAD (Groen) - Rechts (Layer 1)
            else if (layer == _NUMPAD && (i == 42 || i == 43 || i == 44 || i == 49 || i == 50 || 
                     i == 51 || i == 54 || i == 55 || i == 56 || i == 61 || i == 62)) {
                rgb_matrix_set_color(i, 0, 255, 0);
            }
            // C. F-TOETSEN (Blauw) - Beide kanten (Layer 2)
            else if (layer == _FUNC && ((i >= 41 && i <= 47) || (i >= 6 && i <= 10))) {
                rgb_matrix_set_color(i, 0, 0, 255);
            }
            // D. PIJLTJES (Rood)
            else if ((layer == _NUMPAD && (i == 14 || i == 22 || i == 21 || i == 20)) ||
                     (layer == _FUNC && (i == 48 || i == 56 || i == 57 || i == 58))) {
                rgb_matrix_set_color(i, 255, 0, 0);
            }
            // E. EXPLICIETE ORANJE TOETSEN
            else if ((layer == _NUMPAD && (i == 12 || i == 18 || i == 23 || i == 25 || i == 26 || i == 27 || i == 28 || i == 29 || i == 30 || i == 65 || i == 53)) ||
                     (layer == _FUNC && (i == 13 || i == 14 || i == 21 || i == 22 || i == 25 || i == 26 || i == 61 || i == 62 || i == 59 || i == 65 || i == 46 )) ||
					 (layer == _SYS && (i == 44 || i == 45 || i == 46 || i == 48 || i == 49 || i == 56 || i == 57 || i == 60 || i == 61 ))) {	 
                rgb_matrix_set_color(i, 255, 127, 0);
            }
            // F. BLACKOUT (Inclusief KC_TRANS en KC_NO)
            else {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }
    }
    return false;
}