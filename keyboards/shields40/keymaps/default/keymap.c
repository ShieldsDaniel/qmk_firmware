#include QMK_KEYBOARD_H

#define UMLAUT TD(DANCE_0)
#define M_SUPER LGUI_T(KC_M)
#define G_SUPER LGUI_T(KC_G)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)
#define NUMBER MO(_NUMBER)
#define LINUX MO(_LINUX)
#define MEDIA MO(_MEDIA)
#define SPC_L2 LT(_RAISE, KC_SPACE)
#define SPC_L3 LT(_ADJUST, KC_SPACE)
#define EURO LALT(LSFT(KC_2))
#define BSPC_L3 LT(_ADJUST, KC_BACKSPACE)
#define SCREEN LGUI(LSFT(KC_4))
#define RECORD LGUI(LSFT(KC_5))
#define BOOT QK_BOOTLOADER
#define QUIT LCTL(KC_Q)
#define FIND LCTL(KC_F)
#define SELECT LCTL(KC_A)
#define RELOAD LCTL(KC_R)
#define SAVE LCTL(KC_S)
#define TAB LCTL(KC_T)
#define UNDO LCTL(KC_Z)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)

enum shields40_keycodes {
  JS_EQUALS,
  SQUIG_ARO,
  FWRD_ARO,
  FAT_ARO,
  BACK_PIPE,
  FORWARD_PIPE,
};

enum tap_dance_codes {
  DANCE_0,
};

enum shields40_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMBER,
  _MEDIA,
  _LINUX,
  _RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Q       │  W    (ESC) F       │  P       │  B       │  J       │  L       │  U     (ALT) Y      │  BSPC    │
            KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,      KC_J,      KC_L,      KC_U,      KC_Y,      KC_BSPC,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  A       │  R       │  S       │  T       │  G    L4 │  M   MEH │  N       │  E       │  I       │  O       │
            KC_A,      KC_R,      KC_S,      KC_T,      G_SUPER,   M_SUPER,   KC_N,      KC_E,      KC_I,      KC_O,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  Z       │  X    (TAB) C       │  D       │  V       │  K       │  H       │  ,     (GUI) .      │  ENTER   │
            KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,      KC_K,      KC_H,      KC_COMMA,  KC_DOT,    KC_ENTER,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //   MEDIA   │          │  NUMBER  │  LOWER   │ OSM CTLR │OSM SHIFT │ SPC RAISE│  LINUX   │          │          │
            MEDIA,     KC_NO,     NUMBER,    LOWER,     OSM_CTL,   OSM_SFT,   SPC_L2,    LINUX,     KC_NO,     KC_DEL
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_LOWER] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │          │  ===     │          │  "       │ Umlaut/ß │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     JS_EQUALS, KC_NO,     KC_DQUO,   UMLAUT,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  ?       │  ~       │  _       │  -       │  \       │  /       │  =       │  +       │  '       │  :       │
            KC_QUES,   KC_TILD,   KC_UNDS,   KC_MINUS,  KC_BSLS,   KC_SLASH,  KC_EQUAL,  KC_PLUS,   KC_QUOTE,  KC_COLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  ->      │  =>      │  ~>      │  `       │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     BACK_PIPE, FWRD_ARO,  FAT_ARO,   SQUIG_ARO, KC_GRAVE,  KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //           │          │          │          │          │          │  SPC  L2 │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   SPC_L3,    KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_RAISE] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │  €       │          │          │          │  <|      │          │          │
            KC_NO,     KC_NO,     KC_NO,     EURO,      KC_NO,     KC_NO,     KC_NO,     BACK_PIPE, KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  !       │  @       │  #       │  $       │  %       │  ^       │  &       │  |       │  *       │  ;       │
            KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_PIPE,   KC_ASTR,   KC_SCLN,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │  |>      │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,   FORWARD_PIPE,KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //           │          │          │  Adjust  │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     ADJUST,    KC_TRNS,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_ADJUST] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│  Control │  Alt     │  Super   │  Shift   │          │  DOWN    │  LEFT    │          │          │          │
            KC_LCTL,   KC_LALT,   KC_LGUI,   KC_LSFT,   KC_NO,     KC_DOWN,   KC_LEFT,   KC_NO,     KC_NO,    KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  <       │  [       │  {       │  (       │          │          │  )       │   }      │  ]       │  >       │
            KC_LABK,   KC_LBRC,   KC_LCBR,   KC_LPRN,   KC_NO,     KC_NO,     KC_RPRN,   KC_RCBR,   KC_RBRC,  KC_RABK,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│  L5      │          │          │          │          │  UP      │  RIGHT   │          │          │  L5      │
            KC_0,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_UP,     KC_RIGHT,  KC_NO,     KC_NO,    KC_1,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //           │          │          │          │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,    KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_NUMBER] = LAYOUT(
        //
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │  F7      │  F8      │  F9      │  F10     │          │  7       │  8       │  9       │          │
            KC_NO,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_NO,     KC_7,      KC_8,      KC_9,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F4      │  F5      │  F6      │  F11     │          │  4       │  5       │  6       │          │
            KC_NO,     KC_F4,     KC_F5,     KC_F6,     KC_F11,    KC_NO,     KC_4,      KC_5,      KC_6,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │  F1      │  F2      │  F3      │  F12     │  ,       │  1       │  2       │  3       │          │
            KC_NO,     KC_F1,     KC_F2,     KC_F3,     KC_F12,    KC_COMMA,  KC_1,      KC_2,      KC_3,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //           │          │          │          │          │  .       │  0       │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_DOT,    KC_0,      KC_NO,     KC_NO,    KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_MEDIA] = LAYOUT(
        //
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │Screenshot│  Vol up  │          │          │Bright up │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     SCREEN,    KC_VOLU,   KC_NO,     KC_NO,     KC_BRIU,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │  Vol down│          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_VOLD,   KC_NO,     KC_NO,     KC_BRID,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │  Record  │  Mute    │          │          │Bright down
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RECORD,    KC_MUTE,   KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //           │          │          │  Prev    │  Stop    │  Play    │  Next    │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_MPRV,   KC_MSTP,   KC_MPLY,   KC_MNXT,    KC_NO,    KC_NO,    KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_LINUX] = LAYOUT(
        //
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │          │          │          │          │          │
            QUIT,      KC_NO,     FIND,      KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
            SELECT,    RELOAD,    SAVE,      TAB,       KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
            UNDO,      KC_NO,     COPY,      KC_NO,     PASTE,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //           │          │          │          │          │          │          │          │          │          │
            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    ),
    [_RESET] = LAYOUT(
        //╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        //│          │          │          │          │          │          │          │          │          │          │
            TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│          │          │          │          │          │          │          │          │          │          │
            TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //│BOOTLOADER│          │          │          │          │          │          │          │          │          │
            BOOT,      TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),
        //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        //           │          │          │          │          │          │          │          │          │          │
            TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0),     TO(0)
        //╰──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────┴──────────╯
    )
};

// COMBOS:
const uint16_t PROGMEM combo0[] = { KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo3[] = { OSM(MOD_LSFT), OSM(MOD_LCTL), COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_0, KC_1, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_X, KC_C, COMBO_END};
combo_t key_combos[6] = {
    COMBO(combo0, OSM(MOD_LGUI)),
    COMBO(combo1, OSM(MOD_LALT)),
    COMBO(combo2, KC_ESCAPE),
    COMBO(combo3, KC_CAPS),
    COMBO(combo4, TO(5)),
    COMBO(combo5, KC_TAB),
};

// MACROS:
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

// TAPDANCE:
enum {
    SINGLE_TAP = 1,
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
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

