#include QMK_KEYBOARD_H

enum tap_dance_codes {
  TAP_Q,
  TAP_COMM,
  TAP_DOT,
  TAP_CLN
};

#define MT_S MT(MOD_LALT, KC_S)
#define MT_T MT(MOD_LGUI, KC_T)
#define MT_N MT(MOD_RGUI, KC_N)
#define MT_E MT(MOD_RALT, KC_E)
#define MT_BSLS MT(MOD_LALT, KC_BSLS)
#define MT_N0 MT(KC_SPC, KC_0)
#define SCREEN LGUI(S(KC_4))
#define RECORD LGUI(S(KC_5))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
// ╭──────────┬──────────┬──────────┬────────────┬─────────────╮   ╭────────────┬────────────┬─────────────┬─────────────┬──────────╮
// │  Q   ESC │  W       │  F       │  P         │  B          │   │  J         │  L         │  U          │  Y          │  BSPC    │ 
    TD(TAP_Q),  KC_W,      KC_F,      KC_P,        KC_B,             KC_J,        KC_L,        KC_U,         KC_Y,         KC_BSPC,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  A       │  R       │  S  ALT  │  T  GUI    │  G          │   │  M         │  N   GUI   │  E      ALT │  I          │  O       │
     KC_A,      KC_R,      MT_S,      MT_T,        KC_G,             MEH_T(KC_M), MT_N,        MT_E,         KC_I,         KC_O,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  Z       │  X       │  C       │  D         │  V          │   │  K         │  H         │ , <       ? │ . >       ! │  ENTER   │
     KC_Z,      KC_X,      KC_C,      KC_D,        KC_V,             KC_K,        KC_H,        TD(TAP_COMM), TD(TAP_DOT),  KC_ENTER,
// ╰──────────┴──────────┴──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┴─────────────┴──────────╯
//                                  │  TAB    L1 │  OSM CTLR   │   │  OSM SHIFT │  SPC    L2 │
		    		                LT(1, KC_TAB), OSM(MOD_RCTL),  OSM(MOD_LSFT), LT(2, KC_SPC)
//                                  ╰────────────┴─────────────╯   ╰────────────┴────────────╯
  ),
