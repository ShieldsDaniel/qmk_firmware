/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum sweep_keycodes {
  BACK_ARROW = SAFE_RANGE,
  JS_EQUALS,
  SQUIGGLY_ARROW,
  FORWARD_ARROW,
  FAT_ARROW,
  BACK_PIPE,
  FORWARD_PIPE,
};

enum tap_dance_codes {
  DANCE_0,
};

enum sweep_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮     ╭──────────┬──────────┬───────────┬───────────┬──────────╮
        //│  Q       │  W   (ESC)  F       │  P       │  B       │     │  J       │  L       │  U    (ALT)  Y        │ Umlaut/ß │
            KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,            KC_J,      KC_L,      KC_U,       KC_Y,       TD(DANCE_0),    
        //├──────────┼──────────┼──────────┼──────────┼──────────┤     ├──────────┼──────────┼───────────┼───────────┼──────────┤
        //│  A       │  R       │  S       │  T       │  G    L4 │     │  M   MEH │  N       │  E        │  I        │  O       │
            KC_A,      KC_R,      KC_S,      KC_T,      LT(4,KC_G),    MEH_T(KC_M), KC_N,      KC_E,       KC_I,       KC_O,           
        //├──────────┼──────────┼──────────┼──────────┼──────────┤     ├──────────┼──────────┼───────────┼───────────┼──────────┤
        //│  Z       │  X   (TAB)  C       │  D       │  V       │     │  K       │  H       │  ,    (GUI)  .        │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,            KC_K,      KC_H,      KC_COMMA,   KC_DOT,     KC_ENTER,       
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤     ├──────────┼──────────┼───────────┴───────────┴──────────╯
        //                                 │ BSPC  L1 │ OSM CTLR (CAPS) OSM SHIFT │ SPC   L2 │
                                 LT(_LOWER, KC_BACKSPACE),OSM(MOD_LCTL), OSM(MOD_LSFT),LT(_RAISE, KC_SPACE)
        //                                 ╰──────────┴──────────╯     ╰──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬────────────┬────────────┬────────────┬──────────╮   ╭──────────┬─────────┬─────────┬─────────┬──────────╮
        //│          │            │            │  <-        │          │   │          │  ===    │  `      │  "      │          │
            KC_NO,     KC_NO,       KC_NO,       BACK_ARROW,  KC_NO,         KC_NO,    JS_EQUALS, KC_GRAVE, KC_DQUO,  KC_NO,          
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│  ?       │  ~         │  _         │  -         │  \       │   │  /       │  =      │  +      │  '      │  :       │
            KC_QUES,   KC_TILD,     KC_UNDS,     KC_MINUS,    KC_BSLS,       KC_SLASH,  KC_EQUAL, KC_PLUS,  KC_QUOTE, KC_COLN,        
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│          │  ~>        │            │  ->        │          │   │          │  =>     │         │         │          │
            KC_NO,   SQUIGGLY_ARROW,KC_NO,     FORWARD_ARROW, BACK_PIPE,    KC_NO,     FAT_ARROW, KC_NO,    KC_NO,    KC_NO,          
        //╰──────────┴────────────┴────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┴─────────┴──────────╯
        //                                     │            │          │   │          │         │
                                                 KC_NO,       KC_NO,     KC_TRANSPARENT, LT(_ADJUST, KC_SPACE)
        //                                     ╰────────────┴──────────╯   ╰──────────┴─────────╯
    ),
    [_RAISE] = LAYOUT(
        //╭──────────┬────────────┬────────────┬────────────┬──────────╮   ╭──────────┬─────────┬─────────┬─────────┬──────────╮
        //│          │            │            │  €         │          │   │          │         │  <|     │         │          │
            KC_NO,     KC_NO,       KC_NO,   LALT(LSFT(KC_2)), KC_NO,        KC_NO,     KC_NO,   BACK_PIPE, KC_NO,   KC_NO,          
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│  !       │  @         │  #         │  $         │  %       │   │  ^       │  &      │  |      │  *      │  ;       │
            KC_EXLM,   KC_AT,       KC_HASH,     KC_DLR,      KC_PERC,       KC_CIRC,   KC_AMPR,  KC_PIPE,  KC_ASTR,  KC_SCLN,
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│          │            │            │            │          │   │          │         │  |>     │         │          │
            KC_NO,     KC_NO,       KC_NO,       KC_NO,       KC_NO,         KC_NO,     KC_NO,  FORWARD_PIPE, KC_NO,  KC_NO,          
        //╰──────────┴────────────┴────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┴─────────┴──────────╯
        //                                     │            │          │   │          │         │
                                    LT(_ADJUST, KC_BACKSPACE), KC_TRANSPARENT,  KC_NO,     KC_NO
        //                                     ╰────────────┴──────────╯   ╰──────────┴─────────╯
    ),
    [_ADJUST] = LAYOUT(
        //╭──────────┬────────────┬────────────┬────────────┬──────────╮   ╭──────────┬─────────┬─────────┬─────────┬──────────╮
        //│          │            │  Screen    │  Record    │          │   │  DOWN    │  LEFT   │         │         │          │
            KC_NO,     KC_NO,   LGUI(LSFT(KC_4)),LGUI(LSFT(KC_5)),KC_NO,     KC_DOWN,   KC_LEFT,  KC_NO,    KC_NO,    KC_NO,          
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│  <       │  [         │  {         │  (         │          │   │          │  )      │  }      │  ]      │  >       │
            KC_LABK,   KC_LBRC,     KC_LCBR,     KC_LPRN,     KC_NO,         KC_NO,     KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_RABK,        
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│  L5      │            │            │            │          │   │  UP      │  RIGHT  │         │         │  L5      │
            KC_0,      KC_NO,       KC_NO,       KC_NO,       KC_NO,         KC_UP,     KC_RIGHT, KC_NO,    KC_NO,    KC_1,           
        //╰──────────┴────────────┴────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┴─────────┴──────────╯
        //                                     │            │          │   │          │         │
                                                 KC_NO,       KC_NO,         KC_NO,     KC_NO
        //                                     ╰────────────┴──────────╯   ╰──────────┴─────────╯
    ),
    [_LAYER4] = LAYOUT(
        //
        //╭──────────┬────────────┬────────────┬────────────┬──────────╮   ╭──────────┬─────────┬─────────┬─────────┬──────────╮
        //│          │            │            │            │          │   │          │         │         │         │          │
            KC_NO,     KC_F7,       KC_F8,       KC_F9,       KC_F10,        KC_NO,     KC_7,     KC_8,     KC_9,     KC_NO,          
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│          │            │            │            │          │   │          │         │         │         │          │
            KC_F12,    KC_F4,       KC_F5,       KC_F6,       KC_NO,         KC_NO,     KC_4,     KC_5,     KC_6,     KC_NO,          
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│          │            │            │            │          │   │          │         │         │         │          │
            KC_NO,     KC_F1,       KC_F2,       KC_F3,       KC_NO,         KC_COMMA,  KC_1,     KC_2,     KC_3,     KC_NO,          
        //╰──────────┴────────────┴────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┴─────────┴──────────╯
        //                                     │            │          │   │          │         │
                                                 KC_NO, KC_TRANSPARENT,      KC_DOT,    KC_0
        //                                     ╰────────────┴──────────╯   ╰──────────┴─────────╯
    ),
    [_LAYER5] = LAYOUT(
        //╭──────────┬────────────┬────────────┬────────────┬──────────╮   ╭──────────┬─────────┬─────────┬─────────┬──────────╮
        //│          │            │            │            │          │   │          │         │         │         │          │
            KC_NO,     KC_NO,       KC_NO,       KC_NO,       KC_NO,         KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,          
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│          │            │            │            │          │   │          │         │         │         │          │
            TO(0),     TO(0),       TO(0),       TO(0),       KC_NO,         KC_NO,     TO(0),    TO(0),    TO(0),    TO(0),          
        //├──────────┼────────────┼────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┼─────────┼──────────┤
        //│BOOTLOADER│            │            │            │          │   │          │         │         │         │          │
          QK_BOOTLOADER,KC_NO,      KC_NO,       KC_NO,       KC_NO,         KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,          
        //╰──────────┴────────────┴────────────┼────────────┼──────────┤   ├──────────┼─────────┼─────────┴─────────┴──────────╯
        //                                     │            │          │   │          │         │
                                                 TO(0),       TO(0),         TO(0),     TO(0)
        //                                     ╰────────────┴──────────╯   ╰──────────┴─────────╯
    )
};

