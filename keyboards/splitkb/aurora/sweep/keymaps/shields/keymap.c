// SplitKB Aurora Sweep keyboard
#include QMK_KEYBOARD_H

#define M_MEH MEH_T(KC_M)
#define G_MEH MEH_T(KC_G)
#define B_GUI LGUI_T(KC_B)
#define J_GUI LGUI_T(KC_J)
#define G_GUI LGUI_T(KC_G)
#define M_GUI LGUI_T(KC_M)
#define V_ALT LALT_T(KC_V)
#define K_ALT LALT_T(KC_K)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
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

enum macro_keycodes {
  BACK_ARO = SAFE_RANGE,
  JS_EQUALS,
  SQUIG_ARO,
  FWRD_ARO,
  FAT_ARO,
  BACK_PIPE,
  FWRD_PIPE,
  CHECK_OS,
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
  _LINUX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W  (MEDIA) F       │  P       │  B  (GUI)││  J  (GUI)│  L       │  U   (FUNC) Y       │  BSPC    │
            KC_Q,      KC_W,      KC_F,      KC_P,      B_GUI,      J_GUI,     KC_L,      KC_U,      KC_Y,      KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R       │  S       │  T       │  G  (MEH)││  M  (MEH)│  N       │  E       │  I       │  O       │
            KC_A,      KC_R,      KC_S,      KC_T,      G_MEH,      M_MEH,     KC_N,      KC_E,      KC_I,      KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z       │  X   (NUM)  C       │  D       │  V  (ALT)││  K  (ALT)│  H       │  ,(SHORTCUTS).      │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      V_ALT,      K_ALT,     KC_H,      KC_COMM,   KC_DOT,    KC_ENT,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ LOWER    │  CTLR    ││  SHIFT   │SPC(RAISE)│
                                            MO(_LOWER), OSM_CTL,    OSM_SFT,   SPC_RAISE
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │  Umlaut  │  ß       ││          │  ===     │          │  "       │  BSPC    │
            KC_NO,     KC_NO,     KC_NO,    LALT(KC_U), LALT(KC_S), KC_NO,    JS_EQUALS,  KC_NO,     KC_DQUO,   KC_BSPC,
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
    [_LINUX] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W  (MEDIA) F       │  P       │  B  (GUI)││  J  (GUI)│  L       │  U   (FUNC) Y       │  BSPC    │
            KC_Q,      KC_W,      KC_F,      KC_P,      B_GUI,      J_GUI,     KC_L,      KC_U,      KC_Y,      KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R       │  S       │  T       │  G  (GUI)││  M  (GUI)│  N       │  E       │  I       │  O       │
            KC_A,      KC_R,      KC_S,      KC_T,      G_GUI,      M_GUI,     KC_N,      KC_E,      KC_I,      KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z       │  X   (NUM)  C       │  D       │  V  (ALT)││  K  (ALT)│  H       │  ,(SHORTCUTS).      │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      V_ALT,      K_ALT,     KC_H,      KC_COMM,   KC_DOT,    KC_ENT,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ LOWER    │  CTLR    ││  SHIFT   │SPC(RAISE)│
                                            MO(_LOWER), OSM_CTL,    OSM_SFT,   SPC_RAISE
        //                                 ╰──────────┴──────────╯╰──────────┴──────────╯
    )
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

        case CHECK_OS:
            if (record->event.pressed) {
                if (get_highest_layer(layer_state) == _MAC) {
                    SEND_STRING("mac");
                } else if (get_highest_layer(layer_state) == _LINUX) {
                    SEND_STRING("linux");
                }
            }
            break;
    }
    return true;
}

// COMBOS
enum combos {
    TO_MAC = 0,
    TO_LINUX,
    OS_CHECK,
    NUM_TAB,
    MEDIA_ESC,
    FUNC_DEL,
    MAC_SHORTCUTS,
    LINUX_SHORTCUTS,
    RESET,
};

const uint16_t PROGMEM mac_combo[] = {KC_Q, KC_BSPC, COMBO_END};
const uint16_t PROGMEM linux_combo[] = {KC_Q, KC_BSPC, COMBO_END};
const uint16_t PROGMEM os_check_combo[] = {KC_Z, KC_ENT, COMBO_END};
const uint16_t PROGMEM num_tab_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM media_esc_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM func_del_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM mac_shortcuts_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM linux_shortcuts_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM reset_combo[] = {KC_R, KC_S, KC_T, KC_N, KC_E, KC_I, COMBO_END};

combo_t key_combos[] = {
    [TO_MAC] = COMBO(mac_combo, TO(_MAC)),
    [TO_LINUX] = COMBO(linux_combo, TO(_LINUX)),
    [OS_CHECK] = COMBO(os_check_combo, CHECK_OS),
    [NUM_TAB] = COMBO(num_tab_combo, LT(_NUM, KC_TAB)),
    [MEDIA_ESC] = COMBO(media_esc_combo, LT(_MEDIA, KC_ESC)),
    [FUNC_DEL] = COMBO(func_del_combo, LT(_FUNC, KC_DEL)),
    [MAC_SHORTCUTS] = COMBO(mac_shortcuts_combo, OSM(MOD_LGUI)),
    [LINUX_SHORTCUTS] = COMBO(linux_shortcuts_combo, OSM(MOD_LCTL)),
    [RESET] = COMBO(reset_combo, TO(_RESET)),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case TO_LINUX:
        case MAC_SHORTCUTS:
        case RESET:
            return get_highest_layer(layer_state) == _MAC;
            break;

        case TO_MAC:
        case LINUX_SHORTCUTS:
            return get_highest_layer(layer_state) == _LINUX;
            break;
    }

    return true;
}