// TODO: Add Tapdance for euro symbol with KC_4
// TODO: Add Tapdance for mod taps on {}
  [1] = LAYOUT(
// ╭──────────┬──────────┬──────────┬────────────┬─────────────╮   ╭────────────┬────────────┬─────────────┬─────────────┬──────────╮
// │  !       │  @       │  #       │  $         │  %          │   │  ^         │  *         │  *          │  "          │  ;       │ 
     S(KC_1),   S(KC_2),   S(KC_3),   S(KC_4),     S(KC_5),          S(KC_6),     S(KC_7),     S(KC_8),      S(KC_QUOT),   KC_SCLN,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  \       │  `       │  [       │  ]         │  -          │   │  =         │  {         │  }          │  '          │  :       │
     KC_BSLS,   KC_GRV,    KC_LBRC,   KC_RBRC,     KC_MINS,           KC_EQL,     KC_LCBR,     KC_RCBR,      KC_QUOT,    TD(TAP_CLN),
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  |       │  ~       │  <       │  >         │  _          │   │  +         │  (         │  )          │  ?          │  /       │
    S(KC_BSLS), S(KC_GRV),S(KC_COMM), S(KC_DOT),   S(KC_MINS),       S(KC_EQL),   KC_LPRN,     KC_RPRN,      S(KC_SLSH),   KC_SLSH,
// ╰──────────┴──────────┴──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┴─────────────┴──────────╯
//                                  │            │  OSM CTLR   │   │  OSM SHIFT │  SPC    L3 │
		    		                  KC_NO,      OSM(MOD_RCTL),   OSM(MOD_LSFT), LT(3, KC_SPC)
//                                  ╰────────────┴─────────────╯   ╰────────────┴────────────╯
  ),
  [2] = LAYOUT(
// ╭──────────┬──────────┬──────────┬────────────┬─────────────╮   ╭────────────┬────────────┬─────────────┬─────────────┬──────────╮
// │          │  F7      │  F8      │  F9        │  F10        │   │  ,         │  7         │  8          │  9          │          │ 
     KC_NO,     KC_F7,     KC_F8,     KC_F9,       KC_F10,           KC_COMMA,    KC_7,        KC_8,         KC_9,         KC_NO,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │          │  F4      │  F5      │  F6        │  F11        │   │  .         │  4         │  5          │  6          │          │
     KC_NO,     KC_F4,     KC_F5,     KC_F6,       KC_F11,           KC_DOT,      KC_4,        KC_5,         KC_6,         KC_NO,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │          │  F1      │  F2      │  F3        │  F12        │   │  0         │  1         │  2          │  3          │          │
     KC_NO,     KC_F1,     KC_F2,     KC_F3,       KC_F12,           KC_0,        KC_1,        KC_2,         KC_3,         KC_NO,
// ╰──────────┴──────────┴──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┴─────────────┴──────────╯
//                                  │  TAB    L3 │  OSM CTLR   │   │  OSM SHIFT │            │
		    		                LT(3, KC_TAB),OSM(MOD_RCTL),    OSM(MOD_LSFT), KC_NO
//                                  ╰────────────┴─────────────╯   ╰────────────┴────────────╯
  ),
  [3] = LAYOUT(
// ╭──────────┬──────────┬──────────┬────────────┬─────────────╮   ╭────────────┬────────────┬─────────────┬─────────────┬──────────╮
// │  ESC     │  Del     │  Screen  │  Record    │             │   │  DOWN      │  RIGHT     │  MOUSE UP   │ Mouse Middle│ Wheel Up │ 
     KC_ESC,    KC_NO,     SCREEN,    RECORD,      KC_NO,            KC_DOWN,     KC_RIGHT,    KC_MS_U,      KC_BTN3,      KC_WH_U,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  Tab     │          │          │            │             │   │ Mouse Left │ MOUSE LEFT │  MOUSE DOWN │ MOUSE RIGHT │MouseRight│
     KC_TAB,    KC_NO,     KC_NO,     KC_NO,       KC_NO,            KC_BTN1,     KC_MS_L,     KC_MS_D,      KC_MS_R,      KC_BTN2,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │Bootloader│          │          │            │             │   │  UP        │  LEFT      │             │             │Wheel Down│
     QK_BOOT,   KC_NO,     KC_NO,     KC_NO,       KC_NO,            KC_UP,       KC_LEFT,     KC_NO,        KC_NO,        KC_WH_D,
// ╰──────────┴──────────┴──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┴─────────────┴──────────╯
//                                  │            │  OSM CTLR   │   │  OSM SHIFT │            │
		    		                  KC_NO,      OSM(MOD_RCTL),    OSM(MOD_LSFT), KC_NO
//                                  ╰────────────┴─────────────╯   ╰────────────┴────────────╯
  )
};

extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

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

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

// Tap dance - Option on hold & : on tap
void on_alt_cln(qk_tap_dance_state_t *state, void *user_data);
uint8_t alt_cln_dance_step(qk_tap_dance_state_t *state);
void alt_cln_finished(qk_tap_dance_state_t *state, void *user_data);
void alt_cln_reset(qk_tap_dance_state_t *state, void *user_data);

void on_alt_cln(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_COLN);
		tap_code16(KC_COLN);
		tap_code16(KC_COLN);
	}
	if(state->count > 3) {
		tap_code16(KC_COLN);
	}
}

uint8_t alt_cln_dance_step(qk_tap_dance_state_t *state) {
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
void alt_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = alt_cln_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_COLN); break;
		case SINGLE_HOLD: register_code16(KC_RALT); break;
		case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN); break;
	}
}

void alt_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_COLN); break;
		case SINGLE_HOLD: unregister_code16(KC_RALT); break;
		case DOUBLE_TAP: unregister_code16(KC_COLN); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
	}
	dance_state.step = 0;
}

// Tap dance - comma on tap, qustion mark on hold
void on_comm_ques(qk_tap_dance_state_t *state, void *user_data);
uint8_t comm_ques_dance_step(qk_tap_dance_state_t *state);
void comm_ques_finished(qk_tap_dance_state_t *state, void *user_data);
void comm_ques_reset(qk_tap_dance_state_t *state, void *user_data);

void on_comm_ques(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_COMM);
		tap_code16(KC_COMM);
		tap_code16(KC_COMM);
	}
	if(state->count > 3) {
		tap_code16(KC_COMM);
	}
}

uint8_t comm_ques_dance_step(qk_tap_dance_state_t *state) {
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
void comm_ques_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = comm_ques_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_COMM); break;
		case SINGLE_HOLD: register_code16(KC_QUES); break;
		case DOUBLE_TAP: register_code16(KC_COMM); register_code16(KC_COMM); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_COMM); register_code16(KC_COMM); break;
	}
}

void comm_ques_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_COMM); break;
		case SINGLE_HOLD: unregister_code16(KC_QUES); break;
		case DOUBLE_TAP: unregister_code16(KC_COMM); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMM); break;
	}
	dance_state.step = 0;
}

// Tap dance - period on tap, exclamation mark on hold
void on_dot_exlm(qk_tap_dance_state_t *state, void *user_data);
uint8_t dot_exlm_dance_step(qk_tap_dance_state_t *state);
void dot_exlm_finished(qk_tap_dance_state_t *state, void *user_data);
void dot_exlm_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dot_exlm(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
	}
	if(state->count > 3) {
		tap_code16(KC_DOT);
	}
}

uint8_t dot_exlm_dance_step(qk_tap_dance_state_t *state) {
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

void dot_exlm_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dot_exlm_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_DOT); break;
		case SINGLE_HOLD: register_code16(KC_EXLM); break;
		case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT); break;
	}
}

void dot_exlm_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_DOT); break;
		case SINGLE_HOLD: unregister_code16(KC_EXLM); break;
		case DOUBLE_TAP: unregister_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
	}
	dance_state.step = 0;
}

// ---------------------------------------------------------------------

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TAP_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(on_alt_cln, alt_cln_finished, alt_cln_reset),
    [TAP_COMM] = ACTION_TAP_DANCE_FN_ADVANCED(on_comm_ques, comm_ques_finished, comm_ques_reset),
    [TAP_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dot_exlm, dot_exlm_finished, dot_exlm_reset)
};

