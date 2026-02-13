// SplitKB Aurora Sweep keyboard
#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H

#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define SPC_RAISE LT(_RAISE, KC_SPACE)
#define SCREEN LGUI(LSFT(KC_4))
#define RECORD LGUI(LSFT(KC_5))
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define VOL_MUTE KC_AUDIO_MUTE
#define BRIGHTER KC_BRIGHTNESS_UP
#define DIMMER KC_BRIGHTNESS_DOWN
#define BOOT QK_BOOTLOADER
#define UMLAUT RALT(KC_QUOTE)
#define GERMAN_S RALT(KC_S)
#define EURO LALT(LSFT(KC_2))

// MACROS & LAYERS

enum macro_keycodes {
  BACK_ARO = SAFE_RANGE,
  FWRD_ARO,
  FAT_ARO,
};

enum keyboard_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
  _FUNC,
  _MEDIA,
};

// KEYMAP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W       │  F       │  P       │  B       ││  J       │  L       │  U       │  Y       │  Umlaut  │
            KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,       KC_J,      KC_L,      KC_U,      KC_Y,      UMLAUT,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R (ALT) │  S (GUI) │  T (MEH) │  G       ││  M       │  N (MEH) │  E (GUI) │  I (ALT) │  O       │
            KC_A,     LALT(KC_R),LGUI(KC_S),MEH_T(KC_T),KC_G,       KC_M,    MEH_T(KC_T),LGUI(KC_E),LALT(KC_I), KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z       │  X       │  C       │  D       │  V       ││  K       │  H       │  ,       │  .       │  ß       │
            KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,       KC_K,      KC_H,      KC_COMM,   KC_DOT,    GERMAN_S,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ LOWER    │  CTLR    ││  SHIFT   │SPC(RAISE)│
                                           OSL(_LOWER), OSM_CTL,    OSM_SFT,   SPC_RAISE
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          ││          │  7       │  8       │  9       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_7,      KC_8,      KC_9,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││          │  4       │  5       │  6       │          │
            KC_A,      BACK_ARO,  FWRD_ARO,  FAT_ARO,   KC_NO,      KC_NO,     KC_4,      KC_5,      KC_6,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │  Copy    │          │  Paste   ││          │  1       │  2       │  3       │          │
            KC_Z,      KC_NO,    LGUI(KC_C), KC_D,     LGUI(KC_V),  KC_NO,     KC_1,      KC_2,      KC_3,      KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼── ───────┼──────────┴──────────┴──────────╯
        //                                 │ XXXXXXXX │          ││  .       │ 0(ADJUST)│
                                             KC_NO,     KC_NO,      KC_DOT,  LT(_ADJUST, KC_0)
        //                                 ╰──────────┴──────────╯╰──────────┴─── ──────╯
    ),
    [_RAISE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │  €       │          ││          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     EURO,      KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  !       │  @       │  #       │  $       │  %       ││  ^       │          │  *       │          │          │
            KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,    KC_CIRC,   KC_NO,   KC_ASTR,   KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │  ADJUST  │          ││          │ XXXXXXXX │
                                           MO(_ADJUST), KC_NO,      KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_ADJUST] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │  SHIFT   │  GUI     │          ││  DOWN    │  LEFT    │          │          │          │
            KC_NO,     KC_NO,     OSM_SFT,   OSM_GUI,   KC_NO,      KC_DOWN,   KC_LEFT,   KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  <       │  [       │  {       │  (       │          ││          │  )       │  }       │  ]       │  >       │
            KC_LABK,   KC_LBRC,   KC_LCBR,   KC_LPRN,   KC_NO,      KC_NO,     KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_RABK,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │  CTL     │  ALT     │          ││  UP      │  RIGHT   │          │          │          │
            KC_NO,     KC_NO,     OSM_CTL,   OSM_ALT,   KC_NO,      KC_UP,     KC_RIGHT,  KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ XXXXXXXX │          ││          │ XXXXXXXX │
                                             KC_NO,     KC_NO,      KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_FUNC] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │  F7      │  F8      │  F9      │  F10     ││          │          │       XXXXXXXX      │          │
            KC_NO,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F4      │  F5      │  F6      │  F11     ││          │          │          │          │          │
            KC_NO,     KC_F4,     KC_F5,     KC_F6,     KC_F11,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F1      │  F2      │  F3      │  F12     ││          │          │          │          │          │
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_F12,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          ││          │          │
                                             KC_NO,     KC_NO,      KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_MEDIA] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │      XXXXXXXX       │          │          ││ SCREEN   │ Vol up   │ RGB BRIT │ RGB FAST │ Brighter │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      SCREEN,    VOL_UP,    RM_VALU,   RM_SPDU,   BRIGHTER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││          │ Vol down │ RGB DIMM │ RGB SLOW │ Dimmer   │
            BOOT,      KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     VOL_DOWN,  RM_VALD,   RM_SPDD,   DIMMER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││ RECORD   │ Mute     │RGB ON/OFF│ RBG NEXT │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      RECORD,    VOL_MUTE,  RM_TOGG,   RM_NEXT,   KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          ││          │          │
                                             KC_MPRV,   KC_MSTP,    KC_MPLY,   KC_MNXT
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
};

