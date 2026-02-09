// SplitKB Aurora Sweep keyboard
#include QMK_KEYBOARD_H

#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define BSPC_LOWER LT(_LOWER, KC_BSPC)
#define SPC_RAISE LT(_RAISE, KC_SPACE)
#define EURO LALT(LSFT(KC_2))
#define SCREEN LGUI(LSFT(KC_4))
#define RECORD LGUI(LSFT(KC_5))
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define VOL_MUTE KC_AUDIO_MUTE
#define BRIGHTER KC_BRIGHTNESS_UP
#define DIMMER KC_BRIGHTNESS_DOWN
#define BOOT QK_BOOTLOADER
#define UMLAUT LALT(KC_U)
#define GERMAN_S LALT(KC_S)

// MACROS & LAYERS

enum macro_keycodes {
  BACK_ARO = SAFE_RANGE,
  JS_EQUALS,
  SQUIG_ARO,
  FWRD_ARO,
  FAT_ARO,
  BACK_PIPE,
  FWRD_PIPE,
};

enum keyboard_layers {
  _MAC,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
  _FUNC,
  _MEDIA,
  _RESET,
};

// KEYMAP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W       │  F       │  P       │  B       ││  J       │  L       │  U       │  Y       │  BSPC    │
            KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,       KC_J,      KC_L,      KC_U,      KC_Y,      KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R       │  S       │  T       │  G       ││  M       │  N       │  E       │  I       │  O       │
            KC_A,      KC_R,      KC_S,      KC_T,      KC_G,       KC_M,      KC_N,      KC_E,      KC_I,      KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z       │  X       │  C       │  D       │  V       ││  K       │  H       │  ,       │  .       │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,       KC_K,      KC_H,      KC_COMM,   KC_DOT,    KC_ENT,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ LOWER    │  CTLR    ││  SHIFT   │SPC(RAISE)│
                                            BSPC_LOWER, OSM_CTL,    OSM_SFT,   SPC_RAISE
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │  Umlaut  │  ß       ││          │  ===     │          │  "       │  BSPC    │
            KC_NO,     KC_NO,     KC_NO,     UMLAUT,    GERMAN_S,   KC_NO,    JS_EQUALS,  KC_NO,     KC_DQUO,   KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  ?       │  ~       │  _       │  -       │  \       ││  /       │  =       │  +       │  '       │  :       │
            KC_QUES,   KC_TILD,   KC_UNDS,   KC_MINS,   KC_BSLS,    KC_SLSH,   KC_EQL,    KC_PLUS,   KC_QUOT,   KC_COLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││  ->      │  =>      │  ~>      │  `       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      FWRD_ARO,  FAT_ARO,   SQUIG_ARO, KC_GRV,    KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼── ───────┼──────────┴──────────┴──────────╯
        //                                 │ XXXXXXXX │          ││          │  ADJUST  │
                                             KC_NO,     KC_NO,      KC_NO,    MO(_ADJUST)
        //                                 ╰──────────┴──────────╯╰──────────┴─── ──────╯
    ),
    [_RAISE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │  €       │          ││          │          │  <|      │          │  BSPC    │
            KC_NO,     KC_NO,     KC_NO,     EURO,      KC_NO,      KC_NO,     KC_NO,     BACK_PIPE, KC_NO,     KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  !       │  @       │  #       │  $       │  %       ││  ^       │  &       │  |       │  *       │  ;       │
            KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,    KC_CIRC,   KC_AMPR,   KC_PIPE,   KC_ASTR,   KC_SCLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││          │          │  |>      │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_NO,     FWRD_PIPE, KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │  ADJUST  │          ││          │ XXXXXXXX │
                                           MO(_ADJUST), KC_NO,      KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_ADJUST] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │  SHIFT   │  GUI     ││  DOWN    │  LEFT    │          │          │  BSPC    │
            KC_NO,     KC_NO,     KC_NO,     OSM_SFT,   OSM_GUI,    KC_DOWN,   KC_LEFT,   KC_NO,     KC_NO,     KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  <       │  [       │  {       │  (       │          ││          │  )       │  }       │  ]       │  >       │
            KC_LABK,   KC_LBRC,   KC_LCBR,   KC_LPRN,   KC_NO,      KC_NO,     KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_RABK,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │  CTL     │  ALT     ││  UP      │  RIGHT   │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     OSM_CTL,   OSM_ALT,    KC_UP,     KC_RIGHT,  KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ XXXXXXXX │          ││          │ XXXXXXXX │
                                             KC_NO,     KC_NO,      KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_NUM] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          ││          │  7       │  8       │  9       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_7,      KC_8,      KC_9,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││          │  4       │  5       │  6       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_4,      KC_5,      KC_6,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │      XXXXXXXX       │          │          ││  ,       │  1       │  2       │  3       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_COMMA,  KC_1,      KC_2,      KC_3,      KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          ││  .       │  0       │
                                             KC_NO,     KC_NO,      KC_DOT,    KC_0
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
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     VOL_DOWN,  RM_VALD,   RM_SPDD,   DIMMER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││ RECORD   │ Mute     │RGB ON/OFF│ RBG NEXT │          │
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_NO,      RECORD,    VOL_MUTE,  RM_TOGG,   RM_NEXT,   KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          ││          │          │
                                             KC_MPRV,   KC_MSTP,    KC_MPLY,   KC_MNXT
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_RESET] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          ││          │          │          │          │          │
            TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) ,  TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) ,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││          │          │          │          │          │
            TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) ,  TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) ,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│BOOTLOADER│          │          │          │          ││          │          │          │          │          │
            BOOT,      TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) ,  TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) , TO(_MAC) ,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          ││          │          │
                                             TO(_MAC) , TO(_MAC) ,  TO(_MAC) , TO(_MAC)
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
};

// MACROS

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JS_EQUALS:
            if (record->event.pressed) {
                SEND_STRING("===");
            }
            break;

        case BACK_ARO:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;

        case SQUIG_ARO:
            if (record->event.pressed) {
                SEND_STRING("~>");
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

        case BACK_PIPE:
            if (record->event.pressed) {
                SEND_STRING("<|");
            }
            break;

        case FWRD_PIPE:
            if (record->event.pressed) {
                SEND_STRING("|>");
            }
            break;

    }
    return true;
}

// COMBOS

enum combos {
    MEDIA = 0,
    ESC,
    NUM,
    DEL,
    FUNC,
    TAB,
    SHORTCUTS,
    L_SUPER,
    R_SUPER,
    L_GUI,
    R_GUI,
    L_ALT,
    R_ALT,
    TO_RESET,
};

const uint16_t PROGMEM media_combo[]        = { KC_W, KC_F, KC_P,                       COMBO_END};
const uint16_t PROGMEM esc_combo[]          = { KC_W, KC_F,                             COMBO_END};
const uint16_t PROGMEM num_combo[]          = { KC_X, KC_C,                             COMBO_END};
const uint16_t PROGMEM del_combo[]          = { KC_X, KC_C, KC_D,                       COMBO_END};
const uint16_t PROGMEM func_combo[]         = { KC_L, KC_U, KC_Y,                       COMBO_END};
const uint16_t PROGMEM tab_combo[]          = { KC_U, KC_Y,                             COMBO_END};
const uint16_t PROGMEM shortcuts_combo[]    = { KC_COMM, KC_DOT,                        COMBO_END};
const uint16_t PROGMEM l_super_combo[]      = { KC_R, KC_S, KC_T,                       COMBO_END};
const uint16_t PROGMEM r_super_combo[]      = { KC_N, KC_E, KC_I,                       COMBO_END};
const uint16_t PROGMEM l_gui_combo[]        = { KC_P, KC_B,                             COMBO_END};
const uint16_t PROGMEM r_gui_combo[]        = { KC_J, KC_L,                             COMBO_END};
const uint16_t PROGMEM l_alt_combo[]        = { KC_D, KC_V,                             COMBO_END};
const uint16_t PROGMEM r_alt_combo[]        = { KC_K, KC_H,                             COMBO_END};
const uint16_t PROGMEM reset_combo[]        = { KC_Q, KC_W, KC_F, KC_U, KC_Y, KC_ENTER, COMBO_END};

combo_t key_combos[] = {
    [MEDIA]         = COMBO(media_combo,        MO(_FUNC)),
    [ESC]           = COMBO(esc_combo,          KC_ESC),
    [NUM]           = COMBO(num_combo,          MO(_NUM)),
    [TAB]           = COMBO(tab_combo,          KC_TAB),
    [FUNC]          = COMBO(func_combo,         MO(_FUNC)),
    [DEL]           = COMBO(del_combo,          KC_DEL),
    [SHORTCUTS]     = COMBO(shortcuts_combo,    OSM(MOD_LCTL)),
    [L_SUPER]       = COMBO(l_super_combo,      OSM(MOD_MEH)),
    [R_SUPER]       = COMBO(r_super_combo,      OSM(MOD_MEH)),
    [L_GUI]         = COMBO(l_gui_combo,        OSM(MOD_LGUI)),
    [R_GUI]         = COMBO(r_gui_combo,        OSM(MOD_RGUI)),
    [L_ALT]         = COMBO(l_alt_combo,        OSM(MOD_LALT)),
    [R_ALT]         = COMBO(r_alt_combo,        OSM(MOD_RALT)),
    [TO_RESET]      = COMBO(reset_combo,        TO(_RESET)),
};
