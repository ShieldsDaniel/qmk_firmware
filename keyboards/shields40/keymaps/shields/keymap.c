// Shields40 handwired keyboard
#include QMK_KEYBOARD_H

#define G_MEH MT(MOD_LGUI, KC_G)
#define M_MEH MT(MOD_LGUI, KC_M)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define SPC_RAISE LT(_RAISE, KC_SPACE)
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
};

enum keyboard_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
  _FUNC,
  _MEDIA,
  _RESET,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W       │  F       │  P       │  B       │  J       │  L       │  U   (FUNC) Y       │  BSPC    │
            KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,      KC_J,      KC_L,      KC_U,      KC_Y,      KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R       │  S       │  T       │  G  (MEH)│  M  (MEH)│  N       │  E       │  I       │  O       │
            KC_A,      KC_R,      KC_S,      KC_T,      G_MEH,     M_MEH,     KC_N,      KC_E,      KC_I,      KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z       │  X   (NUM)  C       │  D       │  V       │  K       │  H       │  ,(SHORTCUTS).      │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,      KC_K,      KC_H,      KC_COMM,   KC_DOT,    KC_ENT,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │ LOWER    │  CTLR    │  SHIFT   │SPC(RAISE)│          │          │          │
            KC_NO,     KC_NO,     KC_NO,    MO(_LOWER), OSM_CTL,   OSM_SFT,   SPC_RAISE, KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  ESCAPE  │          │          │  Umlaut  │  ß TODO  │          │  ===     │          │  "       │  DELETE  │
            KC_ESC,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    JS_EQUALS,  KC_NO,     KC_DQUO,   KC_DEL,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  ?       │  ~       │  _       │  -       │  \       │  /       │  =       │  +       │  '       │  :       │
            KC_QUES,   KC_TILD,   KC_UNDS,   KC_MINS,   KC_BSLS,   KC_SLSH,   KC_EQL,    KC_PLUS,   KC_QUOT,   KC_COLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  TAB     │          │          │          │          │  ->      │  =>      │  ~>      │  `       │          │
            KC_TAB,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     FWRD_ARO,  FAT_ARO,   SQUIG_ARO, KC_GRV,    KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │  ADJUST  │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    MO(_ADJUST),KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_RAISE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  ESCAPE  │          │          │  € TODO  │          │          │          │  <|      │          │  DELETE  │
            KC_ESC,    KC_NO,     KC_NO,     KC_NO,      KC_NO,    KC_NO,     KC_NO,     BACK_PIPE, KC_NO,     KC_DEL,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  !       │  @       │  #       │  $       │  %       │  ^       │  &       │  |       │  *       │  ;       │
            KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_PIPE,   KC_ASTR,   KC_SCLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  TAB     │          │          │          │          │          │          │  |>      │          │          │
            KC_TAB,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     FWRD_PIPE, KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │  ADJUST  │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,   MO(_ADJUST), KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_ADJUST] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  SHIFT   │  CTLR    │  ALT     │  GUI     │          │  DOWN    │  LEFT    │          │          │  BSPC    │
            OSM_SFT,   OSM_CTL,   OSM_ALT,   OSM_GUI,   KC_NO,     KC_DOWN,   KC_LEFT,   KC_NO,     KC_NO,     KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  <       │  [       │  {       │  (       │          │          │  )       │  }       │  ]       │  >       │
            KC_LABK,   KC_LBRC,   KC_LCBR,   KC_LPRN,   KC_NO,     KC_NO,     KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_RABK,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  UP      │  RIGHT   │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_UP,     KC_RIGHT,  KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_NUM] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │          │  7       │  8       │  9       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_7,      KC_8,      KC_9,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │  4       │  5       │  6       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_4,      KC_5,      KC_6,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  ,       │  1       │  2       │  3       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_COMMA,  KC_1,      KC_2,      KC_3,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  .       │  0       │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_DOT,    KC_0,      KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_FUNC] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │  F7      │  F8      │  F9      │  F10     │          │          │          │          │          │
            KC_NO,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F4      │  F5      │  F6      │  F11     │          │          │          │          │          │
            KC_NO,     KC_F4,     KC_F5,     KC_F6,     KC_F11,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F1      │  F2      │  F3      │  F12     │          │          │          │          │          │
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_F12,    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_MEDIA] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │ SCREEN   │ Vol up   │          │          │ Brighter │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     VOL_UP,    KC_NO,     KC_NO,     BRIGHTER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │ Vol down │          │          │ Dimmer   │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     VOL_DOWN,  KC_NO,     KC_NO,     DIMMER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │ RECORD   │ Mute     │          │          │          │
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_NO,     KC_NO,     VOL_MUTE,  KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_MPRV,   KC_MSTP,   KC_MPLY,   KC_MNXT,   KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_RESET] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │          │          │          │          │          │
           TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE),  TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE),
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
           TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE),  TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE),
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│BOOTLOADER│          │          │          │          │          │          │          │          │          │
            BOOT,     TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE),  TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE), TO(_BASE),
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,    TO(_BASE), TO(_BASE),  TO(_BASE), TO(_BASE), KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    )
};

// MACROS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BACK_ARO:
            if (record->event.pressed) {
                SEND_STRING("<-");
            }
            break;

        case JS_EQUALS:
            if (record->event.pressed) {
                SEND_STRING("===");
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
    SHORTCUTS = 0,
    NUMBER,
    MEDIA,
    FUNC,
    RESET,
};

const uint16_t PROGMEM shortcuts_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM number_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM media_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM func_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM reset_combo[] = {KC_R, KC_S, KC_T, KC_N, KC_E, KC_I, COMBO_END};

combo_t key_combos[] = {
    [SHORTCUTS] = COMBO(shortcuts_combo, OSM(MOD_LCTL)),
    [NUMBER] = COMBO(number_combo, MO(_NUM)),
    [MEDIA] = COMBO(media_combo, MO(_MEDIA)),
    [FUNC] = COMBO(func_combo, MO(_FUNC)),
    [RESET] = COMBO(reset_combo, TO(_RESET)),
};