// MACROS

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BACK_ARO:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;

        case FWRD_ARO:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;

        case FAT_ARO:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;

    }
    return true;
}

// COMBOS

enum combos {
    // Left
    ESC = 0,
    DASH,
    TAB,

    BACKSLSH,
    COLON,
    FRWDSLSH,

    MEDIA,

    // Right
    AMP,
    APOST,
    BACKTICK,

    BACKSPACE,
    EQUALS,
    ENTER,

    FUNC,
};

// Left
const uint16_t PROGMEM w_f_combo[]          = { KC_W, KC_F,         COMBO_END};
const uint16_t PROGMEM r_s_combo[]          = { KC_R, KC_S,         COMBO_END};
const uint16_t PROGMEM x_c_combo[]          = { KC_X, KC_C,         COMBO_END};

// TODO: maybe this is too far?
const uint16_t PROGMEM w_p_combo[]          = { KC_W, KC_P,         COMBO_END};
const uint16_t PROGMEM r_t_combo[]          = { KC_R, KC_T,         COMBO_END};
const uint16_t PROGMEM x_d_combo[]          = { KC_X, KC_D,         COMBO_END};

const uint16_t PROGMEM f_p_combo[]          = { KC_F, KC_P,         COMBO_END};
const uint16_t PROGMEM s_t_combo[]          = { KC_S, KC_T,         COMBO_END};
const uint16_t PROGMEM c_d_combo[]          = { KC_C, KC_D,         COMBO_END};

const uint16_t PROGMEM w_f_p_combo[]        = { KC_W, KC_F, KC_P,   COMBO_END};

// Right
const uint16_t PROGMEM u_y_combo[]          = { KC_U, KC_Y,         COMBO_END};
const uint16_t PROGMEM e_i_combo[]          = { KC_E, KC_I,         COMBO_END};
const uint16_t PROGMEM comm_dot_combo[]     = { KC_COMM, KC_DOT,    COMBO_END};

const uint16_t PROGMEM l_u_combo[]          = { KC_L, KC_U,         COMBO_END};
const uint16_t PROGMEM n_e_combo[]          = { KC_N, KC_E,         COMBO_END};
const uint16_t PROGMEM h_comm_combo[]       = { KC_H, KC_COMM,      COMBO_END};

const uint16_t PROGMEM l_u_y_combo[]        = { KC_L, KC_U, KC_Y,   COMBO_END};

combo_t key_combos[] = {
    // Left
    [ESC]           = COMBO(w_f_combo,          KC_ESCAPE),
    [DASH]          = COMBO(r_s_combo,          KC_MINUS),
    [TAB]           = COMBO(x_c_combo,          KC_TAB),

    [BACKSLSH]      = COMBO(f_p_combo,          KC_BACKSLASH),
    [COLON]         = COMBO(s_t_combo,          KC_SEMICOLON),
    [FRWDSLSH]      = COMBO(c_d_combo,          KC_SLASH),

    [MEDIA]         = COMBO(w_f_p_combo,        MO(_MEDIA)),

    // RIGHT
    [AMP]           = COMBO(l_u_combo,          KC_AMPERSAND),
    [APOST]         = COMBO(n_e_combo,          KC_QUOTE),
    [BACKTICK]      = COMBO(h_comm_combo,       KC_GRAVE),

    [BACKSPACE]     = COMBO(u_y_combo,          KC_BACKSPACE),
    [EQUALS]        = COMBO(e_i_combo,          KC_EQUAL),
    [ENTER]         = COMBO(comm_dot_combo,     KC_ENTER),

    [FUNC]          = COMBO(l_u_y_combo,        MO(_FUNC)),
};