const uint16_t PROGMEM combo0[] = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo3[] = { OSM(MOD_LSFT), OSM(MOD_LCTL), COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_0, KC_1, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, OSM(MOD_LGUI)),
    COMBO(combo1, OSM(MOD_LALT)),
    COMBO(combo2, KC_ESCAPE),
    COMBO(combo3, KC_CAPS),
    COMBO(combo4, TO(5)),
    COMBO(combo5, KC_TAB),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BACK_ARROW:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;

        case JS_EQUALS:
            if (record->event.pressed) {
                SEND_STRING("===");
            }
            break;

        case SQUIGGLY_ARROW:
            if (record->event.pressed) {
                SEND_STRING("~>");
            }
            break;

        case FORWARD_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;

        case FAT_ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;

        case BACK_PIPE:
            if (record->event.pressed) {
                SEND_STRING("<|");
            }
            break;

        case FORWARD_PIPE:
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            break;
    }
    return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_U));
        tap_code16(LALT(KC_U));
        tap_code16(LALT(KC_U));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_U));
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LALT(KC_U)); break;
        case SINGLE_HOLD: register_code16(LALT(KC_S)); break;
        case DOUBLE_TAP: register_code16(LALT(KC_U)); register_code16(LALT(KC_U)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_U)); register_code16(LALT(KC_U));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_U)); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_S)); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_U)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_U)); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall
    // This example string should fill that neatly
    const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?");

    if (is_keyboard_master()) {
        oled_write_P(text, false);
    } else {
        oled_write_P(text, false);
    }
    return false;
}
#endif
