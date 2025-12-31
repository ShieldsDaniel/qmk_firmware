// Shields40 handwired keyboard
#include QMK_KEYBOARD_H

#define UMLAUT TD(GERMAN)
#define M_MEH MEH_T(KC_M)
#define G_MEH MEH_T(KC_G)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
#define SPC_RAISE LT(_RAISE, KC_SPACE)
#define MINS_NUM LT(_NUM, KC_MINS)
#define AMPR_FUNC LT(_FUNC, KC_AMPR)
#define EURO LALT(LSFT(KC_2))
#define SCREEN LGUI(LSFT(KC_4))
#define RECORD LGUI(LSFT(KC_5))
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define VOL_MUTE KC_AUDIO_MUTE
#define BRIGHTER KC_BRIGHTNESS_UP
#define DIMMER KC_BRIGHTNESS_DOWN
#define BOOT QK_BOOTLOADER

enum sweep_keycodes {
  BACK_ARO = SAFE_RANGE,
  JS_EQUALS,
  SQUIG_ARO,
  FWRD_ARO,
  FAT_ARO,
  BACK_PIPE,
  FWRD_PIPE,
};

enum tap_dance_codes {
  GERMAN,
};

enum sweep_layers {
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
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W       │  F       │  P       │  B       │  │  J       │  L       │  U       │  Y       │  BSPC    │
            KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,         KC_J,      KC_L,      KC_U,      KC_Y,      KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R       │  S       │  T       │  G  (MEH)│  │  M  (MEH)│  N       │  E       │  I       │  O       │
            KC_A,      KC_R,      KC_S,      KC_T,      G_MEH,        M_MEH,     KC_N,      KC_E,      KC_I,      KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z  (MEDIA) X       │  C       │  D       │  V       │  │  K       │  H     (OS) ,  (LINUX) .       │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,         KC_K,      KC_H,      KC_COMM,   KC_DOT,    KC_ENT,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │ LOWER    │  CTLR    │  │  SHIFT   │SPC(RAISE)│
            KC_NO,     KC_NO,     KC_NO,    MO(_LOWER), OSM_CTL,      OSM_SFT,   SPC_RAISE, KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  ESCAPE  │          │          │          │          │  │ Umlaut/ß │  ===     │          │  "       │  DELETE  │
            KC_ESC,    KC_NO,     KC_NO,     KC_NO,     KC_NO,        UMLAUT,    JS_EQUALS, KC_NO,     KC_DQUO,   KC_DEL,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  ?       │  ~       │  _       │  - (NUM) │  \       │  │  /       │  =       │  +       │  '       │  :       │
            KC_QUES,   KC_TILD,   KC_UNDS,   MINS_NUM, KC_BSLS,       KC_SLSH,   KC_EQL,    KC_PLUS,   KC_QUOT,   KC_COLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  TAB     │          │          │          │          │  │  ->      │  =>      │  ~>      │  `       │          │
            KC_TAB,    KC_NO,     KC_NO,     KC_NO,     KC_NO,        FWRD_ARO,  FAT_ARO,   SQUIG_ARO, KC_GRV,    KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼── ───────┼──────────┴──────────┴──────────╯
        //                                 │          │          │  │          │  ADJUST  │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,    MO(_ADJUST),KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴─── ──────╯
    ),
    [_RAISE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  ESCAPE  │          │          │  €       │          │  │          │          │  <|      │          │  DELETE  │
            KC_ESC,    KC_NO,     KC_NO,     EURO,      KC_NO,        KC_NO,     KC_NO,     BACK_PIPE, KC_NO,     KC_DEL,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  !       │  @       │  #       │  $       │  %       │  │  ^       │  & (FUNC)│  |       │  *       │  ;       │
            KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,      KC_CIRC,   AMPR_FUNC, KC_PIPE,   KC_ASTR,   KC_SCLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  TAB     │          │          │          │          │  │          │          │  |>      │          │          │
            KC_TAB,    KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,     KC_NO,     FWRD_PIPE, KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │  ADJUST  │          │  │          │          │
            KC_NO,     KC_NO,     KC_NO,   MO(_ADJUST), KC_NO,        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴──────────╯
    ),
    [_ADJUST] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │  GUI     │  SHIFT   │  ALT     │          │  │  DOWN    │  LEFT    │          │          │          │
            KC_NO,     KC_LGUI,   KC_LSFT,    KC_LALT,   KC_NO,        KC_DOWN,   KC_LEFT,   KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  <       │  [       │  {       │  (       │          │  │          │  )       │  }       │  ]       │  >       │
            KC_LABK,   KC_LBRC,   KC_LCBR,   KC_LPRN,   KC_NO,        KC_NO,     KC_RPRN,   KC_RCBR,   KC_RBRC,   KC_RABK,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  (RESET) │          │  CTRL    │  GUI     │          │  │  UP      │  RIGHT   │          │          │  (RESET) │
            KC_0,      KC_NO,     KC_LCTL,   KC_LGUI,   KC_NO,        KC_UP,     KC_RIGHT,  KC_NO,     KC_NO,     KC_1,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          │  │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴──────────╯
    ),
    [_NUM] = LAYOUT(
        //
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │  │          │  7       │  8       │  9       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,     KC_7,      KC_8,      KC_9,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  │          │  4       │  5       │  6       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,     KC_4,      KC_5,      KC_6,      KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  │  ,       │  1       │  2       │  3       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_COMMA,  KC_1,      KC_2,      KC_3,      KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          │  │  .       │  0       │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_DOT,    KC_0,      KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴──────────╯
    ),
    [_FUNC] = LAYOUT(
        //
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │  F7      │  F8      │  F9      │  F10     │  │          │          │          │          │          │
            KC_NO,     KC_F7,     KC_F8,     KC_F9,     KC_F10,       KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F4      │  F5      │  F6      │  F11     │  │          │          │          │          │          │
            KC_NO,     KC_F4,     KC_F5,     KC_F6,     KC_F11,       KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F1      │  F2      │  F3      │  F12     │  │          │          │          │          │          │
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_F12,       KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          │  │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴──────────╯
    ),
    [_MEDIA] = LAYOUT(
        //
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │  │ SCREEN   │ Vol up   │          │          │ Brighter │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        SCREEN,    VOL_UP,    KC_NO,     KC_NO,     BRIGHTER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  │          │ Vol down │          │          │ Dimmer   │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,        KC_NO,     VOL_DOWN,  KC_NO,     KC_NO,     DIMMER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  │ RECORD   │ Mute     │          │          │          │
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_NO,        RECORD,    VOL_MUTE,  KC_NO,     KC_NO,     KC_NO,
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          │  │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_MPRV,   KC_MSTP,      KC_MPLY,   KC_MNXT,   KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴──────────╯
    ),
    [_RESET] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────╮  ╭──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │  │          │          │          │          │          │
            TO(0),     TO(0),     TO(0),     TO(0),     TO(0),        TO(0),     TO(0),     TO(0),     TO(0),     TO(0),
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  │          │          │          │          │          │
            TO(0),     TO(0),     TO(0),     TO(0),     TO(0),        TO(0),     TO(0),     TO(0),     TO(0),     TO(0),
        //├──────────┼──────────┼──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┼──────────┼──────────┤
        //│BOOTLOADER│          │          │          │          │  │          │          │          │          │          │
            BOOT,      TO(0),     TO(0),     TO(0),     TO(0),        TO(0),     TO(0),     TO(0),     TO(0),     TO(0),
        //╰──────────┴──────────┴──────────┼──────────┼──────────┤  ├──────────┼──────────┼──────────┴──────────┴──────────╯
        //                                 │          │          │  │          │          │
            KC_NO,     KC_NO,     KC_NO,     TO(0),     TO(0),        TO(0),     TO(0),     KC_NO,     KC_NO,     KC_NO
        //                                 ╰──────────┴──────────╯  ╰──────────┴──────────╯
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
    MEDIA,
    RESET,
};

const uint16_t PROGMEM shortcuts_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM media_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM reset_combo[] = {KC_1, KC_2, COMBO_END};

combo_t key_combos[] = {
    [SHORTCUTS] = COMBO(shortcuts_combo, KC_LGUI),
    [MEDIA] = COMBO(media_combo, MO(_MEDIA)),
    [RESET] = COMBO(reset_combo, TO(_RESET)),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case SHORTCUTS:
        case MEDIA:
            return layer_state_is(_BASE);
            break;
        case RESET:
            return layer_state_is(_ADJUST);
            break;
    }
    return true;
}

// TAP DANCE
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
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


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_U));
        tap_code16(LALT(KC_U));
        tap_code16(LALT(KC_U));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_U));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LALT(KC_U)); break;
        case SINGLE_HOLD: register_code16(LALT(KC_S)); break;
        case DOUBLE_TAP: register_code16(LALT(KC_U)); register_code16(LALT(KC_U)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_U)); register_code16(LALT(KC_U));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_U)); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_S)); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_U)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_U)); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [GERMAN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

;
