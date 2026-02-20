// SplitKB Aurora Sweep keyboard
#include QMK_KEYBOARD_H

#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
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
#define A_R LALT_T(KC_R)
#define G_S LGUI_T(KC_S)
#define M_T MEH_T(KC_T)
#define M_N MEH_T(KC_N)
#define G_E LGUI_T(KC_E)
#define A_I LALT_T(KC_I)
#define S_LABK LSFT_T(KC_LABK)
#define A_LBRC LALT_T(KC_LBRC)
#define G_LCBR LGUI_T(KC_LCBR)
#define C_LPRN LCTL_T(KC_LPRN)

// MACROS & LAYERS

enum macro_keycodes {
    FWRD_ARO = SAFE_RANGE,
    FAT_ARO,
};

enum keyboard_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUM,
    _SHORTCUTS,
    _FUNC,
    _MEDIA
};

// KEYMAP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W       │  F       │  P       │  B       ││  J       │  L       │  U       │  Y       │  BSPC    │
            KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,       KC_J,      KC_L,      KC_U,      KC_Y,      KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R (ALT) │  S (GUI) │  T (MEH) │  G       ││  M       │  N (MEH) │  E (GUI) │  I (ALT) │  O       │
            KC_A,      A_R,       G_S,       M_T,       KC_G,       KC_M,      M_N,       G_E,       A_I,       KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z       │  X       │  C       │  D       │  V       ││  K       │  H       │  ,       │  .       │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,       KC_K,      KC_H,      KC_COMM,   KC_DOT,    KC_ENT,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ LOWER    │  CTLR    ││  SHIFT   │SPC(RAISE)│
                                            MO(_LOWER), OSM_CTL,    OSM_SFT,   SPC_RAISE
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │  Umlaut  │  ß       │          ││          │          │          │  "       │          │
            KC_NO,     KC_NO,     UMLAUT,    GERMAN_S,  KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_DQUO,   KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  ?       │  ~       │  _       │  -       │  \       ││  /       │  =       │  +       │  '       │  :       │
            KC_QUES,   KC_TILD,   KC_UNDS,   KC_MINS,   KC_BSLS,    KC_SLSH,   KC_EQL,    KC_PLUS,   KC_QUOT,   KC_COLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││  ->      │  =>      │          │  `       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      FWRD_ARO,  FAT_ARO,   KC_NO,     KC_GRV,    KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ XXXXXXXX │          ││  BSPC    │  ADJUST  │
                                             KC_NO,     KC_NO,      KC_BSPC,  MO(_ADJUST)
        //                                 ╰──────────┴──────────╯╰──────────┴─── ──────╯
    ),
    [_RAISE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │  €       │          ││          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     EURO,      KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  !       │  @       │  #       │  $       │  %       ││  ^       │  &       │  |       │  *       │  ;       │
            KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,    KC_CIRC,   KC_AMPR,   KC_PIPE,   KC_ASTR,   KC_SCLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │  ADJUST  │  ENTER   ││          │ XXXXXXXX │
                                           MO(_ADJUST), KC_ENT,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_ADJUST] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          ││  DOWN    │  LEFT    │          │          │  BSPC    │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_DOWN,   KC_LEFT,   KC_NO,     KC_NO,     KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│ < (SHIFT)│  [ (ALT) │  { (GUI) │  ( (CTRL)│          ││          │  )       │  }       │  ]       │  >       │
            S_LABK,    A_LBRC,    G_LCBR,    C_LPRN,   KC_NO,      KC_NO,     KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_RABK,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          ││  UP      │  RIGHT   │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_UP,     KC_RIGHT,  KC_NO,     KC_NO,     KC_NO,
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
    [_SHORTCUTS] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │  SEARCH  │          │          ││          │          │          │          │          │
            KC_NO,     KC_NO,    LGUI(KC_F), KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│SELECT ALL│  RELOAD  │  SAVE    │          │          ││          │          │          │          │          │
           LGUI(KC_A),LGUI(KC_R),LGUI(KC_S), KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  UNDO    │  CUT     │  COPY    │          │  PASTE   ││          │          │          │          │          │
           LGUI(KC_Z),LGUI(KC_X),LGUI(KC_C), KC_NO,    LGUI(KC_V),  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          ││          │          │
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
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_NO,      RECORD,    VOL_MUTE,  RM_TOGG,   RM_NEXT,   KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          ││          │          │
                                             KC_MPRV,   KC_MSTP,    KC_MPLY,   KC_MNXT
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    )
};

// MACROS

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

        case S_LABK:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_LABK);
                } else {
                    unregister_code16(KC_LABK);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_LEFT_SHIFT);
                } else {
                    unregister_code16(KC_LEFT_SHIFT);
                }
            }
            return false;

        case G_LCBR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_LCBR);
                } else {
                    unregister_code16(KC_LCBR);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_LEFT_GUI);
                } else {
                    unregister_code16(KC_LEFT_GUI);
                }
            }
            return false;

        case C_LPRN:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_LPRN);
                } else {
                    unregister_code16(KC_LPRN);
                }
            } else {
                if (record->event.pressed) {
                    register_code16(KC_LEFT_CTRL);
                } else {
                    unregister_code16(KC_LEFT_CTRL);
                }
            }
            return false;

    }
    return true;
}

// COMBOS

enum combos {
    MEDIA = 0,
    ESC,
    NUM,
    TAB,
    FUNC,
    DEL,
    SHORTCUTS,
};

const uint16_t PROGMEM w_f_p_combo[]    = { KC_W, KC_F, KC_P,                       COMBO_END};
const uint16_t PROGMEM w_f_combo[]      = { KC_W, KC_F,                             COMBO_END};
const uint16_t PROGMEM r_s_combo[]      = { MT(MOD_LALT, KC_R), MT(MOD_LGUI, KC_S), COMBO_END};
const uint16_t PROGMEM x_c_combo[]      = { KC_X, KC_C,                             COMBO_END};
const uint16_t PROGMEM l_u_y_combo[]    = { KC_L, KC_U, KC_Y,                       COMBO_END};
const uint16_t PROGMEM u_y_combo[]      = { KC_U, KC_Y,                             COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = { KC_COMM, KC_DOT,                        COMBO_END};

combo_t key_combos[] = {
    [MEDIA]     = COMBO(w_f_p_combo,    MO(_FUNC)),
    [ESC]       = COMBO(w_f_combo,      KC_ESC),
    [NUM]       = COMBO(r_s_combo,      MO(_NUM)),
    [TAB]       = COMBO(x_c_combo,      KC_TAB),
    [FUNC]      = COMBO(l_u_y_combo,    MO(_FUNC)),
    [DEL]       = COMBO(u_y_combo,      KC_DEL),
    [SHORTCUTS] = COMBO(comm_dot_combo, OSL(_SHORTCUTS)),
};
