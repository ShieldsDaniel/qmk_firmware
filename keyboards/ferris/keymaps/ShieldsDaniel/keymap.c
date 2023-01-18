#include QMK_KEYBOARD_H

enum tap_dance_codes {
  TAP_Q,
  TAP_COMM,
  TAP_DOT,
  TAP_CLN
};

#define MT_A MT(MOD_LALT, KC_A)
#define MT_O MT(MOD_RALT, KC_O)
#define MT_BSPC MT(MOD_LGUI, KC_BSPC)
#define MT_SPC MEH_T(KC_SPC)
#define MT_BSLS MT(MOD_LALT, KC_BSLS)
#define MT_N0 MT(KC_SPC, KC_0)
#define SCREEN LGUI(S(KC_4))
#define RECORD LGUI(S(KC_5))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
// ╭──────────┬──────────┬──────────┬────────────┬─────────────╮   ╭────────────┬────────────┬─────────────┬─────────────┬──────────╮
// │  Q   ESC │  W       │  F       │  P         │  B          │   │  J         │  L         │  U          │  Y          │  ;       │ 
    TD(TAP_Q),  KC_W,      KC_F,      KC_P,        KC_B,             KC_J,        KC_L,        KC_U,         KC_Y,         KC_SCLN,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  A       │  R       │  S  ALT  │  T  GUI    │  G          │   │  M         │  N   GUI   │  E      ALT │  I          │  O       │
     MT_A,     LT(1,KC_R),LT(2,KC_S), LT(3,KC_T),  KC_G,             KC_M,        LT(3,KC_N),  LT(2, KC_E),  LT(1, KC_I),  MT_O,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  Z       │  X       │  C       │  D         │  V          │   │  K         │  H         │ , <       ? │ . >       ! │  ENTER   │
     KC_Z,      KC_X,      KC_C,      KC_D,        KC_V,             KC_K,        KC_H,        TD(TAP_COMM), TD(TAP_DOT),  KC_ENTER,
// ╰──────────┴──────────┴──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┴─────────────┴──────────╯
//                                  │  BSPC  GUI │  OSM CTLR   │   │  OSM SHIFT │  SPC       │
		    		                  MT_BSPC,    OSM(MOD_RCTL),    OSM(MOD_LSFT), MT_SPC
//                                  ╰────────────┴─────────────╯   ╰────────────┴────────────╯
  ),
// TODO: Add Tapdance for euro symbol with KC_4
  [1] = LAYOUT(
// ╭──────────┬──────────┬──────────┬────────────┬─────────────╮   ╭────────────┬────────────┬─────────────┬─────────────┬──────────╮
// │  !       │  @       │  #       │  $         │  %          │   │  ^         │  *         │  *          │  "          │  ;       │ 
     S(KC_1),   S(KC_2),   S(KC_3),   S(KC_4),     S(KC_5),          S(KC_6),     S(KC_7),     S(KC_8),      S(KC_QUOT),   KC_SCLN,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  \       │  `       │  [       │  ]         │  -          │   │  =         │  {         │  }          │  '          │  :       │
     MT_BSLS,   KC_GRV,    KC_LBRC,   KC_RBRC,     KC_MINS,           KC_EQL,     KC_LCBR,     KC_RCBR,      KC_QUOT,    TD(TAP_CLN),
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │  |       │  ~       │  <       │  >         │  _          │   │  +         │  (         │  )          │  ?          │  /       │
    S(KC_BSLS), S(KC_GRV),S(KC_COMM), S(KC_DOT),   S(KC_MINS),       S(KC_EQL),   KC_LPRN,     KC_RPRN,      S(KC_SLSH),   KC_SLSH,
// ╰──────────┴──────────┴──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┴─────────────┴──────────╯
//                                  │  BSPC  GUI │  OSM CTLR   │   │  OSM SHIFT │  SPC       │
		    		                  MT_BSPC,    OSM(MOD_RCTL),    OSM(MOD_LSFT), MT_SPC
//                                  ╰────────────┴─────────────╯   ╰────────────┴────────────╯
  ),
  [2] = LAYOUT(
// ╭──────────┬──────────┬──────────┬────────────┬─────────────╮   ╭────────────┬────────────┬─────────────┬─────────────┬──────────╮
// │          │  F7      │  F8      │  F9        │  F10        │   │            │  7         │  8          │  9          │          │ 
     KC_NO,     KC_F7,     KC_F8,     KC_F9,       KC_F10,           KC_NO,       KC_KP_7,     KC_KP_8,      KC_KP_9,      KC_NO,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │          │  F4      │  F5      │  F6        │  F11        │   │  ,         │  4         │  5          │  6          │          │
     KC_NO,     KC_F4,     KC_F5,     KC_F6,       KC_F11,           KC_COMMA,    KC_KP_4,     KC_KP_5,      KC_KP_6,      KC_NO,
// ├──────────┼──────────┼──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┼─────────────┼──────────┤
// │          │  F1      │  F2      │  F3        │  F12        │   │  .         │  1         │  2          │  3          │          │
     KC_NO,     KC_F1,     KC_F2,     KC_F3,       KC_F12,           KC_DOT ,     KC_KP_1,     KC_KP_2,      KC_KP_3,      KC_NO,
// ╰──────────┴──────────┴──────────┼────────────┼─────────────┤   ├────────────┼────────────┼─────────────┴─────────────┴──────────╯
//                                  │  BSPC  GUI │  OSM CTLR   │   │  OSM SHIFT │  0         │
		    		                  MT_BSPC,    OSM(MOD_RCTL),    OSM(MOD_LSFT), MT_N0
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
//                                  │  BSPC  GUI │  OSM CTLR   │   │  OSM SHIFT │  SPC       │
		    		                  MT_BSPC,    OSM(MOD_RCTL),    OSM(MOD_LSFT), MT_SPC
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

